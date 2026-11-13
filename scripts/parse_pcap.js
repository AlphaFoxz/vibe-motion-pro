// pcapng 解析器：提取 UDP 65432 (vpnd IPC) 载荷 + TCP 443 流量统计
const fs = require("fs");
const buf = fs.readFileSync(process.argv[2] || "C:/Users/84195/mpcap.pcapng");

let off = 0;
const flows = new Map(); // key -> {count, sizes:[], times:[], payloads:[]}
let total = 0;

while (off + 12 <= buf.length) {
  const blockType = buf.readUInt32LE(off);
  const blockLen = buf.readUInt32LE(off + 4);
  if (blockLen < 12 || off + blockLen > buf.length) break;

  if (blockType === 0x00000006) {
    // EPB
    const ifaceId = buf.readUInt32LE(off + 8);
    const tsHigh = buf.readUInt32LE(off + 12);
    const tsLow = buf.readUInt32LE(off + 16);
    const capLen = buf.readUInt32LE(off + 20);
    const pkt = buf.slice(off + 28, off + 28 + capLen);
    const ts = (tsHigh * 2 ** 32 + tsLow); // us (if_ms Resolution default)
    parsePacket(pkt, ts);
    total++;
  }
  off += blockLen;
}

function parsePacket(pkt, ts) {
  if (pkt.length < 34) return;
  // 以太网帧（pktmon 输出通常带以太头；兼容 raw IP）
  let ethType = pkt.readUInt16BE(12);
  let ipOff = 14;
  if (ethType !== 0x0800) {
    if ((pkt[0] >> 4) === 4) { ipOff = 0; } else return;
  }
  const ip = pkt.slice(ipOff);
  if (ip.length < 20) return;
  if ((ip[0] >> 4) !== 4) return;
  const ihl = (ip[0] & 0xf) * 4;
  const proto = ip[9];
  const src = `${ip[12]}.${ip[13]}.${ip[14]}.${ip[15]}`;
  const dst = `${ip[16]}.${ip[17]}.${ip[18]}.${ip[19]}`;
  const l4 = ip.slice(ihl);
  if (l4.length < 4) return;
  const sport = l4.readUInt16BE(0), dport = l4.readUInt16BE(2);

  let key, payload;
  if (proto === 17) { // UDP
    payload = l4.slice(8, l4.readUInt16BE(4));
    key = `udp ${src}:${sport}->${dst}:${dport}`;
  } else if (proto === 6) { // TCP
    const dataOff = (l4[12] >> 4) * 4;
    payload = l4.slice(dataOff, l4.readUInt16BE(4));
    const flags = l4[13];
    key = `tcp ${src}:${sport}->${dst}:${dport}`;
    // 汇聚双向: 规范化
    if (sport > dport) key = `tcp ${dst}:${dport}<->${src}:${sport}`;
    else key = `tcp ${src}:${sport}<->${dst}:${dport}`;
    if (!(flags & 0x08) && !(flags & 0x02) && !(flags & 0x01) && payload.length === 0) return; // 纯ACK跳过统计? 保留计数
    var pureAck = payload.length === 0;
  } else return;

  let f = flows.get(key);
  if (!f) { f = { count: 0, dataPkts: 0, bytes: 0, sizes: [], first: ts, last: ts, payloads: [] }; flows.set(key, f); }
  f.count++;
  f.last = ts;
  if (proto === 6 && pureAck) return;
  f.dataPkts++;
  f.bytes += payload.length;
  if (proto === 17 && (dport === 65432 || sport === 65432) && payload.length) {
    if (f.payloads.length < 40) f.payloads.push({ ts, payload });
  }
  if (proto === 6 && (dport === 443 || sport === 443)) {
    f.sizes.push(payload.length);
  }
}

console.log(`总包数: ${total}, 流数: ${flows.size}\n`);
// TCP 443 统计
for (const [k, f] of flows) {
  if (!k.includes(":443") && !k.includes(".443")) continue;
  const dur = (f.last - f.first) / 1e6;
  const sizes = f.sizes;
  const freq = {};
  sizes.forEach(s => freq[s] = (freq[s] || 0) + 1);
  const top = Object.entries(freq).sort((a, b) => b[1] - a[1]).slice(0, 8);
  console.log(`${k}\n  数据包:${f.dataPkts} 字节:${f.bytes} 时长:${dur.toFixed(1)}s 尺寸分布(大小:次数): ${JSON.stringify(top)}`);
}

// UDP 65432 IPC 载荷
console.log(`\n=== UDP 65432 IPC 载荷样本 ===`);
for (const [k, f] of flows) {
  if (!k.includes("65432") || !f.payloads.length) continue;
  console.log(`\n[${k}] ${f.payloads.length} 个样本 (总 ${f.count} 包):`);
  for (const { ts, payload } of f.payloads.slice(0, 15)) {
    const hex = payload.toString("hex").slice(0, 120);
    const ascii = payload.toString("latin1").replace(/[^\x20-\x7e]/g, ".").slice(0, 80);
    console.log(`  ${hex}\n  |${ascii}|`);
  }
}
// 其它 UDP 小流
console.log(`\n=== 所有 UDP 流摘要 ===`);
for (const [k, f] of flows) {
  if (!k.startsWith("udp")) continue;
  console.log(`${k}  count=${f.count} bytes=${f.bytes}`);
}
