//! mp-daemon: 特权守护进程（对应原版 vpnd + VPNService）。
//! - IPC server（127.0.0.1:62000，可用 MP_IPC_ADDR 覆盖）
//! - 1 秒状态轮询广播（对齐原版 vpnd detect_vni_status_thread）
//! - Profile 持久化（MP_PROFILES 路径，默认 <config>/profiles.toml）
//! - 日志：stdout（RUST_LOG 控制）+ 进程内环形缓冲（UI「日志」页按需读取，见 mp_ipc::log）

use mp_core::profile::ProfileStore;
use mp_daemon::{handle_client, poll_interval_secs, DaemonState, FREEZE_TICK};
use mp_ipc::log::LogRing;
use mp_ipc::transport::TcpServer;
use std::path::{Path, PathBuf};
use std::sync::Arc;
use std::time::Instant;
use tokio::sync::Mutex;
use tokio::time::{interval, Duration};

// ---------- managed 模式（--managed，随 UI sidecar 存亡） ----------

/// 父进程死亡后的退出宽限：防 UI 短暂重启（崩溃自愈）误杀 daemon。
const PARENT_GRACE: Duration = Duration::from_secs(3);

/// managed 下端口被占时的接管等待窗口：老 daemon（父进程已死、处退出宽限）
/// 释放端口通常 < 宽限 + 收尾耗时；窗口耗尽仍占用 → 已有健康实例在跑，让位退出。
/// （直接秒退会让「UI 崩溃后立刻重启」的竞态反复触发 UAC 重拉。）
const MANAGED_TAKEOVER_WAIT: Duration = Duration::from_secs(5);

/// managed bind 让位退出码。UI 侧语义：10 = 已有实例在跑，应去连接而非重拉。
const EXIT_MANAGED_PORT_BUSY: i32 = 10;

#[derive(Debug, Default, PartialEq)]
struct DaemonArgs {
    /// 受宿主管理：生命周期绑定父进程，bind 失败快速让位（见上）。
    managed: bool,
    /// 宿主进程 PID（Windows 必传；Unix 用 getppid 忽略此参数）。
    parent_pid: Option<u32>,
}

/// 手写解析（保持零新增依赖，musl 静态构建不受影响）。
/// 支持 `--managed`、`--parent-pid <PID>` 与 `--parent-pid=<PID>`。
fn parse_args<I: IntoIterator<Item = String>>(args: I) -> Result<DaemonArgs, String> {
    let mut out = DaemonArgs::default();
    let mut it = args.into_iter();
    while let Some(a) = it.next() {
        match a.as_str() {
            "--managed" => out.managed = true,
            "--parent-pid" => {
                let v = it.next().ok_or("--parent-pid 需要 <PID> 参数")?;
                out.parent_pid = Some(v.parse().map_err(|_| format!("非法 PID: {v}"))?);
            }
            other => {
                if let Some(v) = other.strip_prefix("--parent-pid=") {
                    out.parent_pid = Some(v.parse().map_err(|_| format!("非法 PID: {v}"))?);
                } else {
                    return Err(format!(
                        "未知参数: {other}（支持 --managed / --parent-pid <PID>）"
                    ));
                }
            }
        }
    }
    Ok(out)
}

/// 父进程死亡判定（纯函数便于单测）：managed 且持续死亡超过宽限 → true。
fn parent_expired(managed: bool, alive: bool, dead_since: Option<Instant>, now: Instant) -> bool {
    if !managed || alive {
        return false;
    }
    dead_since.is_some_and(|t| now.duration_since(t) >= PARENT_GRACE)
}

/// Windows：OpenProcess(QUERY_LIMITED_INFORMATION | SYNCHRONIZE) +
/// WaitForSingleObject(0)，句柄 signaled 即已终止。
/// SYNCHRONIZE 必须显式申请——没有它 WaitForSingleObject 恒返回 WAIT_FAILED，
/// 曾被误判为"存活"导致 daemon 永不退出（2026-11-17 真机实证）。
/// 局限：父进程死后 PID 被复用会误判存活——宽限期 + daemon 短生命周期下可接受。
#[cfg(windows)]
fn parent_alive(pid: u32) -> bool {
    use windows_sys::Win32::Foundation::{CloseHandle, WAIT_OBJECT_0};
    use windows_sys::Win32::System::Threading::{
        OpenProcess, WaitForSingleObject, PROCESS_QUERY_LIMITED_INFORMATION,
    };
    // windows-sys 0.52 未导出 SYNCHRONIZE（标准访问权），此处按 winnt.h 值定义
    const SYNCHRONIZE: u32 = 0x0010_0000;
    unsafe {
        let h = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION | SYNCHRONIZE, 0, pid);
        if h == 0 {
            return false;
        }
        let done = WaitForSingleObject(h, 0);
        CloseHandle(h);
        done != WAIT_OBJECT_0
    }
}

/// Unix：父进程死后子进程被 reparent 到 init/reaper，getppid() ≠ 启动时记录值。
#[cfg(unix)]
fn parent_alive(initial_ppid: u32) -> bool {
    std::os::unix::process::parent_id() == initial_ppid
}

/// 提权拉起 console 子系统二进制会弹 conhost 窗口；managed 模式尽早脱离（仍会闪现一瞬）。
#[cfg(windows)]
fn detach_console_if_managed(managed: bool) {
    if managed {
        use windows_sys::Win32::System::Console::FreeConsole;
        unsafe { FreeConsole() };
    }
}

#[tokio::main]
async fn main() -> anyhow::Result<()> {
    // 日志两个去向：stdout（RUST_LOG 控制）+ 进程内环形缓冲（UI「日志」页按需读取）。
    // 环形缓冲必须赶在任何 tracing 调用之前装好，才称得上「自启动以来」。
    let log_ring = Arc::new(LogRing::new());
    mp_ipc::log::init(log_ring.clone());

    let args = match parse_args(std::env::args().skip(1)) {
        Ok(a) => a,
        Err(e) => {
            eprintln!("mp-daemon: {e}");
            std::process::exit(2);
        }
    };
    #[cfg(windows)]
    detach_console_if_managed(args.managed);

    // 探活目标：Windows 用 UI 传入的 PID；Unix 启动即记 ppid（此时父进程必然在）
    #[cfg(windows)]
    let watch_pid: Option<u32> = args.parent_pid;
    #[cfg(unix)]
    let watch_pid: Option<u32> = Some(std::os::unix::process::parent_id());
    #[cfg(windows)]
    if args.managed && watch_pid.is_none() {
        eprintln!("mp-daemon: --managed 在 Windows 上需要 --parent-pid <PID>");
        std::process::exit(2);
    }
    if args.managed {
        tracing::info!(managed = true, watch_pid, "managed mode");
    }

    // 启动时同步算好本地时区偏移（严禁在异步路径里 spawn PowerShell）
    mp_core::tunnel::set_local_utc_offset(mp_core::tunnel::local_utc_offset_secs());

    // 冻结自检器：心跳 15 秒不前进 → cdb 抓栈（仅本地符号，20s 超时）+ 退出
    spawn_freeze_watchdog();

    let addr = std::env::var("MP_IPC_ADDR").unwrap_or_else(|_| "127.0.0.1:62000".into());
    // Profile 路径：MP_PROFILES 覆盖；默认三平台配置目录
    // （Windows %APPDATA% / macOS ~/Library/Application Support / Linux $XDG_CONFIG_HOME）。
    // 原来直取 APPDATA 在非 Windows 上是 unset，会静默落到当前目录。
    let profiles_path = std::env::var("MP_PROFILES").unwrap_or_else(|_| {
        dirs::config_dir()
            .unwrap_or_else(|| PathBuf::from("."))
            .join(mp_core::APP_ID)
            .join("profiles.toml")
            .display()
            .to_string()
    });
    let store = ProfileStore::load(Path::new(&profiles_path))?;
    tracing::info!("loaded {} profiles from {}", store.list().len(), profiles_path);

    // 状态跨任务共享：每条连接一个独立 task——持久 UI 连接不再饿死主循环 tick
    // （2026-11 真机踩坑：handle_conn 内联 await 时 ticker 分支 15s 不被轮询，
    //   冻结看门狗误判自杀）；连接内另有独立心跳分支，认证期间（锁被长时间持有）
    //   FREEZE_TICK 仍每秒前进，看门狗不会误杀。
    // Shutdown IPC 装配（plan-auto-update.md P1）：managed 标志决定请求是否
    // 受理；watch 信号由 handle_request 置位、主循环 select 感知后走 teardown
    let mut ds = DaemonState::new(store);
    ds.managed = args.managed;
    let (shutdown_tx, mut shutdown_rx) = tokio::sync::watch::channel(false);
    ds.shutdown_tx = Some(shutdown_tx);
    let state = Arc::new(Mutex::new(ds));
    let server = {
        // 绑定失败重试而非立即退出：本机其他服务偶发抢占端口（如开发工具的
        // live-daemon 抢过 62000），重试窗口内常可恢复；耗尽后带指引退出。
        // managed 模式例外：短暂接管等待后让位（见 MANAGED_TAKEOVER_WAIT 注释）。
        let mut attempts = 0u32;
        let managed_deadline = Instant::now() + MANAGED_TAKEOVER_WAIT;
        loop {
            match TcpServer::bind(&addr).await {
                Ok(s) => break s,
                Err(e) => {
                    if args.managed {
                        if Instant::now() < managed_deadline {
                            tracing::info!("managed: IPC {addr} 被占用，等待老实例退出后接管…");
                            tokio::time::sleep(Duration::from_millis(250)).await;
                            continue;
                        }
                        tracing::error!(
                            "managed: IPC bind {addr} 持续失败（已有健康实例在运行？），\
                             让位退出（code {EXIT_MANAGED_PORT_BUSY}）：{e}"
                        );
                        std::process::exit(EXIT_MANAGED_PORT_BUSY);
                    }
                    attempts += 1;
                    if attempts >= 10 {
                        anyhow::bail!(
                            "IPC bind {addr} 失败（重试 {attempts} 次）：{e}；\
                             端口被占用时可改用 MP_IPC_ADDR=127.0.0.1:<port>（UI 侧同样设置）"
                        );
                    }
                    tracing::warn!("ipc bind {addr} failed ({e}), retry {attempts}/10 in 1s");
                    tokio::time::sleep(Duration::from_secs(1)).await;
                }
            }
        }
    };
    tracing::info!("mp-daemon listening on {addr}");

    let mut last: Option<mp_ipc::status::StatusSnapshot> = None;
    let mut ticker = interval(Duration::from_secs(poll_interval_secs()));
    let mut parent_tick = interval(Duration::from_secs(1));
    let mut parent_dead_since: Option<Instant> = None;
    loop {
        tokio::select! {
            conn = server.accept() => {
                // accept 失败绝不退出进程（真机曾出现 logout 后静默退出）：
                // 记日志、退避后继续服务
                let conn = match conn {
                    Ok(c) => c,
                    Err(e) => {
                        tracing::error!("ipc accept failed: {e}");
                        tokio::time::sleep(Duration::from_millis(500)).await;
                        continue;
                    }
                };
                let st = state.clone();
                let logs = log_ring.clone();
                tokio::spawn(async move {
                    if let Err(e) = handle_client(st, logs, conn).await {
                        tracing::warn!("connection error: {e}");
                    }
                });
            }
            _ = ticker.tick() => {
                // 心跳先行且绝不等待状态锁：select handler 一旦 await 锁会挂起
                // 整个主循环任务，心跳就停了 —— 真实网关认证可轻松持锁 >15s，
                // 看门狗会误杀健康 daemon（2026-11-14 12:01 实证）。锁忙（认证中）
                // 则本 tick 跳过广播；连接响应本身会携带最新状态。
                FREEZE_TICK.fetch_add(1, std::sync::atomic::Ordering::Relaxed);
                if let Ok(mut st) = state.try_lock() {
                    if let Some(snap) = st.tick_broadcast(&mut last) {
                        tracing::debug!(state = snap.state, "status broadcast");
                    }
                }
            }
            _ = parent_tick.tick() => {
                // managed 父进程看护：探活不取状态锁（连接中认证可持锁 >15s，
                // 与 ticker 分支同样的纪律）。死亡超过宽限 → 优雅 teardown 后退出。
                let alive = if !args.managed {
                    true
                } else {
                    watch_pid.is_some_and(parent_alive)
                };
                if parent_expired(args.managed, alive, parent_dead_since, Instant::now()) {
                    tracing::info!(
                        "managed: 父进程已退出（宽限 {:?} 耗尽），teardown 后退出",
                        PARENT_GRACE
                    );
                    return managed_shutdown(state).await;
                }
                parent_dead_since = if alive {
                    None
                } else {
                    parent_dead_since.or_else(|| Some(Instant::now()))
                };
            }
            _ = shutdown_rx.changed() => {
                // Shutdown IPC（UI 更新安装前置）：与父进程死亡共用
                // managed_shutdown 的优雅退出路径（teardown 后进程退出，
                // 调用方据端口拒连确认「exe 已不被占用」）
                if *shutdown_rx.borrow() {
                    tracing::info!("shutdown: 收到 IPC 优雅退出请求，teardown 后退出");
                    return managed_shutdown(state).await;
                }
            }
        }
    }
}

/// managed 退出路径：尽力优雅 teardown（注销会话 → 网卡路由/DNS 回滚 → 泵停）。
/// 状态锁可能被在途 Connect 持有（最长 120s 总超时）：轮询 try_lock 等待，
/// 超时则放弃锁路径直接退出（网卡随进程关闭由内核回收，路由随之消失；
/// DNS revert 可能残留——与"daemon 被强杀"同一已知边界，记录于
/// docs/protocol-field-notes.md）。
async fn managed_shutdown(state: Arc<Mutex<DaemonState>>) -> anyhow::Result<()> {
    let deadline = Instant::now() + Duration::from_secs(125);
    loop {
        match state.try_lock() {
            Ok(mut st) => {
                st.logout_last_session_await().await;
                if let Some(mut tun) = st.active_tun.take() {
                    tun.teardown();
                }
                if let Some(pump) = st.active_tunnel.take() {
                    let _ = pump.shutdown().await;
                }
                tracing::info!("managed: teardown 完成，退出");
                return Ok(());
            }
            Err(_) if Instant::now() < deadline => {
                tokio::time::sleep(Duration::from_secs(1)).await;
            }
            Err(_) => {
                tracing::warn!("managed: 状态锁等待超时，放弃优雅 teardown 直接退出");
                std::process::exit(0);
            }
        }
    }
}

/// tokio 心跳计数器（watchdog 检测 runtime 冻结）——定义在 mp_daemon::FREEZE_TICK，
/// main 循环与各连接任务都会推进。

/// 冻结自检线程：独立 std 线程（不依赖 tokio）。15s 无心跳 →
/// 1) 用 cdb 抓全线程栈到 %TEMP%/com.alphafoxz.vibemotionpro/freeze_auto.txt
/// 2) std::process::exit(3)（外部 supervisor/用户重启）
fn spawn_freeze_watchdog() {
    std::thread::Builder::new()
        .name("freeze-watchdog".into())
        .spawn(move || {
            let mut last_tick = FREEZE_TICK.load(std::sync::atomic::Ordering::Relaxed);
            let mut last_change = std::time::Instant::now();
            loop {
                std::thread::sleep(std::time::Duration::from_secs(2));
                let t = FREEZE_TICK.load(std::sync::atomic::Ordering::Relaxed);
                if t != last_tick {
                    last_tick = t;
                    last_change = std::time::Instant::now();
                    continue;
                }
                if last_change.elapsed() >= std::time::Duration::from_secs(15) {
                    // 冻结！抓栈（仅本地符号 + 20s 超时，见 dump_all_thread_stacks）
                    // 后自杀
                    let dir = std::env::temp_dir().join(mp_core::APP_ID);
                    let _ = std::fs::create_dir_all(&dir);
                    dump_all_thread_stacks(&dir.join("freeze_auto.txt"));
                    let _ = std::fs::write(
                        dir.join("freeze_marker.txt"),
                        format!("frozen at {:?}", std::time::SystemTime::now()),
                    );
                    std::process::exit(3);
                }
            }
        })
        .expect("spawn freeze watchdog");
}

/// cdb 抓全线程栈（Windows 诊断用；无 cdb 则静默跳过，mac/Linux 直接走 exit）。
/// 路径全部可环境变量覆盖，默认值不再含开发机绝对路径：
/// - `MP_CDB`：cdb.exe 位置（默认 Windows Kits 附带路径）
/// - `MP_SYMBOLS`：符号目录（默认 exe 所在目录 —— 开发期 pdb 就在旁边）
/// 注意：cdb 只用本地符号（符号服务器下载会永久卡住并让目标线程保持挂起，
/// 真机踩坑），最多等 20s 防止卡死拖住 watchdog。
fn dump_all_thread_stacks(out_path: &std::path::Path) {
    let cdb = std::env::var("MP_CDB").unwrap_or_else(|_| {
        r"C:\Program Files (x86)\Windows Kits\10\Debuggers\x64\cdb.exe".to_string()
    });
    if !std::path::Path::new(&cdb).exists() {
        return;
    }
    let symbols = std::env::var("MP_SYMBOLS").unwrap_or_else(|_| {
        std::env::current_exe()
            .ok()
            .and_then(|p| p.parent().map(|d| d.display().to_string()))
            .unwrap_or_default()
    });
    if let Ok(mut child) = std::process::Command::new(&cdb)
        .arg("-p")
        .arg(std::process::id().to_string())
        .arg("-c")
        .arg("~* k 30; qd")
        .arg("-y")
        .arg(&symbols)
        .arg("-logo")
        .arg(out_path)
        .spawn()
    {
        let start = std::time::Instant::now();
        loop {
            if child.try_wait().ok().flatten().is_some() {
                break;
            }
            if start.elapsed() >= std::time::Duration::from_secs(20) {
                let _ = child.kill();
                break;
            }
            std::thread::sleep(std::time::Duration::from_millis(200));
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn args_default_empty() {
        assert_eq!(parse_args([] as [String; 0]).unwrap(), DaemonArgs::default());
    }

    #[test]
    fn args_managed_with_pid() {
        for argv in [
            vec!["--managed", "--parent-pid", "1234"],
            vec!["--parent-pid=1234", "--managed"],
        ] {
            let args = parse_args(argv.into_iter().map(String::from)).unwrap();
            assert_eq!(
                args,
                DaemonArgs { managed: true, parent_pid: Some(1234) }
            );
        }
    }

    #[test]
    fn args_missing_pid_value_is_error() {
        assert!(parse_args(["--parent-pid".into()].into_iter()).is_err());
    }

    #[test]
    fn args_bad_pid_is_error() {
        assert!(parse_args(["--parent-pid", "abc"].into_iter().map(String::from)).is_err());
        assert!(parse_args(["--parent-pid=abc"].into_iter().map(String::from)).is_err());
    }

    #[test]
    fn args_unknown_is_error() {
        assert!(parse_args(["--frobnicate".into()].into_iter()).is_err());
    }

    #[test]
    fn parent_expired_requires_managed() {
        let now = Instant::now();
        let dead_long_ago = now.checked_sub(Duration::from_secs(60)).unwrap();
        // 非 managed：永不退出（手动/开发模式行为不变）
        assert!(!parent_expired(false, false, Some(dead_long_ago), now));
    }

    #[test]
    fn parent_expired_requires_dead_beyond_grace() {
        let now = Instant::now();
        let just_died = now.checked_sub(Duration::from_secs(1)).unwrap();
        let long_dead = now.checked_sub(PARENT_GRACE + Duration::from_secs(1)).unwrap();
        // 存活 / 首次死亡（尚未记录） → 不退出
        assert!(!parent_expired(true, true, Some(long_dead), now));
        assert!(!parent_expired(true, false, None, now));
        // 死亡未过宽限 → 不退出；超过宽限 → 退出
        assert!(!parent_expired(true, false, Some(just_died), now));
        assert!(parent_expired(true, false, Some(long_dead), now));
    }
}
