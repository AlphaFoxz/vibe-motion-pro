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

/// Windows 路由命令：`route add <addr> mask <mask> <gw> metric <n> if <idx>`。
/// 注意：
/// - addr/mask 必须是独立参数——合并成一个带空格的参数会被引号包裹，
///   route.exe 解析失败但**退出码仍为 0**（真机踩坑：静默无路由）。
/// - 必须显式 `if <idx>`——wintun IP 注册有竞态，缺省时 Windows 可能把网关
///   解析到物理网卡上（真机踩坑：路由落在 WLAN 接口，包全被 WLAN 网关拒收）。
pub fn windows_route_add(
    cidr: &str,
    gateway: &str,
    metric: u16,
    if_index: Option<u32>,
) -> Result<Vec<String>, RouteError> {
    let (addr, prefix) = validate_cidr(cidr)?;
    let gw = validate_ip(gateway)?;
    let mask = prefix_to_mask(prefix);
    let mut argv = vec![
        "route".to_string(),
        "add".to_string(),
        addr,
        "mask".to_string(),
        mask,
        gw,
        "metric".to_string(),
        metric.to_string(),
    ];
    if let Some(idx) = if_index {
        argv.push("if".to_string());
        argv.push(idx.to_string());
    }
    Ok(argv)
}

/// 解析适配器接口索引。Win32 GetAdaptersAddresses 直查（零子进程）：
/// 真机冻结实证（freeze_auto.txt）—— 在 async 线程 spawn `route print` 73 次，
/// 管道读取 WaitForMultipleObjects 永久挂起。API 调用 <1ms，失败返回 None。
#[cfg(target_os = "windows")]
pub fn windows_if_index(interface: &str) -> Option<u32> {
    use windows_sys::Win32::NetworkManagement::IpHelper::{
        GetAdaptersAddresses, GAA_FLAG_SKIP_ANYCAST, GAA_FLAG_SKIP_MULTICAST,
        GAA_FLAG_SKIP_UNICAST, IP_ADAPTER_ADDRESSES_LH,
    };
    use windows_sys::Win32::Networking::WinSock::AF_INET;

    const FLAGS: u32 =
        GAA_FLAG_SKIP_UNICAST | GAA_FLAG_SKIP_ANYCAST | GAA_FLAG_SKIP_MULTICAST;
    unsafe {
        let mut size: u32 = 0;
        // 第一次调用取所需缓冲大小（预期返回 ERROR_BUFFER_OVERFLOW）
        GetAdaptersAddresses(
            AF_INET as u32,
            FLAGS,
            std::ptr::null_mut(),
            std::ptr::null_mut(),
            &mut size,
        );
        if size == 0 {
            return None;
        }
        let mut buf = vec![0u8; size as usize];
        let rc = GetAdaptersAddresses(
            AF_INET as u32,
            FLAGS,
            std::ptr::null_mut(),
            buf.as_mut_ptr() as *mut IP_ADAPTER_ADDRESSES_LH,
            &mut size,
        );
        if rc != 0 {
            tracing::warn!("GetAdaptersAddresses failed: {rc}");
            return None;
        }
        let mut cur = buf.as_ptr() as *const IP_ADAPTER_ADDRESSES_LH;
        while !cur.is_null() {
            let a = &*cur;
            if !a.FriendlyName.is_null() {
                let mut len = 0usize;
                while *a.FriendlyName.add(len) != 0 {
                    len += 1;
                }
                let name = String::from_utf16_lossy(std::slice::from_raw_parts(
                    a.FriendlyName,
                    len,
                ));
                if name.eq_ignore_ascii_case(interface) {
                    return Some(a.Anonymous1.Anonymous.IfIndex);
                }
            }
            cur = a.Next as *const IP_ADAPTER_ADDRESSES_LH;
        }
    }
    None
}

#[cfg(not(target_os = "windows"))]
pub fn windows_if_index(_interface: &str) -> Option<u32> {
    None
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

/// Linux `ip route replace <cidr> via <gw> dev <if>`（replace 幂等：前次会话
/// 残留路由直接被覆盖，无需像 Windows 那样先删后加）。
pub fn linux_route_add(cidr: &str, gateway: &str, dev: &str) -> Result<Vec<String>, RouteError> {
    let (addr, prefix) = validate_cidr(cidr)?;
    let gw = validate_ip(gateway)?;
    Ok(vec![
        "ip".into(),
        "route".into(),
        "replace".into(),
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

/// Linux 删除路由：`ip route del <cidr> dev <if>`。
pub fn linux_route_delete(cidr: &str, dev: &str) -> Result<Vec<String>, RouteError> {
    let (addr, prefix) = validate_cidr(cidr)?;
    Ok(vec!["ip".into(), "route".into(), "del".into(), format!("{addr}/{prefix}"), "dev".into(), dev.into()])
}

/// macOS 删除路由：`route -n delete -net <cidr>`。
pub fn macos_route_delete(cidr: &str) -> Result<Vec<String>, RouteError> {
    let (addr, prefix) = validate_cidr(cidr)?;
    Ok(vec!["route".into(), "-n".into(), "delete".into(), "-net".into(), format!("{addr}/{prefix}")])
}

/// macOS DNS：`networksetup -setdnsservers <svc> <dns...>`（多值；还原用 empty）。
/// 注意 svc 是网络服务名（如 "Wi-Fi"）而非接口名 —— 见 netcfg::MacosBackend 注释。
pub fn macos_set_dns(service: &str, servers: &[String]) -> Result<Vec<String>, RouteError> {
    for s in servers {
        validate_ip(s)?;
    }
    let mut argv = vec!["networksetup".into(), "-setdnsservers".into(), service.into()];
    argv.extend(servers.iter().cloned());
    Ok(argv)
}

/// macOS DNS 还原为自动（DHCP）。
pub fn macos_reset_dns(service: &str) -> Vec<String> {
    vec!["networksetup".into(), "-setdnsservers".into(), service.into(), "empty".into()]
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
        let cmd = windows_route_add("10.3.130.0/24", "10.91.16.1", 25, Some(16)).unwrap();
        assert_eq!(
            cmd.join(" "),
            "route add 10.3.130.0 mask 255.255.255.0 10.91.16.1 metric 25 if 16"
        );
        let no_if = windows_route_add("10.3.130.0/24", "10.91.16.1", 25, None).unwrap();
        assert_eq!(
            no_if.join(" "),
            "route add 10.3.130.0 mask 255.255.255.0 10.91.16.1 metric 25"
        );
        assert!(windows_route_add("bad/24", "10.91.16.1", 25, None).is_err());
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
        assert_eq!(l.join(" "), "ip route replace 10.3.130.0/24 via 10.91.16.1 dev tun0");
        let m = macos_route_add("10.3.130.0/24", "10.91.16.1").unwrap();
        assert_eq!(m.join(" "), "route -n add -net 10.3.130.0/24 10.91.16.1");
    }
}
