//! Profile 管理：多服务器配置，TOML 持久化（对齐原版 [profiles] ini 的升级替代）。

use serde::{Deserialize, Serialize};
use std::collections::BTreeMap;
use std::path::{Path, PathBuf};
use thiserror::Error;

#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
pub struct Profile {
    pub id: String,
    pub name: String,
    pub host: String,
    #[serde(default = "default_port")]
    pub port: u16,
    /// 最后一次成功登录的用户名。非敏感，随 profile 持久化，UI 回填用
    /// （不落 WebView localStorage：WebKitGTK 退出时可能丢，Linux 安装版
    /// 实测用户名永不回填而 keyring 密码正常，2026-11）。
    #[serde(default)]
    pub username: String,
    #[serde(default)]
    pub tunnel_type: crate::session::TunnelType,
    #[serde(default)]
    pub autoconnect: bool,
}

fn default_port() -> u16 {
    crate::protocol::GATEWAY_PORT
}

impl Profile {
    pub fn new(id: impl Into<String>, name: impl Into<String>, host: impl Into<String>) -> Self {
        Self {
            id: id.into(),
            name: name.into(),
            host: host.into(),
            port: default_port(),
            username: String::new(),
            tunnel_type: crate::session::TunnelType::Tcp,
            autoconnect: false,
        }
    }
}

#[derive(Debug, Error)]
pub enum ProfileError {
    #[error("profile not found: {0}")]
    NotFound(String),
    #[error("duplicate profile id: {0}")]
    Duplicate(String),
    #[error("io error: {0}")]
    Io(#[from] std::io::Error),
    #[error("toml error: {0}")]
    Toml(String),
}

/// Profile 存储：内存 BTreeMap + 可选 TOML 文件持久化。
pub struct ProfileStore {
    profiles: BTreeMap<String, Profile>,
    path: Option<PathBuf>,
}

impl ProfileStore {
    pub fn new() -> Self {
        Self { profiles: BTreeMap::new(), path: None }
    }

    /// 从 TOML 文件加载；文件不存在视为空表。
    pub fn load(path: &Path) -> Result<Self, ProfileError> {
        let mut store = Self { profiles: BTreeMap::new(), path: Some(path.to_path_buf()) };
        match std::fs::read_to_string(path) {
            Ok(s) => {
                let data: toml::Value =
                    toml::from_str(&s).map_err(|e| ProfileError::Toml(e.to_string()))?;
                if let Some(items) = data.get("profile").and_then(|v| v.as_array()) {
                    for item in items {
                        let p: Profile = item
                            .clone()
                            .try_into()
                            .map_err(|e| ProfileError::Toml(format!("{e}")))?;
                        store.profiles.insert(p.id.clone(), p);
                    }
                }
            }
            Err(e) if e.kind() == std::io::ErrorKind::NotFound => {}
            Err(e) => return Err(e.into()),
        }
        Ok(store)
    }

    pub fn list(&self) -> Vec<&Profile> {
        self.profiles.values().collect()
    }

    pub fn get(&self, id: &str) -> Result<&Profile, ProfileError> {
        self.profiles.get(id).ok_or_else(|| ProfileError::NotFound(id.to_string()))
    }

    pub fn default_profile(&self) -> Option<&Profile> {
        self.profiles.values().find(|p| p.autoconnect).or_else(|| self.profiles.values().next())
    }

    pub fn add_or_update(&mut self, p: Profile) -> Result<(), ProfileError> {
        self.profiles.insert(p.id.clone(), p);
        self.save()
    }

    pub fn remove(&mut self, id: &str) -> Result<(), ProfileError> {
        if self.profiles.remove(id).is_none() {
            return Err(ProfileError::NotFound(id.to_string()));
        }
        self.save()
    }

    fn save(&self) -> Result<(), ProfileError> {
        let Some(path) = &self.path else { return Ok(()) };
        let mut s = format!("# {} profiles\n", crate::APP_NAME);
        for p in self.profiles.values() {
            let body = toml::to_string(p).map_err(|e| ProfileError::Toml(e.to_string()))?;
            s.push_str(&format!("\n[[profile]]\n{body}"));
        }
        if let Some(parent) = path.parent() {
            std::fs::create_dir_all(parent)?;
        }
        std::fs::write(path, s)?;
        Ok(())
    }
}

impl Default for ProfileStore {
    fn default() -> Self {
        Self::new()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn tmpdir() -> PathBuf {
        let d = std::env::temp_dir().join(format!("mp-test-{}", std::process::id()));
        let _ = std::fs::create_dir_all(&d);
        d
    }

    #[test]
    fn add_get_list() {
        let mut s = ProfileStore::new();
        s.add_or_update(Profile::new("p1", "Office", "vpn.example.com")).unwrap();
        s.add_or_update(Profile::new("p2", "Branch", "branch.example.com")).unwrap();
        assert_eq!(s.list().len(), 2);
        assert_eq!(s.get("p1").unwrap().host, "vpn.example.com");
        assert!(matches!(s.get("nope"), Err(ProfileError::NotFound(_))));
    }

    #[test]
    fn toml_roundtrip_and_defaults() {
        let dir = tmpdir();
        let path = dir.join("profiles.toml");
        let mut s = ProfileStore::load(&path).unwrap();
        assert_eq!(s.list().len(), 0); // 文件不存在 -> 空
        let mut p = Profile::new("p1", "Office", "vpn.example.com");
        p.autoconnect = true;
        p.username = "example_user".into();
        s.add_or_update(p).unwrap();

        let s2 = ProfileStore::load(&path).unwrap();
        assert_eq!(s2.list().len(), 1);
        let p2 = s2.get("p1").unwrap();
        assert_eq!(p2.port, 443); // 默认端口
        assert_eq!(p2.tunnel_type, crate::session::TunnelType::Tcp);
        assert_eq!(p2.username, "example_user"); // 用户名随 toml 往返
        assert!(s2.default_profile().unwrap().id == "p1"); // autoconnect 优先
        let _ = std::fs::remove_dir_all(&dir);
    }

    #[test]
    fn legacy_toml_without_username_loads() {
        // 旧版（username 入库前）写的 profiles.toml 不带该字段，serde default 兜底为空。
        // 独立文件名：tmpdir 按 pid 共享，避免与 toml_roundtrip 并行竞争。
        let dir = tmpdir();
        let path = dir.join("legacy-profiles.toml");
        std::fs::write(
            &path,
            "[[profile]]\nid = \"old\"\nname = \"Old\"\nhost = \"old.example.com\"\nport = 443\ntunnel_type = \"tcp\"\nautoconnect = false\n",
        )
        .unwrap();
        let s = ProfileStore::load(&path).unwrap();
        assert_eq!(s.get("old").unwrap().username, "");
        let _ = std::fs::remove_dir_all(&dir);
    }

    #[test]
    fn remove_and_default_fallback() {
        let mut s = ProfileStore::new();
        s.add_or_update(Profile::new("a", "A", "a.example.com")).unwrap();
        s.add_or_update(Profile::new("b", "B", "b.example.com")).unwrap();
        assert_eq!(s.default_profile().unwrap().id, "a"); // 无 autoconnect 时取第一个
        s.remove("a").unwrap();
        assert_eq!(s.default_profile().unwrap().id, "b");
        assert!(matches!(s.remove("a"), Err(ProfileError::NotFound(_))));
    }
}
