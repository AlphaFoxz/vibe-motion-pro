# mp-app (Tauri 2 UI)

对应原版 MotionPro.exe（Qt5 Widgets UI）。

## UI 结构（2026-11 重构）

- **三视图 + 底部 Tab**：`连接`（状态圆环 + 凭据表单）/ `服务器`（Profile 卡片管理）/ `日志`（见下）。
- **状态反馈**：Rust 侧与 daemon 保持单条长连接，状态变化经 `vpn-status` 事件推送
  （daemon 1s 广播仅在变化时发送；UI 不再轮询）。连接中按钮转 spinner、表单锁定。
- **连接成功**：托盘变绿 + 系统通知 + 自动收起到托盘（`mp_autohide` 可关，Rust 侧延迟 1.2s 执行；
  用户停在 `日志` 页时不收起——正在看日志）。
- **托盘**：三态图标（`icons/tray-{connected,connecting,disconnected}.png`，
  由 `scripts/gen_brand_icons.mjs` 生成）+ 菜单（状态行/显示窗口/连接/断开/退出）；
  左键切换窗口；关窗 = 收起托盘，退出走菜单。
- **Profiles = 服务器**：卡片（名称/host/隧道类型/上次连接/★默认）点击即预选并聚焦动态密保；
  两步删除确认；`autoconnect` 字段用作「默认服务器」。
- **记住密码**：`keyring` crate 写入 OS 凭据管理器（Windows Credential Manager /
  macOS Keychain / Linux Secret Service）。key 两级：稳定键
  `VibeMotionPro / vpn-pass:host:<host>`（host 归一小写，profile 重建后仍可找回）+
  兼容键 `vpn-pass:<profile_id>`（旧版数据，读取兜底、保存后迁移清理）。
  keychain 读取失败不再静默——提示「已保存的密码未回填」（Linux 常见于缺
  gnome-keyring/KWallet）。
- **i18n**：zh-CN / en / ja；语言切换同步托盘菜单文案（`set_tray_texts`）。
- **日志（惰性）**：第三个 Tab，显示守护进程与界面进程**自启动以来**的日志（各进程内的环形缓冲
  `mp_ipc::log`，保留最近 2000 行 / 256KB；未设 `RUST_LOG` 时默认 INFO+，设了则与之同级）。
  没人看日志时没有后台任务、定时器、文件 I/O 或守护进程连接——恒定成本只有每条日志一次
  格式化入队（历史无法事后补录，这是「自启动以来」的最小代价）。前端仅在日志页激活时每秒
  拉一次增量（VPN 状态/链路变化时即时补拉），离开即停表、清空、断开连接；窗口收起托盘或
  最小化时后端直接跳过。交互：级别筛选（全部/警告/错误，带计数徽标）、关键字筛选（`/` 或
  Ctrl+F 聚焦）、跟随滚动（翻到上方时新日志不拉动位置，显示「N 条新日志」）、一键复制
  （带文件头，尊重当前筛选）、守护进程重启分隔线、离线 / 版本不兼容 / 空态提示。

## IPC 模型（对应 main.rs）

daemon 的 IPC 主循环是单连接串行处理，因此 UI 侧把所有请求与 `StatusUpdate` 推送
复用在**同一条连接**上：`link_supervisor` 维持连接（2s 退避重连）→ `reader_loop`
读事件（Status/StatusUpdate → 前端事件；其余响应 → FIFO oneshot 交付在途请求）；
各 tauri command 经 `LinkShared::send` 挂起等待，链路断开时全部在途请求立即失败。

日志页是唯一的例外，另开一条**只在其打开期间存在**的连接：首个请求为 `log_tail` 的连接被
守护进程识别为日志连接（`mp_daemon::handle_client`），不进状态锁、不收状态推送。原因：控制
连接上的 Connect 会让守护进程的连接循环忙到 120s，同连接上的日志请求只能排在它后面——而
「边连接边看日志」正是日志页的主要用法。日志连接空闲 10s 由守护进程主动断开。
