# 阶段2 实施计划：协议与隧道实现

## 原则

- 真实服务器协议字段尚未完成 Ghidra 深度反编译，因此本阶段**先搭可运行、可测试的骨架**，
  协议字段用 trait 抽象隔离，逆向确认后只改实现不改架构。
- 一切可离线测试：状态机、帧编解码、IPC、重连退避均配单元/集成测试（`cargo test`）。
- 数据面使用 smoltcp 做用户态 TCP/IP 栈（对齐原版 vl3vpn.dll 的 lwIP 方案）。

## 增量划分（每步带测试）

### E1 IPC 层（mp-ipc）
- [x] ndjson 行协议编解码（Request/Response）
- [x] 传输抽象 `Transport`：TCP loopback（开发/测试）+ Windows named pipe / Unix socket（生产）
- [x] 集成测试：客户端-服务端请求往返

### E2 状态机与会话管理（mp-core）
- [x] `VpnStatus` 状态机：Disconnected → Connecting → Connected → Reconnecting，非法迁移拒绝
- [x] 心跳保活与超时检测（tokio interval + miss 计数）
- [x] 指数退避自动重连（max_attempts 可配，还原 `ArraySetReconnectParameters` 语义）
- [x] 单元测试：迁移合法性、退避序列、心跳丢失触发重连

### E3 隧道帧协议（mp-core::frame）
- [x] 隧道数据帧编解码：magic + version + type + len + payload（占位设计，逆向确认后替换 magic/字段序）
- [x] 帧类型：Data / KeepAlive / Control(Rekey) / Close
- [x] fuzz-ish 测试：截断/坏 magic/超长 payload 拒绝
- [x] TODO(逆向)：`GET %s/vpntunnel HTTP/1.1` 握手报文格式、cookie/session 字段映射

### E4 数据面（mp-core::dataplane）
- [x] smoltcp 接入（Adapter trait + MockAdapter + smoltcp Device 桥接）：虚拟网卡读写 ↔ smoltcp Interface
- [ ] TCP/UDP 会话分流与 NAT 表
- [ ] 待 Windows SDK/真实网卡后做端到端测试，本步先接口 + 假适配器测试

### E5 引擎与守护进程组装（mp-daemon）
- [x] `Engine`：持有状态机 + 重连策略，响应 IPC Request
- [x] daemon main：IPC server 启动、指令分发
- [x] 集成测试：spawn daemon 逻辑引擎 -> 发 Start/Status/Stop

## 验收标准（阶段2骨架完成）

- `cargo test --workspace` 全绿（GNU 工具链）
- daemon 可启动并通过 IPC 完成 Start/Status/Stop 往返（TCP loopback 模式）
- 协议字段占位点全部集中在 `mp-core::protocol` 一处，逆向就绪后替换
