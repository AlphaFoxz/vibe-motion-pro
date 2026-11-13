//! 协议实现：基于 docs/runtime-forensics.md 的运行时取证 + docs/protocol-clues.md 静态分析。
//! 仍待包级抓包确认的字段标注 TODO(抓包)。

use serde::{Deserialize, Serialize};
use thiserror::Error;

/// 网关服务端口（实测 443，TLS 1.2）。
pub const GATEWAY_PORT: u16 = 443;

/// 认证方式查询端点（证据：aaa.c:431 GET /prx/000/http/localhost/an_login.js）。
pub const AN_LOGIN_PATH: &str = "/prx/000/http/localhost/an_login.js";

/// postlogin 资源查询（证据：common.c:5514，65200 为服务端 web 端口）。
pub const POSTLOGIN_APPS_PATH: &str = "/prx/000/http/localhost:65200/motionpro/postlogin/apps";

/// 数据隧道通道（静态证据 vl3vpn.dll：`GET %s/vpntunnel HTTP/1.1`）。
pub const VPNTUNNEL_PATH: &str = "/vpntunnel";

/// 服务器 Keep-Alive 头（实测 `timeout=15, max=100`）。
pub const SERVER_KEEPALIVE_TIMEOUT_SECS: u64 = 15;

/// vpnd 状态轮询周期（实测日志：detect_vni_status_thread 每 1 秒）。
pub const STATUS_POLL_INTERVAL_SECS: u64 = 1;

/// TCP 隧道心跳间隔（实测抓包：C→S 85B TLS record ≈ 4.4 包/秒，见 runtime-forensics.md）。
pub const TCP_TUNNEL_KEEPALIVE_MS: u64 = 200;

/// 状态数字枚举（对齐 route.cpp，日志实测）。
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
#[repr(i32)]
pub enum RawVpnStatus {
    Unknown = -1,
    NoRun = 0,
    Connecting = 1,
    Connected = 2,
    ConnectFail = 3,
    Reconnecting = 4,
    ReconnectFail = 5,
    Disconnecting = 6,
    Disconnected = 7,
}

impl RawVpnStatus {
    pub fn from_i32(v: i32) -> Self {
        match v {
            -1 => Self::Unknown,
            0 => Self::NoRun,
            1 => Self::Connecting,
            2 => Self::Connected,
            3 => Self::ConnectFail,
            4 => Self::Reconnecting,
            5 => Self::ReconnectFail,
            6 => Self::Disconnecting,
            7 => Self::Disconnected,
            _ => Self::Unknown,
        }
    }
}

/// Web 拉起会话的 valid string（实测 `validcode=@#motionProweb=1`）。
#[derive(Debug, Clone, Default, Serialize, Deserialize)]
pub struct ValidString {
    pub validcode: String,
    pub motion_pro_web: bool,
}

impl ValidString {
    /// 解析 `key=value@key=value` 形式。
    pub fn parse(s: &str) -> Self {
        let mut out = Self::default();
        for part in s.split('#') {
            if let Some(v) = part.strip_prefix("validcode=") {
                // '@' 是多字段分隔符（如 validcode=@#motionProweb=1）
                out.validcode = v.trim_end_matches('@').to_string();
            } else if part == "motionProweb=1" {
                out.motion_pro_web = true;
            }
        }
        out
    }

    pub fn encode(&self) -> String {
        let mut s = format!("validcode={}", self.validcode);
        if self.motion_pro_web {
            s.push_str("@#motionProweb=1");
        }
        s
    }
}

#[derive(Debug, Error, PartialEq)]
pub enum ProtocolError {
    #[error("bad prx path: {0}")]
    BadPath(String),
    #[error("missing session cookie")]
    NoSession,
}

/// 构造 prx 代理路径下的请求（真实流量都走 /prx/000/... 前缀）。
pub fn prx_request(path: &str, host: &str, extra_headers: &[(&str, &str)]) -> String {
    let mut req = format!("GET {path} HTTP/1.1\r\nHost: {host}\r\n");
    for (k, v) in extra_headers {
        req.push_str(k);
        req.push_str(": ");
        req.push_str(v);
        req.push_str("\r\n");
    }
    req.push_str("Connection: Keep-Alive\r\n\r\n");
    req
}

/// AAA 查询请求（对应 an_login.js）。
pub fn aaa_method_request(host: &str) -> String {
    prx_request(AN_LOGIN_PATH, host, &[])
}

/// postlogin 资源查询（实测带 _uname/_role/_pid/_instid 查询参数）。
pub fn postlogin_apps_request(host: &str, uname: &str, pid: &str, instid: &str) -> String {
    prx_request(
        &format!("{POSTLOGIN_APPS_PATH}?_uname={uname}&_role=&_pid={pid}&_instid={instid}"),
        host,
        &[],
    )
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn raw_status_mapping() {
        assert_eq!(RawVpnStatus::from_i32(2), RawVpnStatus::Connected);
        assert_eq!(RawVpnStatus::from_i32(4), RawVpnStatus::Reconnecting);
        assert_eq!(RawVpnStatus::from_i32(7), RawVpnStatus::Disconnected);
        assert_eq!(RawVpnStatus::from_i32(99), RawVpnStatus::Unknown);
    }

    #[test]
    fn valid_string_roundtrip() {
        let v = ValidString::parse("validcode=@#motionProweb=1");
        assert_eq!(v.validcode, "");
        assert!(v.motion_pro_web);
        assert_eq!(v.encode(), "validcode=@#motionProweb=1");
    }

    #[test]
    fn valid_string_code_only() {
        let v = ValidString::parse("validcode=abc123");
        assert_eq!(v.validcode, "abc123");
        assert!(!v.motion_pro_web);
    }

    #[test]
    fn aaa_request_format() {
        let r = aaa_method_request("vpn.example.com");
        assert!(r.starts_with("GET /prx/000/http/localhost/an_login.js HTTP/1.1\r\n"));
        assert!(r.contains("Host: vpn.example.com"));
        assert!(r.contains("Connection: Keep-Alive"));
    }

    #[test]
    fn postlogin_request_format() {
        let r = postlogin_apps_request("h", "example_user", "***", "default");
        assert!(
            r.contains(
                "_uname=example_user&_role=&_pid=***& _instid=default"
                    .replace(' ', "")
                    .as_str()
            ) || r.contains("_uname=example_user&_role=&_pid=***&_instid=default")
        );
    }
}
