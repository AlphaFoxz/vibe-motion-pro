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

1. **登录 POST 响应形态**（JSON / 302 / 空 body 未定 —— 免浏览器登录已按"200/302 + ANsession cookie 即成功"宽容实现）
2. ws/command 帧内容 —— DevTools → Network → WS → Messages 面板截图/导出（HAR 默认不含 WS 帧）
3. welcome.js / l3vpn.js 响应体（HAR 里 content 为空）

## 免浏览器登录（2026-11-14 补充：an_vpn.js 实证）

从登录后 HAR 提取的 `an_vpn.js`（服务器注入的连接参数，值已匿名化）：

```js
var _AN_vsite_name = "<站点名>";   // e.g. baosteel_vpn_token
var _AN_vsite_ip   = "<内网IP>";   // 隧道网关（10.x）
var _AN_vsite_port = 443;
var _AN_username   = "<工号>";
var _AN_auto = 1;                  // 自动拉起客户端
```

→ "建立连接"按钮的全部输入就这四个参数 + 会话 cookie。
**结论：浏览器可完全省略**：

| 浏览器步骤 | 直连替代（mp-core 已实现） |
|---|---|
| 显示验证码图片 | `ControlClient::fetch_captcha(uuid)` → JPEG 字节 → Tauri UI 展示 |
| 提交登录表单 | `ControlClient::login(LoginFormData)` → ANsession cookie |
| postlogin apps | `postlogin_apps()` → `PostloginApps`（site.session 等） |
| 连接按钮 → localhost:60012 WS | **跳过**（那是通知原版客户端的通道；我们直接用 site 会话调 `open_tunnel(vsite_ip:443)`） |

唯一保留的人机交互：动态验证码输入（防自动化设计，本就需人工）。


## 登录 POST（用户实测，凭据已匿名化）

```
POST /restservice/vpnLogin/login        # 端点路径待最终确认（响应头未留存）
Content-Type: application/x-www-form-urlencoded

t=t&userCode=example_user&pwd=<password>&code=<4位验证码>
```

| 字段 | 含义 |
|---|---|
| t | 固定 "t"（可能是 type/type-of-login 标记） |
| userCode | 用户工号 |
| pwd | 密码（明文传输，靠 HTTPS 保护） |
| code | 验证码（来自 getImage，uuid 关联） |

登录成功后种下 ANsession<ts> cookie，随后走 token.example.com 的 /prx 代理会话。

## WS 消息封包格式（原版 60012 端口实测帧）

JSON 信封：`{ data, error, message, receiver, sender }`

**command 响应帧示例**（状态查询，action=8）：
```json
{
  "data": { "action": 8, "site": { "host": "", "name": "" }, "status": 0 },
  "error": 0, "message": "vpn current status",
  "receiver": null, "sender": "daemon"
}
```

**notify 推送帧示例**（action=10）：
```json
{
  "data": { "action": 10, "callback": 1, "error": 0 },
  "error": 0,
  "receiver": "ANsession<ts>=<profile_id>+<uuid>",
  "sender": "daemon"
}
```

关键语义：
- `action` 是命令/事件码（8=查询状态；10=登录回调通知；其余码待采集）
- `receiver` 用 ANsession cookie 值寻址会话（格式 `<cookie>=<profile_id>+<uuid>`）
- `sender`: "daemon"

→ mp-ipc 的 Request/Response 即原版 action 的等价物；若未来需要与原版 web portal 兼容，可实现同格式信封（已建 WsEnvelope 结构，见 mp-core::protocol）。
