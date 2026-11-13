//! 路由 / DNS 管理命令构造（各平台）。
//!
//! 安全设计：命令以「构造 + dry-run 校验」两段式提供；
//! 实际执行由特权 daemon 调用（main 流程），单元测试只验证拼装结果。

use thiserror::Error;

#[derive(Debug, Error, PartialEq)]
pub enum RouteError {
    #[error("invalid cidr: {0}")]
    InvalidCidr(String),
    #[error("invalid ip: {0}")]
    InvalidIp(String),
    #[error("unsupported platform")]
    UnsupportedPlatform,
}

/// 校验 CIDR（a.b.c.d/p）。
pub fn validate_cidr(cidr: &str) -> Result<(String, u8), RouteError> {
    let (addr, prefix) = cidr.split_once('/').ok_or_else(|| RouteError::InvalidCidr(cidr.to_string()))?;
    let prefix: u8 = prefix.parse().map_err(|_| RouteError::InvalidCidr(cidr.to_string()))?;
    if prefix > 32 {
        return Err(RouteError::InvalidCidr(cidr.to_string()));
    }
    addr.parse::<std::net::Ipv4Addr>()
        .map(|a| (a.to_string(), prefix))
        .map_err(|_| RouteError::InvalidCidr(cidr.to_string()))
}

/// 校验 IP。
pub fn validate_ip(ip: &str) -> Result<String, RouteError> {
    ip.parse::<std::net::Ipv4Addr>()
        .map(|a| a.to_string())
        .map_err(|_| RouteError::InvalidIp(ip.to_string()))
}

/// Windows 路由命令：`route add <cidr> <gateway> metric <n>`。
pub fn windows_route_add(cidr: &str, gateway: &str, metric: u16) -> Result<Vec<String>, RouteError> {
    let (addr, prefix) = validate_cidr(cidr)?;
    let gw = validate_ip(gateway)?;
    let mask = prefix_to_mask(prefix);
    Ok(vec![
        "route".into(),
        "add".into(),
        format!("{addr} mask {mask}"),
        gw,
        "metric".into(),
        metric.to_string(),
    ])
}

/// Windows 删除路由。
pub fn windows_route_delete(cidr: &str) -> Result<Vec<String>, RouteError> {
    let (addr, prefix) = validate_cidr(cidr)?;
    let mask = prefix_to_mask(prefix);
    Ok(vec!["route".into(), "delete".into(), format!("{addr} mask {mask}")])
}

/// Windows DNS 设置：`netsh interface ip set dns name=<if> static <dns>`。
pub fn windows_set_dns(interface: &str, dns_server: &str) -> Result<Vec<String>, RouteError> {
    let dns = validate_ip(dns_server)?;
    Ok(vec![
        "netsh".into(),
        "interface".into(),
        "ip".into(),
        "set".into(),
        "dns".into(),
        format!("name=\"{interface}\""),
        "static".into(),
        dns,
    ])
}

/// Windows DNS 还原为 DHCP。
pub fn windows_reset_dns(interface: &str) -> Vec<String> {
    vec![
        "netsh".into(),
        "interface".into(),
        "ip".into(),
        "set".into(),
        "dns".into(),
        format!("name=\"{interface}\""),
        "source=dhcp".into(),
    ]
}

/// 前缀长度 → 子网掩码。
pub fn prefix_to_mask(prefix: u8) -> String {
    let v = if prefix == 0 { 0u32 } else { (!0u32).checked_shl(32 - prefix as u32).unwrap_or(0) };
    let b = v.to_be_bytes();
    format!("{}.{}.{}.{}", b[0], b[1], b[2], b[3])
}

/// Linux `ip route add <cidr> via <gw> dev <if>`。
pub fn linux_route_add(cidr: &str, gateway: &str, dev: &str) -> Result<Vec<String>, RouteError> {
    let (addr, prefix) = validate_cidr(cidr)?;
    let gw = validate_ip(gateway)?;
    Ok(vec![
        "ip".into(),
        "route".into(),
        "add".into(),
        format!("{addr}/{prefix}"),
        "via".into(),
        gw,
        "dev".into(),
        dev.into(),
    ])
}

/// macOS `route -n add -net <cidr> <gw>`。
pub fn macos_route_add(cidr: &str, gateway: &str) -> Result<Vec<String>, RouteError> {
    let (addr, prefix) = validate_cidr(cidr)?;
    let gw = validate_ip(gateway)?;
    Ok(vec![
        "route".into(),
        "-n".into(),
        "add".into(),
        "-net".into(),
        format!("{addr}/{prefix}"),
        gw,
    ])
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn cidr_validation() {
        assert!(validate_cidr("10.25.64.0/24").is_ok());
        assert_eq!(validate_cidr("10.25.64.0/33"), Err(RouteError::InvalidCidr("10.25.64.0/33".into())));
        assert_eq!(validate_cidr("10.25.64.0"), Err(RouteError::InvalidCidr("10.25.64.0".into())));
        assert_eq!(validate_cidr("999.1.1.0/8"), Err(RouteError::InvalidCidr("999.1.1.0/8".into())));
    }

    #[test]
    fn mask_conversion() {
        assert_eq!(prefix_to_mask(8), "255.0.0.0");
        assert_eq!(prefix_to_mask(24), "255.255.255.0");
        assert_eq!(prefix_to_mask(30), "255.255.255.252");
        assert_eq!(prefix_to_mask(32), "255.255.255.255");
        assert_eq!(prefix_to_mask(0), "0.0.0.0");
    }

    #[test]
    fn windows_route_add_format() {
        let cmd = windows_route_add("10.3.130.0/24", "10.91.16.1", 25).unwrap();
        assert_eq!(
            cmd.join(" "),
            "route add 10.3.130.0 mask 255.255.255.0 10.91.16.1 metric 25"
        );
        assert!(windows_route_add("bad/24", "10.91.16.1", 25).is_err());
    }

    #[test]
    fn windows_route_delete_format() {
        let cmd = windows_route_delete("10.3.130.0/24").unwrap();
        assert_eq!(cmd.join(" "), "route delete 10.3.130.0 mask 255.255.255.0");
    }

    #[test]
    fn dns_commands() {
        let cmd = windows_set_dns("Array Networks VPN Adapter", "10.91.16.1").unwrap();
        assert_eq!(cmd[0], "netsh");
        assert!(cmd.iter().any(|s| s.contains("Array Networks VPN Adapter")));
        assert_eq!(cmd.last().unwrap(), "10.91.16.1");
        let reset = windows_reset_dns("eth0");
        assert!(reset.iter().any(|s| s == "source=dhcp"));
        assert!(windows_set_dns("eth0", "not-an-ip").is_err());
    }

    #[test]
    fn unix_route_formats() {
        let l = linux_route_add("10.3.130.0/24", "10.91.16.1", "tun0").unwrap();
        assert_eq!(l.join(" "), "ip route add 10.3.130.0/24 via 10.91.16.1 dev tun0");
        let m = macos_route_add("10.3.130.0/24", "10.91.16.1").unwrap();
        assert_eq!(m.join(" "), "route -n add -net 10.3.130.0/24 10.91.16.1");
    }
}
