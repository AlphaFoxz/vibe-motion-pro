# dev 迭代计划（第 2 轮）

分支：dev（CI 仅 master 触发）。每项实现配测试，全绿后 commit。

## D1 daemon 状态广播器
- [x] mp-daemon 增加 1 秒周期广播（tick_broadcast 返回 Option，变更才广播）（对齐原版 vpnd `send message to clients: cmd 1`）
- [x] handle_conn 用 select!（+ 持久 BufReader 修复丢包卡死） 同时处理「客户端请求」与「服务端主动推送」
- [x] 测试：状态变更推送、无变化不推送/状态变更推送

## D2 Profile 管理（多服务器配置）
- [x] mp-core::profile：Profile{id,name,host,port,tunnel_type,autoconnect}，TOML 持久化
- [x] daemon Start 按 profile_id 查表；新增 IPC ListProfiles / AddProfile / RemoveProfile；新增 IPC ListProfiles / AddProfile
- [x] 测试：TOML 往返、默认 profile、IPC CRUD、默认 profile、查表连接

## D3 UI i18n（中/英/日）
- [x] app/src/i18n.ts 三语字典 + 切换
- [x] index.html + main.ts 接入（语言切换持久化 localStorage）
- [x] vite build 验证
