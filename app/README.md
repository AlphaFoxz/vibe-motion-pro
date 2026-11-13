# mp-app (Tauri 2 UI)

对应原版 MotionPro.exe（Qt5 Widgets UI）。

初始化步骤（待执行）：
```bash
pnpm create tauri-app  # 或手动集成 tauri v2
```
- 前端：建议 Vite + TS（Vanilla/React 皆可）
- 依赖 mp-daemon 通过 mp-ipc 提供连接控制
- 托盘三态图标：connected / disconnected / reconnecting（可从 reference/ 提取原版 ico）
- i18n：zh-CN / en / ja（对齐原版 qm 文件）

注意：Tauri 构建需要 MSVC 工具链，当前机器缺 Windows SDK；
Rust 侧先用 GNU 工具链开发，Tauri 初始化前需安装 Windows 10 SDK（VS Installer → "使用 C++ 的桌面开发" 工作负载勾选 SDK）。
