//! TUN 网卡接线（dev-7）：隧道泵通道 ⇄ 内核网卡 + 路由/DNS 接管。
//!
//! 架构（Windows 教训后的定型）：
//! - **Windows：wintun Session + 两个专职 std 线程**（读线程阻塞 receive、
//!   写线程阻塞收包后 send）。阻塞只发生在自有线程上，绝不触碰 tokio。
//!   曾经用 tun crate 0.6.1 的 async 层，其 poll_read 持锁阻塞 + 每 poll
//!   起线程的缺陷让整个 tokio runtime 冻结（真机实测 ~5 分钟必现）。
//! - 非 Windows：tun crate async 网桥（utun / /dev/net/tun 上无此缺陷报告）。
//!
//! 失败降级策略（可用性优先）：
//! - 无管理员权限 / 无 wintun：**不阻断**隧道（登录与握手照常，仅无本地转发）
//! - 'U' 网络配置缺失（虚拟 IP 未知）：网卡用缺省地址打开，**不下发路由**（避免错误接管默认路由断网）
//! - Drop/teardown 时回滚全部路由与 DNS（RouteManager 逆序还原，幂等）

use mp_platform::adapter::TunAdapter;
use mp_platform::netcfg::{RouteManager, SystemRunner};
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::Arc;

/// 一次已接线的网卡会话：读写线程 + 停止标志 + 路由回滚器。
pub struct TunLink {
    stop: Arc<AtomicBool>,
    bridge: BridgeHandle,
    routes: Option<RouteManager>,
    iface: String,
}

/// 平台网桥句柄（Windows=两个 std 线程；其他=tokio 任务）。
pub struct BridgeHandle {
    #[cfg(target_os = "windows")]
    reader: Option<std::thread::JoinHandle<()>>,
    #[cfg(target_os = "windows")]
    writer: Option<std::thread::JoinHandle<()>>,
    #[cfg(not(target_os = "windows"))]
    task: Option<tokio::task::JoinHandle<()>>,
    /// wintun 会话（teardown 时 shutdown 解除读线程阻塞）
    #[cfg(target_os = "windows")]
    session: Option<std::sync::Arc<wintun::Session>>,
}

impl BridgeHandle {
    fn stop(&mut self, stop: &AtomicBool) {
        stop.store(true, Ordering::Relaxed);
        #[cfg(target_os = "windows")]
        {
            if let Some(s) = self.session.take() {
                let _ = s.shutdown(); // 解除 receive_blocking 阻塞
            }
            // 线程随通道关闭自行退出，不 join（writer 可能还阻塞在通道上）
            self.reader = None;
            self.writer = None;
        }
        #[cfg(not(target_os = "windows"))]
        {
            if let Some(t) = self.task.take() {
                t.abort();
            }
        }
    }
}

impl TunLink {
    /// 接线（需在 tokio runtime 上下文调用）：
    /// - `kernel_tx`：内核 → 隧道（TokioChannelAdapter 侧）
    /// - `kernel_rx`：隧道 → 内核
    /// - `veth_ip/netmask/dns`：来自 'U' 网络配置；None/空 → 降级
    pub async fn bring_up(
        kernel_tx: tokio::sync::mpsc::Sender<Vec<u8>>,
        mut kernel_rx: tokio::sync::mpsc::Receiver<Vec<u8>>,
        veth_ip: Option<std::net::Ipv4Addr>,
        netmask: Option<std::net::Ipv4Addr>,
        dns: Vec<std::net::Ipv4Addr>,
        routes: &[String],
    ) -> Result<Self, String> {
        let ip = veth_ip.unwrap_or(std::net::Ipv4Addr::new(10, 111, 222, 2));
        let mask = netmask.unwrap_or(std::net::Ipv4Addr::new(255, 255, 255, 0));
        let cfg = mp_platform::adapter::TunConfig {
            name: "mp-tun".into(),
            address: ip,
            netmask: mask,
            mtu: 1400,
        };

        // 网卡创建（wintun 驱动交互 + netsh MTU）也含阻塞调用，挪出 async 线程。
        // 注意：async 侧绝不能 std::thread::join —— join 会把当前 tokio worker
        // 连同驱动它的定时器轮一起冻结（freeze_auto.txt 12:17 实证：join 期间
        // 所有 tokio 定时器停摆 → 心跳停 → 看门狗误杀）。改用 oneshot 异步等。
        let adapter = {
            let cfg = cfg.clone();
            let (tx, rx) = tokio::sync::oneshot::channel();
            std::thread::Builder::new()
                .name("mp-adapter-open".into())
                .spawn(move || {
                    let res = TunAdapter::open(&cfg).map_err(|e| e.to_string());
                    let _ = tx.send(res);
                })
                .map_err(|e| format!("spawn adapter open: {e}"))?;
            rx.await
                .map_err(|_| "adapter open thread panicked".to_string())??
        };
        let iface = adapter.name.clone();

        let stop = Arc::new(AtomicBool::new(false));

        #[cfg(target_os = "windows")]
        let bridge = {
            // wintun 原生：专职读写线程（阻塞仅在自有线程；修复 runtime 冻结）
            let session = adapter.session();
            let stop_r = Arc::clone(&stop);
            let reader_session = session.clone();
            let reader = std::thread::Builder::new()
                .name("mp-tun-reader".into())
                .spawn(move || {
                    loop {
                        if stop_r.load(Ordering::Relaxed) {
                            break;
                        }
                        match reader_session.receive_blocking() {
                            Ok(pkt) => {
                                // try_send + 满即丢：TCP 自己会重传，内核侧专职
                                // 线程绝不能在满通道上永久阻塞（真机冻结栈实锤：
                                // blocking_send 卡死 → 泵死无人消费 → 连锁冻结）
                                match kernel_tx.try_send(pkt.bytes().to_vec()) {
                                    Ok(()) => {}
                                    Err(tokio::sync::mpsc::error::TrySendError::Full(_)) => {
                                        // 丢弃：等待 1ms 再读，避免空转
                                        std::thread::sleep(std::time::Duration::from_millis(1));
                                    }
                                    Err(tokio::sync::mpsc::error::TrySendError::Closed(_)) => break,
                                }
                            }
                            Err(_) => break, // 会话关闭/停机
                        }
                    }
                })
                .map_err(|e| format!("spawn reader: {e}"))?;

            let writer_session = session.clone();
            let stop_w = Arc::clone(&stop);
            let writer = std::thread::Builder::new()
                .name("mp-tun-writer".into())
                .spawn(move || {
                    loop {
                        if stop_w.load(Ordering::Relaxed) {
                            break;
                        }
                        match kernel_rx.blocking_recv() {
                            Some(pkt) => {
                                if pkt.len() > u16::MAX as usize {
                                    continue;
                                }
                                if let Ok(mut p) =
                                    writer_session.allocate_send_packet(pkt.len() as u16)
                                {
                                    p.bytes_mut().copy_from_slice(&pkt);
                                    writer_session.send_packet(p);
                                }
                            }
                            None => break, // 隧道侧已关
                        }
                    }
                })
                .map_err(|e| format!("spawn writer: {e}"))?;

            BridgeHandle { reader: Some(reader), writer: Some(writer), session: Some(session) }
        };

        #[cfg(not(target_os = "windows"))]
        let bridge = {
            let mut dev = adapter.into_async_device().map_err(|e| e.to_string())?;
            let stop_bridge = Arc::clone(&stop);
            let task = tokio::spawn(async move {
                use tokio::io::{AsyncReadExt, AsyncWriteExt};
                let mut buf = vec![0u8; 65_535];
                while !stop_bridge.load(Ordering::Relaxed) {
                    tokio::select! {
                        r = dev.read(&mut buf) => {
                            match r {
                                Ok(0) | Err(_) => break,
                                Ok(n) => {
                                    if kernel_tx.send(buf[..n].to_vec()).await.is_err() {
                                        break;
                                    }
                                }
                            }
                        }
                        pkt = kernel_rx.recv() => {
                            match pkt {
                                Some(p) => {
                                    if dev.write_all(&p).await.is_err() {
                                        break;
                                    }
                                }
                                None => break,
                            }
                        }
                    }
                }
            });
            BridgeHandle { task: Some(task) }
        };

        // 路由/DNS 接管：仅当服务器明确下发了虚拟 IP 才动系统网络（安全默认）。
        // 全部子进程操作挪进 spawn_blocking：route/netsh 是同步阻塞调用，
        // 直接在 async 线程跑会把主循环心跳饿死（freeze_auto.txt 实证，
        // 73 条路由 × 每条 2 个子进程阻塞 >15s → 冻结看门狗开火）。
        // 等待方式必须是异步的：连接流程需等路由就绪才能通告已连接，
        // 但 std::thread::join 会冻结定时器轮（12:17 冻结第 2 根因）。
        let mgr = {
            let iface = iface.clone();
            let gw = ip.to_string();
            let routes: Vec<String> = routes.to_vec();
            let dns: Vec<String> = dns.iter().map(|d| d.to_string()).collect();
            let enabled = veth_ip.is_some();
            let (tx, rx) = tokio::sync::oneshot::channel();
            std::thread::Builder::new()
                .name("mp-route-setup".into())
                .spawn(move || {
                    let result = (|| -> Option<RouteManager> {
                        if !enabled {
                            return None;
                        }
                        let mut mgr = RouteManager::new(Arc::new(SystemRunner), &gw, &iface);
                        let mut applied = false;
                        for r in &routes {
                            match mgr.add_route(r) {
                                Ok(()) => applied = true,
                                Err(e) => tracing::warn!("add_route {r} failed: {e}"),
                            }
                        }
                        if !dns.is_empty() && mgr.set_dns(&dns).is_ok() {
                            applied = true;
                        }
                        applied.then_some(mgr)
                    })();
                    let _ = tx.send(result);
                })
                .map_err(|e| format!("spawn route setup: {e}"))?;
            rx.await
                .map_err(|_| "route setup thread panicked".to_string())?
        };

        Ok(Self { stop, bridge, routes: mgr, iface })
    }

    /// 停止网桥并回滚路由/DNS（幂等）。
    pub fn teardown(&mut self) {
        self.bridge.stop(&self.stop);
        if let Some(m) = &mut self.routes {
            let _ = m.revert();
        }
        self.routes = None;
    }

    pub fn iface(&self) -> &str {
        &self.iface
    }
}

impl Drop for TunLink {
    fn drop(&mut self) {
        self.teardown();
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[tokio::test]
    async fn bring_up_fails_gracefully_without_admin() {
        // 非管理员环境：打开网卡失败 → Err（调用方降级不阻断）；有管理员则正常接线
        let (tx, _rx) = tokio::sync::mpsc::channel(16);
        let (_tx2, rx2) = tokio::sync::mpsc::channel(16);
        if let Ok(mut link) = TunLink::bring_up(tx, rx2, None, None, vec![], &[]).await {
            link.teardown();
        }
    }

    #[tokio::test]
    async fn teardown_is_idempotent() {
        let (tx, _rx) = tokio::sync::mpsc::channel(16);
        let (_tx2, rx2) = tokio::sync::mpsc::channel(16);
        if let Ok(mut link) = TunLink::bring_up(tx, rx2, None, None, vec![], &[]).await {
            link.teardown();
            link.teardown(); // 二次调用不 panic
        }
    }
}
