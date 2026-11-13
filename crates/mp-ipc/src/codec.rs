//! ndjson 行协议编解码：一行一个 JSON 消息。

use crate::{IpcError, Request, Response};
use serde::{Deserialize, Serialize};
use tokio::io::{AsyncBufReadExt, AsyncRead, AsyncWrite, AsyncWriteExt, BufReader};

pub async fn send<T: Serialize, W: AsyncWrite + Unpin>(msg: &T, w: &mut W) -> Result<(), IpcError> {
    let mut line = serde_json::to_string(msg)?;
    line.push('\n');
    w.write_all(line.as_bytes()).await?;
    w.flush().await?;
    Ok(())
}

pub async fn recv<T: for<'de> Deserialize<'de>, R: AsyncRead + Unpin>(
    r: &mut R,
) -> Result<T, IpcError> {
    let mut line = String::new();
    let n = BufReader::new(r).read_line(&mut line).await?;
    if n == 0 {
        return Err(IpcError::Closed);
    }
    Ok(serde_json::from_str(line.trim())?)
}

pub async fn send_request<W: AsyncWrite + Unpin>(req: &Request, w: &mut W) -> Result<(), IpcError> {
    send(req, w).await
}

pub async fn recv_request<R: AsyncRead + Unpin>(r: &mut R) -> Result<Request, IpcError> {
    recv(r).await
}

pub async fn send_response<W: AsyncWrite + Unpin>(
    res: &Response,
    w: &mut W,
) -> Result<(), IpcError> {
    send(res, w).await
}

pub async fn recv_response<R: AsyncRead + Unpin>(r: &mut R) -> Result<Response, IpcError> {
    recv(r).await
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::status::StatusSnapshot;
    use tokio::io::DuplexStream;

    async fn duplex_pair() -> (DuplexStream, DuplexStream) {
        tokio::io::duplex(4096)
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
        let (a, mut b) = duplex_pair().await;
        drop(a);
        let err = recv_request(&mut b).await.unwrap_err();
        assert!(matches!(err, IpcError::Closed));
    }
}
