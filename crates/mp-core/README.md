# mp-core

MotionPro 协议核心 crate（跨平台，无特权要求）。

职责：
- `/vpntunnel` HTTPS 握手（rustls）与认证（账号/密码、OAuth、客户端证书、AAA）
- 会话管理：session_id、心跳保活、自动重连、顶号处理
- 隧道会话状态机：Disconnected / Connecting / Connected / Reconnecting
- 隧道类型：TCP（lwIP 类数据面，smoltcp）、UDP、DTLS、WireGuard（含 TCP 混淆 ObfuscateKey）
- 对应原版 `ArrayVPNApi.dll` + `vpnd.exe` 协议逻辑

对外 API 语义对齐原版导出表（见 `docs/protocol-clues.md`）：
Start/Stop/GetRunningStatus/GetSession/GetErrorInfo/SetReconnectParameters/SetKeepaliveOption/...
