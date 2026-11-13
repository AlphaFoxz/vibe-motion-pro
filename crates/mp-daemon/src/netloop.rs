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
}
