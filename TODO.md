# MotionPro VPN 客户端重写计划

## 背景

本产品（MotionPro VPN 客户端）为公司自有产品，原仓库因意外丢失，无法继续维护。
本项目的目标是在原 Windows 版（v1.2.26，C++ / Qt 5 + OpenSSL 1.0 + 特权辅助进程架构）基础上，
进行**跨平台重写补救 + 技术升级**，目标平台：Windows / macOS / Linux。

- 自有产品，无法律风险，可放心对旧二进制进行逆向参考。
- 推荐技术栈：**Rust 核心 + Tauri 2 UI**（原生小体积产物）。已评估并排除 Zig（C++ 绑定困难、GUI/TLS 生态不成熟、1.0 前不稳定）与 C++/Qt 6（维护成本高），最终确认 Rust + Tauri 2。

## TODO

### 阶段0 资产收集

- [x] 收集现有资产：已备份 v1.2.26 二进制到 `reference/binaries/`（MotionPro.exe、ArrayVPNApi.dll、vpnd.exe、vl3vpn.dll、InsideProxy.exe 等，含 CHECKSUMS.md5）
- [ ] 询问同事/备份渠道，寻找丢失仓库的残留副本、文档、协议设计文档、服务器端协议规范
- [x] 保留安装包：已备份 MotionProSetup.exe、OEM.ini、motionpro_templete.ini、OEM_Help.pdf、license.txt 到 `reference/installer/`，证书与配置到 `reference/config/`

### 阶段0 协议逆向重建

- [x] 初步线索提取：导出表 + 字符串分析已完成，见 `docs/protocol-clues.md`（发现 PDB 路径、57 个 API、/vpntunnel 端点、TCP/UDP/DTLS/WG 四种隧道）
- [x] Ghidra 深度反编译（2026-11-14 批次）：vpnd.exe 全量、vl3vpn.dll 多轮锚点、**vpnhwidtool_x64.exe 全量（HWID 生成链）**、**ArrayWGClient.exe（WG TCP 混淆/TLS 伪装，T7）** —— 见 docs/ghidra-tasks.md T1-T7 与 docs/decomp/ 新增 5 个产物；仍缺：InsideProxy.exe、ArrayVPNApi.dll 全量
- [ ] 用 Wireshark 抓包与反编译结果互相印证（重点：UDP 握手报文与 "200 OK"、服务端 UDP 端口下发键、201 JSON 配置键名、launch/disconnect 命令流）
- [x] 整理功能清单：已基于 OEM.ini 全部开关项 + ini 用户配置 + 安装包资源生成 `docs/feature-list.md`（8 大类，含裁剪建议）
- [x] Ghidra 反编译 vpnd.exe：`/vpntunnel` 请求/响应格式、认证字段、cookie 处理（T2/T5）
- [x] Ghidra 反编译 vl3vpn.dll：隧道包封装格式、keepalive 报文、MTU/TAF 结构（T1/T3/T4/T6/T7）
- [x] pktmon 抓包：TCP 隧道心跳实测（~200ms）；UDP/WG 模式未覆盖（原版当前未启用）

### 技术选型：Rust 核心 + Tauri 2 UI

- [x] Rust 核心 crate：协议客户端骨架（state/reconnect/keepalive/frame/nat/protocol 已就绪；TLS 控制通道实现中）、TLS（rustls，替代旧 OpenSSL 1.0 —— 属升级项）、隧道管理
- [x] 特权守护进程骨架（mp-daemon：IPC server + 1s 状态广播；Windows 服务注册在阶段4） / macOS launchd / Linux systemd，负责虚拟网卡（WinTun / utun / tun）与路由/DNS 接管，UI 通过本地 IPC 通信（复刻原 MotionPro.exe↔vpnd.exe 模型）
- [x] Tauri 2 前端骨架（UI + 托盘 + i18n + Profile 管理面板） + 托盘 + 中/英/日 i18n（替代 Qt5 Widgets —— 属升级项）
- [x] monorepo 结构：core/daemon/platform/app + mp-ipc（协议）、daemon（特权服务）、platform（各平台网卡/路由封装）、app（Tauri UI）

### 阶段1 工程骨架

- [x] 建立 monorepo：crates/{mp-core,mp-daemon,mp-platform,mp-ipc} 已创建并编译通过（cargo check OK）
- [x] Windows 10 SDK 已通过 winget 安装，MSVC 工具链恢复
- [x] 初始化 Tauri 2 app（UI 骨架 + 托盘占位 + IPC 桥接 commands）
- [x] CI（.github/workflows/ci.yml，三平台 cargo check/test；Tauri 构建待 SDK 就绪后加入）
- [x] 版本管理已 init + 首次提交；做好备份策略（后续推远端双备份）

### 阶段2 协议与隧道实现

- [ ] 认证（含证书校验、HWID）、UDP/TCP 隧道模式、心跳与自动重连 —— 控制通道已实现（rustls TLS + an_login.js AAA 查询 + session cookie jar + postlogin apps，mock TLS 服务器端到端测试覆盖）；服务器证书严格校验待接入 rootca；**数据面协议已由 Ghidra T1-T6 全部还原并实现**（dev-5：/vpntunnel 握手 + 16B 配置帧 + 裸 IP 转发泵 + keepalive 状态机，75 测试绿，见 docs/plan-dev-5.md）
- [x] 虚拟网卡数据面 + 路由/DNS 接管 —— dev-4 已完成：tun crate 真实适配器（win=wintun/linux/mac）、RouteManager（路由下发+DNS 快照回滚，DryRun 可测）、ChannelAdapter 桥接、Dataplane::pump 真实推进栈、daemon TunnelIo 组装（58 测试全绿，见 docs/plan-dev-4.md）；帧格式确认后接 frame 编解码即闭环
- [x] Ghidra 深度反编译（阶段0 项）—— T1-T6 全部完成（2026-11-14，Ghidra 12.2 headless 自动化流水线，见 docs/ghidra-tasks.md 结论小节）
- [ ] 与原版客户端对拍验证（Wireshark 报文一致、连接成功率）

### 阶段3 UI 功能对齐

- [ ] 逐项对齐功能清单：服务器/账号管理、自动登录、托盘图标三态（connected/disconnected/reconnecting）、web portal 资源、自动更新、客户端安全检查、root CA 安装、i18n

### 阶段4 安装分发（升级项）

- [ ] Windows：NSIS 或 MSIX；macOS：notarized pkg/dmg（Network Extension/特权 helper）；Linux：deb/rpm/AppImage
- [ ] 系统服务注册与卸载清理

### 阶段5 验证发布

- [ ] 与原版并行灰度对拍（连接成功率、断线恢复、DNS/路由正确性）
- [ ] 建立协议回归测试，覆盖服务器端版本升级场景
- [ ] 逐步替换原版客户端，归档新仓库与备份
