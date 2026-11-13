// UI 入口：通过 mp-daemon 的 IPC 完成连接控制。
// Tauri command 层（src-tauri）负责真正与守护进程通信；这里先走命令占位。

import { invoke } from "@tauri-apps/api/core";

const $ = (id: string) => document.getElementById(id)!;

type StatusSnapshot = {
  state: string;
  rtt_ms: number | null;
  server_ip: string | null;
  client_ip: string | null;
};

const STATE_LABEL: Record<string, string> = {
  disconnected: "未连接",
  connecting: "连接中",
  connected: "已连接",
  reconnecting: "重连中",
};

function renderStatus(s: StatusSnapshot) {
  const badge = $("status-badge");
  badge.textContent = STATE_LABEL[s.state] ?? s.state;
  badge.className = `badge ${s.state}`;
  $("server-ip").textContent = s.server_ip ?? "-";
}

async function refresh() {
  try {
    renderStatus(await invoke<StatusSnapshot>("vpn_status"));
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
  $("btn-connect").addEventListener("click", () => connect().catch(alert));
  $("btn-disconnect").addEventListener("click", () => disconnect().catch(alert));
  refresh();
  setInterval(refresh, 3000);
});
