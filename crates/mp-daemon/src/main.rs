//! mp-daemon: 特权守护进程（对应原版 vpnd + VPNService）。
//! - IPC server（127.0.0.1:62000，可用 MP_IPC_ADDR 覆盖）
//! - 1 秒状态轮询广播（对齐原版 vpnd detect_vni_status_thread）
//! - Profile 持久化（MP_PROFILES 路径，默认 <config>/profiles.toml）

use mp_core::profile::ProfileStore;
use mp_daemon::{handle_conn, poll_interval_secs, DaemonState, FREEZE_TICK};
use mp_ipc::transport::TcpServer;
use std::path::{Path, PathBuf};
use std::sync::Arc;
use tokio::sync::Mutex;
use tokio::time::{interval, Duration};

#[tokio::main]
async fn main() -> anyhow::Result<()> {
    tracing_subscriber::fmt()
        .with_env_filter(tracing_subscriber::EnvFilter::from_default_env())
        .init();

    // 启动时同步算好本地时区偏移（严禁在异步路径里 spawn PowerShell）
    mp_core::tunnel::set_local_utc_offset(mp_core::tunnel::local_utc_offset_secs());

    // 冻结自检器：心跳 15 秒不前进 → cdb 抓栈（仅本地符号，20s 超时）+ 退出
    spawn_freeze_watchdog();

    let addr = std::env::var("MP_IPC_ADDR").unwrap_or_else(|_| "127.0.0.1:62000".into());
    let profiles_path = std::env::var("MP_PROFILES").unwrap_or_else(|_| {
        let cfg = std::env::var("APPDATA").unwrap_or_else(|_| ".".into());
        PathBuf::from(cfg).join("MotionPro").join("profiles.toml").display().to_string()
    });
    let store = ProfileStore::load(Path::new(&profiles_path))?;
    tracing::info!("loaded {} profiles from {}", store.list().len(), profiles_path);

    // 状态跨任务共享：每条连接一个独立 task——持久 UI 连接不再饿死主循环 tick
    // （2026-11 真机踩坑：handle_conn 内联 await 时 ticker 分支 15s 不被轮询，
    //   冻结看门狗误判自杀）；连接内另有独立心跳分支，认证期间（锁被长时间持有）
    //   FREEZE_TICK 仍每秒前进，看门狗不会误杀。
    let state = Arc::new(Mutex::new(DaemonState::new(store)));
    let server = {
        // 绑定失败重试而非立即退出：本机其他服务偶发抢占端口（如开发工具的
        // live-daemon 抢过 62000），重试窗口内常可恢复；耗尽后带指引退出。
        let mut attempts = 0u32;
        loop {
            match TcpServer::bind(&addr).await {
                Ok(s) => break s,
                Err(e) => {
                    attempts += 1;
                    if attempts >= 10 {
                        anyhow::bail!(
                            "IPC bind {addr} 失败（重试 {attempts} 次）：{e}；\
                             端口被占用时可改用 MP_IPC_ADDR=127.0.0.1:<port>（UI 侧同样设置）"
                        );
                    }
                    tracing::warn!("ipc bind {addr} failed ({e}), retry {attempts}/10 in 1s");
                    tokio::time::sleep(Duration::from_secs(1)).await;
                }
            }
        }
    };
    tracing::info!("mp-daemon listening on {addr}");

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
                let st = state.clone();
                tokio::spawn(async move {
                    if let Err(e) = handle_conn(st, &mut conn).await {
                        tracing::warn!("connection error: {e}");
                    }
                });
            }
            _ = ticker.tick() => {
                // 心跳先行且绝不等待状态锁：select handler 一旦 await 锁会挂起
                // 整个主循环任务，心跳就停了 —— 真实网关认证可轻松持锁 >15s，
                // 看门狗会误杀健康 daemon（2026-11-14 12:01 实证）。锁忙（认证中）
                // 则本 tick 跳过广播；连接响应本身会携带最新状态。
                FREEZE_TICK.fetch_add(1, std::sync::atomic::Ordering::Relaxed);
                if let Ok(mut st) = state.try_lock() {
                    if let Some(snap) = st.tick_broadcast(&mut last) {
                        tracing::debug!(state = snap.state, "status broadcast");
                    }
                }
            }
        }
    }
}

/// tokio 心跳计数器（watchdog 检测 runtime 冻结）——定义在 mp_daemon::FREEZE_TICK，
/// main 循环与各连接任务都会推进。

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
