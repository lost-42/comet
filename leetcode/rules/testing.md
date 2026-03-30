# 测试规则

## 核心原则

1. 不修改Solution类代码
2. 只使用注释中的示例作为测试用例
3. 添加main函数进行测试

## 具体操作

1. 在Solution类后添加main函数
2. 从注释的示例中提取测试数据
3. 每个测试用例用{}包裹
4. 输出清晰的测试信息
5. 一般不需要验证代码是否可以运行, 如果需要, 使用 `./lc.sh xxx.cpp`

## 示例格式

```cpp
// 题目描述...
// 示例1：输入：nums = [1,2,3]，输出：6

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sum(vector<int>& nums) { return 0; }
};

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
