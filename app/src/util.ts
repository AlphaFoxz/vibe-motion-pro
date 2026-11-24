// main.ts（连接/服务器视图）与 logs.ts（日志页）共用的小工具。

export const $ = (id: string) => document.getElementById(id)!;

/** 用位置参数替换模板里的 `{name}` 占位（参数按出现顺序消费）。 */
export function fmt(f: string, ...args: string[]): string {
  return f.replace(/\{(\w+)\}/g, (_m, _k) => args.shift() ?? _m);
}

/** HTML 文本转义：所有拼进 innerHTML 的动态字符串都必须先过这里。 */
export function esc(s: string): string {
  return s.replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;").replace(/"/g, "&quot;");
}
