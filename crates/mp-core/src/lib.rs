//! mp-core: MotionPro 协议核心（协议握手 / 会话 / 隧道状态机）。
//! 具体实现按 docs/protocol-clues.md 的逆向结果逐步填充。

pub mod error;
pub mod session;

pub use error::Error;

/// 连接状态机，对齐原版三态（connected/disconnected/reconnecting）。
#[derive(Debug, Clone, Copy, PartialEq, Eq, serde::Serialize)]
#[serde(rename_all = "snake_case")]
pub enum VpnStatus {
    Disconnected,
    Connecting,
    Connected,
    Reconnecting,
}
