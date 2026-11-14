#!/usr/bin/env bash
# WSL/Ubuntu 上 mp-daemon 运行时冒烟：启动 → IPC Status 往返 → 日志校验。
# 验证 musl 静态二进制在 Ubuntu 上可跑、IPC 起得来、XDG 路径不炸。
# 用法：bash scripts/wsl-daemon-smoke.sh（先跑过 scripts/linux-musl-test.sh 产出二进制）
set -euo pipefail
source "$(dirname "$0")/linux-musl-env.sh"
BIN="${CARGO_TARGET_DIR}/x86_64-unknown-linux-musl/debug/mp-daemon"
if [ ! -x "$BIN" ]; then
  cargo build --target x86_64-unknown-linux-musl -p mp-daemon
fi
PORT=62999
export MP_IPC_ADDR=127.0.0.1:$PORT
export MP_PROFILES=/tmp/mp-smoke-profiles.toml
export RUST_LOG=info

"$BIN" > /tmp/mp-smoke-daemon.log 2>&1 &
PID=$!
trap 'kill $PID 2>/dev/null || true' EXIT

# 等 IPC 端口就绪（最多 10s）
ready=0
for _ in $(seq 1 50); do
  if python3 -c "import socket;socket.create_connection(('127.0.0.1',$PORT),timeout=0.2).close()" 2>/dev/null; then ready=1; break; fi
  sleep 0.2
done
[ "$ready" = 1 ] || { echo "IPC 端口未就绪"; cat /tmp/mp-smoke-daemon.log; exit 1; }

python3 - "$PORT" <<'EOF'
import json, socket, sys
port = int(sys.argv[1])
s = socket.create_connection(("127.0.0.1", port), timeout=5)
s.sendall(b'{"type":"status"}\n')
buf = b""
while not buf.endswith(b"\n"):
    chunk = s.recv(4096)
    if not chunk:
        raise SystemExit("connection closed before response")
    buf += chunk
msg = json.loads(buf)
assert msg["type"] in ("status", "status_update"), f"unexpected response: {msg}"
print("IPC OK:", json.dumps(msg, ensure_ascii=False)[:120])
EOF

grep -q "listening" /tmp/mp-smoke-daemon.log && echo "daemon log OK"
kill $PID
wait $PID 2>/dev/null || true
echo "SMOKE PASS"
