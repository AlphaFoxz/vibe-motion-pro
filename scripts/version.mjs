// 升版本：只负责改分散在各处的版本号，git 提交/打 tag/推送由人工完成。
//   1) Cargo.toml [workspace.package]（各 crate 均走 version.workspace 继承）
//   2) app/src-tauri/tauri.conf.json（Release CI prepare 强校验项）
//   3) app/package.json
//   4) `cargo update -w` 同步 Cargo.lock 中 5 个 mp-* 成员版本（不动外部依赖）
// 用法：node scripts/version.mjs <版本号> [--dry-run]
//   <版本号>   如 0.1.1（v/V 前缀可带可不带）
//   --dry-run  只预览将修改的内容，不实际写入
// 发布步骤（脚本不管，人工执行）：commit 本次改动 → 合并/推送到 master →
//   git tag v0.1.1 && git push origin v0.1.1（触发 Release CI，自动生成改动日志）
// 示例：
//   node scripts/version.mjs 0.1.1 --dry-run    # 预览
//   node scripts/version.mjs 0.1.1              # 改文件
// 跨平台：Windows / Linux / macOS 均可运行，不依赖 bash/sed/jq（version.sh 的替代版）。
import { execFileSync } from "node:child_process";
import { existsSync, readFileSync, writeFileSync } from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), "..");
process.chdir(root);

const usage = () => {
  console.error(
    `用法：node scripts/version.mjs <版本号> [--dry-run]
  <版本号>   如 0.1.1（v/V 前缀可带可不带）
  --dry-run  只预览将修改的内容，不实际写入`,
  );
  process.exit(1);
};

// ---- 参数解析 ----
let dryRun = false;
let ver = "";
for (const arg of process.argv.slice(2)) {
  if (arg === "--dry-run") dryRun = true;
  else if (arg === "-h" || arg === "--help") usage();
  else if (arg.startsWith("-")) usage();
  else {
    if (ver) usage();
    ver = arg;
  }
}
if (!ver) usage();
ver = ver.replace(/^[vV]/, ""); // v0.1.1 / V0.1.1 与 0.1.1 等价
if (!/^\d+\.\d+\.\d+$/.test(ver)) {
  console.error(`✗ 版本号须为 X.Y.Z 数字格式，收到: ${ver}`);
  process.exit(1);
}

const CARGO_TOML = "Cargo.toml";
const CARGO_LOCK = "Cargo.lock";
const TAURI_CONF = "app/src-tauri/tauri.conf.json";
const PKG_JSON = "app/package.json";

// ---- 前置校验：要改的文件/依赖的工具必须存在；缺失说明仓库结构或环境已重构 ----
const missing = [];
for (const f of [CARGO_TOML, CARGO_LOCK, TAURI_CONF, PKG_JSON]) {
  if (!existsSync(f)) missing.push(`文件 ${f}`);
}
for (const c of ["cargo", "git"]) {
  try {
    execFileSync(c, ["--version"], { stdio: "ignore" });
  } catch {
    missing.push(`命令 ${c}`);
  }
}
if (missing.length > 0) {
  console.error("✗ 以下文件/工具不存在，仓库结构可能已重构，脚本已过期：");
  for (const m of missing) console.error(`    ${m}`);
  process.exit(1);
}

// ---- 读版本工具 ----
// 只截取 [workspace.package] 段（各 crate 走 version.workspace 继承，真正源头在这）
// 手动定位段边界，兼容 LF / CRLF 行尾
function cargoWorkspaceVersion(text) {
  const head = text.match(/^[ \t]*\[workspace\.package\][ \t]*\r?\n/m);
  if (!head) return "";
  const start = head.index + head[0].length;
  const rest = text.slice(start);
  const next = rest.search(/^\[/m); // 下一个段头，-1 表示到文件结尾
  const body = next === -1 ? rest : rest.slice(0, next);
  return body.match(/^version[ \t]*=[ \t]*"([^"\r\n]*)"/m)?.[1] ?? "";
}

// 只替换第一个 "version": "..."，不重排其余内容（比 jq 重排整个文件更安全）
function replaceJsonVersion(text, oldV, newV) {
  const re = new RegExp(`("version"\\s*:\\s*")${oldV}(")`);
  if (!re.test(text)) throw new Error(`未找到 "version": "${oldV}"`);
  return text.replace(re, `$1${newV}$2`);
}

function readJsonVersion(file) {
  return JSON.parse(readFileSync(file, "utf8")).version ?? "";
}

// ---- 升版前预检：三处版本应一致（与 Release CI 的校验口径相同），避免带病升版 ----
const oldCargo = cargoWorkspaceVersion(readFileSync(CARGO_TOML, "utf8"));
const oldConf = readJsonVersion(TAURI_CONF);
const oldPkg = readJsonVersion(PKG_JSON);
if (!oldCargo || oldCargo !== oldConf || oldCargo !== oldPkg) {
  console.error("✗ 版本号不一致，先手工对齐再升版：");
  console.error(`    Cargo.toml=${oldCargo} tauri.conf.json=${oldConf} package.json=${oldPkg}`);
  process.exit(1);
}
if (oldCargo === ver) {
  console.error(`✗ 版本已是 ${ver}，无需升级（记得换新版本号）`);
  process.exit(1);
}

console.log(`==> ${oldCargo} → ${ver}（--dry-run=${dryRun}）`);
if (dryRun) {
  console.log(`    Cargo.toml                    version = "${oldCargo}" → "${ver}"`);
  console.log(`    app/src-tauri/tauri.conf.json "version": "${oldCargo}" → "${ver}"`);
  console.log(`    app/package.json              "version": "${oldCargo}" → "${ver}"`);
  console.log(`    Cargo.lock                    cargo update -w（mp-* 五个成员同步到 ${ver}）`);
  console.log("==> [dry-run] 结束，未做任何改动");
  process.exit(0);
}

const run = (cmd, args) =>
  execFileSync(cmd, args, { stdio: ["ignore", "pipe", "pipe"], encoding: "utf8" });

try {
  // 1) 三处版本文件
  const cargoText = readFileSync(CARGO_TOML, "utf8");
  const replaced = cargoText.replace(
    /^(\[workspace\.package\][\s\S]*?^version[ \t]*=[ \t]*")[^\r\n]*(")/m,
    `$1${ver}$2`,
  );
  if (replaced === cargoText) throw new Error("Cargo.toml 替换失败");
  writeFileSync(CARGO_TOML, replaced);
  for (const f of [TAURI_CONF, PKG_JSON]) {
    const text = readFileSync(f, "utf8");
    writeFileSync(f, replaceJsonVersion(text, oldCargo, ver));
  }

  // 2) 同步 Cargo.lock（只更新 workspace 成员版本，外部依赖不动）
  run("cargo", ["update", "-w"]);

  // 3) 复核（防写文件/cargo 静默失败），失败则整体回滚
  const newCargo = cargoWorkspaceVersion(readFileSync(CARGO_TOML, "utf8"));
  const newConf = readJsonVersion(TAURI_CONF);
  const newPkg = readJsonVersion(PKG_JSON);
  const lockVers = [
    ...new Set(
      readFileSync(CARGO_LOCK, "utf8")
        .match(/^name = "mp-[\s\S]*?^version = "[\d.]+"/gm)
        ?.map((s) => s.match(/^version = "([\d.]+)"/m)?.[1]) ?? [],
    ),
  ].sort();
  if (
    newCargo !== ver || newConf !== ver || newPkg !== ver ||
    lockVers.length !== 1 || lockVers[0] !== ver
  ) {
    throw new Error(
      `Cargo.toml=${newCargo} conf=${newConf} pkg=${newPkg} lock=${lockVers.join(",")}`,
    );
  }
} catch (err) {
  console.error(`✗ 升版复核失败，已回滚，请检查：`);
  console.error(`    ${err.message}`);
  run("git", ["checkout", "--", CARGO_TOML, TAURI_CONF, PKG_JSON, CARGO_LOCK]);
  process.exit(1);
}

console.log("==> 已更新版本号（git 提交/打 tag 请自行完成）：");
console.log(run("git", ["diff", "--stat"]));
