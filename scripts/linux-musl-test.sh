#!/usr/bin/env bash
# 在无 root / 无系统 libc 开发文件的 Linux 环境（如最小化 WSL 镜像）上
# 跑 musl 静态目标的 workspace 测试。环境前置见 linux-musl-env.sh 头注释。
# 用法：bash scripts/linux-musl-test.sh [额外 cargo test 参数]
set -euo pipefail
source "$(dirname "$0")/linux-musl-env.sh"
cd "$(dirname "$0")/.."
exec cargo test --target x86_64-unknown-linux-musl "$@"
