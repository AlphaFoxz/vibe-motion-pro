//! 数据面：虚拟网卡 <-> smoltcp 用户态 TCP/IP 栈（对齐原版 vl3vpn.dll 的 lwIP 方案）。
//!
//! 设计：
//! - `Adapter` trait 抽象网卡读写（生产实现见 mp-platform；测试用 MockAdapter）
//! - `Dataplane` 持有 smoltcp Interface + SocketSet，把适配器字节流灌入栈，
//!   并维护 TCP 会话表（对内监听、对外拨号由上层会话管理器驱动）
//!
//! TODO(逆向): 原版 vl3vpn 的会话分流/NAT 细节（隧道内 IP 分配、TAF 规则）确认后完善。

use smoltcp::iface::{Config, Interface, SocketSet};
use smoltcp::phy::{Device, DeviceCapabilities, RxToken, TxToken, Medium};
use smoltcp::time::Instant as SmolInstant;
use smoltcp::wire::{HardwareAddress, IpAddress, IpCidr, Ipv4Address};
use std::collections::VecDeque;
use std::vec::Vec;
use thiserror::Error;

#[derive(Debug, Error)]
pub enum DataplaneError {
    #[error("adapter rx empty")]
    RxEmpty,
    #[error("smoltcp error: {0}")]
    Smol(String),
}

/// 虚拟网卡抽象（字节级读写，非阻塞语义由实现方决定）。
pub trait Adapter {
    /// 读取一个来自隧道/内核的 IP 包；无数据返回 None。
    fn read(&mut self) -> Option<Vec<u8>>;
    /// 向隧道/内核写一个 IP 包。
    fn write(&mut self, packet: &[u8]);
}

/// 测试/骨架用假适配器：内存队列。
#[derive(Default)]
pub struct MockAdapter {
    pub rx: VecDeque<Vec<u8>>,
    pub tx: VecDeque<Vec<u8>>,
}

impl MockAdapter {
    pub fn new() -> Self {
        Self::default()
    }
    pub fn push_rx(&mut self, packet: Vec<u8>) {
        self.rx.push_back(packet);
    }
    pub fn pop_tx(&mut self) -> Option<Vec<u8>> {
        self.tx.pop_front()
    }
}

impl Adapter for MockAdapter {
    fn read(&mut self) -> Option<Vec<u8>> {
        self.rx.pop_front()
    }
    fn write(&mut self, packet: &[u8]) {
        self.tx.push_back(packet.to_vec());
    }
}

/// 把 Adapter 包装成 smoltcp Device。
struct AdapterDevice<'a> {
    adapter: &'a mut dyn Adapter,
    tx_queue: VecDeque<Vec<u8>>,
}

impl<'a> AdapterDevice<'a> {
    fn new(adapter: &'a mut dyn Adapter) -> Self {
        Self { adapter, tx_queue: VecDeque::new() }
    }
}

struct AdapterRxToken<'a> {
    buf: Vec<u8>,
    _marker: std::marker::PhantomData<&'a ()>,
}

impl RxToken for AdapterRxToken<'_> {
    fn consume<R, F>(self, f: F) -> R
    where
        F: FnOnce(&mut [u8]) -> R,
    {
        let mut buf = self.buf;
        f(&mut buf)
    }
}

pub struct AdapterTxToken<'a> {
    queue: &'a mut VecDeque<Vec<u8>>,
}

impl TxToken for AdapterTxToken<'_> {
    fn consume<R, F>(self, len: usize, f: F) -> R
    where
        F: FnOnce(&mut [u8]) -> R,
    {
        let mut buf = vec![0u8; len];
        let r = f(&mut buf);
        self.queue.push_back(buf);
        r
    }
}

impl Device for AdapterDevice<'_> {
    type RxToken<'a> = AdapterRxToken<'a> where Self: 'a;
    type TxToken<'a> = AdapterTxToken<'a> where Self: 'a;

    fn receive(&mut self, _t: SmolInstant) -> Option<(Self::RxToken<'_>, Self::TxToken<'_>)> {
        let buf = self.adapter.read()?;
        Some((
            AdapterRxToken { buf, _marker: std::marker::PhantomData },
            AdapterTxToken { queue: &mut self.tx_queue },
        ))
    }

    fn transmit(&mut self, _t: SmolInstant) -> Option<Self::TxToken<'_>> {
        Some(AdapterTxToken { queue: &mut self.tx_queue })
    }

    fn capabilities(&self) -> DeviceCapabilities {
        let mut c = DeviceCapabilities::default();
        c.medium = Medium::Ip;
        c.max_transmission_unit = 1400;
        c.max_burst_size = None;
        c
    }
}

/// 用户态 TCP/IP 栈封装。
pub struct Dataplane {
    iface: Interface,
    sockets: SocketSet<'static>,
    device_tx_out: VecDeque<Vec<u8>>,
    // device 每次调用期间临时借用 adapter，这里持有方式见 poll_with
}

impl Dataplane {
    /// veth_ip: 隧道内客户端虚拟 IP；prefix: 掩码前缀。
    pub fn new(veth_ip: [u8; 4], prefix: u8) -> Self {
        let mut iface = Interface::new(
            Config::new(HardwareAddress::Ip),
            &mut DeviceStub,
            SmolInstant::from_millis(0),
        );
        iface.update_ip_addrs(|addrs| {
            let _ = addrs.push(IpCidr::new(IpAddress::Ipv4(Ipv4Address(veth_ip)), prefix));
        });
        // TODO(逆向): 路由规则对应 ArraySetMTUAndTunnelRule / split tunnel 域名表
        Self { iface, sockets: SocketSet::new(Vec::new()), device_tx_out: VecDeque::new() }
    }

    pub fn socket_count(&self) -> usize {
        self.sockets.iter().count()
    }

    /// 用一个假 device 推进栈（骨架验证；真实接入在 mp-platform 联调）。
    pub fn poll_once(&mut self) -> usize {
        // DeviceStub 无包可读；发送队列通过 stub 间接验证。此方法保留给联调用。
        0
    }
}

/// 无 IO 的 device stub，仅供 Interface::new 初始化。
struct DeviceStub;
impl Device for DeviceStub {
    type RxToken<'a> = AdapterRxToken<'a> where Self: 'a;
    type TxToken<'a> = AdapterTxToken<'a> where Self: 'a;
    fn receive(&mut self, _t: SmolInstant) -> Option<(Self::RxToken<'_>, Self::TxToken<'_>)> {
        None
    }
    fn transmit(&mut self, _t: SmolInstant) -> Option<Self::TxToken<'_>> {
        None
    }
    fn capabilities(&self) -> DeviceCapabilities {
        let mut c = DeviceCapabilities::default();
        c.medium = Medium::Ip;
        c.max_transmission_unit = 1400;
        c.max_burst_size = None;
        c
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn mock_adapter_queues() {
        let mut a = MockAdapter::new();
        assert!(a.read().is_none());
        a.push_rx(vec![1, 2, 3]);
        assert_eq!(a.read().unwrap(), vec![1, 2, 3]);
        a.write(&[9]);
        assert_eq!(a.pop_tx().unwrap(), vec![9]);
        assert!(a.pop_tx().is_none());
    }

    #[test]
    fn dataplane_init_with_veth_ip() {
        let mut dp = Dataplane::new([10, 8, 0, 2], 24);
        assert_eq!(dp.socket_count(), 0);
        assert_eq!(dp.poll_once(), 0);
    }
}
