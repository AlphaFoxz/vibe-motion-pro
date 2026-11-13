//! Profile DTO（IPC 传输用，与 mp-core::profile 字段一致）。

use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
pub struct ProfileMsg {
    pub id: String,
    pub name: String,
    pub host: String,
    pub port: u16,
    /// tcp | udp | dtls | wireguard
    pub tunnel_type: String,
    pub autoconnect: bool,
}
