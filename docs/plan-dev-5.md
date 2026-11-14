# dev-5 实施记录：端到端隧道链路（协议 → 数据面闭环）

日期：2026-11-14　状态：完成（workspace 75 测试全绿）

## 前置

Ghidra 逆向（T1-T6）全部完成（见 ghidra-tasks.md），关键结论：
数据面 = TLS 上的**裸 IP 包流**（零封装），keepalive = 协议号 255 的伪 IPv4 包。
架构修正：原版是**纯 L3 转发**（用户态栈不终结内层 TCP），smoltcp 终结方案降级为备选。

## 交付

### mp-core
- `protocol.rs`：
  - `VPNTUNNEL_PATH` 修正为 `/prx/000/http/localhost/vpntunnel`；keepalive 常量修正（30s × 3，废除 200ms 假设）
  - `vpntunnel_request(host, TunnelOpenParams)`：完整请求头（Cookie ANStandalone / x-devtype / appid / clientid / cpuid / hostname / PAYLOAD-IP-VERSION）
  - 16B 配置帧编解码（`encode/decode_config_frame`，类型 P/Q/U，长度 LE u32 @ +4，TODO 抓包对齐端序）
  - postlogin apps schema：`SiteConfig`（22 字段）+ `WgConfig` + `PostloginApps`
- `control.rs`：`ControlClient::open_tunnel` —— TLS 握手 → 200/201/302 分流 → P→Q 配置帧交换
  → 返回数据模式流 + 配置 JSON + **先导字节**（同 record 到达的早期数据包，修过的死锁点）
- `tunnel.rs`（新）：
  - `Wire` trait（同步字节流抽象）+ `pump_once`（同步泵）
  - `pump_async`（生产路径）：tokio select 多路复用隧道读 / TUN 读 / keepalive 定时
  - `KeepaliveState`：对齐原版 select 循环（间隔内无响应 → miss → max_attempts → Dead）
  - `TunnelStats`：对齐原版收发计数器

### mp-daemon
- `netloop.rs`：`TunnelPump` —— open_tunnel 返回的流 + leftover → ChannelAdapter（TUN 线程桥），
  优雅 shutdown（5s 超时）返回最终结果（Ok / Dead / Io）

## 测试

- mp-core 56：帧/切包/keepalive 单测 + mock-TLS 握手端到端（含 302 拒绝、数据模式回环）+ duplex 异步泵双向
- mp-daemon 7：TunnelPump 端到端（下行→TUN、上行→隧道回显、leftover 先导消费）

## 数据通路（已闭环）

```
TUN 网卡 ⇄ ChannelAdapter ⇄ pump_async ⇄ TLS 流 ⇄ 网关
              （裸 IP 包，零封装；keepalive=伪 IPv4 proto 255）
```

## 遗留

- 端到端真机联调（需真实网关 + 管理员权限开网卡）
- 'U' 网络配置帧的请求时序（0x30B 请求体）与路由下发对接
- TLS 严格证书校验（rootca pinning）
- HWID（vpnhwidtool_x64.exe）/ WG ObfuscateKey 算法逆向
