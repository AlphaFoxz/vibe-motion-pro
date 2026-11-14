// 生成品牌图标（纯 Node，无依赖）：
// - app/src-tauri/icons/tray-{connected,connecting,disconnected}.png  托盘三态 32x32 RGBA
// - app/src-tauri/icons/icon.ico                                     应用/任务栏图标（32+16 BMP 条目）
// 设计：实心圆盘 + 白色对勾（connected）；琥珀色圆环带缺口（connecting）；灰色圆盘（disconnected）。
const fs = require("fs");
const path = require("path");
const zlib = require("zlib");

const OUT_DIR = path.join(__dirname, "..", "app", "src-tauri", "icons");

// ---------- PNG 编码 ----------
const CRC_TABLE = (() => {
  const t = new Uint32Array(256);
  for (let n = 0; n < 256; n++) {
    let c = n;
    for (let k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ (c >>> 1) : c >>> 1;
    t[n] = c >>> 0;
  }
  return t;
})();

function crc32(buf) {
  let c = 0xffffffff;
  for (let i = 0; i < buf.length; i++) c = CRC_TABLE[(c ^ buf[i]) & 0xff] ^ (c >>> 8);
  return (c ^ 0xffffffff) >>> 0;
}

function chunk(type, data) {
  const len = Buffer.alloc(4);
  len.writeUInt32BE(data.length, 0);
  const t = Buffer.from(type, "ascii");
  const crc = Buffer.alloc(4);
  crc.writeUInt32BE(crc32(Buffer.concat([t, data])), 0);
  return Buffer.concat([len, t, data, crc]);
}

function encodePNG(rgba, size) {
  const ihdr = Buffer.alloc(13);
  ihdr.writeUInt32BE(size, 0);
  ihdr.writeUInt32BE(size, 4);
  ihdr[8] = 8; // bit depth
  ihdr[9] = 6; // RGBA
  const stride = 1 + size * 4;
  const raw = Buffer.alloc(size * stride);
  for (let y = 0; y < size; y++) {
    raw[y * stride] = 0; // filter: none
    rgba.copy(raw, y * stride + 1, y * size * 4, (y + 1) * size * 4);
  }
  return Buffer.concat([
    Buffer.from([137, 80, 78, 71, 13, 10, 26, 10]),
    chunk("IHDR", ihdr),
    chunk("IDAT", zlib.deflateSync(raw, { level: 9 })),
    chunk("IEND", Buffer.alloc(0)),
  ]);
}

// ---------- 绘制 ----------
function distSeg(px, py, ax, ay, bx, by) {
  const vx = bx - ax, vy = by - ay;
  const wx = px - ax, wy = py - ay;
  const t = Math.max(0, Math.min(1, (wx * vx + wy * vy) / (vx * vx + vy * vy)));
  return Math.hypot(px - (ax + t * vx), py - (ay + t * vy));
}

const COLORS = {
  green: { fill: [34, 197, 94], border: [21, 128, 61] },    // #22c55e / #15803d
  amber: { fill: [245, 158, 11], border: [180, 83, 9] },    // #f59e0b / #b45309
  gray:  { fill: [156, 163, 175], border: [107, 114, 128] } // #9ca3af / #6b7280
};

/** 绘制 32x32 RGBA；kind: "disc"(带对勾) | "ring"(缺口圆环=进行中) */
function draw(size, kind, color) {
  const px = Buffer.alloc(size * size * 4);
  const c = (size - 1) / 2;
  const r = (size / 32) * 12.2, rBorder = (size / 32) * 13.8, rOuter = (size / 32) * 14.4;
  const { fill, border } = COLORS[color];
  for (let y = 0; y < size; y++) {
    for (let x = 0; x < size; x++) {
      const dx = x - c, dy = y - c;
      const d = Math.hypot(dx, dy);
      const i = (y * size + x) * 4;
      const scale = size / 32;
      let col = null;
      if (kind === "disc") {
        if (d <= r) col = d > r - 1.4 * scale ? border : fill;
      } else {
        // ring：留 70° 缺口（右上），暗示进行中
        if (d >= r * 0.76 && d <= rBorder) {
          const deg = (((Math.atan2(dy, dx) * 180) / Math.PI) + 360) % 360;
          if (deg > 75) col = d > rBorder - 1.4 * scale ? border : fill;
        }
      }
      if (col) {
        const aa = Math.max(0, Math.min(1, rOuter - d));
        px[i] = col[0]; px[i + 1] = col[1]; px[i + 2] = col[2];
        px[i + 3] = Math.round(255 * aa);
        // 白色对勾（仅实心盘）
        if (kind === "disc") {
          const inCheck =
            distSeg(x, y, 9.5 * scale, 16.8 * scale, 14 * scale, 21.2 * scale) < 2.1 * scale ||
            distSeg(x, y, 14 * scale, 21.2 * scale, 23 * scale, 11.5 * scale) < 2.1 * scale;
          if (inCheck) { px[i] = 255; px[i + 1] = 255; px[i + 2] = 255; }
        }
      }
    }
  }
  return px;
}

// ---------- ICO 编码（BMP 条目，32bpp + AND mask） ----------
function bmpEntry(px, size) {
  const bih = Buffer.alloc(40);
  bih.writeUInt32LE(40, 0);
  bih.writeInt32LE(size, 4);
  bih.writeInt32LE(size * 2, 8); // XOR + AND
  bih.writeUInt16LE(1, 12);
  bih.writeUInt16LE(32, 14);
  bih.writeUInt32LE(0, 16);
  bih.writeUInt32LE(size * size * 4, 20);

  // XOR：BGRA，自底向上
  const xor = Buffer.alloc(size * size * 4);
  for (let y = 0; y < size; y++) {
    const src = (size - 1 - y) * size * 4;
    for (let x = 0; x < size; x++) {
      const si = src + x * 4, di = (y * size + x) * 4;
      xor[di] = px[si + 2]; xor[di + 1] = px[si + 1]; xor[di + 2] = px[si]; xor[di + 3] = px[si + 3];
    }
  }
  const rowBytes = Math.ceil(size / 32) * 4;
  const mask = Buffer.alloc(rowBytes * size); // 全 0 = 全不透明（alpha 由 XOR 携带）
  return Buffer.concat([bih, xor, mask]);
}

function buildIco() {
  const entries = [
    { size: 32, px: draw(32, "disc", "green") },
    { size: 16, px: draw(16, "disc", "green") },
  ];
  const header = Buffer.alloc(6);
  header.writeUInt16LE(0, 0);
  header.writeUInt16LE(1, 2); // icon
  header.writeUInt16LE(entries.length, 4);
  const dirs = [];
  let offset = 6 + entries.length * 16;
  const images = [];
  for (const e of entries) {
    const img = bmpEntry(e.px, e.size);
    const dir = Buffer.alloc(16);
    dir[0] = e.size === 256 ? 0 : e.size;
    dir[1] = e.size === 256 ? 0 : e.size;
    dir[2] = 0; dir[3] = 0; // palette / reserved
    dir.writeUInt16LE(1, 4);  // planes
    dir.writeUInt16LE(32, 6); // bpp
    dir.writeUInt32LE(img.length, 8);
    dir.writeUInt32LE(offset, 12);
    offset += img.length;
    dirs.push(dir);
    images.push(img);
  }
  return Buffer.concat([header, ...dirs, ...images]);
}

// ---------- 输出 ----------
fs.mkdirSync(OUT_DIR, { recursive: true });
const outputs = [
  ["tray-connected.png", encodePNG(draw(32, "disc", "green"), 32)],
  ["tray-connecting.png", encodePNG(draw(32, "ring", "amber"), 32)],
  ["tray-disconnected.png", encodePNG(draw(32, "disc", "gray"), 32)],
];
for (const [name, buf] of outputs) {
  fs.writeFileSync(path.join(OUT_DIR, name), buf);
  console.log("written", name, buf.length, "bytes");
}
const ico = buildIco();
fs.writeFileSync(path.join(OUT_DIR, "icon.ico"), ico);
console.log("written icon.ico", ico.length, "bytes");
