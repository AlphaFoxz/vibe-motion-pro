// 「日志」页：显示守护进程 / 界面进程自启动以来的日志（后端：mp-ipc::log 环形缓冲）。
//
// 惰性约定——不看日志时，这里不产生任何开销：
//   - 仅当「日志」Tab 激活时才轮询（1s 一次；VPN 状态 / 链路变化时额外立即拉一次）；
//   - 离开 Tab 即停表、丢弃已拉取的日志，并让后端断开守护进程日志连接（log_close）；
//   - 窗口被收起 / 最小化时由后端直接跳过（返回 paused），不碰守护进程。
// 本模块不监听任何 Tauri 事件；状态变化由 main.ts 经 logsPoke() 转达。

import { invoke } from "@tauri-apps/api/core";
import { t, type Lang } from "./i18n";
import { $, esc, fmt } from "./util";

type Level = "ERROR" | "WARN" | "INFO" | "DEBUG" | "TRACE";
type Src = "daemon" | "ui";
type LevelFilter = "all" | "warn" | "error";

type WireLine = { seq: number; ts: number; level: Level; target: string; msg: string };
type Batch = { epoch: number; next: number; dropped: number; lines: WireLine[] };
type DaemonLog = ({ state: "online" } & Batch) | { state: "offline" } | { state: "incompatible" };
type TailOut = { paused: boolean; ui: Batch | null; daemon: DaemonLog | null };

type LogItem = { kind: "log"; src: Src; ts: number; level: Level; target: string; msg: string };
type SepItem = { kind: "sep"; ts: number; text: string };
type Item = LogItem | SepItem;

const POLL_MS = 1000;
/** 内存里最多保留的条目数（两路环形缓冲各 2000 行，默认级别下不会触顶）。 */
const MAX_ITEMS = 4000;
/** DOM 里最多渲染的行数；超出只渲染最近的，复制仍可得全部。 */
const MAX_RENDER = 1000;

const RANK: Record<Level, number> = { ERROR: 0, WARN: 1, INFO: 2, DEBUG: 3, TRACE: 4 };
const FILTER_MAX: Record<LevelFilter, number> = { all: RANK.TRACE, warn: RANK.WARN, error: RANK.ERROR };

let langOf: () => Lang = () => "zh-CN";
let bound = false;
let active = false;
let loaded = false; // 本次打开后是否已完成首次拉取
let timer: number | null = null;
let searchTimer: number | null = null;
let toastTimer: number | null = null;
let pollFailed = false; // 上一轮是否失败（console.warn 只报一次，免得每秒刷屏）
/** 会话代号：每次 logsOpen 递增。上一会话尚在途的轮询结果一律作废——否则快速
 *  「离开 → 再进入」时新旧两个轮询同时在途，旧结果会被当成新会话的数据重复应用。 */
let gen = 0;
let inFlightGen = 0; // 正在途的轮询所属的会话代号，0 = 无

let items: Item[] = []; // 按 ts 有序
let uiNext = 0;
let uiDropped = 0;
let daemon: { epoch: number; next: number; dropped: number } | null = null;
let daemonState: DaemonLog["state"] = "offline";
let levelFilter: LevelFilter = "all";
let query = ""; // 已转小写
let atBottom = true;
let unseen = 0; // 用户翻到上方期间累计的新行数
let frontDropped = 0; // 超过 MAX_ITEMS 时前端自己丢掉的行数

// ---------- 判断与格式化 ----------

function matches(it: Item): boolean {
  if (it.kind === "sep") return true; // 分隔线是上下文，任何筛选下都保留
  if (RANK[it.level] > FILTER_MAX[levelFilter]) return false;
  if (!query) return true;
  return it.msg.toLowerCase().includes(query) || it.target.toLowerCase().includes(query);
}

/** 去掉 ANSI 转义序列，其余控制字符换成空格：日志里可能带来自网络/系统的杂散字节。 */
function cleanMsg(msg: string): string {
  return msg.replace(/\x1b\[[0-9;?]*[ -/]*[@-~]/g, "").replace(/[\x00-\x1f\x7f]/g, " ");
}

const two = (n: number) => String(n).padStart(2, "0");

function fmtClock(ts: number): string {
  const d = new Date(ts);
  return `${two(d.getHours())}:${two(d.getMinutes())}:${two(d.getSeconds())}`;
}

/** 导出用：本地时间，带日期与毫秒。 */
function fmtStamp(ts: number): string {
  const d = new Date(ts);
  return `${d.getFullYear()}-${two(d.getMonth() + 1)}-${two(d.getDate())} ${fmtClock(ts)}.${String(d.getMilliseconds()).padStart(3, "0")}`;
}

/** 运行时长：HH:MM:SS，超过一天时前置天数。 */
function fmtUptime(since: number): string {
  const s = Math.max(0, Math.floor((Date.now() - since) / 1000));
  const days = Math.floor(s / 86400);
  const hms = `${two(Math.floor((s % 86400) / 3600))}:${two(Math.floor((s % 3600) / 60))}:${two(s % 60)}`;
  return days > 0 ? `${days}${t(langOf()).logDayUnit}${hms}` : hms;
}

// ---------- 渲染 ----------

function rowHtml(it: Item): string {
  if (it.kind === "sep") {
    return `<div class="log-sep"><span>${esc(it.text)}</span></div>`;
  }
  const src = it.src === "ui" ? `<span class="log-src">${esc(t(langOf()).logUiTag)}</span>` : "";
  return (
    `<div class="log-row" data-level="${esc(it.level)}" title="${esc(it.target)}">` +
    `<span class="log-t">${fmtClock(it.ts)}</span><span class="log-lv">${esc(it.level)}</span>${src}` +
    `<span class="log-m">${esc(it.msg)}</span></div>`
  );
}

const noteHtml = (text: string) => `<div class="log-note">${esc(text)}</div>`;

function isAtBottom(): boolean {
  const el = $("log-scroll");
  return el.scrollHeight - el.scrollTop - el.clientHeight < 24;
}

function scrollToBottom(): void {
  const el = $("log-scroll");
  el.scrollTop = el.scrollHeight;
}

/** 全量重建列表（打开日志页、切换筛选、乱序插入时）。 */
function rebuild(): void {
  const vis = items.filter(matches);
  const skipped = Math.max(0, vis.length - MAX_RENDER);
  const html: string[] = [];
  const dropped = frontDropped + uiDropped + (daemon?.dropped ?? 0);
  if (dropped > 0) html.push(noteHtml(fmt(t(langOf()).logDropped, String(dropped))));
  if (skipped > 0) html.push(noteHtml(fmt(t(langOf()).logRenderCap, String(MAX_RENDER), String(vis.length))));
  for (const it of vis.slice(skipped)) html.push(rowHtml(it));
  $("log-list").innerHTML = html.join("");
  if (atBottom) scrollToBottom();
}

/** 增量追加一批落在末尾的新行（常规路径：不重建已有 DOM，翻阅中的滚动位置自然保持）。 */
function append(fresh: Item[]): void {
  const list = $("log-list");
  if (list.childElementCount + fresh.length > MAX_RENDER + 200) {
    rebuild();
    return;
  }
  list.insertAdjacentHTML("beforeend", fresh.map(rowHtml).join(""));
  if (atBottom) scrollToBottom();
}

function showJump(count: number): void {
  unseen = count;
  const el = $("log-jump");
  el.textContent = fmt(t(langOf()).logNewLines, String(unseen));
  el.classList.remove("hidden");
}

function onScroll(): void {
  atBottom = isAtBottom();
  if (atBottom) {
    unseen = 0;
    $("log-jump").classList.add("hidden");
  }
}

function setCount(id: string, n: number): void {
  const el = $(id);
  el.textContent = String(n);
  el.classList.toggle("hidden", n === 0);
}

/** 状态行（守护进程是否在线 / 启动时间 / 运行时长）、筛选计数、空态。 */
function renderMeta(): void {
  const d = t(langOf());

  let warn = 0;
  let error = 0;
  let total = 0;
  for (const it of items) {
    if (it.kind !== "log") continue;
    total++;
    if (RANK[it.level] <= RANK.ERROR) error++;
    if (RANK[it.level] <= RANK.WARN) warn++;
  }
  setCount("log-cnt-warn", warn);
  setCount("log-cnt-error", error);

  const dot = (state: string) => `<span class="log-dot" data-state="${state}"></span>`;
  let status: string;
  if (!loaded) {
    // 首次拉取还没回来：此时并不知道守护进程是否在线，不能提前下结论
    status = `${dot("pending")}<span>${esc(d.logDaemon)}</span>`;
  } else if (daemonState === "online" && daemon) {
    status =
      `${dot("online")}<span>${esc(d.logDaemon)}</span>` +
      `<span class="log-meta">${esc(fmt(d.logStartedAt, fmtClock(daemon.epoch)))} · ${esc(fmt(d.logUptime, fmtUptime(daemon.epoch)))}</span>`;
  } else {
    status =
      daemonState === "offline"
        ? `${dot("offline")}<span>${esc(d.logDaemonOffline)}</span>`
        : `${dot("incompatible")}<span>${esc(d.logDaemonIncompatible)}</span>`;
  }
  if (total > 0) status += `<span class="log-meta">${esc(fmt(d.logLineCount, String(total)))}</span>`;
  $("log-status").innerHTML = status;

  // 空态：读取中 / 没有任何日志 / 有日志但被筛选条件全部滤掉
  let title = "";
  let hint = "";
  if (!loaded) {
    title = d.logLoading;
  } else if (items.length === 0) {
    title = d.logEmpty;
    hint = d.logEmptyHint;
  } else if (!items.some(matches)) {
    title = d.logNoMatch;
  }
  const empty = $("log-empty");
  if (!title) {
    empty.classList.add("hidden");
  } else {
    empty.innerHTML = `<b>${esc(title)}</b>${hint ? `<span>${esc(hint)}</span>` : ""}`;
    empty.classList.remove("hidden");
  }
}

// ---------- 数据 ----------

function toLog(src: Src, l: WireLine): LogItem {
  return { kind: "log", src, ts: l.ts, level: l.level, target: l.target, msg: cleanMsg(l.msg) };
}

/** 按 ts 有序插入（同 ts 保持到达顺序）。返回是否全部落在末尾（可增量渲染）。 */
function insert(fresh: Item[]): boolean {
  let appended = true;
  for (const it of fresh) {
    let i = items.length;
    while (i > 0 && items[i - 1].ts > it.ts) i--;
    if (i < items.length) appended = false;
    items.splice(i, 0, it);
  }
  if (items.length > MAX_ITEMS) {
    frontDropped += items.length - MAX_ITEMS;
    items.splice(0, items.length - MAX_ITEMS);
    appended = false;
  }
  return appended;
}

function applyBatch(res: TailOut): void {
  const fresh: Item[] = [];

  if (res.ui) {
    fresh.push(...res.ui.lines.map((l) => toLog("ui", l)));
    uiNext = res.ui.next;
    uiDropped = res.ui.dropped;
  }

  const prev = daemon;
  const prevState = daemonState;
  if (res.daemon?.state === "online") {
    const b = res.daemon;
    daemonState = "online";
    daemon = { epoch: b.epoch, next: b.next, dropped: b.dropped };
    const d = t(langOf());
    if (prev && prev.epoch !== b.epoch) {
      // 守护进程重启：旧日志留在上方，插一条分隔线交代来龙去脉
      fresh.push({ kind: "sep", ts: b.epoch, text: `${d.logRestart} · ${fmtClock(b.epoch)}` });
    } else if (!prev && loaded && prevState !== "online") {
      // 页面开着期间守护进程从离线变为可读
      fresh.push({ kind: "sep", ts: Date.now(), text: `${d.logDaemonUp} · ${fmtClock(Date.now())}` });
    }
    fresh.push(...b.lines.map((l) => toLog("daemon", l)));
  } else if (res.daemon) {
    daemonState = res.daemon.state;
  }

  loaded = true;
  // 两条渲染路径（末尾追加 / 乱序插入后整体重建）在此汇合：用户没停在底部时，
  // 新行一律不拉动滚动位置，只累计到「N 条新日志」浮层里。
  const rows = fresh.filter(matches);
  if (rows.length > 0) {
    if (insert(fresh)) append(rows);
    else rebuild();
    if (atBottom) scrollToBottom();
    else showJump(unseen + rows.length);
  }
  renderMeta();
}

async function poll(): Promise<void> {
  if (!active || inFlightGen === gen) return;
  const g = gen;
  inFlightGen = g;
  try {
    const res = await invoke<TailOut>("log_tail", {
      cursor: { ui_from: uiNext, daemon_epoch: daemon?.epoch ?? 0, daemon_from: daemon?.next ?? 0 },
    });
    if (g !== gen || !active || res.paused) return;
    pollFailed = false;
    applyBatch(res);
  } catch (e) {
    if (g !== gen) return;
    // 单轮失败不打扰用户：游标没有前进，下一轮自然重试
    if (!pollFailed) console.warn("log_tail failed:", e);
    pollFailed = true;
  } finally {
    if (inFlightGen === g) inFlightGen = 0;
  }
}

// ---------- 复制 ----------

function exportText(): string {
  const d = t(langOf());
  const out = [fmt(d.logExportHead, fmtStamp(Date.now()))];
  if (daemonState === "online" && daemon) {
    out.push(fmt(d.logExportDaemonUp, fmtStamp(daemon.epoch), fmtUptime(daemon.epoch)));
  } else {
    out.push(daemonState === "offline" ? d.logDaemonOffline : d.logDaemonIncompatible);
  }
  out.push("--------");
  for (const it of items) {
    if (!matches(it)) continue;
    out.push(
      it.kind === "sep"
        ? `---- ${it.text} ----`
        : `${fmtStamp(it.ts)}  ${it.level.padEnd(5)} [${it.src}] ${it.target}: ${it.msg}`,
    );
  }
  return out.join("\n");
}

/** 复制到剪贴板。不为此引入剪贴板插件：优先同步的 execCommand（各平台 WebView
 * 里都要求在用户手势内调用），不行再退回异步的 Clipboard API。 */
async function copyToClipboard(text: string): Promise<boolean> {
  const ta = document.createElement("textarea");
  ta.value = text;
  ta.setAttribute("readonly", "");
  ta.className = "log-clip";
  document.body.appendChild(ta);
  ta.select();
  let ok = false;
  try {
    ok = document.execCommand("copy");
  } catch {
    ok = false;
  }
  ta.remove();
  if (ok) return true;
  try {
    await navigator.clipboard.writeText(text);
    return true;
  } catch {
    return false;
  }
}

function toast(msg: string): void {
  if (toastTimer != null) clearTimeout(toastTimer);
  const el = $("log-toast");
  el.textContent = msg;
  el.classList.remove("hidden");
  toastTimer = window.setTimeout(() => {
    toastTimer = null;
    el.classList.add("hidden");
  }, 1800);
}

async function copyAll(): Promise<void> {
  const d = t(langOf());
  const count = items.filter((it) => it.kind === "log" && matches(it)).length;
  if (count === 0) {
    toast(d.logCopyEmpty);
    return;
  }
  toast((await copyToClipboard(exportText())) ? fmt(d.logCopied, String(count)) : d.logCopyFail);
}

// ---------- 筛选 ----------

function setLevel(level: LevelFilter): void {
  levelFilter = level;
  $("log-level-seg")
    .querySelectorAll("button")
    .forEach((b) => b.classList.toggle("on", (b as HTMLElement).dataset.level === level));
  rebuild();
}

function setQuery(q: string): void {
  query = q.trim().toLowerCase();
  rebuild();
}

// ---------- 生命周期（由 main.ts 的 Tab 切换驱动） ----------

/** 绑定事件并登记语言取值函数。DOMContentLoaded 时调用一次。 */
export function initLogs(getLang: () => Lang): void {
  langOf = getLang;
  if (bound) return;
  bound = true;

  $("log-level-seg").addEventListener("click", (ev) => {
    const btn = (ev.target as HTMLElement).closest("button") as HTMLElement | null;
    if (btn?.dataset.level) setLevel(btn.dataset.level as LevelFilter);
  });

  const search = $("log-search") as HTMLInputElement;
  const clear = $("log-search-clear");
  search.addEventListener("input", () => {
    clear.classList.toggle("hidden", search.value === "");
    // 边输入边筛，重建略作去抖
    if (searchTimer != null) clearTimeout(searchTimer);
    searchTimer = window.setTimeout(() => {
      searchTimer = null;
      setQuery(search.value);
    }, 150);
  });
  clear.addEventListener("click", () => {
    search.value = "";
    clear.classList.add("hidden");
    setQuery("");
    search.focus();
  });

  $("log-copy").addEventListener("click", () => void copyAll());
  $("log-scroll").addEventListener("scroll", onScroll, { passive: true });
  $("log-jump").addEventListener("click", scrollToBottom);

  // 快捷键（仅日志页激活时生效）：/ 或 Ctrl/Cmd+F 聚焦筛选框，Esc 清空
  document.addEventListener("keydown", (ev) => {
    if (!active) return;
    const typing = (ev.target as HTMLElement).tagName === "INPUT";
    if (ev.key === "Escape" && typing) {
      clear.click();
    } else if (!typing && (ev.key === "/" || ((ev.ctrlKey || ev.metaKey) && ev.key.toLowerCase() === "f"))) {
      ev.preventDefault();
      search.focus();
    }
  });
}

/** 进入「日志」Tab：从零开始拉全量历史，并开始 1s 轮询。 */
export function logsOpen(): void {
  if (active) return;
  active = true;
  gen++; // 上一会话在途的轮询结果自此作废
  loaded = false;
  pollFailed = false;
  items = [];
  uiNext = 0;
  uiDropped = 0;
  daemon = null;
  daemonState = "offline";
  levelFilter = "all";
  query = "";
  atBottom = true;
  unseen = 0;
  frontDropped = 0;
  const search = $("log-search") as HTMLInputElement;
  search.value = "";
  $("log-search-clear").classList.add("hidden");
  $("log-jump").classList.add("hidden");
  $("log-list").innerHTML = "";
  $("log-level-seg")
    .querySelectorAll("button")
    .forEach((b) => b.classList.toggle("on", (b as HTMLElement).dataset.level === "all"));
  renderMeta();

  void poll();
  timer = window.setInterval(() => void poll(), POLL_MS);
}

/** 离开「日志」Tab：停表、清空、断开守护进程日志连接。 */
export function logsClose(): void {
  if (!active) return;
  active = false;
  if (timer != null) {
    clearInterval(timer);
    timer = null;
  }
  if (searchTimer != null) {
    clearTimeout(searchTimer);
    searchTimer = null;
  }
  if (toastTimer != null) {
    clearTimeout(toastTimer);
    toastTimer = null;
  }
  $("log-toast").classList.add("hidden");
  // 不看日志 = 不占内存；下次进入重新拉全量（毫秒级）
  items = [];
  daemon = null;
  $("log-list").innerHTML = "";
  void invoke("log_close").catch(() => {});
}

/** 用户正在看日志时，状态 / 链路刚有变化：立即拉一次，而不是等下一个 1s 节拍。 */
export function logsPoke(): void {
  if (active) void poll();
}

/** 语言切换后刷新日志页内的动态文案。 */
export function logsRenderStatic(): void {
  renderMeta();
  if (active) rebuild();
}
