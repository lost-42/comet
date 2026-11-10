---
name: date-commit
description: |
  Commit all changes using today's date as the commit message (e.g., "2026-08-22").
  Use when the user asks to commit with a date, "提交一下", "commit",
  or wants a quick lightweight commit.
  Triggers on: "date commit", "提交", "commit 一下", "用日期提交".
---

把今天的改动用日期作为提交信息全部提交。核心就一句话，但**提交前先扫一眼有没有可疑文件**。

## 核心规则

**先检查，再提交。** 看到"不确定是干嘛的"文件，先停下研究清楚，问用户怎么处理，绝不直接提交。全是正常文件才 `git add -A` 提交。

## Workflow

### Step 1: 扫变更

```bash
git status --short
```

逐条判断这次变更里有没有**可疑文件**——`git add -A` 会把它们一起卷进去，所以必须先看清。

**可疑文件的特征：**
- 突然出现在仓库根目录、或不在 `cpp/`、`leetcode/`、`nurbs/`、`.agents/` 这些已知目录里的文件
- 像是构建/抓取/缓存的中间产物：`.log`、`.tmp`、`.zip`，以及散落在源码目录外的 `.json`、`.xml`、`.html` 等
- 构建产物（`cpp/build/`、`cpp/bin/`、`.cache/`）本该被 `.gitignore` 挡住——哪天它们出现在 `git status` 里，说明 ignore 没盖住，别直接提交
- 文件名陌生、你没跟用户提过的、之前没见过的新文件

**正常文件（可直接提交）：**
- 源码与题解：`cpp/src/` 下的 `.cpp`/`.h`，`leetcode/` 的题解与工具（`.cpp`、`.h`、`lc.sh`、`scripts/`），`nurbs/` 的笔记与脚本（`.md`、`.py`）
- 项目配置与构建定义：`cpp/CMakePresets.json`、`cpp/.clang-format`、`cpp/scripts/`、`.agents/` 下的技能与规则
- 仓库根目录的 `README.md`、`LICENSE`、`.gitignore`
- 用户明确让改的正常文件

### Step 2: 遇到可疑文件 → 停下确认

发现可疑文件时：
1. 研究它是什么、哪来的（`read` 看内容、`git log` 看何时出现、看它被哪个 skill/脚本写入）
2. 给用户讲清这个文件在干嘛，并给处理建议（删除 / 忽略 / 保留）
3. **等用户拍板，再决定加不加进提交**。不要自己猜，不要直接提交

> 例：仓库根目录冒出个 `CMakeCache.txt`、`main.obj`，一眼不像源码。先看内容——哦，是 MSVC/CMake 构建时落在仓库根目录的中间产物。该删或该补进 `.gitignore`，不是代码。停下问用户。

### Step 3: 正常文件 → 直接提交

确认都是正常文件后（Windows + PowerShell）：

```powershell
git add -A
git commit -m (Get-Date -Format 'yyyy-MM-dd')
```

得到 `YYYY-MM-dd` 格式（如 `2026-08-22`）。bash 等价写法：`git commit -m "$(date +%F)"`。

### Step 4: Push

```powershell
git push
```

## Notes

- 如果用户指定了别的提交信息，用那个。这个仓库的惯例：日常一把梭用日期（`2026-10-11`），单题题解常用 `lc 2120` 这种——用户没特别说就用日期。
- 分不清算不算可疑时，按可疑处理，停下来问。
