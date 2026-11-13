//! 会话与认证状态。
//! TODO: 按逆向文档填充 /vpntunnel 请求/响应与认证字段。

use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct Credentials {
    pub username: String,
    pub password: String,
    /// AAA 认证方式名（对应 ArrayGetAAAMethodInfo）
    pub aaa_method: Option<String>,
    /// 硬件指纹（对应 HWIDType）
    pub hwid: Option<String>,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct Session {
    pub session_id: String,
    pub server: String,
    pub tunnel_type: TunnelType,
}

#[derive(Debug, Clone, Copy, Serialize, Deserialize, PartialEq, Eq, Default)]
#[serde(rename_all = "snake_case")]
pub enum TunnelType {
    #[default]
    Tcp,
    Udp,
    Dtls,
    WireGuard,
}
