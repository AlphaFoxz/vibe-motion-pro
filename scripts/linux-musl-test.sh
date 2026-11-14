#!/usr/bin/env bash
# 在无 root / 无系统 libc 开发文件的 Linux 环境（如最小化 WSL 镜像）上
# 跑 musl 静态目标的 workspace 测试：
#   前置：rustup + `rustup target add x86_64-unknown-linux-musl`
#         + musl.cc 工具链解压到 $MUSL_CROSS（默认 ~/x86_64-linux-musl-cross）
#         （curl -L https://more.musl.cc/x86_64-linux-musl/x86_64-linux-musl-cross.tgz）
# 用法：bash scripts/linux-musl-test.sh [额外 cargo test 参数]
set -euo pipefail
MUSL_CROSS="${MUSL_CROSS:-$HOME/x86_64-linux-musl-cross}"
TC="$MUSL_CROSS/bin/x86_64-linux-musl-gcc"
export CC_x86_64_unknown_linux_musl="$TC"
export AR_x86_64_unknown_linux_musl="$MUSL_CROSS/bin/x86_64-linux-musl-ar"
export CARGO_TARGET_X86_64_UNKNOWN_LINUX_MUSL_LINKER="$TC"
# 最小化环境（无系统 gcc/libc-dev）：宿主（linux-gnu）的 build script/
# proc-macro 需要真 gnu 工具链 —— 用 scripts/gnu-extract-user.sh 解包到 ~/gnu；
# 有系统 gcc 的机器不受影响（仅在可执行时覆盖）
GNU_HOME="${GNU_HOME:-$HOME/gnu}"
if [ -x "$GNU_HOME/usr/bin/gcc" ]; then
  # 解包的 gcc 优先用它自带的 binutils（系统 ld 对系统路径有默认假设）
  export PATH="$GNU_HOME/usr/bin:$PATH"
  export CC_x86_64_unknown_linux_gnu="$GNU_HOME/usr/bin/gcc"
  export AR_x86_64_unknown_linux_gnu="$GNU_HOME/usr/bin/ar"
  export CARGO_TARGET_X86_64_UNKNOWN_LINUX_GNU_LINKER="$GNU_HOME/usr/bin/gcc"
fi
# 避免 /mnt/*（DrvFS）上极慢的 IO；可被外部覆盖
export CARGO_TARGET_DIR="${CARGO_TARGET_DIR:-$HOME/target-musl}"
export PATH="$HOME/.cargo/bin:$PATH"
cd "$(dirname "$0")/.."
exec cargo test --target x86_64-unknown-linux-musl "$@"
