# 真机运行手册（Runbook）

目标：在本机跑通：UI 登录（工号/密码/手机动态密保）→ 建隧道 → 系统级转发。

## 0. 平台差异速览

| | Windows | Linux |
|---|---|---|
| daemon 特权来源 | UAC 提权，UI 可自动拉起 sidecar | systemd 服务（安装版）/ sudo（开发期） |
| 特有前置 | wintun.dll | 无 |
| 开发期起 daemon | 管理员 PowerShell `cargo run -p mp-daemon`；或构建过一次后由 UI 首次连接时自动 UAC 拉起（见 `app/src-tauri/src/main.rs` `ui_spawn_daemon`） | 手动 `cargo run -p mp-daemon`（TUN 降级）；或装 dev systemd 服务（§2.2） |
| 用户安装 | NSIS：装完首连弹一次 UAC，sidecar 自动落位 | deb：内置 systemd unit，装完服务自启（plan-release.md P2） |
| daemon 日志 | stdout + tracing | 服务 `journalctl -u mp-daemon-dev`；手跑同 Windows |

UI 两平台完全一致：`cd app && pnpm tauri dev`，连接流程见 §3。
无特权（daemon 无管理员/root）时 TUN 自动降级：可登录、握手验证，但无系统级转发。
Linux 下 UI **不会**拉起 daemon（设计行为，daemon 生命周期归 systemd/开发者管），断链时静默重连。

## 1. Windows

### 1.0 前置

- Windows 管理员权限（TUN 网卡 + 路由/DNS 需要）
- `wintun.dll`（tun crate 在 Windows 的依赖，需放在 daemon exe 同目录或 PATH）

```powershell
# 下载 wintun（约 130KB，一次性）：
Invoke-WebRequest https://www.wintun.net/builds/wintun-0.14.1.zip -OutFile $env:TEMP\wintun.zip
Expand-Archive $env:TEMP\wintun.zip -DestinationPath $env:TEMP\wintun -Force
Copy-Item $env:TEMP\wintun\wintun\bin\amd64\wintun.dll target\debug\
```

### 1.1 启动 daemon（管理员 PowerShell）

```powershell
cargo run -p mp-daemon            # 监听 127.0.0.1:62000（ndjson IPC）
```

daemon 行为：UI 未连接时静默等待；1s 周期 tick；无管理员时 TUN 降级（仍可登录/握手验证）。

### 1.2 启动 UI

```powershell
cd app; npm run tauri dev
```

## 2. Linux

### 2.1 启动 daemon（手动）

```bash
cargo run -p mp-daemon            # 监听 127.0.0.1:62000；普通用户 → TUN 降级
```

需要完整 TUN/路由接管时（先普通用户构建，再 sudo 跑二进制）：

```bash
cargo build -p mp-daemon --release
sudo target/release/mp-daemon
```

> 不要直接 `sudo cargo run`：root 会把 `target/` 下产物属主改成 root，
> 后续普通用户构建会报权限错。

### 2.2 常驻 dev 服务（可选，推荐）

开机自动起 daemon、行为与发布版一致（root + 固定 profile 路径 + 崩溃自愈）：

```bash
sudo bash scripts/install-daemon-dev-service.sh            # 安装并启动（开机自启）
cargo build -p mp-daemon --release \
  && sudo systemctl restart mp-daemon-dev                  # 改 daemon 代码后生效
journalctl -u mp-daemon-dev -f                             # 跟踪日志
sudo bash scripts/install-daemon-dev-service.sh uninstall  # 卸载
```

- unit 的 `ExecStart` 指向仓库 `target/release/mp-daemon`：`cargo clean` 后服务起不来
  属正常（Restart 会被 systemd 限流），先重新构建再 restart
- profile 固定在 `/var/lib/vibe-motionpro/profiles.toml`（与发布版一致），与手动跑
  daemon 的 `~/.config` 数据**不互通**，切换方式后 UI 里需重新保存一次账号
- 服务名刻意用 `mp-daemon-dev`，不与正式 deb 的 `mp-daemon` unit 冲突

### 2.3 启动 UI

```bash
cd app && pnpm tauri dev
```

daemon 晚于 UI 启动也能恢复：断链自动重连，恢复时补拉一次 profile 列表。

## 3. 连接（两平台一致）

UI 填：服务器 `vpn.example.com`（或公司给的门户域名）、工号、密码、手机 App 动态密保 → 「连接」。

链路：login → postlogin → /vpntunnel（P→Q，T→U）→ TUN + 路由/DNS 接管 → 系统流量走隧道。

## 4. 故障排查

| 现象 | 排查 |
|---|---|
| 「登录被拒绝」 | 工号/密码/动态密保错（密保每分钟变，注意时效） |
| 连接成功但无网络 | 日志看 TUN 是否降级（Windows：管理员？wintun.dll？Linux：daemon 是否 root？）；'U' 是否下发 virip（没下发则不动路由） |
| 状态一直 connected 但实际断流 | keepalive 30s×3 后判死自动回 disconnected（≤3s 可见），重连即可 |
| daemon 日志 | Windows：stdout + tracing；Linux 服务：`journalctl -u mp-daemon-dev`；手跑：stdout。`RUST_LOG=debug` 看协议细节 |
| Linux UI 一直离线 | `ss -ltn \| grep 62000` 看 daemon 是否在听；服务模式 `systemctl status mp-daemon-dev`；确认没有旧进程占端口 |

## 5. 已知限制（当前版本）

- TLS 证书校验：danger 模式（接受任意证书）—— 功能优先，接 rootca 在 TODO
- 'T'→'U' 帧字段布局按 Ghidra 推断实现，真机首次连通后建议抓包核对
- 分流路由表（Include/Exclude Zone）未接：当前仅在服务器下发 virip 时设置 DNS
- WireGuard / UDP 速度隧道未实现（TCP 隧道模式）
- macOS：未分发（TODO）
