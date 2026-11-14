// UI 入口：通过 mp-daemon 的 IPC 完成连接控制。
// Rust 侧（src-tauri/main.rs）维持与 daemon 的单条长连接：
//   - 状态经 "vpn-status" 事件推送（1s 广播，替代旧 3s 轮询）
//   - 链路存活经 "vpn-link" 事件（守护进程未运行时给出提示）
//   - "tray-connect"：托盘「连接」唤起主界面并预选默认服务器

import { invoke } from "@tauri-apps/api/core";
import { listen } from "@tauri-apps/api/event";
import { detectLang, setLang, t, LANGS, type Lang } from "./i18n";

type StatusSnapshot = {
  state: string;
  rtt_ms: number | null;
  server_ip: string | null;
  client_ip: string | null;
};

type Profile = {
  id: string;
  name: string;
  host: string;
  port: number;
  tunnel_type: string;
  autoconnect: boolean;
};

const $ = (id: string) => document.getElementById(id)!;

// ---------- 全局状态 ----------

let lang: Lang = detectLang();
let profiles: Profile[] = [];
let selectedId: string | null = localStorage.getItem("mp_last_profile") || null;
let status: StatusSnapshot = { state: "disconnected", rtt_ms: null, server_ip: null, client_ip: null };
let offline = false; // 与 daemon 的链路断开
let connectingLocal = false; // 乐观置位：点击连接后立即进入 connecting 视觉态
let connectedAt = 0;
let tickTimer: number | null = null;
let editingId: string | null = null; // 编辑器打开时的 profile id；null = 新建
let deletingId: string | null = null; // 两步删除确认

// ---------- 工具 ----------

function fmt(f: string, ...args: string[]): string {
  return f.replace(/\{(\w+)\}/g, (_m, _k) => args.shift() ?? _m);
}

function tunnelLabel(tt: string): string {
  const d = t(lang);
  switch (tt) {
    case "udp": return d.tunnelUdp;
    case "dtls": return d.tunnelDtls;
    case "wireguard": return d.tunnelWg;
    default: return d.tunnelTcp;
  }
}

function fmtDuration(ms: number): string {
  const s = Math.floor(ms / 1000);
  const h = Math.floor(s / 3600), m = Math.floor((s % 3600) / 60), ss = s % 60;
  const two = (n: number) => String(n).padStart(2, "0");
  return h > 0 ? `${h}:${two(m)}:${two(ss)}` : `${two(m)}:${two(ss)}`;
}

function esc(s: string): string {
  return s.replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;").replace(/"/g, "&quot;");
}

// ---------- 渲染：静态文案 ----------

function renderStatic() {
  const d = t(lang);
  document.documentElement.lang = lang;
  $("appTitle").textContent = d.appTitle;

  // data-i18n 挂载点
  const map: Record<string, string> = {
    "server-label": d.server,
    "server-label2": d.server,
    "port-label": d.fPort,
    "username-label": d.username,
    "password-label": d.password,
    "remember-label": d.rememberPwd,
    "otp-label": d.otp,
    "autohide-label": d.autohide,
    "dur-label": d.dur,
    "rtt-label": d.rtt,
    "clientIp-label": d.clientIp,
    "serverIp-label": d.serverIp,
    "servers-hint": d.serversHint,
    "add-server-label": d.addServer,
    "editor-title": editingId ? d.editServer : d.addServer,
    "fName-label": d.fName,
    "fHost-label": d.fHost,
    "fPort-label": d.fPort,
    "fTunnel-label": d.fTunnel,
    "fAuto-label": d.fAuto,
    "btn-editor-save": d.save,
    "btn-editor-cancel": d.cancel,
    "tab-connect-label": d.tabConnect,
    "tab-servers-label": d.tabServers,
    "offline-banner": d.errOffline,
  };
  for (const [id, text] of Object.entries(map)) {
    const el = $(id);
    if (el) el.textContent = text;
  }

  ($("server-host") as HTMLInputElement).placeholder = "vpn.example.com";
  ($("username") as HTMLInputElement).placeholder = d.username;
  ($("password") as HTMLInputElement).placeholder = d.password;
  ($("otp") as HTMLInputElement).placeholder = "——6 位——";

  const sel = $("lang-select") as HTMLSelectElement;
  sel.innerHTML = LANGS.map((l) => `<option value="${l.value}">${l.label}</option>`).join("");
  sel.value = lang;

  renderStatusUI();
  renderServerSelect();
  renderServerCards();
  syncTrayTexts();
}

function syncTrayTexts() {
  const d = t(lang);
  invoke("set_tray_texts", {
    lang,
    show: d.trayShow,
    connect: d.trayConnect,
    disconnect: d.trayDisconnect,
    quit: d.trayQuit,
  }).catch(() => {});
}

// ---------- 渲染：连接视图 ----------

const STATE_KEY: Record<string, keyof ReturnType<typeof t>> = {
  disconnected: "stDisconnected",
  connecting: "stConnecting",
  connected: "stConnected",
  reconnecting: "stReconnecting",
  disconnecting: "stDisconnecting",
};

function renderStatusUI() {
  const d = t(lang);
  // 乐观连接态：本地点击优先于推送（推送最长 1s 延迟）
  const state = connectingLocal && status.state === "disconnected" ? "connecting" : status.state;

  $("ring").setAttribute("data-state", state);
  $("brand-dot").setAttribute("data-state", state);
  $("status-text").textContent = (d as Record<string, string>)[STATE_KEY[state] as string] ?? state;

  const glyph = $("ring-glyph");
  glyph.textContent = state === "connected" ? "✓" : state === "disconnected" ? "—" : "";
  glyph.style.visibility = state === "connecting" || state === "reconnecting" || state === "disconnecting" ? "hidden" : "visible";

  const btn = $("btn-main") as HTMLButtonElement;
  const form = $("conn-form") as HTMLFormElement;
  const busy = state === "connecting" || state === "reconnecting" || state === "disconnecting";
  if (state === "connected") {
    btn.dataset.action = "disconnect";
    btn.disabled = false;
    btn.textContent = d.btnDisconnect;
    $("fields").classList.add("collapsed"); // 已连接：凭据区折叠，圆环与详情占主视图
  } else if (busy) {
    btn.dataset.action = "connect";
    btn.disabled = true;
    btn.textContent = `${d.btnConnecting}`;
    $("fields").classList.remove("collapsed");
  } else {
    btn.dataset.action = "connect";
    btn.disabled = false;
    btn.textContent = d.btnConnect;
    $("fields").classList.remove("collapsed");
  }
  (form.querySelectorAll("input, select") as NodeListOf<HTMLInputElement | HTMLSelectElement>)
    .forEach((el) => { el.disabled = busy; });

  // 副标题 + 详情网格
  const sub = $("status-sub");
  const details = $("conn-details");
  if (state === "connected") {
    sub.textContent = status.server_ip ?? "";
    details.classList.remove("hidden");
    $("rtt").textContent = status.rtt_ms != null ? `${status.rtt_ms} ms` : "-";
    $("client-ip").textContent = status.client_ip ?? "-";
    $("server-ip").textContent = status.server_ip ?? "-";
    $("dur").textContent = connectedAt ? fmtDuration(Date.now() - connectedAt) : "-";
  } else {
    details.classList.add("hidden");
    sub.textContent = busy ? "" : profiles.length === 0 ? d.hintNoServers : d.hintIdle;
    if (!busy && !connectedAt) $("dur").textContent = "-";
  }
}

function startTicker() {
  stopTicker();
  tickTimer = window.setInterval(() => {
    if (status.state === "connected" && connectedAt) {
      $("dur").textContent = fmtDuration(Date.now() - connectedAt);
    }
  }, 1000);
}
function stopTicker() {
  if (tickTimer != null) { clearInterval(tickTimer); tickTimer = null; }
}

function showError(msg: string) {
  $("error-text").textContent = msg;
  $("error-banner").classList.remove("hidden");
}
function hideError() {
  $("error-banner").classList.add("hidden");
}
function showPickHint(name: string) {
  $("pick-banner").textContent = fmt(t(lang).pickHint, name);
  $("pick-banner").classList.remove("hidden");
  setTimeout(() => $("pick-banner").classList.add("hidden"), 6000);
}
function markInvalid(ids: string[]) {
  for (const id of ids) {
    const el = $(id) as HTMLInputElement;
    el.classList.add("invalid");
    setTimeout(() => el.classList.remove("invalid"), 1200);
  }
}

// ---------- 渲染：服务器选择器 ----------

function renderServerSelect() {
  const sel = $("server") as HTMLSelectElement;
  const manual = $("manual-host")!;
  const d = t(lang);

  if (profiles.length === 0) {
    sel.parentElement?.classList.add("hidden");
    manual.classList.remove("hidden");
    return;
  }
  manual.classList.add("hidden");
  sel.parentElement?.classList.remove("hidden");

  sel.innerHTML =
    `<option value="">${d.serverPlaceholder}</option>` +
    profiles
      .map((p) => `<option value="${esc(p.id)}">${esc(p.name)}${p.autoconnect ? " ★" : ""}</option>`)
      .join("") +
    `<option value="__manage">＋ ${d.manageServers}</option>`;
  const cur = profiles.find((p) => p.id === selectedId);
  sel.value = cur ? cur.id : "";
}

// ---------- 渲染：服务器卡片 ----------

function renderServerCards() {
  const wrap = $("server-cards")!;
  const d = t(lang);
  if (profiles.length === 0) {
    wrap.innerHTML = `<div class="empty-tip">${esc(d.empty)}</div>`;
    return;
  }
  wrap.innerHTML = profiles
    .map((p) => {
      const last = localStorage.getItem(`mp_last_connected:${p.id}`);
      const lastTxt = last
        ? `${d.lastConn} ${new Date(Number(last)).toLocaleString(lang, { month: "short", day: "numeric", hour: "2-digit", minute: "2-digit" })}`
        : `${d.lastConn}: ${d.never}`;
      const active = status.state === "connected";
      if (deletingId === p.id) {
        return `<div class="card" data-id="${esc(p.id)}">
          <div class="card-confirm">
            <span>${esc(d.delConfirm)} <b>${esc(p.name)}</b></span>
            <span class="spacer"></span>
            <button class="btn danger mini-del-yes">${esc(d.del)}</button>
            <button class="btn ghost mini-del-no">${esc(d.cancel)}</button>
          </div>
        </div>`;
      }
      return `<div class="card ${selectedId === p.id ? "selected" : ""}" data-id="${esc(p.id)}">
        <div class="card-top">
          <span class="card-dot ${active && selectedId === p.id ? "on" : ""}"></span>
          <span class="card-name">${esc(p.name)}</span>
          <span class="card-actions">
            <button class="star ${p.autoconnect ? "on" : ""}" data-act="default" title="${esc(p.autoconnect ? d.isDefault : d.setDefault)}">★</button>
            <button class="mini" data-act="edit" title="${esc(d.editServer)}">✎</button>
            <button class="mini" data-act="del" title="${esc(d.del)}">✕</button>
          </span>
        </div>
        <div class="card-host">${esc(p.host)}:${p.port}</div>
        <div class="card-meta">
          <span class="chip">${esc(tunnelLabel(p.tunnel_type))}</span>
          ${p.autoconnect ? `<span class="chip">${esc(d.isDefault)}</span>` : ""}
          <span>${esc(lastTxt)}</span>
        </div>
      </div>`;
    })
    .join("");

  // 事件绑定
  wrap.querySelectorAll(".card").forEach((card) => {
    const id = (card as HTMLElement).dataset.id!;
    // 两步删除确认
    const yes = card.querySelector(".mini-del-yes") as HTMLButtonElement | null;
    const no = card.querySelector(".mini-del-no") as HTMLButtonElement | null;
    if (yes) {
      yes.addEventListener("click", (ev) => { ev.stopPropagation(); void doDelete(id); });
      no?.addEventListener("click", (ev) => { ev.stopPropagation(); deletingId = null; renderServerCards(); });
      return;
    }
    card.addEventListener("click", () => {
      selectProfile(id, true);
      switchTab("connect");
    });
    card.querySelectorAll("[data-act]").forEach((btn) => {
      btn.addEventListener("click", (ev) => {
        ev.stopPropagation();
        const act = (btn as HTMLElement).dataset.act;
        if (act === "edit") openEditor(id);
        else if (act === "del") { deletingId = id; renderServerCards(); }
        else if (act === "default") void setDefault(id);
      });
    });
  });
}

// ---------- 服务器数据 ----------

async function loadProfiles() {
  try {
    profiles = await invoke<Profile[]>("profile_list");
    // 兼容旧数据：id = name 的历史 profile 保留原 id
    renderServerSelect();
    renderServerCards();
    if (selectedId && !profiles.some((p) => p.id === selectedId)) selectedId = null;
  } catch (e) {
    setOffline(true);
  }
}

function selectProfile(id: string, withHint = false) {
  const p = profiles.find((x) => x.id === id);
  if (!p) return;
  selectedId = id;
  localStorage.setItem("mp_last_profile", id);
  renderServerSelect();
  renderServerCards();

  // 回填用户名 / 记住的密码
  const uname = localStorage.getItem(`mp_username:${id}`) ?? "";
  ($("username") as HTMLInputElement).value = uname;
  ($("password") as HTMLInputElement).value = "";
  ($("remember-pwd") as HTMLInputElement).checked = false;
  void (async () => {
    try {
      const saved = await invoke<string | null>("password_get", { profileId: id });
      if (saved) {
        ($("password") as HTMLInputElement).value = saved;
        ($("remember-pwd") as HTMLInputElement).checked = true;
      }
    } catch { /* keychain 不可用 */ }
  })();

  if (withHint) showPickHint(p.name);
}

async function doDelete(id: string) {
  try {
    profiles = await invoke<Profile[]>("profile_remove", { profileId: id });
    invoke("password_delete", { profileId: id }).catch(() => {});
    localStorage.removeItem(`mp_last_connected:${id}`);
    localStorage.removeItem(`mp_username:${id}`);
    if (selectedId === id) { selectedId = null; localStorage.removeItem("mp_last_profile"); }
  } catch (e) {
    showError(String(e));
  }
  deletingId = null;
  renderServerSelect();
  renderServerCards();
}

async function setDefault(id: string) {
  try {
    // 单默认：把选中的置 autoconnect，其余清掉
    const changed = profiles.map((p) =>
      p.id === id ? { ...p, autoconnect: true } : p.autoconnect ? { ...p, autoconnect: false } : null
    ).filter((x): x is Profile => x !== null);
    await Promise.all(changed.map((p) => invoke("profile_add", { profile: p })));
    profiles = await invoke<Profile[]>("profile_list");
  } catch (e) {
    showError(String(e));
  }
  renderServerSelect();
  renderServerCards();
}

function openEditor(id: string | null) {
  editingId = id;
  const p = id ? profiles.find((x) => x.id === id) : null;
  $("editor-title").textContent = t(lang)[editingId ? "editServer" : "addServer"];
  ($("f-name") as HTMLInputElement).value = p?.name ?? "";
  ($("f-host") as HTMLInputElement).value = p?.host ?? "";
  ($("f-port") as HTMLInputElement).value = String(p?.port ?? 443);
  ($("f-tunnel") as HTMLSelectElement).value = p?.tunnel_type ?? "tcp";
  ($("f-auto") as HTMLInputElement).checked = p?.autoconnect ?? false;
  $("server-editor").classList.remove("hidden");
}

function closeEditor() {
  editingId = null;
  $("server-editor").classList.add("hidden");
}

async function saveEditor() {
  const name = ($("f-name") as HTMLInputElement).value.trim();
  const host = ($("f-host") as HTMLInputElement).value.trim();
  const port = parseInt(($("f-port") as HTMLInputElement).value, 10) || 443;
  const tunnel = ($("f-tunnel") as HTMLSelectElement).value;
  const auto = ($("f-auto") as HTMLInputElement).checked;
  if (!name || !host) {
    showError(t(lang).errRequired);
    markInvalid([name ? "f-host" : "f-name"]);
    return;
  }
  const id = editingId ?? (crypto.randomUUID ? crypto.randomUUID() : `p-${Date.now()}`);
  try {
    const p: Profile = {
      id, name, host, port, tunnel_type: tunnel,
      autoconnect: auto || (editingId ? profiles.find((x) => x.id === id)?.autoconnect === true : false),
    };
    profiles = await invoke<Profile[]>("profile_add", { profile: p });
    // 选了默认则清掉其他
    if (auto) await setDefaultQuiet(id);
    closeEditor();
  } catch (e) {
    showError(String(e));
  }
  renderServerSelect();
  renderServerCards();
}

async function setDefaultQuiet(id: string) {
  const changed = profiles.map((p) =>
    p.id === id ? { ...p, autoconnect: true } : p.autoconnect ? { ...p, autoconnect: false } : null
  ).filter((x): x is Profile => x !== null);
  await Promise.all(changed.map((p) => invoke("profile_add", { profile: p })));
  profiles = await invoke<Profile[]>("profile_list");
}

// ---------- 连接流程 ----------

function currentServer(): { host: string; port: number } | null {
  if (profiles.length > 0) {
    const p = profiles.find((x) => x.id === selectedId);
    return p ? { host: p.host, port: p.port } : null;
  }
  const host = ($("server-host") as HTMLInputElement).value.trim();
  const port = parseInt(($("server-port") as HTMLInputElement)?.value ?? "443", 10) || 443;
  return host ? { host, port } : null;
}

async function connect() {
  const d = t(lang);
  hideError();
  const srv = currentServer();
  const username = ($("username") as HTMLInputElement).value.trim();
  const password = ($("password") as HTMLInputElement).value;
  const code = ($("otp") as HTMLInputElement).value.trim();

  const missing: string[] = [];
  if (!srv) missing.push("server-host");
  if (!username) missing.push("username");
  if (!password) missing.push("password");
  if (!code) missing.push("otp");
  if (missing.length > 0) {
    markInvalid(missing);
    showError(d.errFill);
    return;
  }

  connectingLocal = true;
  renderStatusUI(); // 即时反馈：按钮转 spinner、表单锁定
  try {
    const snap = await invoke<StatusSnapshot>("vpn_connect", {
      host: srv!.host, port: srv!.port, username, password, code,
    });
    connectingLocal = false;
    applyStatus(snap);
  } catch (e) {
    connectingLocal = false;
    showError(String(e));
    renderStatusUI();
    return;
  }

  // 连接成功：记住凭据偏好
  if (selectedId) {
    localStorage.setItem(`mp_username:${selectedId}`, username);
    const remember = ($("remember-pwd") as HTMLInputElement).checked;
    if (remember) {
      invoke("password_save", { profileId: selectedId, password }).catch(() => showError(d.keyringFail));
    } else {
      invoke("password_delete", { profileId: selectedId }).catch(() => {});
    }
  }
}

async function disconnect() {
  connectingLocal = false;
  try {
    const snap = await invoke<StatusSnapshot>("vpn_stop");
    applyStatus(snap);
  } catch (e) {
    showError(String(e));
  }
}

function applyStatus(snap: StatusSnapshot) {
  const prev = status.state;
  status = snap;
  if (snap.state === "connected" && prev !== "connected") {
    connectedAt = Date.now();
    startTicker();
    if (selectedId) localStorage.setItem(`mp_last_connected:${selectedId}`, String(Date.now()));
    // 自动收起到托盘（可在设置勾选关闭）
    if (localStorage.getItem("mp_autohide") !== "0") {
      setTimeout(() => invoke("ui_hide_window").catch(() => {}), 1200);
    }
  }
  if (snap.state !== "connected" && prev === "connected") {
    connectedAt = 0;
    stopTicker();
  }
  if (snap.state === "disconnected") connectingLocal = false;
  renderStatusUI();
  renderServerCards();
}

function setOffline(v: boolean) {
  offline = v;
  $("offline-banner").classList.toggle("hidden", !offline);
  if (offline) {
    connectingLocal = false;
    renderStatusUI();
  }
}

// ---------- 视图切换 ----------

function switchTab(tab: "connect" | "servers") {
  document.querySelectorAll(".view").forEach((v) => v.classList.remove("active"));
  $(`view-${tab}`).classList.add("active");
  document.querySelectorAll(".tab").forEach((tb) => {
    tb.classList.toggle("active", (tb as HTMLElement).dataset.tab === tab);
  });
}

// ---------- 初始化 ----------

window.addEventListener("DOMContentLoaded", () => {
  renderStatic();
  loadProfiles().then(() => {
    // 启动预选：默认(autoconnect) > 上次选择 > 第一个
    const def = profiles.find((p) => p.autoconnect);
    const pick = def?.id ?? selectedId ?? profiles[0]?.id;
    if (pick) selectProfile(pick);
  });

  // 事件桥（Rust 长连接推送）
  void listen<StatusSnapshot>("vpn-status", (ev) => { connectingLocal = false; applyStatus(ev.payload); });
  void listen<boolean>("vpn-link", (ev) => setOffline(!ev.payload));
  void listen("tray-connect", () => {
    switchTab("connect");
    const def = profiles.find((p) => p.autoconnect) ?? profiles[0];
    if (def) { selectProfile(def.id, true); }
    ($("otp") as HTMLInputElement).focus();
  });

  // 初始状态兜底：若推送未到，主动查一次
  invoke<StatusSnapshot>("vpn_status")
    .then((s) => applyStatus(s))
    .catch(() => setOffline(true));

  // 语言
  ($("lang-select") as HTMLSelectElement).addEventListener("change", () => {
    lang = ($("lang-select") as HTMLSelectElement).value as Lang;
    setLang(lang);
    renderStatic();
  });

  // Tab 切换
  document.querySelectorAll(".tab").forEach((tb) => {
    tb.addEventListener("click", () => switchTab((tb as HTMLElement).dataset.tab as "connect" | "servers"));
  });

  // 服务器选择器
  ($("server") as HTMLSelectElement).addEventListener("change", () => {
    const v = ($("server") as HTMLSelectElement).value;
    if (v === "__manage") {
      ($("server") as HTMLSelectElement).value = selectedId ?? "";
      switchTab("servers");
      return;
    }
    if (v) selectProfile(v);
  });

  // 连接表单
  $("conn-form").addEventListener("submit", (ev) => {
    ev.preventDefault();
    const state = status.state === "connected" ? disconnect() : connect();
    void state;
  });
  $("error-close").addEventListener("click", hideError);

  // 自动收起偏好
  const autohide = $("autohide") as HTMLInputElement;
  autohide.checked = localStorage.getItem("mp_autohide") !== "0";
  autohide.addEventListener("change", () => {
    localStorage.setItem("mp_autohide", autohide.checked ? "1" : "0");
    invoke("set_autohide", { enabled: autohide.checked }).catch(() => {});
  });
  invoke("set_autohide", { enabled: autohide.checked }).catch(() => {});

  // 服务器管理
  $("btn-add-server").addEventListener("click", () => openEditor(null));
  $("btn-editor-save").addEventListener("click", () => void saveEditor());
  $("btn-editor-cancel").addEventListener("click", closeEditor);
});
