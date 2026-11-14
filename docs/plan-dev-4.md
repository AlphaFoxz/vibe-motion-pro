# dev-4 实施记录：真实虚拟网卡 + 路由/DNS 执行 + 数据面接线

日期：2026-11-14　状态：完成（58 测试全绿）

## 目标

在数据帧格式仍待 Ghidra（T1-T6）的前提下，把与协议无关的
「虚拟网卡 / 路由 / DNS / 数据面桥接」整条链路做完，
帧格式确认后即可端到端联通。

## 交付

### mp-platform
- `adapter.rs`：真实 TUN 适配器（`tun` crate：Windows=wintun.dll / Linux=/dev/net/tun / macOS=utun）
  - `TunConfig`（名称/隧道内 IP/掩码/MTU=1400，MTU 对齐原版预留隧道开销）
  - `TunAdapter::open/read_packet/write_packet`（阻塞语义，供独立线程）
  - `pump_in/pump_out`：内核 ⇄ mpsc 桥接线程循环体（阻塞 IO 与 async 解耦）
- `netcfg.rs`：`CommandRunner` trait（SystemRunner 真执行 / DryRunRunner 演练可测）
  - `RouteManager`：add_route（按平台拼 route add/ip route/route -n add，指向虚拟网卡网关）
  - DNS：Windows=netsh set+add dns（多 DNS）；macOS=networksetup；Linux=resolvectl
  - `set_dns` 记录还原命令（Win=DHCP / mac=empty / Linux=revert），`revert()` 逆序回滚路由+DNS，幂等

### mp-core
- `dataplane.rs`：
  - 新增 `ChannelAdapter`（mpsc pair + try_recv/try_send，队列满丢弃不拖死数据面）
  - 新增 `Dataplane::pump(adapter)`：网卡 → smoltcp iface.poll → 回写网卡（一轮真实推进）

### mp-daemon
- `netloop.rs`：`spawn_dataplane_task`（spawn_blocking poll 循环，5ms 间隔）+
  `TunnelIo`（组装 ChannelAdapter/数据面/net 端点，async shutdown 幂等）

## 测试

- mp-platform 9：路由下发/逆序回滚/幂等 revert、DNS set+restore、非法输入拒绝、tun 格式化
- mp-core 3+37：ChannelAdapter 跨线程桥接、pump 驱动、原骨架回归
- mp-daemon：TunnelIo 运行+垃圾包不 panic、shutdown 幂等、IPC/广播/Profile CRUD 回归

## 遗留

- wintun.dll 随包分发（阶段4 打包项）；真实网卡开/关需管理员，仅联调验证
- pump 循环的 TCP/UDP socket 建立（对内监听/对外拨号）待 NAT 分流策略确认后接入
- 数据帧格式（T1-T6）→ 帧确认后 TunAdapter ⇄ frame 编解码对接即闭环
