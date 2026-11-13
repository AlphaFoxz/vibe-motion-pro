//! TUN 网卡接线（dev-7）：隧道泵通道 ⇄ 内核网卡 + 路由/DNS 接管。
//!
//! 架构：tun crate "async" feature（tokio AsyncRead/AsyncWrite）——
//! 单个异步网桥任务 select 双向转发（Windows wintun 设备不可 clone，
//! 双线程方案在 Windows 不可行，异步 select 是跨平台正解）。
//!
//! 失败降级策略（可用性优先）：
//! - 无管理员权限 / 无 wintun：**不阻断**隧道（登录与握手照常，仅无本地转发）
//! - 'U' 网络配置缺失（虚拟 IP 未知）：网卡用缺省地址打开，**不下发路由**（避免错误接管默认路由断网）
//! - Drop/teardown 时回滚全部路由与 DNS（RouteManager 逆序还原，幂等）

use mp_platform::adapter::TunAdapter;
use mp_platform::netcfg::{RouteManager, SystemRunner};
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::Arc;

/// 一次已接线的网卡会话：网桥任务 + 停止标志 + 路由回滚器。
pub struct TunLink {
    stop: Arc<AtomicBool>,
    bridge: tokio::task::JoinHandle<()>,
    routes: Option<RouteManager>,
    iface: String,
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

        let adapter = TunAdapter::open(&cfg).map_err(|e| e.to_string())?;
        let iface = adapter.name.clone();
        let mut dev = adapter.into_async_device().map_err(|e| e.to_string())?;

        // 异步网桥：select 双向转发
        let stop = Arc::new(AtomicBool::new(false));
        let stop_bridge = Arc::clone(&stop);
        let bridge = tokio::spawn(async move {
            use tokio::io::{AsyncReadExt, AsyncWriteExt};
            let mut buf = vec![0u8; 65_535];
            while !stop_bridge.load(Ordering::Relaxed) {
                tokio::select! {
                    r = dev.read(&mut buf) => {
                        match r {
                            Ok(0) | Err(_) => break,
                            Ok(n) => {
                                if kernel_tx.send(buf[..n].to_vec()).await.is_err() {
                                    break; // 隧道侧已关
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
                            None => break, // 隧道侧已关
                        }
                    }
                }
            }
        });

        // 路由/DNS 接管：仅当服务器明确下发了虚拟 IP 才动系统网络（安全默认）
        let mut mgr = RouteManager::new(Arc::new(SystemRunner), &ip.to_string(), &iface);
        let mut route_mgr = None;
        if veth_ip.is_some() {
            let mut applied = false;
            for r in routes {
                if mgr.add_route(r).is_ok() {
                    applied = true;
                }
            }
            if !dns.is_empty() {
                let servers: Vec<String> = dns.iter().map(|d| d.to_string()).collect();
                if mgr.set_dns(&servers).is_ok() {
                    applied = true;
                }
            }
            if applied {
                route_mgr = Some(mgr);
            }
        }

        Ok(Self { stop, bridge, routes: route_mgr, iface })
    }

    /// 停止网桥并回滚路由/DNS（幂等）。
    pub fn teardown(&mut self) {
        self.stop.store(true, Ordering::Relaxed);
        self.bridge.abort();
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
        match TunLink::bring_up(tx, rx2, None, None, vec![], &[]).await {
            Ok(mut link) => link.teardown(),
            Err(_) => {}
        }
    }
}
