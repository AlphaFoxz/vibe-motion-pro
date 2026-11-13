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

/// 会话：cookie jar + AAA 方式缓存。
#[derive(Debug, Clone, Default)]
pub struct Session {
    pub cookies: Vec<String>,
    pub aaa_methods: Vec<String>,
    pub server: String,
}

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
        let cfg = if danger {
            rustls::ClientConfig::builder()
                .dangerous()
                .with_custom_certificate_verifier(Arc::new(NoVerify))
                .with_no_client_auth()
        } else {
            // TODO: rustls-native-certs 载入系统根证书 + 原版 rootca pinning
            let roots = rustls::RootCertStore::empty();
            rustls::ClientConfig::builder().with_root_certificates(roots).with_no_client_auth()
        };
        Ok(TlsConnector::from(Arc::new(cfg)))
    }

    async fn connect_tls(&self) -> Result<tokio_rustls::client::TlsStream<TcpStream>, ControlError> {
        let tcp = TcpStream::connect((self.connect_addr.0.as_str(), self.connect_addr.1)).await?;
        let name = ServerName::try_from(self.host.clone())
            .map_err(|_| ControlError::Protocol(ProtocolError::BadPath(self.host.clone())))?;
        Ok(self.connector.connect(name, tcp).await?)
    }

    /// GET 并解析；自动附带 session cookie，自动捕获 Set-Cookie。
    async fn get(
        &self,
        stream: &mut tokio_rustls::client::TlsStream<TcpStream>,
        path: &str,
        session: &mut Session,
    ) -> Result<HttpResponse, ControlError> {
        let cookie_hdr = if session.cookies.is_empty() {
            String::new()
        } else {
            format!("Cookie: {}\r\n", session.cookies.join("; "))
        };
        let req = format!(
            "GET {path} HTTP/1.1\r\nHost: {}\r\nConnection: Keep-Alive\r\n{cookie_hdr}\r\n",
            self.host
        );
        stream.write_all(req.as_bytes()).await?;
        let mut buf = Vec::with_capacity(8192);
        let mut chunk = [0u8; 4096];
        loop {
            let n = stream.read(&mut chunk).await?;
            if n == 0 {
                break;
            }
            buf.extend_from_slice(&chunk[..n]);
            // 头完整后按 Content-Length 判断是否读完
            if let Ok(resp) = parse_response(&buf) {
                let header_end = buf.windows(4).position(|w| w == b"\r\n\r\n").unwrap_or(0) + 4;
                let clen: usize =
                    resp.header("content-length").and_then(|v| v.parse().ok()).unwrap_or(0);
                if resp.header("transfer-encoding").is_none() && buf.len() >= header_end + clen {
                    break;
                }
            }
        }
        let mut resp = parse_response(&buf)?;
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
}

/// 骨架阶段：不校验服务器证书。
#[derive(Debug)]
struct NoVerify;

impl rustls::client::danger::ServerCertVerifier for NoVerify {
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
}
