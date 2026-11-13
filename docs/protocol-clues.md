# MotionPro v1.2.26 逆向线索笔记

来源：`reference/binaries/` 静态分析（objdump 导出表 + strings），2024-01 构建。
待办：Ghidra/IDA 深度反编译、Wireshark 动态抓包印证。

## 组件全景

| 组件 | 技术 | 职责 |
|---|---|---|
| MotionPro.exe | Qt5 C++ (VS2013) | UI/托盘，通过 `ArrayVPNApi.dll` 操控 |
| ArrayVPNApi.dll | C++ (VS2010，PDB: `D:\code\vs2010\out\pdb\ArrayVPNApi.pdb`) | 客户端 API 层，启动/查询 vpnd |
| vpnd.exe | C++ | VPN 守护进程，SSL/UDP 隧道会话 |
| vl3vpn.dll | C (lwIP + `l3vpn\udp_tunnel.c`) | L3 数据面：虚拟网卡、TCP/UDP/DTLS 隧道、DNS |
| InsideProxy.exe | ATL C++ | 本地代理转发（SSL transport、Basic/NTLM 上游代理认证） |
| ArrayWGClient.exe | TunSafe 分支（PDB: `D:\tongjj\ag_client_pc_trunk_wg\wireguard\TunSafe-master\...`） | WireGuard（含 TCP 混淆 `ObfuscateKey`） |
| MotionProHttpd.exe | - | 本地 web portal（9090 端口 appicon 等查询） |

## ArrayVPNApi.dll 导出 API（57 个，完整清单）

生命周期：`ArrayStartVPNClient(W|NoDrive|W_WG)` / `ArrayStopVPNClient(NoDrive)` / `ArrayStopProcessByNameW`
状态：`ArrayGetVPNRunningStatus(W|NoDrive)` / `ArrayGetVPNSession(W)` / `ArrayGetVPNErrorInfo(W)` / `ArrayMonitorKeepaliveStatus`
隧道配置：`ArrayGet/SetMTUAndTunnelRule(NoDriver)` / `ArrayGet/SetMTUAndTAF` / `ArraySetAccessMode` / `ArraySetDomainList(W)` / `ArrayGetNetworkInfo`
UDP：`ArrayGetUDPTunnelRunningStatus(W)` / `ArrayEnableDebugModeNoDriver`
重连：`ArraySetReconnectParameters(NoDriver)` / `ArraySetWaittingTimesNoDriver`
保活：`ArraySetKeepaliveOption`
SSL：`ArrayGet/SetSSLProtocolValue` / `ArrayGetSSLProtocolValue` / `ArrayVerifyServerCert(W)`
证书：`ArraySetClientCertAuthRule`
代理：`ArraySetIEProxySettingsW` / `ArrayEnableDNSProxy`
WG：`ArrayGetWireGuardList`
AAA：`ArrayGetAAAMethodInfo` / `ArraySetAAAMethodNameW`
其他：`ArrayGetClientPublicIP` / `ArraySetMPFlag` / `ArraySetSessionReuse` / `ArrayEnableRSAAutomation` / `ArrayGetRSAAutomationStatus` / `ArrayClearUserModeVPNAdapter` / `ArrayResumeUserModeVPNAdapter` / `ArrayDisableAdapter` / `ArrayLoggerPrint` / `ArrayVPNStatusForceResume`

## 协议线索（字符串证据）

- **隧道建立**：`GET %s/vpntunnel HTTP/1.1` —— HTTPS 上的 HTTP 端点 `/vpntunnel`
- **会话**：`session_id`、`MPWebNoSession`、会话过期/顶号逻辑（"user login again, current session will be terminated"）
- **参数**：`sslproto`、`sslerror`、`tunneltype`（vpnd 消息含 host/port/server type/ssl proto）
- **隧道类型**：TCP 隧道（lwIP 栈）、UDP 隧道（`udp_tunnel.c`，可由注册表/`Disable_UDP_Tunnel.reg` 关闭）、DTLS（`DTLS SPEED TUNNEL`）、WireGuard（TunSafe TCP 混淆）
- **路由**：full tunnel / split tunnel（`Include Zone:ip=..., this is full tunnel`、ipv6 支持）
- **DNS**：dnsproxy 开关、静态 DNS host、lwIP dns.c
- **保活**：`send_tcp_tunnel_keep_alive`、RTT 测速
- **Web portal 代理路径**：`/prx/000/http/...`、`/prx/000/https/`、`mp_redirect`、`client_sec/l3vpn/`
- **内核驱动**：`SSL VPN Driver`（注册表 `SSL VPN Client\WebVPN.exe`）、另有 NoDriver（用户态 TAP）模式

## 重写映射（Rust 实现规划）

| 原组件 | Rust 重写 |
|---|---|
| ArrayVPNApi.dll | `core` crate 公开同语义 API（Start/Stop/Status/Session/Reconnect…） |
| vpnd.exe SSL/TCP 隧道 | `core` + `daemon`：rustls TLS + `/vpntunnel` HTTP 握手 + lwIP 类数据面（可用 smoltcp） |
| UDP/DTLS 隧道 | quinn/DTLS（rustls + webrtc-dtls 或 openssl-binding） |
| ArrayWGClient | 直接调用官方 wireguard-go / embed-go，或 boringtun（注意 TCP 混淆需自实现 ObfuscateKey 层） |
| vl3vpn 虚拟网卡 | wintun / utun / tun crate + 路由/DNS 接管 |
| InsideProxy | 本地 SOCKS/HTTP 代理转发模块 |
| MotionPro.exe | Tauri 2 UI |

## 下一步逆向任务

- [ ] Ghidra 反编译 vpnd.exe：`/vpntunnel` 请求/响应格式、认证字段、cookie 处理
- [ ] Ghidra 反编译 vl3vpn.dll：隧道包封装格式、keepalive 报文、MTU/TAF 结构
- [ ] Wireshark 抓包（TCP 隧道 + UDP 隧道 + WG 各一次）印证
- [ ] 确认 ObfuscateKey（TunSafe TCP 混淆）算法与服务器开关
