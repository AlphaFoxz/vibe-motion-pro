fn main() {
    prepare_sidecar();
    tauri_build::build()
}

/// 填充 bundle.resources 引用的 sidecar 源目录（app/src-tauri/sidecar/）。
/// tauri build script 会在构建期校验 resources 路径存在——没有这一步，
/// fresh checkout 上 `cargo check -p mp-app` / `tauri dev` 直接失败。
///
/// - wintun.dll：从仓库内真实文件拷贝（crates/mp-daemon/wintun/）；
/// - mp-daemon.exe：仅当缺失时写入**占位文件**——真实产物由
///   `scripts/prepare-sidecar.ps1`（本地）或 release.yml 的 prepare 步骤注入，
///   已存在的真身不覆盖。忘跑 prepare 直接 tauri build 会把占位打进安装包，
///   后果是 UI 拉起 daemon 时报"启动失败"（可见、可诊断），不会静默出错。
fn prepare_sidecar() {
    let manifest = std::env::var("CARGO_MANIFEST_DIR").unwrap_or_default();
    let sidecar = std::path::Path::new(&manifest).join("sidecar");
    if std::fs::create_dir_all(&sidecar).is_err() {
        return;
    }

    let wintun_src = std::path::Path::new(&manifest)
        .join("..")
        .join("..")
        .join("crates")
        .join("mp-daemon")
        .join("wintun")
        .join("wintun.dll");
    let wintun_dst = sidecar.join("wintun.dll");
    if !wintun_dst.exists() {
        if let Err(e) = std::fs::copy(&wintun_src, &wintun_dst) {
            println!("cargo:warning=sidecar wintun.dll copy failed: {e}");
        }
    }

    let daemon_dst = sidecar.join("mp-daemon.exe");
    if !daemon_dst.exists() {
        let _ = std::fs::write(
            &daemon_dst,
            b"placeholder - run scripts/prepare-sidecar.ps1 before release build\n",
        );
    }
}
