//! Profile DTO（IPC 传输用，与 mp-core::profile 字段一致）。

use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
pub struct ProfileMsg {
    pub id: String,
    pub name: String,
    pub host: String,
    pub port: u16,
    /// 最后一次成功登录的用户名（非敏感，随 profile 持久化）。
    /// default：新旧 UI/daemon 混跑时缺字段不报错。
    #[serde(default)]
    pub username: String,
    /// tcp | udp | dtls | wireguard
    pub tunnel_type: String,
    pub autoconnect: bool,
}
