// 生成 updater 更新清单 latest.json（plan-auto-update.md P3）。
// 输入：Windows 构建的安装包 + .sig（--dir 指向含产物的目录）、
// 可选 --notes <release-notes.md>；版本号读 app/src-tauri/tauri.conf.json。
// 输出：latest.json（--out，默认写入 --dir）。
//
// 只写 windows-x86_64 条目：Linux 走「检查+引导下载」（不放安装产物），
// 且 updater 会**全量校验**清单里所有平台条目——没有产物的平台不能写。
//
// URL 规则（GitHub Releases 资产直链）：
//   https://github.com/AlphaFoxz/vibe-motion-pro/releases/download/v<ver>/<file>
// 注意：`.sig` 内容必须是 minisign 签名全文（tauri bundler 直出），
// latest.json 的 signature 字段 = .sig 文件内容，URL/路径都不行。
//
// 用法（release.yml 里，在下载完 build artifacts 后）：
//   node scripts/gen-latest-json.mjs --dir dist --notes release-notes.md
import { existsSync, readFileSync, readdirSync, writeFileSync } from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";

const REPO = "AlphaFoxz/vibe-motion-pro";
const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), "..");

// ---- 参数 ----
const args = process.argv.slice(2);
const opt = {};
for (let i = 0; i < args.length; i++) {
  const a = args[i];
  if (a === "--dir") opt.dir = args[++i];
  else if (a === "--notes") opt.notes = args[++i];
  else if (a === "--out") opt.out = args[++i];
  else if (a === "-h" || a === "--help") opt.help = true;
  else {
    console.error(`未知参数: ${a}`);
    process.exit(1);
  }
}
if (opt.help || !opt.dir) {
  console.error("用法: node scripts/gen-latest-json.mjs --dir <产物目录> [--notes release-notes.md] [--out latest.json]");
  process.exit(1);
}

const die = (msg) => {
  console.error(`✗ ${msg}`);
  process.exit(1);
};

// ---- 版本（与 Release CI prepare 校验同源：tauri.conf.json）----
const conf = JSON.parse(readFileSync(path.join(root, "app/src-tauri/tauri.conf.json"), "utf8"));
const version = conf.version ?? die("tauri.conf.json 缺 version");

// ---- 找签名产物：目录里唯一的 .sig（其去后缀即安装包）----
const dir = path.resolve(opt.dir);
const sigs = readdirSync(dir).filter((f) => f.endsWith(".sig"));
if (sigs.length === 0) die(`${dir} 下没有 .sig 文件（Windows 构建需开启 createUpdaterArtifacts 并注入签名密钥）`);
if (sigs.length > 1) die(`${dir} 下有多个 .sig（${sigs.join(", ")}），无法确定用哪个`);
const sigFile = path.join(dir, sigs[0]);
const artifact = sigs[0].replace(/\.sig$/, "");
if (!existsSync(path.join(dir, artifact))) die(`签名对应的安装包不存在: ${artifact}`);
const signature = readFileSync(sigFile, "utf8").trim();
if (!signature) die(`.sig 内容为空: ${sigs[0]}`);

// ---- notes（可缺省）----
let notes = "";
if (opt.notes && existsSync(opt.notes)) notes = readFileSync(opt.notes, "utf8").trim();

// ---- 输出 ----
const manifest = {
  version,
  notes,
  pub_date: new Date().toISOString(),
  platforms: {
    "windows-x86_64": {
      signature,
      url: `https://github.com/${REPO}/releases/download/v${version}/${artifact}`,
    },
  },
};
const out = opt.out ?? path.join(dir, "latest.json");
writeFileSync(out, JSON.stringify(manifest, null, 2) + "\n");
console.log(`==> ${out}`);
console.log(`    version=${version} artifact=${artifact}`);
