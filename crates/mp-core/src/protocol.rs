//! 协议占位模块：所有待逆向确认的常量与报文格式集中在此。
//! 逆向就绪后只改本模块（见 docs/protocol-clues.md 与 docs/plan-phase2.md）。

/// 握手端点（证据：vl3vpn.dll 字符串 `GET %s/vpntunnel HTTP/1.1`）。
pub const VPNTUNNEL_PATH: &str = "/vpntunnel";

/// TODO(逆向):
/// - 请求头字段（session_id / sslproto / tunneltype / HWID 如何编码）
/// - 响应格式与错误码
/// - cookie 会话处理（原版 CHttpHttpRequestCookie）
/// - UDP/DTLS 隧道建立流程（udp_tunnel.c / DTLS SPEED TUNNEL）

pub struct HandshakePlaceholder;

impl HandshakePlaceholder {
    /// 占位：构造 /vpntunnel 请求行（真实字段待逆向）。
    pub fn request_line(host: &str) -> String {
        format!("GET {VPNTUNNEL_PATH} HTTP/1.1\r\nHost: {host}\r\n\r\n")
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn request_line_format() {
        let s = HandshakePlaceholder::request_line("vpn.example.com");
        assert!(s.starts_with("GET /vpntunnel HTTP/1.1\r\n"));
        assert!(s.contains("Host: vpn.example.com"));
    }
}
