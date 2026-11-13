# Ghidra 逆向任务清单（数据帧格式攻坚）

> **自动化流水线（2026-11-14 起）**：Ghidra 12.2 headless 全自动分析，无需人工 GUI 操作。
> - 工具：`D:\tools\ghidra_scripts\DumpAnchors.java` + `run-ghidra-dump.ps1`（JDK 25 便携版在 `D:\tools\jdk-25*`）
> - 用法：`powershell -File D:\tools\ghidra_scripts\run-ghidra-dump.ps1 -Binary <dll路径> [-Anchors "a,b"]`
> - 产物：`docs/decomp/<名>.c`（锚点函数 + 一层 caller/callee 的伪 C）

样本：`reference/binaries/`（不入库，内部存储）。本地路径 `reference/binaries/vl3vpn.dll` 等。
使用 Ghidra 打开时建议先跑自动分析（默认即可）。

## 使用方法

- 每个任务给出「锚点字符串 → xrefs → 目标函数 → 需要回答的问题」。
- 完成后把结论写进本文档对应任务的「结论」小节，并同步更新 `docs/protocol-clues.md`。
- 一个任务一次 commit（`docs(ghidra): T# ...`）。

## 优先级总览

| # | 任务 | 价值 | 难度 |
|---|---|---|---|
| T1 | TCP 隧道 keepalive 帧格式 | ★★★ | 低 |
| T2 | /vpntunnel 请求/响应与数据帧封装 | ★★★ | 中 |
| T3 | 隧道数据包（内层 IP 包）封送格式 | ★★★ | 中 |
| T4 | UDP/DTLS 隧道建立与帧格式 | ★★ | 高 |
| T5 | 认证字段与 cookie 名 | ★★ | 低 |
| T6 | MTU/TAF/tunnelRule 结构 | ★ | 低 |

---

## T1 keepalive 帧（入口最浅，先做）

- 锚点字符串：`send_tcp_tunnel_keep_alive`（vl3vpn.dll，出现在失败日志
  "It seems send_tcp_tunnel_keep_alive failed, return tunnel error %d"）
- 步骤：
  1. Search → For Strings → 找到该字符串地址
  2. Show References to XREF → 定位调用函数（即 keepalive 发送函数）
  3. 反编译该函数，回答：
     - [ ] 心跳报文的长度/结构（实测外层 TLS record 85B，明文 ≈80B）
     - [ ] 是否有序号/时间戳字段
     - [ ] keepalive 间隔常量（实测 ≈200ms，找硬编码值）
     - [ ] 服务端回应（101B record）的判断逻辑
- 结论：
  - **帧为 20 字节（0x14）定长明文，经 SSL_write 写入 TLS 隧道**（函数 FUN_10063d70 @ vl3vpn.dll，l3vpn.c 行 0x4e2）：
    | 偏移 | 大小 | 值 | 含义 |
    |---|---|---|---|
    | 0 | 4 | `45 00 00 14` | 0x45 类型标记 + BE 长度 0x0014（=20，自指总长）|
    | 4 | 4 | 0 | 保留/序号（置 0）|
    | 8 | 4 | `00 ff 00 00` | 命令 0xff00（keepalive 操作码）|
    | 12 | 2 | `00 01` (BE) | 版本/计数 = 1 |
    | 14 | 4 | 毫秒数 | 当日时间戳（秒×1000+毫秒，GetLocalTime）|
    | 18 | 2 | 0 / 2 | 隧道类型（2 = WG 隧道 keepalive）|
  - **间隔与重试**：select 循环（FUN_100640d0，l3vpn.c 行 0x54c 起）
    - 默认 30s（0x1e），会话字段钳制 [1,60]；注册表 `HKLM\SOFTWARE\VPN\Keepalive\SendInterval` 可覆盖（1-60）
    - 无响应 `AttemptMaxTimes`（默认 3，上限 300）个周期后重连（TCP 错误码 0x32，UDP 0x79）
    - select 超时 1s；send 次数写 `HKCU\...\Keepalive\L3TCPTunnel`（Running/SendTimes/TimeofLatestSend）
  - **重要修正**：源码级 keepalive 是 30s 间隔、20B 明文，**与 pktmon 实测的 ~200ms/85B 外层 record 不符** —— 200ms 流量应为别的帧（待查），85B 与 20B 明文 + TLS 1.2 开销需重新对齐；实测锚点需修正后再用于自检
  - 发送成功后维护两个计数器（包数/字节数）
  - 反编译产物：`docs/decomp/vl3vpn.c`（select 循环 FUN_100640d0、隧道主线程 FUN_10066250——其中可见 `validcode=`、`motionProweb=1`、`L4Connected=1`、`CustomDNS=` 连接串解析，T2/T5 素材）
  - [x] 心跳报文长度/结构；[x] 时间戳字段；[x] keepalive 间隔常量（30s 默认，非 200ms）

## T2 /vpntunnel 隧道建立

- 锚点字符串：`GET %s/vpntunnel HTTP/1.1`（vl3vpn.dll / vpnd.exe 都有）
- 步骤：
  1. 字符串 XREF → 构造该 GET 请求的函数
  2. 回答：
     - [ ] 完整请求头列表（Host / Cookie / 其他自定义头，如 validcode、MotionPro-web）
     - [ ] 响应 200 后如何切换到数据模式（同连接升级？还是新连接？）
     - [ ] session_id / sslproto / tunneltype 参数从哪携带
- 已知上下文（runtime-forensics.md）：TLS 1.2 → tunnel socket → an_login.js → cookie 复用
- 结论：
  - （待填）

## T3 隧道数据封送（核心）

- 锚点：`..\l3vpn\l3vpn.c`、`..\l3vpn\udp_tunnel.c` 路径字符串 + `"!!! write data to vpn tunnel failed, ret: %d !!!"`
- 步骤：
  1. 找 write/read tunnel 的函数（错误字符串 XREF）
  2. 回答：
     - [ ] 帧头结构（是否有 magic/长度/类型字段 —— 我们的占位设计 MPFR 待替换）
     - [ ] 内层 IP 包是否分片重组（MTU 1400 实测）
     - [ ] 压缩/加密是否在 TLS 之外还有一层
- 结论：
  - （待填）

## T4 UDP/DTLS 隧道

- 锚点：`DTLS SPEED TUNNEL`、`udp_tunnel.c`、`set_udp_tunnel_running_status`
- 依赖：T2/T3 的 TCP 版结论作为对照
- 问题：
  - [ ] UDP 隧道端口与握手包
  - [ ] DTLS 与 TCP 模式的切换条件（实测本环境 TCP；UDP 何时启用）
- 结论：
  - （待填）

## T5 认证字段

- 锚点：`an_login.js`、`login_vpn_server`、`get_aaa_method`、`session_id`、`sslerror`、`sslproto`、`tunneltype`（vpnd.exe / vl3vpn.dll）
- 问题：
  - [ ] AAA 查询响应的解析格式（我们假定 `{"methods":[...]}`，真实字段名待确认）
  - [ ] 登录提交经过 web portal（/restservice/vpnLogin/login，HAR 已得表单字段）后，
        客户端如何拿到 vpn 会话（cookie → /vpntunnel？）
  - [ ] HWID 字段如何编码（vpnhwidtool_x64.exe 可单独分析，产出 HWIDType=100 的算法）
- 结论：
  - （待填）

## T6 MTU / TAF / tunnelRule

- 锚点：`ArrayGetMTUAndTAF`、`ArraySetMTUAndTunnelRule`（ArrayVPNApi.dll 导出表）、
  `Get tunnelRule flag from reg: [%d]`
- 问题：
  - [ ] TAF（Traffic Access Filter）规则的数据结构
  - [ ] split tunnel 域名表如何下发（实测路由表 30 条 /25）
- 结论：
  - （待填）

---

## 附：辅助工具

- `scripts/` 里的抓包解析器可对照：实测包尺寸（85/101/181/133 C/S 方向）是反编译结果的自检锚点。
- 每完成一个任务，同步勾掉本文档对应 `[ ]`，并在 `docs/protocol-clues.md` 的「重写映射」段落补一行。
