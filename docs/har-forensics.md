# Web Portal / 认证协议发现（HAR 取证，2026-11-13）

来源：用户提供的两份浏览器 HAR（登录前 14 条 / 登录后 27 条）。域名已匿名化：
- `portal.example.com` ← 原登录页域名（企业 SSO 入口）
- `token.example.com` ← 原 VPN token 网关域名

## 关键架构发现（最重要）

**`wss://127.0.0.1:60012/ws/command` + `wss://127.0.0.1:60012/ws/notify`（101 Switching Protocols）**

浏览器 portal 页面通过本地 MotionProHttpd（60012 端口）的 **双 WebSocket** 与客户端通信：
- `ws/command`：UI → 本地客户端命令通道（对应 mp-ipc Request）
- `ws/notify`：本地客户端 → UI 状态推送通道（对应 mp-daemon tick_broadcast StatusUpdate）

✅ **我们的 mp-ipc（请求响应）+ tick_broadcast（状态推送）双通道设计与原版完全同构**。
差异仅是传输载体（原版 wss，我们是 ndjson over loopback TCP）——功能等价，无需改架构。

## 登录页协议（portal.example.com）

| 请求 | 说明 |
|---|---|
| `GET /` | 登录页（static/vpn-new/ 资源） |
| `GET /restservice/vpnLogin/getImage?d=<ms时间戳>&uuid=<uuid>` | **验证码图片**（每次登录会刷新） |
| `POST /restservice/vpnLogin/...` | **登录提交 —— 尚未捕获，需重新登录时录制** |

已知 cookie：`ANsession1716635751154266`（会话）、`username`、`role_xid`、`role_names`、`vpn_auto`、`vpn_status`。

## 登录后 portal（token.example.com，经 /prx 代理）

- 静态资源：`/prx/000/http/localhost/welcome/*`、`an_*.js`（an_welcome/an_util/an_bookmark/an_dd/an_vpn/l3vpn.js）
- **登出端点**：`GET /prx/000/http/localhost/logout`（an_welcome.js 实证）
- 客户端下载：`/prx/000/http/localhost/client_sec/userresource/<profile>/MotionProSetup_win64_v1.2.26.zip`
- vpn_util.js：`Logout()` / `SetCookie()` / `clearCookie()`

## 待补抓包

1. **登录 POST**（账号+密码+验证码提交的端点与字段）—— 重新登录时录 HAR
2. **ws/command 帧内容** —— DevTools → Network → WS → Messages 面板截图/导出（HAR 默认不含 WS 帧）
3. welcome.js / l3vpn.js 响应体（HAR 未含，需 Disable cache 后重载页面再导出）
