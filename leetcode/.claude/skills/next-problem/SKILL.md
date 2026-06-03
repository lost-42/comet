---
name: next-problem
description: 从已做题目最高 rating 出发，选择未做题目中 rating 不低于该阈值的最低分题目，获取内容并创建 .cpp 文件，然后调用 add-test 添加测试
compatibility: ['Read', 'Edit', 'Write', 'Bash', 'Skill']
---

# Next Problem

## 核心逻辑

已做题目的最高 rating 为基准线，从未做题中选择 rating ≥ 该基准的最低分题目，保证难度始终递增。自动跳过 VIP 题目。

## Workflow

### Step 1: 选择下一道未做题

```bash
python3 .claude/skills/next-problem/find_next.py
```

输出 JSON：`{"id": <题号>, "title": "<英文标题>", "title_zh": "<中文标题>", "title_slug": "<slug>", "rating": <rating>, ...}`

如果所有题都做完了（exit code 1），告知用户并结束。

前置条件：`problem_queue.txt` 必须存在，不存在则运行：
```bash
python3 .claude/skills/next-problem/prepare_queue.py
```

### Step 2: 获取题目内容

```bash
python3 .claude/skills/next-problem/fetch_problem.py <title-slug> > /tmp/leet.json
```

返回 JSON 字段：`questionId`, `questionFrontendId`, `translatedTitle`, `translatedContent`（HTML）, `codeSnippets`, `exampleTestcases`

VIP 题目返回 exit code 2，跳过并回到 Step 1 选下一道。

### Step 3: 创建 .cpp 文件

#### 3a. 处理题目描述

将 `translatedContent`（HTML）转成 `// ` 前缀的中文注释。关键点：
- 还原 HTML 实体（`&lt;` → `<` 等）
- `<code>` → `` ` ``，`<sup>` → `^`，`<sub>` → `_`
- `<p>`, `<br>`, `<pre>` → 换行，列表标签合理排版
- 删除其他 HTML 标签，保留文本内容
- 保持 `输入：` / `输出：` 原样，供 add-test 解析

#### 3b. 提取代码模板

从 `codeSnippets` 取 `langSlug == "cpp"` 的 `code` 字段。

#### 3c. 头文件

按需添加 `#include`，总是包含 `"check.h"`（已包含 `<iostream>`、`"utils.h"` 和 `using namespace std` 之外所需的所有标准库头文件）。若代码模板需 `<algorithm>` 等额外头文件则按需补充。

#### 3d. 写入 `<题号>.cpp`

```
// [题目描述注释]
//
// https://leetcode.cn/problems/<title-slug>/description/

#include "check.h"
using namespace std;

class Solution {
public:
    [代码模板]
};
```

不要添加 main 函数（留给 add-test）。

### Step 4: 调用 add-test

使用 Skill 工具调用 `add-test`，传入刚创建的 `.cpp` 文件名。
