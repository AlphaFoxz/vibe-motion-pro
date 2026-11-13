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
                let mut conn = conn?;
                if let Err(e) = handle_conn(&mut state, &mut conn).await {
                    tracing::warn!("connection error: {e}");
                }
            }
            _ = ticker.tick() => {
                if let Some(snap) = state.tick_broadcast(&mut last) {
                    // 状态已广播给订阅的 handle_conn；这里仅记录
                    tracing::debug!(state = snap.state, "status broadcast");
                }
            }
        }
    }
}
