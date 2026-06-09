---
name: review
description: 管理 LeetCode 复习列表。添加题目到复习列表，或从列表中抽取题目复习（清空 Solution 代码）。
compatibility: ['Read', 'Edit', 'Write', 'Bash']
---

# Review

## 核心逻辑

维护 skill 目录下的 `review.md`（markdown 表格），记录题目序号、标题、加入日期、复习日期。复习日期为 `-` 表示未复习。

选取策略：从加入 ≥ 3 天的未复习题目中随机抽一道，清空对应 `.cpp` 文件中的 Solution 类方法体。

## Workflow

### 添加模式

触发：用户说"把这题加到复习列表"、"加入复习" 等。

1. 从当前讨论的 `.cpp` 文件名提取题目 ID
2. 读取 `.cpp` 文件，从头部 `//` 注释块的 `//` 开头的第一行提取标题（例如 `// 给你一个...` 后面接近的独立注释行可能没有标题——此时取 LeetCode 链接中的 slug 或跳过标题提取）
   - 更直接的方式：读取文件第一行注释，通常中文标题在文件头部。若无法确定，用文件名作为 fallback
3. 运行：
   ```bash
   python3 .claude/skills/review/add_to_review.py <id> "<title>"
   ```

### 复习模式

触发：用户说"我想复习一道题"、"抽一题复习" 等。

1. 运行：
   ```bash
   python3 .claude/skills/review/pick_for_review.py
   ```
   exit 1 则告知用户无合适题目并结束
2. 解析 JSON 输出 `{"id": ..., "title": ..., "added_date": ...}`
3. 读取 `<id>.cpp`
4. 清空 Solution 类中所有方法体：
   - `void` / `const void` 返回 → `{ }`
   - 其他返回类型 → `{ return {}; }`
   - 保留缩进，不修改方法签名
   - 保持 includes、using、注释、类外辅助函数、main() 全部不变
5. 告知用户：`"请复习 #<id> <title>，文件 <id>.cpp 已清空 Solution 实现"`

## review.md 格式

```markdown
# LeetCode 复习列表
| # | 标题 | 加入日期 | 复习日期 |
|---|------|----------|----------|
| 748 | 最短补全词 | 2026-06-01 | - |
```
