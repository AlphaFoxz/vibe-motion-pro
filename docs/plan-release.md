# plan-release：发布架构（Windows=sidecar 提权拉起 / Linux=systemd 服务）

日期：2026-11-17　状态：**P0-P3 已完成**（Windows UAC 真机端到端与首次 tag 发布留人工验收；macOS launchd 暂缓）

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

## P1 Windows sidecar —— ✅ 已完成（2026-11-17，UAC 真机端到端留人工验收）

- [x] daemon + wintun 进安装包：`tauri.conf.json` `bundle.resources` map 到安装根目录
      （**偏差**：未用原计划的 externalBin——triple 后缀改名、CI/dev 双平台都要占位、
      且 missing-file 直接炸 `cargo check`；resources map 让三文件同目录且无改名。
      已实证 NSIS 产物：mp-app.exe / mp-daemon.exe(3.9MB 真身) / wintun.dll 同目录，
      静默安装+卸载通过）
- [x] `app/src-tauri/build.rs` 自愈 sidecar 源目录（**偏差**：原计划只在 CI/发布脚本填充，
      但 tauri build script 在 check/dev 阶段就校验 resources 存在——fresh clone 会挂。
      现由 build.rs 兜底：wintun 拷真身、daemon 缺失时写占位（发布忘跑 prepare 会得到
      可见的"启动失败"错误，不会静默出错）；真身存在时不覆盖）
- [x] `ui_spawn_daemon` command：ShellExecuteW + runas + `--managed --parent-pid <UI pid>`、
      SW_HIDE（提权用 runas 动词，Tauri shell 插件/CreateProcess 均无提权能力）
- [x] `link_supervisor` 拉起策略：断链 ≥3s 首次、≥20s 第二次、之后转人工横幅；
      链路稳定在线 ≥60s 后配额清零（daemon 崩溃可自愈，同时防"秒死循环"UAC 轰炸）；
      结果经 `daemon-spawn` 事件推前端（ok 不打扰 / denied / error 分流）
- [x] 前端三语文案（spawnDenied / spawnError）+ `daemon-spawn` 监听
- [x] **决策点已裁（推翻初稿推荐）**：不传 PROGRAMDATA——同账户 UAC 提权后 `%APPDATA%`
      不变，保持 AGENT.md 的 per-user 配置根（`config_dir/APP_ID`）；"提权到其他管理员
      账户"属罕见边缘（后果仅 profiles 落到该账户目录，重加服务器即可），不值得引入
      全局路径分裂
- [x] `scripts/prepare-sidecar.ps1`（本地发布流）+ release.yml windows prepare 步骤

验证：

- [x] 安装包内容（7z 不可用 → 静默安装到临时目录检查）：三文件同目录、daemon 为真身
- [x] 静默安装（/S /D=）与静默卸载
- [x] 拉起策略单测（spawn_policy_two_attempts_then_stop）；workspace 测试全绿
- [ ] **人工验收项**（需 GUI 交互，自动化不覆盖）：干净虚拟机装包 → 首次打开弹一次 UAC →
      daemon 起来 → UI 自动连上 → 连接 VPN；杀 UI → daemon 随即退出无残留；
      拒绝 UAC → 横幅指引
- [ ] 已知化妆问题：提权拉起瞬间 conhost 闪现（daemon 已 FreeConsole 尽早脱离）

## P2 Linux systemd —— ✅ 已完成（2026-11-17，WSL 真机全链路验证）

- [x] `scripts/deb-inject-service.sh`：通用 deb 后处理（WSL 本地流与 release CI 共用）——
      `dpkg-deb -R` 解包 → 清理 tauri 直出的 sidecar 资源副本（占位 daemon/wintun）→
      注入 `/usr/bin/mp-daemon` + unit + postinst/prerm → `dpkg-deb -b --root-owner-group`
      重打包（包内属主 root:root）
- [x] unit：root 起步 + `MP_PROFILES=/var/lib/vibe-motionpro/profiles.toml`（固定路径，
      避免与用户手跑 daemon 的 ~/.config 分叉）+ `RUST_LOG=info`（journal 排障必需）
      + `Restart=on-failure`；非 root + CAP_NET_ADMIN 加固仍列为后续项
- [x] `scripts/wsl-deb-service.sh`（WSL 本地端到端构建流：musl daemon → tauri deb → 注入）
      + `scripts/wsl-service-verify.sh`（安装→服务→IPC→卸载验证，可重复执行）
- [x] 前端 Linux 离线文案：`errOfflineLinux`（systemctl 引导）×3 语言，按 userAgent
      探测平台分流
- [x] **踩坑记录**：① Windows checkout 的 autocrlf 会给 .sh 文件带 CRLF，WSL bash
      source 时报 `$'\r': command not found`——验证脚本统一先 `sed -i 's/\r$//'`；
      ② wire 协议 tag 是 snake_case（`status` 非 `Status`），手写探测时发错大小写
      会得到"连上即被关闭"，journal 里可见 serde 报错；③ 非交互 shell 里 sudo 会
      卡在密码输入——用 `wsl -u root` 替代

验证（WSL Ubuntu，全部通过）：

- [x] `dpkg -i` → 服务 active + enabled（postinst 生效）
- [x] IPC 往返：62000 端口 status 请求 → `disconnected` 响应
- [x] `MP_PROFILES` 指向 /var/lib/vibe-motionpro（服务化固定路径生效）
- [x] `wsl --shutdown` 完整重启 → 服务自动拉起（active）
- [x] `dpkg -r` → 服务停止、unit 移除、二进制移除，无残留

## P3 release CI —— ✅ 已完成（2026-11-17）

- [x] windows job：`prepare sidecar` 步骤跑 `scripts/prepare-sidecar.ps1`（daemon release
      构建 + sidecar 落位）→ `tauri build --bundles nsis`
- [x] ubuntu job：tauri deb/appimage 构建后 `deb-inject-service.sh` 注入 systemd 服务
      （gnu release daemon），deb 即最终产物
- [x] prepare 门禁（tag=master + 版本一致）不动；YAML 结构校验通过
      （ActionScript 级验证以首次 tag 发布跑通为准——发布前在 TODO 里留人工项）

## 实施顺序与提交纪律

- 顺序：P0 → P1 → P2 → P3 —— **已按序完成**（P0 独立提交 `55b7723`；
  P1+P2/P3 因前端与 CI 文件交叠合并为一个 commit，偏差可接受）
- 每阶段独立 commit（`feat(release): p0 daemon managed mode` 风格），每阶段完成即更新
  本文档 checkbox 与 TODO.md 索引（AGENT.md：文档与代码同步）
- 涉及 UI 壳时按 AGENT.md 红线 3：`pnpm build` 出 dist 后 `cargo check -p mp-app`

## 风险清单

| 风险 | 缓解 | 状态 |
|---|---|---|
| sidecar 孤儿占 62000 → 下次启动连不上 | P0 managed bind 接管等待 + 让位退出 | ✅ 真机双开验证 |
| 提权账户 ≠ 登录账户 → profiles 漂移 | 裁决：保持 per-user 路径，罕见边缘接受 | ✅ 已裁决记录 |
| systemd root daemon 与手跑 daemon 数据分叉 | unit 固定 MP_PROFILES=/var/lib/vibe-motionpro | ✅ 验证生效 |
| wintun.dll 安装后找不到（DLL 搜索序） | NSIS 产物实测同目录 | ✅ 验证 |
| UAC 弹窗被用户勾选"始终拒绝" | P1 文案引导 + 记录修复路径 | 人工验收项 |
| 发布忘跑 prepare → 占位 daemon 进包 | build.rs 占位是**可见错误**（UI 报"启动失败"） | ✅ 已兜底 |
| 与"Windows 服务"未来路径冲突 | daemon 参数化设计留口（服务模式忽略 parent-pid） | 留口未实现 |

## 完成定义（整体验收）

1. ~~Windows 干净虚拟机：安装包一路下一步 → 打开应用 → 一次 UAC → 连接成功 →
   退出应用后系统无残留（进程/路由/DNS）~~ —— 打包/静默装卸已自动化验证；
   **UAC 弹窗与 VPN 连接需 GUI 交互，留人工验收项**（下方清单）
2. ~~WSL/Ubuntu 干净环境~~ —— ✅ dpkg -i → 服务 active → IPC 往返 → 重启自启 → 干净卸载
3. ✅ 开发者体验不变：手动 `cargo run -p mp-daemon` + `pnpm tauri dev` 的 runbook 流程照常
   （build.rs 自愈 sidecar 使 fresh checkout 的 cargo check 不受影响）
4. ✅ `cargo test --workspace` 全绿；核心资产（红线清单）零改动

## 人工验收清单（发布前）

- [ ] Windows 干净虚拟机：装 NSIS 包 → 打开应用 → UAC 允许一次 → UI 自动连上 daemon →
      连接真实 VPN 成功 → 退出应用 → 无孤儿 mp-daemon 进程、路由/DNS 干净
- [ ] UAC 拒绝路径：横幅出现正确指引文案，无重试轰炸
- [ ] 首次 tag 发布：release.yml 双平台产物齐全（nsis exe + 注入服务的 deb + appimage）
