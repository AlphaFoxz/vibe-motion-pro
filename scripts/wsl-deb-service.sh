#!/usr/bin/env bash
# WSL/Ubuntu：构建「systemd 服务化 daemon」的完整 deb 并真机验证。
# 前置：wsl-apt-deps.sh 已装依赖、musl 工具链就绪（linux-musl-env.sh 头注）。
# 流程：musl 静态 daemon → tauri deb（gnu）→ deb-inject-service.sh 注入
#       → dpkg -i → systemd active → IPC 往返 → 重启持久 → 干净卸载。
set -euo pipefail
cd "$(dirname "$0")/.."

# ---- 1. musl 静态 daemon ----
source scripts/linux-musl-env.sh
cargo build -p mp-daemon --release --target x86_64-unknown-linux-musl
MUSL_DAEMON="$CARGO_TARGET_DIR/x86_64-unknown-linux-musl/release/mp-daemon"
[ -x "$MUSL_DAEMON" ] || { echo "musl daemon 构建失败" >&2; exit 1; }

# ---- 2. tauri deb（gnu）----
export CARGO_TARGET_DIR="${CARGO_TARGET_DEB:-$HOME/target-deb}"
cd app
pnpm install --registry=https://registry.npmjs.org
pnpm tauri build --bundles deb
cd ..
DEB_SRC="$(ls "$CARGO_TARGET_DIR"/release/bundle/deb/*.deb | head -1)"

# ---- 3. 注入 systemd 服务 ----
OUT_DEB="$PWD/target_web/VibeMotionPro-service.deb"
mkdir -p "$(dirname "$OUT_DEB")"
bash scripts/deb-inject-service.sh "$DEB_SRC" "$MUSL_DAEMON" "$OUT_DEB"

echo "==== 产物: $OUT_DEB ===="
