//! 网络（路由/DNS）执行器：把 route.rs 构造的命令真正跑起来，
//! 并提供 DNS 变更前的快照与回滚（对齐原版 InsideProxy 的 netsh 用法）。
//!
//! 可测试性：`CommandRunner` trait 注入 —— 测试用 `DryRunRunner` 只记录命令不执行。

use crate::PlatformError;
use crate::route::{
    linux_route_add, linux_route_delete, macos_route_add, macos_route_delete, windows_route_add,
    windows_route_delete, windows_reset_dns, windows_set_dns,
};
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
        if argv.is_empty() {
            return Err(PlatformError::Route("empty argv".into()));
        }
        let out = std::process::Command::new(&argv[0])
            .args(&argv[1..])
            .output()
            .map_err(|e| PlatformError::Route(format!("spawn {} failed: {e}", argv[0])))?;
        let text = format!("{}{}", String::from_utf8_lossy(&out.stdout), String::from_utf8_lossy(&out.stderr));
        if !out.status.success() {
            return Err(PlatformError::Route(format!("{} exited {:?}: {}", argv[0], out.status.code(), text)));
        }
        Ok(text)
    }
}

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

/// 连接期路由/DNS 管理：apply 后保留快照，disconnect 时整体回滚。
pub struct RouteManager {
    runner: Arc<dyn CommandRunner>,
    /// 已下发的路由（用于回滚）
    applied_routes: Vec<String>,
    /// DNS 快照：Some(还原命令) 表示做过 DNS 变更
    dns_restore: Option<Vec<String>>,
    /// 路由网关 = 虚拟网卡本端地址
    gateway: String,
    interface: String,
}

impl RouteManager {
    pub fn new(runner: Arc<dyn CommandRunner>, gateway: &str, interface: &str) -> Self {
        Self {
            runner,
            applied_routes: Vec::new(),
            dns_restore: None,
            gateway: gateway.to_string(),
            interface: interface.to_string(),
        }
    }

    /// 添加一条到内网网段的路由（指向虚拟网卡）。成功后记录以便回滚。
    /// Windows 下先删同前缀旧路由（前次会话残留会与本次竞争，且可能仍绑在
    /// 物理网卡接口上 —— 真机实测 ping 时通时不通）。
    pub fn add_route(&mut self, cidr: &str) -> Result<(), PlatformError> {
        let argv = match std::env::consts::OS {
            "windows" => {
                if let Ok(del) = windows_route_delete(cidr) {
                    let _ = self.runner.run(&del); // 不存在时忽略失败
                }
                // 显式绑定接口索引，避免 wintun IP 注册竞态导致路由落到物理网卡
                let if_index = crate::route::windows_if_index(&self.interface);
                windows_route_add(cidr, &self.gateway, 25, if_index)
                    .map_err(|e| PlatformError::Route(e.to_string()))?
            },
            "linux" => linux_route_add(cidr, &self.gateway, &self.interface)
                .map_err(|e| PlatformError::Route(e.to_string()))?,
            "macos" => macos_route_add(cidr, &self.gateway)
                .map_err(|e| PlatformError::Route(e.to_string()))?,
            _ => return Err(PlatformError::Route("unsupported platform".into())),
        };
        self.runner.run(&argv)?;
        self.applied_routes.push(cidr.to_string());
        Ok(())
    }

    /// 设置虚拟网卡 DNS，并记录还原命令（Windows 还原为 DHCP；macOS 还原为 empty；
    /// Linux 走 systemd-resolved 还原空 DNS 列表）。
    pub fn set_dns(&mut self, servers: &[String]) -> Result<(), PlatformError> {
        if servers.is_empty() {
            return Err(PlatformError::Dns("no dns servers".into()));
        }
        let apply = match std::env::consts::OS {
            "windows" => windows_set_dns(&self.interface, &servers[0])
                .map_err(|e| PlatformError::Dns(e.to_string()))?,
            "macos" => {
                macos_set_dns(&self.interface, servers).map_err(|e| PlatformError::Dns(e.to_string()))?
            }
            "linux" => {
                linux_set_dns(&self.interface, servers).map_err(|e| PlatformError::Dns(e.to_string()))?
            }
            _ => return Err(PlatformError::Dns("unsupported platform".into())),
        };
        self.runner.run(&apply)?;
        // Windows 追加备用 DNS
        if std::env::consts::OS == "windows" {
            for (i, extra) in servers.iter().enumerate().skip(1) {
                let argv = vec![
                    "netsh".into(), "interface".into(), "ip".into(), "add".into(), "dns".into(),
                    format!("name=\"{}\"", self.interface), extra.clone(), format!("index={}", i + 1),
                ];
                self.runner.run(&argv)?;
            }
        }
        // 还原命令（Windows=DHCP，macOS=empty，Linux=resolvectl revert）
        self.dns_restore = Some(match std::env::consts::OS {
            "windows" => windows_reset_dns(&self.interface),
            "macos" => macos_reset_dns(&self.interface),
            "linux" => linux_reset_dns(&self.interface),
            _ => return Err(PlatformError::Dns("unsupported platform".into())),
        });
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
            let argv = match std::env::consts::OS {
                "windows" => windows_route_delete(&cidr).map_err(|e| PlatformError::Route(e.to_string()))?,
                "linux" => linux_route_delete(&cidr, &self.interface)
                    .map_err(|e| PlatformError::Route(e.to_string()))?,
                "macos" => macos_route_delete(&cidr).map_err(|e| PlatformError::Route(e.to_string()))?,
                _ => continue,
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

/// macOS DNS：`networksetup -setdnsservers <svc> <dns...>`（多值；还原用 empty）。
pub fn macos_set_dns(service: &str, servers: &[String]) -> Result<Vec<String>, crate::route::RouteError> {
    for s in servers {
        crate::route::validate_ip(s)?;
    }
    let mut argv = vec!["networksetup".into(), "-setdnsservers".into(), service.into()];
    argv.extend(servers.iter().cloned());
    Ok(argv)
}

pub fn macos_reset_dns(service: &str) -> Vec<String> {
    vec!["networksetup".into(), "-setdnsservers".into(), service.into(), "empty".into()]
}

/// Linux DNS：`resolvectl dns <if> <servers...>`（systemd-resolved）。
pub fn linux_set_dns(iface: &str, servers: &[String]) -> Result<Vec<String>, crate::route::RouteError> {
    for s in servers {
        crate::route::validate_ip(s)?;
    }
    let mut argv = vec!["resolvectl".into(), "dns".into(), iface.into()];
    argv.extend(servers.iter().cloned());
    Ok(argv)
}

pub fn linux_reset_dns(iface: &str) -> Vec<String> {
    vec!["resolvectl".into(), "revert".into(), iface.into()]
}
