//! mp-core: MotionPro 协议核心。
//! 模块划分见 docs/plan-phase2.md。

pub mod control;
pub mod dataplane;
pub mod engine;
pub mod error;
pub mod frame;
pub mod keepalive;
pub mod nat;
pub mod profile;
pub mod protocol;
pub mod reconnect;
pub mod session;
pub mod state;

pub use engine::Engine;
pub use error::Error;
pub use state::{StateMachine, VpnStatus};

/// 连接状态机，对齐原版三态（connected/disconnected/reconnecting）。
#[derive(Debug, Clone, Copy, PartialEq, Eq, serde::Serialize)]
#[serde(rename_all = "snake_case")]
pub enum VpnStatusAlias {
    Disconnected,
    Connecting,
    Connected,
    Reconnecting,
}
