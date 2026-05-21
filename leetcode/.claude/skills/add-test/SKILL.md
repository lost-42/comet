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

## 格式

每个测试用例用 `{}` 包裹，输出实际结果和期望值：

```cpp
int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<int> nums = {1, 2, 3};
        int result = solution.sum(nums);
        cout << "测试用例1 - 输入: [1,2,3]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 6" << endl;
    }

    return 0;
}
```

验证编译用 `./lc.sh xxx.cpp`。
