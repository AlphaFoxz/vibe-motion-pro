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

pub mod adapter;
pub mod netcfg;
pub mod route;

// netcfg 的平台命令序列测试见 netcfg::tests（后端注入，任意宿主可跑
// 任意平台的 DryRun 演练）。
