//! 传输抽象。
//! - `TcpTransport`: TCP loopback，开发/测试用，也可用于本地回环（127.0.0.1:port）
//! - 生产环境平台本地管道（Windows named pipe / Unix socket）在 platform 模块按 cfg 提供，
//!   协议层（ndjson codec）完全复用。

use crate::IpcError;
use tokio::net::{TcpListener, TcpStream};

pub struct TcpServer {
    listener: TcpListener,
}

impl TcpServer {
    pub async fn bind(addr: &str) -> Result<Self, IpcError> {
        Ok(Self {
            listener: TcpListener::bind(addr).await?,
        })
    }

    pub fn local_addr(&self) -> Result<std::net::SocketAddr, IpcError> {
        Ok(self.listener.local_addr()?)
    }

    /// 接受一个连接；之后用 codec 在流上收发消息。
    pub async fn accept(&self) -> Result<TcpStream, IpcError> {
        let (stream, _) = self.listener.accept().await?;
        Ok(stream)
    }
}

pub async fn tcp_connect(addr: &str) -> Result<TcpStream, IpcError> {
    Ok(TcpStream::connect(addr).await?)
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::codec::{recv_request, recv_response, send_request, send_response};
    use crate::{Request, Response};

    #[tokio::test]
    async fn tcp_end_to_end() {
        let server = TcpServer::bind("127.0.0.1:0").await.unwrap();
        let addr = server.local_addr().unwrap().to_string();

        let client_task = tokio::spawn(async move {
            let mut stream = tcp_connect(&addr).await.unwrap();
            send_request(&Request::Status, &mut stream).await.unwrap();
            let res = recv_response(&mut stream).await.unwrap();
            res
        });

        let mut conn = server.accept().await.unwrap();
        let req = recv_request(&mut conn).await.unwrap();
        assert_eq!(req, Request::Status);
        send_response(&Response::Ok, &mut conn).await.unwrap();

        let res = client_task.await.unwrap();
        assert_eq!(res, Response::Ok);
    }
}
