//! 指数退避重连策略（对齐 ArraySetReconnectParameters / ArraySetWaittingTimesNoDriver 语义）。

#[derive(Debug, Clone)]
pub struct ReconnectPolicy {
    pub enabled: bool,
    pub max_attempts: u32,
    pub base_delay_ms: u64,
    pub max_delay_ms: u64,
}

impl Default for ReconnectPolicy {
    fn default() -> Self {
        Self { enabled: true, max_attempts: 5, base_delay_ms: 1000, max_delay_ms: 30_000 }
    }
}

impl ReconnectPolicy {
    /// 第 attempt 次重连（从 0 计）应等待的毫秒数：base * 2^attempt，封顶 max。
    pub fn delay_ms(&self, attempt: u32) -> u64 {
        let d = self.base_delay_ms.saturating_mul(1u64 << attempt.min(16));
        d.min(self.max_delay_ms)
    }

    pub fn should_retry(&self, attempt: u32) -> bool {
        self.enabled && attempt < self.max_attempts
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn exponential_backoff_capped() {
        let p = ReconnectPolicy { base_delay_ms: 1000, max_delay_ms: 8000, ..Default::default() };
        assert_eq!(p.delay_ms(0), 1000);
        assert_eq!(p.delay_ms(1), 2000);
        assert_eq!(p.delay_ms(2), 4000);
        assert_eq!(p.delay_ms(3), 8000);
        assert_eq!(p.delay_ms(4), 8000); // 封顶
        assert_eq!(p.delay_ms(10), 8000);
    }

    #[test]
    fn retry_limit() {
        let p = ReconnectPolicy { enabled: true, max_attempts: 3, ..Default::default() };
        assert!(p.should_retry(0));
        assert!(p.should_retry(2));
        assert!(!p.should_retry(3));
    }

    #[test]
    fn disabled_no_retry() {
        let p = ReconnectPolicy { enabled: false, ..Default::default() };
        assert!(!p.should_retry(0));
    }
}
