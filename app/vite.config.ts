import { defineConfig } from "vite";

// Tauri 期望固定的前端端口与产物目录
export default defineConfig({
  clearScreen: false,
  server: {
    host: "127.0.0.1", // 显式 IPv4：Node 把 localhost 解析成 ::1 时只绑 IPv6，Tauri/浏览器连 127.0.0.1 会失败
    port: 1420,
    strictPort: true,
    watch: {
      // Rust 构建目录：文件锁（EBUSY）+ 海量无关变更，前端 HMR 不需要盯它
      ignored: ["**/src-tauri/**"],
    },
  },
  build: {
    target: "es2021",
    outDir: "dist",
  },
});
