//! ndjson 行协议编解码：一行一个 JSON 消息。

use crate::{IpcError, Request, Response};
use serde::{Deserialize, Serialize};
use tokio::io::{AsyncBufRead, AsyncBufReadExt, AsyncWrite, AsyncWriteExt};

pub async fn send<T: Serialize, W: AsyncWrite + Unpin>(msg: &T, w: &mut W) -> Result<(), IpcError> {
    let mut line = serde_json::to_string(msg)?;
    line.push('\n');
    w.write_all(line.as_bytes()).await?;
    w.flush().await?;
    Ok(())
}

/// 接收一行 JSON。`R` 必须是**持久** BufReader（跨调用保留缓冲）：
/// 一次 poll_read 可能带回多行（应答与推送挤在同一 TCP 段），若每次
/// 调用临时包一层 BufReader，未消费的行会随临时缓冲一起丢失。
pub async fn recv<T: for<'de> Deserialize<'de>, R: AsyncBufRead + Unpin>(
    r: &mut R,
) -> Result<T, IpcError> {
    let mut line = String::new();
    let n = r.read_line(&mut line).await?;
    if n == 0 {
        return Err(IpcError::Closed);
    }
    Ok(serde_json::from_str(line.trim())?)
}

pub async fn send_request<W: AsyncWrite + Unpin>(req: &Request, w: &mut W) -> Result<(), IpcError> {
    send(req, w).await
}

pub async fn recv_request<R: AsyncBufRead + Unpin>(r: &mut R) -> Result<Request, IpcError> {
    recv(r).await
}

pub async fn send_response<W: AsyncWrite + Unpin>(
    res: &Response,
    w: &mut W,
) -> Result<(), IpcError> {
    send(res, w).await
}

pub async fn recv_response<R: AsyncBufRead + Unpin>(r: &mut R) -> Result<Response, IpcError> {
    recv(r).await
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::status::StatusSnapshot;
    use tokio::io::DuplexStream;

    async fn duplex_pair() -> (
        tokio::io::BufReader<DuplexStream>,
        tokio::io::BufReader<DuplexStream>,
    ) {
        let (a, b) = tokio::io::duplex(4096);
        (tokio::io::BufReader::new(a), tokio::io::BufReader::new(b))
    }

    #[tokio::test]
    async fn request_roundtrip() {
        let (mut a, mut b) = duplex_pair().await;
        let req = Request::Start {
            profile_id: "p1".into(),
        };
        send_request(&req, &mut a).await.unwrap();
        let got = recv_request(&mut b).await.unwrap();
        assert_eq!(got, req);
    }

    #[tokio::test]
    async fn response_roundtrip() {
        let (mut a, mut b) = duplex_pair().await;
        let res = Response::Status {
            status: StatusSnapshot {
                state: "connected".into(),
                rtt_ms: Some(42),
                server_ip: Some("10.0.0.1".into()),
                client_ip: None,
            },
        };
        send_response(&res, &mut a).await.unwrap();
        let got = recv_response(&mut b).await.unwrap();
        assert_eq!(got, res);
    }

    #[tokio::test]
    async fn closed_stream_yields_closed() {
        let (_a, mut b) = duplex_pair().await;
        drop(_a);
        let err = recv_request(&mut b).await.unwrap_err();
        assert!(matches!(err, IpcError::Closed));
    }

    /// 回归：两条消息挤在同一读段（应答 + 推送背靠背写出）时，
    /// 第二条曾被 recv 内部的临时 BufReader 吞掉。
    #[tokio::test]
    async fn two_messages_in_one_segment_are_both_delivered() {
        let (mut a, mut b) = duplex_pair().await;

        let first = serde_json::to_string(&Response::Ok).unwrap();
        let second = serde_json::to_string(&Response::Status {
            status: StatusSnapshot::disconnected(),
        })
        .unwrap();
        // 单次写出：接收端一次 poll_read 拿到两行
        a.write_all(format!("{first}\n{second}\n").as_bytes())
            .await
            .unwrap();
        a.flush().await.unwrap();

        assert_eq!(recv_response(&mut b).await.unwrap(), Response::Ok);
        assert_eq!(
            recv_response(&mut b).await.unwrap(),
            Response::Status {
                status: StatusSnapshot::disconnected()
            }
        );
    }
}
