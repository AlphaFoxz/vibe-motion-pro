---
name: Git Squash
description: 把本地未推送（未 push）的零碎 commit 按主题合并成少量语义清晰的 commit。当用户要求整理/合并/压缩未推送的 commit、抱怨 commit 太多太碎时使用。
---

# Git Squash：合并未推送的 commit

把分支上尚未 push 的 commit 按主题合并成少量自洽的 commit，同时保证最终代码树与整理前**逐字节一致**。

## 流程

### 1. 摸底

```sh
git status -sb          # 必须干净；有未提交改动先停下来问用户
git log --oneline '@{u}..HEAD'
git branch -vv
```

- 若分支没有 upstream（`@{u}` 报错），改用与主分支的分叉点（如 `git merge-base master HEAD`）作为基线。
- 数一下领先多少个 commit；少于 5 个时先问用户是否值得整理。

### 2. 分组并确认策略

通读每个 commit 的 message，按主题归类（feat 基础设施、fix 系列、docs、test 修正等）。然后用提问工具让用户选择：

- **按主题合成 ~5 个**（推荐）：每个主题一个 commit，历史可读性最好。
- **全部压成 1 个**：整轮工作一个大 commit。
- **调试临时代码怎么处理**：纯诊断用的临时代码（dump 二进制到临时目录、探针脚本等）如果问题还没解决，保留；用户明确要求删除时才删。

把你的分组方案（每个组的 commit 范围 + 拟定的合并 message 要点）展示给用户后再动手。

### 3. 备份

整理前必须建备份分支（存在多个时递增编号）：

```sh
git branch backup/pre-squash-dev
```

### 4. 重放（树快照法）

不要用 `rebase -i` 手改 59 行 todo；用树快照法机械且不会出错：

```sh
git reset --hard <基线>                      # 基线 = upstream 或分叉点
# 对每个主题组（按时间从旧到新）：
git read-tree -u --reset <该组最后一个commit的SHA>
git commit -m "<合并后的 message>"
```

要点：
- 以每个主题组**最后一个 commit 的 SHA** 为快照点，`read-tree -u --reset` 会把工作区和 index 精确置为该 commit 的树（包括删除的文件），然后 commit 得到该组 squashed 后的净差异。
- 不要用 `git checkout <sha> -- .` 代替：它不会删除两个快照点之间被删掉的文件。
- 合并 message 用传统式格式（`feat(scope):` / `fix(scope):`），正文把该组各 commit 的关键发现浓缩成要点列表——原因（bug 现象/证据）+ 修复手段，这是将来回溯最有价值的部分。

### 5. 验证（缺一不可）

```sh
git diff --stat <整理前tip> dev        # 必须为空 → 代码零丢失
git log --oneline '@{u}..HEAD'         # 数量 = 主题组数
cargo test --workspace                 # 或项目对应的测试命令，全绿
```

- 如果测试失败，**先确认它在整理前的历史里就是失败的**（对比相关文件在旧历史中的状态）。是既有问题则顺手修掉并单独提交一个 `test:` commit；是整理引入的则说明快照点选错了，回查。

### 6. 收尾

- 汇报：新 commit 列表（表格：SHA + 一句话）、代码树一致性验证结果、测试结果、备份分支名。
- 提醒用户确认后可 `git branch -D backup/...` 删除备份，然后 `git push`。

## 注意

- 只动**未推送**的 commit；upstream 及更早的历史永远不重写。
- `git reset --hard` 前确认工作区干净，备份分支已建好。
- 用户中断或结果异常时，恢复：`git reset --hard backup/pre-squash-dev`。
