#!/usr/bin/env bash
# WSL/Ubuntu 真实安装 deb 并验证（stdin 传 sudo 密码）：
# dpkg -i → 包清单 → ldd 缺库检查 → WSLg 下 5s 冒烟启动 → dpkg -r 还原
set -euo pipefail
DEB="$HOME/target-deb/release/bundle/deb/MotionPro_0.1.0_amd64.deb"
PKG=$(dpkg-deb -f "$DEB" Package)
echo "package: $PKG"
read -r pass
printf '%s\n' "$pass" | sudo -S --prompt='' dpkg -i "$DEB" 2>&1 | tail -3
dpkg -L "$PKG" | head -12
echo "---- ldd ----"
if ldd /usr/bin/mp-app | grep -q "not found"; then
  ldd /usr/bin/mp-app | grep "not found"
  echo "MISSING LIBS"
  exit 1
fi
echo "deps OK"
echo "---- gui smoke (5s) ----"
if [ -n "${DISPLAY:-}${WAYLAND_DISPLAY:-}" ]; then
  set +e
  timeout 5 /usr/bin/mp-app >/tmp/mp-app-smoke.log 2>&1
  rc=$?
  set -e
  echo "exit=$rc (124=alive-until-timeout)"
  tail -3 /tmp/mp-app-smoke.log || true
else
  echo "no display, skip gui smoke"
fi
printf '%s\n' "$pass" | sudo -S --prompt='' dpkg -r "$PKG"
echo "DEB INSTALL TEST DONE"
