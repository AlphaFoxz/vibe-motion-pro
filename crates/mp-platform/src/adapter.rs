//! 真实虚拟网卡适配器（对齐原版 vl3vpn.dll 的虚拟网卡能力）。
//!
//! 实现策略（按平台分裂，Windows 有重大教训）：
//! - **Windows：直接使用 `wintun` crate（0.5，2026-11-14 从 0.3 升级 —— 0.3.2 钉死
//!   windows ^0.51 全家桶，0.5.1 改用 windows-sys ^0.52 与本 crate 一致；API 兼容零改动，
//!   见 commit 993b564）。**
//!   曾经走 `tun` crate 0.6.1 的 async 层，但其 `poll_read` 实现存在致命缺陷：
//!   1. 每次无数据 poll 都 `thread::spawn` 一个阻塞读线程（线程泄漏）
//!   2. 该线程**持有 std Mutex 调用 `receive_blocking()`**（持锁无限期等待）
//!   3. 异步路径 `cached.lock()` 同步抢锁 —— 服务器侧停止下发数据后，
//!      tokio worker 线程逐个卡死在这把锁上，**整个 runtime 冻结**
//!      （真机实测：连接 ~5 分钟后全任务消失、CPU 归零、无任何日志）
//!
//! 现改为 mp-daemon 的专职读写 std 线程直接驱动 Session（阻塞只发生在
//! 自有线程上），彻底绕开 tun crate 的 async 机制。
//! - 非 Windows：`tun` crate（/dev/net/tun、utun），行为不变
//! - `TunAdapter` 提供阻塞式 `read_packet`/`write_packet`，
//!   供 mp-daemon 用独立线程跑阻塞读写，再经 mpsc 桥接进 mp-core 数据面
//!   （见 mp-core::dataplane::ChannelAdapter）
//! - wintun.dll 需随应用分发（build.rs 拷贝到 exe 旁）

use crate::PlatformError;

/// 虚拟网卡打开参数。
#[derive(Debug, Clone)]
pub struct TunConfig {
    /// 接口名（Windows 为 wintun 适配器名；Linux 尽量用 tun{n}；macOS 忽略由系统分配 utun{n}）
    pub name: String,
    /// 本端 IPv4（隧道内地址，服务器分配）
    pub address: std::net::Ipv4Addr,
    /// 掩码
    pub netmask: std::net::Ipv4Addr,
    /// MTU（对齐原版 ~1400，隧道开销预留）
    pub mtu: u16,
}

impl Default for TunConfig {
    fn default() -> Self {
        Self {
            name: "mp-tun".into(),
            address: std::net::Ipv4Addr::new(10, 111, 222, 1),
            netmask: std::net::Ipv4Addr::new(255, 255, 255, 0),
            mtu: 1400,
        }
    }
}

// ===================== Windows：wintun crate 原生实现 =====================

#[cfg(target_os = "windows")]
pub mod imp {
    use super::{PlatformError, TunConfig};

    /// 已打开的虚拟网卡（wintun 原生）。
    /// `session()` 供 mp-daemon 的专职读写线程直接驱动（Send+Sync）。
    pub struct TunAdapter {
        session: std::sync::Arc<wintun::Session>,
        _adapter: std::sync::Arc<wintun::Adapter>,
        pub name: String,
        pub mtu: u16,
    }

    impl TunAdapter {
        /// 打开/创建虚拟网卡并启用。需要管理员权限（由特权 daemon 调用）。
        pub fn open(cfg: &TunConfig) -> Result<Self, PlatformError> {
            // DLL 搜索路径含 exe 目录（build.rs 已拷贝）
            let wintun = unsafe { wintun::load() }
                .map_err(|e| PlatformError::Adapter(format!("wintun load: {e}")))?;
            let adapter = wintun::Adapter::create(&wintun, &cfg.name, "MotionPro", None)
                .map_err(|e| PlatformError::Adapter(format!("adapter create: {e}")))?;
            adapter
                .set_network_addresses_tuple(
                    std::net::IpAddr::V4(cfg.address),
                    std::net::IpAddr::V4(cfg.netmask),
                    None,
                )
                .map_err(|e| PlatformError::Adapter(format!("set address: {e}")))?;
            let session = std::sync::Arc::new(
                adapter
                    .start_session(wintun::MAX_RING_CAPACITY)
                    .map_err(|e| PlatformError::Adapter(format!("start session: {e}")))?,
            );
            // 接口 MTU（尽力而为；wintun 环形缓冲不受此限制）。
            // 复用 SystemRunner：带 15s 超时 + CREATE_NO_WINDOW（裸 .output()
            // 曾在真机永久挂起）。
            let _ = crate::netcfg::CommandRunner::run(
                &crate::netcfg::SystemRunner,
                &[
                    "netsh".into(),
                    "interface".into(),
                    "ipv4".into(),
                    "set".into(),
                    "subinterface".into(),
                    cfg.name.clone(),
                    format!("mtu={}", cfg.mtu),
                    "store=persistent".into(),
                ],
            );
            Ok(Self { session, _adapter: adapter, name: cfg.name.clone(), mtu: cfg.mtu })
        }

        /// wintun 会话句柄（Send+Sync；专职线程阻塞驱动的正确载体）。
        pub fn session(&self) -> SessionHandle {
            SessionHandle(self.session.clone())
        }

        /// 阻塞读取一个来自内核的 IP 包（仅在专职线程上使用）。
        pub fn read_packet(&mut self, buf: &mut [u8]) -> Result<usize, PlatformError> {
            let pkt = self
                .session
                .receive_blocking()
                .map_err(|e| PlatformError::Adapter(format!("receive: {e}")))?;
            let bytes = pkt.bytes();
            let n = bytes.len().min(buf.len());
            buf[..n].copy_from_slice(&bytes[..n]);
            Ok(n)
        }

        /// 阻塞写一个 IP 包到内核（wintun send 为非阻塞拷贝进环形缓冲）。
        pub fn write_packet(&mut self, packet: &[u8]) -> Result<usize, PlatformError> {
            let mut p = self
                .session
                .allocate_send_packet(packet.len() as u16)
                .map_err(|e| PlatformError::Adapter(format!("allocate send: {e}")))?;
            let n = p.bytes_mut().len();
            p.bytes_mut().copy_from_slice(packet);
            self.session.send_packet(p);
            Ok(n)
        }
    }

    /// 可跨线程克隆的会话句柄：mp-daemon 的专职读写线程用它阻塞驱动网卡。
    /// 平台类型不外漏 —— daemon 不直接依赖 wintun crate，只认这个抽象。
    #[derive(Clone)]
    pub struct SessionHandle(std::sync::Arc<wintun::Session>);

    impl SessionHandle {
        /// 阻塞读一个来自内核的 IP 包（仅在专职线程上使用）。
        /// 会话关闭/停机返回 None。
        pub fn receive_blocking(&self) -> Option<Vec<u8>> {
            self.0.receive_blocking().ok().map(|p| p.bytes().to_vec())
        }

        /// 写一个 IP 包到内核（拷入环形缓冲，非阻塞；超长包丢弃返回 false）。
        pub fn send(&self, packet: &[u8]) -> bool {
            if packet.len() > u16::MAX as usize {
                return false;
            }
            match self.0.allocate_send_packet(packet.len() as u16) {
                Ok(mut p) => {
                    p.bytes_mut().copy_from_slice(packet);
                    self.0.send_packet(p);
                    true
                }
                Err(_) => false,
            }
        }

        /// 关闭会话（解除阻塞读线程的等待）。
        pub fn shutdown(&self) {
            let _ = self.0.shutdown();
        }
    }
}

#[cfg(target_os = "windows")]
pub use imp::{SessionHandle, TunAdapter};

// ===================== 非 Windows：tun crate（utun / /dev/net/tun） =====================

#[cfg(not(target_os = "windows"))]
pub mod imp {
    use super::{PlatformError, TunConfig};
    use tun::Device;
    use tun::platform::Device as TunDevice;

    /// 已打开的虚拟网卡句柄（阻塞读写语义）。
    pub struct TunAdapter {
        dev: TunDevice,
        pub name: String,
        pub mtu: u16,
    }

    impl TunAdapter {
        /// 打开/创建虚拟网卡并启用。需要管理员/root 权限（由特权 daemon 调用）。
        pub fn open(cfg: &TunConfig) -> Result<Self, PlatformError> {
            let mut config = tun::Configuration::default();
            config
                .name(&cfg.name)
                .address(cfg.address)
                .netmask(cfg.netmask)
                .mtu(cfg.mtu as i32)
                .up();
            let dev = tun::create(&config).map_err(|e| PlatformError::Adapter(e.to_string()))?;
            Ok(Self { dev, name: cfg.name.clone(), mtu: cfg.mtu })
        }

        /// 转为异步设备（tun "async" feature：AsyncDevice 实现 tokio AsyncRead/AsyncWrite）。
        pub fn into_async_device(self) -> Result<tun::r#async::AsyncDevice, PlatformError> {
            tun::r#async::AsyncDevice::new(self.dev).map_err(|e| PlatformError::Adapter(e.to_string()))
        }

        /// 当前接口名（macOS 上可能与请求名不同，系统分配 utun{n}）。
        pub fn actual_name(&self) -> Result<String, PlatformError> {
            self.dev.name().map_err(|e| PlatformError::Adapter(e.to_string()))
        }

        /// 阻塞读取一个来自内核的 IP 包。
        pub fn read_packet(&mut self, buf: &mut [u8]) -> Result<usize, PlatformError> {
            use std::io::Read;
            let q = self
                .dev
                .queue(0)
                .ok_or_else(|| PlatformError::Adapter("no queue 0".into()))?;
            let n = q.read(buf).map_err(|e| PlatformError::Adapter(e.to_string()))?;
            Ok(n)
        }

        /// 阻塞写一个 IP 包到内核。
        pub fn write_packet(&mut self, packet: &[u8]) -> Result<usize, PlatformError> {
            use std::io::Write;
            let q = self
                .dev
                .queue(0)
                .ok_or_else(|| PlatformError::Adapter("no queue 0".into()))?;
            let n = q.write(packet).map_err(|e| PlatformError::Adapter(e.to_string()))?;
            Ok(n)
        }
    }
}

#[cfg(not(target_os = "windows"))]
pub use imp::TunAdapter;
