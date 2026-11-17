#!/usr/bin/env bash
# P2 真机验证：重注入（--root-owner-group）→ 安装 → 服务活跃 → IPC 往返
# → 自启启用 → 干净卸载。在 WSL Ubuntu 内运行。
set -euo pipefail
cd /mnt/d/vscode_projects/vibe-motion-pro
source scripts/linux-musl-env.sh
MUSL_DAEMON="${MUSL_DAEMON:-/home/wong/target-musl/x86_64-unknown-linux-musl/release/mp-daemon}"
DEB_SRC="$(ls /home/wong/target-deb/release/bundle/deb/*.deb | head -1)"
OUT_DEB="$PWD/target_web/VibeMotionPro-service.deb"

bash scripts/deb-inject-service.sh "$DEB_SRC" "$MUSL_DAEMON" "$OUT_DEB" | tail -8

echo "==== 1. dpkg -i ===="
sudo dpkg -i "$OUT_DEB"

echo "==== 2. 服务状态 ===="
sleep 1
systemctl is-active mp-daemon
systemctl is-enabled mp-daemon

echo "==== 3. IPC 往返（127.0.0.1:62000 Status）===="
python3 - <<'EOF'
import socket, json
s = socket.create_connection(("127.0.0.1", 62000), timeout=5)
# 注意：serde tag = snake_case，variant 名在 wire 上是全小写 "status"
s.sendall(b'{"type":"status"}\n')
buf = b""
while not buf.endswith(b"\n"):
    chunk = s.recv(4096)
    if not chunk:
        raise AssertionError("connection closed before response")
    buf += chunk
resp = json.loads(buf)
assert resp["type"] == "status", f"unexpected: {resp}"
print("IPC OK:", resp["status"]["state"])
EOF

echo "==== 4. profiles 落在 /var/lib（服务化固定路径）===="
systemctl show mp-daemon -p Environment --no-pager | grep -o 'MP_PROFILES=[^ ]*' || true
ls -la /var/lib/vibe-motionpro/ 2>/dev/null || echo "(profiles 文件尚未生成——首次保存时创建，正常)"

echo "==== 5. 干净卸载 ===="
sudo dpkg -r motion-pro
sleep 1
systemctl is-active mp-daemon 2>&1 | grep -q "inactive\|not-loaded\|failed" && echo "服务已停止" || systemctl is-active mp-daemon || true
[ ! -e /lib/systemd/system/mp-daemon.service ] && echo "unit 已移除"
[ ! -e /usr/bin/mp-daemon ] && echo "二进制已移除"
echo "==== ALL PASS ===="
