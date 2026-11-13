//! Engine：组合状态机 + 重连策略 + 保活，响应 IPC 指令。
//! 真实隧道建立（mp-core::protocol / dataplane）未就绪时以模拟连接验证全流程。

use crate::keepalive::KeepaliveMonitor;
use crate::reconnect::ReconnectPolicy;
use crate::session::{Credentials, Session, TunnelType};
use crate::state::{StateMachine, VpnStatus};
use std::time::Duration;

#[derive(Default)]
pub struct Engine {
    sm: StateMachine,
    pub reconnect: ReconnectPolicy,
    session: Option<Session>,
    reconnect_attempt: u32,
}

impl Engine {
    pub fn new() -> Self {
        Self {
            sm: StateMachine::new(),
            reconnect: ReconnectPolicy::default(),
            session: None,
            reconnect_attempt: 0,
        }
    }

    pub fn status(&self) -> VpnStatus {
        self.sm.status()
    }

    pub fn session(&self) -> Option<&Session> {
        self.session.as_ref()
    }

    /// 发起连接（对应 ArrayStartVPNClient）。
    pub fn start(
        &mut self,
        _creds: &Credentials,
        tunnel: TunnelType,
    ) -> Result<VpnStatus, crate::Error> {
        match self.sm.status() {
            VpnStatus::Disconnected => {
                self.sm.transition(VpnStatus::Connecting)?;
                self.reconnect_attempt = 0;
                // TODO(逆向): 真实握手 -> 连接成功后填 session
                self.session = Some(Session {
                    session_id: format!("sim-{}", uuid_v4()),
                    server: String::new(),
                    tunnel_type: tunnel,
                });
                self.sm.transition(VpnStatus::Connected)?;
                Ok(self.sm.status())
            }
            s => Err(crate::Error::Protocol(format!(
                "cannot start from state {s:?}"
            ))),
        }
    }

    /// 主动断开（对应 ArrayStopVPNClient）。先 Disconnecting 再 Disconnected。
    pub fn stop(&mut self) -> Result<VpnStatus, crate::Error> {
        match self.sm.status() {
            VpnStatus::Disconnected => Ok(VpnStatus::Disconnected),
            _ => {
                self.session = None;
                if self.sm.status() != VpnStatus::Disconnecting {
                    self.sm.transition(VpnStatus::Disconnecting)?;
                }
                self.sm.transition(VpnStatus::Disconnected)?;
                self.reconnect_attempt = 0;
                Ok(self.sm.status())
            }
        }
    }

    /// 数据面/心跳报告连接丢失，进入重连（对应 ArrayMonitorKeepaliveStatus 断链）。
    pub fn on_link_dead(&mut self) -> Result<(VpnStatus, Option<u64>), crate::Error> {
        if matches!(
            self.sm.status(),
            VpnStatus::Connected | VpnStatus::Connecting | VpnStatus::Reconnecting
        ) {
            if self.reconnect.should_retry(self.reconnect_attempt) {
                self.sm.transition(VpnStatus::Reconnecting)?;
                let delay = self.reconnect.delay_ms(self.reconnect_attempt);
                self.reconnect_attempt += 1;
                Ok((self.sm.status(), Some(delay)))
            } else {
                self.stop()?;
                Ok((VpnStatus::Disconnected, None))
            }
        } else {
            Err(crate::Error::Protocol(format!(
                "link dead in state {:?}",
                self.sm.status()
            )))
        }
    }

    /// 重连成功后调用。
    pub fn on_reconnected(&mut self) -> Result<VpnStatus, crate::Error> {
        self.sm.transition(VpnStatus::Connected)?;
        self.reconnect_attempt = 0;
        Ok(self.sm.status())
    }

    pub fn set_reconnect(&mut self, enabled: bool, max_attempts: u32) {
        self.reconnect.enabled = enabled;
        self.reconnect.max_attempts = max_attempts;
    }
}

/// 简单 UUID v4（避免为骨架引入依赖）。
fn uuid_v4() -> String {
    use std::time::{SystemTime, UNIX_EPOCH};
    let t = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .unwrap_or_default();
    format!("{:x}-{:x}", t.as_nanos(), std::process::id())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn creds() -> Credentials {
        Credentials {
            username: "u".into(),
            password: "p".into(),
            aaa_method: None,
            hwid: None,
        }
    }

    #[test]
    fn start_stop_lifecycle() {
        let mut e = Engine::new();
        assert_eq!(e.status(), VpnStatus::Disconnected);
        e.start(&creds(), TunnelType::Tcp).unwrap();
        assert_eq!(e.status(), VpnStatus::Connected);
        assert!(e.session().is_some());
        e.stop().unwrap();
        assert_eq!(e.status(), VpnStatus::Disconnected);
        assert!(e.session().is_none());
    }

    #[test]
    fn double_start_rejected() {
        let mut e = Engine::new();
        e.start(&creds(), TunnelType::Udp).unwrap();
        assert!(e.start(&creds(), TunnelType::Udp).is_err());
    }

    #[test]
    fn link_dead_goes_reconnecting_then_gives_up() {
        let mut e = Engine::new();
        e.set_reconnect(true, 2);
        e.start(&creds(), TunnelType::Tcp).unwrap();

        let (st, d0) = e.on_link_dead().unwrap();
        assert_eq!(st, VpnStatus::Reconnecting);
        assert_eq!(d0, Some(1000));
        let (_, d1) = e.on_link_dead().unwrap(); // attempt=1
        assert_eq!(d1, Some(2000));

        // 恢复一次
        e.on_reconnected().unwrap();
        assert_eq!(e.status(), VpnStatus::Connected);
        assert_eq!(e.reconnect_attempt, 0);

        // 再次失联：重试计数已恢复，需要 max_attempts 次后才放弃 -> Disconnected
        let (st, _) = e.on_link_dead().unwrap();
        assert_eq!(st, VpnStatus::Reconnecting);
        let (st, _) = e.on_link_dead().unwrap();
        assert_eq!(st, VpnStatus::Reconnecting);
        let (st, d) = e.on_link_dead().unwrap(); // attempt=2 耗尽
        assert_eq!(st, VpnStatus::Disconnected);
        assert_eq!(d, None);
    }

    #[test]
    fn keepalive_detects_dead_peer() {
        let mut m = KeepaliveMonitor::new(Duration::from_millis(0), 2);
        m.mark_seen();
        assert!(!m.tick());
        assert!(m.tick());
    }
}
