//! mp-daemon 库部分：可测试的连接处理逻辑。
//! main.rs 仅负责启动。

use mp_core::profile::{Profile, ProfileError, ProfileStore};
use mp_core::session::{Credentials, TunnelType};
use mp_core::{Engine, VpnStatus};

/// 免浏览器登录 + 建立真实隧道的完整流程（dev-6 内化登录）：
/// 1. POST /restservice/vpnLogin/login（用户名/密码/动态密保）→ ANsession
/// 2. postlogin apps → site.session（VPN 凭据）
/// 3. GET /vpntunnel 握手（16B 配置帧）→ 数据模式流
/// 4. TunnelPump：TUN ⇄ TLS 裸 IP 转发 + keepalive
///
/// 返回运行中的 pump（daemon 持有，Stop 时 shutdown）。
pub async fn connect_with_login(
    host: &str,
    port: u16,
    username: &str,
    password: &str,
    code: &str,
) -> Result<
    (
        netloop::TunnelPump,
        Option<tunsetup::TunLink>,
        mp_core::protocol::PostloginApps,
        mp_core::protocol::NetworkConfig,
    ),
    String,
> {
    use mp_core::control::{ControlClient, ControlError, Session};
    use mp_core::protocol::{LoginFormData, PostloginApps, TunnelOpenParams};

    // TODO(安全): 接入 rootca 严格校验后移除 danger 标志
    let client = ControlClient::new(host, port, true).map_err(|e| e.to_string())?;
    let mut session = Session::default();

    // 1. 登录（动态密保码来自手机 App）
    let form = LoginFormData {
        t: "t".into(),
        user_code: username.to_string(),
        pwd: password.to_string(),
        code: code.to_string(),
    };
    client.login(&mut session, &form).await.map_err(|e| login_err("login", &e))?;

    // 2. postlogin apps：站点/会话信息
    let body = client
        .postlogin_apps(&mut session, username, "0")
        .await
        .map_err(|e| login_err("postlogin", &e))?;
    let apps: PostloginApps =
        serde_json::from_str(body.trim()).map_err(|e| format!("postlogin parse: {e}"))?;

    // 3. 建隧道：host 取 site.domain（AG 网关），port 取 site.port（缺省 443）
    let tunnel_host = if apps.site.domain.is_empty() { host.to_string() } else { apps.site.domain.clone() };
    let tunnel_port = if apps.site.port == 0 { port } else { apps.site.port };
    let tclient = ControlClient::new(&tunnel_host, tunnel_port, true).map_err(|e| e.to_string())?;
    let cookie = session.cookies.join("; ");
    let params = TunnelOpenParams {
        cookie: &cookie,
        dev_type: 1,
        client_id: "motionpro-rs",
        cpu_id: "",
        hostname: &std::env::var("COMPUTERNAME").unwrap_or_default(),
        ipv6: false,
    };
    let (stream, _cfg, netcfg, leftover) =
        tclient.open_tunnel(&params, &local_ips(), &local_mac()).await.map_err(|e| login_err("open_tunnel", &e))?;

    // 4. 数据面泵 + TUN 网卡接线（通道对两端分别交给泵与内核异步网桥）
    let (adapter, kernel_tx, kernel_rx) = mp_core::dataplane::TokioChannelAdapter::pair(256);
    let pump = netloop::TunnelPump::spawn_with(
        stream,
        leftover,
        adapter,
        std::time::Duration::from_secs(mp_core::protocol::KEEPALIVE_INTERVAL_SECS),
    );
    // TUN 接线失败（无管理员/wintun）→ 降级：隧道照常，仅无本地转发
    let tun = match tunsetup::TunLink::bring_up(
        kernel_tx,
        kernel_rx,
        netcfg.virtual_ip,
        netcfg.netmask,
        netcfg.dns.clone(),
        &[],
    )
    .await
    {
        Ok(l) => Some(l),
        Err(e) => {
            tracing::warn!("TUN 降级运行（无本地转发）: {e}");
            None
        }
    };
    Ok((pump, tun, apps, netcfg))
}

/// 本机所有 IPv4（'T' 请求载荷；取非环回地址）。
fn local_ips() -> Vec<[u8; 4]> {
    let mut out = Vec::new();
    if let Ok(addrs) = local_ip_address::list_afinet_netifas() {
        for (_, ip) in addrs {
            if let std::net::IpAddr::V4(v4) = ip {
                if !v4.is_loopback() {
                    out.push(v4.octets());
                }
            }
        }
    }
    out
}

/// 本机网卡 MAC（'T' 请求载荷；取第一块以太网卡）。
fn local_mac() -> [u8; 6] {
    if let Ok(Some(m)) = mac_address::get_mac_address() {
        return m.bytes();
    }
    [0; 6]
}

fn login_err(stage: &str, e: &mp_core::control::ControlError) -> String {
    // 凭据错误提示对齐原版语义（区分认证失败与网络失败）
    match e {
        mp_core::control::ControlError::AuthFailed => {
            format!("{stage}: 登录被拒绝（用户名/密码/动态密保错误）")
        }
        other => format!("{stage}: {other}"),
    }
}pub mod netloop;
pub mod tunsetup;
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

/// 守护进程共享状态：引擎 + profile 存储 + 状态广播 + 活动隧道泵。
pub struct DaemonState {
    pub engine: Engine,
    pub profiles: ProfileStore,
    /// 状态变更广播（对齐原版 vpnd 1s 周期 "send message to clients"）
    pub status_tx: broadcast::Sender<StatusSnapshot>,
    /// 活动隧道（免浏览器登录连接的真实数据面；Stop 时 shutdown）
    pub active_tunnel: Option<netloop::TunnelPump>,
    /// 活动网卡接线（路由/DNS 随 Drop 回滚）
    pub active_tun: Option<tunsetup::TunLink>,
}

impl DaemonState {
    pub fn new(profiles: ProfileStore) -> Self {
        let (status_tx, _) = broadcast::channel(16);
        Self { engine: Engine::new(), profiles, status_tx, active_tunnel: None, active_tun: None }
    }

    /// 每 1 秒调用一次（main.rs 里的轮询任务）：检测状态变化并广播。
    /// 同时回收已死亡的隧道（pump 任务结束 → 断开网卡 + 引擎状态回 disconnected）。
    /// 返回 Some(快照) 表示发生了变化（调用方负责推送到已连接客户端），None 表示无变化。
    pub fn tick_broadcast(&mut self, last: &mut Option<StatusSnapshot>) -> Option<StatusSnapshot> {
        self.reap_tunnel();
        let snap = status_snapshot(&self.engine);
        if last.as_ref() != Some(&snap) {
            let _ = self.status_tx.send(snap.clone());
            *last = Some(snap.clone());
            Some(snap)
        } else {
            None
        }
    }

    /// 隧道死亡检测：pump 任务已结束 → 关网卡、回滚路由、引擎状态归位。
    /// UI 每 3 秒轮询 Status；tick_broadcast 每秒调用 —— 断线 ≤3 秒内可见。
    pub fn reap_tunnel(&mut self) {
        let dead = self
            .active_tunnel
            .as_ref()
            .is_some_and(|p| p.task.is_finished());
        if dead {
            if let Some(mut tun) = self.active_tun.take() {
                tun.teardown();
            }
            if let Some(pump) = self.active_tunnel.take() {
                tokio::spawn(pump.shutdown());
            }
            let _ = self.engine.stop();
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
        Request::Connect { .. } => {
            // 异步流程，由 handle_conn 的 handle_connect 处理；同步路径直接报错
            Response::Error { message: "connect requires async handler".into() }
        }
        Request::Stop => {
            // 关闭网卡（回滚路由/DNS）与隧道泵（异步 shutdown 后台执行，不阻塞响应）
            if let Some(mut tun) = state.active_tun.take() {
                tun.teardown();
            }
            if let Some(pump) = state.active_tunnel.take() {
                tokio::spawn(pump.shutdown());
            }
            match engine.stop() {
                Ok(_) => Response::Status { status: status_snapshot(engine) },
                Err(e) => Response::Error { message: e.to_string() },
            }
        }
        Request::Status => {
            state.reap_tunnel(); // 隧道死亡时状态即时归位（UI 轮询路径）
            Response::Status { status: status_snapshot(&state.engine) }
        }
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

/// 免浏览器登录连接（Connect 请求）：全链路 + 引擎/会话状态登记。
async fn handle_connect(
    state: &mut DaemonState,
    host: &str,
    port: u16,
    username: &str,
    password: &str,
    code: &str,
) -> Response {
    match connect_with_login(host, port, username, password, code).await {
        Ok((pump, tun, apps, _netcfg)) => {
            // 替换旧隧道与旧网卡
            if let Some(mut old_tun) = state.active_tun.take() {
                old_tun.teardown();
            }
            if let Some(old) = state.active_tunnel.take() {
                tokio::spawn(old.shutdown());
            }
            state.active_tunnel = Some(pump);
            state.active_tun = tun;
            let creds = Credentials {
                username: username.to_string(),
                password: String::new(),
                aaa_method: None,
                hwid: None,
            };
            let _ = state.engine.start(&creds, TunnelType::Tcp);
            if let Some(s) = state.engine.session_mut() {
                s.server = if apps.site.domain.is_empty() { host.to_string() } else { apps.site.domain.clone() };
                s.session_id = apps.site.session.clone();
            }
            Response::Status { status: status_snapshot(&state.engine) }
        }
        Err(message) => Response::Error { message },
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
                let resp = match req {
                    Request::Connect { host, port, username, password, code } => {
                        handle_connect(state, &host, port, &username, &password, &code).await
                    }
                    other => handle_request(state, &other),
                };
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

    /// 全链路 mock 网关：login / postlogin / vpntunnel / 数据回显 一体。
    async fn spawn_mock_gateway() -> u16 {
        use tokio::io::{AsyncReadExt, AsyncWriteExt};
        use tokio::net::TcpListener;
        use tokio_rustls::rustls::pki_types::{CertificateDer, PrivateKeyDer};
        use tokio_rustls::TlsAcceptor;

        let cert = rcgen::generate_simple_self_signed(vec!["127.0.0.1".into(), "vpn.example.com".into()]).unwrap();
        let key_der = PrivateKeyDer::Pkcs8(cert.key_pair.serialize_der().into());
        let cfg = tokio_rustls::rustls::ServerConfig::builder()
            .with_no_client_auth()
            .with_single_cert(vec![CertificateDer::from(cert.cert)], key_der)
            .unwrap();
        let acceptor = TlsAcceptor::from(std::sync::Arc::new(cfg));
        let listener = TcpListener::bind("127.0.0.1:0").await.unwrap();
        let port = listener.local_addr().unwrap().port();
        tokio::spawn(async move {
            while let Ok((sock, _)) = listener.accept().await {
                let acceptor = acceptor.clone();
                let port = port;
                tokio::spawn(async move {
                    let Ok(mut tls) = acceptor.accept(sock).await else { return };
                    let mut buf = vec![0u8; 16384];
                    let Ok(n) = tls.read(&mut buf).await else { return };
                    let req = String::from_utf8_lossy(&buf[..n]).to_string();

                    if req.starts_with("POST /restservice/vpnLogin/login") {
                        assert!(req.contains("userCode=example_user"));
                        assert!(req.contains("code=654321"), "动态密保码: {req}");
                        let resp = "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\
                                    Set-Cookie: ANsession1=tok; Path=/\r\n\r\n";
                        let _ = tls.write_all(resp.as_bytes()).await;
                    } else if req.contains("postlogin/apps") {
                        assert!(req.contains("Cookie: ANsession1=tok"), "cookie: {req}");
                        let body = format!(
                            r#"{{"site":{{"domain":"127.0.0.1","port":{port},"session":"vpn-sess-1"}}}}"#
                        );
                        let resp = format!(
                            "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: {}\r\n\r\n{body}",
                            body.len()
                        );
                        let _ = tls.write_all(resp.as_bytes()).await;
                    } else if req.starts_with("GET /prx/000/http/localhost/vpntunnel") {
                        assert!(req.contains("Cookie: ANStandalone=true;ANsession1=tok"));
                        let _ = tls.write_all(b"HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n").await;
                        let mut frame = [0u8; 16];
                        if tls.read_exact(&mut frame).await.is_err() {
                            return;
                        }
                        assert_eq!(frame[0], b'P');
                        let _ = tls
                            .write_all(&mp_core::protocol::encode_config_frame(
                                mp_core::protocol::ConfigMsgType::CommonConfig,
                                br#"{"mtu":1400}"#,
                            ))
                            .await;
                        // 'T' 网络配置请求 → 'U' 响应
                        let mut treq = [0u8; 48];
                        if tls.read_exact(&mut treq).await.is_err() {
                            return;
                        }
                        assert_eq!(treq[0], b'T');
                        let _ = tls
                            .write_all(&mp_core::protocol::encode_config_frame(
                                mp_core::protocol::ConfigMsgType::NetworkConfig,
                                br#"{"virip":"10.8.0.9","dns":["10.8.0.1"]}"#,
                            ))
                            .await;
                        // 数据模式：回显
                        let mut echo = [0u8; 4096];
                        loop {
                            match tls.read(&mut echo).await {
                                Ok(0) | Err(_) => break,
                                Ok(k) => {
                                    if tls.write_all(&echo[..k]).await.is_err() {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                });
            }
        });
        port
    }

    #[tokio::test(flavor = "multi_thread", worker_threads = 2)]
    async fn connect_login_full_flow_over_ipc() {
        let port = spawn_mock_gateway().await;
        let (client, mut server) = tokio::io::duplex(4096);
        let mut client = tokio::io::BufReader::new(client);
        let mut st = state();
        let srv = tokio::spawn(async move {
            handle_conn(&mut st, &mut server).await.unwrap();
        });

        // 免浏览器登录连接（用户名/密码/动态密保）
        send_request(
            &Request::Connect {
                host: "127.0.0.1".into(),
                port,
                username: "example_user".into(),
                password: "pw".into(),
                code: "654321".into(),
            },
            &mut client,
        )
        .await
        .unwrap();
        let res = recv_response(&mut client).await.unwrap();
        match res {
            Response::Status { status } => {
                assert_eq!(status.state, "connected");
                assert_eq!(status.server_ip.as_deref(), Some("127.0.0.1"));
            }
            other => panic!("unexpected: {other:?}"),
        }
        // 会话登记
        send_request(&Request::GetSession, &mut client).await.unwrap();
        match recv_response(&mut client).await.unwrap() {
            Response::Session { session_id } => assert_eq!(session_id.as_deref(), Some("vpn-sess-1")),
            other => panic!("unexpected: {other:?}"),
        }

        // 断开：Stop 应 shutdown 隧道泵并返回 disconnected
        send_request(&Request::Stop, &mut client).await.unwrap();
        match recv_response(&mut client).await.unwrap() {
            Response::Status { status } => assert_eq!(status.state, "disconnected"),
            other => panic!("unexpected: {other:?}"),
        }

        drop(client);
        srv.await.unwrap();
    }

    #[tokio::test(flavor = "multi_thread", worker_threads = 2)]
    async fn connect_auth_failure_returns_error() {
        let port = spawn_mock_tls_reject_login().await;
        let (client, mut server) = tokio::io::duplex(4096);
        let mut client = tokio::io::BufReader::new(client);
        let mut st = state();
        let srv = tokio::spawn(async move {
            handle_conn(&mut st, &mut server).await.unwrap();
        });
        send_request(
            &Request::Connect {
                host: "127.0.0.1".into(),
                port,
                username: "example_user".into(),
                password: "bad".into(),
                code: "000000".into(),
            },
            &mut client,
        )
        .await
        .unwrap();
        match recv_response(&mut client).await.unwrap() {
            Response::Error { message } => assert!(message.contains("登录被拒绝"), "{message}"),
            other => panic!("unexpected: {other:?}"),
        }
        drop(client);
        srv.await.unwrap();
    }

    /// 登录被拒的 mock：200 但不种 ANsession。
    async fn spawn_mock_tls_reject_login() -> u16 {
        use tokio::net::TcpListener;
        use tokio_rustls::rustls::pki_types::{CertificateDer, PrivateKeyDer};
        use tokio_rustls::TlsAcceptor;
        let cert = rcgen::generate_simple_self_signed(vec!["127.0.0.1".into()]).unwrap();
        let key_der = PrivateKeyDer::Pkcs8(cert.key_pair.serialize_der().into());
        let cfg = tokio_rustls::rustls::ServerConfig::builder()
            .with_no_client_auth()
            .with_single_cert(vec![CertificateDer::from(cert.cert)], key_der)
            .unwrap();
        let acceptor = TlsAcceptor::from(std::sync::Arc::new(cfg));
        let listener = TcpListener::bind("127.0.0.1:0").await.unwrap();
        let port = listener.local_addr().unwrap().port();
        tokio::spawn(async move {
            while let Ok((sock, _)) = listener.accept().await {
                let acceptor = acceptor.clone();
                tokio::spawn(async move {
                    use tokio::io::{AsyncReadExt, AsyncWriteExt};
                    let Ok(mut tls) = acceptor.accept(sock).await else { return };
                    let mut buf = vec![0u8; 8192];
                    if tls.read(&mut buf).await.is_ok() {
                        let _ = tls
                            .write_all(b"HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n")
                            .await;
                    }
                });
            }
        });
        port
    }
}
