# AGENT.md — AI 自迭代说明

本项目（**vibe-motion-pro**，产品名 VibeMotionPro：MotionPro VPN 跨平台重写）是一个**以 AI 自主迭代为主要开发方式**的仓库。
任何 AI agent（或人类协作者）接手时，请遵循以下宽松约定，积极、大胆地维护仓库。

## 核心原则

- **积极维护文档**：文档与代码同等重要。发现文档过时、与代码不一致，直接修改，不需要请示。
- **大胆删改**：过时的方案、被推翻的假设、冗余的段落，直接删除或重写。历史通过 git 保留，不必在文件里留"废弃""已修改"之类的水印。
- **自规划、自实现、自测试**：接手任务后自行拆解增量、写代码、跑 `cargo test --workspace` 全绿后提交。
- **每次实质变更都要 commit**，message 用 `type: summary` 格式（feat/docs/fix/chore）。

## 技术选型：宽松约定（可被证据推翻）

- 主线是 **Rust 核心 + Tauri 2 UI**，但这不是教条。若某部分用其他方案明显更优（如某平台组件用 C、协议分析脚本用 Node），直接采用并在相关文档记录一句理由即可。
- 架构对齐原版运行时行为（见 `docs/runtime-forensics.md`），优先级高于任何事先设计。

## 命名规范（发布身份，以 GitHub 仓库名 vibe-motion-pro 为准）

| 用途 | 值 | 来源/说明 |
|---|---|---|
| 仓库/包名 | `vibe-motion-pro` | GitHub 仓库名，本地目录名可以不同 |
| 用户可见产品名 | `VibeMotionPro` | `mp_core::APP_NAME`；无空格（安装包/安装目录/快捷方式路径免转义） |
| 应用标识 | `com.alphafoxz.vibemotionpro` | `mp_core::APP_ID` = tauri.conf.json identifier；无连字符（注册表/DBus 兼容）；**发布后不可改** |
| 配置/数据根目录 | `<config_dir>/com.alphafoxz.vibemotionpro/` | UI（Tauri 自动派生）与 daemon（显式 join APP_ID）同根 |
| 临时目录 | `<temp>/com.alphafoxz.vibemotionpro/` | 崩溃栈、协议帧 dump |
| 凭据服务名 | `VibeMotionPro`，key `vpn-pass:<profile_id>` | OS 凭据管理器/Keychain/Secret Service |
| 内部 crate/二进制 | `mp-core` / `mp-daemon` / `mp-platform` / `mp-ipc` / `mp-app` | 内部命名，不发布 crates.io，无需跟随产品改名 |

**刻意保留 `MotionPro` 字样的位置**（协议兼容/取证记录，不要“顺手”改名）：
- 注册表 `HKCU\Software\MotionPro\L3VPN`（读取原版客户端设备身份，服务器侧已绑定该 HWID）
- 门户 URL `/prx/000/http/localhost:65200/motionpro/postlogin/apps`（服务器契约）
- `docs/protocol-clues.md`、`docs/runtime-forensics.md`、`docs/ghidra-tasks.md` 等（描述对象是原版二进制）

## 文档结构（自由增删）

- `TODO.md` — 总待办（checkbox 格式，完成就打勾）
- `docs/protocol-clues.md` — 原版二进制静态分析线索
- `docs/runtime-forensics.md` — 运行时动态取证
- `docs/feature-list.md` — 功能基线
- `docs/plan-phase2.md` 等阶段计划 — 阶段结束后可归并/删减
- AI 可以随时新增、合并、拆分文档，只要 TODO.md 里的索引仍然成立

## 红线（不可自动化违反）

1. **不要提交敏感信息**：真实服务器地址、账号、证书私钥（`reference/config/server.p12` 已 ignore）。示例一律用 `vpn.example.com` / `203.0.113.x` / `example_user`。
2. **`reference/`（逆向参考样本）不入库**，存内部存储；不要把大样本文件加进 git，完整性用 `docs/reference-checksums.md5` 校验。
3. 提交前确认 `cargo test` 通过（default-members 四个 crate；Windows 需 MSVC 环境）。涉及 UI 壳时另跑 `cargo check -p mp-app`（需先 `pnpm build` 出 dist）。

## 环境

- Windows 10/11 + MSVC（SDK 已装）+ Node/pnpm + Rust stable
- 抓包需管理员：`pktmon` → `pktmon etl2pcap` → `scripts/parse_pcap.js`
- pnpm 需 `--registry=https://registry.npmjs.org`（镜像不通）
