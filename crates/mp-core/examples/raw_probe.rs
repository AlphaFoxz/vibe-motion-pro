//! 裸字节级探针：手动 TLS + 发送与 ControlClient 完全相同的请求字节，
//! 读完整个响应（到 EOF 或空闲超时），打印总长度与结尾字节的转义形式。
use std::time::Duration;
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use tokio::net::TcpStream;
use tokio_rustls::rustls::pki_types::ServerName;
use tokio_rustls::TlsConnector;

#[tokio::main]
async fn main() {
    let host = "vpn.baowugroup.com";
    let tcp = TcpStream::connect((host, 443)).await.expect("tcp");
    let _ = tokio_rustls::rustls::crypto::ring::default_provider().install_default();
    let mut cfg = tokio_rustls::rustls::ClientConfig::builder_with_protocol_versions(&[&tokio_rustls::rustls::version::TLS12])
        .dangerous()
        .with_custom_certificate_verifier(std::sync::Arc::new(mp_core::control::NoVerify))
        .with_no_client_auth();
    cfg.alpn_protocols = vec![b"http/1.1".to_vec()];
    let connector = TlsConnector::from(std::sync::Arc::new(cfg));
    let mut tls = connector
        .connect(ServerName::try_from(host.to_string()).unwrap(), tcp)
        .await
        .expect("tls");

    let req = format!(
        "GET /restservice/vpnLogin/getImage?d={}&uuid=probe-uuid HTTP/1.1\r\nHost: {host}\r\n{}Connection: Keep-Alive\r\n\r\n",
        std::time::SystemTime::now().duration_since(std::time::UNIX_EPOCH).unwrap().as_millis(),
        mp_core::control::BROWSER_LIKE_HEADERS
    );
    tls.write_all(req.as_bytes()).await.unwrap();

    // 一直读到 EOF 或 3 秒无新数据
    let mut all = Vec::new();
    let mut buf = [0u8; 8192];
    loop {
        match tokio::time::timeout(Duration::from_secs(3), tls.read(&mut buf)).await {
            Ok(Ok(0)) => { println!("[raw] EOF，服务端关闭连接"); break; }
            Ok(Ok(n)) => { println!("[raw] +{n} 字节 (累计 {})", all.len() + n); all.extend_from_slice(&buf[..n]); }
            Ok(Err(e)) => { println!("[raw] 读错误: {e}"); break; }
            Err(_) => { println!("[raw] 3 秒无新数据，停止读取"); break; }
        }
    }
    println!("[raw] 总计 {} 字节", all.len());
    let head_end = all.windows(4).position(|w| w == b"\r\n\r\n").map(|p| p + 4).unwrap_or(all.len());
    println!("[raw] 头部 {} 字节:\n{}", head_end, String::from_utf8_lossy(&all[..head_end]));
    let tail = &all[all.len().saturating_sub(60)..];
    println!("[raw] 结尾 60 字节（转义）: {:?}", String::from_utf8_lossy(tail));
    println!("[raw] ends_with 0\\r\\n\\r\\n ? {}", all.ends_with(b"0\r\n\r\n"));

    // A/B 对照：同一进程内再用 ControlClient::fetch_captcha 走一遍
    if let Ok(client) = mp_core::control::ControlClient::new(host, 443, true) {
        let mut session = mp_core::control::Session::default();
        match tokio::time::timeout(Duration::from_secs(10), client.fetch_captcha(&mut session, "probe-uuid")).await {
            Ok(Ok(img)) => println!("[ab] fetch_captcha OK: {} bytes, cookies={:?}", img.len(), session.cookies),
            Ok(Err(e)) => println!("[ab] fetch_captcha ERR: {e}"),
            Err(_) => println!("[ab] fetch_captcha TIMEOUT"),
        }
    }
}
