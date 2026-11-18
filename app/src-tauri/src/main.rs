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
        // daemon 侧 Connect 有 120s 总超时兜底；这里必须等得更久，
        // 否则慢登录实际成功、UI 却提前报错，连接成功后的逻辑被跳过。
        match tokio::time::timeout(Duration::from_secs(125), rx).await {
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
                .title("VibeMotionPro")
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
                .title("VibeMotionPro")
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
                .set_tooltip(Some(format!("VibeMotionPro — {}", state_label(&cur, lang))));
            let _ = ui
                .status_item
                .set_text(format!("VibeMotionPro — {}", state_label(&cur, lang)).as_str());
            let busy = matches!(cur.as_str(), "connecting" | "reconnecting");
            let _ = ui.connect_item.set_enabled(cur != "connected" && !busy);
            let _ = ui.disconnect_item.set_enabled(cur == "connected" || busy);
        }
    };
}

// ---------- 链路维护 ----------

/// 断链多久后首次自动拉起 daemon（给"daemon 还没起"一点余量，也避免
/// 应用启动瞬间的抖动直接触发 UAC）。
const SPAWN_AFTER: Duration = Duration::from_secs(3);
/// 首次拉起未果后，第二次（最后一次）拉起的等待时长。
const SPAWN_RETRY_AFTER: Duration = Duration::from_secs(20);
/// 链路稳定在线多久后，重新获得自动拉起配额（防 daemon「秒死循环」
/// 反复触发 UAC 轰炸；正常崩溃自愈不受影响）。
const LINK_STABLE: Duration = Duration::from_secs(60);

/// 是否应该自动拉起 daemon（纯函数便于单测）。`attempts` 为本次断链
/// 已拉起次数（链路稳定在线 ≥ LINK_STABLE 后由调用方清零）。
fn should_spawn_daemon(link_down: Option<Duration>, attempts: u32) -> bool {
    let Some(down) = link_down else { return false };
    match attempts {
        0 => down >= SPAWN_AFTER,
        1 => down >= SPAWN_RETRY_AFTER,
        _ => false,
    }
}

/// 拉起结果（`daemon-spawn` 事件载荷，前端据此分流提示文案）。
/// Ok/Denied 仅在 Windows 构造（非 Windows 不走 sidecar）。
#[derive(Clone, Serialize)]
#[serde(rename_all = "snake_case", tag = "kind")]
#[allow(dead_code)]
enum SpawnOutcome {
    /// ShellExecuteW 成功（连接随后自动恢复，不打扰用户）。
    Ok,
    /// UAC 被拒绝（SE_ERR_ACCESSDENIED）。
    Denied,
    /// 其他失败：sidecar 缺失 / 路径无法定位 / ShellExecute 错误。
    Error { detail: String },
}

/// 以管理员权限（UAC）拉起 daemon sidecar：`runas` + `--managed --parent-pid <UI>`。
/// daemon 生命周期随本进程（见 mp-daemon managed 模式）。
/// 提权用 ShellExecuteW 的 runas 动词——Tauri shell 插件与 CreateProcess 均无法提权。
#[tauri::command]
fn ui_spawn_daemon() -> SpawnOutcome {
    #[cfg(windows)]
    {
        let exe_dir = std::env::current_exe()
            .ok()
            .and_then(|p| p.parent().map(|d| d.to_path_buf()));
        let Some(dir) = exe_dir else {
            return SpawnOutcome::Error {
                detail: "无法定位应用目录".into(),
            };
        };
        let daemon = dir.join("mp-daemon.exe");
        if !daemon.exists() {
            // exe 缺位：bundle resources 只在 tauri build 时拷贝，dev 下从未
            // cargo build -p mp-daemon 就会落到这里。注意：本仓库 cargo workspace
            // 共享 target/debug，daemon 构建过一次（且按 runbook 放好 wintun.dll）
            // 后 exe 就在 UI exe 旁，dev 同样走自动拉起；runbook 里管理员终端手动
            // cargo run -p mp-daemon 只在需要 RUST_LOG=debug 看 daemon 日志时才有必要。
            return SpawnOutcome::Error {
                detail: format!("未找到守护进程二进制（{}）", daemon.display()),
            };
        }
        let params = format!("--managed --parent-pid {}", std::process::id());
        let to_wide = |s: &str| {
            let mut v: Vec<u16> = s.encode_utf16().collect();
            v.push(0);
            v
        };
        let verb = to_wide("runas");
        let file = to_wide(&daemon.display().to_string());
        let args = to_wide(&params);
        let dir_w = to_wide(&dir.display().to_string());
        // SW_HIDE = 0（daemon 侧另有 FreeConsole 兜底）；HWND null = 0（0.52 句柄为 isize）
        let code = unsafe {
            windows_sys::Win32::UI::Shell::ShellExecuteW(
                0,
                verb.as_ptr(),
                file.as_ptr(),
                args.as_ptr(),
                dir_w.as_ptr(),
                0,
            )
        };
        // 返回值 > 32 为成功；SE_ERR_ACCESSDENIED(5) = UAC 被拒
        if code as isize > 32 {
            tracing::info!("daemon sidecar spawned (runas)");
            SpawnOutcome::Ok
        } else if code as isize == 5 {
            tracing::warn!("daemon sidecar spawn: UAC denied");
            SpawnOutcome::Denied
        } else {
            SpawnOutcome::Error {
                detail: format!("ShellExecuteW code {code}"),
            }
        }
    }
    #[cfg(not(windows))]
    {
        // Linux 由 systemd 服务承担 daemon 生命周期（plan-release.md P2），不走 sidecar
        SpawnOutcome::Error {
            detail: "仅 Windows 支持自动拉起".into(),
        }
    }
}

/// 常驻任务：维持与 daemon 的单条长连接（断线 2s 退避重连）。
/// 断链持续时按 should_spawn_daemon 策略自动拉起 daemon（仅 Windows），
/// 结果经 `daemon-spawn` 事件推给前端分流提示。
/// 建链后发一次 Status 握手（daemon 广播仅在变化时推送，需主动取初值）。
async fn link_supervisor(app: AppHandle) {
    let mut down_since: Option<std::time::Instant> = None;
    let mut spawn_attempts: u32 = 0;
    let mut up_since: Option<std::time::Instant> = None;
    loop {
        match tcp_connect(&daemon_addr()).await {
            Err(e) => {
                tracing::debug!(error = %e, "daemon link not available");
                let down = down_since
                    .get_or_insert_with(std::time::Instant::now)
                    .elapsed();
                if should_spawn_daemon(Some(down), spawn_attempts) {
                    spawn_attempts += 1;
                    let outcome = ui_spawn_daemon();
                    let _ = app.emit("daemon-spawn", &outcome);
                }
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

                // 握手：查询当前状态。此刻 pending 为空，应答在 reader 里
                // 走"无在途请求的 Status"分支按推送处理（若前端恰好抢先
                // 发出了 Status 请求，则由它拿到同一份数据，二者等价）。
                {
                    let mut g = shared.write.lock().await;
                    if let Some(w) = g.as_mut() {
                        let _ = send_request(&Request::Status, w).await;
                    }
                }

                let reader = tokio::spawn(reader_loop(rd, shared.clone(), app.clone()));
                let _ = reader.await;
                // 链路断开：稳定在线过则重置拉起配额（下次 daemon 崩溃仍可自动恢复）
                if let Some(t) = up_since {
                    if t.elapsed() >= LINK_STABLE {
                        spawn_attempts = 0;
                    }
                }
                up_since = None;
                down_since = Some(std::time::Instant::now());
                tokio::time::sleep(Duration::from_millis(1500)).await;
            }
        }
    }
}

/// 读循环：StatusUpdate 推送 → 事件；其余响应 → FIFO 交给在途请求。
/// 注意 `Response::Status` 有两种来源：Status/Connect/Stop 请求的**应答**
/// （必须归还挂起槽，否则前端 invoke 挂到超时、连接后的保存密码等
/// 后续逻辑全部被跳过），以及 link_supervisor 建链握手（不入队，此时
/// 队列为空 → 按推送处理）。
/// 单任务独占读半边，await 到完成再迭代，无 select 取消风险。
/// BufReader 在本任务内包装（split 的 ReadHalf 不透传 AsyncBufRead）。
async fn reader_loop(rd_raw: TcpRd, shared: Arc<LinkShared>, app: AppHandle) {
    let push_app = app.clone();
    reader_core(rd_raw, shared, move |status| {
        handle_status(&push_app, status)
    })
    .await;
    let _ = app.emit("vpn-link", false);
}

/// reader_loop 的核心（推送回调注入以便测试；AppHandle/Tauri 事件不可在单测构造）。
async fn reader_core<F: FnMut(StatusSnapshot)>(
    rd_raw: TcpRd,
    shared: Arc<LinkShared>,
    mut on_push: F,
) {
    let mut rd = BufReader::new(rd_raw);
    loop {
        match recv_response(&mut rd).await {
            Ok(Response::StatusUpdate { status }) => on_push(status),
            Ok(other) => {
                let tx = shared.pending.lock().unwrap().pop_front();
                match (tx, other) {
                    (Some(tx), resp) => {
                        let _ = tx.send(Ok(resp));
                    }
                    // 握手应答（无在途请求）：作为初始状态推送处理
                    (None, Response::Status { status }) => on_push(status),
                    (None, other) => tracing::debug!(?other, "unsolicited daemon response"),
                }
            }
            Err(e) => {
                tracing::info!(error = %e, "daemon link closed");
                break;
            }
        }
    }
    shared.teardown().await;
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
    keyring::Entry::new("VibeMotionPro", &format!("vpn-pass:{profile_id}")).map_err(|e| e.to_string())
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
                .set_text(format!("VibeMotionPro — {}", state_label(&cur, recognized)).as_str())
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
            set_tray_texts,
            ui_spawn_daemon
        ])
        .setup(|app| {
            let handle = app.handle().clone();

            // 托盘：三态图标 + 菜单（状态行禁用项 / 显示窗口 / 连接 / 断开 / 退出）
            let status_item =
                MenuItem::with_id(&handle, "status-line", "VibeMotionPro — 未连接", false, None::<&str>)?;
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
                .tooltip("VibeMotionPro — 未连接")
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

#[cfg(test)]
mod tests {
    use super::*;
    use mp_ipc::codec::recv_request;
    use std::sync::Mutex as StdMutex;

    fn snap(state: &str) -> StatusSnapshot {
        StatusSnapshot { state: state.into(), rtt_ms: None, server_ip: None, client_ip: None }
    }

    fn connect_req() -> Request {
        Request::Connect {
            host: "vpn.example.com".into(),
            port: 443,
            username: "user".into(),
            password: "pass".into(),
            code: "123456".into(),
        }
    }

    /// 建立一对「UI(LinkShared+reader_core) ↔ 假 daemon」的回环链路。
    /// 返回共享链路与收到的推送列表（按到达顺序记录 state）。
    async fn setup_link() -> (Arc<LinkShared>, Arc<StdMutex<Vec<String>>>) {
        let listener = tokio::net::TcpListener::bind("127.0.0.1:0").await.unwrap();
        let addr = listener.local_addr().unwrap();

        tokio::spawn(async move { fake_daemon(listener).await });

        let stream = tokio::net::TcpStream::connect(addr).await.unwrap();
        let (rd, wr) = tokio::io::split(stream);
        let shared = Arc::new(LinkShared::new());
        *shared.write.lock().await = Some(wr);

        let pushes = Arc::new(StdMutex::new(Vec::new()));
        let sink = pushes.clone();
        tokio::spawn(reader_core(rd, shared.clone(), move |s| {
            sink.lock().unwrap().push(s.state);
        }));
        (shared, pushes)
    }

    /// 假 daemon：对齐 crates/mp-daemon handle_conn 的真实行为——
    /// - Connect：先推 StatusUpdate(connecting)（engine 状态变化触发广播），
    ///   再回 Status(connected) 应答；两行**一次写出**，模拟应答与推送
    ///   挤在同一 TCP 段；
    /// - Status：回 Status 应答；
    /// - Stop：回 Status(disconnected) 应答（真实 daemon 行为）。
    async fn fake_daemon(listener: tokio::net::TcpListener) {
        let (stream, _) = listener.accept().await.unwrap();
        let (rd, mut wr) = tokio::io::split(stream);
        let mut rd = BufReader::new(rd);
        while let Ok(req) = recv_request(&mut rd).await {
            let (push, resp) = match req {
                Request::Connect { .. } => {
                    (Some(snap("connecting")), Response::Status { status: snap("connected") })
                }
                Request::Status => (None, Response::Status { status: snap("disconnected") }),
                Request::Stop => (None, Response::Status { status: snap("disconnected") }),
                _ => (None, Response::Error { message: "unsupported".into() }),
            };
            let mut wire = String::new();
            if let Some(s) = push {
                wire.push_str(
                    &serde_json::to_string(&Response::StatusUpdate { status: s }).unwrap(),
                );
                wire.push('\n');
            }
            wire.push_str(&serde_json::to_string(&resp).unwrap());
            wire.push('\n');
            use tokio::io::AsyncWriteExt as _;
            wr.write_all(wire.as_bytes()).await.unwrap();
            wr.flush().await.unwrap();
        }
    }

    /// 回归（保存密码失效的根因）：daemon 对 Connect 的应答是
    /// Response::Status。修复前 reader 把它当推送吃掉，`send` 永远等不到
    /// 应答直到 125s 超时——前端 connect() 走 catch 提前 return，
    /// 连接成功后的保存用户名/密码代码块从不执行。
    #[tokio::test]
    async fn connect_status_reply_resolves_pending_request() {
        let (shared, _pushes) = setup_link().await;
        let resp = tokio::time::timeout(Duration::from_secs(5), shared.send(connect_req()))
            .await
            .expect("send 应收到 daemon 的 Status 应答（修复前挂到超时）")
            .unwrap();
        match resp {
            Response::Status { status } => assert_eq!(status.state, "connected"),
            other => panic!("unexpected: {other:?}"),
        }
    }

    /// Connect 在途时 daemon 的 StatusUpdate 广播必须走推送回调，
    /// 且不影响应答归还（应答与推送同段写出，兼测 codec 批量解帧）。
    #[tokio::test]
    async fn interleaved_push_and_reply_are_routed_separately() {
        let (shared, pushes) = setup_link().await;
        let resp = tokio::time::timeout(Duration::from_secs(5), shared.send(connect_req()))
            .await
            .expect("应答必须归还挂起请求")
            .unwrap();
        assert!(matches!(resp, Response::Status { ref status } if status.state == "connected"));

        tokio::time::timeout(Duration::from_secs(5), async {
            while pushes.lock().unwrap().is_empty() {
                tokio::time::sleep(Duration::from_millis(10)).await;
            }
        })
        .await
        .expect("推送必须经 on_push 送达");
        assert_eq!(pushes.lock().unwrap().as_slice(), ["connecting"]);
    }

    /// link_supervisor 建链握手：pending 为空时，Status 应答按初始状态推送处理。
    #[tokio::test]
    async fn handshake_status_without_pending_is_pushed() {
        let (shared, pushes) = setup_link().await;
        // 不发任何请求，仅做握手查询（对齐 link_supervisor 的直发方式）
        {
            let mut g = shared.write.lock().await;
            let w = g.as_mut().unwrap();
            mp_ipc::codec::send_request(&Request::Status, w).await.unwrap();
        }
        tokio::time::timeout(Duration::from_secs(5), async {
            while pushes.lock().unwrap().is_empty() {
                tokio::time::sleep(Duration::from_millis(10)).await;
            }
        })
        .await
        .expect("握手应答应作为推送送达");
        assert_eq!(pushes.lock().unwrap().as_slice(), ["disconnected"]);
    }

    /// Stop / Status 请求的应答同样是 Response::Status，也必须归还。
    #[tokio::test]
    async fn stop_and_status_replies_resolve_pending() {
        let (shared, _pushes) = setup_link().await;
        for req in [Request::Status, Request::Stop, Request::Status] {
            let resp = tokio::time::timeout(Duration::from_secs(5), shared.send(req))
                .await
                .expect("应答必须归还挂起请求（FIFO）")
                .unwrap();
            assert!(matches!(resp, Response::Status { .. }), "unexpected: {resp:?}");
        }
    }

    /// 断链拉起策略：3s 首次 / 20s 第二次 / 之后转人工；未断链不拉起。
    #[test]
    fn spawn_policy_two_attempts_then_stop() {
        assert!(!should_spawn_daemon(None, 0), "链路正常时不拉起");
        assert!(!should_spawn_daemon(Some(Duration::from_secs(1)), 0), "断链未满 3s");
        assert!(should_spawn_daemon(Some(SPAWN_AFTER), 0), "断链 ≥3s 首次拉起");
        assert!(!should_spawn_daemon(Some(Duration::from_secs(10)), 1), "首次未果未满 20s");
        assert!(should_spawn_daemon(Some(SPAWN_RETRY_AFTER), 1), "二次拉起");
        assert!(!should_spawn_daemon(Some(Duration::from_secs(300)), 2), "配额用尽转人工");
    }
}
