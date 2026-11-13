//! mp-ipc: UI 进程 <-> 守护进程 本地 IPC。
//! ndjson 行协议；传输抽象：TCP loopback（开发/测试）+ 平台本地管道（生产）。

use serde::{Deserialize, Serialize};
use thiserror::Error;

use crate::status::StatusSnapshot;

pub mod codec;
pub mod profile;
pub mod status;
pub mod transport;

#[derive(Debug, Error)]
pub enum IpcError {
    #[error("io error: {0}")]
    Io(#[from] std::io::Error),
    #[error("serde error: {0}")]
    Serde(#[from] serde_json::Error),
    #[error("connection closed")]
    Closed,
}

#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
#[serde(tag = "type", rename_all = "snake_case")]
pub enum Request {
    Start { profile_id: String },
    /// 免浏览器直连登录（内化登录）：凭据 + 手机 App 动态密保码。
    /// 走 web 登录 → postlogin → /vpntunnel 全链路（对齐原版 an_vpn.js 参数流）。
    Connect {
        /// 门户主机（登录服务器，如 vpn.example.com）
        host: String,
        port: u16,
        username: String,
        password: String,
        /// 手机 App 每分钟更新的动态密保码
        code: String,
    },
    Stop,
    Status,
    GetSession,
    SetReconnect { enabled: bool, max_attempts: u32 },
    ListWireGuard,
    ListProfiles,
    AddProfile { profile: crate::profile::ProfileMsg },
    RemoveProfile { profile_id: String },
}

#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
#[serde(tag = "type", rename_all = "snake_case")]
pub enum Response {
    Status { status: StatusSnapshot },
    StatusUpdate { status: StatusSnapshot },
    Session { session_id: Option<String> },
    Profiles { profiles: Vec<crate::profile::ProfileMsg> },
    Ok,
    Error { message: String },
}
