# 计划：应用自更新机制（Tauri Updater）

> 状态：**待实施（当前阶段不做）**。本文档仅记录方案与实施步骤，供后续发版阶段参考。

## 背景

当前项目基于 Tauri 2 打包，发版流程见 `.github/workflows/release.yml`（tag `v*` 触发，Windows 走 NSIS，Linux 走 deb + AppImage）。

现状：

- **没有任何自更新机制**：`tauri.conf.json` 无 `plugins.updater` / `createUpdaterArtifacts`，Rust 侧无 `tauri-plugin-updater`，也未配置更新签名密钥。
- 用户升级只能手动下载新版安装包覆盖安装（NSIS 默认支持覆盖安装到同一路径，用户数据保留）。

目标：发布新版（如 v0.1.1）后，旧版本应用能在应用内检测更新、下载并安装，无需用户手动下载。

## 方案（Tauri 2 官方 updater 插件）

使用 `tauri-plugin-updater` + GitHub Releases 作为更新源，更新清单指向 Release 中的 `latest.json`。

### 1. 生成签名密钥

```bash
pnpm tauri signer generate -w ~/.tauri/vibemotionpro.key
```

- 私钥内容 → GitHub Secrets：`TAURI_SIGNING_PRIVATE_KEY`
- 私钥密码（如有）→ GitHub Secrets：`TAURI_SIGNING_PRIVATE_KEY_PASSWORD`
- 公钥内容 → 写入 `tauri.conf.json` 的 `plugins.updater.pubkey`

### 2. 引入插件

- Rust（`app/src-tauri`）：`cargo add tauri-plugin-updater`，在 tauri builder 中 `.plugin(tauri_plugin_updater::Builder::new().build())` 注册。
- 前端：`pnpm add @tauri-apps/plugin-updater`（如需权限配置，在 capabilities 中添加 updater 相关 permission）。

### 3. 配置 `tauri.conf.json`

```json
{
  "bundle": {
    "createUpdaterArtifacts": true
  },
  "plugins": {
    "updater": {
      "pubkey": "<公钥>",
      "endpoints": [
        "https://github.com/<owner>/<repo>/releases/latest/download/latest.json"
      ]
    }
  }
}
```

注意：`createUpdaterArtifacts: true` 会额外生成 updater 产物（Windows 为 `.nsis.zip` + `.sig`），常规 NSIS setup.exe 仍会正常产出，二者共存。

### 4. 前端更新逻辑

- 启动时（或设置页手动触发）调用 `check()` 检测更新；有新版则提示用户，确认后 `downloadAndInstall()` 并重启。
- 建议加"跳过此版本"与失败静默降级（仅手动检查时提示）。

### 5. 修改 `.github/workflows/release.yml`

- build 阶段注入环境变量：

```yaml
env:
  TAURI_SIGNING_PRIVATE_KEY: ${{ secrets.TAURI_SIGNING_PRIVATE_KEY }}
  TAURI_SIGNING_PRIVATE_KEY_PASSWORD: ${{ secrets.TAURI_SIGNING_PRIVATE_KEY_PASSWORD }}
```

- 传参启用 updater 产物（或在配置中已开启则无需传参）。
- release 阶段额外上传 `*.nsis.zip`、`*.sig`、`latest.json`（版本号与 tag 一致，校验逻辑沿用现有 prepare 阶段）。

### 6. Linux 说明

- AppImage 支持 updater；deb 走系统包管理器，updater 插件对 deb 的支持有限，可先仅对 Windows（NSIS）和 AppImage 启用应用内更新，deb 继续手动升级。

## 验证清单

- [ ] 发布 vX.Y.Z 后，旧版本应用能检测到更新并完成升级
- [ ] 签名校验通过（篡改产物应被拒绝）
- [ ] 覆盖更新后 sidecar（`mp-daemon.exe`、`wintun.dll`）完整可用
- [ ] 无更新时检查请求静默失败，不影响正常使用
- [ ] 版本号三处同步（`tauri.conf.json`、根 `Cargo.toml`、`app/package.json`）
