// 分析网关流 203.0.113.10:443 的包间隔与尺寸时序
const fs = require("fs");
const buf = fs.readFileSync(process.argv[2] || "C:/Users/84195/mpcap.pcapng");

let off = 0;
const evts = []; // {ts, dir, size}
const GATEWAY = "203.0.113.10";

while (off + 12 <= buf.length) {
  const blockType = buf.readUInt32LE(off);
  const blockLen = buf.readUInt32LE(off + 4);
  if (blockLen < 12 || off + blockLen > buf.length) break;
  if (blockType === 0x00000006) {
    const tsHigh = buf.readUInt32LE(off + 12);
    const tsLow = buf.readUInt32LE(off + 16);
    const capLen = buf.readUInt32LE(off + 20);
    const pkt = buf.slice(off + 28, off + 28 + capLen);
    if (pkt.length > 34) {
      let ethType = pkt.readUInt16BE(12), ipOff = 14;
      if (ethType !== 0x0800 && (pkt[0] >> 4) === 4) ipOff = 0;
      if (ethType === 0x0800 || ipOff === 0) {
        const ip = pkt.slice(ipOff);
        if (ip.length > 20 && (ip[0] >> 4) === 4 && ip[9] === 6) {
          const src = `${ip[12]}.${ip[13]}.${ip[14]}.${ip[15]}`;
          const dst = `${ip[16]}.${ip[17]}.${ip[18]}.${ip[19]}`;
          if (src === GATEWAY || dst === GATEWAY) {
            const ihl = (ip[0] & 0xf) * 4;
            const l4 = ip.slice(ihl);
            const sport = l4.readUInt16BE(0), dport = l4.readUInt16BE(2);
            if (dport === 443 || sport === 443) {
              const dataOff = (l4[12] >> 4) * 4;
              const payloadLen = ip.readUInt16BE(2) - ihl - dataOff;
              const flags = l4[13];
              evts.push({
                ts: tsHigh * 2 ** 32 + tsLow,
                dir: sport === 443 ? "S->C" : "C->S",
                size: payloadLen,
                flags: flags & 0x1f,
                seqAck: (flags & 0x10) ? "ACK" : "",
              });
            }
          }
        }
      }
    }
  }
  off += blockLen;
}

evts.sort((a, b) => a.ts - b.ts);
// pktmon 在多个网络组件重复捕获，按 ts+dir+size+flags 去重
{ const seen = new Set(); const uniq = [];
  for (const e of evts) { const k = `${e.ts}|${e.dir}|${e.size}|${e.flags}`; if (!seen.has(k)) { seen.add(k); uniq.push(e); } }
  evts.length = 0; evts.push(...uniq); }
console.log(`去重后: ${evts.length}`);
console.log(`网关流事件总数: ${evts.length}\n`);

// 按方向×尺寸 分组统计间隔
const groups = new Map();
for (const e of evts) {
  const k = `${e.dir} size=${e.size}`;
  if (!groups.has(k)) groups.set(k, []);
  groups.get(k).push(e);
}
for (const [k, arr] of groups) {
  if (arr.length < 3) continue;
  const gaps = [];
  for (let i = 1; i < arr.length; i++) gaps.push(arr[i].ts - arr[i - 1].ts);
  gaps.sort((a, b) => a - b);
  const median = gaps[Math.floor(gaps.length / 2)] / 1000;
  const p25 = gaps[Math.floor(gaps.length * 0.25)] / 1000;
  const p75 = gaps[Math.floor(gaps.length * 0.75)] / 1000;
  console.log(`${k}: n=${arr.length} 间隔中位=${median.toFixed(1)}ms p25=${p25.toFixed(1)}ms p75=${p75.toFixed(1)}ms`);
}

// 打印一段连续时序（2 秒）看 keepalive 模式
console.log("\n=== 时序样本（第 10-14 秒）===");
const t0 = evts[0].ts;
let printed = 0;
for (const e of evts) {
  const rel = (e.ts - t0) / 1e6;
  if (rel < 10) continue;
  if (rel > 14 || printed > 200) break;
  console.log(`${rel.toFixed(3)}s ${e.dir} size=${e.size} ${e.seqAck}${e.flags & 0x01 ? " FIN" : ""}${e.flags & 0x08 ? " PSH" : ""}`);
  printed++;
}
