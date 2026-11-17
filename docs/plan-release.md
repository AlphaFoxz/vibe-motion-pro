# plan-release：发布架构（Windows=sidecar 提权拉起 / Linux=systemd 服务）

日期：2026-11-17　状态：**待实施**（供后续 AI agent 按此迭代；对应 TODO 阶段4）

## 背景与决策

当前发布 blockers 之一：daemon 与 UI 需要用户**分别手动启动**（见 `docs/runbook.md`）。
runbook 是开发流程，不能当作用户体验。原版商业客户端的拓扑（`docs/runtime-forensics.md`）：

- `VPNService.exe` = Windows 服务，开机自启、SYSTEM 权限、持有 TLS 长连接（会话不随用户注销中断）
- `MotionPro.exe` = 纯 UI，随时崩溃不影响连接

本项目的取舍（**已定，勿反复**）：

| 平台 | 方案 | 理由 |
|---|---|---|
| Windows | **B：UI 以 UAC 提权拉起 daemon sidecar**，daemon 随 UI 存亡 | 关 UI 即断开符合普通用户直觉；规避 daemon 孤儿进程残留路由/DNS（`protocol-field-notes.md` 记录的边界情况）；不用碰 Windows 服务注册。代价：连接期间 UI 崩溃会断线（可接受，重开即可）+ 每次启动一次 UAC |
| Linux | **A：deb 内置 systemd unit** | WebKitGTK 不能 root 跑 → UI 内嵌 daemon 不可行；pkexec+polkit 每登录会话弹权且仍需安装包放 policy 文件，绕不开"改系统"；systemd unit 是 Linux 上最便宜的特权方案，UI 全程零提权 |
| macOS | 暂缓（CI 已暂停，见 72ab462） | launchd + 特权 helper 后续单独立项 |

企业级 always-on（会话不随注销中断）不在本期目标内；若未来需要，Windows 可再加服务注册路径，
与 sidecar 模式共存（daemon 检测到自己由服务管理时忽略 `--parent-pid`）。

## 红线（本计划不许碰的东西）

**VPN 功能已真机调试完毕。** 以下属于"能跑通连接"的核心资产，本计划的任何步骤都不许修改：

- `mp-core`：协议实现、数据面、keepalive、控制通道
- `mp-daemon`：连接业务逻辑（`handle_connect` / `handle_conn` 的请求处理与广播语义、
  120s Connect 总超时、状态锁纪律）、冻结看门狗
- `mp-ipc`：消息格式与 codec 语义
- `app/`：连接/保存密码/Profile 业务流程（前端 `connect()` 语义、keyring 键名）

允许的改动面（超出即越界）：

1. **进程生命周期**：daemon 启动参数、父进程看护、单例/退出语义（仅 `crates/mp-daemon/src/main.rs` 装配层）
2. **UI 壳的进程管理**：`link_supervisor` 的"探测失败 → 拉起/引导"分支、spawn 相关 Tauri command、离线横幅文案（`app/src-tauri/src/main.rs`、`app/src/main.ts`、`app/src/i18n.ts`）
3. **打包与 CI**：`tauri.conf.json`、`scripts/wsl-*.sh`、`.github/workflows/release.yml`

若实施中发现上述核心资产有 bug：**单独开 fix commit，不与本计划的 commit 混合**，并在 commit message 里写明复现证据。

命名遵循 `AGENT.md`（identifier `com.alphafoxz.vibemotionpro` 发布后不可改；产品名 VibeMotionPro 无空格）。

## 现状事实（2026-11-17 已核实，可直接依赖）

- `crates/mp-daemon/src/main.rs`：**无任何 CLI 参数**；IPC bind 失败重试 10×1s 后带指引退出
  （开发机端口抢占场景）；profiles 路径 `MP_PROFILES` 可覆盖，默认
  `dirs::config_dir()/com.alphafoxz.vibemotionpro/profiles.toml`
- `app/src-tauri/src/main.rs` `link_supervisor`：2s 退避无限重连；失败仅发 `vpn-link=false`
  事件 → 前端离线横幅（`errOffline`）。**没有任何拉起 daemon 的逻辑**
- `tauri.conf.json`：无 `externalBin`；bundle targets "all"；devUrl 1420 / dist ../dist
- deb 由 `tauri build --bundles deb` 直出，`scripts/wsl-tauri-deb.sh` 只做 dpkg-deb 校验；
  daemon 的 musl 静态构建环境已有（`scripts/linux-musl-env.sh`）
- `.github/workflows/release.yml`：prepare 门禁（tag 在 master 上 + 版本与 tauri.conf.json 一致）
  + windows/ubuntu 双矩阵 build
- wintun.dll：`crates/mp-daemon/wintun/`（x64），build.rs 开发期拷到 target exe 旁；
  arm64 变体缺失是 TODO 既有项（本计划只处理 x64）
- IPC 传输：双平台都是 TCP loopback `127.0.0.1:62000`（`MP_IPC_ADDR` 可覆盖）——
  **本计划保持不变**（named pipe / unix socket 是后续优化项，非必需）

## P0 daemon 生命周期模式（双平台共用底座）——✅ 已完成（2026-11-17）

改动点全部在 `crates/mp-daemon/src/main.rs`（装配层）+ lib.rs 一个纯增量方法：

- [x] 启动参数 `--managed`（受宿主管理）与 `--parent-pid <PID>`（Windows 必传；
      Unix 侧直接 `getppid()`，参数可忽略）。手写 `std::env::args` 解析，
      支持 `--parent-pid=N` 等价形式，零新增依赖（musl 静态构建不受影响）
- [x] 父进程看护：纯函数 `parent_expired` + 单测（7 个新测试）；Windows
      `OpenProcess(QUERY_LIMITED_INFORMATION | SYNCHRONIZE)` + `WaitForSingleObject(0)`
      轮询；宽限 3s 防 UI 短暂重启误杀；Unix `getppid() != 启动时记录值`
- [x] 父进程死亡 → 既有 teardown 语义退出（logout → TUN teardown → pump shutdown；
      状态锁被在途 Connect 持有时轮询 try_lock 最多 125s，超时直接退出交内核回收）
- [x] `--managed` 下 bind 失败：**接管等待 5s 后让位退出（code 10）**——
      立即退出会让「UI 崩溃后立刻重启」竞态反复触发 UAC 重拉，见下方偏差记录
- [x] 非 managed（现状：手动/开发模式）行为完全不变——runbook 流程不受影响

**实施偏差（相对本计划初稿，均已定稿）**：

1. bind 让位语义从"立即退出"改为"接管等待 5s 后退出 code 10"：老 daemon（父进程
   已死、处退出宽限）通常 3s 内释放端口，新 daemon 无需重拉（少一次 UAC）；
2. lib.rs 新增 `logout_last_session_await`（纯增量）：退出路径必须等待注销完成，
   spawn 版会随 runtime drop 被取消、注销请求发不出去；原 spawn 版行为不变；
3. Windows 教训：`OpenProcess` 不带 `SYNCHRONIZE` 时 `WaitForSingleObject` 恒返回
   WAIT_FAILED，曾被误判为"存活"导致 daemon 永不退出（真机实证后修复）；
4. managed 模式启动即 `FreeConsole()`：提权拉起 console 子系统二进制会弹 conhost
   窗口，尽早脱离（仍会闪现一瞬，纯化妆问题）。

验证（全部通过，2026-11-17 真机）：

- [x] 单测 7 项（args 解析 ×5 + parent_expired ×2）；workspace 103 测试全绿
- [x] 父进程死亡 → daemon 3.1s 退出（code 0），teardown 日志完整
- [x] 健康实例占用端口 → managed 新实例等待 ~5s 后让位退出（code 10）
- [x] 接管窗口内老实例死亡 → 新实例接管 bind 并继续服务

## P1 Windows sidecar

- [ ] `tauri.conf.json`：`bundle.externalBin` 加入 mp-daemon（CI 里把
      `target/release/mp-daemon.exe` 复制为 `mp-daemon-<target-triple>.exe` 放到
      tauri 期望的位置）；**wintun.dll** 确保安装后与 daemon exe 同目录
      （tun crate 走标准 DLL 搜索顺序，exe 同目录即可命中；用 resources 映射到安装根目录，
      NSIS 安装后实测确认）
- [ ] Rust 侧新增 command `ui_spawn_daemon`（`app/src-tauri/src/main.rs`）：
      `ShellExecuteW` + `runas` 动词、`--managed --parent-pid <UI pid>` 参数、detached、
      无控制台窗口。注意：Tauri 插件无法直接提权，必须走 ShellExecute 的 runas verb
      （`windows-sys` 或 `windows` crate，挑依赖树里已有的）
- [ ] `link_supervisor` 增强：首连失败约 3s 后触发**一次** `ui_spawn_daemon`
      （每进程生命周期至多一次，避免 UAC 弹窗轰炸），之后维持既有 2s 重连循环；
      spawn 结果（成功/被拒/失败）发事件给前端（如 `vpn-link` 扩展或新事件 `daemon-spawn`）
- [ ] 前端离线横幅分流（`i18n.ts` 三语言都要加）：
      spawn 被拒 → "需要管理员权限允许 VibeMotionPro 守护进程"；spawn 后仍连不上 →
      引导重装或检查杀软；Linux 文案见 P2
- [ ] **决策点（默认按推荐做，实施时可推翻并在此记录理由）**：UAC 提权账户 ≠ 登录账户时
      `%APPDATA%` 漂移 → sidecar spawn 时统一传 `MP_PROFILES=%PROGRAMDATA%\VibeMotionPro\profiles.toml`。
      profiles 全走 IPC，UI 不直读文件，改动只影响 spawn 命令的参数拼装

验证：

- [ ] 干净 Windows 虚拟机：装 NSIS 包 → 点图标 → 一次 UAC → daemon 起来 → UI 自动连上 →
      连接 VPN 成功
- [ ] 连接状态下杀 UI 进程 → daemon 随即退出、无孤儿进程、路由/DNS 干净
- [ ] 拒绝 UAC → 横幅给出指引，不崩溃不重试轰炸；再次点连接可重新触发（或按重启应用处理，
      实施时定夺并记录）

## P2 Linux systemd

- [ ] deb 后处理流水线（扩展 `scripts/wsl-tauri-deb.sh` 或新增 `scripts/wsl-deb-service.sh`）：
      `dpkg-deb -x` 解包 tauri 直出的 deb → 注入 `/usr/bin/mp-daemon`（musl 静态产物，
      复用 `linux-musl-env.sh`）、`/usr/lib/systemd/system/mp-daemon.service`、
      `postinst`（`systemctl preset mp-daemon && systemctl enable --now mp-daemon`）、
      `prerm`（stop + disable）→ `dpkg-deb -b` 重打包。
      选择后处理而非 tauri 原生配置的原因：Tauri v2 对 maintainer scripts 支持不稳定，
      且 daemon 二进制来自独立 musl 构建
- [ ] unit 内容（起步从简，root 运行）：
      `ExecStart=/usr/bin/mp-daemon`、
      `Environment=MP_PROFILES=/var/lib/vibe-motionpro/profiles.toml`
      （固定路径，避免 root 服务与用户手跑 daemon 的 ~/.config 数据分叉）、
      `Restart=on-failure`、`WantedBy=multi-user.target`
- [ ] 非 root + `AmbientCapabilities=CAP_NET_ADMIN` 加固**列为后续项不做**
      （resolvectl 总线权限牵连多，先把能用的发出去）
- [ ] 前端 Linux 文案：探测失败 → 提示 `systemctl status mp-daemon` / 重装

验证（WSL，复用 `wsl-deb-install.sh` 的校验模式）：

- [ ] `dpkg -i` → 服务 active（systemctl status）→ UI 启动即连（无需任何提权交互）
- [ ] 重启 WSL → 服务自启 → UI 直连
- [ ] `dpkg -r` → 服务停止移除，无残留（/var/lib 目录可保留用户数据，与惯例一致则记录决定）

## P3 release CI

- [ ] `.github/workflows/release.yml` windows job：`cargo build -p mp-daemon --release` →
      sidecar 按target-triple 改名落位 → 确认 wintun.dll 进包 → `tauri build`
- [ ] ubuntu job：musl daemon 构建 → 跑 P2 deb 后处理脚本 → 产物改名（含 daemon 的完整 deb）
      上传 Release
- [ ] prepare 门禁不动（tag=master + 版本一致已就绪）

## 实施顺序与提交纪律

- 顺序：P0 → P1 → P2 → P3（P0/P2 无相互依赖，可先做 P2 赢得更快反馈）
- 每阶段独立 commit（`feat(release): p0 daemon managed mode` 风格），每阶段完成即更新
  本文档 checkbox 与 TODO.md 索引（AGENT.md：文档与代码同步）
- 涉及 UI 壳时按 AGENT.md 红线 3：`pnpm build` 出 dist 后 `cargo check -p mp-app`

## 风险清单

| 风险 | 缓解 |
|---|---|
| sidecar 孤儿占 62000 → 下次启动连不上 | P0 managed bind 快速退出语义（验收必测双开） |
| UAC 提权账户 ≠ 登录账户 → profiles 漂移 | P1 决策点：MP_PROFILES 指 PROGRAMDATA |
| systemd root daemon 与手跑 daemon 数据分叉 | P2 固定 MP_PROFILES=/var/lib/vibe-motionpro |
| wintun.dll 安装后找不到（DLL 搜索序） | P1 安装后冒烟为验收项，不许跳过 |
| UAC 弹窗被用户勾选"始终拒绝" | P1 文案引导 + 记录修复路径（控制面板 UAC 设置） |
| 与"Windows 服务"未来路径冲突 | daemon 参数化设计留口（服务模式忽略 parent-pid），本计划不实现 |

## 完成定义（整体验收）

1. Windows 干净虚拟机：安装包一路下一步 → 打开应用 → 一次 UAC → 连接成功 →
   退出应用后系统无残留（进程/路由/DNS）
2. WSL/Ubuntu 干净环境：dpkg -i → 重启 → 打开应用直接可用，全程无提权交互
3. 开发者体验不变：手动 `cargo run -p mp-daemon` + `pnpm tauri dev` 的 runbook 流程照常
4. `cargo test --workspace` 全绿；核心资产（红线清单）的 diff 为零
