#!/usr/bin/env bash
# musl 测试/构建共享环境（被 linux-musl-test.sh 与 wsl-daemon-smoke.sh source）。
# 前置：rustup + `rustup target add x86_64-unknown-linux-musl`
#       + musl.cc 工具链解压到 $MUSL_CROSS（默认 ~/x86_64-linux-musl-cross）
#       （curl -L https://more.musl.cc/x86_64-linux-musl/x86_64-linux-musl-cross.tgz）
#       最小化环境还需 scripts/gnu-extract-user.sh 解包宿主 gnu 工具链到 ~/gnu
MUSL_CROSS="${MUSL_CROSS:-$HOME/x86_64-linux-musl-cross}"
TC="$MUSL_CROSS/bin/x86_64-linux-musl-gcc"
export CC_x86_64_unknown_linux_musl="$TC"
export AR_x86_64_unknown_linux_musl="$MUSL_CROSS/bin/x86_64-linux-musl-ar"
export CARGO_TARGET_X86_64_UNKNOWN_LINUX_MUSL_LINKER="$TC"

# 最小化环境（无系统 gcc/libc-dev）：宿主（linux-gnu）的 build script/
# proc-macro 需要真 gnu 工具链 —— gnu-extract-user.sh 解包到 ~/gnu；
# 系统已有 cc（如装过 build-essential）则优先系统工具链
GNU_HOME="${GNU_HOME:-$HOME/gnu}"
if ! command -v cc >/dev/null 2>&1 && [ -x "$GNU_HOME/usr/bin/gcc" ]; then
  # 解包的 gcc 优先用它自带的 binutils（系统 ld 对系统路径有默认假设）
  export PATH="$GNU_HOME/usr/bin:$PATH"
  export CC_x86_64_unknown_linux_gnu="$GNU_HOME/usr/bin/gcc"
  export AR_x86_64_unknown_linux_gnu="$GNU_HOME/usr/bin/ar"
  export CARGO_TARGET_X86_64_UNKNOWN_LINUX_GNU_LINKER="$GNU_HOME/usr/bin/gcc"
fi

# 避免 /mnt/*（DrvFS）上极慢的 IO；可被外部覆盖
export CARGO_TARGET_DIR="${CARGO_TARGET_DIR:-$HOME/target-musl}"
export PATH="$HOME/.cargo/bin:$PATH"
