# 真机协议实测记录（2026-11-13，一天打通全链路）

本文档记录当天对真实网关（宝武 ArrayOS94）逐层打通过程中实证的协议细节。
所有结论都有真机日志或字节转储佐证，与 `docs/ghidra-tasks.md` 的静态逆向互补。

## 1. TLS 层

- **强制 TLS 1.2**：网关对 TLS 1.3"握手成功但请求装死"（原版 INI `TLSV_12=true` 实证）
- **ALPN `http/1.1` 必须声明**：前端是 `Reverse Proxy Server/2.8.1`，无 ALPN 时按 HTTP/2 语义丢弃 HTTP/1.1 文本（curl 对照 0.24s 返回 200 定位）
- **禁用会话复用**：AG 网关 resume 后的连接会被 RST（10054）
- 响应体为 `Transfer-Encoding: chunked`（无 Content-Length）

## 2. 登录（两跳）

1. **门户**（vpn.baowugroup.com）：`GET /` 种会话 → `GET /restservice/vpnLogin/getImage?d=&uuid=`（预校验前置，浏览器流程必经）→ `POST /restservice/vpnLogin/nextVpnNumberPhone`（`t=t&userCode=&pwd=&code=`）→ 期望 `{"message":"Success"}`
2. **AG 网关**（表单 action 解析自门户首页，vpntoken.baosteel.com）：`POST /prx/000/http/localhost/login`（`method=test&uname=&pwd=&authCode=`）→ 302 → `/welcome` + `ANsession<ts>` cookie

注意：POST 请求头必须以空行 `\r\n\r\n` 终止（缺失时服务器永远等待更多头）。

## 3. 隧道握手（AG 网关，同 cookie）

- `GET /prx/000/http/localhost/vpntunnel`，头：`Cookie: ANStandalone=true;<ANsession>`、`x-devtype`、`appid: SSPVPN`、`clientid`、`cpuid`、`hostname`、**`PAYLOAD-IP-VERSION: 6`（无条件携带——网关的载荷转发开关，缺失时控制帧正常但单播数据被静默丢弃）**
- 200（Server: ArrayOS94）后进入二进制帧模式：
  - 16B 帧头：`[0]=类型字符`，**长度字段在 `[12..16]`（LE）**（不是 [4..8]）
  - `P`（空载荷）→ `Q`（56B 二进制通用配置，内容待解析）
  - `T`（48B：本机 IP×5 + MAC）→ `U`（网络配置）
- **'U' 载荷 = JSON（带 tab/换行缩进，尾带 1 个 NUL 填充字节，解析前必须剔除）**：

```jsonc
{
  "resource_group_flag": 8,
  "client_ipv4": 1599363850,       // 小端 u32：to_le_bytes → 10.91.x.x
  "client_ipv4_mask": 15794175,    // → 255.255.240.0
  "include_network_resource": { "ipv4": [{"ip":..LE,"mask":..LE,"protocol":4,"port_type":2,"ports":[0,65535,0,0,0]}] },
  "exclude_network_resource": {...},
  "dns_servers": [{"ipv4": [..LE, ..LE]}]
}
```

- 未带 PAYLOAD-IP-VERSION 时 'U' 只有 1812B 截断 JSON（帧头声明 3548），全量 10986B

## 4. 数据面

- **裸 IP 直传**（无封装头），背靠背流式；解帧按 IPv4 总长/IPv6 载荷长切分
- **心跳 = 20B 伪 IPv4 包**（`45 00 00 14`，TTL=0、协议号 255、count=1、当日毫秒时间戳、隧道类型），**间隔 ~200ms**（原版 pktmon 实测 4.4/s；服务器 15s 无心跳判死）
- 网关对心跳/广播包回 `ICMP type=11`（TTL 超时，src=2.255.255.253）属正常现象，勿当作错误
- MTU 1400

## 5. Windows 系统集成（真机踩坑集）

- `route add` 参数必须逐个独立传递：合并 `addr mask x.x.x.x` 成一个参数时 route.exe 解析失败**且退出码仍为 0**（静默无路由）
- 路由必须显式 `if <索引>` 绑定 TUN：wintun IP 注册有竞态，否则路由落到物理网卡
- 装路由前先删同前缀旧路由：会话残留会与当前路由竞争（表现为 ping 时通时不通）
- wintun.dll 需随构建部署到 exe 旁（build.rs 自动拷贝，入库于 `crates/mp-daemon/wintun/`）
- Windows 新 TUN 网卡会自发 IPv6 ND / LLMNR / mDNS 广播进隧道，属噪音

## 6. 遗留事项

- [ ] Q 帧 56B 二进制配置解析（MTU/能力位图？）
- [ ] TLS 严格证书校验（rootca pinning，替换 NoVerify）
- [ ] DNS 接管验证（U 帧已下发 10.250.243.11/.10，set_dns 已调用未真机验证域名解析）
- [ ] 断开时路由/DNS 回滚的边界情况（daemon 被杀时残留）
- [ ] HWID（cpuid 头）算法：vpnhwidtool_x64.exe 未分析
- [ ] 心跳 miss 上限与重连策略调优（当前 200ms×225）
