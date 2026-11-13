//! 状态机：Disconnected / Connecting / Connected / Reconnecting
//! 对齐原版三态托盘图标 + connecting 中间态。

use thiserror::Error;

#[derive(Debug, Clone, Copy, PartialEq, Eq, serde::Serialize, serde::Deserialize)]
#[serde(rename_all = "snake_case")]
pub enum VpnStatus {
    /// -1/unknown 映射为 Disconnected 处理，另含细化态（route.cpp 枚举）
    Disconnected,
    Disconnecting,
    Connecting,
    ConnectFailed,
    Connected,
    Reconnecting,
    ReconnectFailed,
}

#[derive(Debug, Error, PartialEq)]
pub enum StateError {
    #[error("illegal transition: {0:?} -> {1:?}")]
    Illegal(VpnStatus, VpnStatus),
}

pub struct StateMachine {
    status: VpnStatus,
}

impl StateMachine {
    pub fn new() -> Self {
        Self { status: VpnStatus::Disconnected }
    }

    pub fn status(&self) -> VpnStatus {
        self.status
    }

    /// 状态迁移表（对齐原版 route.cpp 枚举，见 docs/runtime-forensics.md）：
    /// Disconnected    -> Connecting | Disconnecting
    /// Connecting      -> Connected | ConnectFailed | Disconnected(取消) | Reconnecting
    /// ConnectFailed   -> Disconnected | Connecting(重试)
    /// Connected       -> Reconnecting(断线) | Disconnecting(主动停止)
    /// Reconnecting    -> Connected(恢复) | ReconnectFailed | Disconnected(放弃/停止)
    /// ReconnectFailed -> Disconnected | Connecting(手动重试)
    /// Disconnecting   -> Disconnected
    pub fn transition(&mut self, to: VpnStatus) -> Result<VpnStatus, StateError> {
        let allowed = match (self.status, to) {
            (VpnStatus::Disconnected, VpnStatus::Connecting) => true,
            (VpnStatus::Disconnected, VpnStatus::Disconnecting) => true,
            (VpnStatus::Connecting, VpnStatus::Connected) => true,
            (VpnStatus::Connecting, VpnStatus::ConnectFailed) => true,
            (VpnStatus::Connecting, VpnStatus::Disconnected) => true,
            (VpnStatus::Connecting, VpnStatus::Reconnecting) => true,
            (VpnStatus::ConnectFailed, VpnStatus::Disconnected) => true,
            (VpnStatus::ConnectFailed, VpnStatus::Connecting) => true,
            (VpnStatus::Connected, VpnStatus::Reconnecting) => true,
            (VpnStatus::Connected, VpnStatus::Disconnecting) => true,
            (VpnStatus::Reconnecting, VpnStatus::Connected) => true,
            (VpnStatus::Reconnecting, VpnStatus::ReconnectFailed) => true,
            (VpnStatus::Reconnecting, VpnStatus::Disconnected) => true,
            (VpnStatus::Reconnecting, VpnStatus::Reconnecting) => true, // 重连尝试再次失败
            (VpnStatus::ReconnectFailed, VpnStatus::Disconnected) => true,
            (VpnStatus::ReconnectFailed, VpnStatus::Connecting) => true,
            (VpnStatus::Disconnecting, VpnStatus::Disconnected) => true,
            _ => false,
        };
        if !allowed {
            return Err(StateError::Illegal(self.status, to));
        }
        self.status = to;
        Ok(to)
    }
}

impl Default for StateMachine {
    fn default() -> Self {
        Self::new()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn happy_path() {
        let mut sm = StateMachine::new();
        sm.transition(VpnStatus::Connecting).unwrap();
        sm.transition(VpnStatus::Connected).unwrap();
        sm.transition(VpnStatus::Disconnected).unwrap();
        assert_eq!(sm.status(), VpnStatus::Disconnected);
    }

    #[test]
    fn reconnect_path() {
        let mut sm = StateMachine::new();
        sm.transition(VpnStatus::Connecting).unwrap();
        sm.transition(VpnStatus::Connected).unwrap();
        sm.transition(VpnStatus::Reconnecting).unwrap();
        sm.transition(VpnStatus::Connected).unwrap();
        assert_eq!(sm.status(), VpnStatus::Connected);
    }

    #[test]
    fn illegal_transitions_rejected() {
        let mut sm = StateMachine::new();
        // 未连接不能直接 Connected
        assert!(sm.transition(VpnStatus::Connected).is_err());
        // Disconnected 不能直接 Reconnecting
        assert!(sm.transition(VpnStatus::Reconnecting).is_err());
        sm.transition(VpnStatus::Connecting).unwrap();
        // Connecting 不能直接 Connecting
        assert_eq!(sm.transition(VpnStatus::Connecting), Err(StateError::Illegal(VpnStatus::Connecting, VpnStatus::Connecting)));
    }
}
