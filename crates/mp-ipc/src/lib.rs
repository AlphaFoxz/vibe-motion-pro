//! mp-ipc: UI 进程 <-> 守护进程 本地 IPC。
//! ndjson 行协议；传输抽象：TCP loopback（开发/测试）+ 平台本地管道（生产）。

use serde::{Deserialize, Serialize};
use thiserror::Error;

use crate::status::StatusSnapshot;

pub mod codec;
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
    Stop,
    Status,
    GetSession,
    SetReconnect { enabled: bool, max_attempts: u32 },
    ListWireGuard,
}

#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
#[serde(tag = "type", rename_all = "snake_case")]
pub enum Response {
    Status { status: StatusSnapshot },
    Session { session_id: Option<String> },
    Ok,
    Error { message: String },
}
