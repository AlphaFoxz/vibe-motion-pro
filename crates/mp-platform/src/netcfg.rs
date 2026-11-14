//! 网络（路由/DNS）执行器与平台后端。
//!
//! 架构（三层，职责分离）：
//! - [`crate::route`]：纯命令构造（无副作用，全平台可单测）
//! - [`NetBackend`]：各平台的「接管/还原策略」（残留清理、追加命令、advisory 命令）
//! - [`RouteManager`]：流程编排（apply → 记账 → revert 幂等回滚），平台无感知
//!
//! 可测试性：`RouteManager::with_backend` 可在**任意宿主机**上演练指定平台的
//! 命令序列（DryRunRunner 只记录不执行）——按宿主 OS 断言的旧测试在
//! Linux/macOS 上必然失败（2026-11 Linux 基线实证后重构）。

use crate::route::{
    linux_route_add, linux_route_delete, macos_reset_dns, macos_route_add, macos_route_delete,
    macos_set_dns, windows_reset_dns, windows_route_add, windows_route_delete, windows_set_dns,
    RouteError,
};
use crate::PlatformError;
use std::sync::{Arc, Mutex};

/// 命令执行抽象（argv 形式；route.rs 构造出的就是无 shell 的 argv）。
pub trait CommandRunner: Send + Sync {
    /// 执行一条命令，成功返回合并的 stdout+stderr（用于诊断）。
    fn run(&self, argv: &[String]) -> Result<String, PlatformError>;
}

/// 真实执行器。
pub struct SystemRunner;

impl CommandRunner for SystemRunner {
    fn run(&self, argv: &[String]) -> Result<String, PlatformError> {
        use std::process::{Command, Stdio};
        use std::time::{Duration, Instant};

        const CMD_TIMEOUT: Duration = Duration::from_secs(15);

        if argv.is_empty() {
            return Err(PlatformError::Route("empty argv".into()));
        }
        let mut cmd = Command::new(&argv[0]);
        cmd.args(&argv[1..])
            .stdin(Stdio::null())
            .stdout(Stdio::piped())
            .stderr(Stdio::piped());
        #[cfg(target_os = "windows")]
        {
            use std::os::windows::process::CommandExt;
            cmd.creation_flags(CREATE_NO_WINDOW);
        }
        let mut child = cmd
            .spawn()
            .map_err(|e| PlatformError::Route(format!("spawn {} failed: {e}", argv[0])))?;
        // 轮询等待 + 超时击杀：子进程（route/netsh）偶发永久挂起时不能拖死整个流程
        let deadline = Instant::now() + CMD_TIMEOUT;
        loop {
            match child.try_wait() {
                Ok(Some(_)) => break,
                Ok(None) => {
                    if Instant::now() >= deadline {
                        let _ = child.kill();
                        return Err(PlatformError::Route(format!(
                            "{} timed out after {:?}",
                            argv[0],
                            CMD_TIMEOUT
                        )));
                    }
                    std::thread::sleep(Duration::from_millis(15));
                }
                Err(e) => {
                    return Err(PlatformError::Route(format!("wait {}: {e}", argv[0])));
                }
            }
        }
        let out = child
            .wait_with_output()
            .map_err(|e| PlatformError::Route(format!("read {} output: {e}", argv[0])))?;
        let text = format!("{}{}", String::from_utf8_lossy(&out.stdout), String::from_utf8_lossy(&out.stderr));
        if !out.status.success() {
            return Err(PlatformError::Route(format!("{} exited {:?}: {}", argv[0], out.status.code(), text)));
        }
        Ok(text)
    }
}

#[cfg(target_os = "windows")]
pub const CREATE_NO_WINDOW: u32 = 0x0800_0000;

/// 测试/演练执行器：只记录，不执行，永远成功。
#[derive(Default, Clone)]
pub struct DryRunRunner {
    pub executed: Arc<Mutex<Vec<Vec<String>>>>,
}

impl DryRunRunner {
    pub fn new() -> Self {
        Self::default()
    }
    pub fn log(&self) -> Vec<String> {
        self.executed.lock().unwrap().iter().map(|a| a.join(" ")).collect()
    }
}

impl CommandRunner for DryRunRunner {
    fn run(&self, argv: &[String]) -> Result<String, PlatformError> {
        self.executed.lock().unwrap().push(argv.to_vec());
        Ok(String::new())
    }
}

/// 一条 DNS 接管命令；`advisory = true` 表示尽力而为（失败仅告警，
/// 不判接管失败——例如 resolvectl default-route 在老 systemd 上不存在）。
pub struct Apply {
    pub argv: Vec<String>,
    pub advisory: bool,
}

/// 平台网络接管策略（路由/DNS 的「怎么接管、怎么还原」）。
pub trait NetBackend: Send + Sync {
    /// 下发一条路由的主命令（gateway = 虚拟网卡本端地址）。
    fn route_add(&self, cidr: &str, gateway: &str, iface: &str) -> Result<Vec<String>, RouteError>;
    /// add 前的残留清理命令（None = 平台自身幂等无需清理）。
    /// 执行失败会被忽略（残留不存在是常态）。
    fn route_pre(&self, _cidr: &str) -> Option<Vec<String>> {
        None
    }
    /// DNS 接管命令序列（主命令在前；advisory 追加命令在后）。
    fn dns_apply(&self, iface: &str, servers: &[String]) -> Result<Vec<Apply>, RouteError>;
    /// DNS 还原命令。
    fn dns_restore(&self, iface: &str) -> Vec<String>;
    /// 删除一条路由（回滚用）。
    fn route_del(&self, cidr: &str, iface: &str) -> Result<Vec<String>, RouteError>;
}

/// 按宿主 OS 选择后端（测试请用 `with_backend` 显式固定平台）。
pub fn os_backend() -> Box<dyn NetBackend> {
    match std::env::consts::OS {
        "linux" => Box::new(LinuxBackend),
        "macos" => Box::new(MacosBackend),
        _ => Box::new(WindowsBackend),
    }
}

// ===================== Windows =====================

/// Windows：route.exe + netsh。
/// 真机教训两条（详见 route.rs 注释）：
/// - add 前先删同前缀旧路由（前次会话残留可能与物理网卡竞争）
/// - 显式 `if <idx>` 绑定接口（wintun IP 注册竞态会把路由落到物理网卡）
pub struct WindowsBackend;

impl NetBackend for WindowsBackend {
    fn route_add(&self, cidr: &str, gateway: &str, iface: &str) -> Result<Vec<String>, RouteError> {
        windows_route_add(cidr, gateway, 25, crate::route::windows_if_index(iface))
    }

    fn route_pre(&self, cidr: &str) -> Option<Vec<String>> {
        windows_route_delete(cidr).ok()
    }

    fn dns_apply(&self, iface: &str, servers: &[String]) -> Result<Vec<Apply>, RouteError> {
        let mut out = vec![Apply {
            argv: windows_set_dns(iface, &servers[0])?,
            advisory: false,
        }];
        // 追加备用 DNS（index 从 2 起）
        for (i, extra) in servers.iter().enumerate().skip(1) {
            out.push(Apply {
                argv: vec![
                    "netsh".into(),
                    "interface".into(),
                    "ip".into(),
                    "add".into(),
                    "dns".into(),
                    format!("name=\"{iface}\""),
                    extra.clone(),
                    format!("index={}", i + 1),
                ],
                advisory: false,
            });
        }
        Ok(out)
    }

    fn dns_restore(&self, iface: &str) -> Vec<String> {
        windows_reset_dns(iface)
    }

    fn route_del(&self, cidr: &str, _iface: &str) -> Result<Vec<String>, RouteError> {
        windows_route_delete(cidr)
    }
}

// ===================== Linux =====================

/// Linux：iproute2（`ip route replace` 幂等，无需清理残留）+ systemd-resolved。
/// `resolvectl default-route true` 为 advisory：让 VPN DNS 承担默认解析
/// （仅 split 场景需要多路由域时不加）；老 systemd 无此子命令，失败仅告警。
pub struct LinuxBackend;

impl NetBackend for LinuxBackend {
    fn route_add(&self, cidr: &str, gateway: &str, iface: &str) -> Result<Vec<String>, RouteError> {
        linux_route_add(cidr, gateway, iface)
    }

    fn dns_apply(&self, iface: &str, servers: &[String]) -> Result<Vec<Apply>, RouteError> {
        let mut argv = vec!["resolvectl".into(), "dns".into(), iface.into()];
        argv.extend(servers.iter().cloned());
        Ok(vec![
            Apply { argv, advisory: false },
            Apply {
                argv: vec![
                    "resolvectl".into(),
                    "default-route".into(),
                    iface.into(),
                    "true".into(),
                ],
                advisory: true,
            },
        ])
    }

    fn dns_restore(&self, iface: &str) -> Vec<String> {
        // revert 一并清除该接口的 dns/domain/default-route 设置
        vec!["resolvectl".into(), "revert".into(), iface.into()]
    }

    fn route_del(&self, cidr: &str, iface: &str) -> Result<Vec<String>, RouteError> {
        linux_route_delete(cidr, iface)
    }
}

// ===================== macOS =====================

/// macOS：route + networksetup。
/// 已知限制：`networksetup -setdnsservers` 的第一个参数是**网络服务名**
/// （如 "Wi-Fi"），当前以接口名（utunN）传入仅对同名服务有效 ——
/// 待 macOS 真机阶段做「接口 → 服务名」映射（-listnetworkserviceorder）。
pub struct MacosBackend;

impl NetBackend for MacosBackend {
    fn route_add(&self, cidr: &str, gateway: &str, _iface: &str) -> Result<Vec<String>, RouteError> {
        macos_route_add(cidr, gateway)
    }

    fn dns_apply(&self, iface: &str, servers: &[String]) -> Result<Vec<Apply>, RouteError> {
        Ok(vec![Apply {
            argv: macos_set_dns(iface, servers)?,
            advisory: false,
        }])
    }

    fn dns_restore(&self, iface: &str) -> Vec<String> {
        macos_reset_dns(iface)
    }

    fn route_del(&self, cidr: &str, _iface: &str) -> Result<Vec<String>, RouteError> {
        macos_route_delete(cidr)
    }
}

// ===================== 编排 =====================

/// 连接期路由/DNS 管理：apply 后保留记账，disconnect 时整体回滚。
pub struct RouteManager {
    runner: Arc<dyn CommandRunner>,
    backend: Box<dyn NetBackend>,
    /// 已下发的路由（用于回滚）
    applied_routes: Vec<String>,
    /// DNS 快照：Some(还原命令) 表示做过 DNS 变更
    dns_restore: Option<Vec<String>>,
    /// 路由网关 = 虚拟网卡本端地址
    gateway: String,
    interface: String,
}

impl RouteManager {
    /// 按宿主 OS 选择后端（生产路径）。
    pub fn new(runner: Arc<dyn CommandRunner>, gateway: &str, interface: &str) -> Self {
        Self::with_backend(runner, gateway, interface, os_backend())
    }

    /// 显式指定后端（测试：在任意宿主机演练任意平台的命令序列）。
    pub fn with_backend(
        runner: Arc<dyn CommandRunner>,
        gateway: &str,
        interface: &str,
        backend: Box<dyn NetBackend>,
    ) -> Self {
        Self {
            runner,
            backend,
            applied_routes: Vec::new(),
            dns_restore: None,
            gateway: gateway.to_string(),
            interface: interface.to_string(),
        }
    }

    /// 添加一条到内网网段的路由（指向虚拟网卡）。成功后记录以便回滚。
    pub fn add_route(&mut self, cidr: &str) -> Result<(), PlatformError> {
        if let Some(pre) = self.backend.route_pre(cidr) {
            let _ = self.runner.run(&pre); // 残留不存在时失败，忽略
        }
        let argv = self
            .backend
            .route_add(cidr, &self.gateway, &self.interface)
            .map_err(|e| PlatformError::Route(e.to_string()))?;
        self.runner.run(&argv)?;
        self.applied_routes.push(cidr.to_string());
        Ok(())
    }

    /// 设置虚拟网卡 DNS，并记录还原命令（Windows 还原 DHCP；Linux
    /// resolvectl revert；macOS 置 empty）。
    pub fn set_dns(&mut self, servers: &[String]) -> Result<(), PlatformError> {
        if servers.is_empty() {
            return Err(PlatformError::Dns("no dns servers".into()));
        }
        let applies = self
            .backend
            .dns_apply(&self.interface, servers)
            .map_err(|e| PlatformError::Dns(e.to_string()))?;
        for apply in applies {
            match self.runner.run(&apply.argv) {
                Ok(_) => {}
                // advisory 命令失败不回滚接管（主命令已成功）
                Err(e) if apply.advisory => {
                    tracing::warn!("advisory dns command failed (ignored): {e}")
                }
                Err(e) => return Err(e),
            }
        }
        self.dns_restore = Some(self.backend.dns_restore(&self.interface));
        Ok(())
    }

    /// 断开清理：按记录逆序回滚 DNS 与路由。幂等（重复调用安全）。
    pub fn revert(&mut self) -> Result<(), PlatformError> {
        let mut errs = Vec::new();
        if let Some(restore) = self.dns_restore.take() {
            if self.runner.run(&restore).is_err() {
                errs.push("dns restore failed");
            }
        }
        for cidr in self.applied_routes.drain(..).rev() {
            let argv = match self.backend.route_del(&cidr, &self.interface) {
                Ok(a) => a,
                Err(_) => {
                    errs.push("route delete failed");
                    continue;
                }
            };
            if self.runner.run(&argv).is_err() {
                errs.push("route delete failed");
            }
        }
        if errs.is_empty() {
            Ok(())
        } else {
            Err(PlatformError::Route(errs.join("; ")))
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::sync::Arc;

    fn mgr_with(b: Box<dyn NetBackend>) -> (DryRunRunner, RouteManager) {
        let dry = DryRunRunner::new();
        let mgr = RouteManager::with_backend(Arc::new(dry.clone()), "10.111.222.1", "mp-tun", b);
        (dry, mgr)
    }

    #[test]
    fn windows_flow_predelete_add_dns_restore() {
        let (dry, mut mgr) = mgr_with(Box::new(WindowsBackend));
        mgr.add_route("10.3.130.0/24").unwrap();
        mgr.set_dns(&["10.91.16.1".into(), "10.91.16.2".into()]).unwrap();
        mgr.revert().unwrap();
        let log = dry.log();
        // 非 Windows 宿主上 windows_if_index 为 None → route add 无 if 段
        assert!(log[0].starts_with("route delete 10.3.130.0"));
        assert!(log[1].starts_with("route add 10.3.130.0 mask 255.255.255.0 10.111.222.1 metric 25"));
        assert!(log[2].contains("set dns") && log[2].contains("10.91.16.1"));
        assert!(log[3].contains("add dns") && log[3].contains("10.91.16.2"));
        assert!(log[4].contains("source=dhcp"));
        assert!(log[5].starts_with("route delete 10.3.130.0"));
        assert_eq!(log.len(), 6);
        // 幂等：无路由/DNS 残留时 revert 不再执行命令
        mgr.revert().unwrap();
        assert_eq!(dry.log().len(), 6);
    }

    #[test]
    fn linux_flow_replace_resolvectl_revert() {
        let (dry, mut mgr) = mgr_with(Box::new(LinuxBackend));
        mgr.add_route("10.3.130.0/24").unwrap();
        mgr.set_dns(&["10.91.16.1".into()]).unwrap();
        mgr.revert().unwrap();
        let log = dry.log();
        assert_eq!(log[0], "ip route replace 10.3.130.0/24 via 10.111.222.1 dev mp-tun");
        assert_eq!(log[1], "resolvectl dns mp-tun 10.91.16.1");
        assert_eq!(log[2], "resolvectl default-route mp-tun true");
        assert_eq!(log[3], "resolvectl revert mp-tun");
        assert_eq!(log[4], "ip route del 10.3.130.0/24 dev mp-tun");
        assert_eq!(log.len(), 5);
    }

    #[test]
    fn macos_flow_route_networksetup() {
        let (dry, mut mgr) = mgr_with(Box::new(MacosBackend));
        mgr.add_route("10.3.130.0/24").unwrap();
        mgr.set_dns(&["10.91.16.1".into(), "10.91.16.2".into()]).unwrap();
        mgr.revert().unwrap();
        let log = dry.log();
        assert_eq!(log[0], "route -n add -net 10.3.130.0/24 10.111.222.1");
        assert_eq!(log[1], "networksetup -setdnsservers mp-tun 10.91.16.1 10.91.16.2");
        assert_eq!(log[2], "networksetup -setdnsservers mp-tun empty");
        assert_eq!(log[3], "route -n delete -net 10.3.130.0/24");
        assert_eq!(log.len(), 4);
    }

    #[test]
    fn rejects_empty_dns_and_bad_cidr() {
        let (_, mut mgr) = mgr_with(Box::new(LinuxBackend));
        assert!(mgr.set_dns(&[]).is_err());
        assert!(mgr.add_route("bad-cidr").is_err());
    }
}
