# mp-app (Tauri 2 UI)

对应原版 MotionPro.exe（Qt5 Widgets UI）。

## UI 结构（2026-11 重构）

- **双视图 + 底部 Tab**：`连接`（状态圆环 + 凭据表单）/ `服务器`（Profile 卡片管理）。
- **状态反馈**：Rust 侧与 daemon 保持单条长连接，状态变化经 `vpn-status` 事件推送
  （daemon 1s 广播仅在变化时发送；UI 不再轮询）。连接中按钮转 spinner、表单锁定。
- **连接成功**：托盘变绿 + 系统通知 + 自动收起到托盘（`mp_autohide` 可关，Rust 侧延迟 1.2s 执行）。
- **托盘**：三态图标（`icons/tray-{connected,connecting,disconnected}.png`，
  由 `scripts/gen_brand_icons.js` 生成）+ 菜单（状态行/显示窗口/连接/断开/退出）；
  左键切换窗口；关窗 = 收起托盘，退出走菜单。
- **Profiles = 服务器**：卡片（名称/host/隧道类型/上次连接/★默认）点击即预选并聚焦动态密保；
  两步删除确认；`autoconnect` 字段用作「默认服务器」。
- **记住密码**：`keyring` crate 写入 OS 凭据管理器（Windows Credential Manager /
  macOS Keychain / Linux Secret Service），key = `MotionPro / vpn-pass:<profile_id>`。
- **i18n**：zh-CN / en / ja；语言切换同步托盘菜单文案（`set_tray_texts`）。

## IPC 模型（对应 main.rs）

daemon 的 IPC 主循环是单连接串行处理，因此 UI 侧把所有请求与 `StatusUpdate` 推送
复用在**同一条连接**上：`link_supervisor` 维持连接（2s 退避重连）→ `reader_loop`
读事件（Status/StatusUpdate → 前端事件；其余响应 → FIFO oneshot 交付在途请求）；
各 tauri command 经 `LinkShared::send` 挂起等待，链路断开时全部在途请求立即失败。
