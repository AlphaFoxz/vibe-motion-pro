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

- [x] Ghidra 反编译 vpnd.exe：`/vpntunnel` 请求/响应格式、认证字段、cookie 处理 → **已完成，见 ghidra-tasks.md T2/T5**
- [x] Ghidra 反编译 vl3vpn.dll：隧道包封装格式、keepalive 报文、MTU/TAF 结构 → **T1/T3/T4/T6 完成（2026-11-14，Ghidra 12.2 headless 自动化）**
- [x] vpnhwidtool_x64.exe 全量反编译（HWID/clientid 生成链，T5 结论；2026-11-14）
- [x] ArrayWGClient.exe 反编译（ObfuscateKey/ObfuscateTCP/TLS 伪装，T7；2026-11-14）—— 密钥流 cipher 细节暂缓（WG 模式生产未启用）
- [ ] Wireshark 抓包（TCP 隧道 + UDP 隧道 + WG 各一次）印证：重点核 UDP 握手报文与 "200 OK"、服务端 UDP 端口下发键、201 JSON 配置键名
- [ ] FUN_1005ae50/b090/b220（'U' JSON 的 DNS/WINS/search-domain 键名）—— 随抓包一并确认

## 已确认协议事实（Ghidra 逆向，详见 ghidra-tasks.md）

- **数据面无封装**：TLS/DTLS/UDP 承载背靠背裸 IPv4/IPv6 包；IPv4 总长 +2 BE、IPv6 载荷长 +4 BE（总长+40）；**TLS 之外无压缩/二次加密**
- **keepalive = 伪 IPv4 包**：20B，`45 00 00 14`，TTL=0 / 协议号 255 / 校验和 0，+12 计数(1)、+14 当日毫秒时间戳、+18 隧道类型(0/2)；默认 30s、3 次无响应重连
- **伪 IP 控制帧子类型（+12 BE，协议 255）**：1=keepalive、4=udp clientid（52B 带 36B clientid）、5=关闭 speed tunnel
- **/vpntunnel 请求**：`GET /prx/000/http/localhost/vpntunnel HTTP/1.1` + Cookie + appid/clientid/cpuid/hostname 等；200=二进制模式、201=JSON 协议、302 拒绝
- **16B 配置帧**：`[0]=类型字符（P 请求/Q 通用配置/U 网络配置）[4]=载荷长度`，载荷为 JSON；200 分支则读 56B 公共配置块 + hostmap 流 + launch/disconnect 命令流（`{4B BE len, 数据}` 重复）
- **hostmap 条目**：`{4B BE 域名长, 4B IPv4（0=虚 IP）, 域名}`；launch/disconnect 命令：`{4B BE 长, 命令串}`，各 ≤16 条（服务端可下发命令，重写需策略化）
- **UDP 速度隧道三形态**：明文 UDP（4B 轻信封头 `[flag,(len+12)/8,p[3]^p[0],p[3]]`）/ 会话密钥 XOR / DTLS；握手 = 明文 `clientid+enc+num` → 明文 `"200 OK"`；端口纯配置驱动无协商
- **clientid/HWID**：clientid/devid = 62 字符表随机串（兜底 `BFBFFBFB000101A1A1D4589C69D897A6D92A`），持久化 `HKCU\Software\MotionPro\L3VPN\*`；HWID = vpnhwidtool_x64.exe 生成写 ClientID（`<HWID>|<extra>` 取前缀）；method 字段可含 `UnresolvedFlag=<int>`
- **WG TCP 混淆**（TunSafe 分支）：`obf_key=BLAKE2s(seed32‖ObfuscateKey)`，包 = TLS1.2 record（`17 03 03 + len`）包装 + 伪 ClientHello（SNI `enabled.tls13.com`，模式 default/tls-firefox/tls-chrome）
- **MTU/TAF**：INI `[Global_Configuration]`：VNIC_MTU∈[576,1472]、TAF=VNIC_TCP_ACK_Frequency∈[1,32]、L3VPNTunnelDispatchRule∈[0,4]

## 重写映射更新

- ~~lwIP 类数据面 + MPFR 帧占位~~ → `mp-core::frame::PacketStream`（裸 IP 切包器 + 伪 IPv4 keepalive，已实现）
