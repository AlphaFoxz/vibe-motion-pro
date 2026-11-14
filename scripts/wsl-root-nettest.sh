#!/usr/bin/env bash
# root 级 Linux 网络接管真机测试封装（WSL/Ubuntu）：
#   echo <sudo密码> | bash scripts/wsl-root-nettest.sh
# 步骤：普通用户构建（cargo 缓存属主不变）→ sudo 运行 example 二进制。
set -euo pipefail
cd "$(dirname "$0")/.."
source "$(dirname "$0")/linux-musl-env.sh"

cargo build --target x86_64-unknown-linux-musl -p mp-platform --example root_nettest
BIN="$CARGO_TARGET_DIR/x86_64-unknown-linux-musl/debug/examples/root_nettest"

read -r pass
printf '%s\n' "$pass" | sudo -S --prompt='' "$BIN"
