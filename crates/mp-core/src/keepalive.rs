//! 心跳保活（对齐 ArraySetKeepaliveOption / send_tcp_tunnel_keep_alive）。
//! 连续 miss 阈值后触发 on_dead 回调（由引擎转 Reconnecting）。

use std::time::{Duration, Instant};

pub struct KeepaliveMonitor {
    pub interval: Duration,
    pub max_misses: u32,
    last_seen: Instant,
    misses: u32,
}

impl KeepaliveMonitor {
    pub fn new(interval: Duration, max_misses: u32) -> Self {
        Self { interval, max_misses, last_seen: Instant::now(), misses: 0 }
    }

    /// 收到对端任何报文（KeepAlive 或 Data）即调用。
    pub fn mark_seen(&mut self) {
        self.last_seen = Instant::now();
        self.misses = 0;
    }

    /// 每个心跳周期调用一次；返回 true 表示对端已死。
    pub fn tick(&mut self) -> bool {
        if self.last_seen.elapsed() >= self.interval {
            self.misses += 1;
        }
        self.misses >= self.max_misses
    }

    pub fn misses(&self) -> u32 {
        self.misses
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn alive_when_seen() {
        let mut m = KeepaliveMonitor::new(Duration::from_millis(50), 3);
        m.mark_seen();
        assert!(!m.tick());
        assert!(!m.tick());
    }

    #[test]
    fn dead_after_max_misses() {
        let mut m = KeepaliveMonitor::new(Duration::from_millis(0), 3);
        // 不喂 mark_seen，模拟对端失联
        assert!(!m.tick());
        assert!(!m.tick());
        assert!(m.tick()); // 第 3 次到达阈值
        assert_eq!(m.misses(), 3);
    }
}
