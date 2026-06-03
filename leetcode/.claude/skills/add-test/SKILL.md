---
name: add-test
description: 为 LeetCode 题目文件添加测试代码，不修改 Solution 类，只使用注释中的示例
compatibility: ['Read', 'Edit', 'Write']
---

# Add Test

## 原则

1. 不修改 Solution 类
2. 只使用注释中的 `示例` 部分作为测试数据
3. 在 Solution 类后添加 `main()` 函数
4. 必须将 `#include` 中已有的 `"utils.h"` 改为 `"check.h"`（check.h 已包含 utils.h）

## 校验

使用 `check.h` 中的 `check()` 函数替代手动打印。该函数自动比较实际值和期望值，打印 `[🟢 PASS]` 或 `[🔴 FAIL]`。

`check` 支持以下重载：
- 通用类型（int, bool, string 等）：直接传入值
- `vector<T>`：直接传入 `vector<T>{...}`
- `vector<vector<T>>`：直接传入 `vector<vector<T>>{{...}}`

## 格式

```cpp
int main() {
    Solution solution;

    // 示例 1
    {
        vector<int> nums = {1, 2, 3};
        int result = solution.sum(nums);
        check("示例1: nums=[1,2,3]", result, 6);
    }

    return 0;
}
```

添加完 main 函数后用 `./lc.sh xxx.cpp` 验证编译运行。
