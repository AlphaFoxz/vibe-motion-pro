// UI 入口：通过 mp-daemon 的 IPC 完成连接控制。
// Tauri command 层（src-tauri）负责真正与守护进程通信。

import { invoke } from "@tauri-apps/api/core";
import { detectLang, setLang, t, LANGS, type Lang, type Dict } from "./i18n";

type ProfileMsg = {
  id: string;
  name: string;
  host: string;
  port: number;
  tunnel_type: string;
  autoconnect: boolean;
};

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

async function loadProfiles() {
  try {
    const profiles = await invoke<ProfileMsg[]>("profile_list");
    const list = $("profiles-list");
    list.innerHTML = profiles
      .map(
        (p) =>
          `<li data-id="${p.id}"><b>${p.name}</b> (${p.host}:${p.port}, ${p.tunnel_type}) <button class="del" data-id="${p.id}">x</button></li>`
      )
      .join("");
    list.querySelectorAll("li").forEach((li) => {
      li.addEventListener("click", (ev) => {
        if ((ev.target as HTMLElement).classList.contains("del")) return;
        const id = (li as HTMLElement).dataset.id!;
        ($("username") as HTMLInputElement).value = id;
        connect().catch(alert);
      });
    });
    list.querySelectorAll("button.del").forEach((btn) => {
      btn.addEventListener("click", async (ev) => {
        ev.stopPropagation();
        await invoke("profile_remove", { profileId: (btn as HTMLElement).dataset.id });
        loadProfiles();
      });
    });
  } catch {
    // daemon 未运行
  }
}

async function addProfile() {
  const name = ($("profile-name") as HTMLInputElement).value.trim();
  const host = ($("profile-host") as HTMLInputElement).value.trim();
  if (!name || !host) return;
  await invoke("profile_add", {
    profile: { id: name, name, host, port: 443, tunnel_type: "tcp", autoconnect: false },
  });
  ($("profile-name") as HTMLInputElement).value = "";
  ($("profile-host") as HTMLInputElement).value = "";
  loadProfiles();
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
  $("btn-add-profile").addEventListener("click", () => addProfile().catch(alert));
  renderStatic();
  refresh();
  loadProfiles();
  setInterval(refresh, 3000);
});
