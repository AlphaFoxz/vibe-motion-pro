// UI 入口：通过 mp-daemon 的 IPC 完成连接控制。
// Tauri command 层（src-tauri）负责真正与守护进程通信。

import { invoke } from "@tauri-apps/api/core";
import { detectLang, setLang, t, LANGS, type Lang, type Dict } from "./i18n";

const $ = (id: string) => document.getElementById(id)!;

type StatusSnapshot = {
  state: string;
  rtt_ms: number | null;
  server_ip: string | null;
  client_ip: string | null;
};

let lang: Lang = detectLang();

function renderStatic() {
  const d = t(lang);
  $("appTitle").textContent = d.appTitle;
  ($("server") as HTMLInputElement).placeholder = `vpn.example.com (${d.server})`;
  ($("username") as HTMLInputElement).placeholder = d.username;
  ($("password") as HTMLInputElement).placeholder = d.password;
  $("btn-connect").textContent = d.connect;
  $("btn-disconnect").textContent = d.disconnect;
  $("session-label").textContent = d.session;
  $("server-ip-label").textContent = d.serverIp;
  const sel = $("lang-select") as HTMLSelectElement;
  sel.innerHTML = LANGS.map((l) => `<option value="${l.value}">${l.label}</option>`).join("");
  sel.value = lang;
}

function renderStatus(s: StatusSnapshot, d: Dict) {
  const badge = $("status-badge");
  badge.textContent = (d as Record<string, string>)[s.state] ?? s.state;
  badge.className = `badge ${s.state}`;
  $("server-ip").textContent = s.server_ip ?? "-";
}

async function refresh() {
  const d = t(lang);
  try {
    renderStatus(await invoke<StatusSnapshot>("vpn_status"), d);
  } catch {
    // daemon 未运行时静默
  }
}

async function connect() {
  const profile_id = ($("username") as HTMLInputElement).value || "default";
  await invoke("vpn_start", { profileId: profile_id });
  refresh();
}

async function disconnect() {
  await invoke("vpn_stop");
  refresh();
}

window.addEventListener("DOMContentLoaded", () => {
  renderStatic();
  const sel = $("lang-select") as HTMLSelectElement;
  sel.addEventListener("change", () => {
    lang = sel.value as Lang;
    setLang(lang);
    renderStatic();
    refresh();
  });
  $("btn-connect").addEventListener("click", () => connect().catch(alert));
  $("btn-disconnect").addEventListener("click", () => disconnect().catch(alert));
  refresh();
  setInterval(refresh, 3000);
});
