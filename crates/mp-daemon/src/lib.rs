//! mp-daemon 库部分：可测试的连接处理逻辑。
//! main.rs 仅负责启动。

use mp_core::profile::{Profile, ProfileError, ProfileStore};
use mp_core::session::{Credentials, TunnelType};
use mp_core::{Engine, VpnStatus};

pub mod netloop;
use mp_ipc::codec::{recv_request, send_response};
use mp_ipc::profile::ProfileMsg;
use mp_ipc::status::StatusSnapshot;
use mp_ipc::{Request, Response};
use tokio::io::{AsyncRead, AsyncWrite};
use tokio::sync::broadcast;

fn status_snapshot(e: &Engine) -> StatusSnapshot {
    let mut snap = StatusSnapshot::disconnected();
    snap.state = match e.status() {
        VpnStatus::Disconnected | VpnStatus::ConnectFailed | VpnStatus::ReconnectFailed => {
            "disconnected"
        }
        VpnStatus::Disconnecting => "disconnecting",
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

fn to_msg(p: &Profile) -> ProfileMsg {
    ProfileMsg {
        id: p.id.clone(),
        name: p.name.clone(),
        host: p.host.clone(),
        port: p.port,
        tunnel_type: format!("{:?}", p.tunnel_type).to_lowercase(),
        autoconnect: p.autoconnect,
    }
}

fn from_msg(m: &ProfileMsg) -> Profile {
    let mut p = Profile::new(m.id.clone(), m.name.clone(), m.host.clone());
    p.port = m.port;
    p.tunnel_type = match m.tunnel_type.as_str() {
        "udp" => TunnelType::Udp,
        "dtls" => TunnelType::Dtls,
        "wireguard" => TunnelType::WireGuard,
        _ => TunnelType::Tcp,
    };
    p.autoconnect = m.autoconnect;
    p
}

/// 守护进程共享状态：引擎 + profile 存储 + 状态广播。
pub struct DaemonState {
    pub engine: Engine,
    pub profiles: ProfileStore,
    /// 状态变更广播（对齐原版 vpnd 1s 周期 "send message to clients"）
    pub status_tx: broadcast::Sender<StatusSnapshot>,
}

impl DaemonState {
    pub fn new(profiles: ProfileStore) -> Self {
        let (status_tx, _) = broadcast::channel(16);
        Self { engine: Engine::new(), profiles, status_tx }
    }

    /// 每 1 秒调用一次（main.rs 里的轮询任务）：检测状态变化并广播。
    /// 返回 Some(快照) 表示发生了变化（调用方负责推送到已连接客户端），None 表示无变化。
    pub fn tick_broadcast(&mut self, last: &mut Option<StatusSnapshot>) -> Option<StatusSnapshot> {
        let snap = status_snapshot(&self.engine);
        if last.as_ref() != Some(&snap) {
            let _ = self.status_tx.send(snap.clone());
            *last = Some(snap.clone());
            Some(snap)
        } else {
            None
        }
    }
}

/// 处理单条请求；独立出来便于测试。
pub fn handle_request(state: &mut DaemonState, req: &Request) -> Response {
    let engine = &mut state.engine;
    match req {
        Request::Start { profile_id } => {
            // 按 profile 查表；未找到则回退为临时凭据（骨架模式）
            let (host, tunnel) = match state.profiles.get(profile_id) {
                Ok(p) => (p.host.clone(), p.tunnel_type),
                Err(_) => (String::new(), TunnelType::Tcp),
            };
            let creds = Credentials {
                username: profile_id.clone(),
                password: String::new(),
                aaa_method: None,
                hwid: None,
            };
            match engine.start(&creds, tunnel) {
                Ok(_) => {
                    if let Some(s) = engine.session_mut() {
                        s.server = host;
                    }
                    Response::Status { status: status_snapshot(engine) }
                }
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
        Request::ListProfiles => Response::Profiles {
            profiles: state.profiles.list().iter().map(|p| to_msg(p)).collect(),
        },
        Request::AddProfile { profile } => match state.profiles.add_or_update(from_msg(profile)) {
            Ok(()) => Response::Profiles {
                profiles: state.profiles.list().iter().map(|p| to_msg(p)).collect(),
            },
            Err(e) => Response::Error { message: e.to_string() },
        },
        Request::RemoveProfile { profile_id } => match state.profiles.remove(profile_id) {
            Ok(()) => Response::Profiles {
                profiles: state.profiles.list().iter().map(|p| to_msg(p)).collect(),
            },
            Err(e) => Response::Error { message: e.to_string() },
        },
    }
}

/// 在一条连接上循环处理请求直到对端关闭；
/// 同时 select 广播通道，向客户端推送 StatusUpdate（对齐原版 cmd 1 推送）。
pub async fn handle_conn<S: AsyncRead + AsyncWrite + Unpin>(
    state: &mut DaemonState,
    stream: &mut S,
) -> anyhow::Result<()> {
    use mp_ipc::IpcError;
    let mut rx = state.status_tx.subscribe();
    // 持久 BufReader：跨 select 迭代保留缓冲字节，避免丢包卡死
    let mut stream = tokio::io::BufReader::new(stream);
    loop {
        tokio::select! {
            req = recv_request(&mut stream) => {
                let req = match req {
                    Ok(r) => r,
                    Err(IpcError::Closed) => return Ok(()),
                    Err(e) => return Err(e.into()),
                };
                let resp = handle_request(state, &req);
                send_response(&resp, &mut stream).await?;
            }
            update = rx.recv() => {
                if let Ok(status) = update {
                    send_response(&Response::StatusUpdate { status }, &mut stream).await?;
                }
            }
        }
    }
}

/// 1 秒周期轮询广播任务体（供 main spawn；独立可测）。
pub fn poll_interval_secs() -> u64 {
    mp_core::protocol::STATUS_POLL_INTERVAL_SECS
}


#[cfg(test)]
mod tests {
    use super::*;
    use mp_ipc::codec::{recv_response, send_request};

    fn state() -> DaemonState {
        let mut s = DaemonState::new(ProfileStore::new());
        let _ = s.profiles.add_or_update(Profile::new("prof1", "Office", "vpn.example.com"));
        s
    }

    #[tokio::test]
    async fn full_request_cycle_over_duplex() {
        let (client, mut server) = tokio::io::duplex(4096);
        let mut client = tokio::io::BufReader::new(client);
        let mut st = state();

        let srv = tokio::spawn(async move {
            handle_conn(&mut st, &mut server).await.unwrap();
        });

        // 普通请求往返
        send_request(&Request::Status, &mut client).await.unwrap();
        let res = recv_response(&mut client).await.unwrap();
        assert!(matches!(res, Response::Status { .. }));

        // Profile 查表连接
        send_request(&Request::Start { profile_id: "prof1".into() }, &mut client)
            .await
            .unwrap();
        let res = recv_response(&mut client).await.unwrap();
        match res {
            Response::Status { status } => {
                assert_eq!(status.state, "connected");
                assert_eq!(status.server_ip.as_deref(), Some("vpn.example.com"));
            }
            other => panic!("unexpected: {other:?}"),
        }

        send_request(&Request::GetSession, &mut client).await.unwrap();
        let res = recv_response(&mut client).await.unwrap();
        match res {
            Response::Session { session_id } => assert!(session_id.is_some()),
            other => panic!("unexpected: {other:?}"),
        }

        drop(client);
        srv.await.unwrap();
    }

    #[tokio::test]
    async fn status_broadcast_pushed_to_client() {
        let (client, mut server) = tokio::io::duplex(4096);
        let mut client = tokio::io::BufReader::new(client);
        let mut st = state();

        // 客户端任务：Start -> 收响应 -> 等 StatusUpdate 推送 -> 断开
        let client_flow = async {
            send_request(&Request::Start { profile_id: "prof1".into() }, &mut client)
                .await
                .unwrap();
            let res = recv_response(&mut client).await.unwrap();
            assert!(matches!(res, Response::Status { .. }));
            let res = recv_response(&mut client).await.unwrap();
            match res {
                Response::StatusUpdate { status } => assert_eq!(status.state, "connected"),
                other => panic!("unexpected: {other:?}"),
            }
            // 已无状态变化，不应再有推送
            assert!(tokio::time::timeout(
                std::time::Duration::from_millis(150),
                recv_response(&mut client)
            )
            .await
            .is_err());
            drop(client);
        };

        // 服务端：与 main.rs 同构的 select 循环（请求处理 + 周期 tick 广播）
        let server_flow = async {
            let mut server = tokio::io::BufReader::new(server);
            let mut last: Option<StatusSnapshot> = None;
            loop {
                tokio::select! {
                    req = recv_request(&mut server) => {
                        match req {
                            Ok(r) => {
                                let resp = handle_request(&mut st, &r);
                                send_response(&resp, &mut server).await.unwrap();
                            }
                            Err(_) => break, // 客户端断开
                        }
                    }
                    _ = tokio::time::sleep(std::time::Duration::from_millis(30)) => {
                        if let Some(snap) = st.tick_broadcast(&mut last) {
                            send_response(&Response::StatusUpdate { status: snap }, &mut server)
                                .await
                                .unwrap();
                        }
                    }
                }
            }
        };

        tokio::join!(client_flow, server_flow);
    }

    #[tokio::test]
    async fn profile_crud_over_ipc() {
        let (client, mut server) = tokio::io::duplex(4096);
        let mut client = tokio::io::BufReader::new(client);
        let mut st = state();
        let srv = tokio::spawn(async move {
            handle_conn(&mut st, &mut server).await.unwrap();
        });

        send_request(
            &Request::AddProfile {
                profile: ProfileMsg {
                    id: "p2".into(),
                    name: "Branch".into(),
                    host: "b.example.com".into(),
                    port: 8443,
                    tunnel_type: "udp".into(),
                    autoconnect: false,
                },
            },
            &mut client,
        )
        .await
        .unwrap();
        let res = recv_response(&mut client).await.unwrap();
        match res {
            Response::Profiles { profiles } => {
                assert_eq!(profiles.len(), 2);
                let p = profiles.iter().find(|p| p.id == "p2").unwrap();
                assert_eq!(p.port, 8443);
                assert_eq!(p.tunnel_type, "udp");
            }
            other => panic!("unexpected: {other:?}"),
        }

        send_request(&Request::RemoveProfile { profile_id: "p2".into() }, &mut client)
            .await
            .unwrap();
        let res = recv_response(&mut client).await.unwrap();
        match res {
            Response::Profiles { profiles } => assert_eq!(profiles.len(), 1),
            other => panic!("unexpected: {other:?}"),
        }

        // 不存在的 profile 删除 -> Error
        send_request(&Request::RemoveProfile { profile_id: "p2".into() }, &mut client)
            .await
            .unwrap();
        let res = recv_response(&mut client).await.unwrap();
        assert!(matches!(res, Response::Error { .. }));

        // 查表连接不存在的 profile -> 回退骨架模式仍可连（临时凭据）
        send_request(&Request::Start { profile_id: "ghost".into() }, &mut client)
            .await
            .unwrap();
        let res = recv_response(&mut client).await.unwrap();
        assert!(matches!(res, Response::Status { .. }));

        drop(client);
        srv.await.unwrap();
    }
}
