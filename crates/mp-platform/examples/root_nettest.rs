//! Linux root 真机验证（WSL/Ubuntu）：网卡创建 → 路由/DNS 接管 → 校验 → 回滚。
//!
//! 这是平台层与内核的真实交互测试（区别于 DryRun/MemoryFs 单测）：
//! - tun 设备真实创建/命名/配地址，Drop 后设备消失
//! - RouteManager 走真实子进程（ip route replace / resolvectl），前后状态可查
//! - 断言失败 panic 非零退出；全过打印 NETTEST PASS
//!
//! 运行：sudo ./root_nettest（scripts/wsl-root-nettest.sh 封装了构建与提权）。
//! 仅 Linux；无 root 直接失败退出（不降级——降级测不到东西）。

use mp_platform::adapter::{TunConfig, TunAdapter};
use mp_platform::netcfg::{RouteManager, SystemRunner};
use std::sync::Arc;

fn sh(cmd: &str) -> String {
    let out = std::process::Command::new("sh")
        .arg("-c")
        .arg(cmd)
        .output()
        .unwrap_or_else(|e| panic!("spawn sh: {e}"));
    let text = format!(
        "{}{}",
        String::from_utf8_lossy(&out.stdout),
        String::from_utf8_lossy(&out.stderr)
    );
    if !out.status.success() {
        panic!("`{cmd}` exited {:?}: {text}", out.status.code());
    }
    text
}

fn check(cond: bool, what: &str) {
    if !cond {
        panic!("CHECK FAILED: {what}");
    }
    println!("  ok: {what}");
}

fn main() {
    println!("== root_nettest ==");
    check(sh("id -u").trim() == "0", "running as root");

    // 1) 网卡创建（请求名 mp-tun / 10.111.222.1/24 / mtu 1400）
    let cfg = TunConfig {
        name: "mp-tun".into(),
        address: "10.111.222.1".parse().unwrap(),
        netmask: "255.255.255.0".parse().unwrap(),
        mtu: 1400,
    };
    let adapter = TunAdapter::open(&cfg).expect("TunAdapter::open");
    let actual = adapter.actual_name().expect("actual_name");
    println!("  adapter created, actual_name = {actual}");
    check(actual == "mp-tun", "linux honors requested name mp-tun");
    check(
        sh("ip link show mp-tun").contains("mp-tun"),
        "ip link shows mp-tun",
    );
    check(
        sh("ip -4 addr show dev mp-tun").contains("10.111.222.1"),
        "address 10.111.222.1 assigned",
    );

    // 2) 路由 + DNS 接管（真实子进程；resolved 在跑则走 resolvectl 路径）
    let mut mgr = RouteManager::new(Arc::new(SystemRunner), "10.111.222.1", "mp-tun");
    mgr.add_route("10.3.130.0/24").expect("add_route");
    mgr.set_dns(&["10.91.16.1".into(), "10.91.16.2".into()]).expect("set_dns");
    let route_show = sh("ip route show dev mp-tun");
    check(
        route_show.contains("10.3.130.0/24") && route_show.contains("10.111.222.1"),
        "route 10.3.130.0/24 via 10.111.222.1 installed",
    );
    let resolved_active = std::path::Path::new("/run/systemd/resolve").exists();
    println!("  systemd-resolved active: {resolved_active}");
    if resolved_active {
        let dns_show = sh("resolvectl dns mp-tun");
        check(
            dns_show.contains("10.91.16.1") && dns_show.contains("10.91.16.2"),
            "resolvectl dns mp-tun carries both servers",
        );
    } else {
        let rc = sh("cat /etc/resolv.conf");
        check(
            rc.contains("nameserver 10.91.16.1") && rc.contains("nameserver 10.91.16.2"),
            "resolv.conf rewritten with both servers",
        );
    }

    // 3) 回滚（网卡仍开着：路由应被显式删除）
    mgr.revert();
    check(
        !sh("ip route show dev mp-tun").contains("10.3.130.0/24"),
        "route removed after revert",
    );
    if resolved_active {
        check(
            !sh("resolvectl dns mp-tun").contains("10.91.16."),
            "resolvectl dns reverted",
        );
    }
    drop(mgr);

    // 4) 网卡生命周期：Drop 即设备消失（fd 关闭，内核回收）
    drop(adapter);
    let gone = std::process::Command::new("sh")
        .arg("-c")
        .arg("ip link show mp-tun")
        .output()
        .unwrap();
    check(!gone.status.success(), "tun device gone after drop");

    println!("NETTEST PASS");
}
