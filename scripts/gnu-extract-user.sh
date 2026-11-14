#!/usr/bin/env bash
# 无 root 情况下把 Ubuntu 官方 gcc + libc6-dev 解包到 ~/gnu（最小化 WSL/
# 容器环境给宿主目标 linux-gnu 提供 cc/链接器/crt）。
# 自带用户级 apt 状态目录刷新索引（/var 不可写、系统列表可能过期 404）。
# 前置：/var/lib/dpkg/status 存在、网络可达 archive.ubuntu.com。
# 用法：bash scripts/gnu-extract-user.sh   （可 GNU_HOME=... 覆盖目标目录）
set -euo pipefail
DEST="${GNU_HOME:-$HOME/gnu}"
APT="$HOME/apt-user"
# deb 缓存目录（重复运行不再重新下载）
CACHE="$HOME/gnu-debs-cache"
mkdir -p "$CACHE" "$APT/lists/partial" "$APT/cache/archives/partial"

# 用户级索引刷新（复用系统 dpkg 状态以解出依赖闭包）
apt-get -o Dir::State::lists="$APT/lists" -o Dir::Cache="$APT/cache" \
  -o Dir::State::status=/var/lib/dpkg/status update -qq || echo "warn: apt update 部分源失败"

TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT
cd "$CACHE"
# 递归闭包里含虚包（不可下载），逐个容错
pkgs=$(apt-cache -o Dir::State::lists="$APT/lists" -o Dir::State::status=/var/lib/dpkg/status \
  depends --recurse --no-recommends --no-suggests \
  --no-conflicts --no-breaks --no-replaces --no-enhances \
  gcc libc6-dev binutils | grep -E '^[a-z0-9]' | sort -u || true)
for p in $pkgs; do
  # 缓存命中则跳过下载
  ls "${p}"_*.deb >/dev/null 2>&1 && continue
  apt-get -o Dir::State::lists="$APT/lists" -o Dir::Cache="$APT/cache" \
    -o Dir::State::status=/var/lib/dpkg/status \
    download "$p" >/dev/null 2>&1 || echo "skip: $p"
done
shopt -s nullglob
mkdir -p "$DEST"
for f in "$CACHE"/*.deb; do dpkg -x "$f" "$DEST"; done
# glibc 的 libc.so 等是「链接器脚本」，内部 GROUP() 引用系统绝对路径
# （/usr/lib/x86_64-linux-gnu/libc_nonshared.a 等）—— 系统目录无 dev 文件时
# 404。改写到解包目录（/lib/... 是运行时库、系统存在，保持不动）
SO_DIR="$DEST/usr/lib/x86_64-linux-gnu"
if [ -d "$SO_DIR" ]; then
  find "$SO_DIR" -maxdepth 1 -name '*.so' -type f | while read -r s; do
    if grep -q 'GROUP (' "$s" 2>/dev/null; then
      sed -i "s|/usr/lib/x86_64-linux-gnu/|$SO_DIR/|g" "$s"
    fi
  done
fi
"$DEST/usr/bin/gcc" --version | head -1
ls "$DEST/usr/lib/x86_64-linux-gnu/crt1.o" >/dev/null && echo "crt1.o OK"
echo "extracted to $DEST (export GNU_HOME=$DEST for linux-musl-test.sh)"
