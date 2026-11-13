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

/// 登出端点（HAR 取证：an_welcome.js，见 docs/har-forensics.md）。
pub const LOGOUT_PATH: &str = "/prx/000/http/localhost/logout";

/// 企业 SSO 登录页验证码（HAR 取证：/restservice/vpnLogin/getImage）。
pub const CAPTCHA_PATH: &str = "/restservice/vpnLogin/getImage";

/// 本地 web portal 双 WebSocket（对齐原版 MotionProHttpd 60012）：
/// ws/command = 请求通道，ws/notify = 状态推送通道（与 mp-ipc + tick_broadcast 同构）。
pub const PORTAL_WS_COMMAND: &str = "/ws/command";
pub const PORTAL_WS_NOTIFY: &str = "/ws/notify";

/// 登录提交端点（HAR：/restservice/vpnLogin/*，POST 路径待响应头最终确认）。
pub const LOGIN_SUBMIT_PATH: &str = "/restservice/vpnLogin/login";

/// 登录表单字段（HAR 实测字段名；凭据值匿名化后不入库）。
#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
pub struct LoginFormData {
    /// 固定 "t"（登录类型标记，原版实测值）
    pub t: String,
    pub user_code: String,
    pub pwd: String,
    /// 验证码（来自 CAPTCHA_PATH，uuid 关联）
    pub code: String,
}

impl LoginFormData {
    pub fn to_form_urlencoded(&self) -> String {
        format!(
            "t={}&userCode={}&pwd={}&code={}",
            urlencode(&self.t),
            urlencode(&self.user_code),
            urlencode(&self.pwd),
            urlencode(&self.code)
        )
    }
}

fn urlencode(s: &str) -> String {
    let mut out = String::with_capacity(s.len());
    for b in s.bytes() {
        match b {
            b'A'..=b'Z' | b'a'..=b'z' | b'0'..=b'9' | b'-' | b'_' | b'.' | b'~' => {
                out.push(b as char)
            }
            _ => out.push_str(&format!("%{:02X}", b)),
        }
    }
    out
}

/// 原版 action 码（WS 帧实测；8=状态查询，10=登录回调通知，其余待采集）。
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
#[repr(i32)]
pub enum WsAction {
    StatusQuery = 8,
    LoginCallback = 10,
}

/// 原版 WS 信封（若需与原版 web portal 兼容时使用）。
#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
pub struct WsEnvelope {
    pub data: serde_json::Value,
    #[serde(default)]
    pub error: i32,
    #[serde(default)]
    pub message: String,
    #[serde(default)]
    pub receiver: Option<String>,
    #[serde(default)]
    pub sender: String,
}

impl WsEnvelope {
    pub fn parse(raw: &str) -> Option<Self> {
        serde_json::from_str(raw).ok()
    }
}

/// receiver 寻址格式："<ANsession cookie>=<profile_id>+<uuid>"。
pub fn ws_receiver(session_cookie: &str, profile_id: &str, uuid: &str) -> String {
    format!("{session_cookie}={profile_id}+{uuid}")
}

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
    fn login_form_encoding() {
        let f = LoginFormData {
            t: "t".into(),
            user_code: "example_user".into(),
            pwd: "p@ss w0rd".into(),
            code: "105119".into(),
        };
        assert_eq!(
            f.to_form_urlencoded(),
            "t=t&userCode=example_user&pwd=p%40ss%20w0rd&code=105119"
        );
    }

    #[test]
    fn ws_envelope_parse_command() {
        let raw = r#"{"data":{"action":8,"site":{"host":"","name":""},"status":0},"error":0,"message":"vpn current status","receiver":null,"sender":"daemon"}"#;
        let e = WsEnvelope::parse(raw).unwrap();
        assert_eq!(e.error, 0);
        assert_eq!(e.sender, "daemon");
        assert!(e.receiver.is_none());
        assert_eq!(e.data["action"], 8);
    }

    #[test]
    fn ws_envelope_parse_notify() {
        let raw = r#"{"data":{"action":10,"callback":1,"error":0},"error":0,"receiver":"ANsession1=prof+u1","sender":"daemon"}"#;
        let e = WsEnvelope::parse(raw).unwrap();
        assert_eq!(e.data["action"], 10);
        assert_eq!(e.receiver.as_deref(), Some("ANsession1=prof+u1"));
    }

    #[test]
    fn ws_receiver_format() {
        assert_eq!(
            ws_receiver("ANsession1", "prof1", "u1"),
            "ANsession1=prof1+u1"
        );
    }
}