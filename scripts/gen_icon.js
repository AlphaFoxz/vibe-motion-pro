// 生成占位 icon.ico（32x32 32bpp 全色块）
const fs = require("fs");

const w = 32, h = 32, bpp = 32;
const bih = Buffer.alloc(40);
bih.writeUInt32LE(40, 0);        // biSize
bih.writeInt32LE(w, 4);          // biWidth
bih.writeInt32LE(h * 2, 8);      // biHeight (XOR+AND)
bih.writeUInt16LE(1, 12);        // biPlanes
bih.writeUInt16LE(bpp, 14);      // biBitCount
bih.writeUInt32LE(0, 16);        // biCompression
bih.writeUInt32LE((w * h * bpp) / 8, 20);
bih.writeUInt32LE(0, 28);
bih.writeUInt32LE(0, 32);

const px = Buffer.alloc(w * h * 4);
for (let i = 0; i < w * h; i++) {
  px[i * 4 + 0] = 255; // B
  px[i * 4 + 1] = 80;  // G
  px[i * 4 + 2] = 30;  // R
  px[i * 4 + 3] = 255; // A
}
const rowBytes = Math.ceil(w / 32) * 4;
const mask = Buffer.alloc(rowBytes * h);

const img = Buffer.concat([bih, px, mask]);
const header = Buffer.alloc(22);
header.writeUInt16LE(0, 0);      // reserved
header.writeUInt16LE(1, 2);      // type: icon
header.writeUInt16LE(1, 4);      // count
header[6] = w; header[7] = h;    // width/height
header.writeUInt16LE(1, 10);     // planes
header.writeUInt16LE(bpp, 12);   // bpp
header.writeUInt32LE(img.length, 14);
header.writeUInt32LE(22, 18);    // offset

const out = Buffer.concat([header, img]);
fs.writeFileSync("app/src-tauri/icons/icon.ico", out);
console.log("ico written", out.length);
