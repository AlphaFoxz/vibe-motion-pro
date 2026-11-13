use thiserror::Error;

#[derive(Debug, Error)]
pub enum Error {
    #[error("tls error: {0}")]
    Tls(#[from] rustls::Error),
    #[error("io error: {0}")]
    Io(#[from] std::io::Error),
    #[error("protocol error: {0}")]
    Protocol(String),
    #[error("session expired or kicked")]
    SessionInvalid,
}
