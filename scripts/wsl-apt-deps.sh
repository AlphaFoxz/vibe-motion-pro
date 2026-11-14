#!/usr/bin/env bash
# WSL/Ubuntu 装 Tauri Linux 构建依赖（需 sudo）：
#   echo <sudo密码> | bash scripts/wsl-apt-deps.sh
set -euo pipefail
read -r pass
# 系统列表可能过期（pool 点版本更替 → 404），先刷新
printf '%s\n' "$pass" | sudo -S --prompt='' apt-get update -qq || echo "warn: apt update partial"
printf '%s\n' "$pass" | sudo -S --prompt='' apt-get install -y \
  libwebkit2gtk-4.1-dev build-essential curl wget file \
  libxdo-dev libssl-dev libayatana-appindicator3-dev librsvg2-dev \
  pkg-config nodejs npm
# pnpm 全局可用（app/ 的构建脚本用 pnpm）
sudo npm install -g pnpm --silent >/dev/null
node --version && pnpm --version
