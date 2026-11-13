//! 隧道数据面泵（dev-5，对齐 Ghidra 逆向出的原版架构）。
//!
//! 原版（vl3vpn.dll）是**纯 L3 转发**：TUN 网卡读出的 IP 包原样 SSL_write 进隧道，
//! 隧道读出的裸 IP 包原样写回网卡 —— 用户态栈不终结内层 TCP。本模块实现该泵：
//!
//! - `Wire`：隧道字节流抽象（TLS/DTLS/明文 UDP 皆可；同步语义，daemon 侧桥接 async）
//! - `pump_once`：一轮转发（wire → PacketStream → TUN；TUN → wire）+ keepalive 定时
//! - `KeepaliveState`：对齐 FUN_100640d0 select 循环 —— 间隔内无响应计数，
//!   达到 `max_attempts` 返回 `Dead` 触发重连（原版错误码 TCP=0x32/UDP=0x79）
//!
//! 心跳 = `frame::KeepAlive`（伪 IPv4，协议号 255），与数据包同一流分发。

use crate::dataplane::Adapter;
use crate::frame::{KeepAlive, PacketStream, StreamItem, TunnelKind};
use std::io;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::{Duration, Instant};

/// 隧道字节流抽象（发送/接收裸字节；由 daemon 用 TLS/DTLS stream 实现）。
pub trait Wire {
    fn send(&mut self, bytes: &[u8]) -> io::Result<()>;
    /// 返回 0 = 对端关闭。
    fn recv(&mut self, buf: &mut [u8]) -> io::Result<usize>;
}

/// keepalive 状态机（Ghidra T1：默认 30s × 3 次 → 重连）。
#[derive(Debug)]
pub struct KeepaliveState {
    pub interval: Duration,
    pub max_attempts: u32,
    kind: TunnelKind,
    last_response: Instant,
    last_send: Option<Instant>,
    attempts: u32,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum KeepaliveVerdict {
    /// 一切正常（或刚收到响应）。
    Alive,
    /// 该发心跳了（本周期尚未发过）。
    SendNow,
    /// 连续 max_attempts 个周期无响应 —— 对端已死。
    Dead,
}

impl KeepaliveState {
    pub fn new(interval: Duration, max_attempts: u32, kind: TunnelKind) -> Self {
        Self {
            interval,
            max_attempts,
            kind,
            last_response: Instant::now(),
            last_send: None,
            attempts: 0,
        }
    }

    /// 收到对端任何报文（数据包或 keepalive）时调用。
    pub fn mark_seen(&mut self) {
        self.last_response = Instant::now();
        self.attempts = 0;
    }

    /// 周期性调用：决定本轮动作。
    pub fn tick(&mut self) -> KeepaliveVerdict {
        if self.last_response.elapsed() < self.interval {
            return KeepaliveVerdict::Alive;
        }
        // 到期但本周期已发过 → 计一次 miss
        if let Some(t) = self.last_send {
            if t >= self.last_response {
                self.attempts += 1;
                self.last_send = None;
                if self.attempts >= self.max_attempts {
                    return KeepaliveVerdict::Dead;
                }
                return KeepaliveVerdict::Alive;
            }
        }
        KeepaliveVerdict::SendNow
    }

    /// 记录"已发送 keepalive"并构造帧。
    pub fn send_keepalive(&mut self, timestamp_ms: u32) -> KeepAlive {
        self.last_send = Some(Instant::now());
        KeepAlive::new(timestamp_ms, self.kind)
    }

    pub fn attempts(&self) -> u32 {
        self.attempts
    }
}

/// 泵错误。
#[derive(Debug)]
pub enum PumpError {
    Io(io::Error),
    /// keepalive 连续超时（对应原版 sess.error=0x32）。
    Dead,
    Frame(crate::frame::FrameError),
}

impl From<io::Error> for PumpError {
    fn from(e: io::Error) -> Self {
        PumpError::Io(e)
    }
}

impl From<crate::frame::FrameError> for PumpError {
    fn from(e: crate::frame::FrameError) -> Self {
        PumpError::Frame(e)
    }
}

/// 统计（对齐原版 DAT_10aea020/10ae9ff0 计数器）。
#[derive(Debug, Default, Clone, Copy, PartialEq)]
pub struct TunnelStats {
    pub packets_in: u64,
    pub bytes_in: u64,
    pub packets_out: u64,
    pub bytes_out: u64,
    pub keepalives_sent: u32,
}

/// 当日毫秒时间戳（原版 GetLocalTime 换算：h*3600+m*60+s 的千倍 + ms）。
fn day_ms(now: std::time::SystemTime) -> u32 {
    let secs = now
        .duration_since(std::time::UNIX_EPOCH)
        .map(|d| d.as_secs())
        .unwrap_or(0);
    ((secs % 86_400) * 1000) as u32
}

/// 一轮隧道泵：
/// 1. wire 尽量读（非阻塞语义由实现方保证；返回 Ok(0) 视为对端关闭 → Io(UnexpectedEof)）
/// 2. 解出的 IP 包写 TUN；keepalive 记响应
/// 3. TUN 读出的包原样发 wire（纯 L3 转发，无封装）
/// 4. keepalive 到期则发送心跳帧
pub fn pump_once(
    wire: &mut dyn Wire,
    tun: &mut dyn Adapter,
    stream: &mut PacketStream,
    ka: &mut KeepaliveState,
    stats: &mut TunnelStats,
    scratch: &mut [u8],
) -> Result<(), PumpError> {
    // 1) wire → TUN
    loop {
        match wire.recv(scratch) {
            Ok(0) => return Err(PumpError::Io(io::Error::new(io::ErrorKind::UnexpectedEof, "tunnel closed"))),
            Ok(n) => {
                stats.bytes_in += n as u64;
                stream.feed(&scratch[..n]);
            }
            Err(e) if e.kind() == io::ErrorKind::WouldBlock => break,
            Err(e) => return Err(PumpError::Io(e)),
        }
    }
    while let Some(item) = stream.next_item()? {
        match item {
            StreamItem::IpPacket(pkt) => {
                tun.write(&pkt);
                stats.packets_in += 1;
            }
            StreamItem::KeepAlive(_) => ka.mark_seen(),
        }
    }
    // 任何下行字节都算"对端活着"（对齐原版 select 循环：有读即清零 miss）
    if stats.bytes_in > 0 {
        ka.mark_seen();
    }

    // 2) TUN → wire（裸 IP 直传）
    while let Some(pkt) = tun.read() {
        wire.send(&pkt)?;
        stats.packets_out += 1;
        stats.bytes_out += pkt.len() as u64;
    }

    // 3) keepalive
    match ka.tick() {
        KeepaliveVerdict::SendNow => {
            let frame = ka.send_keepalive(day_ms(std::time::SystemTime::now()));
            wire.send(&frame.encode())?;
            stats.keepalives_sent += 1;
        }
        KeepaliveVerdict::Dead => return Err(PumpError::Dead),
        KeepaliveVerdict::Alive => {}
    }
    Ok(())
}

/// 异步版泵（daemon 生产路径）：tokio select 多路复用 TLS 流读、周期 tick、TUN 非阻塞读。
///
/// - `stream`：数据模式 TLS 流（`ControlClient::open_tunnel` 的返回值）
/// - `tun`：TUN 适配器（mp-platform ChannelAdapter）
/// - 停止：`stop` 置位后返回 Ok(())
pub async fn pump_async<S>(
    stream: &mut S,
    tun: &mut (dyn Adapter + Send),
    stream_demux: &mut PacketStream,
    ka: &mut KeepaliveState,
    stats: &mut TunnelStats,
    stop: &AtomicBool,
) -> Result<(), PumpError>
where
    S: tokio::io::AsyncRead + tokio::io::AsyncWrite + Unpin,
{
    use tokio::io::{AsyncReadExt, AsyncWriteExt};
    use tokio::time::{sleep, Duration as TokioDuration};
    stream_demux.feed(&[]); // no-op，保留接口对称
    let mut chunk = [0u8; 16_384];
    loop {
        if stop.load(Ordering::Relaxed) {
            return Ok(());
        }
        // 1) 隧道读（最多等一个短周期，期间让出给 TUN/keepalive）
        tokio::select! {
            r = stream.read(&mut chunk) => {
                match r {
                    Ok(0) => return Err(PumpError::Io(io::Error::new(io::ErrorKind::UnexpectedEof, "tunnel closed"))),
                    Ok(n) => {
                        stats.bytes_in += n as u64;
                        stream_demux.feed(&chunk[..n]);
                        while let Some(item) = stream_demux.next_item()? {
                            match item {
                                StreamItem::IpPacket(pkt) => {
                                    tun.write(&pkt);
                                    stats.packets_in += 1;
                                }
                                StreamItem::KeepAlive(_) => ka.mark_seen(),
                            }
                        }
                        ka.mark_seen();
                    }
                    Err(e) => return Err(PumpError::Io(e)),
                }
            }
            _ = sleep(TokioDuration::from_millis(POLL_MS)) => {}
        }
        // 2) TUN → 隧道（裸 IP 直传）
        while let Some(pkt) = tun.read() {
            stream.write_all(&pkt).await?;
            stats.packets_out += 1;
            stats.bytes_out += pkt.len() as u64;
        }
        // 3) keepalive
        match ka.tick() {
            KeepaliveVerdict::SendNow => {
                let frame = ka.send_keepalive(day_ms(std::time::SystemTime::now()));
                stream.write_all(&frame.encode()).await?;
                stats.keepalives_sent += 1;
            }
            KeepaliveVerdict::Dead => return Err(PumpError::Dead),
            KeepaliveVerdict::Alive => {}
        }
    }
}

/// 异步泵的 TUN/keepalive 轮询周期（ms）。
const POLL_MS: u64 = 5;

#[cfg(test)]
mod tests {
    use super::*;
    use crate::frame::KEEPALIVE_LEN;
    use std::collections::VecDeque;
    use std::sync::Arc;

    /// 内存 Wire：to_wire 是对端 → 我们收到的字节；from_wire 是我们发出的字节。
    struct MockWire {
        to_wire: VecDeque<Vec<u8>>,
        from_wire: VecDeque<Vec<u8>>,
        recv_chunk: usize,
    }

    impl MockWire {
        fn new() -> Self {
            Self { to_wire: VecDeque::new(), from_wire: VecDeque::new(), recv_chunk: 4096 }
        }
        fn peer_send(&mut self, bytes: Vec<u8>) {
            self.to_wire.push_back(bytes);
        }
    }

    impl Wire for MockWire {
        fn send(&mut self, bytes: &[u8]) -> io::Result<()> {
            self.from_wire.push_back(bytes.to_vec());
            Ok(())
        }
        fn recv(&mut self, buf: &mut [u8]) -> io::Result<usize> {
            match self.to_wire.pop_front() {
                Some(chunk) => {
                    let n = chunk.len().min(buf.len());
                    buf[..n].copy_from_slice(&chunk[..n]);
                    Ok(n)
                }
                None => Err(io::Error::new(io::ErrorKind::WouldBlock, "empty")),
            }
        }
    }

    fn ipv4(total_len: u16, proto: u8) -> Vec<u8> {
        let mut p = vec![0u8; total_len as usize];
        p[0] = 0x45;
        p[2..4].copy_from_slice(&total_len.to_be_bytes());
        p[9] = proto;
        p
    }

    #[test]
    fn forwards_downstream_packets_to_tun() {
        let mut wire = MockWire::new();
        let mut tun = crate::dataplane::MockAdapter::new();
        let mut stream = PacketStream::new();
        let mut ka = KeepaliveState::new(Duration::from_secs(30), 3, TunnelKind::Tcp);
        let mut stats = TunnelStats::default();
        let mut scratch = [0u8; 4096];

        let pkt = ipv4(32, 6);
        wire.peer_send(pkt.clone());
        pump_once(&mut wire, &mut tun, &mut stream, &mut ka, &mut stats, &mut scratch).unwrap();
        assert_eq!(tun.pop_tx().unwrap(), pkt);
        assert_eq!(stats.packets_in, 1);
        assert_eq!(stats.bytes_in, 32);
    }

    #[test]
    fn forwards_tun_packets_raw_to_wire() {
        let mut wire = MockWire::new();
        let mut tun = crate::dataplane::MockAdapter::new();
        let mut stream = PacketStream::new();
        let mut ka = KeepaliveState::new(Duration::from_secs(30), 3, TunnelKind::Tcp);
        let mut stats = TunnelStats::default();
        let mut scratch = [0u8; 4096];

        let pkt = ipv4(40, 17);
        tun.push_rx(pkt.clone());
        pump_once(&mut wire, &mut tun, &mut stream, &mut ka, &mut stats, &mut scratch).unwrap();
        // 原样直传：字节完全一致（无封装头）
        assert_eq!(wire.from_wire.pop_front().unwrap(), pkt);
        assert_eq!(stats.packets_out, 1);
    }

    #[test]
    fn keepalive_sent_when_interval_elapsed() {
        let mut wire = MockWire::new();
        let mut tun = crate::dataplane::MockAdapter::new();
        let mut stream = PacketStream::new();
        let mut ka = KeepaliveState::new(Duration::from_millis(0), 3, TunnelKind::Tcp);
        let mut stats = TunnelStats::default();
        let mut scratch = [0u8; 4096];

        pump_once(&mut wire, &mut tun, &mut stream, &mut ka, &mut stats, &mut scratch).unwrap();
        let sent = wire.from_wire.pop_front().unwrap();
        assert_eq!(sent.len(), KEEPALIVE_LEN);
        assert_eq!(sent[0], 0x45);
        assert_eq!(sent[9], 0xff);
        assert_eq!(stats.keepalives_sent, 1);
    }

    #[test]
    fn peer_keepalive_resets_misses() {
        let mut ka = KeepaliveState::new(Duration::from_millis(0), 2, TunnelKind::Tcp);
        let mut wire = MockWire::new();
        let mut tun = crate::dataplane::MockAdapter::new();
        let mut stream = PacketStream::new();
        let mut stats = TunnelStats::default();
        let mut scratch = [0u8; 4096];

        // 对端持续回 keepalive：永不 Dead
        for _ in 0..10 {
            wire.peer_send(KeepAlive::new(1, TunnelKind::Tcp).encode().to_vec());
            pump_once(&mut wire, &mut tun, &mut stream, &mut ka, &mut stats, &mut scratch)
                .unwrap();
        }
        assert_eq!(ka.attempts(), 0);
    }

    #[test]
    fn dead_after_max_attempts_without_response() {
        let mut wire = MockWire::new();
        let mut tun = crate::dataplane::MockAdapter::new();
        let mut stream = PacketStream::new();
        let mut ka = KeepaliveState::new(Duration::from_millis(0), 2, TunnelKind::Tcp);
        let mut stats = TunnelStats::default();
        let mut scratch = [0u8; 4096];

        // 第 1 轮：发心跳
        pump_once(&mut wire, &mut tun, &mut stream, &mut ka, &mut stats, &mut scratch).unwrap();
        // 第 2 轮：计 miss → attempts=1
        pump_once(&mut wire, &mut tun, &mut stream, &mut ka, &mut stats, &mut scratch).unwrap();
        assert_eq!(ka.attempts(), 1);
        // 第 3 轮：再发；第 4 轮 attempts=2 >= max → Dead
        let mut r = Ok(());
        for _ in 0..2 {
            r = pump_once(&mut wire, &mut tun, &mut stream, &mut ka, &mut stats, &mut scratch);
        }
        assert!(matches!(r, Err(PumpError::Dead)));
    }

    #[test]
    fn wire_eof_is_error() {
        let mut tun = crate::dataplane::MockAdapter::new();
        let mut stream = PacketStream::new();
        let mut ka = KeepaliveState::new(Duration::from_secs(30), 3, TunnelKind::Tcp);
        let mut stats = TunnelStats::default();
        let mut scratch = [0u8; 4096];

        // 模拟对端关闭：一个空 chunk = EOF
        struct DeadWire;
        impl Wire for DeadWire {
            fn send(&mut self, _: &[u8]) -> io::Result<()> { Ok(()) }
            fn recv(&mut self, _: &mut [u8]) -> io::Result<usize> { Ok(0) }
        }
        let mut dead = DeadWire;
        assert!(matches!(
            pump_once(&mut dead, &mut tun, &mut stream, &mut ka, &mut stats, &mut scratch),
            Err(PumpError::Io(_))
        ));
    }

    // ---- 异步泵端到端（duplex channel 当隧道流 + ChannelAdapter 当 TUN） ----

    #[tokio::test(flavor = "multi_thread", worker_threads = 2)]
    async fn async_pump_forwards_both_directions_and_stops() {
        use crate::dataplane::ChannelAdapter;
        use tokio::io::{duplex, AsyncReadExt, AsyncWriteExt};

        let (mut client, mut server) = duplex(64 * 1024);
        let (mut tun, net_tx, net_rx) = ChannelAdapter::pair(64);
        let mut demux = PacketStream::new();
        let mut ka = KeepaliveState::new(Duration::from_secs(30), 3, TunnelKind::Tcp);
        let mut stats = TunnelStats::default();
        let stop = Arc::new(AtomicBool::new(false));

        // 对端：先发一个下行 IP 包，随后回显收到的所有字节
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

        let stop2 = Arc::clone(&stop);
        let pump = tokio::spawn(async move {
            pump_async(&mut client, &mut tun, &mut demux, &mut ka, &mut stats, &stop2).await
        });

        // 下行：对端发的 IP 包应经泵写到 TUN 通道
        let down = net_rx.recv_timeout(Duration::from_secs(2)).unwrap();
        assert_eq!(down.len(), 28);
        assert_eq!(down[0], 0x45);

        // 上行：TUN 通道送一个包，泵应原样发到隧道（对端回显 → 再从下行收到）
        let mut up = vec![0u8; 20];
        up[0] = 0x45;
        up[2..4].copy_from_slice(&20u16.to_be_bytes());
        up[9] = 6;
        net_tx.send(up.clone()).unwrap();
        let echoed = net_rx.recv_timeout(Duration::from_secs(2)).unwrap();
        assert_eq!(echoed, up);

        // 停止：泵任务应干净退出（client 随任务结束 drop，对端读到 EOF）
        stop.store(true, Ordering::Relaxed);
        let _ = tokio::time::timeout(Duration::from_secs(2), pump).await;
        let _ = peer.await;
    }
}
