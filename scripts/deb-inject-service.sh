#!/usr/bin/env bash
# deb 后处理：向 tauri 直出的 deb 注入 systemd 服务化的 mp-daemon。
# 用法：deb-inject-service.sh <in.deb> <mp-daemon 二进制> [out.deb]
#   <mp-daemon 二进制>：WSL 本地流用 musl 静态产物；CI 用 gnu release 产物。
#   [out.deb] 缺省时覆盖 <in.deb>。
# 设计依据 docs/plan-release.md P2：Tauri v2 对 maintainer scripts 支持不稳，
# 且 daemon 二进制来自独立构建，dpkg-deb -R/-b 后处理是最稳路径。
set -euo pipefail

in_deb="${1:?用法: deb-inject-service.sh <in.deb> <mp-daemon> [out.deb]}"
daemon_bin="${2:?缺少 mp-daemon 二进制路径}"
out_deb="${3:-$in_deb}"

[ -f "$in_deb" ] || { echo "deb 不存在: $in_deb" >&2; exit 1; }
[ -x "$daemon_bin" ] || { echo "daemon 二进制不存在或不可执行: $daemon_bin" >&2; exit 1; }

tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
dpkg-deb -R "$in_deb" "$tmp/root"

# tauri resources 直出的 sidecar 副本（占位 daemon / Windows wintun）——Linux 无用，清掉
find "$tmp/root" -type f \( -name 'mp-daemon.exe' -o -name 'wintun.dll' \) -delete

install -D -m 0755 "$daemon_bin" "$tmp/root/usr/bin/mp-daemon"

install -D -m 0644 /dev/null "$tmp/root/lib/systemd/system/mp-daemon.service"
cat > "$tmp/root/lib/systemd/system/mp-daemon.service" <<'UNIT'
[Unit]
Description=VibeMotionPro VPN daemon (mp-daemon)
After=network.target

[Service]
Type=simple
ExecStart=/usr/bin/mp-daemon
# 固定路径：root 服务与用户手跑 daemon 不共享 ~/.config，避免数据分叉
Environment=MP_PROFILES=/var/lib/vibe-motionpro/profiles.toml
# journal 里保留 info 级日志（bind/连接/广播），排障必需
Environment=RUST_LOG=info
Restart=on-failure
RestartSec=2

[Install]
WantedBy=multi-user.target
UNIT

install -D -m 0755 /dev/null "$tmp/root/DEBIAN/postinst"
cat > "$tmp/root/DEBIAN/postinst" <<'POSTINST'
#!/bin/sh
set -e
systemctl daemon-reload >/dev/null 2>&1 || true
systemctl preset mp-daemon.service >/dev/null 2>&1 || true
systemctl enable mp-daemon.service >/dev/null 2>&1 || true
systemctl start mp-daemon.service >/dev/null 2>&1 || true
POSTINST

install -D -m 0755 /dev/null "$tmp/root/DEBIAN/prerm"
cat > "$tmp/root/DEBIAN/prerm" <<'PRERM'
#!/bin/sh
set -e
systemctl stop mp-daemon.service >/dev/null 2>&1 || true
systemctl disable mp-daemon.service >/dev/null 2>&1 || true
systemctl daemon-reload >/dev/null 2>&1 || true
PRERM

dpkg-deb -b --root-owner-group "$tmp/root" "$out_deb"
echo "---- service deb: $out_deb ----"
dpkg-deb -c "$out_deb" | grep -E 'mp-daemon|systemd|DEBIAN' || true
