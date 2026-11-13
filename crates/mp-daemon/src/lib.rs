//! mp-daemon 库部分：可测试的连接处理逻辑。
//! main.rs 仅负责启动。

use mp_core::session::{Credentials, TunnelType};
use mp_core::{Engine, VpnStatus};
use mp_ipc::codec::{recv_request, send_response};
use mp_ipc::status::StatusSnapshot;
use mp_ipc::{Request, Response};
use tokio::io::{AsyncRead, AsyncWrite};

fn status_snapshot(e: &Engine) -> StatusSnapshot {
    let mut snap = StatusSnapshot::disconnected();
    snap.state = match e.status() {
        VpnStatus::Disconnected => "disconnected",
        VpnStatus::Connecting => "connecting",
        VpnStatus::Connected => "connected",
        VpnStatus::Reconnecting => "reconnecting",
    }
    .into();
    if let Some(s) = e.session() {
        snap.server_ip = Some(s.server.clone());
    }
    snap
}

/// 处理单条请求；独立出来便于测试。
pub fn handle_request(engine: &mut Engine, req: &Request) -> Response {
    match req {
        Request::Start { profile_id } => {
            let creds = Credentials {
                username: profile_id.clone(), // TODO: 从 profile 存储加载
                password: String::new(),
                aaa_method: None,
                hwid: None,
            };
            match engine.start(&creds, TunnelType::Tcp) {
                Ok(_) => Response::Status { status: status_snapshot(engine) },
                Err(e) => Response::Error { message: e.to_string() },
            }
        }
        Request::Stop => match engine.stop() {
            Ok(_) => Response::Status { status: status_snapshot(engine) },
            Err(e) => Response::Error { message: e.to_string() },
        },
        Request::Status => Response::Status { status: status_snapshot(engine) },
        Request::GetSession => Response::Session {
            session_id: engine.session().map(|s| s.session_id.clone()),
        },
        Request::SetReconnect { enabled, max_attempts } => {
            engine.set_reconnect(*enabled, *max_attempts);
            Response::Ok
        }
        Request::ListWireGuard => Response::Ok, // TODO: WG 配置列表
    }
}

/// 在一条连接上循环处理请求直到对端关闭。
pub async fn handle_conn<S: AsyncRead + AsyncWrite + Unpin>(engine: &mut Engine, stream: &mut S) -> anyhow::Result<()> {
    use mp_ipc::IpcError;
    loop {
        let req = match recv_request(stream).await {
            Ok(r) => r,
            Err(IpcError::Closed) => return Ok(()),
            Err(e) => return Err(e.into()),
        };
        let resp = handle_request(engine, &req);
        send_response(&resp, stream).await?;
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use mp_ipc::codec::{recv_response, send_request};

    #[tokio::test]
    async fn full_request_cycle_over_duplex() {
        let (mut client, mut server) = tokio::io::duplex(4096);
        let mut engine = Engine::new();

        let srv = tokio::spawn(async move {
            handle_conn(&mut engine, &mut server).await.unwrap();
        });

        send_request(&Request::Status, &mut client).await.unwrap();
        let res = recv_response(&mut client).await.unwrap();
        assert!(matches!(res, Response::Status { .. }));

        send_request(&Request::Start { profile_id: "prof1".into() }, &mut client).await.unwrap();
        let res = recv_response(&mut client).await.unwrap();
        match res {
            Response::Status { status } => assert_eq!(status.state, "connected"),
            other => panic!("unexpected: {other:?}"),
        }

        send_request(&Request::GetSession, &mut client).await.unwrap();
        let res = recv_response(&mut client).await.unwrap();
        match res {
            Response::Session { session_id } => assert!(session_id.is_some()),
            other => panic!("unexpected: {other:?}"),
        }

        send_request(&Request::Stop, &mut client).await.unwrap();
        let res = recv_response(&mut client).await.unwrap();
        match res {
            Response::Status { status } => assert_eq!(status.state, "disconnected"),
            other => panic!("unexpected: {other:?}"),
        }

        drop(client); // 关闭连接，服务端循环退出
        srv.await.unwrap();
    }

    #[tokio::test]
    async fn error_response_on_bad_state() {
        let mut engine = Engine::new();
        let res = handle_request(&mut engine, &Request::Stop);
        match res {
            Response::Status { status } => assert_eq!(status.state, "disconnected"), // Disconnected 状态 Stop 幂等
            other => panic!("unexpected: {other:?}"),
        }

        // 未连接时模拟非法迁移：直接 GetSession 无 session
        let res = handle_request(&mut engine, &Request::GetSession);
        match res {
            Response::Session { session_id } => assert!(session_id.is_none()),
            other => panic!("unexpected: {other:?}"),
        }
    }
}
