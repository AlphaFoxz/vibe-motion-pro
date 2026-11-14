//! mp-daemon: 特权守护进程（对应原版 vpnd + VPNService）。
//! - IPC server（127.0.0.1:62000，可用 MP_IPC_ADDR 覆盖）
//! - 1 秒状态轮询广播（对齐原版 vpnd detect_vni_status_thread）
//! - Profile 持久化（MP_PROFILES 路径，默认 <config>/profiles.toml）

use mp_core::profile::ProfileStore;
use std::path::Path;
use mp_daemon::{handle_conn, poll_interval_secs, DaemonState};
use mp_ipc::transport::TcpServer;
use std::path::PathBuf;
use tokio::time::{interval, Duration};

#[tokio::main]
async fn main() -> anyhow::Result<()> {
    tracing_subscriber::fmt()
        .with_env_filter(tracing_subscriber::EnvFilter::from_default_env())
        .init();

    // 启动时同步算好本地时区偏移（严禁在异步路径里 spawn PowerShell）
    mp_core::tunnel::set_local_utc_offset(mp_core::tunnel::local_utc_offset_secs());

    // 冻结自检器：主循环心跳 15 秒不前进 → cdb 抓栈（仅本地符号，20s 超时）+ 退出
    spawn_freeze_watchdog();

    let addr = std::env::var("MP_IPC_ADDR").unwrap_or_else(|_| "127.0.0.1:62000".into());
    let profiles_path = std::env::var("MP_PROFILES").unwrap_or_else(|_| {
        let cfg = std::env::var("APPDATA").unwrap_or_else(|_| ".".into());
        PathBuf::from(cfg).join("MotionPro").join("profiles.toml").display().to_string()
    });
    let store = ProfileStore::load(Path::new(&profiles_path))?;
    tracing::info!("loaded {} profiles from {}", store.list().len(), profiles_path);

    let mut state = DaemonState::new(store);
    let server = TcpServer::bind(&addr).await?;
    tracing::info!("mp-daemon listening on {addr}");

    // 状态轮询广播任务（对齐原版 1s 周期）
    {
        let state_ref = &state;
        // main 里 state 不能同时被连接处理与轮询可变借用；
        // 广播只读引擎状态，这里用 try_lock 模式：把 tick 放进 select 循环见下。
        let _ = state_ref;
    }

    let mut last: Option<mp_ipc::status::StatusSnapshot> = None;
    let mut ticker = interval(Duration::from_secs(poll_interval_secs()));
    loop {
        tokio::select! {
            conn = server.accept() => {
                // accept 失败绝不退出进程（真机曾出现 logout 后静默退出）：
                // 记日志、退避后继续服务
                let mut conn = match conn {
                    Ok(c) => c,
                    Err(e) => {
                        tracing::error!("ipc accept failed: {e}");
                        tokio::time::sleep(Duration::from_millis(500)).await;
                        continue;
                    }
                };
                if let Err(e) = handle_conn(&mut state, &mut conn).await {
                    tracing::warn!("connection error: {e}");
                }
            }
            _ = ticker.tick() => {
                FREEZE_TICK.fetch_add(1, std::sync::atomic::Ordering::Relaxed);
                if let Some(snap) = state.tick_broadcast(&mut last) {
                    // 状态已广播给订阅的 handle_conn；这里仅记录
                    tracing::debug!(state = snap.state, "status broadcast");
                }
            }
        }
    }
}

/// tokio 心跳计数器（watchdog 检测 runtime 冻结）。
pub static FREEZE_TICK: std::sync::atomic::AtomicU64 = std::sync::atomic::AtomicU64::new(0);

/// 冻结自检线程：独立 std 线程（不依赖 tokio）。15s 无心跳 →
/// 1) 用 cdb 抓全线程栈到 %TEMP%/opencode/freeze_auto.txt
/// 2) std::process::exit(3)（外部 supervisor/用户重启）
fn spawn_freeze_watchdog() {
    std::thread::Builder::new()
        .name("freeze-watchdog".into())
        .spawn(move || {
            let mut last_tick = FREEZE_TICK.load(std::sync::atomic::Ordering::Relaxed);
            let mut last_change = std::time::Instant::now();
            loop {
                std::thread::sleep(std::time::Duration::from_secs(2));
                let t = FREEZE_TICK.load(std::sync::atomic::Ordering::Relaxed);
                if t != last_tick {
                    last_tick = t;
                    last_change = std::time::Instant::now();
                    continue;
                }
                if last_change.elapsed() >= std::time::Duration::from_secs(15) {
                    // 冻结！抓栈（cdb 仅本地符号 + 20s 超时；符号服务器下载会永久
                    // 卡住并让目标线程保持挂起 —— 真机踩坑）后自杀
                    let dir = std::env::temp_dir().join("opencode");
                    let _ = std::fs::create_dir_all(&dir);
                    let out_path = dir.join("freeze_auto.txt");
                    let cdb = r"C:\Program Files (x86)\Windows Kits\10\Debuggers\x64\cdb.exe";
                    if std::path::Path::new(cdb).exists() {
                        if let Ok(mut child) = std::process::Command::new(cdb)
                            .arg("-p")
                            .arg(std::process::id().to_string())
                            .arg("-c")
                            .arg("~* k 30; qd")
                            .arg("-y")
                            .arg("D:\\vscode_projects\\motion-pro\\target\\debug")
                            .arg("-logo")
                            .arg(&out_path)
                            .spawn()
                        {
                            // 最多等 20s，防 cdb 卡死拖住 watchdog
                            let start = std::time::Instant::now();
                            loop {
                                if child.try_wait().ok().flatten().is_some() {
                                    break;
                                }
                                if start.elapsed() >= std::time::Duration::from_secs(20) {
                                    let _ = child.kill();
                                    break;
                                }
                                std::thread::sleep(std::time::Duration::from_millis(200));
                            }
                        }
                    }
                    let _ = std::fs::write(
                        dir.join("freeze_marker.txt"),
                        format!("frozen at {:?}", std::time::SystemTime::now()),
                    );
                    std::process::exit(3);
                }
            }
        })
        .expect("spawn freeze watchdog");
}
