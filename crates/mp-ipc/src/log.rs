//! 进程内日志环形缓冲：tracing Layer → 有界内存历史 → 按游标增量读取。
//!
//! 用途：UI「日志」页展示守护进程 / UI 进程自启动以来的日志。整个功能是
//! **惰性**的——没人看日志时不落盘、不推送、无后台任务、无定时器；恒定成本
//! 只有每条（默认 INFO 及以上）日志一次格式化 + 入队。「自启动以来」的历史
//! 无法事后补录，这是提供它的最小代价。
//!
//! 读取模型：每行有从 1 起单调递增的 `seq`。读取方把上次的
//! [`LogBatch::next`] 作为 `from` 调 [`LogRing::tail`]，取回 `seq >= from` 的行，
//! 无重复、无遗漏。`epoch`（进程启动时刻）不符说明进程重启过、`seq` 已重新
//! 计数，此时从头给。容量见 [`MAX_LINES`] / [`MAX_BYTES`]，超限 FIFO 淘汰。

use std::collections::VecDeque;
use std::fmt::Write as _;
use std::sync::{Arc, Mutex, PoisonError};
use std::time::{SystemTime, UNIX_EPOCH};

use serde::{Deserialize, Serialize};
use tracing::field::{Field, Visit};
use tracing_subscriber::layer::SubscriberExt;
use tracing_subscriber::util::SubscriberInitExt;
use tracing_subscriber::{EnvFilter, Layer};

/// 环形缓冲最多保留的行数（与 [`MAX_BYTES`] 先到为准）。
pub const MAX_LINES: usize = 2000;
/// 环形缓冲最多保留的消息字节数。
pub const MAX_BYTES: usize = 256 * 1024;
/// 单行消息上限：一条异常日志（如大段 dump）不能挤空整个缓冲。
const MAX_LINE: usize = 8 * 1024;

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Serialize, Deserialize)]
#[serde(rename_all = "UPPERCASE")]
pub enum Level {
    Error,
    Warn,
    Info,
    Debug,
    Trace,
}

impl From<tracing::Level> for Level {
    fn from(l: tracing::Level) -> Self {
        match l {
            tracing::Level::ERROR => Level::Error,
            tracing::Level::WARN => Level::Warn,
            tracing::Level::INFO => Level::Info,
            tracing::Level::DEBUG => Level::Debug,
            tracing::Level::TRACE => Level::Trace,
        }
    }
}

/// 环形缓冲的一行（线格式，经 IPC 原样送给 UI）。
#[derive(Debug, Clone, PartialEq, Serialize, Deserialize)]
pub struct LogLine {
    /// 进程内单调递增，从 1 起
    pub seq: u64,
    /// Unix 时间，毫秒
    pub ts: u64,
    pub level: Level,
    /// tracing target（记录日志的模块路径，如 `mp_daemon`）
    pub target: String,
    /// `message k=v k=v`
    pub msg: String,
}

/// 一次增量读取的结果。
#[derive(Debug, Clone, PartialEq, Serialize, Deserialize)]
pub struct LogBatch {
    /// 日志纪元 = 进程启动时刻（Unix 毫秒）。与上次不同即进程重启过：
    /// `seq` 已从头计数，`lines` 是新进程的全部保留行。
    pub epoch: u64,
    /// 游标：下一条日志的 `seq`。读取方下次把它作为 `from` 回传。
    pub next: u64,
    /// 因容量淘汰的行数。它 ≥ 请求的 `from` 时，中间的行已取不到。
    pub dropped: u64,
    /// `seq >= from` 的保留行，按 `seq` 升序
    pub lines: Vec<LogLine>,
}

struct Entry {
    seq: u64,
    ts: u64,
    level: Level,
    target: &'static str,
    msg: String,
}

struct Inner {
    lines: VecDeque<Entry>,
    /// 保留行的消息字节合计
    bytes: usize,
    /// 下一条日志的 seq（从 1 起；0 留给「从头取」的游标）
    next: u64,
    /// 已淘汰行数 + 1 = 最旧保留行的 seq = 新读者应使用的 `from`
    dropped: u64,
}

impl Inner {
    fn new() -> Self {
        Self { lines: VecDeque::new(), bytes: 0, next: 1, dropped: 0 }
    }
}

/// 有界日志历史。写入只需一次加锁 + 一次格式化，读取 [`LogRing::tail`] 克隆出
/// 线格式行；两者互不阻塞守护进程的状态锁。
pub struct LogRing {
    epoch: u64,
    max_lines: usize,
    max_bytes: usize,
    inner: Mutex<Inner>,
}

impl Default for LogRing {
    fn default() -> Self {
        Self::new()
    }
}

impl LogRing {
    /// 默认容量（[`MAX_LINES`] / [`MAX_BYTES`]）。
    pub fn new() -> Self {
        Self::with_caps(MAX_LINES, MAX_BYTES)
    }

    /// 自定义容量（测试用）。
    pub fn with_caps(max_lines: usize, max_bytes: usize) -> Self {
        Self {
            epoch: now_ms(),
            max_lines,
            max_bytes,
            inner: Mutex::new(Inner::new()),
        }
    }

    /// 日志纪元：进程启动时刻（Unix 毫秒）。
    pub fn epoch(&self) -> u64 {
        self.epoch
    }

    /// 追加一行（由 [`LogLayer`] 调用）。
    pub fn push(&self, level: Level, target: &'static str, msg: String) {
        let msg = truncate_line(msg);
        let mut g = self.lock();
        let seq = g.next;
        g.next += 1;
        g.bytes += msg.len();
        g.lines.push_back(Entry { seq, ts: now_ms(), level, target, msg });
        while g.lines.len() > self.max_lines || g.bytes > self.max_bytes {
            let Some(old) = g.lines.pop_front() else { break };
            g.bytes -= old.msg.len();
            g.dropped += 1;
        }
    }

    /// 取出 `seq >= from` 的全部保留行。`epoch` 与本进程不符、或 `from` 超前
    /// （不可能出现的游标）时视为新读者，从头给。
    pub fn tail(&self, epoch: u64, from: u64) -> LogBatch {
        let g = self.lock();
        let from = if epoch != self.epoch || from > g.next { 0 } else { from };
        LogBatch {
            epoch: self.epoch,
            next: g.next,
            dropped: g.dropped,
            lines: g
                .lines
                .iter()
                .filter(|e| e.seq >= from)
                .map(|e| LogLine {
                    seq: e.seq,
                    ts: e.ts,
                    level: e.level,
                    target: e.target.to_string(),
                    msg: e.msg.clone(),
                })
                .collect(),
        }
    }

    fn lock(&self) -> std::sync::MutexGuard<'_, Inner> {
        // 锁中毒不向上冒泡：在日志路径上 panic 会把一次普通错误放大成进程
        // 故障；缓冲内容不依赖跨字段不变量，中毒后照常可用。
        self.inner.lock().unwrap_or_else(PoisonError::into_inner)
    }
}

fn now_ms() -> u64 {
    SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .map(|d| d.as_millis() as u64)
        .unwrap_or(0)
}

fn truncate_line(mut msg: String) -> String {
    if msg.len() <= MAX_LINE {
        return msg;
    }
    let mut cut = MAX_LINE;
    while !msg.is_char_boundary(cut) {
        cut -= 1;
    }
    msg.truncate(cut);
    msg.push('…');
    msg
}

// ---------- tracing 接入 ----------

/// 把事件写进环形缓冲的 Layer。只实现 `on_event`：span 进出不记录。
pub struct LogLayer {
    ring: Arc<LogRing>,
}

impl LogLayer {
    pub fn new(ring: Arc<LogRing>) -> Self {
        Self { ring }
    }
}

impl<S: tracing::Subscriber> Layer<S> for LogLayer {
    fn on_event(&self, event: &tracing::Event<'_>, _ctx: tracing_subscriber::layer::Context<'_, S>) {
        let meta = event.metadata();
        let mut visitor = LineVisitor::default();
        event.record(&mut visitor);
        self.ring.push(Level::from(*meta.level()), meta.target(), visitor.finish());
    }
}

/// 把事件字段拼成一行：`message k=v k=v`，message 恒在最前。
///
/// 字段按书写顺序访问，而本仓库习惯 `info!(managed = true, "managed mode")`
/// （message 在后），所以 message 与其余字段分开攒，最后再拼。
#[derive(Default)]
struct LineVisitor {
    msg: String,
    fields: String,
}

impl Visit for LineVisitor {
    fn record_debug(&mut self, field: &Field, value: &dyn std::fmt::Debug) {
        // tracing 以 Debug 形式送达 message（fmt::Arguments / DisplayValue 的
        // Debug 即 Display），与 tracing-subscriber 的 DefaultVisitor 一致。
        if field.name() == "message" {
            let _ = write!(self.msg, "{:?}", value);
        } else {
            let _ = write!(self.fields, "{}={:?} ", field, value);
        }
    }

    fn record_str(&mut self, field: &Field, value: &str) {
        if field.name() == "message" {
            self.msg.push_str(value);
        } else {
            let _ = write!(self.fields, "{}={} ", field, value);
        }
    }
}

impl LineVisitor {
    fn finish(self) -> String {
        let fields = self.fields.trim_end();
        if fields.is_empty() {
            return self.msg;
        }
        let mut line = self.msg;
        if !line.is_empty() {
            line.push(' ');
        }
        line.push_str(fields);
        line
    }
}

/// 安装全局 subscriber：stdout 层 + 环形缓冲层（[`init`] 的可测内核）。
fn subscriber(
    ring: Arc<LogRing>,
    stdout: EnvFilter,
    buffered: EnvFilter,
) -> impl tracing::Subscriber + Send + Sync + 'static {
    tracing_subscriber::registry()
        .with(tracing_subscriber::fmt::layer().with_filter(stdout))
        .with(LogLayer::new(ring).with_filter(buffered))
}

/// 安装全局 tracing：stdout（行为与引入本模块前一致）+ 环形缓冲（供日志页读取）。
///
/// 必须在任何 `tracing` 调用之前执行，才称得上「自启动以来」。
///
/// 过滤规则：
/// - stdout 层沿用 `RUST_LOG`（未设置时 `EnvFilter` 默认只放行 ERROR）。
/// - 环形缓冲层在显式设置 `RUST_LOG` 时与之同级；否则默认 INFO——Windows
///   sidecar 没有可看的 stdout，若同样只留 ERROR，日志页将无内容可读。
pub fn init(ring: Arc<LogRing>) {
    let buffered = match std::env::var_os("RUST_LOG") {
        Some(_) => EnvFilter::from_default_env(),
        None => EnvFilter::new("info"),
    };
    subscriber(ring, EnvFilter::from_default_env(), buffered).init();
}

#[cfg(test)]
mod tests {
    use super::*;

    fn push(ring: &LogRing, msg: &str) {
        ring.push(Level::Info, "test", msg.into());
    }

    #[test]
    fn tail_starts_from_beginning_and_is_incremental() {
        let ring = LogRing::new();
        push(&ring, "one");
        push(&ring, "two");

        let first = ring.tail(ring.epoch(), 0);
        assert_eq!(first.lines.iter().map(|l| l.msg.as_str()).collect::<Vec<_>>(), ["one", "two"]);
        assert_eq!((first.epoch, first.next, first.dropped), (ring.epoch(), 3, 0));
        assert_eq!(first.lines[0].seq, 1, "seq 从 1 起");

        push(&ring, "three");
        let next = ring.tail(first.epoch, first.next);
        assert_eq!(next.lines.iter().map(|l| l.msg.as_str()).collect::<Vec<_>>(), ["three"]);
        assert_eq!(next.next, 4);
        assert!(ring.tail(next.epoch, next.next).lines.is_empty(), "追平后为空");
    }

    #[test]
    fn stale_cursor_reports_evicted_lines() {
        let ring = LogRing::with_caps(2, usize::MAX);
        for i in 0..5 {
            push(&ring, &format!("line {i}"));
        }
        let batch = ring.tail(ring.epoch(), 0);
        assert_eq!(batch.lines.iter().map(|l| l.msg.as_str()).collect::<Vec<_>>(), ["line 3", "line 4"]);
        assert_eq!(batch.dropped, 3, "最早可取的行 = dropped + 1");

        // 读者还停在第 1 行（from = 1）：第 1..=3 行已淘汰，只能拿到现存的全部；
        // 读取方据 dropped ≥ from 算出漏掉的行数（这里是 3 行）。
        let batch = ring.tail(ring.epoch(), 1);
        assert_eq!(batch.lines.iter().map(|l| l.seq).collect::<Vec<_>>(), [4, 5]);
        assert_eq!(batch.dropped - 1 + 1, 3);
    }

    #[test]
    fn byte_cap_evicts_even_when_line_count_is_small() {
        let ring = LogRing::with_caps(usize::MAX, 12);
        push(&ring, "0123456789"); // 10B
        push(&ring, "abcdef"); // 超出 12B → 淘汰首行
        let batch = ring.tail(ring.epoch(), 0);
        assert_eq!(batch.lines.iter().map(|l| l.msg.as_str()).collect::<Vec<_>>(), ["abcdef"]);
        assert_eq!(batch.dropped, 1);
    }

    #[test]
    fn oversized_line_is_truncated_and_kept() {
        let ring = LogRing::with_caps(10, MAX_LINE * 2);
        push(&ring, &"x".repeat(MAX_LINE * 2));
        push(&ring, "after");
        let batch = ring.tail(ring.epoch(), 0);
        assert_eq!(batch.lines.len(), 2, "超长行截断保留，而不是被容量规则丢掉");
        assert!(batch.lines[0].msg.ends_with('…'));
        assert!(batch.lines[0].msg.len() <= MAX_LINE + '…'.len_utf8());
    }

    /// 截断不切断 UTF-8 字符（中文 3 字节/字）。
    #[test]
    fn truncation_respects_char_boundary() {
        let ring = LogRing::with_caps(10, MAX_LINE * 2);
        push(&ring, &"中".repeat(MAX_LINE));
        let line = ring.tail(ring.epoch(), 0).lines.remove(0);
        assert!(line.msg.chars().all(|c| c == '中' || c == '…'));
    }

    #[test]
    fn restart_or_future_cursor_restarts_from_beginning() {
        let ring = LogRing::new();
        push(&ring, "fresh");
        // 纪元不符：对端把上一次进程的游标发了过来
        let stale = ring.tail(ring.epoch() - 1, 900);
        assert_eq!(stale.epoch, ring.epoch());
        assert_eq!(stale.lines.len(), 1);
        // 纪元相符但游标超前（不可能出现）：同样按新读者处理，而不是返回空
        assert_eq!(ring.tail(ring.epoch(), 900).lines.len(), 1);
    }

    #[test]
    fn tail_output_is_wire_shaped() {
        let ring = LogRing::new();
        ring.push(Level::Warn, "mp_daemon", "ipc bind failed".into());
        let line = ring.tail(ring.epoch(), 0).lines.remove(0);
        assert_eq!(line.level, Level::Warn);
        assert_eq!(line.target, "mp_daemon");
        let json = serde_json::to_string(&line).unwrap();
        assert!(json.contains(r#""level":"WARN""#), "{json}");
        assert!(json.contains(r#""target":"mp_daemon""#), "{json}");
    }

    /// Layer 把事件按 `message k=v` 拼行，与字段书写顺序无关，级别映射正确。
    #[test]
    fn layer_formats_message_first_with_fields_after() {
        let ring = Arc::new(LogRing::new());
        let sub = tracing_subscriber::registry().with(LogLayer::new(ring.clone()));
        tracing::subscriber::with_default(sub, || {
            tracing::info!("plain {}", 7);
            tracing::warn!(attempts = 3, "retrying");
            tracing::error!(error = %std::io::Error::other("boom"), host = "vpn.example.com", "connect failed");
            tracing::debug!(port = 443);
        });

        let lines = ring.tail(ring.epoch(), 0).lines;
        let text: Vec<&str> = lines.iter().map(|l| l.msg.as_str()).collect();
        assert_eq!(
            text,
            [
                "plain 7",
                "retrying attempts=3",
                "connect failed error=boom host=vpn.example.com",
                "port=443",
            ]
        );
        let levels: Vec<Level> = lines.iter().map(|l| l.level).collect();
        assert_eq!(levels, [Level::Info, Level::Warn, Level::Error, Level::Debug]);
        assert!(lines.iter().all(|l| l.ts > 0), "带 Unix 毫秒时间戳");
        assert!(lines.iter().all(|l| l.target == "mp_ipc::log::tests"), "target 为记录处的模块路径");
    }

    /// 两层各带各的过滤器：stdout 只留 ERROR 时，INFO 仍进环形缓冲。
    #[test]
    fn buffered_layer_filters_independently_of_stdout_layer() {
        let ring = Arc::new(LogRing::new());
        let sub = subscriber(ring.clone(), EnvFilter::new("error"), EnvFilter::new("info"));
        tracing::subscriber::with_default(sub, || {
            tracing::info!("kept by ring, silent on stdout");
            tracing::debug!("below both");
            tracing::error!("everywhere");
        });
        let batch = ring.tail(ring.epoch(), 0);
        let text: Vec<&str> = batch.lines.iter().map(|l| l.msg.as_str()).collect();
        assert_eq!(text, ["kept by ring, silent on stdout", "everywhere"]);

        let quiet = Arc::new(LogRing::new());
        let sub = subscriber(quiet.clone(), EnvFilter::new("error"), EnvFilter::new("error"));
        tracing::subscriber::with_default(sub, || tracing::info!("dropped"));
        assert!(quiet.tail(quiet.epoch(), 0).lines.is_empty());
    }

    #[test]
    fn concurrent_writers_keep_seq_unique_and_dense() {
        let ring = Arc::new(LogRing::with_caps(10_000, usize::MAX));
        let threads: Vec<_> = (0..4)
            .map(|_| {
                let ring = ring.clone();
                std::thread::spawn(move || {
                    for _ in 0..500 {
                        push(&ring, "x");
                    }
                })
            })
            .collect();
        for t in threads {
            t.join().unwrap();
        }
        let batch = ring.tail(ring.epoch(), 0);
        assert_eq!(batch.lines.len(), 2000);
        let seqs: Vec<u64> = batch.lines.iter().map(|l| l.seq).collect();
        assert_eq!(seqs, (1..=2000).collect::<Vec<_>>(), "seq 连续且不重复");
    }
}
