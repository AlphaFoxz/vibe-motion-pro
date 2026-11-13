# MotionPro VPN Client — 跨平台重写

原 Windows 版 MotionPro VPN 客户端（C++ / Qt5，仓库意外丢失）的跨平台重写项目。
目标：Windows / macOS / Linux 一比一功能复刻 + 技术升级，构建产物为原生应用。

> 本仓库以 **AI 自迭代**方式维护，协作约定见 [AGENT.md](AGENT.md)。

## 技术栈

- **核心/守护进程**：Rust（协议、TLS、隧道、状态机）
- **UI**：Tauri 2 + Vite + TypeScript
- **数据面**：smoltcp 用户态 TCP/IP 栈（对齐原版 lwIP 方案）
- **构建产物**：原生（各平台安装包）

## 仓库结构

```
crates/
  mp-core      协议核心（认证/会话/隧道帧/状态机/数据面）
  mp-daemon    特权守护进程（对应原版 vpnd/VPNService）
  mp-platform  各平台虚拟网卡/路由/DNS 封装
  mp-ipc       UI <-> daemon 本地 IPC（ndjson over loopback）
app/           Tauri 2 前端
docs/          逆向线索 / 运行时取证 / 功能基线 / 阶段计划（含原版样本校验和）
scripts/       抓包解析、图标生成等辅助脚本
```

> 原版 v1.2.26 逆向参考样本（二进制/安装包，约 95MB）**不入库**，存于内部存储；
> 完整性校验见 [`docs/reference-checksums.md5`](docs/reference-checksums.md5)，放到本地 `reference/` 目录即与文档配套使用。

## 现状

- [x] 阶段0：原版资产收集 + 静态/动态取证（协议时间线、状态枚举、心跳频率实测）
- [x] 阶段1：monorepo 骨架，33 个测试全绿（Windows MSVC）
- [x] 阶段2：IPC / 状态机 / 重连退避 / 隧道帧编解码 / smoltcp 数据面骨架
- [x] 阶段3（部分）：Tauri UI 骨架 + 托盘 + IPC 桥接
- [ ] 协议帧格式逆向（Ghidra 深度分析 vl3vpn.dll，样本在内部存储 reference/）
- [ ] UI 功能对齐、安装分发、验证发布

详见 [TODO.md](TODO.md)。

## 构建

```bash
cargo test --workspace        # Rust 侧（Windows 需 MSVC）
cd app && pnpm install --registry=https://registry.npmjs.org
pnpm tauri dev                # UI 开发
```

## 文档

| 文档 | 内容 |
|---|---|
| [TODO.md](TODO.md) | 总待办 |
| [docs/protocol-clues.md](docs/protocol-clues.md) | 原版二进制静态分析 |
| [docs/runtime-forensics.md](docs/runtime-forensics.md) | 原版运行时取证（进程拓扑/协议流/心跳实测） |
| [docs/feature-list.md](docs/feature-list.md) | 功能基线（8 大类） |

## License

Proprietary — 公司内部项目。
