import { defineConfig } from "vite";

// Tauri 期望固定的前端端口与产物目录
export default defineConfig({
  clearScreen: false,
  server: {
    port: 1420,
    strictPort: true,
  },
  build: {
    target: "es2021",
    outDir: "dist",
  },
});
