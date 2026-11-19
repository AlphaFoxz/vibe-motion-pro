#!/usr/bin/env bash
# 升版本：只负责改分散在各处的版本号，git 提交/打 tag/推送由人工完成。
#   1) Cargo.toml [workspace.package]（各 crate 均走 version.workspace 继承）
#   2) app/src-tauri/tauri.conf.json（Release CI prepare 强校验项）
#   3) app/package.json
#   4) `cargo update -w` 同步 Cargo.lock 中 5 个 mp-* 成员版本（不动外部依赖）
# 用法：version.sh <版本号> [--dry-run]
#   <版本号>   如 0.1.1（v/V 前缀可带可不带）
#   --dry-run  只预览将修改的内容，不实际写入
# 发布步骤（脚本不管，人工执行）：commit 本次改动 → 合并/推送到 master →
#   git tag v0.1.1 && git push origin v0.1.1（触发 Release CI，自动生成改动日志）
# 示例：
#   version.sh 0.1.1 --dry-run    # 预览
#   version.sh 0.1.1              # 改文件
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$root"

usage() { sed -n '2,17p' "$0" >&2; exit 1; }

dry_run=false
ver=""
for arg in "$@"; do
  case "$arg" in
    --dry-run) dry_run=true ;;
    -h|--help) usage ;;
    -*) usage ;;
    *) [ -z "$ver" ] || usage; ver="$arg" ;;
  esac
done
[ -n "$ver" ] || usage
ver="${ver#[vV]}"   # v0.1.1 / V0.1.1 与 0.1.1 等价
[[ "$ver" =~ ^[0-9]+\.[0-9]+\.[0-9]+$ ]] || { echo "✗ 版本号须为 X.Y.Z 数字格式，收到: $ver" >&2; exit 1; }

# 前置校验：本脚本要改的文件/依赖的工具必须存在；
# 缺失说明仓库结构或环境已重构，脚本过期了，先更新脚本而不是带病升版
missing=()
for f in Cargo.toml Cargo.lock app/src-tauri/tauri.conf.json app/package.json; do
  [ -f "$f" ] || missing+=("文件 $f")
done
for c in jq cargo; do
  command -v "$c" >/dev/null 2>&1 || missing+=("命令 $c")
done
if [ "${#missing[@]}" -gt 0 ]; then
  echo "✗ 以下文件/工具不存在，仓库结构可能已重构，脚本已过期：" >&2
  printf '    %s\n' "${missing[@]}" >&2
  exit 1
fi

# 升版前预检：三处版本应一致（与 Release CI 的校验口径相同），避免带病升版
old_cargo=$(sed -n '/^\[workspace\.package\]/,/^\[/ s/^version = "\(.*\)"/\1/p' Cargo.toml)
old_conf=$(jq -r '.version' app/src-tauri/tauri.conf.json)
old_pkg=$(jq -r '.version' app/package.json)
if [ -z "$old_cargo" ] || [ "$old_cargo" != "$old_conf" ] || [ "$old_cargo" != "$old_pkg" ]; then
  echo "✗ 版本号不一致，先手工对齐再升版：" >&2
  echo "    Cargo.toml=$old_cargo tauri.conf.json=$old_conf package.json=$old_pkg" >&2
  exit 1
fi
if [ "$old_cargo" = "$ver" ]; then
  echo "✗ 版本已是 $ver，无需升级（记得换新版本号）" >&2
  exit 1
fi

echo "==> $old_cargo → $ver（--dry-run=$dry_run）"
if $dry_run; then
  echo "    Cargo.toml                    version = \"$old_cargo\" → \"$ver\""
  echo "    app/src-tauri/tauri.conf.json \"version\": \"$old_cargo\" → \"$ver\""
  echo "    app/package.json              \"version\": \"$old_cargo\" → \"$ver\""
  echo "    Cargo.lock                    cargo update -w（mp-* 五个成员同步到 $ver）"
  echo "==> [dry-run] 结束，未做任何改动"
  exit 0
fi

# 1) 三处版本文件（临时文件放同目录）
sed -i '/^\[workspace\.package\]/,/^\[/ s/^version = ".*"/version = "'"$ver"'"/' Cargo.toml
jq --arg v "$ver" '.version = $v' app/src-tauri/tauri.conf.json > app/src-tauri/tauri.conf.json.tmp && mv app/src-tauri/tauri.conf.json.tmp app/src-tauri/tauri.conf.json
jq --arg v "$ver" '.version = $v' app/package.json                 > app/package.json.tmp                 && mv app/package.json.tmp                 app/package.json

# 2) 同步 Cargo.lock（只更新 workspace 成员版本，外部依赖不动）
cargo update -w >/dev/null 2>&1

# 3) 复核（防 sed/jq 静默失败），失败则整体回滚
new_cargo=$(sed -n '/^\[workspace\.package\]/,/^\[/ s/^version = "\(.*\)"/\1/p' Cargo.toml)
new_conf=$(jq -r '.version' app/src-tauri/tauri.conf.json)
new_pkg=$(jq -r '.version' app/package.json)
lock_vers=$(grep -A1 '^name = "mp-' Cargo.lock | grep -oE '[0-9]+\.[0-9]+\.[0-9]+' | sort -u)
if [ "$new_cargo" != "$ver" ] || [ "$new_conf" != "$ver" ] || [ "$new_pkg" != "$ver" ] \
   || [ "$lock_vers" != "$ver" ]; then
  echo "✗ 升版复核失败，已回滚，请检查：" >&2
  echo "    Cargo.toml=$new_cargo conf=$new_conf pkg=$new_pkg lock=$lock_vers" >&2
  git checkout -- Cargo.toml app/src-tauri/tauri.conf.json app/package.json Cargo.lock
  exit 1
fi

echo "==> 已更新版本号（git 提交/打 tag 请自行完成）："
git diff --stat
