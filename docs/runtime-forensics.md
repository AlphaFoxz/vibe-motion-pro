# 运行时动态取证（2026-11-13，v1.2.26 原版在线时采集）

来源：ipconfig/route/netstat/tasklist、原版日志（AppData\Local\MotionPro\Log）、注册表、适配器统计。
网络无需管理员权限的采集方式（pktmon/typeperf 均需提权，已记录，若后续需要包级证据需管理员 shell）。

## 实际运行的进程拓扑（比安装包清单更重要）

| 进程 | PID 角色 | 关键点 |
|---|---|---|
| MotionPro.exe | UI | UDP 127.0.0.1:57133；-connectsession 命令行启动（Web 单点登录拉起） |
| vpnd.exe | 守护/状态机 | **监听 127.0.0.1:65432 TCP+UDP**（IPC 总线），每 1 秒轮询 VNIC 状态并广播 |
| VPNService.exe | Windows 服务 | **持有到网关的 TCP 443 长连接**（203.0.113.10，ESTABLISHED）|
| VPNInstallManager.exe | 安装管理服务 | |
| MotionProHttpd.exe | web portal | 监听 127.0.0.1:60012 |
| WebVPN.exe（SSL VPN Client 目录） | PAC/代理脚本 | `-setproxyforvnic` / `-resumeproxyforvnic` |

注意：**l3vpn 库实际上被加载进 MotionPro.exe 进程内**（日志源标签 <MotionPro.exe> 调 l3vpn.c），
vpnd 只做 VNIC/路由/状态广播——与"vpnd 独立建隧道"的旧假设不同。
而 TLS 长连接归属 VPNService.exe（服务进程，会话不随用户注销中断）。

## 会话参数（本机实测）

- 网关：`vpn.example.com` = `203.0.113.10:443`，TLS 1.2（sslProtocol=2）
- 隧道类型：10 (Default) → 解析为 TCP 隧道（`set_udp_tunnel_running_status: 0`，UDP 禁用）
- VNIC：`Array Networks SSL VPN Driver`（另有 TAP-Windows Adapter 备用），adapterType=2
- VNIC IP：10.91.17.175/（网段内网关 10.91.16.1），**split tunnel**：约 30 条 /24-/30 路由（10.25.x、10.3.x 等）全部走 10.91.16.1，metric 25，物理网 metric 45
- DNS：无 dnsproxy（dnsproxy[0]），自定义 DNS 为空
- HTTP Keep-Alive: `timeout=15, max=100`（服务器响应头）

## 认证/会话协议流（日志时序还原）

```
TLS 连接网关 443 (openssl init, TLS1.2, socket 1380)
→ GET /prx/000/http/localhost/an_login.js            # 查询 AAA 认证方式
→ session cookie 复用（"session cookie exist, don't need to login"）
→ GET settings（get_settings_motionpro：bookmark、cs postlogin、cs interval=300）
→ GET /prx/000/http/localhost:65200/motionpro/postlogin/apps?_uname=example_user&_role=&_pid=***&_instid=default
  （返回 2 = 无资源，继续 L3VPN）
→ MotionPro --IPC--> vpnd: VpnStart {host, port=443, server type=2, sslproto=2,
   wg info(site_name/wg_server/wg_name), proxy 配置, devname=主机名}
→ vpnd 驱动 VNIC 连接，状态 1→2（约 11 秒）
→ OnVpnConnected: WebVPN.exe -setproxyforvnic，显示三态
```

- valid string 形如 `validcode=@#motionProweb=1`（Web 拉起登录态透传）
- 状态枚举（route.cpp）：`1 connecting, 2 connected, 3 connect_fail, 4 reconnecting, 5 reconnect_fail, 6 disconnecting, 7 disconnected, -1 unknown`
- vpnd 状态广播：`send message to clients: cmd 1, error 0`，1s 周期
- 重连实测：08:19 断开→reconnecting；17:03→17:05 reconnect failed（≈2 分钟后放弃）

## 包级抓包结论（pktmon, 2026-11-13，49.6s 空闲隧道采样）

- C→S 85 字节 TLS record ×220（去重后）≈ **4.4 包/秒，即 TCP 隧道心跳 ≈ 200ms 间隔**（部分突发 17-35ms，长尾 0.9-4.4s 为空闲期）
- S→C 101 字节 record ×~1270（含重复 tap，去重后约 254）≈ 心跳回应（96B 明文）
- 181/133（S→C）与 170/255/149（C→S）为偶发数据帧
- 载荷为 TLS 加密，**帧内格式需 Ghidra 逆向 vl3vpn.dll 才能确认**（heartbeat 帧明文约 80B）
- 抓包工具链：pktmon（需管理员）→ `pktmon etl2pcap` → 自研 `scripts/parse_pcap.js` / `scripts/analyze_gw.js`（已入库，pktmon 多组件重复捕获需按 seq 去重）

## 密码学栈
- openssl init（libeay32 1.0 系）；TLS12 first priority，带协议降级尝试（Try TLSv1_2_client_method）

## 对重写的影响
1. Rust 侧应把「服务进程持有 TLS 隧道」作为默认架构（mp-daemon ≈ VPNService + vpnd 合并），UI 崩溃不断线。
2. 状态机增加 connect_fail / reconnect_fail / disconnecting 细化态。
3. 认证入口是 `/prx/000/http/localhost/an_login.js` 而非直接 `/vpntunnel`（后者是数据隧道通道），Cookie 是会话核心。
4. IPC 用 127.0.0.1:65432 TCP+UDP 总线；重写可保留 mp-ipc 抽象（实现换成 fixed loopback port + 广播）。
5. 状态轮询 1s + 全局广播，UI 只读状态不参与隧道。

## 待管理员权限补证（需提权 shell）
- pktmon/netsh trace 抓 443 报文：TCP 隧道帧格式、keepalive 间隔实测
- VNIC 驱动层 ioctl（vl3vpn 数据面）
