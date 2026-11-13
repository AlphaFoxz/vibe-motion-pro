//! 隧道数据帧协议（占位设计 —— 字段布局待逆向确认后替换，集中在模块顶部常量区）。
//!
//! 布局（大端）：
//! ```text
//! +--------+---------+--------+--------+---------+
//! | magic  | version | type   | length | payload |
//! | u32    | u8      | u8     | u16    | len B   |
//! +--------+---------+--------+--------+---------+
//! ```
//!
//! TODO(逆向): 原版线索——vpnd 走 HTTPS `/vpntunnel`，vl3vpn.dll 有 udp_tunnel.c 与
//! keepalive；真实 magic/字段序/压缩等从 Ghidra 结果确认后改这里。

use thiserror::Error;

pub const MAGIC: u32 = 0x4D50_4652; // "MPFR" 占位
pub const VERSION: u8 = 1;
pub const MAX_PAYLOAD: usize = 65_535;
pub const HEADER_LEN: usize = 8; // magic(4) + version(1) + type(1) + length(2)

#[derive(Debug, Error, PartialEq)]
pub enum FrameError {
    #[error("bad magic: {0:#x}")]
    BadMagic(u32),
    #[error("unsupported version: {0}")]
    BadVersion(u8),
    #[error("unknown frame type: {0}")]
    BadType(u8),
    #[error("payload too large: {0}")]
    TooLarge(usize),
    #[error("incomplete frame: have {0} bytes, need {1}")]
    Incomplete(usize, usize),
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u8)]
pub enum FrameType {
    Data = 1,
    KeepAlive = 2,
    ControlRekey = 3,
    Close = 4,
}

impl FrameType {
    fn from_u8(v: u8) -> Result<Self, FrameError> {
        match v {
            1 => Ok(FrameType::Data),
            2 => Ok(FrameType::KeepAlive),
            3 => Ok(FrameType::ControlRekey),
            4 => Ok(FrameType::Close),
            _ => Err(FrameError::BadType(v)),
        }
    }
}

#[derive(Debug, Clone, PartialEq)]
pub struct Frame {
    pub ftype: FrameType,
    pub payload: Vec<u8>,
}

impl Frame {
    pub fn new(ftype: FrameType, payload: impl Into<Vec<u8>>) -> Result<Self, FrameError> {
        let payload = payload.into();
        if payload.len() > MAX_PAYLOAD {
            return Err(FrameError::TooLarge(payload.len()));
        }
        Ok(Self { ftype, payload })
    }

    pub fn encode(&self) -> Vec<u8> {
        let mut buf = Vec::with_capacity(HEADER_LEN + self.payload.len());
        buf.extend_from_slice(&MAGIC.to_be_bytes());
        buf.push(VERSION);
        buf.push(self.ftype as u8);
        buf.extend_from_slice(&(self.payload.len() as u16).to_be_bytes());
        buf.extend_from_slice(&self.payload);
        buf
    }

    /// 尝试从缓冲头部解码一帧；返回 (frame, consumed)。缓冲不足完整帧时返回 Incomplete。
    pub fn decode(buf: &[u8]) -> Result<(Frame, usize), FrameError> {
        if buf.len() < HEADER_LEN {
            return Err(FrameError::Incomplete(buf.len(), HEADER_LEN));
        }
        let magic = u32::from_be_bytes([buf[0], buf[1], buf[2], buf[3]]);
        if magic != MAGIC {
            return Err(FrameError::BadMagic(magic));
        }
        if buf[4] != VERSION {
            return Err(FrameError::BadVersion(buf[4]));
        }
        let ftype = FrameType::from_u8(buf[5])?;
        let len = u16::from_be_bytes([buf[6], buf[7]]) as usize;
        let total = HEADER_LEN + len;
        if buf.len() < total {
            return Err(FrameError::Incomplete(buf.len(), total));
        }
        let frame = Frame {
            ftype,
            payload: buf[HEADER_LEN..total].to_vec(),
        };
        Ok((frame, total))
    }
}

/// 递增式解码器：流式读取时逐字节喂入。
pub struct Decoder {
    buf: Vec<u8>,
}

impl Decoder {
    pub fn new() -> Self {
        Self {
            buf: Vec::with_capacity(HEADER_LEN + 1500),
        }
    }

    pub fn feed(&mut self, bytes: &[u8]) {
        self.buf.extend_from_slice(bytes);
    }

    pub fn next_frame(&mut self) -> Result<Option<Frame>, FrameError> {
        match Frame::decode(&self.buf) {
            Ok((f, used)) => {
                self.buf.drain(..used);
                Ok(Some(f))
            }
            Err(FrameError::Incomplete(_, _)) => Ok(None),
            Err(e) => Err(e),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn encode_decode_roundtrip() {
        let f = Frame::new(FrameType::Data, b"hello world").unwrap();
        let bytes = f.encode();
        assert_eq!(bytes.len(), HEADER_LEN + 11);
        let (got, used) = Frame::decode(&bytes).unwrap();
        assert_eq!(used, bytes.len());
        assert_eq!(got, f);
    }

    #[test]
    fn empty_keepalive() {
        let f = Frame::new(FrameType::KeepAlive, Vec::<u8>::new()).unwrap();
        let (got, _) = Frame::decode(&f.encode()).unwrap();
        assert_eq!(got.ftype, FrameType::KeepAlive);
        assert!(got.payload.is_empty());
    }

    #[test]
    fn rejects_bad_magic() {
        let mut bytes = Frame::new(FrameType::Data, b"x").unwrap().encode();
        bytes[0] ^= 0xFF;
        assert!(matches!(
            Frame::decode(&bytes),
            Err(FrameError::BadMagic(_))
        ));
    }

    #[test]
    fn rejects_bad_version() {
        let mut bytes = Frame::new(FrameType::Data, b"x").unwrap().encode();
        bytes[4] = 99;
        assert!(matches!(
            Frame::decode(&bytes),
            Err(FrameError::BadVersion(99))
        ));
    }

    #[test]
    fn rejects_bad_type() {
        let mut bytes = Frame::new(FrameType::Data, b"x").unwrap().encode();
        bytes[5] = 0x7F;
        assert!(matches!(
            Frame::decode(&bytes),
            Err(FrameError::BadType(0x7F))
        ));
    }

    #[test]
    fn incomplete_then_complete() {
        let bytes = Frame::new(FrameType::Data, b"payload").unwrap().encode();
        assert!(matches!(
            Frame::decode(&bytes[..4]),
            Err(FrameError::Incomplete(4, 8))
        ));
        assert!(matches!(
            Frame::decode(&bytes[..9]),
            Err(FrameError::Incomplete(9, 15))
        ));
        let (f, _) = Frame::decode(&bytes).unwrap();
        assert_eq!(f.payload, b"payload");
    }

    #[test]
    fn payload_too_large() {
        assert_eq!(
            Frame::new(FrameType::Data, vec![0u8; MAX_PAYLOAD + 1]).unwrap_err(),
            FrameError::TooLarge(MAX_PAYLOAD + 1)
        );
    }

    #[test]
    fn stream_decoder_handles_partial_and_multiple() {
        let f1 = Frame::new(FrameType::Data, b"aaa").unwrap();
        let f2 = Frame::new(FrameType::KeepAlive, Vec::<u8>::new()).unwrap();
        let f3 = Frame::new(FrameType::Close, b"bye").unwrap();
        let mut all = Vec::new();
        all.extend_from_slice(&f1.encode());
        all.extend_from_slice(&f2.encode());
        all.extend_from_slice(&f3.encode());

        let mut dec = Decoder::new();
        // 喂入截断的前 5 字节
        dec.feed(&all[..5]);
        assert!(dec.next_frame().unwrap().is_none());
        // 一次喂入剩余全部
        dec.feed(&all[5..]);
        assert_eq!(dec.next_frame().unwrap(), Some(f1));
        assert_eq!(dec.next_frame().unwrap(), Some(f2));
        assert_eq!(dec.next_frame().unwrap(), Some(f3));
        assert!(dec.next_frame().unwrap().is_none());
    }
}
