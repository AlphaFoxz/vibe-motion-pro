//! NAT / 会话表：隧道内五元组流 → smoltcp socket 关联与老化。
//!
//! 对齐原版 vl3vpn.dll 的会话分流（split tunnel 域名表 + TAF 规则配合）。

use std::collections::HashMap;
use std::net::Ipv4Addr;
use std::time::{Duration, Instant};

/// 五元组流标识。
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct FlowKey {
    pub proto: u8, // 6=TCP, 17=UDP
    pub src: Ipv4Addr,
    pub sport: u16,
    pub dst: Ipv4Addr,
    pub dport: u16,
}

impl FlowKey {
    /// 反向流。
    pub fn reverse(&self) -> Self {
        FlowKey { proto: self.proto, src: self.dst, sport: self.dport, dst: self.src, dport: self.sport }
    }

    /// 从 IP/TCP|UDP 包头提取 FlowKey（失败返回 None）。packet 为完整 IP 包。
    pub fn key_from_packet(packet: &[u8]) -> Option<FlowKey> {
        if packet.len() < 20 || (packet[0] >> 4) != 4 {
            return None;
        }
        let ihl = (packet[0] & 0xf) as usize * 4;
        if packet.len() < ihl {
            return None;
        }
        let proto = packet[9];
        if proto != 6 && proto != 17 {
            return None;
        }
        let src = Ipv4Addr::new(packet[12], packet[13], packet[14], packet[15]);
        let dst = Ipv4Addr::new(packet[16], packet[17], packet[18], packet[19]);
        let l4 = packet.get(ihl..ihl + 4)?;
        Some(FlowKey {
            proto,
            src,
            sport: u16::from_be_bytes([l4[0], l4[1]]),
            dst,
            dport: u16::from_be_bytes([l4[2], l4[3]]),
        })
    }

    /// 从 IP 包提取载荷长度（total - ihl - 4 伪头，测试构造对应）。
    pub fn payload_len_from_packet(packet: &[u8]) -> Option<usize> {
        if packet.len() < 20 || (packet[0] >> 4) != 4 {
            return None;
        }
        let ihl = (packet[0] & 0xf) as usize * 4;
        let total = u16::from_be_bytes([packet[2], packet[3]]) as usize;
        Some(total.saturating_sub(ihl).saturating_sub(4))
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum FlowState {
    /// SYN/首包新建
    New,
    /// 已建立（看到握手完成或数据）
    Established,
    /// 半关闭
    Closing,
}

#[derive(Debug, Clone)]
pub struct FlowEntry {
    pub state: FlowState,
    pub last_seen: Instant,
    /// 关联的 smoltcp socket handle（由 Dataplane 填写）
    pub socket_ref: Option<u64>,
    /// 累计字节数（上下行合计）
    pub bytes: u64,
}

/// 会话表。
pub struct SessionTable {
    flows: HashMap<FlowKey, FlowEntry>,
    idle_timeout: Duration,
    max_entries: usize,
}

impl SessionTable {
    pub fn new(idle_timeout: Duration, max_entries: usize) -> Self {
        Self { flows: HashMap::new(), idle_timeout, max_entries }
    }

    /// 默认：空闲 300s 老化；上限 4096 条。
    pub fn with_defaults() -> Self {
        Self::new(Duration::from_secs(300), 4096)
    }

    pub fn len(&self) -> usize {
        self.flows.len()
    }

    pub fn is_empty(&self) -> bool {
        self.flows.is_empty()
    }

    pub fn get(&self, k: &FlowKey) -> Option<&FlowEntry> {
        self.flows.get(k)
    }

    /// 记录一个包：新建或更新流。返回 (是否新建, 表是否因上限拒绝)。
    pub fn observe(&mut self, k: FlowKey, payload_len: usize, now: Instant) -> (bool, bool) {
        if let Some(e) = self.flows.get_mut(&k) {
            e.last_seen = now;
            e.bytes += payload_len as u64;
            if e.state == FlowState::New && payload_len > 0 {
                e.state = FlowState::Established;
            }
            return (false, false);
        }
        if self.flows.len() >= self.max_entries {
            self.expire(now);
            if self.flows.len() >= self.max_entries {
                return (false, true); // 仍满，拒绝新建
            }
        }
        self.flows.insert(
            k,
            FlowEntry { state: FlowState::New, last_seen: now, socket_ref: None, bytes: payload_len as u64 },
        );
        (true, false)
    }

    /// 标记流关闭。
    pub fn close(&mut self, k: &FlowKey) -> bool {
        if let Some(e) = self.flows.get_mut(k) {
            e.state = FlowState::Closing;
            true
        } else {
            false
        }
    }

    /// 移除 Closing 流与超时流，返回移除数量。
    pub fn expire(&mut self, now: Instant) -> usize {
        let before = self.flows.len();
        self.flows.retain(|_, e| {
            e.state != FlowState::Closing && now.duration_since(e.last_seen) < self.idle_timeout
        });
        before - self.flows.len()
    }
}

/// 测试用：手工构造 IPv4 包（无校验和，仅表测试用；4 字节伪头携带 sport/dport）。
pub fn build_ip_packet(
    proto: u8,
    src: Ipv4Addr,
    dst: Ipv4Addr,
    sport: u16,
    dport: u16,
    payload: &[u8],
) -> Vec<u8> {
    let ihl = 20u16;
    let l4 = 4u16;
    let total = ihl + l4 + payload.len() as u16;
    let mut p = Vec::with_capacity(total as usize);
    p.push(0x45);
    p.push(0);
    p.extend_from_slice(&total.to_be_bytes());
    p.extend_from_slice(&[0, 0]); // id (2B)
    p.extend_from_slice(&[0, 0]); // flags/frag (2B)
    p.push(64); // ttl
    p.push(proto);
    p.extend_from_slice(&[0, 0]); // checksum
    p.extend_from_slice(&src.octets());
    p.extend_from_slice(&dst.octets());
    p.extend_from_slice(&sport.to_be_bytes());
    p.extend_from_slice(&dport.to_be_bytes());
    p.extend_from_slice(payload);
    p
}

#[cfg(test)]
mod tests {
    use super::*;

    fn key(sport: u16, dport: u16) -> FlowKey {
        FlowKey {
            proto: 6,
            src: Ipv4Addr::new(10, 91, 17, 175),
            sport,
            dst: Ipv4Addr::new(10, 25, 64, 6),
            dport,
        }
    }

    #[test]
    fn flow_lifecycle() {
        let mut t = SessionTable::with_defaults();
        let k = key(5000, 80);
        let now = Instant::now();
        let (created, _) = t.observe(k, 0, now); // SYN
        assert!(created);
        assert_eq!(t.get(&k).unwrap().state, FlowState::New);
        let (created, _) = t.observe(k, 100, now + Duration::from_millis(10));
        assert!(!created);
        assert_eq!(t.get(&k).unwrap().state, FlowState::Established);
        assert_eq!(t.get(&k).unwrap().bytes, 100);

        t.close(&k);
        assert_eq!(t.expire(now + Duration::from_millis(20)), 1);
        assert!(t.is_empty());
    }

    #[test]
    fn idle_timeout_expires() {
        let mut t = SessionTable::new(Duration::from_secs(10), 100);
        let now = Instant::now();
        t.observe(key(1, 80), 0, now);
        t.observe(key(2, 80), 0, now);
        // 一个流仍在活动
        t.observe(key(1, 80), 0, now + Duration::from_secs(5));
        let removed = t.expire(now + Duration::from_secs(11));
        assert_eq!(removed, 1); // 只老化 key(2,80)
        assert_eq!(t.len(), 1);
    }

    #[test]
    fn capacity_rejects_when_full() {
        let mut t = SessionTable::new(Duration::from_secs(10), 2);
        let now = Instant::now();
        t.observe(key(1, 80), 0, now);
        t.observe(key(2, 80), 0, now);
        let (created, rejected) = t.observe(key(3, 80), 0, now);
        assert!(!created);
        assert!(rejected);
        assert_eq!(t.len(), 2);
    }

    #[test]
    fn key_from_packet_roundtrip() {
        let k = key(52341, 443);
        let pkt = build_ip_packet(6, k.src, k.dst, k.sport, k.dport, b"hello");
        assert_eq!(FlowKey::key_from_packet(&pkt), Some(k));
        assert_eq!(FlowKey::payload_len_from_packet(&pkt), Some(5));
        // 非 IP 包
        assert_eq!(FlowKey::key_from_packet(&[1, 2, 3]), None);
        // ICMP 不支持
        let icmp = build_ip_packet(1, k.src, k.dst, 0, 0, &[]);
        assert_eq!(FlowKey::key_from_packet(&icmp), None);
    }

    #[test]
    fn reverse_flow() {
        let k = key(5000, 443);
        let r = k.reverse();
        assert_eq!(r.src, k.dst);
        assert_eq!(r.sport, k.dport);
        assert_eq!(r.reverse(), k);
    }
}
