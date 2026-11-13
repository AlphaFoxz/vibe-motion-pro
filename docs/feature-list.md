# MotionPro 功能清单（重写范围基线）

依据：OEM.ini（`reference/installer/OEM.ini`）、用户配置 motionpro.ini（`reference/config/`）、
安装包资源（托盘图标 connected/disconnected/reconnecting、oauth.png）、UI 字符串。

## 1. 连接核心

- [ ] SSL VPN 连接（HTTPS `/vpntunnel` 握手 + TCP 隧道）
- [ ] UDP 隧道模式（可禁用，`Disable_UDP_Tunnel` / `VPNTunnelProtocol`）
- [ ] DTLS 加速隧道
- [ ] WireGuard 隧道（`ArrayStartVPNClientW_WG`，TunSafe TCP 混淆 `ObfuscateKey`）
- [ ] 驱动模式 / 无驱动用户态模式（`NoDriver` 系列 API，`VirtualNetworkCardType`、`SSTPAdapterPort=65443`）
- [ ] Full tunnel / Split tunnel（`ArraySetAccessMode`、`ArraySetDomainList`）
- [ ] IPv6 隧道支持
- [ ] MTU 设置（`mtu_value`、`ArraySetMTUAndTAF`）
- [ ] 接口跃点数 `InterfaceMetric`

## 2. 认证与账号

- [ ] 账号/密码登录（含 OEM 自定义多密码框 labPwd/labPwd2/labPwd3、SMS 密码 labPwdSMS）
- [ ] OAuth 登录（安装包含 oauth.png）
- [ ] AAA 认证方式选择（`ArrayGetAAAMethodInfo` / `ArraySetAAAMethodNameW`）
- [ ] 客户端证书认证（`ArraySetClientCertAuthRule`、server.p12、`MachineCertFlag`）
- [ ] Windows 自动登录（`DisableAutoLoginWindows`、windows_username/password）
- [ ] 服务器证书校验（`ArrayVerifyServerCert`、rootca.crt、Firefox 根证书信任 `DisableFFTrustSystemRootca`）
- [ ] 硬件指纹 HWID（`HWIDType=100`、`HWIDDomainType`、vpnhwidtool）
- [ ] 改密检查（`DisableCheckOldPwd`）
- [ ] 授权密码 `AuthorizePwdDown`
- [ ] SKF 国密 U 盾（`[GMSKF]` sslproto/skfdriverlist、`GetSKFDriver*`）

## 3. 会话管理

- [ ] 自动重连（`ArraySetReconnectParameters`，三态：connected/disconnected/reconnecting）
- [ ] 心跳保活（`ArraySetKeepaliveOption`、TCP/UDP keepalive、RTT 测速）
- [ ] 会话复用（`ArraySetSessionReuse`）
- [ ] 断线顶号提示（"user login again, current session will be terminated"）
- [ ] 自动连接（`autoconnect`、`EnableBestWay` 最佳线路）
- [ ] 开机自启（`autorun`、`autorun_only_outside` 仅外网时）
- [ ] 锁屏断开 `lockscreen`

## 4. 网络/DNS

- [ ] DNS 代理（`[DNSProxy]`：DNSProxyType=4、hosts、redirect；`ArrayEnableDNSProxy`）
- [ ] 静态 DNS host 映射
- [ ] 内网网段/端口设置（`EnableClientSubnet`、`intranet_port/ip`）
- [ ] 上游代理支持（InsideProxy：Basic/NTLM 代理认证）
- [ ] 本地 DNS 丢弃标志 `SetLocalDNSDropFlag`
- [ ] PPPoE `PPPoEFlag`

## 5. Web Portal / 资源

- [ ] Web portal 展示（`ShowWebPortal`，`MotionProHttpd.exe` 本地 9090 服务、`/prx/000/...` 代理路径、appicon）
- [ ] Web 资源开关 `ShowWebResource`、DesktopDirect 资源 `ShowDDResource`（含窗口尺寸 DDSize）
- [ ] 连接后自动打开浏览器（`LaunchWebAfterConnected`、`LaunchURL`、`BrowserType/Path`）
- [ ] 托盘左键行为 `LeftClickWebPortal`
- [ ] H5 边缘检测 `H5EdgeDetect`

## 6. 客户端安全检查

- [ ] 客户端安全检查 V5（`EnableClientSecurityV5`、MyClientSecurity 目录、`client_sec/l3vpn` 路径）
- [ ] 清除 IE Cookie `ClearIECookie`
- [ ] 配置文件备份 `ProfileBackupType`、profile 自动导入（`ProfileAutoImport`、`MPProfileUrl`）

## 7. UI / 多语言

- [ ] 托盘三态图标（connected/disconnected/reconnecting.ico）
- [ ] 中/英/日三语（qt_zh_CN.qm、vpn_zh_CN.qm、qtbase_ja.qm、vpn_ja.qm）
- [ ] Profile 管理（多服务器配置，`[profiles]`、`default_profile`、btnaddprofile）
- [ ] 连接后显示/隐藏 UI（`ShowUIAfterConnected`、`ShowMenuAfterConnected`、`DisplayTabwidget`）
- [ ] OEM 文案定制（`[OEMString]` 全部标签自定义）
- [ ] OEM 品牌定制（CompanyName/ApplicationName/logo.bmp/application.ico）
- [ ] 虚拟键盘密码输入 `AuthorizePwdDown`（软键盘）

## 8. 更新与分发

- [ ] 自动升级检查（`DisableClientUpgrade`）
- [ ] 安装时导入根证书（rootca-add-nsis.bat、cert.vbs）
- [ ] 安装/卸载可选 PKG（`[InstallPKG]`/`[UninstallPKG]`/`[KillPKGProcess]`）
- [ ] 桌面快捷方式 `CreateShortcut`
- [ ] 升级：保留原 `RetainCurrentConfig` 语义

## 重写裁剪建议

- Windows 专属项（TDI 驱动 `InstallTDIonWin7`、SSTP 路由监视、IE Cookie）→ 跨平台版本仅 Windows 实现或裁剪
- `SSLeay/libeay`（OpenSSL 1.0）→ rustls
- `webportal` 本地 httpd → Tauri 侧窗口或轻量 HTTP 服务（axum）
