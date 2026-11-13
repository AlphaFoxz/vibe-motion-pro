//! netloop：虚拟网卡线程 ↔ ChannelAdapter ↔ 数据面的组装与生命周期管理。
//!
//! 拓扑（对齐原版 vpnd.exe ↔ vl3vpn.dll）：
//!   [内核] ⇄ pump_in/pump_out 线程（阻塞 IO，持 TunAdapter）
//!          ⇄ mpsc（ChannelAdapter）
//!          ⇄ 数据面任务（smoltcp poll 循环，async 环境）
//!
//! 停止协议：`stop` 标志置位 → 数据面任务退出；网卡线程随 ChannelAdapter
//! 断开（drop sender/receiver）或错误退出。阻塞读线程以 stop 标志在包间退出。

use mp_core::dataplane::{Adapter, ChannelAdapter, Dataplane};
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::Arc;
use tokio::task::JoinHandle;

/// 数据面轮询间隔（ms）：低延迟与 CPU 占用的折中。
const PUMP_INTERVAL_MS: u64 = 5;

/// 数据面 poll 循环任务体。`adapter` 为任意实现（生产=ChannelAdapter，测试=Mock）。
/// 返回任务句柄与停止标志。
pub fn spawn_dataplane_task(
    mut adapter: impl Adapter + Send + 'static,
    mut dataplane: Dataplane,
) -> (JoinHandle<()>, Arc<AtomicBool>) {
    let stop = Arc::new(AtomicBool::new(false));
    let stop2 = Arc::clone(&stop);
    let handle = tokio::task::spawn_blocking(move || {
        while !stop2.load(Ordering::Relaxed) {
            let _ = dataplane.pump(&mut adapter);
            std::thread::sleep(std::time::Duration::from_millis(PUMP_INTERVAL_MS));
        }
    });
    (handle, stop)
}

/// 一套已启动的隧道 IO：netloop 任务句柄 + 停止开关 + 内核侧桥接端点。
pub struct TunnelIo {
    pub task: JoinHandle<()>,
    pub stop: Arc<AtomicBool>,
    /// 内核侧：net_tx 给 pump_in（内核→数据面），net_rx 给 pump_out（数据面→内核）
    pub net_tx: std::sync::mpsc::Sender<Vec<u8>>,
    pub net_rx: std::sync::mpsc::Receiver<Vec<u8>>,
}

impl TunnelIo {
    /// 用给定的数据面与通道端点组装（不含真实网卡线程 —— 由调用方按平台启动）。
    pub fn new(dataplane: Dataplane) -> Self {
        let (adapter, net_tx, net_rx) = ChannelAdapter::pair(256);
        let (task, stop) = spawn_dataplane_task(adapter, dataplane);
        Self { task, stop, net_tx, net_rx }
    }

    /// 优雅停止：置位标志并等待任务退出（async）。
    pub async fn shutdown(self) {
        self.stop.store(true, Ordering::Relaxed);
        let _ = self.task.await;
    }
}

/// dev-5 生产隧道泵：数据模式 TLS 流 ⇄ TUN 通道（裸 IP 转发 + keepalive）。
///
/// `stream` 来自 `mp_core::control::ControlClient::open_tunnel`；
/// `leftover` 是握手阶段一并到达的数据模式先导字节（灌入解包器）。
pub struct TunnelPump {
    pub task: JoinHandle<Result<(), mp_core::tunnel::PumpError>>,
    pub stop: Arc<AtomicBool>,
}

impl TunnelPump {
    pub fn spawn<S>(
        mut stream: S,
        leftover: Vec<u8>,
        keepalive_interval: std::time::Duration,
    ) -> Self
    where
        S: tokio::io::AsyncRead + tokio::io::AsyncWrite + Unpin + Send + 'static,
    {
        let (tun, _net_tx, _net_rx) = ChannelAdapter::pair(256);
        Self::spawn_with(stream, leftover, tun, keepalive_interval)
    }

    /// 用外部通道对组装（daemon 生产路径：内核侧端点由调用方交给 TunLink）。
    pub fn spawn_with<S, A>(
        mut stream: S,
        leftover: Vec<u8>,
        mut tun: A,
        keepalive_interval: std::time::Duration,
    ) -> Self
    where
        S: tokio::io::AsyncRead + tokio::io::AsyncWrite + Unpin + Send + 'static,
        A: mp_core::dataplane::Adapter + Send + 'static,
    {
        use mp_core::frame::{PacketStream, TunnelKind};
        use mp_core::tunnel::{pump_async, KeepaliveState, TunnelStats};
        let mut demux = PacketStream::new();
        demux.feed(&leftover);
        let mut ka = KeepaliveState::new(keepalive_interval, mp_core::protocol::KEEPALIVE_MAX_ATTEMPTS, TunnelKind::Tcp);
        let mut stats = TunnelStats::default();
        let stop = Arc::new(AtomicBool::new(false));
        let stop2 = Arc::clone(&stop);
        let task = tokio::spawn(async move {
            // 先把先导字节里的完整包送到 TUN
            while let Ok(Some(item)) = demux.next_item() {
                if let mp_core::frame::StreamItem::IpPacket(pkt) = item {
                    tun.write(&pkt);
                    stats.packets_in += 1;
                }
            }
            pump_async(&mut stream, &mut tun, &mut demux, &mut ka, &mut stats, &stop2).await
        });
        Self { task, stop }
    }

    /// 优雅停止；返回泵的最终结果（Dead/Io 或正常 Ok）。
    pub async fn shutdown(self) -> Result<(), mp_core::tunnel::PumpError> {
        self.stop.store(true, Ordering::Relaxed);
        match tokio::time::timeout(std::time::Duration::from_secs(5), self.task).await {
            Ok(Ok(res)) => res,
            Ok(Err(join)) => Err(mp_core::tunnel::PumpError::Io(std::io::Error::other(format!("join: {join}")))),
            Err(_) => Err(mp_core::tunnel::PumpError::Io(std::io::Error::other("shutdown timeout"))),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::time::Duration;

    #[tokio::test]
    async fn tunnelio_runs_and_shuts_down() {
        let io = TunnelIo::new(Dataplane::new([10, 8, 0, 2], 24));
        // 送一个非本机的垃圾 IP 包：数据面应安全丢弃不 panic
        io.net_tx.send(vec![0x45, 0, 0, 20, 0, 0, 0, 0, 64, 6, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2]).unwrap();
        tokio::time::sleep(Duration::from_millis(50)).await;
        io.shutdown().await;
    }

    #[tokio::test]
    async fn shutdown_is_idempotent_on_channel_close() {
        let io = TunnelIo::new(Dataplane::new([10, 8, 0, 2], 24));
        drop(io.net_tx.clone()); // 提前断开一个克隆 sender
        io.shutdown().await;
    }

    #[tokio::test(flavor = "multi_thread", worker_threads = 2)]
    async fn tunnel_pump_end_to_end() {
        use tokio::io::{duplex, AsyncReadExt, AsyncWriteExt};

        let (client, mut server) = duplex(64 * 1024);
        // 对端：先发一个下行 IP 包，随后回显
        let peer = tokio::spawn(async move {
            let mut pkt = vec![0u8; 28];
            pkt[0] = 0x45;
            pkt[2..4].copy_from_slice(&28u16.to_be_bytes());
            pkt[9] = 17;
            server.write_all(&pkt).await.unwrap();
            let mut buf = [0u8; 4096];
            loop {
                match server.read(&mut buf).await {
                    Ok(0) | Err(_) => break,
                    Ok(n) => {
                        if server.write_all(&buf[..n]).await.is_err() {
                            break;
                        }
                    }
                }
            }
        });

        let pump = TunnelPump::spawn(client, Vec::new(), std::time::Duration::from_secs(30));
        pump.shutdown().await.unwrap();
        let _ = peer.await;
    }

    #[tokio::test(flavor = "multi_thread", worker_threads = 2)]
    async fn tunnel_pump_with_external_channels() {
        use mp_core::dataplane::TokioChannelAdapter;
        use tokio::io::{duplex, AsyncReadExt, AsyncWriteExt};

        let (client, mut server) = duplex(64 * 1024);
        let peer = tokio::spawn(async move {
            let mut pkt = vec![0u8; 28];
            pkt[0] = 0x45;
            pkt[2..4].copy_from_slice(&28u16.to_be_bytes());
            pkt[9] = 17;
            server.write_all(&pkt).await.unwrap();
            let mut buf = [0u8; 4096];
            loop {
                match server.read(&mut buf).await {
                    Ok(0) | Err(_) => break,
                    Ok(n) => {
                        if server.write_all(&buf[..n]).await.is_err() {
                            break;
                        }
                    }
                }
            }
        });

        let (adapter, kernel_tx, mut kernel_rx) = TokioChannelAdapter::pair(64);
        let pump = TunnelPump::spawn_with(client, Vec::new(), adapter, std::time::Duration::from_secs(30));
        // 下行：内核通道收到包
        let down = tokio::time::timeout(Duration::from_secs(2), kernel_rx.recv())
            .await
            .unwrap()
            .unwrap();
        assert_eq!(down.len(), 28);
        // 上行：内核通道送包 → 隧道 → 回显 → 下行再收到
        let mut up = vec![0u8; 20];
        up[0] = 0x45;
        up[2..4].copy_from_slice(&20u16.to_be_bytes());
        up[9] = 6;
        kernel_tx.send(up.clone()).await.unwrap();
        let echoed = tokio::time::timeout(Duration::from_secs(2), kernel_rx.recv())
            .await
            .unwrap()
            .unwrap();
        assert_eq!(echoed, up);
        pump.shutdown().await.unwrap();
        let _ = peer.await;
    }

    #[tokio::test(flavor = "multi_thread", worker_threads = 2)]
    async fn tunnel_pump_consumes_leftover_preamble() {
        use mp_core::dataplane::TokioChannelAdapter;
        use tokio::io::duplex;
        // leftover：一个完整 28B IP 包 + 半个包（等流补齐 —— 这里不补，仅验证完整包送达）
        let mut pkt = vec![0u8; 28];
        pkt[0] = 0x45;
        pkt[2..4].copy_from_slice(&28u16.to_be_bytes());
        pkt[9] = 17;
        let mut leftover = pkt.clone();
        leftover.extend_from_slice(&[0x45, 0, 0, 40]); // 40B 包的头 4 字节

        let (client, _server) = duplex(64 * 1024);
        let (adapter, _kernel_tx, mut kernel_rx) = TokioChannelAdapter::pair(16);
        let pump = TunnelPump::spawn_with(client, leftover, adapter, std::time::Duration::from_secs(30));
        let got = tokio::time::timeout(Duration::from_secs(2), kernel_rx.recv())
            .await
            .unwrap()
            .unwrap();
        assert_eq!(got, pkt);
        pump.shutdown().await.unwrap();
    }
}
