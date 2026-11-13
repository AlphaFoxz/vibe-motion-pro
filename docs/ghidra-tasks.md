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
  - **请求格式**（两个变体，均 `GET /prx/000/http/localhost/vpntunnel HTTP/1.1`，同连接发送后切二进制模式）：
    1. TCS 辅助通道（`array_vpn_tcs_connect` @10054e00，common.c；DNS 解析等）：
       `Cookie: %s` + `appid: SSPVPN` + `clientid: %s` + `Appid:DesktopDirect`
    2. 主数据隧道（`FUN_1005cc10`，get_config.c）额外携带：
       `Cookie: ANStandalone=true;%s` + `x-devtype: %d` + `cpuid: %s` + `hostname: %s` + `PAYLOAD-IP-VERSION: 6`（IPv6 模式）
  - **响应**：要求 `HTTP/1.1 200 OK`；`201 OK` = 新版 **JSON 协议**（体即 JSON，置 json_protocol 标志）；`302 Redirect` 拒绝
  - **模式切换**：同一 TLS 连接，读完 HTTP 头立即切二进制帧（见 T3），无新连接
  - [x] 完整请求头；[x] 切换方式（同连接升级）；[x] 参数经 cookie + 自定义 header 携带

## T3 隧道数据封送（核心）

- 锚点：`..\l3vpn\l3vpn.c`、`..\l3vpn\udp_tunnel.c` 路径字符串 + `"!!! write data to vpn tunnel failed, ret: %d !!!"`
- 步骤：
  1. 找 write/read tunnel 的函数（错误字符串 XREF）
  2. 回答：
     - [x] 帧头结构（是否有 magic/长度/类型字段 —— 我们的占位设计 MPFR 待替换）
     - [x] 内层 IP 包是否分片重组（MTU 1400 实测）
     - [ ] 压缩/加密是否在 TLS 之外还有一层
- 结论：
  - **数据面 = TLS 上跑裸 IP 包流，无任何额外封装头**（读循环 `FUN_10063130`，l3vpn.c 0x35b-0x3b4）：
    - `SSL_read` 入 64KB 缓冲（0x10000），缓冲内容为背靠背的原始 IPv4/IPv6 包
    - 首半字节 `0x60`=IPv6（+4 BE 载荷长 + 头 40B），否则 IPv4（+2 BE 总长）
    - 半包累积、一读多包、残余保留 —— **只做切包，不做重组**（IP 分片由内核/网卡 MTU 保证，MTU 1400）
  - **keepalive 即伪 IPv4 包**：`45 00 00 14` = 版本4+IHL5 / TOS=0 / 总长 BE 0x0014=20；+8 字节 `00 ff 00 00` = **TTL=0、协议号=255、校验和=0**；读循环 `proto==0xff` 特判走 keepalive 处理（FUN_10062270）—— 协议设计为同一裸 IP 流统一分发
  - 16 字节配置帧（HTTP 200 后，同一连接）：`[0]=消息类型字符，[4]=载荷长度`，客户端发 `'P'`（0x50），服务端响应 `'Q'`=通用配置 JSON、`'U'`=网络配置 JSON；随后普通配置请求体 0x30B、另有 0x10B 交换（TCS 通道起始帧首字节 0x0f；DNS 解析帧首字节 0x14、BE 长度在 +12、载荷主机名在 +16）
  - 实测对齐：85B/181B/133B TLS record = TLS 开销 + 内层裸 IP 包；**~200ms 小流量是内层 TCP 心跳，非 l3vpn keepalive（30s）**
  - **对重写的影响：删除 mp-core frame 的 MPFR 占位设计，直接实现「TLS 流 ⇄ 裸 IP 包切包器」**

## T4 UDP/DTLS 隧道

- 锚点：`DTLS SPEED TUNNEL`、`udp_tunnel.c`、`set_udp_tunnel_running_status`
- 依赖：T2/T3 的 TCP 版结论作为对照
- 结论：
  - **UDP 读循环（FUN_10062c70，l3vpn.c 0x2e4）与 TCP 完全同构：裸 IP 包流**，同一套半包/多包切分
  - 两种承载按会话标志（+0x59c8）区分：**明文 UDP `recvfrom`**（每报文即一或多个完整 IP 包）或 **DTLS `SSL_read`**（流式）
  - **写路径分流**（FUN_10063650 vpn_tunnel_write，l3vpn.c 0x3cd）：按速度隧道模式（+0x59c0：1=tcp2tcp、2=tcp2udp 等）路由——内层 proto==6（TCP）与非 TCP 各走 TCP 隧道（SSL_write）或 UDP 隧道（FUN_1007dd70→sendto），裸包无封装
  - 速度隧道启用条件（FUN_100659b0 l3vpn.c 0x7fb）：服务端配置允许（sess+0x5b7d）且客户端偏好非 0（sess+0x53a4，0=TCP/1=UDP/10=Default）时，先 FUN_1007e0f0 发送 udp clientid，失败则禁用 speed tunnel 回落 TCP
  - [x] 握手包（clientid 交换）；[ ] UDP 端口协商细节（FUN_1007e0f0 待深挖）

## T5 认证字段

- 锚点：`an_login.js`、`login_vpn_server`、`get_aaa_method`、`session_id`、`sslerror`、`sslproto`、`tunneltype`（vpnd.exe / vl3vpn.dll）
- 问题：
  - [x] AAA 查询响应的解析格式（我们假定 `{"methods":[...]}`，真实字段名待确认）
  - [x] 登录提交经过 web portal（/restservice/vpnLogin/login，HAR 已得表单字段）后，
        客户端如何拿到 vpn 会话（cookie → /vpntunnel？）
  - [ ] HWID 字段如何编码（vpnhwidtool_x64.exe 可单独分析，产出 HWIDType=100 的算法）
- 结论：
  - **postlogin apps JSON schema**（vpnd.exe 全量反编译 `docs/decomp/vpnd_all.c`，742 函数；解析函数 ~line 18060）：
    ```jsonc
    {
      "site": {                        // 主隧道站点
        "domain": "", "session": "",   // 会话凭据 → 用于 /vpntunnel 的 Cookie
        "server_type": 0, "port": 443,
        "method": "",                  // AAA 认证方法名（与 15 字符常量比较取子串转 int）
        "validcode": "", "username": "", "password": "",
        "certpath": "", "certpassword": "",          // 客户端证书
        "reconncount": 0, "reconntime": 0, "reconninterval": 0,  // 重连参数
        "flags": 0,                    // 能力位图（缺省 0x200），会话上再置 |0x180000
        "tunneltype": 0, "sslproto": 0,              // 隧道类型 / SSL 协议版本号
        "proxyhost": "", "proxyport": 0, "proxydomain": "", "proxyusername": "", "proxypassword": ""
      },
      "wg": {                          // WireGuard 站点（可选）
        "site_name": "", "session_id": "", "ip": "", "pub_key": "", "wg_desc": "", "wg_name": ""
      }
    }
    ```
  - **会话流转确认**：web portal 登录 → postlogin apps 返回 `site.session` → 作为 Cookie（`ANStandalone=true;...`）发起 `GET /vpntunnel`（与 T2 结论闭环）
  - WG session_id 另存注册表 `HKLM\SOFTWARE\VPN\AWG\session_id`（line 13712）
  - 主机名经 `gethostname` + 解析（line 18234）——对应 /vpntunnel 请求头 `hostname:`
  - 待办：0x4189db 处 15 字符 method 常量内容、HWID 编码算法（vpnhwidtool_x64.exe 未分析）
  - **附带收获**（vpnd.exe 字符串全景）：
    - 本地 IPC：`POST /channel/vpn HTTP/1.1` + `Content-Type: application/json` + `Host:127.0.0.1` —— UI↔vpnd 的本地 JSON 通道（印证我们的 IPC+broadcast 设计）
    - 路由下发：`route add %s MASK 255.255.255.255 %s METRIC 1`、`route -6 add %s/128 %s METRIC 1`、`route add ::/0 %s METRIC 1`（v4/v6 默认路由）—— 与 mp-platform RouteManager 实现一致
    - split tunnel：注册表 `HKCU\Software\VPN\VPN2\Include|Exclude`（`include_%d`/`exclude_%d` 枚举）、`virip=%d.%d.%d.%d@mask=%d.%d.%d.%d`、Include/Exclude Zone 数量、DNS list、Hostmap(host=, ip=)
    - JSON 解析库为 **jsoncpp**（postlogin 响应解析）

## T6 MTU / TAF / tunnelRule

- 锚点：`ArrayGetMTUAndTAF`、`ArraySetMTUAndTunnelRule`（ArrayVPNApi.dll 导出表）、
  `Get tunnelRule flag from reg: [%d]`
- 结论：
  - `ArrayGetMTUAndTAF(short* mtu, short* taf)`（@10001990，ArrayApi.cpp）从**服务器下发的 INI 配置**（CommonConfiguration，configfile.cpp）读取 `[Global_Configuration]` 段：
    | 键 | 含义 | 合法区间 |
    |---|---|---|
    | `VNIC_MTU` | 虚拟网卡 MTU | **[576, 1472]**（0x240-0x5c0），越界忽略 |
    | `VNIC_DTLS_MTU` | DTLS 隧道 MTU | 同上 |
    | `VNIC_TCP_ACK_Frequency` | **TAF**（TCP ACK 频率）| [1, 32] |
    | `L3VPNTunnelDispatchRule` | 隧道分流规则（0-4）| [0, 4] |
    | `Virtual_DNS_Timeout` / `Local_DNS_Timeout` | DNS 超时 ms | [100, 3000] |
    | `Proxy_Profix_Value` | 代理前缀值 | [2, 3] |
    | `Local_Subnet_Access` / `IPsec_Over_SSL` / `TLSV_12` | 布尔开关 | TLSV_12 缺省 true |
  - 优先级：DTLS MTU 存在则覆盖普通 MTU；**MTU 1400 实测值在 [576,1472] 内自洽**
  - [x] TAF 结构（TCP ACK 频率，非数据结构）；[ ] split tunnel 域名表下发格式（待'U'网络配置 JSON 深挖）

---

## 附：辅助工具

- `scripts/` 里的抓包解析器可对照：实测包尺寸（85/101/181/133 C/S 方向）是反编译结果的自检锚点。
- 每完成一个任务，同步勾掉本文档对应 `[ ]`，并在 `docs/protocol-clues.md` 的「重写映射」段落补一行。
