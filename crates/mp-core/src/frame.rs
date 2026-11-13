//! 隧道数据面协议（依据 Ghidra 逆向 vl3vpn.dll 的实测结论，见 docs/ghidra-tasks.md T1-T3）。
//!
//! TLS（或 DTLS/明文 UDP）承载的是**背靠背的裸 IPv4/IPv6 包流，无任何额外封装头**：
//! - IPv4：首半字节 0x4，总长在 +2（BE u16）
//! - IPv6：首半字节 0x6，载荷长在 +4（BE u16），总长 = 载荷长 + 40
//! - keepalive = 伪 IPv4 包：`45 00 00 14`，TTL=0、协议号=255（0xff）、总长 20：
//!   ```text
//!   +0  45 00 00 14        版本4+IHL5 / TOS=0 / 总长 BE=20
//!   +4  00 00 00 00        id/flags/frag offset = 0
//!   +8  00 ff 00 00        TTL=0 / 协议=255 / 校验和=0
//!   +12 00 01              计数 = 1（BE）
//!   +14 xx xx xx xx        当日毫秒时间戳（秒×1000+ms）
//!   +18 xx xx              隧道类型（0=TCP, 2=WG）
//!   ```
//!
//! 原版读循环（FUN_10063130，l3vpn.c 0x35b）按协议号 0xff 分发 keepalive，
//! 其余作为 IP 包写入虚拟网卡；写路径（FUN_10063650）直接把网卡读出的
//! IP 包 SSL_write / sendto，无封装。

use thiserror::Error;

/// keepalive 帧总长（原版 SSL_write 长度 0x14）。
pub const KEEPALIVE_LEN: usize = 20;
/// 读缓冲上限（原版 0x10000）。
pub const MAX_BUFFER: usize = 65_536;
/// 单个 IP 包最大长度（IPv4 总长字段 u16 上限）。
pub const MAX_PACKET: usize = 65_535;

/// keepalive 载荷中的隧道类型（帧 +18 字段）。
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum TunnelKind {
    Tcp = 0,
    Wg = 2,
}

/// 20 字节伪 IPv4 keepalive 帧。
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct KeepAlive {
    /// 帧计数（原版恒为 1，BE u16 @ +12）。
    pub count: u16,
    /// 当日毫秒时间戳（@ +14，发送端 GetLocalTime 换算）。
    pub timestamp_ms: u32,
    /// 隧道类型（@ +18）。
    pub kind: TunnelKind,
}

impl KeepAlive {
    pub fn new(timestamp_ms: u32, kind: TunnelKind) -> Self {
        Self {
            count: 1,
            timestamp_ms,
            kind,
        }
    }

    pub fn encode(&self) -> [u8; KEEPALIVE_LEN] {
        let mut b = [0u8; KEEPALIVE_LEN];
        b[0] = 0x45; // 版本 4 + IHL 5
        b[1] = 0x00; // TOS
        b[2..4].copy_from_slice(&(KEEPALIVE_LEN as u16).to_be_bytes()); // 总长 = 20
        b[8] = 0x00; // TTL = 0
        b[9] = 0xff; // 协议号 255 —— keepalive 分发标记
        b[10..12].copy_from_slice(&[0, 0]); // 校验和 = 0
        b[12..14].copy_from_slice(&self.count.to_be_bytes());
        b[14..18].copy_from_slice(&self.timestamp_ms.to_be_bytes());
        b[18..20].copy_from_slice(&(self.kind as u16).to_be_bytes());
        b
    }

    /// 从 20 字节 keepalive 帧解析（不校验前 12 字节的固定值之外的字段语义）。
    pub fn decode(buf: &[u8]) -> Result<Self, FrameError> {
        if buf.len() < KEEPALIVE_LEN {
            return Err(FrameError::Incomplete(buf.len(), KEEPALIVE_LEN));
        }
        if !is_keepalive(buf) {
            return Err(FrameError::NotKeepAlive);
        }
        Ok(Self {
            count: u16::from_be_bytes([buf[12], buf[13]]),
            timestamp_ms: u32::from_be_bytes([buf[14], buf[15], buf[16], buf[17]]),
            kind: match u16::from_be_bytes([buf[18], buf[19]]) {
                0 => TunnelKind::Tcp,
                _ => TunnelKind::Wg,
            },
        })
    }
}

/// 判断一个 IPv4 包是否为 keepalive（协议号 255；原版 FUN_10063130 在读循环分发）。
pub fn is_keepalive(pkt: &[u8]) -> bool {
    pkt.len() >= KEEPALIVE_LEN && pkt[0] >> 4 == 4 && pkt[9] == 0xff
}

/// 计算裸 IP 包总长；返回 None 表示头部不完整或版本无法识别。
fn packet_len(buf: &[u8]) -> Option<usize> {
    if buf.len() < 4 {
        return None;
    }
    match buf[0] >> 4 {
        4 => Some(u16::from_be_bytes([buf[2], buf[3]]) as usize),
        6 => {
            if buf.len() < 6 {
                return None;
            }
            Some(u16::from_be_bytes([buf[4], buf[5]]) as usize + 40)
        }
        _ => None,
    }
}

#[derive(Debug, Error, PartialEq)]
pub enum FrameError {
    #[error("unknown ip version: {0:#x}")]
    BadVersion(u8),
    #[error("declared packet length {0} exceeds buffer limit {1}")]
    TooLarge(usize, usize),
    #[error("declared packet length is zero")]
    ZeroLength,
    #[error("incomplete: have {0} bytes, need {1}")]
    Incomplete(usize, usize),
    #[error("not a keepalive frame")]
    NotKeepAlive,
}

/// 流中解析出的条目。
#[derive(Debug, Clone, PartialEq)]
pub enum StreamItem {
    /// 内层 IP 包（原样写入虚拟网卡）。
    IpPacket(Vec<u8>),
    /// keepalive（伪 IPv4，协议号 255）。
    KeepAlive(KeepAlive),
}

/// 递增式「裸 IP 流」切包器：feed 字节流，逐个吐出 IP 包 / keepalive。
///
/// 对齐原版 FUN_10063130 / FUN_10062c70 的行为：
/// 半包累积、一读多包、残余保留、keepalive 按协议号 255 分发。
#[derive(Debug)]
pub struct PacketStream {
    buf: Vec<u8>,
}

impl PacketStream {
    pub fn new() -> Self {
        Self {
            buf: Vec::with_capacity(MAX_BUFFER),
        }
    }

    pub fn feed(&mut self, bytes: &[u8]) {
        self.buf.extend_from_slice(bytes);
    }

    /// 缓冲中尚未消费的字节数。
    pub fn pending(&self) -> usize {
        self.buf.len()
    }

    /// 取出下一个完整条目；None = 当前缓冲不足以构成一个完整包。
    pub fn next_item(&mut self) -> Result<Option<StreamItem>, FrameError> {
        if self.buf.len() < 4 {
            return Ok(None);
        }
        let version = self.buf[0] >> 4;
        if version != 4 && version != 6 {
            return Err(FrameError::BadVersion(self.buf[0]));
        }
        if is_keepalive(&self.buf) {
            let ka = KeepAlive::decode(&self.buf)?;
            self.buf.drain(..KEEPALIVE_LEN);
            return Ok(Some(StreamItem::KeepAlive(ka)));
        }
        let len = packet_len(&self.buf).unwrap_or(0);
        if len == 0 {
            return Err(FrameError::ZeroLength);
        }
        if len > MAX_PACKET {
            return Err(FrameError::TooLarge(len, MAX_PACKET));
        }
        if self.buf.len() < len {
            // 包体不足 —— 保留残余等待后续 feed
            return Ok(None);
        }
        let pkt: Vec<u8> = self.buf.drain(..len).collect();
        Ok(Some(StreamItem::IpPacket(pkt)))
    }

    /// 消费整个缓冲，尽量多地产出条目。
    pub fn drain(&mut self, out: &mut Vec<StreamItem>) -> Result<(), FrameError> {
        loop {
            match self.next_item()? {
                Some(item) => out.push(item),
                None => return Ok(()),
            }
        }
    }
}

impl Default for PacketStream {
    fn default() -> Self {
        Self::new()
    }
}

/// 构造一个最小 IPv4 包（仅用于测试/自检）。
#[cfg(test)]
pub(crate) fn test_ipv4(total_len: u16, proto: u8) -> Vec<u8> {
    let mut p = vec![0u8; total_len as usize];
    p[0] = 0x45;
    p[2..4].copy_from_slice(&total_len.to_be_bytes());
    p[9] = proto;
    p
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn keepalive_roundtrip() {
        let ka = KeepAlive::new(123_456, TunnelKind::Tcp);
        let b = ka.encode();
        assert_eq!(b.len(), 20);
        assert_eq!(&b[..4], &[0x45, 0, 0, 0x14]);
        assert_eq!(b[9], 0xff); // 协议号 255
        assert_eq!(KeepAlive::decode(&b).unwrap(), ka);
    }

    #[test]
    fn keepalive_wg_kind() {
        let ka = KeepAlive::new(0, TunnelKind::Wg);
        let b = ka.encode();
        assert_eq!(b[18..20], [0, 2]);
        assert_eq!(KeepAlive::decode(&b).unwrap().kind, TunnelKind::Wg);
    }

    #[test]
    fn keepalive_incomplete() {
        let b = KeepAlive::new(1, TunnelKind::Tcp).encode();
        assert!(matches!(
            KeepAlive::decode(&b[..19]),
            Err(FrameError::Incomplete(19, 20))
        ));
    }

    #[test]
    fn demux_single_ipv4() {
        let pkt = test_ipv4(40, 6);
        let mut s = PacketStream::new();
        s.feed(&pkt);
        let items = {
            let mut v = vec![];
            s.drain(&mut v).unwrap();
            v
        };
        assert_eq!(items, vec![StreamItem::IpPacket(pkt)]);
        assert_eq!(s.pending(), 0);
    }

    #[test]
    fn demux_multiple_and_partial() {
        let p1 = test_ipv4(28, 17);
        let p2 = test_ipv4(64, 6);
        let mut stream = Vec::new();
        stream.extend_from_slice(&p1);
        stream.extend_from_slice(&p2);

        let mut s = PacketStream::new();
        // 喂入前半（跨包边界截断）
        s.feed(&stream[..30]);
        let mut v = vec![];
        s.drain(&mut v).unwrap();
        assert_eq!(v.len(), 1); // 只有 p1 完整
        assert_eq!(v[0], StreamItem::IpPacket(p1.clone()));
        assert_eq!(s.pending(), 2); // p2 的前 2 字节残留
                                 // 补齐剩余
        s.feed(&stream[30..]);
        let mut v2 = vec![];
        s.drain(&mut v2).unwrap();
        assert_eq!(v2, vec![StreamItem::IpPacket(p2)]);
    }

    #[test]
    fn demux_ipv6() {
        // IPv6：版本 6，载荷长 8 → 总长 48
        let mut p = vec![0u8; 48];
        p[0] = 0x60;
        p[4..6].copy_from_slice(&8u16.to_be_bytes());
        let mut s = PacketStream::new();
        s.feed(&p[..10]); // 头都不够 → None
        assert!(s.next_item().unwrap().is_none());
        s.feed(&p[10..]);
        assert_eq!(s.next_item().unwrap(), Some(StreamItem::IpPacket(p)));
    }

    #[test]
    fn keepalive_dispatched_not_written_as_ip() {
        let mut stream = KeepAlive::new(999, TunnelKind::Tcp).encode().to_vec();
        stream.extend_from_slice(&test_ipv4(20, 6));
        let mut s = PacketStream::new();
        s.feed(&stream);
        let mut v = vec![];
        s.drain(&mut v).unwrap();
        assert_eq!(v.len(), 2);
        assert!(matches!(v[0], StreamItem::KeepAlive(_)));
        assert!(matches!(v[1], StreamItem::IpPacket(_)));
    }

    #[test]
    fn rejects_unknown_version() {
        let mut s = PacketStream::new();
        s.feed(&[0x30, 0, 0, 4]);
        assert!(matches!(
            s.next_item(),
            Err(FrameError::BadVersion(0x30))
        ));
    }

    #[test]
    fn rejects_zero_length() {
        let mut s = PacketStream::new();
        s.feed(&[0x45, 0, 0, 0]);
        assert!(matches!(s.next_item(), Err(FrameError::ZeroLength)));
    }

    #[test]
    fn partial_header_is_none() {
        let mut s = PacketStream::new();
        s.feed(&[0x45, 0]);
        assert!(s.next_item().unwrap().is_none());
    }
}
