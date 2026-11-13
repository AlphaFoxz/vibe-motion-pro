//! 真机网关探针：用 ControlClient 实际代码走 getImage/login(可选)，打印每步结果。
//! 用法：
//!   cargo run -p mp-core --example probe -- vpn.baowugroup.com
//!   （可选环境变量 PROBE_LOGIN=1 PROBE_USER=xx PROBE_PASS=xx PROBE_CODE=123456 时再测 login）

use mp_core::control::{ControlClient, Session};
use mp_core::protocol::LoginFormData;

#[tokio::main]
async fn main() {
    tracing_subscriber::fmt()
        .with_max_level(tracing::Level::DEBUG)
        .init();
    let host = std::env::args().nth(1).unwrap_or_else(|| "vpn.baowugroup.com".into());
    let client = match ControlClient::new(&host, 443, true) {
        Ok(c) => c,
        Err(e) => {
            eprintln!("[probe] client build failed: {e}");
            return;
        }
    };

    // 1. getImage
    let mut session = Session::default();
    let t0 = std::time::Instant::now();
    match tokio::time::timeout(std::time::Duration::from_secs(10), client.fetch_captcha(&mut session, "probe-uuid")).await {
        Ok(Ok(img)) => println!("[probe] getImage OK: {} bytes image, cookies={:?}, {:?}", img.len(), session.cookies, t0.elapsed()),
        Ok(Err(e)) => println!("[probe] getImage ERR: {e}"),
        Err(_) => println!("[probe] getImage TIMEOUT after 10s"),
    }

    // 2. login（仅在显式提供凭据时）
    if std::env::var("PROBE_LOGIN").is_ok() {
        let form = LoginFormData {
            t: "t".into(),
            user_code: std::env::var("PROBE_USER").unwrap_or_default(),
            pwd: std::env::var("PROBE_PASS").unwrap_or_default(),
            code: std::env::var("PROBE_CODE").unwrap_or_default(),
        };
        let t1 = std::time::Instant::now();
        match tokio::time::timeout(std::time::Duration::from_secs(10), client.login(&mut session, &form)).await {
            Ok(Ok((status, loc))) => println!("[probe] login OK: status={status} location={loc:?} cookies={:?}, {:?}", session.cookies, t1.elapsed()),
            Ok(Err(e)) => println!("[probe] login ERR: {e} cookies={:?}", session.cookies),
            Err(_) => println!("[probe] login TIMEOUT after 10s"),
        }
    }
}
