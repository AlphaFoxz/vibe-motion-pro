//! 登录后资源抓取探针：完整走 captcha→precheck→login，然后用会话拉取欢迎页关键 JS。
//! 用法：
//!   $env:PROBE_USER="工号"; $env:PROBE_PASS="密码"; $env:PROBE_CODE="动态码"
//!   cargo run -q -p mp-core --example fetch_after_login -- vpn.baowugroup.com
//! 产物写入 %TEMP%\opencode\gw\*.js（l3vpn.js / an_login.js / welcome.js ...）

use mp_core::control::{ControlClient, Session};
use mp_core::protocol::LoginFormData;

#[tokio::main]
async fn main() {
    let host = std::env::args().nth(1).unwrap_or_else(|| "vpn.baowugroup.com".into());
    let user = std::env::var("PROBE_USER").expect("PROBE_USER");
    let pass = std::env::var("PROBE_PASS").expect("PROBE_PASS");
    let code = std::env::var("PROBE_CODE").expect("PROBE_CODE（手机动态码，1分钟时效）");

    let client = ControlClient::new(&host, 443, true).unwrap();
    let mut session = Session::default();

    // 1. captcha 种会话
    let uuid = format!("probe{}", std::process::id());
    let _ = client.fetch_captcha(&mut session, &uuid).await;
    println!("[probe] captcha seeded");

    // 2. 预校验
    let form = LoginFormData {
        t: "t".into(),
        user_code: user.clone(),
        pwd: pass,
        code,
    };
    client.token_precheck(&mut session, &form).await.expect("precheck failed");
    println!("[probe] precheck ok");

    // 3. /prx 登录（AG 网关）
    let action = client.fetch_login_action(&mut session).await.expect("no form action");
    let ag_host = action
        .split("://").nth(1).unwrap_or(&action)
        .split('/').next().unwrap()
        .split(':').next().unwrap().to_string();
    println!("[probe] AG host: {ag_host}");
    let ag = ControlClient::new(&ag_host, 443, true).unwrap();
    let (status, loc) = ag.login(&mut session, &form).await.expect("login failed");
    println!("[probe] login ok: {status} -> {loc:?}");
    println!("[probe] cookies: {:?}", session.cookies.iter().map(|c| c.split('=').next().unwrap_or("")).collect::<Vec<_>>());

    // 4. 用会话拉关键资源（AG 网关上的 /prx 树）
    let targets = [
        "/prx/000/http/localhost/welcome/l3vpn.js",
        "/prx/000/http/localhost/welcome/welcome.js",
        "/prx/000/http/localhost/welcome/dd.js",
        "/prx/000/http/localhost/an_login.js",
        "/prx/000/http/localhost/an_vpn.js",
        "/prx/000/http/localhost:65200/motionpro/postlogin/apps?_uname={UNAME}&_role=&_pid=0&_instid=default",
    ];
    let out_dir = std::env::temp_dir().join("opencode").join("gw");
    std::fs::create_dir_all(&out_dir).unwrap();
    for t in targets {
        let path = t.replace("{UNAME}", &user);
        match ag.get_public(&path, &mut session).await {
            Ok(resp) => {
                let name = path.split('/').next_back().unwrap_or("x").split('?').next().unwrap_or("res");
                let file = out_dir.join(format!("{}-{name}", resp.status));
                std::fs::write(&file, &resp.body).unwrap();
                println!("[probe] {} -> {} ({} bytes) saved {:?}", resp.status, path, resp.body.len(), file.file_name());
            }
            Err(e) => println!("[probe] ERR {path}: {e}"),
        }
    }
}
