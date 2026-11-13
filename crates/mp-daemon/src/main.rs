//! mp-daemon: 特权守护进程（对应原版 vpnd.exe）。
//! 逻辑在 lib.rs，此处仅启动 IPC server。

use mp_core::Engine;
use mp_daemon::handle_conn;
use mp_ipc::transport::TcpServer;

#[tokio::main]
async fn main() -> anyhow::Result<()> {
    tracing_subscriber::fmt()
        .with_env_filter(tracing_subscriber::EnvFilter::from_default_env())
        .init();
    let addr = std::env::var("MP_IPC_ADDR").unwrap_or_else(|_| "127.0.0.1:62000".into());
    let server = TcpServer::bind(&addr).await?;
    tracing::info!("mp-daemon listening on {addr}");

    let mut engine = Engine::new();
    loop {
        let mut conn = server.accept().await?;
        if let Err(e) = handle_conn(&mut engine, &mut conn).await {
            tracing::warn!("connection error: {e}");
        }
    }
}
