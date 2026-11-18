#!/usr/bin/env bash
# mp-daemon 开发版 systemd 服务（原生 Linux 开发机，需 sudo 执行）。
#
# 用法：
#   sudo bash scripts/install-daemon-dev-service.sh             # 安装并启动（开机自启）
#   sudo bash scripts/install-daemon-dev-service.sh uninstall   # 停止并卸载
#
# 设计（docs/runbook.md §2.2）：
# - ExecStart 指向本仓库 target/release/mp-daemon；改代码后
#   cargo build -p mp-daemon --release && sudo systemctl restart mp-daemon-dev 即生效。
# - 环境与发布 unit（scripts/deb-inject-service.sh）一致：
#   MP_PROFILES=/var/lib/vibe-motionpro/profiles.toml + RUST_LOG=info。
# - 用独立名 mp-daemon-dev（非 mp-daemon），避免 /etc 下的 unit 将来遮蔽
#   正式 deb 安装到 /lib/systemd/system 的同名 unit。
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN="$ROOT/target/release/mp-daemon"
UNIT=/etc/systemd/system/mp-daemon-dev.service

[ "$(id -u)" -eq 0 ] || { echo "请用 sudo 执行" >&2; exit 1; }
[ -x "$BIN" ] || { echo "daemon 未构建：先 cargo build -p mp-daemon --release" >&2; exit 1; }

case "${1:-install}" in
install)
  # profile 目录预建（daemon 不保证自建父目录）
  install -d -m 0755 /var/lib/vibe-motionpro
  cat > "$UNIT" <<EOF
[Unit]
Description=VibeMotionPro VPN daemon (dev build from repo target)
After=network.target

[Service]
Type=simple
ExecStart=$BIN
# 固定路径：root 服务与用户手跑 daemon 不共享 ~/.config，避免数据分叉
Environment=MP_PROFILES=/var/lib/vibe-motionpro/profiles.toml
# journal 里保留 info 级日志（bind/连接/广播），排障必需
Environment=RUST_LOG=info
Restart=on-failure
RestartSec=2

[Install]
WantedBy=multi-user.target
EOF
  systemctl daemon-reload
  systemctl enable --now mp-daemon-dev.service
  echo "已安装并启动 mp-daemon-dev.service（日志：journalctl -u mp-daemon-dev -f）"
  ;;
uninstall)
  systemctl disable --now mp-daemon-dev.service
  rm -f "$UNIT"
  systemctl daemon-reload
  echo "已卸载 mp-daemon-dev.service（/var/lib/vibe-motionpro 保留）"
  ;;
*)
  echo "未知动作: $1（可用：install / uninstall）" >&2
  exit 1
  ;;
esac
