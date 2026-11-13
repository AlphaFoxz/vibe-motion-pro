# Ghidra 逆向任务清单（数据帧格式攻坚）

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
  - （待填）

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
