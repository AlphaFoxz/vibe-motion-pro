//! 状态快照（对齐原版三态 + 附加信息）。

use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
pub struct StatusSnapshot {
    /// disconnected | connecting | connected | reconnecting
    pub state: String,
    pub rtt_ms: Option<u32>,
    pub server_ip: Option<String>,
    pub client_ip: Option<String>,
}

impl StatusSnapshot {
    pub fn disconnected() -> Self {
        Self { state: "disconnected".into(), rtt_ms: None, server_ip: None, client_ip: None }
    }
}
