//! Tauri UI 进程：对应原版 MotionPro.exe（Qt5 UI）。
//!
//! 与 mp-daemon 的通信模型：**单条长连接 + 请求/推送多路复用**。
//! daemon 的 IPC 主循环是单连接串行处理（handle_conn 内 select 请求与
//! 1s 状态广播），因此 UI 侧必须把所有请求与 StatusUpdate 推送复用在
//! 同一条连接上——由 link_supervisor 维护连接，reader_loop 读事件，
//! 各 tauri command 经 send_cmd 挂起 oneshot 等待响应。
//!
//! 状态变化通过 `vpn-status` 事件推给前端（替代旧轮询）；
//! 托盘三态图标 / 菜单 / 通知 / 连接后自动收起窗口都在 Rust 侧完成。

use mp_ipc::codec::{recv_response, send_request};
use mp_ipc::profile::ProfileMsg;
use mp_ipc::status::StatusSnapshot;
use mp_ipc::transport::tcp_connect;
use mp_ipc::{Request, Response};
use serde::Serialize;
use std::collections::VecDeque;
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::time::Duration;
use tauri::menu::{Menu, MenuItem, PredefinedMenuItem};
use tauri::tray::{MouseButton, MouseButtonState, TrayIcon, TrayIconBuilder, TrayIconEvent};
use tauri::{AppHandle, Emitter, Manager, State, WindowEvent};
use tauri_plugin_notification::NotificationExt;
use tokio::io::{BufReader, ReadHalf, WriteHalf};
use tokio::sync::oneshot;

/// daemon IPC 地址；与 mp-daemon 一致支持 MP_IPC_ADDR 覆盖（开发/多实例测试用）。
fn daemon_addr() -> String {
    std::env::var("MP_IPC_ADDR").unwrap_or_else(|_| "127.0.0.1:62000".into())
}

type TcpRd = ReadHalf<tokio::net::TcpStream>;
type TcpWr = WriteHalf<tokio::net::TcpStream>;

/// 连接已断开时写入 write 槽的错误文案。
const ERR_LINK_DOWN: &str = "未连接到守护进程";

// ---------- 共享链路状态 ----------

struct LinkShared {
    /// 当前连接的写半边；None = 未连接。tokio Mutex（需跨 .await 持有）。
    write: tokio::sync::Mutex<Option<TcpWr>>,
    /// 在途请求的响应槽，FIFO 与请求发送顺序一致。
    pending: Mutex<VecDeque<oneshot::Sender<Result<Response, String>>>>,
}

impl LinkShared {
    fn new() -> Self {
        Self {
            write: tokio::sync::Mutex::new(None),
            pending: Mutex::new(VecDeque::new()),
        }
    }

    /// 发送请求并等待下一个非推送响应。挂起槽在写之前入队，保证 FIFO 配对。
    async fn send(&self, req: Request) -> Result<Response, String> {
        let (tx, rx) = oneshot::channel();
        {
            let mut g = self.write.lock().await;
            let wr = g.as_mut().ok_or_else(|| ERR_LINK_DOWN.to_string())?;
            self.pending.lock().unwrap().push_back(tx);
            if let Err(e) = send_request(&req, wr).await {
                // 写失败即连接已坏：reader 随后会 drain 所有挂起槽，这里直接报错
                return Err(format!("发送失败：{e}"));
            }
        }
        match tokio::time::timeout(Duration::from_secs(90), rx).await {
            Ok(Ok(res)) => res,
            Ok(Err(_)) => Err("与守护进程的连接已断开".into()),
            Err(_) => Err("守护进程响应超时".into()),
        }
    }

    /// reader 断开时清理：写槽置空 + 失败所有在途请求。
    async fn teardown(&self) {
        *self.write.lock().await = None;
        let mut q = self.pending.lock().unwrap();
        while let Some(tx) = q.pop_front() {
            let _ = tx.send(Err("与守护进程的连接已断开".into()));
        }
    }
}

// ---------- 托盘 UI 句柄 ----------

struct TrayUi {
    tray: TrayIcon<tauri::Wry>,
    status_item: MenuItem<tauri::Wry>,
    show_item: MenuItem<tauri::Wry>,
    connect_item: MenuItem<tauri::Wry>,
    disconnect_item: MenuItem<tauri::Wry>,
    quit_item: MenuItem<tauri::Wry>,
}

struct AppState {
    link: Arc<LinkShared>,
    tray: Mutex<Option<TrayUi>>,
    /// 上一次状态（用于检测进入/离开 connected 的边沿）
    last_state: Mutex<String>,
    /// 托盘菜单语言（"zh-CN" | "en" | "ja"），由前端 set_tray_texts 同步
    tray_lang: Mutex<&'static str>,
}

/// 连接成功后自动收起窗口（原版 ShowUIAfterConnected 语义的镜像）。
static AUTO_HIDE: AtomicBool = AtomicBool::new(true);

// ---------- 托盘图标资源（scripts/gen_brand_icons.js 生成） ----------

const TRAY_CONNECTED: &[u8] = include_bytes!("../icons/tray-connected.png");
const TRAY_CONNECTING: &[u8] = include_bytes!("../icons/tray-connecting.png");
const TRAY_DISCONNECTED: &[u8] = include_bytes!("../icons/tray-disconnected.png");

fn tray_icon_for(state: &str) -> Option<tauri::image::Image<'static>> {
    let bytes = match state {
        "connected" => TRAY_CONNECTED,
        "connecting" | "reconnecting" => TRAY_CONNECTING,
        _ => TRAY_DISCONNECTED,
    };
    tauri::image::Image::from_bytes(bytes).ok()
}

fn state_label(state: &str, lang: &str) -> &'static str {
    match (state, lang) {
        ("connected", "en") => "Connected",
        ("connected", "ja") => "接続済み",
        ("connected", _) => "已连接",
        ("connecting", "en") => "Connecting",
        ("connecting", "ja") => "接続中",
        ("connecting", _) => "连接中",
        ("reconnecting", "en") => "Reconnecting",
        ("reconnecting", "ja") => "再接続中",
        ("reconnecting", _) => "重连中",
        ("disconnecting", "en") => "Disconnecting",
        ("disconnecting", "ja") => "切断中",
        ("disconnecting", _) => "断开中",
        (_, "en") => "Disconnected",
        (_, "ja") => "未接続",
        (_, _) => "未连接",
    }
}

/// 状态变化：推事件给前端 + 同步托盘（图标/文案/菜单可用性） + 边沿通知与自动收起。
fn handle_status(app: &AppHandle, snap: StatusSnapshot) {
    let state = app.state::<AppState>();
    let prev = state.last_state.lock().unwrap().clone();
    let cur = snap.state.clone();

    if prev != cur {
        *state.last_state.lock().unwrap() = cur.clone();
        if cur == "connected" {
            let _ = app
                .notification()
                .builder()
                .title("MotionPro")
                .body("VPN 已连接 · Connected")
                .show();
            if AUTO_HIDE.load(Ordering::Relaxed) {
                let a = app.clone();
                tauri::async_runtime::spawn(async move {
                    tokio::time::sleep(Duration::from_millis(900)).await;
                    if AUTO_HIDE.load(Ordering::Relaxed) {
                        if let Some(w) = a.get_webview_window("main") {
                            let _ = w.hide();
                        }
                    }
                });
            }
        } else if prev == "connected" && cur == "disconnected" {
            let _ = app
                .notification()
                .builder()
                .title("MotionPro")
                .body("VPN 已断开 · Disconnected")
                .show();
        }
    }

    let _ = app.emit("vpn-status", &snap);

    let lang = *state.tray_lang.lock().unwrap();
    if let Ok(guard) = state.tray.lock() {
        if let Some(ui) = guard.as_ref() {
            if let Some(img) = tray_icon_for(&cur) {
                let _ = ui.tray.set_icon(Some(img));
            }
            let _ = ui
                .tray
                .set_tooltip(Some(format!("MotionPro — {}", state_label(&cur, lang))));
            let _ = ui
                .status_item
                .set_text(format!("MotionPro — {}", state_label(&cur, lang)).as_str());
            let busy = matches!(cur.as_str(), "connecting" | "reconnecting");
            let _ = ui.connect_item.set_enabled(cur != "connected" && !busy);
            let _ = ui.disconnect_item.set_enabled(cur == "connected" || busy);
        }
    };
}

// ---------- 链路维护 ----------

/// 常驻任务：维持与 daemon 的单条长连接（断线 2s 退避重连）。
/// 建链后发一次 Status 握手（daemon 广播仅在变化时推送，需主动取初值）。
async fn link_supervisor(app: AppHandle) {
    loop {
        match tcp_connect(&daemon_addr()).await {
            Err(e) => {
                tracing::debug!(error = %e, "daemon link not available");
                tokio::time::sleep(Duration::from_millis(2000)).await;
            }
            Ok(stream) => {
                let shared = {
                    let state = app.state::<AppState>();
                    state.link.clone()
                };
                let (rd, wr) = tokio::io::split(stream);
                *shared.write.lock().await = Some(wr);
                let _ = app.emit("vpn-link", true);
                tracing::info!("daemon link established");

                // 握手：查询当前状态（响应走 reader 的推送分支，不入 pending 队列）
                {
                    let mut g = shared.write.lock().await;
                    if let Some(w) = g.as_mut() {
                        let _ = send_request(&Request::Status, w).await;
                    }
                }

                let reader = tokio::spawn(reader_loop(rd, shared.clone(), app.clone()));
                let _ = reader.await;
                tokio::time::sleep(Duration::from_millis(1500)).await;
            }
        }
    }
}

/// 读循环：Status/StatusUpdate → 事件；其余响应 → FIFO 交给在途请求。
/// 单任务独占读半边，await 到完成再迭代，无 select 取消风险。
/// BufReader 在本任务内包装（split 的 ReadHalf 不透传 AsyncBufRead）。
async fn reader_loop(rd_raw: TcpRd, shared: Arc<LinkShared>, app: AppHandle) {
    let mut rd = BufReader::new(rd_raw);
    loop {
        match recv_response(&mut rd).await {
            Ok(Response::StatusUpdate { status }) | Ok(Response::Status { status }) => {
                handle_status(&app, status);
            }
            Ok(other) => {
                let tx = shared.pending.lock().unwrap().pop_front();
                if let Some(tx) = tx {
                    let _ = tx.send(Ok(other));
                } else {
                    tracing::debug!(?other, "unsolicited daemon response");
                }
            }
            Err(e) => {
                tracing::info!(error = %e, "daemon link closed");
                break;
            }
        }
    }
    shared.teardown().await;
    let _ = app.emit("vpn-link", false);
}

// ---------- 窗口辅助 ----------

fn show_main(app: &AppHandle) {
    if let Some(w) = app.get_webview_window("main") {
        let _ = w.show();
        let _ = w.set_focus();
    }
}

fn toggle_main(app: &AppHandle) {
    if let Some(w) = app.get_webview_window("main") {
        let visible = w.is_visible().unwrap_or(false);
        let focused = w.is_focused().unwrap_or(false);
        if visible && focused {
            let _ = w.hide();
        } else {
            let _ = w.show();
            let _ = w.set_focus();
        }
    }
}

// ---------- DTO ----------

#[derive(Serialize)]
struct SessionInfo {
    session_id: Option<String>,
}

// ---------- Tauri commands ----------

#[tauri::command]
async fn vpn_status(state: State<'_, AppState>) -> Result<StatusSnapshot, String> {
    match state.link.send(Request::Status).await? {
        Response::Status { status } => Ok(status),
        _ => Err("unexpected response".into()),
    }
}

#[tauri::command]
async fn vpn_connect(
    state: State<'_, AppState>,
    host: String,
    port: u16,
    username: String,
    password: String,
    code: String,
) -> Result<StatusSnapshot, String> {
    match state
        .link
        .send(Request::Connect { host, port, username, password, code })
        .await?
    {
        Response::Status { status } => Ok(status),
        Response::Error { message } => Err(message),
        _ => Err("unexpected response".into()),
    }
}

#[allow(dead_code)] // 原版对齐保留：daemon Start 目前是骨架模式（无凭据）
#[tauri::command]
async fn vpn_start(state: State<'_, AppState>, profile_id: String) -> Result<StatusSnapshot, String> {
    match state.link.send(Request::Start { profile_id }).await? {
        Response::Status { status } => Ok(status),
        Response::Error { message } => Err(message),
        _ => Err("unexpected response".into()),
    }
}

#[tauri::command]
async fn vpn_stop(state: State<'_, AppState>) -> Result<StatusSnapshot, String> {
    match state.link.send(Request::Stop).await? {
        Response::Status { status } => Ok(status),
        Response::Error { message } => Err(message),
        _ => Err("unexpected response".into()),
    }
}

#[tauri::command]
async fn vpn_session(state: State<'_, AppState>) -> Result<SessionInfo, String> {
    match state.link.send(Request::GetSession).await? {
        Response::Session { session_id } => Ok(SessionInfo { session_id }),
        _ => Err("unexpected response".into()),
    }
}

#[tauri::command]
async fn profile_list(state: State<'_, AppState>) -> Result<Vec<ProfileMsg>, String> {
    match state.link.send(Request::ListProfiles).await? {
        Response::Profiles { profiles } => Ok(profiles),
        Response::Error { message } => Err(message),
        _ => Err("unexpected response".into()),
    }
}

#[tauri::command]
async fn profile_add(state: State<'_, AppState>, profile: ProfileMsg) -> Result<Vec<ProfileMsg>, String> {
    match state.link.send(Request::AddProfile { profile }).await? {
        Response::Profiles { profiles } => Ok(profiles),
        Response::Error { message } => Err(message),
        _ => Err("unexpected response".into()),
    }
}

#[tauri::command]
async fn profile_remove(state: State<'_, AppState>, profile_id: String) -> Result<Vec<ProfileMsg>, String> {
    match state.link.send(Request::RemoveProfile { profile_id }).await? {
        Response::Profiles { profiles } => Ok(profiles),
        Response::Error { message } => Err(message),
        _ => Err("unexpected response".into()),
    }
}

// ---------- OS 凭据管理器（记住密码） ----------

fn keyring_entry(profile_id: &str) -> Result<keyring::Entry, String> {
    keyring::Entry::new("MotionPro", &format!("vpn-pass:{profile_id}")).map_err(|e| e.to_string())
}

#[tauri::command]
async fn password_save(profile_id: String, password: String) -> Result<(), String> {
    tokio::task::spawn_blocking(move || {
        let entry = keyring_entry(&profile_id)?;
        entry.set_password(&password).map_err(|e| e.to_string())
    })
    .await
    .map_err(|e| e.to_string())?
}

#[tauri::command]
async fn password_get(profile_id: String) -> Result<Option<String>, String> {
    tokio::task::spawn_blocking(move || {
        let entry = keyring_entry(&profile_id)?;
        match entry.get_password() {
            Ok(p) => Ok(Some(p)),
            Err(keyring::Error::NoEntry) => Ok(None),
            Err(e) => Err(e.to_string()),
        }
    })
    .await
    .map_err(|e| e.to_string())?
}

#[tauri::command]
async fn password_delete(profile_id: String) -> Result<(), String> {
    tokio::task::spawn_blocking(move || {
        let entry = keyring_entry(&profile_id)?;
        match entry.delete_credential() {
            Ok(()) | Err(keyring::Error::NoEntry) => Ok(()),
            Err(e) => Err(e.to_string()),
        }
    })
    .await
    .map_err(|e| e.to_string())?
}

// ---------- UI 偏好 ----------

#[tauri::command]
fn set_autohide(enabled: bool) {
    AUTO_HIDE.store(enabled, Ordering::Relaxed);
}

#[tauri::command]
fn ui_hide_window(app: AppHandle) {
    if let Some(w) = app.get_webview_window("main") {
        let _ = w.hide();
    }
}

/// 前端语言切换时同步托盘菜单文案。
#[tauri::command]
fn set_tray_texts(
    state: State<'_, AppState>,
    lang: String,
    show: String,
    connect: String,
    disconnect: String,
    quit: String,
) -> Result<(), String> {
    let recognized = match lang.as_str() {
        "en" => "en",
        "ja" => "ja",
        _ => "zh-CN",
    };
    *state.tray_lang.lock().unwrap() = recognized;
    if let Ok(guard) = state.tray.lock() {
        if let Some(ui) = guard.as_ref() {
            ui.show_item.set_text(show.as_str()).map_err(|e| e.to_string())?;
            ui.connect_item.set_text(connect.as_str()).map_err(|e| e.to_string())?;
            ui.disconnect_item.set_text(disconnect.as_str()).map_err(|e| e.to_string())?;
            ui.quit_item.set_text(quit.as_str()).map_err(|e| e.to_string())?;
            // 状态行按当前状态刷新
            let cur = state.last_state.lock().unwrap().clone();
            ui.status_item
                .set_text(format!("MotionPro — {}", state_label(&cur, recognized)).as_str())
                .map_err(|e| e.to_string())?;
        }
    }
    Ok(())
}

fn main() {
    tracing_subscriber::fmt()
        .with_env_filter(tracing_subscriber::EnvFilter::from_default_env())
        .init();

    tauri::Builder::default()
        .plugin(tauri_plugin_notification::init())
        .invoke_handler(tauri::generate_handler![
            vpn_status,
            vpn_connect,
            vpn_start,
            vpn_stop,
            vpn_session,
            profile_list,
            profile_add,
            profile_remove,
            password_save,
            password_get,
            password_delete,
            set_autohide,
            ui_hide_window,
            set_tray_texts
        ])
        .setup(|app| {
            let handle = app.handle().clone();

            // 托盘：三态图标 + 菜单（状态行禁用项 / 显示窗口 / 连接 / 断开 / 退出）
            let status_item =
                MenuItem::with_id(&handle, "status-line", "MotionPro — 未连接", false, None::<&str>)?;
            let show_item = MenuItem::with_id(&handle, "show", "显示主窗口", true, None::<&str>)?;
            let connect_item = MenuItem::with_id(&handle, "tray-connect", "连接…", true, None::<&str>)?;
            let disconnect_item =
                MenuItem::with_id(&handle, "tray-disconnect", "断开", false, None::<&str>)?;
            let quit_item = MenuItem::with_id(&handle, "quit", "退出", true, None::<&str>)?;
            let sep1 = PredefinedMenuItem::separator(&handle)?;
            let sep2 = PredefinedMenuItem::separator(&handle)?;
            let menu = Menu::with_items(
                &handle,
                &[&status_item, &sep1, &show_item, &connect_item, &disconnect_item, &sep2, &quit_item],
            )?;

            let tray = TrayIconBuilder::with_id("mp-tray")
                .icon(tray_icon_for("disconnected").expect("embedded tray icon"))
                .menu(&menu)
                .show_menu_on_left_click(false)
                .tooltip("MotionPro — 未连接")
                .build(&handle)?;

            tray.on_menu_event(|app, event| match event.id().as_ref() {
                "show" => show_main(app),
                // 真实认证需要动态密保，托盘只负责唤起主界面并预选默认服务器
                "tray-connect" => {
                    show_main(app);
                    let _ = app.emit("tray-connect", ());
                }
                "tray-disconnect" => {
                    let app = app.clone();
                    tauri::async_runtime::spawn(async move {
                        let state = app.state::<AppState>();
                        if let Err(e) = state.link.send(Request::Stop).await {
                            tracing::warn!(error = %e, "tray disconnect failed");
                        }
                    });
                }
                "quit" => app.exit(0),
                _ => {}
            });
            tray.on_tray_icon_event(|tray, event| {
                if let TrayIconEvent::Click {
                    button: MouseButton::Left,
                    button_state: MouseButtonState::Up,
                    ..
                } = event
                {
                    toggle_main(tray.app_handle());
                }
            });

            app.manage(AppState {
                link: Arc::new(LinkShared::new()),
                tray: Mutex::new(Some(TrayUi {
                    tray,
                    status_item,
                    connect_item,
                    disconnect_item,
                    show_item,
                    quit_item,
                })),
                last_state: Mutex::new("disconnected".into()),
                tray_lang: Mutex::new("zh-CN"),
            });

            tauri::async_runtime::spawn(link_supervisor(handle));
            Ok(())
        })
        .on_window_event(|window, event| {
            // 关窗 = 收起托盘（VPN 客户端惯例），退出走托盘菜单
            if let WindowEvent::CloseRequested { api, .. } = event {
                api.prevent_close();
                let _ = window.hide();
            }
        })
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
