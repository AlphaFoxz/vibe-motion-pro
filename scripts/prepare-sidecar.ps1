# 填充 tauri bundle 的 sidecar 资源源目录（app/src-tauri/sidecar/）：
#   mp-daemon.exe —— 特权守护进程（提权拉起，随 UI 存亡，见 docs/plan-release.md P1）
#   wintun.dll   —— tun crate 运行时依赖（与 daemon exe 同目录，DLL 搜索序首位命中）
# tauri.conf.json 的 bundle.resources 引用这些文件；缺失时 tauri build 会失败。
# 本地发布：pwsh scripts/prepare-sidecar.ps1 && cd app && pnpm tauri build --bundles nsis
# CI（release.yml）执行等价步骤。
param(
    # 跳过 daemon 构建（已有产物时加速重打包）
    [switch]$SkipBuild
)
$ErrorActionPreference = "Stop"
$repo = Split-Path $PSScriptRoot -Parent
$sidecar = Join-Path $repo "app\src-tauri\sidecar"

if (-not $SkipBuild) {
    Push-Location $repo
    try {
        cargo build -p mp-daemon --release
        if ($LASTEXITCODE -ne 0) { throw "cargo build -p mp-daemon failed" }
    } finally { Pop-Location }
}

New-Item -ItemType Directory -Force $sidecar | Out-Null
Copy-Item (Join-Path $repo "target\release\mp-daemon.exe") (Join-Path $sidecar "mp-daemon.exe") -Force
Copy-Item (Join-Path $repo "crates\mp-daemon\wintun\wintun.dll") (Join-Path $sidecar "wintun.dll") -Force
Write-Host "sidecar prepared:"
Get-ChildItem $sidecar | Select-Object Name, Length | Format-Table | Out-String | Write-Host
