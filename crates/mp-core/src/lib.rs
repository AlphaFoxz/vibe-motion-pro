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
pub mod tunnel;

pub use engine::Engine;
pub use error::Error;
pub use state::{StateMachine, VpnStatus};

/// 产品身份常量 —— 发布命名的唯一来源（与 app/src-tauri/tauri.conf.json 手工保持一致）。
/// - `APP_ID`：三平台配置/数据目录名。UI 侧 Tauri 自动用 identifier 派生目录，
///   daemon 侧显式 join 同名目录 → UI 与 daemon 数据同根，不散落两处。
///   不用连字符：注册表键名、DBus 服务名等场景对 `-` 兼容性差（发布后不可再改，
///   改了等于换应用：配置目录、凭据、升级通道全部重置）。
/// - `APP_NAME`：用户可见名。驼峰无空格：安装包文件名/安装目录/快捷方式/.app
///   bundle 路径都不需要引号转义，规避经典“路径带空格”问题。
pub const APP_ID: &str = "com.alphafoxz.vibemotionpro";
pub const APP_NAME: &str = "VibeMotionPro";

/// 连接状态机，对齐原版三态（connected/disconnected/reconnecting）。
#[derive(Debug, Clone, Copy, PartialEq, Eq, serde::Serialize)]
#[serde(rename_all = "snake_case")]
pub enum VpnStatusAlias {
    Disconnected,
    Connecting,
    Connected,
    Reconnecting,
}
