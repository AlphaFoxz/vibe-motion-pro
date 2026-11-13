//! mp-platform: 各平台虚拟网卡 / 路由 / DNS / 系统服务封装。
//! Windows: wintun.dll；macOS: utun；Linux: tun。

use thiserror::Error;

#[derive(Debug, Error)]
pub enum PlatformError {
    #[error("adapter error: {0}")]
    Adapter(String),
    #[error("route error: {0}")]
    Route(String),
    #[error("dns error: {0}")]
    Dns(String),
}

/// 虚拟网卡句柄（对齐原版 vl3vpn.dll 能力）。
pub struct VpnAdapter {
    pub name: String,
    pub mtu: u16,
}

impl VpnAdapter {
    pub fn open(_name: &str, _mtu: u16) -> Result<Self, PlatformError> {
        // TODO: 按平台 cfg 实现
        Err(PlatformError::Adapter("not implemented".into()))
    }

    pub fn add_route(&self, _cidr: &str) -> Result<(), PlatformError> {
        Err(PlatformError::Route("not implemented".into()))
    }

    pub fn set_dns(&self, _servers: &[String]) -> Result<(), PlatformError> {
        Err(PlatformError::Dns("not implemented".into()))
    }
}
