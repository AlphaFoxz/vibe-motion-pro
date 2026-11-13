//! Tauri UI 进程：对应原版 MotionPro.exe（Qt5 UI）。
//! commands 桥接 mp-daemon（通过 mp-ipc 传输）。

use mp_core::VpnStatus;
use mp_ipc::codec::{recv_response, send_request};
use mp_ipc::profile::ProfileMsg;
use mp_ipc::status::StatusSnapshot;
use mp_ipc::transport::tcp_connect;
use mp_ipc::{Request, Response};
use serde::Serialize;
use std::sync::Mutex;
use tauri::{State, tray::TrayIconBuilder};

const DAEMON_ADDR: &str = "127.0.0.1:62000";

#[derive(Default)]
struct AppEngine {
    last_status: Mutex<StatusSnapshot>,
}

#[derive(Serialize)]
struct SessionInfo {
    session_id: Option<String>,
}

fn status_from_response(res: Response) -> StatusSnapshot {
    match res {
        Response::Status { status } => status,
        _ => StatusSnapshot::disconnected(),
    }
}

async fn ask_daemon(req: Request) -> Result<Response, String> {
    let stream = tcp_connect(DAEMON_ADDR).await.map_err(|e| e.to_string())?;
    let mut stream = tokio::io::BufReader::new(stream);
    send_request(&req, &mut stream).await.map_err(|e| e.to_string())?;
    recv_response(&mut stream).await.map_err(|e| e.to_string())
}

#[tauri::command]
async fn vpn_status(state: State<'_, AppEngine>) -> Result<StatusSnapshot, String> {
    match ask_daemon(Request::Status).await {
        Ok(res) => {
            let s = status_from_response(res);
            *state.last_status.lock().unwrap() = s.clone();
            Ok(s)
        }
        Err(_) => Ok(state.last_status.lock().unwrap().clone()),
    }
}

#[tauri::command]
async fn vpn_start(profile_id: String) -> Result<StatusSnapshot, String> {
    let res = ask_daemon(Request::Start { profile_id }).await?;
    Ok(status_from_response(res))
}

#[tauri::command]
async fn vpn_stop() -> Result<StatusSnapshot, String> {
    let res = ask_daemon(Request::Stop).await?;
    Ok(status_from_response(res))
}

#[tauri::command]
async fn vpn_session() -> Result<SessionInfo, String> {
    match ask_daemon(Request::GetSession).await? {
        Response::Session { session_id } => Ok(SessionInfo { session_id }),
        _ => Err("unexpected response".into()),
    }
}

#[tauri::command]
async fn profile_list() -> Result<Vec<ProfileMsg>, String> {
    match ask_daemon(Request::ListProfiles).await? {
        Response::Profiles { profiles } => Ok(profiles),
        _ => Err("unexpected response".into()),
    }
}

#[tauri::command]
async fn profile_add(profile: ProfileMsg) -> Result<Vec<ProfileMsg>, String> {
    match ask_daemon(Request::AddProfile { profile }).await? {
        Response::Profiles { profiles } => Ok(profiles),
        Response::Error { message } => Err(message),
        _ => Err("unexpected response".into()),
    }
}

#[tauri::command]
async fn profile_remove(profile_id: String) -> Result<Vec<ProfileMsg>, String> {
    match ask_daemon(Request::RemoveProfile { profile_id }).await? {
        Response::Profiles { profiles } => Ok(profiles),
        Response::Error { message } => Err(message),
        _ => Err("unexpected response".into()),
    }
}

fn main() {
    tracing_subscriber::fmt()
        .with_env_filter(tracing_subscriber::EnvFilter::from_default_env())
        .init();
    let _ = VpnStatus::Disconnected; // 保留引用
    tauri::Builder::default()
        .manage(AppEngine::default())
        .invoke_handler(tauri::generate_handler![
            vpn_status,
            vpn_start,
            vpn_stop,
            vpn_session,
            profile_list,
            profile_add,
            profile_remove
        ])
        .setup(|app| {
            // 托盘图标（对齐原版三态：connected/disconnected/reconnecting）
            // TODO: 从 reference/ 提取原版 ico 后替换默认图标
            let _tray = TrayIconBuilder::with_id("mp-tray")
                .tooltip("MotionPro")
                .build(app)?;
            Ok(())
        })
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
