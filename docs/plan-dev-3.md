# dev 迭代计划（第 3 轮）

## D1 数据面 NAT / 会话表（mp-core::dataplane）
- [x] FlowKey（proto, src, sport, dst, dport）→ 会话表，增删/老化
- [x] 会话表 socket_ref 关联点（smoltcp handle 接入在 E5 联调时完成）：每 flow 一个 TcpSocket handle
- [x] 手工构造 IP 包测试（build_ip_packet + key/payload 提取）（手工构造 IP/TCP 包）

## D2 UI Profile 管理接 IPC
- [x] src-tauri 新 commands：profile_list / profile_add / profile_remove：profile_list / profile_add / profile_remove
- [x] 前端 Profile 面板（列表+点击连接+删除+添加）（列表 + 添加 + 删除）
- [x] vite build 验证

## D3 mp-platform 路由/DNS 命令骨架
- [x] Windows: route/netsh 命令构造（dry-run 可测）+ Linux ip route + macOS route / `netsh interface ip set dns` 命令构造（ dry-run 可测）
- [x] 测试：6 个命令拼装/掩码转换/校验测试（不实际执行系统命令）
