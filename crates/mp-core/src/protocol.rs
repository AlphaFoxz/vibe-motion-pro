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

/// 数据隧道通道（Ghidra T2 确认：%s = /prx/000/http/localhost，同连接升级二进制）。
pub const VPNTUNNEL_PATH: &str = "/prx/000/http/localhost/vpntunnel";

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

/// TCP 隧道 keepalive（Ghidra T1 确认：默认 30s，注册表 SendInterval 1-60 可调；
/// 之前实测的 ~200ms 小流量是内层 TCP 自身心跳，非本协议 keepalive）。
pub const KEEPALIVE_INTERVAL_SECS: u64 = 30;

/// keepalive 无响应重连阈值（Ghidra T1：AttemptMaxTimes 默认 3，上限 300）。
pub const KEEPALIVE_MAX_ATTEMPTS: u32 = 3;

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

/// /vpntunnel 握手参数（Ghidra T2 确认的请求头集）。
#[derive(Debug, Clone, Default)]
pub struct TunnelOpenParams<'a> {
    /// Cookie 值（通常为 "ANStandalone=true;<session>"）。
    pub cookie: &'a str,
    /// 设备类型（x-devtype，实测值 1）。
    pub dev_type: i32,
    /// 客户端 ID（clientid 头）。
    pub client_id: &'a str,
    /// CPU ID（cpuid 头，来自 HWID 工具）。
    pub cpu_id: &'a str,
    /// 主机名（hostname 头，gethostname）。
    pub hostname: &'a str,
    /// IPv6 载荷模式时追加 PAYLOAD-IP-VERSION: 6。
    pub ipv6: bool,
}

/// 构造 `GET /prx/000/http/localhost/vpntunnel` 请求（Ghidra T2：get_config.c 0x4fa）。
pub fn vpntunnel_request(host: &str, params: &TunnelOpenParams) -> String {
    let mut req = format!(
        "GET {VPNTUNNEL_PATH} HTTP/1.1\r\nHost: {host}\r\n\
         Cookie: ANStandalone=true;{}\r\nx-devtype: {}\r\nappid: SSPVPN\r\n\
         clientid: {}\r\ncpuid: {}\r\nhostname: {}",
        params.cookie, params.dev_type, params.client_id, params.cpu_id, params.hostname
    );
    if params.ipv6 {
        req.push_str("\r\nPAYLOAD-IP-VERSION: 6");
    }
    req.push_str("\r\n\r\n");
    req
}

/// 16 字节配置帧（HTTP 200 后同连接二进制模式；Ghidra T3）。
/// 布局：`[0]=消息类型字符 [1..4]=0 [4..8]=载荷长度(LE u32)`，载荷 = JSON。
pub const CONFIG_FRAME_HEADER_LEN: usize = 16;

/// 配置帧消息类型（Ghidra T3：P=客户端请求，Q=通用配置响应，U=网络配置响应）。
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum ConfigMsgType {
    /// 客户端 → 服务端：请求通用配置（帧其余字段为 0，首 u32=0x50）。
    Request = 0x50,      // 'P'
    /// 服务端 → 客户端：通用配置 JSON。
    CommonConfig = 0x51, // 'Q'
    /// 服务端 → 客户端：网络配置 JSON。
    NetworkConfig = 0x55, // 'U'
}

/// 编码 16 字节配置帧头 + 载荷。
pub fn encode_config_frame(kind: ConfigMsgType, payload: &[u8]) -> Vec<u8> {
    let mut f = vec![0u8; CONFIG_FRAME_HEADER_LEN + payload.len()];
    f[0] = kind as u8;
    f[4..8].copy_from_slice(&(payload.len() as u32).to_le_bytes());
    f[CONFIG_FRAME_HEADER_LEN..].copy_from_slice(payload);
    f
}

/// 解码配置帧；缓冲不足返回 `None`，格式非法返回 `Err(())`。
/// TODO(抓包): 长度字段 LE/BE 待实测对齐（反编译显示 short 直接作 malloc 尺寸 → LE）。
pub fn decode_config_frame(buf: &[u8]) -> Option<Result<(ConfigMsgType, Vec<u8>, usize), ()>> {
    if buf.len() < CONFIG_FRAME_HEADER_LEN {
        return None;
    }
    let kind = match buf[0] {
        0x50 => ConfigMsgType::Request,
        0x51 => ConfigMsgType::CommonConfig,
        0x55 => ConfigMsgType::NetworkConfig,
        _ => return Some(Err(())),
    };
    let len = u32::from_le_bytes([buf[4], buf[5], buf[6], buf[7]]) as usize;
    let total = CONFIG_FRAME_HEADER_LEN + len;
    if buf.len() < total {
        return None;
    }
    Some(Ok((kind, buf[CONFIG_FRAME_HEADER_LEN..total].to_vec(), total)))
}

/// 编码 48 字节网络配置请求帧（'T'；Ghidra T3：get_config.c 0x5f4-0x61f）。
/// 布局：16B 头 {[0]='T' [12]=载荷长 0x20(LE)} + 32B 载荷
/// {[16]=本机地址数 [20..40]=5×本机 IPv4 [40..46]=网卡 MAC}。
/// TODO(抓包): 载荷逐字段对齐待真机验证。
pub fn network_config_request(local_ips: &[[u8; 4]], mac: &[u8; 6]) -> Vec<u8> {
    let mut f = vec![0u8; CONFIG_FRAME_HEADER_LEN + 32];
    f[0] = 0x54; // 'T'
    f[12..16].copy_from_slice(&32u32.to_le_bytes());
    f[16] = local_ips.len().min(5) as u8;
    for (i, ip) in local_ips.iter().take(5).enumerate() {
        f[20 + i * 4..24 + i * 4].copy_from_slice(ip);
    }
    f[40..46].copy_from_slice(mac);
    f
}

/// 'U' 网络配置（宽容解析 —— 真实字段名待抓包确认；候选键按原版线索）：
/// 虚拟 IP：virip / virtual_ip / ip / address；掩码：mask/netmask；
/// DNS：dns/dns_list/dns_servers；路由：routes/include_zone。
#[derive(Debug, Clone, Default, Deserialize, PartialEq)]
pub struct NetworkConfig {
    #[serde(default)]
    pub virtual_ip: Option<std::net::Ipv4Addr>,
    #[serde(default)]
    pub netmask: Option<std::net::Ipv4Addr>,
    #[serde(default)]
    pub dns: Vec<std::net::Ipv4Addr>,
}

impl NetworkConfig {
    /// 从任意 JSON 提取（递归浅扫键名候选）。
    pub fn from_json(value: &serde_json::Value) -> Self {
        use serde_json::Value;
        let mut out = Self::default();
        fn walk(v: &Value, out: &mut NetworkConfig) {
            match v {
                Value::Object(m) => {
                    for (k, val) in m {
                        match k.to_ascii_lowercase().as_str() {
                            "virip" | "virtual_ip" | "vnic_ip" => {
                                if out.virtual_ip.is_none() {
                                    out.virtual_ip = val.as_str().and_then(|s| s.parse().ok());
                                }
                            }
                            "mask" | "netmask" => {
                                if out.netmask.is_none() {
                                    out.netmask = val.as_str().and_then(|s| s.parse().ok());
                                }
                            }
                            "dns" | "dns_list" | "dns_servers" => {
                                if let Some(arr) = val.as_array() {
                                    for d in arr {
                                        if let Some(ip) = d.as_str().and_then(|s| s.parse().ok()) {
                                            out.dns.push(ip);
                                        }
                                    }
                                } else if let Some(ip) = val.as_str().and_then(|s| s.parse().ok()) {
                                    out.dns.push(ip);
                                }
                            }
                            _ => {}
                        }
                        walk(val, out);
                    }
                }
                Value::Array(a) => {
                    for item in a {
                        walk(item, out);
                    }
                }
                _ => {}
            }
        }
        walk(value, &mut out);
        out
    }
}

/// postlogin apps JSON（Ghidra T5 确认的字段集；jsoncpp 解析，缺省宽容）。
#[derive(Debug, Clone, Default, Deserialize, PartialEq)]
pub struct SiteConfig {
    #[serde(default)]
    pub domain: String,
    #[serde(default)]
    pub session: String,
    #[serde(default)]
    pub server_type: i64,
    #[serde(default)]
    pub port: u16,
    #[serde(default)]
    pub method: String,
    #[serde(default)]
    pub validcode: String,
    #[serde(default)]
    pub username: String,
    #[serde(default)]
    pub password: String,
    #[serde(default)]
    pub certpath: String,
    #[serde(default)]
    pub certpassword: String,
    #[serde(default)]
    pub reconncount: i64,
    #[serde(default)]
    pub reconntime: i64,
    #[serde(default)]
    pub reconninterval: i64,
    #[serde(default)]
    pub flags: u32,
    #[serde(default)]
    pub tunneltype: i64,
    #[serde(default)]
    pub sslproto: i64,
    #[serde(default)]
    pub proxyhost: String,
    #[serde(default)]
    pub proxyport: u16,
    #[serde(default)]
    pub proxydomain: String,
    #[serde(default)]
    pub proxyusername: String,
    #[serde(default)]
    pub proxypassword: String,
}

/// WireGuard 站点配置（存在时启用 WG 隧道）。
#[derive(Debug, Clone, Default, Deserialize, PartialEq)]
pub struct WgConfig {
    #[serde(default)]
    pub site_name: String,
    #[serde(default)]
    pub session_id: String,
    #[serde(default)]
    pub ip: String,
    #[serde(default)]
    pub pub_key: String,
    #[serde(default)]
    pub wg_desc: String,
    #[serde(default)]
    pub wg_name: String,
}

#[derive(Debug, Clone, Default, Deserialize, PartialEq)]
pub struct PostloginApps {
    #[serde(default)]
    pub site: SiteConfig,
    #[serde(default)]
    pub wg: Option<WgConfig>,
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

    #[test]
    fn vpntunnel_request_headers() {
        let req = vpntunnel_request(
            "vpn.example.com",
            &TunnelOpenParams {
                cookie: "sid=abc",
                dev_type: 1,
                client_id: "cid",
                cpu_id: "cpu123",
                hostname: "PC-1",
                ipv6: false,
            },
        );
        assert!(req.starts_with("GET /prx/000/http/localhost/vpntunnel HTTP/1.1\r\n"));
        assert!(req.contains("Host: vpn.example.com\r\n"));
        assert!(req.contains("Cookie: ANStandalone=true;sid=abc\r\n"));
        assert!(req.contains("x-devtype: 1\r\n"));
        assert!(req.contains("appid: SSPVPN\r\n"));
        assert!(req.contains("clientid: cid\r\ncpuid: cpu123\r\nhostname: PC-1"));
        assert!(!req.contains("PAYLOAD-IP-VERSION"));
        assert!(req.ends_with("\r\n\r\n"));
    }

    #[test]
    fn vpntunnel_request_ipv6() {
        let req = vpntunnel_request("h", &TunnelOpenParams { ipv6: true, ..Default::default() });
        assert!(req.contains("PAYLOAD-IP-VERSION: 6\r\n"));
    }

    #[test]
    fn config_frame_roundtrip() {
        let f = encode_config_frame(ConfigMsgType::Request, b"");
        assert_eq!(f.len(), CONFIG_FRAME_HEADER_LEN);
        assert_eq!(f[0], b'P');
        let (kind, payload, used) = decode_config_frame(&f).unwrap().unwrap();
        assert_eq!(kind, ConfigMsgType::Request);
        assert!(payload.is_empty());
        assert_eq!(used, CONFIG_FRAME_HEADER_LEN);

        let f = encode_config_frame(ConfigMsgType::CommonConfig, br#"{"a":1}"#);
        let (kind, payload, used) = decode_config_frame(&f).unwrap().unwrap();
        assert_eq!(kind, ConfigMsgType::CommonConfig);
        assert_eq!(payload, br#"{"a":1}"#.to_vec());
        assert_eq!(used, f.len());
    }

    #[test]
    fn config_frame_incomplete_then_bad_type() {
        // 不足 16B 头 → None（等待更多数据）
        assert!(decode_config_frame(&[b'P', 0, 0]).is_none());
        let mut f = encode_config_frame(ConfigMsgType::NetworkConfig, b"x");
        f.truncate(CONFIG_FRAME_HEADER_LEN); // 头在、载荷缺 → None
        assert!(decode_config_frame(&f).is_none());
        // 未知类型 → Err
        let mut bad = [0u8; CONFIG_FRAME_HEADER_LEN];
        bad[0] = b'Z';
        assert!(decode_config_frame(&bad).unwrap().is_err());
    }

    #[test]
    fn postlogin_apps_parse() {
        let raw = r#"{
            "site": {"domain":"vpn.example.com","session":"S1","port":443,
                     "tunneltype":0,"sslproto":3,"flags":512,"method":"Local"},
            "wg": {"site_name":"wg1","session_id":"W1","ip":"10.9.0.1","pub_key":"K="}
        }"#;
        let apps: PostloginApps = serde_json::from_str(raw).unwrap();
        assert_eq!(apps.site.domain, "vpn.example.com");
        assert_eq!(apps.site.session, "S1");
        assert_eq!(apps.site.sslproto, 3);
        assert_eq!(apps.wg.as_ref().unwrap().pub_key, "K=");

        // 空对象宽容解析
        let empty: PostloginApps = serde_json::from_str("{}").unwrap();
        assert_eq!(empty.site.port, 0);
        assert!(empty.wg.is_none());
    }
}