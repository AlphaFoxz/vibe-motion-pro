//! 网络（路由/DNS）执行器与平台后端。
//!
//! 架构（三层，职责分离）：
//! - [`crate::route`]：纯命令/内容构造（无副作用，全平台可单测）
//! - [`NetBackend`]：各平台的「接管/还原策略」（残留清理、advisory 命令、
//!   命令式 vs 文件改写式 DNS）
//! - [`RouteManager`]：流程编排（apply → 记账 → revert 幂等回滚），平台无感知
//!
//! 可测试性：`RouteManager::with_backend` 可在**任意宿主机**上演练指定平台的
//! 命令序列/文件改写（DryRunRunner + MemoryFs 只记录不执行）——按宿主 OS
//! 断言的旧测试在 Linux/macOS 上必然失败（2026-11 Linux 基线实证后重构）。

use crate::route::{
    build_resolv_conf, linux_route_add, linux_route_delete, macos_route_add, macos_route_delete,
    macos_set_dns, windows_route_add, windows_route_delete, windows_set_dns, RouteError,
};
use crate::PlatformError;
use std::path::{Path, PathBuf};
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

/// 文件操作抽象（resolv.conf 直写路径用；注入以便测试）。
pub trait FsOps: Send + Sync {
    fn read_to_string(&self, path: &Path) -> std::io::Result<String>;
    fn write(&self, path: &Path, contents: &str) -> std::io::Result<()>;
    fn remove(&self, path: &Path) -> std::io::Result<()>;
    fn exists(&self, path: &Path) -> bool;
}

/// 真实文件系统（std::fs 直通；write 沿符号链接写目标）。
pub struct RealFs;

impl FsOps for RealFs {
    fn read_to_string(&self, path: &Path) -> std::io::Result<String> {
        std::fs::read_to_string(path)
    }
    fn write(&self, path: &Path, contents: &str) -> std::io::Result<()> {
        std::fs::write(path, contents)
    }
    fn remove(&self, path: &Path) -> std::io::Result<()> {
        std::fs::remove_file(path)
    }
    fn exists(&self, path: &Path) -> bool {
        path.exists()
    }
}

/// DNS 接管计划（apply 期由后端产出）。
pub enum DnsPlan {
    /// 命令式：apply 命令序列 + 还原命令（netsh / resolvectl / networksetup）。
    Commands {
        apply: Vec<Apply>,
        restore: Vec<String>,
    },
    /// 文件改写式（无 systemd-resolved 的 Linux）：写接管内容，还原写回快照；
    /// 原文件不存在（snapshot = None）则还原时删除。
    File {
        target: PathBuf,
        content: String,
        snapshot: Option<String>,
    },
}

/// 一条 DNS 接管命令；`advisory = true` 表示尽力而为（失败仅告警，
/// 不判接管失败——例如 resolvectl default-route 在老 systemd 上不存在）。
pub struct Apply {
    pub argv: Vec<String>,
    pub advisory: bool,
}

/// 策略产出期的执行上下文（探测 + 快照需要真实 runner/fs）。
pub struct DnsCtx<'a> {
    pub runner: &'a dyn CommandRunner,
    pub fs: &'a dyn FsOps,
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
    /// 产出 DNS 接管计划（可能探测系统环境选择子策略）。
    fn dns_apply(&self, iface: &str, servers: &[String], ctx: &DnsCtx<'_>) -> Result<DnsPlan, RouteError>;
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

    fn dns_apply(&self, iface: &str, servers: &[String], _ctx: &DnsCtx<'_>) -> Result<DnsPlan, RouteError> {
        let mut apply = vec![Apply {
            argv: windows_set_dns(iface, &servers[0])?,
            advisory: false,
        }];
        // 追加备用 DNS（index 从 2 起）
        for (i, extra) in servers.iter().enumerate().skip(1) {
            apply.push(Apply {
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
        Ok(DnsPlan::Commands {
            apply,
            restore: crate::route::windows_reset_dns(iface),
        })
    }

    fn route_del(&self, cidr: &str, _iface: &str) -> Result<Vec<String>, RouteError> {
        windows_route_delete(cidr)
    }
}

// ===================== Linux =====================

/// Linux：iproute2（`ip route replace` 幂等，无需清理残留）。
/// DNS 双策略：systemd-resolved 在跑 → resolvectl；否则直写 /etc/resolv.conf
/// （Ubuntu Server 最小安装 / 无 resolved 容器与 WSL 的实际路径）。
pub struct LinuxBackend;

/// systemd-resolved 活动标志目录。
const RESOLVED_MARKER: &str = "/run/systemd/resolve";
/// 传统 DNS 配置文件（可能是指向 stub/NetworkManager 的符号链接，写穿即可）。
const RESOLV_CONF: &str = "/etc/resolv.conf";

impl NetBackend for LinuxBackend {
    fn route_add(&self, cidr: &str, gateway: &str, iface: &str) -> Result<Vec<String>, RouteError> {
        linux_route_add(cidr, gateway, iface)
    }

    fn dns_apply(&self, iface: &str, servers: &[String], ctx: &DnsCtx<'_>) -> Result<DnsPlan, RouteError> {
        if ctx.fs.exists(Path::new(RESOLVED_MARKER)) {
            // resolvectl 路径。default-route 为 advisory：让 VPN DNS 承担默认解析，
            // 老 systemd 无此子命令时失败仅告警（DNS 本身已接管成功）。
            let mut dns_argv = vec!["resolvectl".into(), "dns".into(), iface.into()];
            dns_argv.extend(servers.iter().cloned());
            return Ok(DnsPlan::Commands {
                apply: vec![
                    Apply { argv: dns_argv, advisory: false },
                    Apply {
                        argv: vec![
                            "resolvectl".into(),
                            "default-route".into(),
                            iface.into(),
                            "true".into(),
                        ],
                        advisory: true,
                    },
                ],
                // revert 一并清除该接口的 dns/domain/default-route 设置
                restore: vec!["resolvectl".into(), "revert".into(), iface.into()],
            });
        }
        // resolv.conf 直写：快照整文件内容用于还原。
        let target = PathBuf::from(RESOLV_CONF);
        let snapshot = ctx.fs.read_to_string(&target).ok();
        let content = build_resolv_conf(snapshot.as_deref().unwrap_or(""), servers);
        Ok(DnsPlan::File { target, content, snapshot })
    }

    fn route_del(&self, cidr: &str, iface: &str) -> Result<Vec<String>, RouteError> {
        linux_route_delete(cidr, iface)
    }
}

// ===================== macOS =====================

/// macOS：route + networksetup。
/// `networksetup` 操作的是**网络服务**（如 "Wi-Fi"）而非接口名 —— 运行期从
/// `-listnetworkservices` 解析优先级最高的可用服务；查询失败回退接口名。
/// 还原基于 `-getdnsservers` 快照（固定还原 "empty" 会抹掉用户手动静态 DNS）。
pub struct MacosBackend;

/// 从 `-listnetworkservices` 输出解析首个可用服务（首行是说明文字，
/// `*` 前缀 = 已禁用，顺序即服务优先级）。
fn macos_primary_service(list_output: &str) -> Option<String> {
    list_output
        .lines()
        .map(str::trim)
        .filter(|l| !l.is_empty() && !l.starts_with("An asterisk") && !l.starts_with('*'))
        .next()
        .map(str::to_string)
}

/// 从 `-getdnsservers` 输出构造还原命令（"There aren't any..." → empty；
/// 否则原样回填 IP 列表）。
fn macos_dns_restore_cmd(service: &str, get_output: &str) -> Vec<String> {
    let mut argv = vec!["networksetup".to_string(), "-setdnsservers".to_string(), service.to_string()];
    let ips: Vec<&str> = get_output
        .lines()
        .map(str::trim)
        .filter(|l| l.parse::<std::net::Ipv4Addr>().is_ok())
        .collect();
    if ips.is_empty() {
        argv.push("empty".into());
    } else {
        argv.extend(ips.into_iter().map(str::to_string));
    }
    argv
}

impl NetBackend for MacosBackend {
    fn route_add(&self, cidr: &str, gateway: &str, _iface: &str) -> Result<Vec<String>, RouteError> {
        macos_route_add(cidr, gateway)
    }

    fn dns_apply(&self, iface: &str, servers: &[String], ctx: &DnsCtx<'_>) -> Result<DnsPlan, RouteError> {
        let list = ctx
            .runner
            .run(&["networksetup".into(), "-listnetworkservices".into()])
            .unwrap_or_default();
        let service = macos_primary_service(&list).unwrap_or_else(|| iface.to_string());
        let current = ctx
            .runner
            .run(&["networksetup".into(), "-getdnsservers".into(), service.clone()])
            .unwrap_or_default();
        Ok(DnsPlan::Commands {
            apply: vec![Apply {
                argv: macos_set_dns(&service, servers)?,
                advisory: false,
            }],
            restore: macos_dns_restore_cmd(&service, &current),
        })
    }

    fn route_del(&self, cidr: &str, _iface: &str) -> Result<Vec<String>, RouteError> {
        macos_route_delete(cidr)
    }
}

// ===================== 编排 =====================

/// 还原记账（apply 期由 DnsPlan 折算而来）。
enum DnsRestore {
    Commands(Vec<String>),
    File { target: PathBuf, snapshot: Option<String> },
}

/// 连接期路由/DNS 管理：apply 后保留记账，disconnect 时整体回滚。
pub struct RouteManager {
    runner: Arc<dyn CommandRunner>,
    fs: Arc<dyn FsOps>,
    backend: Box<dyn NetBackend>,
    /// 已下发的路由（用于回滚）
    applied_routes: Vec<String>,
    /// DNS 还原记账：Some 表示做过 DNS 变更
    dns_restore: Option<DnsRestore>,
    /// 路由网关 = 虚拟网卡本端地址
    gateway: String,
    interface: String,
}

impl RouteManager {
    /// 按宿主 OS 选择后端（生产路径）。
    pub fn new(runner: Arc<dyn CommandRunner>, gateway: &str, interface: &str) -> Self {
        Self::with_backend(runner, Arc::new(RealFs), gateway, interface, os_backend())
    }

    /// 显式指定后端与文件操作（测试：在任意宿主机演练任意平台）。
    pub fn with_backend(
        runner: Arc<dyn CommandRunner>,
        fs: Arc<dyn FsOps>,
        gateway: &str,
        interface: &str,
        backend: Box<dyn NetBackend>,
    ) -> Self {
        Self {
            runner,
            fs,
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

    /// 设置 DNS 并记账还原方式（命令还原 / 文件快照还原）。
    pub fn set_dns(&mut self, servers: &[String]) -> Result<(), PlatformError> {
        if servers.is_empty() {
            return Err(PlatformError::Dns("no dns servers".into()));
        }
        let ctx = DnsCtx { runner: self.runner.as_ref(), fs: self.fs.as_ref() };
        match self
            .backend
            .dns_apply(&self.interface, servers, &ctx)
            .map_err(|e| PlatformError::Dns(e.to_string()))?
        {
            DnsPlan::Commands { apply, restore } => {
                for a in apply {
                    match self.runner.run(&a.argv) {
                        Ok(_) => {}
                        // advisory 命令失败不回滚接管（主命令已成功）
                        Err(e) if a.advisory => {
                            tracing::warn!("advisory dns command failed (ignored): {e}")
                        }
                        Err(e) => return Err(e),
                    }
                }
                self.dns_restore = Some(DnsRestore::Commands(restore));
            }
            DnsPlan::File { target, content, snapshot } => {
                self.fs
                    .write(&target, &content)
                    .map_err(|e| PlatformError::Dns(format!("write {}: {e}", target.display())))?;
                self.dns_restore = Some(DnsRestore::File { target, snapshot });
            }
        }
        Ok(())
    }

    /// 断开清理：按记录逆序回滚 DNS 与路由。幂等（重复调用安全）。
    ///
    /// 回滚是尽力而为的清理路径：失败只告警不返回 Err —— 典型场景是网卡
    /// 先于回滚关闭，内核已自动清掉该接口的路由（Linux/macOS 关 tun 即如此），
    /// 此时 del 失败恰是期望状态。真正的失败在日志里可见。
    pub fn revert(&mut self) {
        match self.dns_restore.take() {
            Some(DnsRestore::Commands(cmds)) => {
                if let Err(e) = self.runner.run(&cmds) {
                    tracing::warn!("dns restore failed: {e}");
                }
            }
            Some(DnsRestore::File { target, snapshot }) => {
                let r = match &snapshot {
                    Some(c) => self.fs.write(&target, c),
                    None => self.fs.remove(&target),
                };
                if let Err(e) = r {
                    tracing::warn!("dns restore ({}) failed: {e}", target.display());
                }
            }
            None => {}
        }
        for cidr in self.applied_routes.drain(..).rev() {
            match self.backend.route_del(&cidr, &self.interface) {
                Ok(argv) => {
                    if let Err(e) = self.runner.run(&argv) {
                        tracing::warn!("route delete {cidr} failed (may already be gone): {e}");
                    }
                }
                Err(e) => tracing::warn!("route delete {cidr} construction failed: {e}"),
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashMap;

    /// 内存文件系统（可预置、可断言）。
    #[derive(Default, Clone)]
    struct MemoryFs {
        files: Arc<Mutex<HashMap<PathBuf, String>>>,
    }

    impl MemoryFs {
        fn set(&self, path: &str, content: &str) {
            self.files.lock().unwrap().insert(path.into(), content.into());
        }
        fn get(&self, path: &str) -> Option<String> {
            self.files.lock().unwrap().get(Path::new(path)).cloned()
        }
    }

    impl FsOps for MemoryFs {
        fn read_to_string(&self, path: &Path) -> std::io::Result<String> {
            self.files
                .lock()
                .unwrap()
                .get(path)
                .cloned()
                .ok_or_else(|| std::io::Error::new(std::io::ErrorKind::NotFound, "not found"))
        }
        fn write(&self, path: &Path, contents: &str) -> std::io::Result<()> {
            self.files.lock().unwrap().insert(path.to_path_buf(), contents.to_string());
            Ok(())
        }
        fn remove(&self, path: &Path) -> std::io::Result<()> {
            self.files.lock().unwrap().remove(&path.to_path_buf()).map(|_| ()).ok_or_else(|| {
                std::io::Error::new(std::io::ErrorKind::NotFound, "not found")
            })
        }
        fn exists(&self, path: &Path) -> bool {
            self.files.lock().unwrap().contains_key(&path.to_path_buf())
        }
    }

    /// 按调用次序返回预置输出的 runner（macOS 探测/快照用）。
    #[derive(Clone)]
    struct ScriptedRunner {
        outputs: Arc<Mutex<Vec<String>>>,
        log: Arc<Mutex<Vec<String>>>,
    }

    impl ScriptedRunner {
        fn new(outputs: Vec<String>) -> Self {
            Self {
                outputs: Arc::new(Mutex::new(outputs)),
                log: Arc::new(Mutex::new(vec![])),
            }
        }
        fn calls(&self) -> Vec<String> {
            self.log.lock().unwrap().clone()
        }
    }

    impl CommandRunner for ScriptedRunner {
        fn run(&self, argv: &[String]) -> Result<String, PlatformError> {
            self.log.lock().unwrap().push(argv.join(" "));
            // 预置输出耗尽（如 revert 的还原命令）→ 空输出即可
            let mut out = self.outputs.lock().unwrap();
            if out.is_empty() {
                return Ok(String::new());
            }
            Ok(out.remove(0))
        }
    }

    fn mgr_with(b: Box<dyn NetBackend>) -> (DryRunRunner, MemoryFs, RouteManager) {
        let dry = DryRunRunner::new();
        let fs = MemoryFs::default();
        let mgr = RouteManager::with_backend(
            Arc::new(dry.clone()),
            Arc::new(fs.clone()),
            "10.111.222.1",
            "mp-tun",
            b,
        );
        (dry, fs, mgr)
    }

    #[test]
    fn windows_flow_predelete_add_dns_restore() {
        let (dry, _fs, mut mgr) = mgr_with(Box::new(WindowsBackend));
        mgr.add_route("10.3.130.0/24").unwrap();
        mgr.set_dns(&["10.91.16.1".into(), "10.91.16.2".into()]).unwrap();
        mgr.revert();
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
        mgr.revert();
        assert_eq!(dry.log().len(), 6);
    }

    #[test]
    fn linux_resolved_flow_replace_and_resolvectl() {
        let (dry, fs, mut mgr) = mgr_with(Box::new(LinuxBackend));
        fs.set(RESOLVED_MARKER, ""); // systemd-resolved 在跑
        mgr.add_route("10.3.130.0/24").unwrap();
        mgr.set_dns(&["10.91.16.1".into()]).unwrap();
        mgr.revert();
        let log = dry.log();
        assert_eq!(log[0], "ip route replace 10.3.130.0/24 via 10.111.222.1 dev mp-tun");
        assert_eq!(log[1], "resolvectl dns mp-tun 10.91.16.1");
        assert_eq!(log[2], "resolvectl default-route mp-tun true");
        assert_eq!(log[3], "resolvectl revert mp-tun");
        assert_eq!(log[4], "ip route del 10.3.130.0/24 dev mp-tun");
        assert_eq!(log.len(), 5);
    }

    #[test]
    fn linux_legacy_flow_resolv_conf_rewrite_and_restore() {
        let (dry, fs, mut mgr) = mgr_with(Box::new(LinuxBackend));
        // 无 resolved 标志；resolv.conf 有既有 DNS + search
        fs.set(
            RESOLV_CONF,
            "# Generated by NetworkManager\nnameserver 192.168.1.1\nsearch office.example\n",
        );
        mgr.add_route("10.3.130.0/24").unwrap();
        mgr.set_dns(&["10.91.16.1".into(), "10.91.16.2".into()]).unwrap();
        // 接管：nameserver 替换为 VPN DNS，search 保留，无 resolvectl 命令
        assert_eq!(
            fs.get(RESOLV_CONF).unwrap(),
            "search office.example\nnameserver 10.91.16.1\nnameserver 10.91.16.2\n"
        );
        mgr.revert();
        // 还原：字节级回到快照
        assert_eq!(
            fs.get(RESOLV_CONF).unwrap(),
            "# Generated by NetworkManager\nnameserver 192.168.1.1\nsearch office.example\n"
        );
        // 文件路径不产生任何命令；路由仍是 iproute2
        let log = dry.log();
        assert_eq!(log[0], "ip route replace 10.3.130.0/24 via 10.111.222.1 dev mp-tun");
        assert_eq!(log[1], "ip route del 10.3.130.0/24 dev mp-tun");
        assert_eq!(log.len(), 2);
        // 幂等
        mgr.revert();
        assert_eq!(dry.log().len(), 2);
    }

    #[test]
    fn linux_legacy_flow_removes_file_when_it_did_not_exist() {
        let (_dry, fs, mut mgr) = mgr_with(Box::new(LinuxBackend));
        mgr.set_dns(&["10.91.16.1".into()]).unwrap();
        assert!(fs.get(RESOLV_CONF).is_some()); // 接管期创建了内容
        mgr.revert();
        assert!(fs.get(RESOLV_CONF).is_none()); // 原本不存在 → 还原即删除
    }

    #[test]
    fn macos_dns_targets_primary_service_and_restores_snapshot() {
        let runner = ScriptedRunner::new(vec![
            "An asterisk (*) denotes that a network service is disabled.\n*Thunderbolt Bridge\nWi-Fi\nEthernet\n".into(),
            "10.0.0.1\n10.0.0.2\n".into(),
        ]);
        let mut mgr = RouteManager::with_backend(
            Arc::new(runner.clone()),
            Arc::new(MemoryFs::default()),
            "10.111.222.1",
            "utun7",
            Box::new(MacosBackend),
        );
        mgr.set_dns(&["10.91.16.1".into()]).unwrap();
        mgr.revert();
        let calls = runner.calls();
        // 探测命令
        assert_eq!(calls[0], "networksetup -listnetworkservices");
        assert_eq!(calls[1], "networksetup -getdnsservers Wi-Fi"); // 跳过禁用的 Thunderbolt
        // 接管与还原都以 Wi-Fi 为目标；还原回填快照 IP
        assert_eq!(calls[2], "networksetup -setdnsservers Wi-Fi 10.91.16.1");
        assert_eq!(calls[3], "networksetup -setdnsservers Wi-Fi 10.0.0.1 10.0.0.2");
    }

    #[test]
    fn macos_dns_restore_empty_when_no_previous_servers() {
        let runner = ScriptedRunner::new(vec![
            "An asterisk (*) denotes that a network service is disabled.\nEthernet\n".into(),
            "There aren't any DNS Servers set for Ethernet. You may want to use sudo networksetup -setdnsservers <networkservice> <dns1> <dns2> ...".into(),
        ]);
        let mut mgr = RouteManager::with_backend(
            Arc::new(runner.clone()),
            Arc::new(MemoryFs::default()),
            "10.111.222.1",
            "utun7",
            Box::new(MacosBackend),
        );
        mgr.set_dns(&["10.91.16.1".into()]).unwrap();
        mgr.revert();
        let calls = runner.calls();
        assert_eq!(calls[3], "networksetup -setdnsservers Ethernet empty");
    }

    #[test]
    fn rejects_empty_dns_and_bad_cidr() {
        let (_, _fs, mut mgr) = mgr_with(Box::new(LinuxBackend));
        assert!(mgr.set_dns(&[]).is_err());
        assert!(mgr.add_route("bad-cidr").is_err());
    }
}
