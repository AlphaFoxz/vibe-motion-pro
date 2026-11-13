// 构建时把 wintun.dll 复制到编译输出目录（exe 同目录），
// 避免 target 清理后 dll 丢失导致运行时 LoadLibraryExW 失败（真机踩坑）。
// 来源：wintun 0.14.1 amd64（SHA256 E5DA8447DC2C320EDC0FC52FA01885C103DE8C118481F683643CACC3220DAFCE）
use std::path::PathBuf;

fn main() {
    if std::env::consts::OS != "windows" {
        return;
    }
    let manifest = PathBuf::from(std::env::var("CARGO_MANIFEST_DIR").unwrap());
    let src = manifest.join("wintun").join("wintun.dll");
    if !src.exists() {
        println!("cargo:warning=wintun.dll not found at {}", src.display());
        return;
    }
    // OUT_DIR = <target>/<profile>/build/<pkg>-<hash>/out
    let out_dir = PathBuf::from(std::env::var("OUT_DIR").unwrap());
    if let Some(profile_dir) = out_dir.ancestors().nth(3) {
        let dst = profile_dir.join("wintun.dll");
        if std::fs::copy(&src, &dst).is_ok() {
            println!("cargo:rerun-if-changed={}", src.display());
        }
    }
}
