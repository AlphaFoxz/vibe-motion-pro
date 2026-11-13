//! 真实虚拟网卡适配器（对齐原版 vl3vpn.dll 的虚拟网卡能力）。
//!
//! 实现策略：
//! - 底层用 `tun` crate：Windows=wintun.dll、Linux=/dev/net/tun、macOS=utun
//! - `TunAdapter` 提供阻塞式 `read_packet`/`write_packet`，
//!   供 mp-daemon 用独立线程跑阻塞读写，再经 mpsc 桥接进 mp-core 数据面
//!     见 mp-core::dataplane::ChannelAdapter）
//! - wintun.dll 需随应用分发（阶段4 打包项），此处只负责加载调用

use crate::PlatformError;
use tun::Device;
use tun::platform::Device as TunDevice;

/// 虚拟网卡打开参数。
#[derive(Debug, Clone)]
pub struct TunConfig {
    /// 接口名（Windows 为 wintun 会话名；Linux 尽量用 tun{n}；macOS 忽略由系统分配 utun{n}）
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

    /// 克隆设备句柄（供 pump_in/pump_out 双线程分别持读写端；Windows wintun
    /// 后端不支持 clone，跨平台双端请用 `into_device` + tokio 异步网桥）。
    #[cfg(not(target_os = "windows"))]
    pub fn try_clone(&self) -> Result<Self, PlatformError> {
        let dev = self.dev.try_clone().map_err(|e| PlatformError::Adapter(e.to_string()))?;
        Ok(Self { dev, name: self.name.clone(), mtu: self.mtu })
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

/// mp-platform 侧适配器 → mp-core::dataplane::Adapter 的桥接线程循环体。
///
/// 分别在两个独立线程运行（阻塞 IO 与 async 运行时解耦）：
/// - `pump_in`：内核 → tx（交给数据面）
/// - `pump_out`：rx（来自数据面）→ 内核
pub fn pump_in(mut dev: TunAdapter, tx: std::sync::mpsc::Sender<Vec<u8>>, stop: &std::sync::atomic::AtomicBool) {
    let mut buf = vec![0u8; 65535];
    while !stop.load(std::sync::atomic::Ordering::Relaxed) {
        match dev.read_packet(&mut buf) {
            Ok(0) => break,
            Ok(n) => {
                if tx.send(buf[..n].to_vec()).is_err() {
                    break; // 数据面已关闭
                }
            }
            Err(_) => break,
        }
    }
}

pub fn pump_out(
    mut dev: TunAdapter,
    rx: std::sync::mpsc::Receiver<Vec<u8>>,
    stop: &std::sync::atomic::AtomicBool,
) {
    // 非阻塞轮询：recv_timeout 兼顾 stop 检查（避免收不到包时永不退出）
    while !stop.load(std::sync::atomic::Ordering::Relaxed) {
        match rx.recv_timeout(std::time::Duration::from_millis(200)) {
            Ok(packet) => {
                let _ = dev.write_packet(&packet);
            }
            Err(std::sync::mpsc::RecvTimeoutError::Timeout) => continue,
            Err(std::sync::mpsc::RecvTimeoutError::Disconnected) => break,
        }
    }
}
