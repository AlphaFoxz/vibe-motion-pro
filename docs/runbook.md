# 真机运行手册（Runbook）

目标：在本机（Windows）跑通：UI 登录（工号/密码/手机动态密保）→ 建隧道 → 系统级转发。

## 0. 前置

- Windows 管理员权限（TUN 网卡 + 路由/DNS 需要）
- `wintun.dll`（tun crate 在 Windows 的依赖，需放在 daemon exe 同目录或 PATH）

```powershell
# 下载 wintun（约 130KB，一次性）：
Invoke-WebRequest https://www.wintun.net/builds/wintun-0.14.1.zip -OutFile $env:TEMP\wintun.zip
Expand-Archive $env:TEMP\wintun.zip -DestinationPath $env:TEMP\wintun -Force
Copy-Item $env:TEMP\wintun\wintun\bin\amd64\wintun.dll target\debug\
```

## 1. 启动 daemon（管理员 PowerShell）

```powershell
cargo run -p mp-daemon            # 监听 127.0.0.1:62000（ndjson IPC）
```

daemon 行为：UI 未连接时静默等待；1s 周期 tick；无管理员时 TUN 降级（仍可登录/握手验证）。

## 2. 启动 UI

```powershell
cd app; npm run tauri dev
```

## 3. 连接

UI 填：服务器 `vpn.baowugroup.com`（或公司给的门户域名）、工号、密码、手机 App 动态密保 → 「连接」。

链路：login → postlogin → /vpntunnel（P→Q，T→U）→ TUN + 路由/DNS 接管 → 系统流量走隧道。

## 4. 故障排查

| 现象 | 排查 |
|---|---|
| 「登录被拒绝」 | 工号/密码/动态密保错（密保每分钟变，注意时效） |
| 连接成功但无网络 | 日志看 TUN 是否降级（管理员？wintun.dll？）；'U' 是否下发 virip（没下发则不动路由） |
| 状态一直 connected 但实际断流 | keepalive 30s×3 后判死自动回 disconnected（≤3s 可见），重连即可 |
| daemon 日志 | stdout + `tracing`（`RUST_LOG=debug` 看协议细节） |

## 5. 已知限制（当前版本）

- TLS 证书校验：danger 模式（接受任意证书）—— 功能优先，接 rootca 在 TODO
- 'T'→'U' 帧字段布局按 Ghidra 推断实现，真机首次连通后建议抓包核对
- 分流路由表（Include/Exclude Zone）未接：当前仅在服务器下发 virip 时设置 DNS
- WireGuard / UDP 速度隧道未实现（TCP 隧道模式）
