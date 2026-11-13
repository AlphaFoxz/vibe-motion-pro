//! mp-platform: 各平台虚拟网卡 / 路由 / DNS / 系统服务封装。
//! Windows: wintun.dll；macOS: utun；Linux: tun。

use thiserror::Error;

#[derive(Debug, Error)]
pub enum PlatformError {
    #[error("adapter error: {0}")]
    Adapter(String),
    #[error("route error: {0}")]
    Route(String),
    #[error("dns error: {0}")]
    Dns(String),
}

pub mod adapter;
pub mod netcfg;
pub mod route;

#[cfg(test)]
mod netcfg_tests {
    use super::netcfg::*;
    use std::sync::Arc;

    #[test]
    fn dry_run_route_apply_and_revert() {
        let dry = DryRunRunner::new();
        let mut mgr = RouteManager::new(Arc::new(dry.clone()), "10.111.222.1", "mp-tun");
        mgr.add_route("10.3.130.0/24").unwrap();
        mgr.add_route("192.168.88.0/24").unwrap();
        mgr.revert().unwrap();
        let log = dry.log();
        // 当前为 Windows 平台：add_route 先清同前缀旧路由，revert 再逆序删除
        assert!(log[0].starts_with("route delete 10.3.130.0"));
        assert!(log[1].starts_with("route add 10.3.130.0 mask 255.255.255.0 10.111.222.1 metric 25"));
        assert!(log[2].starts_with("route delete 192.168.88.0"));
        assert!(log[3].starts_with("route add 192.168.88.0 mask 255.255.255.0"));
        assert!(log[4].starts_with("route delete 192.168.88.0"));
        assert!(log[5].starts_with("route delete 10.3.130.0"));
        assert_eq!(log.len(), 6);
        // 幂等：无路由/DNS 残留时 revert 不再执行命令
        mgr.revert().unwrap();
        assert_eq!(dry.log().len(), 6);
    }

    #[test]
    fn dry_run_dns_set_and_restore() {
        let dry = DryRunRunner::new();
        let mut mgr = RouteManager::new(Arc::new(dry.clone()), "10.111.222.1", "Array VPN");
        mgr.set_dns(&["10.91.16.1".into(), "10.91.16.2".into()]).unwrap();
        mgr.revert().unwrap();
        let log = dry.log();
        assert!(log[0].contains("set dns") && log[0].contains("10.91.16.1"));
        assert!(log[1].contains("add dns") && log[1].contains("10.91.16.2"));
        assert!(log.last().unwrap().contains("source=dhcp"));
    }

    #[test]
    fn rejects_empty_dns_and_bad_cidr() {
        let mut mgr = RouteManager::new(Arc::new(DryRunRunner::new()), "10.111.222.1", "tun");
        assert!(mgr.set_dns(&[]).is_err());
        assert!(mgr.add_route("bad-cidr").is_err());
    }
}
