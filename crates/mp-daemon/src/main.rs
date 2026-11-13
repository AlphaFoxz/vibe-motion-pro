//! mp-daemon: 特权守护进程（对应原版 vpnd.exe）。
//! Windows: 服务 / macOS: launchd / Linux: systemd
//! 职责：创建虚拟网卡（mp-platform）、运行隧道数据面（mp-core）、
//! 通过 mp-ipc 接受 UI 进程指令。

use mp_core::VpnStatus;

#[tokio::main]
async fn main() -> anyhow::Result<()> {
    tracing_subscriber::fmt()
        .with_env_filter(tracing_subscriber::EnvFilter::from_default_env())
        .init();
    tracing::info!("mp-daemon starting");
    // TODO: 初始化 IPC server（named pipe / unix socket）
    // TODO: 收到 start 指令后：mp-platform 建网卡 -> mp-core 建隧道 -> 写路由/DNS
    tracing::info!(status = ?VpnStatus::Disconnected, "idle");
    Ok(())
}
