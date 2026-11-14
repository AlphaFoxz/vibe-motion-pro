//! mp-daemon 库部分：可测试的连接处理逻辑。
//! main.rs 仅负责启动。

use mp_core::profile::{Profile, ProfileStore};
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
        Option<(String, String)>,
    ),
    String,
> {
    use mp_core::control::{ControlClient, Session};
    use mp_core::protocol::{LoginFormData, PostloginApps, TunnelOpenParams};

    // TODO(安全): 接入 rootca 严格校验后移除 danger 标志
    let client = ControlClient::new(host, port, true).map_err(|e| e.to_string())?;
    let mut session = Session::default();

    // 1a. 先取一次 getImage（浏览器流程必经）：种服务器端验证码会话（uuid cookie），
    //     否则登录 POST 被网关静默丢弃（真机实测）。图片字节不需要（动态密保来自手机 App）。
    let uuid = uuid_simple();
    let _ = tokio::time::timeout(
        std::time::Duration::from_secs(10),
        client.fetch_captcha(&mut session, &uuid),
    )
    .await;
    tracing::debug!("captcha session seeded (uuid={uuid})");

    // 1b. 令牌预校验（门户 main.js 实证：POST nextVpnNumberPhone → {"message":"Success"}）
    let form = LoginFormData {
        t: "t".into(),
        user_code: username.to_string(),
        pwd: password.to_string(),
        code: code.to_string(),
    };
    match tokio::time::timeout(std::time::Duration::from_secs(15), client.token_precheck(&mut session, &form)).await {
        Ok(Ok(())) => tracing::info!("precheck ok: 动态密保校验通过"),
        Ok(Err(e)) => return Err(login_err("precheck", &e)),
        Err(_) => return Err("precheck: 15s 超时".into()),
    }

    // 1c. /prx 登录：AG 网关地址从门户首页表单 action 解析（index.html 实证），
    //     解析失败回退到已知常量 vpntoken.baosteel.com
    let action = match tokio::time::timeout(
        std::time::Duration::from_secs(15),
        client.fetch_login_action(&mut session),
    )
    .await
    {
        Ok(Ok(a)) => a,
        Ok(Err(e)) => {
            tracing::warn!("fetch_login_action failed: {e}, fallback to known AG host");
            format!("https://{}/prx/000/http/localhost/login", mp_core::protocol::AG_GATEWAY_HOST)
        }
        Err(_) => {
            tracing::warn!("fetch_login_action timeout, fallback to known AG host");
            format!("https://{}/prx/000/http/localhost/login", mp_core::protocol::AG_GATEWAY_HOST)
        }
    };
    let ag_host = url_host(&action).unwrap_or_else(|| mp_core::protocol::AG_GATEWAY_HOST.to_string());
    let ag_port = url_port(&action).unwrap_or(443);
    tracing::info!("AG gateway: {ag_host}:{ag_port} (action={action})");
    let ag_client = ControlClient::new(&ag_host, ag_port, true).map_err(|e| e.to_string())?;
    let (login_status, location) =
        ag_client.login(&mut session, &form).await.map_err(|e| login_err("login", &e))?;
    tracing::info!("login ok: status={login_status}, redirect={location:?}");

    // 原版客户端在隧道请求里带 ANStandalone=true（T2/Ghidra 实证），登录后补种
    if !session.cookies.iter().any(|c| c.starts_with("ANStandalone")) {
        session.cookies.push("ANStandalone=true".into());
    }

    // postlogin apps：可选步骤（l3vpn.js 实证：原版 WS 启动消息不含 postlogin 结果，
    // 原版日志"返回 2 = 无资源，继续 L3VPN"）。失败/票据不合法不阻断，仅记录。
    let apps = match tokio::time::timeout(
        std::time::Duration::from_secs(15),
        client.postlogin_apps(&mut session, username, "0"),
    )
    .await
    {
        Ok(Ok(body)) => match PostloginApps::parse_tolerant(&body) {
            Ok(apps) if !apps.site.domain.is_empty() => {
                tracing::info!("postlogin ok: domain={:?} port={}", apps.site.domain, apps.site.port);
                apps
            }
            Ok(_) => {
                tracing::warn!("postlogin returned no site info (可能票据域不匹配), 按无资源继续 L3VPN");
                PostloginApps::default()
            }
            Err(e) => {
                tracing::warn!("postlogin parse failed: {e}, 按无资源继续 L3VPN");
                PostloginApps::default()
            }
        },
        Ok(Err(e)) => {
            tracing::warn!("postlogin request failed: {e}, 按无资源继续 L3VPN");
            PostloginApps::default()
        }
        Err(_) => {
            tracing::warn!("postlogin 15s 超时, 按无资源继续 L3VPN");
            PostloginApps::default()
        }
    };

    // 3. 建隧道（l3vpn.js startVpn 实证）：host=AG 网关（欢迎页主机）、port=443、
    //    会话=ANsession cookie；postlogin 的 site.domain 仅作覆盖（若有效）
    let tunnel_host = if apps.site.domain.is_empty() { ag_host.to_string() } else { apps.site.domain.clone() };
    let tunnel_port = if apps.site.port == 0 { 443 } else { apps.site.port };
    tracing::info!("tunnel target: {tunnel_host}:{tunnel_port}");
    let tclient = ControlClient::new(&tunnel_host, tunnel_port, true).map_err(|e| e.to_string())?;
    // 会话 cookie（vpntunnel_request 会自动加 "ANStandalone=true;" 前缀，这里只送 ANsession）
    let cookie = session
        .cookies
        .iter()
        .filter(|c| c.starts_with("ANsession"))
        .cloned()
        .collect::<Vec<_>>()
        .join("; ");
    // 设备身份：优先复用原版客户端注册表身份（服务器认识这台机器），否则随机持久化
    let dev = device_identity();
    let hostname = std::env::var("COMPUTERNAME").unwrap_or_else(|_| "DESKTOP".into());
    let params = TunnelOpenParams {
        cookie: &cookie,
        dev_type: 1,
        client_id: &dev.clientid,
        cpu_id: &dev.cpuid,
        hostname: &hostname,
        ipv6: false,
    };
    let (stream, _cfg, netcfg, leftover) =
        tclient.open_tunnel(&params, &local_ips(), &local_mac()).await.map_err(|e| login_err("open_tunnel", &e))?;

    // 4. 数据面泵 + TUN 网卡接线（通道对两端分别交给泵与内核异步网桥）
    let (adapter, kernel_tx, kernel_rx) = mp_core::dataplane::TokioChannelAdapter::pair(256);
    let pump = netloop::TunnelPump::spawn_with(stream, leftover, adapter);
    // TUN 接线失败（无管理员/wintun）→ 降级：隧道照常，仅无本地转发
    // include 路由（'U' 解析的 split tunnel 网段 → CIDR 前缀形式交给 RouteManager）
    let include_routes: Vec<String> = netcfg
        .include_routes
        .iter()
        .filter_map(|(ip, m)| mask_to_prefix(m).map(|p| format!("{ip}/{p}")))
        .collect();
    let tun = match tunsetup::TunLink::bring_up(
        kernel_tx,
        kernel_rx,
        netcfg.virtual_ip,
        netcfg.netmask,
        netcfg.dns.clone(),
        &include_routes,
    )
    .await
    {
        Ok(l) => Some(l),
        Err(e) => {
            tracing::warn!("TUN 降级运行（无本地转发）: {e}");
            None
        }
    };
    Ok((pump, tun, apps, netcfg, Some((tunnel_host.clone(), cookie))))
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
}

/// 点分掩码 → CIDR 前缀长度（非连续掩码返回 None）。
fn mask_to_prefix(mask: &std::net::Ipv4Addr) -> Option<u8> {
    let bits = u32::from(*mask);
    let prefix = bits.leading_ones() as u8;
    if prefix == 32 || (bits << prefix) == 0 {
        Some(prefix)
    } else {
        None
    }
}

/// 设备身份（对齐原版 vl3vpn：vl3vpn.dll 持久化于 HKCU\Software\MotionPro\L3VPN）。
/// 优先复用原版客户端留下的身份（服务器侧已绑定该设备），否则生成并持久化随机 ID。
pub struct DeviceIdentity {
    pub clientid: String,
    pub cpuid: String,
}

pub fn device_identity() -> DeviceIdentity {
    let read_reg = |value: &str| -> Option<String> {
        let out = std::process::Command::new("reg")
            .args([
                "query",
                r"HKCU\Software\MotionPro\L3VPN",
                "/v",
                value,
            ])
            .output()
            .ok()?;
        let text = String::from_utf8_lossy(&out.stdout).to_string();
        text.lines()
            .find(|l| l.contains("REG_SZ"))
            .and_then(|l| l.split_whitespace().last().map(|s| s.to_string()))
    };
    // ClientID 形如 "<HWID>|<extra>|hostname=..."，取 | 前缀
    let clientid = read_reg("ClientID")
        .and_then(|v| v.split('|').next().map(|s| s.to_string()))
        .filter(|s| !s.is_empty())
        .unwrap_or_else(|| "motionpro-rs-fallback-deviceid".into());
    let cpuid = read_reg("cpuid").filter(|s| !s.is_empty()).unwrap_or_default();
    DeviceIdentity { clientid, cpuid }
}

/// 简易 uuid（v4 形态，验证码会话关联用，无密码学要求）。
fn uuid_simple() -> String {
    use std::time::{SystemTime, UNIX_EPOCH};
    let ms = SystemTime::now().duration_since(UNIX_EPOCH).unwrap_or_default().as_millis();
    let pid = std::process::id();
    format!("{ms:x}{pid:x}{:04x}", (ms as u16) ^ (pid as u16))
}

/// 从 Location 头提取主机名（支持 "https://host[:port]/path" 与 "host:port/path"）。
fn url_host(loc: &str) -> Option<String> {
    let rest = loc.split("://").nth(1).unwrap_or(loc);
    rest.split(['/', '?', '#']).next()?.split(':').next().map(|s| s.to_string())
}

/// 从 Location 头提取端口（缺省 443）。
fn url_port(loc: &str) -> Option<u16> {
    let rest = loc.split("://").nth(1).unwrap_or(loc);
    let auth = rest.split(['/', '?', '#']).next()?;
    let port = auth.split(':').nth(1)?;
    port.parse().ok()
}pub mod netloop;
pub mod tunsetup;
use mp_ipc::codec::{recv_request, send_response};
use mp_ipc::profile::ProfileMsg;
use mp_ipc::status::StatusSnapshot;
use mp_ipc::{Request, Response};
use std::sync::atomic::AtomicU64;
use std::sync::Arc;
use tokio::io::{AsyncRead, AsyncWrite};
use tokio::sync::{broadcast, Mutex};

/// 主循环/连接处理心跳计数（供 main.rs 的冻结看门狗读取）。
/// 每秒 +1；15s 不动 → 运行时冻结，看门狗抓栈后自杀。
pub static FREEZE_TICK: AtomicU64 = AtomicU64::new(0);

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
    /// 最近一次会话的（AG 主机, Cookie）——teardown 时发 logout 释放服务端会话
    /// （反复重登不注销会在网关堆僵尸隧道，真机实测后续会话被立即拒转）
    pub last_session: Option<(String, String)>,
}

impl DaemonState {
    pub fn new(profiles: ProfileStore) -> Self {
        let (status_tx, _) = broadcast::channel(16);
        Self {
            engine: Engine::new(),
            profiles,
            status_tx,
            active_tunnel: None,
            active_tun: None,
            last_session: None,
        }
    }

    /// 异步注销：GET /prx/.../logout（带会话 cookie）。失败只记日志。
    pub fn logout_last_session(&mut self) {
        if let Some((host, cookie)) = self.last_session.take() {
            tokio::spawn(async move {
                match mp_core::control::ControlClient::new(&host, 443, true) {
                    Ok(c) => match c.logout(&cookie).await {
                        Ok(status) => tracing::info!("logout: {status}"),
                        Err(e) => tracing::warn!("logout failed: {e}"),
                    },
                    Err(e) => tracing::warn!("logout client build failed: {e}"),
                }
            });
        }
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
            self.logout_last_session();
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
            state.logout_last_session(); // 释放服务端会话（防僵尸堆积）
            match state.engine.stop() {
                Ok(_) => Response::Status { status: status_snapshot(&state.engine) },
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
        Ok((pump, tun, apps, _netcfg, session_info)) => {
            // 替换旧隧道与旧网卡（旧会话先注销，避免服务端僵尸堆积）
            state.logout_last_session();
            if let Some(mut old_tun) = state.active_tun.take() {
                old_tun.teardown();
            }
            if let Some(old) = state.active_tunnel.take() {
                tokio::spawn(old.shutdown());
            }
            state.last_session = session_info;
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
        Err(message) => {
            tracing::warn!("connect failed: {message}");
            Response::Error { message }
        }
    }
}

/// 处理一条连接直到对端关闭；由调用方 spawn 为独立任务，
/// 主循环因此能继续 accept 与 1s tick（心跳）——否则持久 UI 连接会
/// 让 ticker 分支饿死、冻结看门狗误判自杀（2026-11 真机踩坑）。
/// 同时 select 广播通道，向客户端推送 StatusUpdate（对齐原版 cmd 1 推送）。
///
/// `state` 为跨任务共享；心跳分支不取锁，长连接认证期间（锁被长时间持有）
/// FREEZE_TICK 仍每秒前进，看门狗不会误杀。
pub async fn handle_conn<S: AsyncRead + AsyncWrite + Unpin>(
    state: Arc<Mutex<DaemonState>>,
    stream: S,
) -> anyhow::Result<()> {
    use mp_ipc::IpcError;
    let mut rx = state.lock().await.status_tx.subscribe();
    // 持久 BufReader：跨 select 迭代保留缓冲字节，避免丢包卡死
    let mut stream = tokio::io::BufReader::new(stream);
    // 连接内独立心跳：仅推进 FREEZE_TICK，不碰状态锁
    let mut heartbeat = tokio::time::interval(std::time::Duration::from_secs(1));
    loop {
        tokio::select! {
            _ = heartbeat.tick() => {
                FREEZE_TICK.fetch_add(1, std::sync::atomic::Ordering::Relaxed);
            }
            req = recv_request(&mut stream) => {
                let req = match req {
                    Ok(r) => r,
                    Err(IpcError::Closed) => return Ok(()),
                    Err(e) => return Err(e.into()),
                };
                let resp = {
                    let mut st = state.lock().await;
                    match req {
                        Request::Connect { host, port, username, password, code } => {
                            handle_connect(&mut st, &host, port, &username, &password, &code).await
                        }
                        other => handle_request(&mut st, &other),
                    }
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
        let (client, server) = tokio::io::duplex(4096);
        let mut client = tokio::io::BufReader::new(client);
        let st = Arc::new(Mutex::new(state()));

        let srv = tokio::spawn(handle_conn(st, server));

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
        srv.await.unwrap().unwrap();
    }

    #[tokio::test]
    async fn status_broadcast_pushed_to_client() {
        let (client, server) = tokio::io::duplex(4096);
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
        let (client, server) = tokio::io::duplex(4096);
        let mut client = tokio::io::BufReader::new(client);
        let st = Arc::new(Mutex::new(state()));
        let srv = tokio::spawn(handle_conn(st, server));

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
        srv.await.unwrap().unwrap();
    }

    /// 全链路 mock 网关：login / postlogin / vpntunnel / 数据回显 一体。
    /// 读取完整 HTTP 请求（头 + Content-Length 体），避免分包竞态。
    async fn read_http_request(
        tls: &mut tokio_rustls::server::TlsStream<tokio::net::TcpStream>,
    ) -> String {
        use tokio::io::AsyncReadExt;
        let mut buf = Vec::with_capacity(4096);
        let mut chunk = [0u8; 4096];
        loop {
            let n = tls.read(&mut chunk).await.unwrap_or(0);
            if n == 0 {
                break;
            }
            buf.extend_from_slice(&chunk[..n]);
            if let Some(pos) = buf.windows(4).position(|w| w == b"\r\n\r\n") {
                let head = String::from_utf8_lossy(&buf[..pos]).to_string();
                let clen: usize = head
                    .lines()
                    .find_map(|l| l.split_once(':').map(|(k, v)| (k.trim().to_ascii_lowercase(), v.trim().to_string())))
                    .filter(|(k, _)| k == "content-length")
                    .and_then(|(_, v)| v.parse().ok())
                    .unwrap_or(0);
                if buf.len() >= pos + 4 + clen {
                    break;
                }
            }
        }
        String::from_utf8_lossy(&buf).to_string()
    }

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
                    let req = read_http_request(&mut tls).await;
                    let _ = &req;

                    if req.starts_with("GET / ") || req.starts_with("GET /?") {
                        // 门户首页：登录表单 action 指回本 mock（AG 网关）
                        let body = format!(
                            "<form id=\"form-password\" method=\"post\" action=\"https://127.0.0.1:{port}/prx/000/http/localhost/login\">"
                        );
                        let resp = format!(
                            "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: {}\r\n\r\n{body}",
                            body.len()
                        );
                        let _ = tls.write_all(resp.as_bytes()).await;
                    } else if req.starts_with("POST /restservice/vpnLogin/nextVpnNumberPhone") {
                        assert!(req.contains("userCode=example_user"));
                        assert!(req.contains("code=654321"), "动态密保码: {req}");
                        let _ = tls
                            .write_all(b"HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: 21\r\n\r\n{\"message\":\"Success\"}")
                            .await;
                    } else if req.starts_with("POST /prx/000/http/localhost/login") {
                        assert!(req.contains("uname=example_user"));
                        assert!(req.contains("authCode=654321"), "动态密保码: {req}");
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
        let (client, server) = tokio::io::duplex(4096);
        let mut client = tokio::io::BufReader::new(client);
        let st = Arc::new(Mutex::new(state()));
        let srv = tokio::spawn(handle_conn(st, server));

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
        srv.await.unwrap().unwrap();
    }

    #[tokio::test(flavor = "multi_thread", worker_threads = 2)]
    async fn connect_auth_failure_returns_error() {
        let port = spawn_mock_tls_reject_login().await;
        let (client, server) = tokio::io::duplex(4096);
        let mut client = tokio::io::BufReader::new(client);
        let st = Arc::new(Mutex::new(state()));
        let srv = tokio::spawn(handle_conn(st, server));
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
        srv.await.unwrap().unwrap();
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
                let port = port;
                tokio::spawn(async move {
                    use tokio::io::AsyncWriteExt;
                    let Ok(mut tls) = acceptor.accept(sock).await else { return };
                    let req = read_http_request(&mut tls).await;
                    if req.starts_with("GET / ") {
                        let body = format!(
                            "<form method=\"post\" action=\"https://127.0.0.1:{port}/prx/000/http/localhost/login\">"
                        );
                        let resp = format!(
                            "HTTP/1.1 200 OK\r\nContent-Length: {}\r\n\r\n{body}",
                            body.len()
                        );
                        let _ = tls.write_all(resp.as_bytes()).await;
                    } else if req.starts_with("POST /restservice/vpnLogin/nextVpnNumberPhone") {
                        let _ = tls
                            .write_all(b"HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: 21\r\n\r\n{\"message\":\"Success\"}")
                            .await;
                    } else if req.starts_with("POST /prx/000/http/localhost/login") {
                        // 200 但不种 ANsession → 认证失败
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
