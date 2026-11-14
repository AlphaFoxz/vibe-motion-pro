#!/usr/bin/env bash
# WSL/Ubuntu 构建真实 deb 包（前置：wsl-apt-deps.sh 已装 webkit 等依赖）。
# pnpm install → tauri build --bundles deb → dpkg-deb -c 校验产物内容。
set -euo pipefail
cd "$(dirname "$0")/../app"
# gnu 构建产物放本地盘（/mnt 的 DrvFS IO 极慢）；cargo 在 ~/.cargo/bin
export CARGO_TARGET_DIR="${CARGO_TARGET_DIR:-$HOME/target-deb}"
export PATH="$HOME/.cargo/bin:$PATH"

pnpm install --registry=https://registry.npmjs.org
pnpm tauri build --bundles deb

echo "---- bundle ----"
ls -la "$CARGO_TARGET_DIR/release/bundle/deb/"
echo "---- contents ----"
dpkg-deb -c "$CARGO_TARGET_DIR"/release/bundle/deb/*.deb | head -30
