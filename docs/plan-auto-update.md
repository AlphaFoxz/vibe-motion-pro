# plan-auto-update：应用自更新（Windows 应用内更新 / Linux 检查引导）

> 状态：**规划完成，待实施**（2026-11-22）。对齐已落地的发布架构
> （[plan-release.md](plan-release.md)：win=sidecar UAC / linux=deb+systemd），
> 取代早期的 updater 骨架草案。

## 背景

当前无任何自更新机制（`tauri.conf.json` 无 `plugins.updater` / `createUpdaterArtifacts`，
未引入 `tauri-plugin-updater`，无签名密钥）。用户升级只能手动下载安装包覆盖安装。

发版流程见 `.github/workflows/release.yml`：tag `v*` → prepare 校验 → 双平台 build →
release job（git-cliff 生成改动日志 + 发布 GitHub Release）。

## 目标 / 非目标

**目标**

1. Windows：发布新版后，旧版应用内检测 → 下载 → 安装，无需用户手动找安装包
2. Linux（deb）：应用内检测新版本并引导到下载页（实际升级仍走 dpkg/apt）
3. 版本号单一来源不变：`tauri.conf.json`（`scripts/version.mjs` 统一升降），
   updater 用它与清单版本做 semver 比较

**非目标**

- deb 应用内安装（Tauri updater 不支持 deb）
- 自动回滚 / 降级（Release 页保留历史安装包，手动回退）
- macOS（未分发）
- 自动重连：重连需要手机动态密保码，更新后必须由用户手动重连

## 关键约束（决定方案形态的事实）

| # | 事实 | 影响 | 对策 |
|---|---|---|---|
| 1 | Windows 上执行 install 时**应用被强制退出**（安装器限制，Tauri 文档） | UI 退出 → VPN 断 | 下载完成后才进入该步骤，见 #3 |
| 2 | daemon 是随 UI 存亡的 sidecar（`--managed`，父进程死后 3s 退出），且以**管理员**权限运行 | 安装器是普通权限，无法结束提权进程；`mp-daemon.exe` 被占用则覆盖失败，应用已退出 → 用户手里没有可用应用 | install 前经新增 **`Shutdown` IPC** 让 daemon 主动退出并确认，超时则中止更新（P1） |
| 3 | 重连需动态密保码 | 更新后无法静默恢复连接 | 连接态更新需二次确认；文案明确「更新后需重新连接」 |
| 4 | NSIS 未配 `installMode` = `currentUser`（装 `%LOCALAPPDATA%`） | 更新安装本身不需要提权 | 无需处理；若日后改 `perMachine` 需重评（passive 模式安装器不能自行提权） |
| 5 | Tauri updater 不支持 deb | Linux 无法应用内安装 | 检查 + 引导下载（P4） |
| 6 | AppImage 产物**不含 Linux daemon**（Linux 上 UI 不拉起 daemon，服务只注入 deb） | AppImage 独立不可用 | 不纳入更新支持；去留见「待决策」 |
| 7 | updater 会**全量校验** `latest.json` 的所有平台条目 | 不能放不完整的 linux 条目 | 只写 `windows-x86_64` |
| 8 | 开启 `createUpdaterArtifacts` 后，**没有私钥的构建直接失败** | `ci.yml` 的 bundle job 与本地 `pnpm tauri build` 会红 | 无密钥构建统一加 `--config '{"bundle":{"createUpdaterArtifacts":false}}'`（P0 同批改） |
| 9 | 公钥烧入已安装客户端 | 私钥丢失 = 存量用户永久收不到更新，只能手动重装 | 私钥 + 密码离线备份（P0） |
| 10 | ≤ 0.1.3 的已安装版本没有 updater | 存量用户收不到首个带 updater 的版本 | 公告手动安装一次 ≥ 首发版本 |

已核实的前提：Rust ≥ 1.90（本机 1.100，CI 用 stable）；仓库 public，用户机器可访问
GitHub（更新源定为 GitHub Releases）；updater 支持 `download()` 与 `install()` **分步调用**。

## 架构

```
启动 +8s ──check()──┬─ 无更新 / 请求失败：静默（4h 后重试）
                    └─ 有更新：顶部横幅「发现新版本 vY  [立即更新] ×」
用户点击 ─(已连接？二次确认)→ download() 进度条
        → daemon_shutdown()：Shutdown IPC + 等 62000 释放（≤10s）
        ├─ 已退出 → install()：应用退出 → NSIS passive 安装 → 应用重启
        │            → 新 UI 自动 UAC 拉起新 sidecar → 用户手动重连
        └─ 未退出 → 中止安装，横幅报错，应用继续可用（旧 daemon 仍在跑）

Linux(deb)：同一横幅，按钮为「前往下载」→ 打开 GitHub Release 页
```

## P0 密钥与插件接入

- [ ] 生成签名密钥：`pnpm tauri signer generate -w ~/.tauri/vibemotionpro.key`（设密码）。
      公钥写入 `tauri.conf.json`；**私钥文件 + 密码离线备份**（密码管理器）
- [ ] GitHub Secrets：`TAURI_SIGNING_PRIVATE_KEY`、`TAURI_SIGNING_PRIVATE_KEY_PASSWORD`
- [ ] 引入插件：`pnpm tauri add updater`（Rust `tauri-plugin-updater` +
      JS `@tauri-apps/plugin-updater`），builder 注册
      `.plugin(tauri_plugin_updater::Builder::new().build())`
- [ ] `tauri.conf.json`：

```jsonc
{
  "bundle": { "createUpdaterArtifacts": true },
  "plugins": {
    "updater": {
      "pubkey": "<公钥内容，不能是文件路径>",
      "endpoints": [
        "https://github.com/AlphaFoxz/vibe-motion-pro/releases/latest/download/latest.json"
      ],
      "windows": { "installMode": "passive" }
    }
  }
}
```

- [ ] capabilities 加 `updater:default`（check / download / install / download-and-install）
- [ ] `ci.yml` bundle job（双平台）与 README/runbook 的本地构建说明：无密钥构建加
      `--config '{"bundle":{"createUpdaterArtifacts":false}}'`（约束 #8）

## P1 daemon 优雅退出（Shutdown IPC）

更新安装的前置条件（约束 #2），也是本计划风险最高的环节。

- [ ] `mp-ipc`：`Request::Shutdown`
- [ ] `mp-daemon`：**仅 managed 模式响应**——置退出标志，走既有清理路径
      （隧道关闭 / 路由与 DNS 回滚）后 `exit(0)`；非 managed 返回 `Error`
      （防止被用来停掉 Linux 的 systemd 服务）
- [ ] `mp-app` 命令 `daemon_shutdown()`：发请求 → 等 62000 释放（上限 10s）→ `Ok` / `Err`
- [ ] 测试：IPC 往返、非 managed 拒绝、managed 退出路径复用既有清理

## P2 Windows 更新 UI 流程

- [ ] 顶部横幅 `update-banner`（非模态，info 风格）：「发现新版本 vY」+ 按钮 + 关闭
- [ ] 触发：启动后延迟 8s（避开启动期的 UAC 拉起与首连），之后每 4h 一次；失败一律静默
- [ ] 托盘菜单加「检查更新…」：有更新 → 显示主窗口 + 横幅；已最新 → 通知「已是最新版本」
- [ ] 连接态点击更新 → 二次确认「更新将断开 VPN 连接，完成后需重新连接」
- [ ] **必须分步**：`update.download(onEvent)`（横幅内进度条）→ `daemon_shutdown` 成功
      → `update.install(path)`。禁止使用一步式 `downloadAndInstall`
- [ ] 失败恢复：下载失败 / 签名校验失败 / daemon 未退出 → 横幅报错并可重试，应用保持可用
- [ ] 关闭横幅后本次会话不再提示；下次启动仍检查（不做「跳过此版本」）
- [ ] i18n 三语言文案

## P3 CI：签名构建 + latest.json

- [ ] `release.yml` build(windows)：注入两个签名 env；artifact 增加 `*.sig`
- [ ] `scripts/gen-latest-json.mjs`（Node ESM，沿用现有脚本风格）：输入 `.sig` +
      `release-notes.md` + 版本 → 输出 `latest.json`

```jsonc
{
  "version": "0.1.4",
  "notes": "<git-cliff 本版本改动日志>",
  "pub_date": "<RFC 3339>",
  "platforms": {
    "windows-x86_64": {
      "signature": "<.sig 文件全文>",
      "url": "https://github.com/AlphaFoxz/vibe-motion-pro/releases/download/v0.1.4/<安装包文件名>"
    }
  }
}
```

- [ ] 在 release job 生成并上传（`notes` 来自该 job 产出的 `release-notes.md`）；
      不采用 tauri-action（它会接管 Release 创建，与现有 git-cliff 流程冲突）
- [ ] build(linux)：`--config` 关闭 updater 产物（deb 无产物，AppImage 不纳入）
- [ ] 发布后冒烟：`curl` 校验 `latest.json` 可取、JSON 合法、`url` 可达
- [ ] Windows updater 产物形态（`setup.exe` + `.sig`）以 CI 实际产出为准，上传用 glob 匹配

## P4 Linux：检查更新 + 引导下载

- [ ] Rust 命令 `check_latest_version`：GET 同一 endpoint，解析 `version` 并做 semver 比较，
      返回 `{ version, notes?, url }`。不走 updater 的 `check()`（Linux 下要求 AppImage 环境）。
      HTTP 客户端建议 `ureq`（rustls，阻塞调用放 `spawn_blocking`），版本比较用 `semver`
      （tauri 已依赖，不增加编译量）。此路径只做提示，不校验签名——Windows 的安装仍由
      updater 校验
- [ ] 横幅按钮「前往下载」→ opener 插件打开 `https://github.com/AlphaFoxz/vibe-motion-pro/releases/latest`
- [ ] 可选：`deb-inject-service.sh` 的 `prerm` 按 `$1` 分支处理（升级时只 stop 不 disable，
      postinst 重新 start 到新二进制）

## P5 端到端验证与首发

- [ ] 以 **0.1.4 作为首个带 updater 的版本**发布；验证 0.1.4 → 0.1.5 的升级链路
- [ ] CI 全流程演练建议在 fork 仓库进行（`prepare` 要求 tag 与 `tauri.conf.json` 版本严格
      一致，无法用 `-rc` 标签在正式仓库演练）
- [ ] 文档同步：README 平台速览表加「升级」一行；TODO.md 阶段4 索引；
      plan-release.md 风险清单交叉引用

## 验证清单

- [ ] Windows 干净机：装首发版 → 发布下一版 → 启动后横幅出现 → 更新 → 进度窗 →
      应用重启为新版本（标题与托盘版本号一致）
- [ ] 连接态更新：二次确认 → **下载完成前 VPN 不断** → daemon 无残留进程 →
      安装成功（sidecar 未被占用）→ 新 UI 拉起新 daemon（UAC 一次）→ 用户可重连
- [ ] daemon 未能退出：更新中止，横幅报错，旧应用与连接保持可用
- [ ] 篡改 `latest.json` 的 signature 或替换产物 → 校验拒绝
- [ ] 无网络 / GitHub 不可达 → 静默，无报错弹窗
- [ ] 已是最新 → 静默；手动检查 → 通知「已是最新版本」
- [ ] Linux deb：横幅提示 + 浏览器打开 Release 页
- [ ] 覆盖更新后 sidecar（`mp-daemon.exe`、`wintun.dll`）完整可用
- [ ] `ci.yml` 无密钥构建通过；`release.yml` 产物齐全（安装包 / `.sig` / `latest.json`）
- [ ] ⚠ passive 安装器是否自动重启应用——实测确认；若不重启，在横幅文案或
      NSIS hook 中处理
- [ ] ⚠ NSIS 安装器对「仍在运行的主程序」的处理不涉及 sidecar——以实测为准

## 风险清单

| 风险 | 缓解 | 状态 |
|---|---|---|
| sidecar 被占用导致更新半途失败 | Shutdown IPC + 确认退出 + 超时中止 | 待实施 |
| 更新中断 VPN、更新后需手动重连 | 下载后才断；二次确认；文案说明 | 产品既定 |
| 私钥丢失 / 泄露 | 离线备份；泄露时轮换公钥（updater 支持 Rust 侧运行时设置 pubkey） | 轮换逻辑本期不做 |
| GitHub 短时不可达 | 静默失败不影响使用；`endpoints` 是数组，日后可加内网地址兜底 | 可接受 |
| 存量 ≤ 0.1.3 用户收不到更新 | 公告手动安装一次 | 一次性 |
| 安装失败无自动回滚 | Release 页保留历史安装包 | 可接受 |
| 新 UI + 旧 daemon 混跑（覆盖不完整时） | Shutdown 确认后才安装；IPC 变更保持向后兼容 | 待验证 |
| IPC 无鉴权（既有设计）：本机任意进程可发 `Stop` / `Shutdown` | `Shutdown` 仅 managed 模式生效，影响面等同 `Stop` | 记录，不在本期范围 |

## 待决策

- **AppImage 去留**：当前产物不含 Linux daemon，独立不可用，也不纳入更新支持。
  建议从 release 产物移除，或仅作为「已安装 deb 服务的机器上的免安装 UI」并在文档注明。

## 实施顺序与提交纪律

- 顺序：P0 → P1 → P2 → P3 → P4 → P5（P4 可与 P2/P3 并行）
- **P0 必须同批改 `ci.yml`**：配置一旦开启 `createUpdaterArtifacts`，无密钥的构建即失败
- 每阶段独立 commit（`feat(updater): p0 keys and plugin` 风格），完成即更新本文档
  checkbox 与 TODO.md 索引
- 提交前 `cargo test --workspace` 全绿；涉及 UI 壳时 `pnpm build` 后 `cargo check -p mp-app`
