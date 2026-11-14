//! TLS 控制通道客户端：实现认证/会话 HTTP 流。
//!
//! 流程对齐 docs/runtime-forensics.md 实测：
//! 1. TLS 连接网关（TLS 1.2+，rustls）
//! 2. GET /prx/000/http/localhost/an_login.js —— 查询 AAA 认证方式
//! 3. 携带 session cookie 复用会话（"session cookie exist, don't need to login"）
//! 4. GET postlogin apps（_uname/_pid/_instid）
//!
//! 数据帧格式仍待 Ghidra（见 protocol.rs），本模块只负责控制通道。

use crate::protocol::{ProtocolError, AN_LOGIN_PATH, POSTLOGIN_APPS_PATH};
use serde::Deserialize;
use std::sync::Arc;
use thiserror::Error;
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use tokio::net::TcpStream;
use tokio_rustls::rustls::pki_types::ServerName;
use tokio_rustls::{rustls, TlsConnector};

#[derive(Debug, Error)]
pub enum ControlError {
    #[error("io error: {0}")]
    Io(#[from] std::io::Error),
    #[error("tls error: {0}")]
    Tls(#[from] rustls::Error),
    #[error("protocol: {0}")]
    Protocol(#[from] ProtocolError),
    #[error("http status {0}")]
    HttpStatus(u16),
    #[error("login rejected (no ANsession cookie)")]
    AuthFailed,
    #[error("operation timed out: {0}")]
    Timeout(&'static str),
    #[error("malformed response")]
    Malformed,
}

/// HTTP 响应解析结果。
#[derive(Debug, Clone, Default)]
pub struct HttpResponse {
    pub status: u16,
    pub headers: Vec<(String, String)>,
    pub body: String,
}

impl HttpResponse {
    pub fn header(&self, name: &str) -> Option<&str> {
        let n = name.to_ascii_lowercase();
        self.headers.iter().find(|(k, _)| k.to_ascii_lowercase() == n).map(|(_, v)| v.as_str())
    }

    pub fn set_cookies(&self) -> Vec<String> {
        self.headers
            .iter()
            .filter(|(k, _)| k.eq_ignore_ascii_case("set-cookie"))
            .map(|(_, v)| v.split(';').next().unwrap_or("").to_string())
            .collect()
    }
}

/// 解析 HTTP/1.1 响应（Content-Length 精确 / 连接关闭兜底）。
pub fn parse_response(raw: &[u8]) -> Result<HttpResponse, ControlError> {
    let text = String::from_utf8_lossy(raw);
    let (head, body) = text.split_once("\r\n\r\n").ok_or(ControlError::Malformed)?;
    let mut lines = head.lines();
    let status_line = lines.next().ok_or(ControlError::Malformed)?;
    let status = status_line
        .split_whitespace()
        .nth(1)
        .and_then(|s| s.parse::<u16>().ok())
        .ok_or(ControlError::Malformed)?;
    let headers = lines
        .filter_map(|l| l.split_once(':').map(|(k, v)| (k.trim().to_string(), v.trim().to_string())))
        .collect();
    Ok(HttpResponse { status, headers, body: body.to_string() })
}

/// 解码 chunked 体（容错：格式异常时返回原始字节）。
fn decode_chunked(raw: &[u8]) -> Vec<u8> {
    let mut out = Vec::with_capacity(raw.len());
    let mut pos = 0usize;
    loop {
        // 找 chunk 大小行的 \r\n
        let Some(line_end) = raw[pos..].windows(2).position(|w| w == b"\r\n") else {
            out.extend_from_slice(&raw[pos..]);
            return out;
        };
        let size_str = String::from_utf8_lossy(&raw[pos..pos + line_end]);
        let size = usize::from_str_radix(size_str.trim().split(';').next().unwrap_or("0"), 16)
            .unwrap_or(0);
        if size == 0 {
            return out;
        }
        let start = pos + line_end + 2;
        let end = (start + size).min(raw.len());
        out.extend_from_slice(&raw[start..end]);
        if end >= raw.len() {
            return out;
        }
        pos = end + 2; // 跳过块尾 \r\n
    }
}

/// 会话：cookie jar + AAA 方式缓存。
#[derive(Debug, Clone, Default)]
pub struct Session {
    pub cookies: Vec<String>,
    pub aaa_methods: Vec<String>,
    pub server: String,
}

/// 浏览器式公共请求头（企业网关 WAF 常按 UA/Referer 过滤，缺失会被静默丢弃）。
pub const BROWSER_LIKE_HEADERS: &str = "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36\r\nAccept: */*\r\nAccept-Language: zh-CN,zh;q=0.9\r\nX-Requested-With: XMLHttpRequest\r\n";

/// 控制通道客户端。
pub struct ControlClient {
    /// 逻辑主机名（Host 头 + TLS SNI）
    pub host: String,
    /// 实际连接地址（默认与 host:port 相同；测试/自定义 DNS 时可覆盖为 IP）
    pub connect_addr: (String, u16),
    connector: TlsConnector,
}

impl ControlClient {
    /// `danger_accept_any_cert`: 骨架阶段跳过服务器证书校验。
    /// TODO: 实现 VerifyServerCert 对应的证书链校验 + root CA pinning 后移除。
    pub fn new(host: impl Into<String>, port: u16, danger_accept_any_cert: bool) -> Result<Self, ControlError> {
        let host = host.into();
        let connector = Self::build_connector(danger_accept_any_cert)?;
        Ok(Self { connect_addr: (host.clone(), port), host, connector })
    }

    /// 测试/自定义 DNS：Host 与 SNI 仍用 host，但 TCP 连到指定 IP。
    pub fn with_connect_addr(mut self, ip: &str, port: u16) -> Self {
        self.connect_addr = (ip.to_string(), port);
        self
    }

    fn build_connector(danger: bool) -> Result<TlsConnector, ControlError> {
        // workspace 同时启用 ring/aws-lc-rs feature 时 rustls 无法自动选择，显式指定 ring
        let _ = rustls::crypto::ring::default_provider().install_default();
        // 强制 TLS 1.2：原版客户端 TLSV_12=true（ArrayVPNApi INI 实证），网关对 TLS 1.3
        // "握手成功但请求装死"（真机实测）。只影响我们发起的连接。
        let versions = &[&rustls::version::TLS12];
        let mut cfg = if danger {
            rustls::ClientConfig::builder_with_protocol_versions(versions)
                .dangerous()
                .with_custom_certificate_verifier(Arc::new(NoVerify))
                .with_no_client_auth()
        } else {
            // TODO: rustls-native-certs 载入系统根证书 + 原版 rootca pinning
            let roots = rustls::RootCertStore::empty();
            rustls::ClientConfig::builder_with_protocol_versions(versions)
                .with_root_certificates(roots)
                .with_no_client_auth()
        };
        // ALPN http/1.1：网关前端是反向代理（Reverse Proxy Server/2.8.1），无 ALPN 时
        // 按 HTTP/2 语义处理请求 → 静默丢弃（真机实测 curl 对照定位）。
        cfg.alpn_protocols = vec![b"http/1.1".to_vec()];
        // 禁用 TLS 会话复用：AG 网关 resume 后的连接会被 RST（真机实测 login 成功后
        // postlogin 复用会话被 10054 重置；完整握手稳定）。每次握手仅多 ~20ms。
        cfg.resumption = rustls::client::Resumption::disabled();
        Ok(TlsConnector::from(Arc::new(cfg)))
    }

    async fn connect_tls(&self) -> Result<tokio_rustls::client::TlsStream<TcpStream>, ControlError> {
        let tcp = TcpStream::connect((self.connect_addr.0.as_str(), self.connect_addr.1)).await?;
        let name = ServerName::try_from(self.host.clone())
            .map_err(|_| ControlError::Protocol(ProtocolError::BadPath(self.host.clone())))?;
        Ok(self.connector.connect(name, tcp).await?)
    }

    /// GET 任意路径（探针/调试用）：新连接 + 会话 cookie。
    pub async fn get_public(
        &self,
        path: &str,
        session: &mut Session,
    ) -> Result<HttpResponse, ControlError> {
        let mut stream = self.connect_tls().await?;
        self.get(&mut stream, path, session).await
    }

    /// GET 并解析；自动附带 session cookie，自动捕获 Set-Cookie。
    /// 支持 Content-Length 与 chunked 两种响应体（真机网关用 chunked）。
    async fn get(
        &self,
        stream: &mut tokio_rustls::client::TlsStream<TcpStream>,
        path: &str,
        session: &mut Session,
    ) -> Result<HttpResponse, ControlError> {
        use tokio::io::AsyncWriteExt;
        let cookie_hdr = if session.cookies.is_empty() {
            String::new()
        } else {
            format!("Cookie: {}\r\n", session.cookies.join("; "))
        };
        let req = format!(
            "GET {path} HTTP/1.1\r\nHost: {}\r\n{BROWSER_LIKE_HEADERS}Connection: Keep-Alive\r\n{cookie_hdr}\r\n",
            self.host
        );
        stream.write_all(req.as_bytes()).await?;
        let (head, body) = Self::read_response_raw(stream).await?;
        let mut resp = parse_response(&head)?;
        resp.body = String::from_utf8_lossy(&body).to_string();
        for c in resp.set_cookies() {
            if !session.cookies.contains(&c) {
                session.cookies.push(c);
            }
        }
        Ok(resp)
    }

    /// 步骤 2：查询 AAA 认证方式（an_login.js）。
    pub async fn query_aaa(&self, session: &mut Session) -> Result<Vec<String>, ControlError> {
        let mut stream = self.connect_tls().await?;
        let resp = self.get(&mut stream, AN_LOGIN_PATH, session).await?;
        if resp.status != 200 {
            return Err(ControlError::HttpStatus(resp.status));
        }
        // TODO(抓包): 字段名待原版响应确认（骨架假定 {"methods":[...]}）
        #[derive(Deserialize)]
        struct AaaResp {
            #[serde(default)]
            methods: Vec<String>,
        }
        let parsed: AaaResp =
            serde_json::from_str(resp.body.trim()).map_err(|_| ControlError::Malformed)?;
        session.aaa_methods = parsed.methods.clone();
        session.server = self.host.clone();
        Ok(parsed.methods)
    }

    /// 步骤 5：postlogin 用户资源查询。
    pub async fn postlogin_apps(
        &self,
        session: &mut Session,
        uname: &str,
        pid: &str,
    ) -> Result<String, ControlError> {
        let mut stream = self.connect_tls().await?;
        let path =
            format!("{POSTLOGIN_APPS_PATH}?_uname={uname}&_role=&_pid={pid}&_instid=default");
        let resp = self.get(&mut stream, &path, session).await?;
        if resp.status != 200 {
            return Err(ControlError::HttpStatus(resp.status));
        }
        Ok(resp.body)
    }

    /// 步骤 2a：拉取登录验证码图片（HAR 实测 image/jpeg；uuid 关联本次验证码）。
    /// 返回图片字节（UI 直接展示），Set-Cookie 自动入 session。
    pub async fn fetch_captcha(&self, session: &mut Session, uuid: &str) -> Result<Vec<u8>, ControlError> {
        let mut stream = self.connect_tls().await?;
        let path = format!("{}?d={}&uuid={}", crate::protocol::CAPTCHA_PATH, now_ms(), uuid);
        let req = format!(
            // 注意结尾必须有空行（\r\n\r\n）结束请求头，否则服务器等待后续头不响应（真机实测）
            "GET {path} HTTP/1.1\r\nHost: {}\r\n{BROWSER_LIKE_HEADERS}Connection: Keep-Alive\r\n\r\n",
            self.host
        );
        stream.write_all(req.as_bytes()).await?;
        let (head, body) = Self::read_response_raw(&mut stream).await?;
        let resp = parse_response(&head)?;
        for c in resp.set_cookies() {
            if !session.cookies.contains(&c) {
                session.cookies.push(c);
            }
        }
        if resp.status != 200 {
            return Err(ControlError::HttpStatus(resp.status));
        }
        Ok(body)
    }

    /// 步骤 2a：取门户首页并解析登录表单 action（AG 网关地址的唯一权威来源）。
    /// index.html: <form method="post" action="https://vpntoken.baosteel.com/prx/000/http/localhost/login">
    pub async fn fetch_login_action(&self, session: &mut Session) -> Result<String, ControlError> {
        let mut stream = self.connect_tls().await?;
        let resp = self.get(&mut stream, "/", session).await?;
        if resp.status != 200 {
            return Err(ControlError::HttpStatus(resp.status));
        }
        let html = &resp.body;
        let key = "action=\"";
        let Some(start) = html.find(key) else {
            return Err(ControlError::Malformed);
        };
        let rest = &html[start + key.len()..];
        let Some(end) = rest.find('"') else {
            return Err(ControlError::Malformed);
        };
        Ok(rest[..end].to_string())
    }

    /// 步骤 2a'：令牌预校验（门户 main.js 实证）。
    /// POST TOKEN_PRECHECK_PATH，期望 JSON {"message":"Success"}。
    pub async fn token_precheck(
        &self,
        session: &mut Session,
        form: &crate::protocol::LoginFormData,
    ) -> Result<(), ControlError> {
        use tokio::io::AsyncWriteExt;
        let mut stream = self.connect_tls().await?;
        let body = form.to_form_urlencoded();
        let req = format!(
            "POST {} HTTP/1.1\r\nHost: {}\r\n{BROWSER_LIKE_HEADERS}\
             Content-Type: application/x-www-form-urlencoded;charset=UTF-8\r\n\
             Content-Length: {}\r\nReferer: https://{}/\r\nConnection: Keep-Alive\r\n\r\n{body}",
            crate::protocol::TOKEN_PRECHECK_PATH,
            self.host,
            body.len(),
            self.host
        );
        stream.write_all(req.as_bytes()).await?;
        let (head, resp_body) = Self::read_response_raw(&mut stream).await?;
        let resp = parse_response(&head)?;
        for c in resp.set_cookies() {
            if !session.cookies.contains(&c) {
                session.cookies.push(c);
            }
        }
        if resp.status != 200 {
            return Err(ControlError::HttpStatus(resp.status));
        }
        let text = String::from_utf8_lossy(&resp_body);
        #[derive(serde::Deserialize)]
        struct PrecheckResp {
            message: String,
        }
        match serde_json::from_str::<PrecheckResp>(text.trim()) {
            Ok(r) if r.message == "Success" => Ok(()),
            Ok(r) => {
                tracing::warn!("precheck rejected: {}", r.message);
                Err(ControlError::AuthFailed)
            }
            Err(_) => Err(ControlError::Malformed),
        }
    }

    /// 步骤 2b：提交 /prx 登录表单（index.html form action 实证：
    /// POST https://<AG网关>/prx/000/http/localhost/login，method=test&uname=&pwd=&authCode=）。
    /// 本方法应通过 AG 网关主机构造的 ControlClient 调用（表单 action 的目标主机）。
    /// 返回 (状态码, 302 跳转目标)。
    pub async fn login(
        &self,
        session: &mut Session,
        form: &crate::protocol::LoginFormData,
    ) -> Result<(u16, Option<String>), ControlError> {
        use tokio::io::{AsyncReadExt, AsyncWriteExt};
        let fut = async {
            let mut stream = self.connect_tls().await?;
            let body = form.to_prx_form_urlencoded();
            let cookie_hdr = if session.cookies.is_empty() {
                String::new()
            } else {
                format!("Cookie: {}\r\n", session.cookies.join("; "))
            };
            let req = format!(
                "POST {} HTTP/1.1\r\nHost: {}\r\n{BROWSER_LIKE_HEADERS}\
                 Content-Type: application/x-www-form-urlencoded\r\n\
                 Content-Length: {}\r\nReferer: https://{}/\r\nConnection: Keep-Alive\r\n{cookie_hdr}\r\n{body}",
                crate::protocol::LOGIN_SUBMIT_PATH,
                self.host,
                body.len(),
                self.host
            );
            stream.write_all(req.as_bytes()).await?;
            let (head, resp_body) = Self::read_response_raw(&mut stream).await?;
            let resp = parse_response(&head)?;
            for c in resp.set_cookies() {
                if !session.cookies.contains(&c) {
                    session.cookies.push(c);
                }
            }
            if resp.status == 200 {
                // 200 可能是"登录失败回显页"：打一小段便于定位
                let text = String::from_utf8_lossy(&resp_body);
                let snippet: String = text.chars().take(200).collect();
                tracing::warn!("login got 200 (not redirect), body head: {snippet}");
            }
            Ok::<_, ControlError>((resp.status, resp.header("location").map(|s| s.to_string())))
        };
        match tokio::time::timeout(std::time::Duration::from_secs(15), fut).await {
            Ok(r) => {
                let (status, location) = r?;
                let has_an = session.cookies.iter().any(|c| c.starts_with("ANsession"));
                match status {
                    200 | 302 if has_an => Ok((status, location)),
                    200 | 302 => Err(ControlError::AuthFailed),
                    other => Err(ControlError::HttpStatus(other)),
                }
            }
            Err(_) => Err(ControlError::Timeout("login")),
        }
    }

    /// 注销：GET /prx/000/http/localhost/logout（带会话 cookie）。
    /// 释放服务端会话，防止同账号隧道僵尸堆积（真机实测：反复重登不注销后，
    /// 后续会话的转发被立即掐断）。返回 HTTP 状态码。
    pub async fn logout(&self, cookie: &str) -> Result<u16, ControlError> {
        use tokio::io::AsyncWriteExt;
        let mut stream = self.connect_tls().await?;
        let req = format!(
            "GET {} HTTP/1.1\r\nHost: {}\r\n{BROWSER_LIKE_HEADERS}\
             Cookie: ANStandalone=true;{cookie}\r\nConnection: Close\r\n\r\n",
            crate::protocol::LOGOUT_PATH,
            self.host
        );
        stream.write_all(req.as_bytes()).await?;
        let (head, _body) = Self::read_response_raw(&mut stream).await?;
        let resp = parse_response(&head)?;
        Ok(resp.status)
    }

    /// 读完整响应：返回 (头字节, 体字节)。
    /// 支持 Content-Length 精确读取与 Transfer-Encoding: chunked（真机网关用 chunked）。
    async fn read_response_raw(
        stream: &mut tokio_rustls::client::TlsStream<TcpStream>,
    ) -> Result<(Vec<u8>, Vec<u8>), ControlError> {
        let mut buf = Vec::with_capacity(4096);
        let mut chunk = [0u8; 4096];
        let head_end = loop {
            if let Some(pos) = buf.windows(4).position(|w| w == b"\r\n\r\n") {
                break pos + 4;
            }
            let n = stream.read(&mut chunk).await?;
            if n == 0 {
                return Err(ControlError::Malformed);
            }
            buf.extend_from_slice(&chunk[..n]);
        };
        let resp = parse_response(&buf[..head_end])?;
        let chunked = resp
            .header("transfer-encoding")
            .map(|v| v.to_ascii_lowercase().contains("chunked"))
            .unwrap_or(false);
        if chunked {
            // 读到终止块 0\r\n\r\n
            while !buf.ends_with(b"0\r\n\r\n") {
                let n = stream.read(&mut chunk).await?;
                if n == 0 {
                    break; // 对端提前关闭：尽力而为
                }
                buf.extend_from_slice(&chunk[..n]);
            }
            let body = decode_chunked(&buf[head_end..]);
            return Ok((buf[..head_end].to_vec(), body));
        }
        let clen: usize = resp
            .header("content-length")
            .and_then(|v| v.parse().ok())
            .unwrap_or(0);
        while buf.len() < head_end + clen {
            let n = stream.read(&mut chunk).await?;
            if n == 0 {
                break;
            }
            buf.extend_from_slice(&chunk[..n]);
        }
        Ok((buf[..head_end].to_vec(), buf[head_end..].to_vec()))
    }

    /// 数据隧道建立（Ghidra T2/T3：/vpntunnel 握手 → 同连接切二进制 → 16B 配置帧）。
    ///
    /// 流程：GET → 200/201 → 'P'→'Q'（通用配置）→ 'T'→'U'（网络配置：虚拟 IP/DNS）。
    /// 返回 (数据模式流, 'Q' 配置 JSON, 'U' 网络配置, 先导字节)。
    /// - 200 = 二进制模式（本流程）；201 = JSON 协议（暂按二进制头继续）
    /// - 302 Redirect = 拒绝
    pub async fn open_tunnel(
        &self,
        params: &crate::protocol::TunnelOpenParams<'_>,
        local_ips: &[[u8; 4]],
        mac: &[u8; 6],
    ) -> Result<
        (
            tokio_rustls::client::TlsStream<TcpStream>,
            Vec<u8>,
            crate::protocol::NetworkConfig,
            Vec<u8>,
        ),
        ControlError,
    > {
        use crate::protocol::{
            decode_config_frame, encode_config_frame, vpntunnel_request, ConfigMsgType,
            CONFIG_FRAME_HEADER_LEN,
        };
        let mut stream = self.connect_tls().await?;
        let req = vpntunnel_request(&self.host, params);
        stream.write_all(req.as_bytes()).await?;

        // 读 HTTP 头（到 \r\n\r\n 为止；201 时其后可能直接是 JSON body，一并留在流里）
        let mut buf = Vec::with_capacity(2048);
        let mut chunk = [0u8; 1024];
        let head_end;
        loop {
            let n = stream.read(&mut chunk).await?;
            if n == 0 {
                return Err(ControlError::Malformed);
            }
            buf.extend_from_slice(&chunk[..n]);
            if let Some(pos) = buf.windows(4).position(|w| w == b"\r\n\r\n") {
                head_end = pos + 4;
                break;
            }
        }
        let resp = parse_response(&buf[..head_end])?;
        tracing::debug!(
            "vpntunnel resp: status={} headers={:?} leftover={}B",
            resp.status,
            String::from_utf8_lossy(&buf[..head_end])
                .lines()
                .skip(1)
                .take(8)
                .collect::<Vec<_>>(),
            buf.len() - head_end
        );
        match resp.status {
            200 | 201 => {}
            302 => {
                tracing::warn!("vpntunnel 302 location={:?}", resp.header("location"));
                return Err(ControlError::HttpStatus(302));
            }
            other => return Err(ControlError::HttpStatus(other)),
        }

        // 二进制模式：发 'P' 请求 → 循环补读直到一个完整 'Q' 通用配置帧
        stream.write_all(&encode_config_frame(ConfigMsgType::Request, b"")).await?;
        let mut pending = buf[head_end..].to_vec(); // 201 的 body 或服务端抢先发的帧
        let common_payload;
        loop {
            // 诊断：未知帧类型（如 '3'）——打印内容并跳过，继续等 'Q'
            if pending.len() >= CONFIG_FRAME_HEADER_LEN && !matches!(pending[0], 0x50 | 0x51 | 0x55) {
                let len = u32::from_le_bytes([pending[4], pending[5], pending[6], pending[7]]) as usize;
                if pending.len() >= CONFIG_FRAME_HEADER_LEN + len {
                    tracing::warn!(
                        "unknown frame kind='{}' (0x{:02X}) len={len} payload_hex={:02X?} payload_utf8={:?}",
                        pending[0] as char, pending[0],
                        &pending[CONFIG_FRAME_HEADER_LEN..CONFIG_FRAME_HEADER_LEN + len],
                        String::from_utf8_lossy(&pending[CONFIG_FRAME_HEADER_LEN..CONFIG_FRAME_HEADER_LEN + len])
                    );
                    pending.drain(..CONFIG_FRAME_HEADER_LEN + len);
                    continue;
                }
            }
            if let Some(res) = decode_config_frame(&pending) {
                let (kind, payload, used) = res.map_err(|_| ControlError::Malformed)?;
                if kind != ConfigMsgType::CommonConfig {
                    tracing::warn!("expected 'Q' common config, got kind={kind:?}");
                    return Err(ControlError::Malformed);
                }
                common_payload = payload;
                pending.drain(..used);
                break;
            }
            let n = stream.read(&mut chunk).await?;
            if n == 0 {
                tracing::warn!("stream EOF waiting for 'Q' frame, pending={:?}B", pending.len());
                return Err(ControlError::Malformed);
            }
            pending.extend_from_slice(&chunk[..n]);
            tracing::debug!("waiting 'Q': +{n}B pending={} head={:02X?}", pending.len(), &pending.iter().take(8).collect::<Vec<_>>());
        }
        tracing::info!(
            "'Q' common config: {} bytes: {}",
            common_payload.len(),
            String::from_utf8_lossy(&common_payload)
        );
        // Q 载荷 = 220B JSON（真机 dump 实证）：
        // {"thread_number":4,"netpool_flag":1149184,"keepalive_interval":30,
        //  "allow_speed_tunnel":0,"speed_tunnel_encryption":0,...}
        let dump_dir = std::path::PathBuf::from(std::env::temp_dir()).join("opencode");
        let _ = std::fs::create_dir_all(&dump_dir);
        let _ = std::fs::write(dump_dir.join("q_frame.bin"), &common_payload);
        let mut allow_speed_tunnel = false;
        let payload_trimmed: &[u8] = {
            let end = common_payload
                .iter()
                .rposition(|&b| b != 0)
                .map(|i| i + 1)
                .unwrap_or(0);
            &common_payload[..end]
        };
        if let Ok(v) = serde_json::from_slice::<serde_json::Value>(payload_trimmed) {
            allow_speed_tunnel = v["allow_speed_tunnel"].as_i64().unwrap_or(0) != 0;
            tracing::info!(
                "common config(Q JSON): netpool_flag={:?} keepalive_interval={:?} allow_speed_tunnel={allow_speed_tunnel}",
                v["netpool_flag"].as_i64(),
                v["keepalive_interval"].as_i64()
            );
        } else if let Some(cc) = crate::protocol::decode_common_config(&common_payload) {
            tracing::info!(
                "common config(56B binary): flags={:#x} l3vpn_enabled={} keepalive={}",
                cc.flags,
                cc.flags & 0x100 != 0,
                cc.keepalive
            );
        }

        // 'T' 网络配置请求（本机 IP 列表 + MAC）→ 'U' 响应（虚拟 IP/DNS）
        stream
            .write_all(&crate::protocol::network_config_request(local_ips, mac))
            .await?;
        let mut netcfg = crate::protocol::NetworkConfig::default();
        let u_wait = async {
            loop {
                // 诊断：未知帧类型——打印并跳过，继续等 'U'
                if pending.len() >= CONFIG_FRAME_HEADER_LEN
                    && !matches!(pending[0], 0x50 | 0x51 | 0x55)
                {
                    let len =
                        u32::from_le_bytes([pending[12], pending[13], pending[14], pending[15]])
                            as usize;
                    if pending.len() >= CONFIG_FRAME_HEADER_LEN + len {
                        tracing::warn!(
                            "waiting 'U': unknown frame kind='{}' (0x{:02X}) len={len} utf8={:?}",
                            pending[0] as char,
                            pending[0],
                            String::from_utf8_lossy(
                                &pending[CONFIG_FRAME_HEADER_LEN..CONFIG_FRAME_HEADER_LEN + len]
                            )
                        );
                        pending.drain(..CONFIG_FRAME_HEADER_LEN + len);
                        continue;
                    }
                }
                if let Some(res) = decode_config_frame(&pending) {
                    let (kind, payload, used) = res.map_err(|_| ControlError::Malformed)?;
                    if kind != ConfigMsgType::NetworkConfig {
                        // 非 'U' 帧（顺序差异/额外推送）——跳过继续等
                        tracing::debug!("waiting 'U': skip kind={kind:?} {}B", payload.len());
                        pending.drain(..used);
                        continue;
                    }
                    // 帧尾可能带 NUL 填充字节（真机实测 10986B 含尾部 0x00，
                    // serde 整体校验会拒绝）——先剔除再解析
                    let trimmed: &[u8] = {
                        let end = payload
                            .iter()
                            .rposition(|&b| b != 0)
                            .map(|i| i + 1)
                            .unwrap_or(0);
                        &payload[..end]
                    };
                    if let Ok(v) = serde_json::from_slice::<serde_json::Value>(trimmed) {
                        netcfg = crate::protocol::NetworkConfig::from_control_json(&v);
                        if let Some(flag) = v["resource_group_flag"].as_i64() {
                            tracing::info!("resource_group_flag = {flag} (非 0/异常值 = 账号可能被限流/隔离)");
                        }
                    } else {
                        // 真机 'U' 载荷是二进制结构（非 JSON）：启发式扫描 vIP/掩码/include 路由
                        netcfg = crate::protocol::NetworkConfig::from_binary(&payload);
                        // 布局取证：完整载荷落盘（%TEMP%/opencode/u_frame.bin）+ 头部 hex
                        let dump_dir =
                            std::path::PathBuf::from(std::env::temp_dir()).join("opencode");
                        let _ = std::fs::create_dir_all(&dump_dir);
                        let _ = std::fs::write(dump_dir.join("u_frame.bin"), &payload);
                        tracing::debug!(
                            "U payload ({}B) dumped; head hex: {:02X?}",
                            payload.len(),
                            &payload.iter().take(96).collect::<Vec<_>>()
                        );
                    }
                    tracing::info!(
                        "network config: vip={:?} mask={:?} dns={:?} include_routes={}",
                        netcfg.virtual_ip,
                        netcfg.netmask,
                        netcfg.dns,
                        netcfg
                            .include_routes
                            .iter()
                            .map(|(ip, m)| format!("{ip}/{m}"))
                            .collect::<Vec<_>>()
                            .join(",")
                    );
                    pending.drain(..used);
                    return Ok::<(), ControlError>(());
                }
                // 短超时读：'U' 帧头声明长度可能大于实际到达量（真机 3548 vs 1796），
                // 1s 无新数据且帧头是 'U' 就按已有字节部分解析
                match tokio::time::timeout(std::time::Duration::from_secs(1), stream.read(&mut chunk)).await {
                    Ok(Ok(0)) => {
                        // 对端直接进入数据模式：无 'U' 也可用（虚拟 IP 由调用方缺省处理）
                        tracing::warn!("waiting 'U': stream EOF, enter data mode with defaults");
                        return Ok::<(), ControlError>(());
                    }
                    Ok(Ok(n)) => {
                        pending.extend_from_slice(&chunk[..n]);
                        tracing::debug!(
                            "waiting 'U': +{n}B pending={} head={:02X?}",
                            pending.len(),
                            &pending.iter().take(8).collect::<Vec<_>>()
                        );
                    }
                    Ok(Err(e)) => return Err(e.into()),
                    Err(_) => {
                        if pending.len() >= CONFIG_FRAME_HEADER_LEN && pending[0] == 0x55 {
                            tracing::warn!(
                                "waiting 'U': no more data (declared len > received), partial-parse {}B payload",
                                pending.len() - CONFIG_FRAME_HEADER_LEN
                            );
                            let payload = pending[CONFIG_FRAME_HEADER_LEN..].to_vec();
                            let trimmed: Vec<u8> = {
                                let end = payload
                                    .iter()
                                    .rposition(|&b| b != 0)
                                    .map(|i| i + 1)
                                    .unwrap_or(0);
                                payload[..end].to_vec()
                            };
                            netcfg = match serde_json::from_slice::<serde_json::Value>(&trimmed) {
                                Ok(v) => crate::protocol::NetworkConfig::from_control_json(&v),
                                Err(_) => crate::protocol::NetworkConfig::from_binary(&payload),
                            };
                            tracing::info!(
                                "network config(partial): vip={:?} mask={:?} routes={}",
                                netcfg.virtual_ip, netcfg.netmask,
                                netcfg.include_routes.iter().map(|(i, m)| format!("{i}/{m}")).collect::<Vec<_>>().join(",")
                            );
                            pending.clear();
                            return Ok::<(), ControlError>(());
                        }
                    }
                }
            }
        };
        // 'U' 10s 不回 → 带缺省进入数据模式（宽容）
        if tokio::time::timeout(std::time::Duration::from_secs(10), u_wait)
            .await
            .is_err()
        {
            // 转储 U 帧原始字节（真机 U 帧为二进制结构，字段布局待对齐）
            let dump: Vec<u8> = pending.iter().take(96).cloned().collect();
            tracing::warn!(
                "waiting 'U': 10s timeout, enter data mode with defaults; U head hex={:02X?}",
                dump
            );
        }
        // speed tunnel 客户端注册（FUN_1007e0f0）：仅在服务器允许时发送
        // （Q 配置 allow_speed_tunnel=0 时硬发可能干扰服务端状态机）
        if allow_speed_tunnel {
            let cid_frame = crate::protocol::clientid_frame(params.client_id);
            use tokio::io::AsyncWriteExt;
            if let Err(e) = stream.write_all(&cid_frame).await {
                tracing::warn!("clientid frame write failed: {e}");
            } else {
                tracing::info!("clientid frame sent ({}B)", cid_frame.len());
            }
        }
        return Ok((stream, common_payload, netcfg, pending));
    }
}

fn now_ms() -> u128 {
    std::time::SystemTime::now()
        .duration_since(std::time::UNIX_EPOCH)
        .map(|d| d.as_millis())
        .unwrap_or(0)
}

/// 骨架阶段：不校验服务器证书（探针也复用）。
#[derive(Debug)]
pub struct NoVerify;impl rustls::client::danger::ServerCertVerifier for NoVerify {
    fn verify_server_cert(
        &self,
        _end_entity: &rustls::pki_types::CertificateDer<'_>,
        _intermediates: &[rustls::pki_types::CertificateDer<'_>],
        _server_name: &rustls::pki_types::ServerName<'_>,
        _ocsp_response: &[u8],
        _now: rustls::pki_types::UnixTime,
    ) -> Result<rustls::client::danger::ServerCertVerified, rustls::Error> {
        Ok(rustls::client::danger::ServerCertVerified::assertion())
    }

    fn verify_tls12_signature(
        &self,
        _message: &[u8],
        _cert: &rustls::pki_types::CertificateDer<'_>,
        _dss: &rustls::DigitallySignedStruct,
    ) -> Result<rustls::client::danger::HandshakeSignatureValid, rustls::Error> {
        Ok(rustls::client::danger::HandshakeSignatureValid::assertion())
    }

    fn verify_tls13_signature(
        &self,
        _message: &[u8],
        _cert: &rustls::pki_types::CertificateDer<'_>,
        _dss: &rustls::DigitallySignedStruct,
    ) -> Result<rustls::client::danger::HandshakeSignatureValid, rustls::Error> {
        Ok(rustls::client::danger::HandshakeSignatureValid::assertion())
    }

    fn supported_verify_schemes(&self) -> Vec<rustls::SignatureScheme> {
        vec![
            rustls::SignatureScheme::RSA_PKCS1_SHA256,
            rustls::SignatureScheme::ECDSA_NISTP256_SHA256,
            rustls::SignatureScheme::ED25519,
            rustls::SignatureScheme::RSA_PSS_SHA256,
        ]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    // ---- 纯解析 ----

    #[test]
    fn parse_response_basic() {
        let raw = b"HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nSet-Cookie: session_id=abc123; Path=/\r\n\r\n{\"ok\":1}";
        let r = parse_response(raw).unwrap();
        assert_eq!(r.status, 200);
        assert_eq!(r.header("content-type"), Some("application/json"));
        assert_eq!(r.set_cookies(), vec!["session_id=abc123"]);
        assert_eq!(r.body, "{\"ok\":1}");
    }

    #[test]
    fn parse_response_errors() {
        assert!(matches!(parse_response(b"not http"), Err(ControlError::Malformed)));
        assert!(matches!(parse_response(b"HTTP/1.1 abc\r\n\r\n"), Err(ControlError::Malformed)));
    }

    // ---- mock TLS 服务器端到端 ----

    async fn spawn_mock_tls(app: Arc<dyn Fn(String) -> String + Send + Sync>) -> u16 {
        use tokio::net::TcpListener;
        use tokio_rustls::rustls::pki_types::{CertificateDer, PrivateKeyDer};
        use tokio_rustls::TlsAcceptor;

        let cert = rcgen::generate_simple_self_signed(vec!["vpn.example.com".into()]).unwrap();
        let cert_der = CertificateDer::from(cert.cert);
        let key_der = PrivateKeyDer::Pkcs8(cert.key_pair.serialize_der().into());
        let mut cfg = rustls::ServerConfig::builder()
            .with_no_client_auth()
            .with_single_cert(vec![cert_der], key_der)
            .unwrap();
        cfg.alpn_protocols = vec![b"http/1.1".to_vec()];
        let acceptor = TlsAcceptor::from(Arc::new(cfg));

        let listener = TcpListener::bind("127.0.0.1:0").await.unwrap();
        let port = listener.local_addr().unwrap().port();
        tokio::spawn(async move {
            while let Ok((sock, _)) = listener.accept().await {
                let acceptor = acceptor.clone();
                let app = Arc::clone(&app);
                tokio::spawn(async move {
                    if let Ok(mut tls) = acceptor.accept(sock).await {
                        let mut buf = vec![0u8; 8192];
                        if let Ok(n) = tls.read(&mut buf).await {
                            let req = String::from_utf8_lossy(&buf[..n]).to_string();
                            let resp = app(req);
                            let _ = tls.write_all(resp.as_bytes()).await;
                            let _ = tls.shutdown().await;
                        }
                    }
                });
            }
        });
        port
    }

    fn http_resp(body: &str) -> String {
        format!(
            "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nSet-Cookie: session_id=tok123; Path=/\r\nContent-Length: {}\r\n\r\n{body}",
            body.len()
        )
    }

    #[tokio::test]
    async fn aaa_query_and_cookie_capture() {
        let port = spawn_mock_tls(Arc::new(|req| {
            assert!(req.starts_with("GET /prx/000/http/localhost/an_login.js HTTP/1.1"));
            assert!(req.contains("Host: vpn.example.com"));
            http_resp("{\"methods\":[\"password\",\"sms\"]}")
        }))
        .await;

        let client =
            ControlClient::new("vpn.example.com", port, true).unwrap().with_connect_addr("127.0.0.1", port);
        let mut session = Session::default();
        let methods = client.query_aaa(&mut session).await.unwrap();
        assert_eq!(methods, vec!["password", "sms"]);
        assert_eq!(session.cookies, vec!["session_id=tok123"]);
        assert_eq!(session.aaa_methods, vec!["password", "sms"]);
        assert_eq!(session.server, "vpn.example.com");
    }

    #[tokio::test]
    async fn cookie_replay_and_postlogin() {
        let port = spawn_mock_tls(Arc::new(|req| {
            if req.contains("an_login.js") {
                http_resp("{}")
            } else if req.contains("postlogin/apps") {
                // 校验 cookie 复用
                assert!(req.contains("Cookie: session_id=tok123"), "cookie not replayed: {req}");
                http_resp("{\"apps\":[]}")
            } else {
                "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n".into()
            }
        }))
        .await;

        let client =
            ControlClient::new("vpn.example.com", port, true).unwrap().with_connect_addr("127.0.0.1", port);
        let mut session = Session::default();
        client.query_aaa(&mut session).await.unwrap();
        let body = client.postlogin_apps(&mut session, "example_user", "p1").await.unwrap();
        assert_eq!(body, "{\"apps\":[]}");
    }

    #[tokio::test]
    async fn http_error_propagates() {
        let port = spawn_mock_tls(Arc::new(|_| {
            "HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\n\r\n".into()
        }))
        .await;
        let client =
            ControlClient::new("vpn.example.com", port, true).unwrap().with_connect_addr("127.0.0.1", port);
        let mut session = Session::default();
        let err = client.query_aaa(&mut session).await.unwrap_err();
        assert!(matches!(err, ControlError::HttpStatus(403)));
    }

    // ---- /vpntunnel 握手 + 数据模式端到端 ----

    /// 二进制 mock 服务器：读 vpntunnel GET → 回 200 → 读 'P' 帧 → 回 'Q' 配置帧 → 回显数据
    async fn spawn_tunnel_mock() -> u16 {
        use tokio::net::TcpListener;
        use tokio_rustls::rustls::pki_types::{CertificateDer, PrivateKeyDer};
        use tokio_rustls::TlsAcceptor;

        let cert = rcgen::generate_simple_self_signed(vec!["vpn.example.com".into()]).unwrap();
        let key_der = PrivateKeyDer::Pkcs8(cert.key_pair.serialize_der().into());
        let cfg = rustls::ServerConfig::builder()
            .with_no_client_auth()
            .with_single_cert(vec![CertificateDer::from(cert.cert)], key_der)
            .unwrap();
        let acceptor = TlsAcceptor::from(Arc::new(cfg));

        let listener = TcpListener::bind("127.0.0.1:0").await.unwrap();
        let port = listener.local_addr().unwrap().port();
        tokio::spawn(async move {
            while let Ok((sock, _)) = listener.accept().await {
                let acceptor = acceptor.clone();
                tokio::spawn(async move {
                    use tokio::io::{AsyncReadExt, AsyncWriteExt};
                    let Ok(mut tls) = acceptor.accept(sock).await else { return };
                    let mut buf = vec![0u8; 8192];
                    // 1. 读 GET /vpntunnel
                    let Ok(n) = tls.read(&mut buf).await else { return };
                    let req = String::from_utf8_lossy(&buf[..n]).to_string();
                    assert!(req.starts_with("GET /prx/000/http/localhost/vpntunnel HTTP/1.1"));
                    assert!(req.contains("Cookie: ANStandalone=true;sid=s1"));
                    assert!(req.contains("appid: SSPVPN"));
                    // 2. 200 切二进制
                    tls.write_all(b"HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n").await.unwrap();
                    // 3. 读 16B 'P' 帧 → 回 'Q' 配置帧（JSON 载荷）
                    let mut frame = [0u8; 16];
                    tls.read_exact(&mut frame).await.unwrap();
                    assert_eq!(frame[0], b'P');
                    let cfg_json = br#"{"mtu":1400,"allow_speed_tunnel":1}"#;
                    tls.write_all(&crate::protocol::encode_config_frame(
                        crate::protocol::ConfigMsgType::CommonConfig,
                        cfg_json,
                    ))
                    .await
                    .unwrap();
                    // 4. 读 48B 'T' 网络配置请求 → 回 'U'（虚拟 IP/DNS）
                    let mut treq = [0u8; 48];
                    tls.read_exact(&mut treq).await.unwrap();
                    assert_eq!(treq[0], b'T');
                    assert_eq!(treq[12], 32);
                    // 真实 U 帧结构（LE u32 编码 IP）：10.8.0.2 → LE u32 0x0200080A=33556490，
                    // /24 掩码 → 16777215；include 10.3.130.0/24；dns 10.8.0.1
                    let net_json = br#"{"client_ipv4":33556490,"client_ipv4_mask":16777215,"include_network_resource":{"ipv4":[{"ip":8390154,"mask":16777215}]},"dns_servers":[{"ipv4":[16783370]}]}"#;
                    let mut resp = crate::protocol::encode_config_frame(
                        crate::protocol::ConfigMsgType::NetworkConfig,
                        net_json,
                    );
                    // 5. 紧跟一个下行裸 IP 包（数据模式）
                    let mut pkt = vec![0u8; 28];
                    pkt[0] = 0x45;
                    pkt[2..4].copy_from_slice(&28u16.to_be_bytes());
                    pkt[9] = 17;
                    resp.extend_from_slice(&pkt);
                    tls.write_all(&resp).await.unwrap();
                    // 5.5 读 52B clientid 控制帧（speed tunnel 注册；不回显）
                    let mut cid = [0u8; 52];
                    tls.read_exact(&mut cid).await.unwrap();
                    assert_eq!(cid[0], 0x45);
                    assert_eq!(cid[9], 0xff);
                    assert_eq!(u16::from_be_bytes([cid[12], cid[13]]), 4);
                    // 6. 回显后续所有字节（模拟隧道）
                    loop {
                        match tls.read(&mut buf).await {
                            Ok(0) | Err(_) => break,
                            Ok(k) => {
                                if tls.write_all(&buf[..k]).await.is_err() {
                                    break;
                                }
                            }
                        }
                    }
                });
            }
        });
        port
    }

    #[tokio::test]
    async fn open_tunnel_handshake_and_data_mode() {
        let port = spawn_tunnel_mock().await;
        let client =
            ControlClient::new("vpn.example.com", port, true).unwrap().with_connect_addr("127.0.0.1", port);
        let (mut stream, cfg, netcfg, leftover) = client
            .open_tunnel(
                &crate::protocol::TunnelOpenParams {
                    cookie: "sid=s1",
                    dev_type: 1,
                    client_id: "cid",
                    cpu_id: "cpu",
                    hostname: "PC",
                    ipv6: false,
                },
                &[[192, 168, 1, 10]],
                &[0x11, 0x22, 0x33, 0x44, 0x55, 0x66],
            )
            .await
            .unwrap();
        assert_eq!(cfg, br#"{"mtu":1400,"allow_speed_tunnel":1}"#.to_vec());
        assert_eq!(
            netcfg.virtual_ip.map(|i| i.to_string()).as_deref(),
            Some("10.8.0.2")
        );
        assert_eq!(netcfg.dns.len(), 1);

        // 数据模式先导：leftover 里应有服务端随配置帧同 record 发来的裸 IP 包
        let mut wire_bytes = leftover;
        if wire_bytes.len() < 28 {
            use tokio::io::AsyncReadExt;
            let mut buf = [0u8; 64];
            let n = stream.read(&mut buf).await.unwrap();
            wire_bytes.extend_from_slice(&buf[..n]);
        }
        let mut ps = crate::frame::PacketStream::new();
        ps.feed(&wire_bytes);
        let item = ps.next_item().unwrap().unwrap();
        assert!(matches!(item, crate::frame::StreamItem::IpPacket(ref p) if p.len() == 28));

        // 再写一个包，服务器应回显
        use tokio::io::{AsyncReadExt, AsyncWriteExt};
        let echo_in = [0x45u8, 0, 0, 20, 0, 0, 0, 0, 64, 6, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2];
        stream.write_all(&echo_in).await.unwrap();
        let mut buf = [0u8; 64];
        let n = stream.read(&mut buf).await.unwrap();
        assert_eq!(&buf[..n], &echo_in);
    }

    #[tokio::test]
    async fn open_tunnel_rejects_302() {
        let port = spawn_mock_tls(Arc::new(|_| {
            "HTTP/1.1 302 Redirect\r\nLocation: /login\r\nContent-Length: 0\r\n\r\n".into()
        }))
        .await;
        let client =
            ControlClient::new("vpn.example.com", port, true).unwrap().with_connect_addr("127.0.0.1", port);
        let err = client
            .open_tunnel(
                &crate::protocol::TunnelOpenParams::default(),
                &[],
                &[0, 0, 0, 0, 0, 0],
            )
            .await
            .unwrap_err();
        assert!(matches!(err, ControlError::HttpStatus(302)));
    }

    // ---- 免浏览器登录流（验证码 + 登录提交） ----

    /// 二进制 mock：getImage 回 JPEG 字节；login 校验表单后种 ANsession。
    async fn spawn_weblogin_mock() -> u16 {
        use tokio::net::TcpListener;
        use tokio_rustls::rustls::pki_types::{CertificateDer, PrivateKeyDer};
        use tokio_rustls::TlsAcceptor;

        let cert = rcgen::generate_simple_self_signed(vec!["vpn.example.com".into()]).unwrap();
        let key_der = PrivateKeyDer::Pkcs8(cert.key_pair.serialize_der().into());
        let cfg = rustls::ServerConfig::builder()
            .with_no_client_auth()
            .with_single_cert(vec![CertificateDer::from(cert.cert)], key_der)
            .unwrap();
        let acceptor = TlsAcceptor::from(Arc::new(cfg));

        let listener = TcpListener::bind("127.0.0.1:0").await.unwrap();
        let port = listener.local_addr().unwrap().port();
        tokio::spawn(async move {
            while let Ok((sock, _)) = listener.accept().await {
                let acceptor = acceptor.clone();
                tokio::spawn(async move {
                    use tokio::io::{AsyncReadExt, AsyncWriteExt};
                    let Ok(mut tls) = acceptor.accept(sock).await else { return };
                    let mut buf = vec![0u8; 8192];
                    let Ok(n) = tls.read(&mut buf).await else { return };
                    let req = String::from_utf8_lossy(&buf[..n]).to_string();
                    if req.starts_with("GET /restservice/vpnLogin/getImage") {
                        let img: &[u8] = &[0xFF, 0xD8, 0xFF, 0xE0, 1, 2, 3, 0xFF, 0xD9]; // 假 JPEG
                        let resp = format!(
                            "HTTP/1.1 200 OK\r\nContent-Type: image/jpeg\r\nContent-Length: {}\r\n\
                             Set-Cookie: captcha_uuid=u1; Path=/\r\n\r\n",
                            img.len()
                        );
                        tls.write_all(resp.as_bytes()).await.unwrap();
                        tls.write_all(img).await.unwrap();
                    } else if req.starts_with("POST /restservice/vpnLogin/nextVpnNumberPhone") {
                        // 预校验：成功 JSON（门户 main.js 契约）
                        tls.write_all(b"HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: 21\r\n\r\n{\"message\":\"Success\"}").await.unwrap();
                    } else if req.starts_with("POST /prx/000/http/localhost/login") {
                        assert!(req.contains("Content-Type: application/x-www-form-urlencoded"));
                        let body = req.split("\r\n\r\n").nth(1).unwrap_or("");
                        assert!(body.contains("method=test&uname=example_user&pwd=p%40ss&authCode=1234"), "form: {body}");
                        let resp = "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\
                                    Set-Cookie: ANsession1716635751154266=abc; Path=/\r\n\r\n";
                        tls.write_all(resp.as_bytes()).await.unwrap();
                    } else {
                        tls.write_all(b"HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n").await.unwrap();
                    }
                });
            }
        });
        port
    }

    #[tokio::test]
    async fn web_login_captcha_and_submit() {
        let port = spawn_weblogin_mock().await;
        let client =
            ControlClient::new("vpn.example.com", port, true).unwrap().with_connect_addr("127.0.0.1", port);
        let mut session = Session::default();

        // 1. 验证码：二进制图片字节 + cookie 捕获
        let img = client.fetch_captcha(&mut session, "u1").await.unwrap();
        assert_eq!(img, vec![0xFF, 0xD8, 0xFF, 0xE0, 1, 2, 3, 0xFF, 0xD9]);
        assert!(session.cookies.contains(&"captcha_uuid=u1".to_string()));

        // 2. 预校验 + 登录提交：ANsession 种下
        let form = crate::protocol::LoginFormData {
            t: "t".into(),
            user_code: "example_user".into(),
            pwd: "p@ss".into(),
            code: "1234".into(),
        };
        client.token_precheck(&mut session, &form).await.unwrap();
        client.login(&mut session, &form).await.unwrap();
        assert!(session.cookies.iter().any(|c| c.starts_with("ANsession")));
    }

    #[tokio::test]
    async fn web_login_rejected_without_ansession() {
        let port = spawn_mock_tls(Arc::new(|_| {
            "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n".into() // 无 Set-Cookie
        }))
        .await;
        let client =
            ControlClient::new("vpn.example.com", port, true).unwrap().with_connect_addr("127.0.0.1", port);
        let mut session = Session::default();
        let form = crate::protocol::LoginFormData {
            t: "t".into(),
            user_code: "u".into(),
            pwd: "p".into(),
            code: "1".into(),
        };
        let err = client.login(&mut session, &form).await.unwrap_err();
        assert!(matches!(err, ControlError::AuthFailed));
    }
}
