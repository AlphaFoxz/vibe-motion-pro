# 更新日志

本文件由 CI 在发布时依据 [约定式提交](https://www.conventionalcommits.org/zh-hans/) 自动生成，请勿手工编辑。

## v0.1.1（2026-11-19）
### ⚡ 性能
- **ui**: 首连失败立即拉起 daemon，消除启动时 UAC 前的数秒等待

### ✨ 功能
- **ci**: add git-cliff configuration for automated changelog generation

### 🐛 修复
- **ui**: 断开连接增加乐观中间态，点击立即显示断开中状态而非等待后端返回
- **ui**: Linux 断链不再尝试自动拉起 daemon
- **ui**: 凭据稳定键按 host 兜底 + keychain 读取失败不再静默

### 📚 文档
- 添加应用自更新机制（Tauri Updater）实施计划
- 补全双平台安装/调试说明（runbook 扩 Linux + README 平台速览）

### 🔧 杂项
- update version numbers to 0.1.1 in Cargo.toml, package.json, tauri.conf.json, and Cargo.lock; add version management script

## v0.1.0（2026-11-18）
### ♻️ 重构
- **platform**: encapsulate wintun Session behind SessionHandle - daemon no longer depends on wintun crate directly; drop dead mp-platform features (windows/macos/linux never referenced)
- **workspace**: pull app/src-tauri into cargo workspace - single lockfile, shared dep versions via workspace=true, path deps centralized; CI splits rust (default-members, no webkit needed) vs app matrix (linux webkit deps + frontend dist before mp-app check); docs synced
- **platform**: NetBackend trait - per-OS route/DNS strategy (windows predelete+if-index, linux ip-route-replace + resolvectl default-route advisory, macos networksetup) injected into RouteManager; host-OS-bound tests replaced with backend-pinned dry-run flows runnable on any host (linux baseline caught 2 failures); remove non-windows TunAdapter::try_clone (tun 0.6.1 unix Device has no try_clone - never compiled on linux until now); gnu-extract-user.sh + linux-musl-test.sh dev-env helpers
- **platform**: TunLink sinks into mp-platform::link - daemon is now platform-mechanism free (remaining cfg = registry identity reuse only); non-windows iface uses kernel-assigned actual_name (macOS utunN - requested name is ignored, routes/DNS previously targeted nonexistent interface); hostname via hostname crate (COMPUTERNAME was windows-only); device identity now truly persisted cross-platform (registry reuse -> config-dir file -> random generated + stored, replacing never-persisted constant fallback)

### ✨ 功能
- **phase2**: IPC ndjson+TCP transport, VPN state machine, reconnect backoff, keepalive monitor, tunnel frame codec, daemon engine wiring — 27 tests green
- **phase2/E4**: smoltcp dataplane skeleton + Adapter trait/mock; Windows SDK installed via winget, MSVC toolchain restored, drop gnu override
- **phase3**: Tauri 2 app skeleton (login UI + tray placeholder + IPC bridge commands)
- **dev-2**: status broadcaster (1s poll, change-only push), profile store (TOML) + IPC CRUD, UI i18n (zh/en/ja); fix ipc codec BufReader data-loss hang — 37 tests green
- **dev-3**: NAT/session table (FlowKey+aging+capacity), UI profile panel wired to IPC, platform route/dns command builders (win/linux/mac) — 48 tests green, tauri check OK
- TLS control channel client (rustls) — AAA query, cookie jar, postlogin apps with mock-TLS e2e tests; fix rustls provider ambiguity (tokio-rustls default off); TODO reality sync — 53 tests green
- original WS envelope protocol (WsEnvelope/action codes/receiver addressing), login form builder (credentials anonymized), login/captcha/logout endpoint consts — 52 tests green
- **dev-4**: real TUN adapter (wintun/utun/tun), RouteManager with DNS snapshot/rollback, ChannelAdapter bridge, Dataplane::pump, daemon TunnelIo — 58 tests green
- **dev-5**: tunnel pump, vpntunnel handshake + protocol/ghidra notes
- **dev-6/7**: internalized browserless login, TUN wiring, real-machine runbook
- **tunnel**: U/Q frame binary decoding + tunnel param fixes against live gateway
- **tunnel**: clientid/speed-tunnel registration + Ghidra T7 notes
- **frame**: decode proto-255 control frames fully
- **ui**: WARP-style redesign - event-driven status, tray states, server cards, keychain pwd (dev-7)
- **platform**: dual-path DNS takeover - Linux falls back to resolv.conf rewrite when systemd-resolved absent (snapshot byte-exact restore, file removed on revert if it never existed); macOS targets primary network service resolved at runtime (networksetup takes service name not interface) with -getdnsservers snapshot restore (was unconditional empty, wiping user static DNS); revert is best-effort cleanup (kernel drops routes when tun closes - del failure is the expected state, warn not Err); FsOps abstraction keeps file path testable
- add release workflow for GitHub Actions to automate tagging and building for multiple platforms
- **release**: P0 daemon managed 模式（--managed/--parent-pid 生命周期底座）
- **release**: P1-P3 daemon 随应用分发（win sidecar UAC / linux systemd / CI）
- update release plan status to P0-P3 completed and clarify implementation details
- **ui**: refactor profile selection logic to improve server list initialization

### 🐛 修复
- align state machine/engine/validcode tests with runtime-forensics enums — 33 tests green
- **app**: vite dev server on Windows - pin 127.0.0.1, ignore src-tauri build artifacts
- **login**: real-gateway login chain - TLS 1.2, ALPN, two-hop login, postlogin targeting
- **pump**: live-session stability - 200ms heartbeat, egress filtering, write watchdog, logout on teardown
- **keepalive**: heartbeat rework + regression revert
- **tun**: replace tun-0.6.1 async layer with native wintun on Windows - runtime freeze root cause
- **freeze**: compute timezone offset at startup, never spawn PowerShell inside async paths (first-heartbeat OnceLock init spawns a child process on a tokio worker - prime suspect for runtime freezes); watchdog cdb now local-symbols-only with 20s kill timeout (symbol-server download hung cdb and kept target threads suspended)
- **freeze**: eliminate blocking child-process spawns from async paths - ROOT CAUSE captured by freeze watchdog (freeze_auto.txt): main async thread wedged forever in windows_if_index spawn of 'route print' during 73-route setup storm (73x2 child spawns, pipe read WaitForMultipleObjects never returned, heartbeat starved >15s, watchdog fired). Fixes: (1) windows_if_index now uses Win32 GetAdaptersAddresses API (zero child processes, <1ms); (2) adapter open + route/DNS setup moved to dedicated std threads (mp-adapter-open / mp-route-setup); (3) SystemRunner: every route/netsh command gets 15s timeout + kill + CREATE_NO_WINDOW; (4) netsh MTU in TunAdapter::open reuses SystemRunner
- **daemon**: never exit on IPC accept failure - log + backoff + continue (daemon exited silently with code 1 right after clean teardown/logout on real gateway; only silent exit path was conn? in main select loop)
- **daemon**: eliminate runtime blocking points - watchdog false-kill freeze #2/#3/#4
- **daemon**: cross-platform profile path via dirs::config_dir (APPDATA was windows-only, silently fell back to cwd elsewhere); watchdog paths env-overridable (MP_CDB/MP_SYMBOLS), symbol dir defaults to exe dir instead of hardcoded project path, dump dir temp/motionpro
- root_nettest 仅 Linux 平台编译（补 cfg gate，修复 Windows cargo test 编译 example 报错）
- IPC 应答误路由致前端 invoke 超时（保存密码失效的根因）
- **daemon**: TUN bring_up failure is now a hard connect error, never silent degraded mode - real-machine incident 2026-11-18 07:33: non-elevated daemon (shell lost admin after server restart) hit wintun 'Failed to create private namespace: Access Denied', degraded to a data-path-less 'connected' (out=0pkt for 6min, user browsing dead, process killed in frustration). Now: pump shut down + session aborted with actionable message; only MP_TUN_DEGRADED_OK=1 (tests) may degrade
- **ui**: 未连接态内容溢出 400×580（紧凑态圆环 88px 让位 + 收紧间距，隐藏 main 滚动条；连上后圆环长回 108px）

### 📚 文档
- update TODO after scaffold
- TODO updates (SDK/Tauri done)
- runtime forensics from live original VPN (process topology, auth flow, status enum, split-tunnel routes); align core state machine + protocol module with real endpoints
- packet capture analysis (pktmon->pcapng parsers), TCP tunnel keepalive measured ~200ms, TLS-encrypted payload confirmed; protocol consts updated
- add public README
- HAR forensics — portal auth flow (captcha endpoint, logout), 60012 dual-WebSocket architecture confirms our IPC+broadcast design; new protocol consts
- Ghidra reverse-engineering task checklist (T1-T6, anchored on known strings, self-check against measured packet sizes)
- **ghidra**: T1 solved - TCP keepalive is 20B plaintext frame (0x45 header, 0xff00 opcode, 30s default interval), corrects 200ms pktmon assumption; headless Ghidra 12.2 pipeline documented
- **ghidra**: T2+T3 solved - data plane is raw IP packets over TLS (no envelope, MPFR placeholder obsolete), keepalive=fake IPv4 proto 255, 16B config frames P/Q/U, /vpntunnel request headers confirmed
- **adapter**: stale wintun 0.3 comment -> 0.5 (follow-up to 993b564)
- 发布架构实施计划 plan-release.md（win=sidecar UAC / linux=systemd，核心功能红线）

### 📦 构建
- **bundle**: cross-platform packaging smoke - full icon set (gen_brand_icons 1024 source + tauri icon: icns/multi-size ico/pngs), bundle.targets=all, release profile strip/lto/cgu=1, CI bundle matrix (win=nsis verified locally 2.4MB, linux=deb+appimage, mac=app+dmg) with artifact upload; fix tun dep dislodged from workspace.dependencies by profile edit, drop unused mp-daemon workspace dep
- **linux**: real deb built+installed on Ubuntu - wsl-tauri-deb.sh produces MotionPro_0.1.0_amd64.deb (desktop entry, hicolor icons, /usr/bin/mp-app), wsl-deb-install.sh verifies dpkg -i, ldd, 5s WSLg gui smoke (alive), clean dpkg -r; pnpm>=10 build approval via pnpm-workspace.yaml allowBuilds (onlyBuiltDependencies removed in pnpm 11), CI pnpm 9->12

### 🔧 杂项
- monorepo skeleton (mp-core/mp-daemon/mp-platform/mp-ipc) + docs + reference assets
- prepare for public GitHub release — gitignore sensitive/temp files, anonymize server/account identifiers, add AGENT.md for AI self-iteration
- move reference samples out of git (internal storage + checksums), CI adds frontend build job
- **cleanup**: zero cargo check/clippy warnings, prune dead dependencies
- **deps**: wintun 0.3 -> 0.5 - drop windows 0.51 core tree
- **platform**: drop dead TunAdapter::read_packet/write_packet (zero callers since SessionHandle/async-bridge split), remove duplicate tools/wintun.dll (identical copy tracked at crates/mp-daemon/wintun/ which build.rs reads)
- 发布命名统一为 vibe-motion-pro（产品名 VibeMotionPro）

### 🤖 CI
- trigger only on master (push/PR), skip dev branch builds
- trigger only on master (push/PR), skip dev branch builds
- pause macOS from all matrices and bundle steps (win/linux only for now) - restoration notes left inline

### 🧪 测试
- **netcfg**: update dry-run route assertions for stale-route purge - add_route now emits route delete before each add
- **linux**: WSL Ubuntu runtime smoke - mp-daemon musl static binary starts, IPC status round-trip over loopback, shared musl env script (linux-musl-env.sh) for test/build/smoke; docs: linux support status in TODO
- **linux**: kernel-level root nettest - real tun create (mp-tun honored, address assigned, device gone on drop) + real ip-route-replace install/remove + resolvectl dns takeover/revert, all verified against live kernel in WSL Ubuntu via sudo; wsl-apt-deps.sh installs tauri linux build deps + node/pnpm for real deb bundling; musl env prefers system cc once available

