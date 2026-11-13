//! mp-ipc: UI 进程 <-> 守护进程 的本地 IPC 协议。
//! 传输层：Windows named pipe / macOS+Linux unix domain socket。
//! 消息先用 JSON 行协议（ndjson），后续可演进 protobuf。

use serde::{Deserialize, Serialize};

#[derive(Debug, Serialize, Deserialize)]
#[serde(tag = "type", rename_all = "snake_case")]
pub enum Request {
    Start { profile_id: String },
    Stop,
    Status,
    GetSession,
    SetReconnect { enabled: bool, interval_secs: u32 },
    ListWireGuard,
}

#[derive(Debug, Serialize, Deserialize)]
#[serde(tag = "type", rename_all = "snake_case")]
pub enum Response {
    Status { status: crate::status::StatusSnapshot },
    Session { session_id: String },
    Ok,
    Error { message: String },
}

pub mod status {
    use serde::{Deserialize, Serialize};

    #[derive(Debug, Serialize, Deserialize)]
    pub struct StatusSnapshot {
        pub state: String, // disconnected | connecting | connected | reconnecting
        pub rtt_ms: Option<u32>,
        pub server_ip: Option<String>,
        pub client_ip: Option<String>,
    }
}
