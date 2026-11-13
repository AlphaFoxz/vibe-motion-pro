// i18n：中/英/日三语（对齐原版 qt_zh_CN.qm / vpn_zh_CN.qm / qtbase_ja.qm / vpn_ja.qm）
export type Lang = "zh-CN" | "en" | "ja";

const dict = {
  "zh-CN": {
    appTitle: "MotionPro",
    disconnected: "未连接",
    connecting: "连接中",
    connected: "已连接",
    reconnecting: "重连中",
    disconnecting: "断开中",
    server: "服务器",
    username: "用户名",
    password: "密码",
    connect: "连接",
    disconnect: "断开",
    session: "会话",
    serverIp: "服务器 IP",
    addProfile: "添加配置",
    profileName: "配置名称",
    language: "语言",
  },
  en: {
    appTitle: "MotionPro",
    disconnected: "Disconnected",
    connecting: "Connecting",
    connected: "Connected",
    reconnecting: "Reconnecting",
    disconnecting: "Disconnecting",
    server: "Server",
    username: "Username",
    password: "Password",
    connect: "Connect",
    disconnect: "Disconnect",
    session: "Session",
    serverIp: "Server IP",
    addProfile: "Add Profile",
    profileName: "Profile Name",
    language: "Language",
  },
  ja: {
    appTitle: "MotionPro",
    disconnected: "未接続",
    connecting: "接続中",
    connected: "接続済み",
    reconnecting: "再接続中",
    disconnecting: "切断中",
    server: "サーバー",
    username: "ユーザー名",
    password: "パスワード",
    connect: "接続",
    disconnect: "切断",
    session: "セッション",
    serverIp: "サーバー IP",
    addProfile: "プロファイル追加",
    profileName: "プロファイル名",
    language: "言語",
  },
} as const;

export type Dict = (typeof dict)["zh-CN"];

const STORAGE_KEY = "mp_lang";

export function detectLang(): Lang {
  const saved = localStorage.getItem(STORAGE_KEY) as Lang | null;
  if (saved && saved in dict) return saved;
  const nav = navigator.language;
  if (nav.startsWith("ja")) return "ja";
  if (nav.startsWith("zh")) return "zh-CN";
  return "en";
}

export function setLang(lang: Lang) {
  localStorage.setItem(STORAGE_KEY, lang);
}

export function t(lang: Lang): Dict {
  return dict[lang] as Dict;
}

export const LANGS: { value: Lang; label: string }[] = [
  { value: "zh-CN", label: "中文" },
  { value: "en", label: "English" },
  { value: "ja", label: "日本語" },
];
