// 一个数组的 异或总和 定义为数组中所有元素按位 `XOR` 的结果；如果数组为 空 ，则异或总和为 `0` 。
// 例如，数组 `[2,5,6]` 的 异或总和 为 `2 XOR 5 XOR 6 = 1` 。
//
// 给你一个数组 `nums` ，请你求出 `nums` 中每个 子集 的 异或总和 ，计算并返回这些值相加之 和 。
//
// 注意：在本题中，元素 相同 的不同子集应 多次 计数。
//
// 数组 `a` 是数组 `b` 的一个 子集 的前提条件是：从 `b` 删除几个（也可能不删除）元素能够得到 `a` 。
//
// 示例 1：
// 输入：nums = [1,3]
// 输出：6
// 解释：[1,3] 共有 4 个子集：
// - 空子集的异或总和是 0 。
// - [1] 的异或总和为 1 。
// - [3] 的异或总和为 3 。
// - [1,3] 的异或总和为 1 XOR 3 = 2 。
// 0 + 1 + 3 + 2 = 6
//
// 示例 2：
// 输入：nums = [5,1,6]
// 输出：28
// 解释：[5,1,6] 共有 8 个子集：
// - 空子集的异或总和是 0 。
// - [5] 的异或总和为 5 。
// - [1] 的异或总和为 1 。
// - [6] 的异或总和为 6 。
// - [5,1] 的异或总和为 5 XOR 1 = 4 。
// - [5,6] 的异或总和为 5 XOR 6 = 3 。
// - [1,6] 的异或总和为 1 XOR 6 = 7 。
// - [5,1,6] 的异或总和为 5 XOR 1 XOR 6 = 2 。
// 0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
//
// 示例 3：
// 输入：nums = [3,4,5,6,7,8]
// 输出：480
// 解释：每个子集的全部异或总和值之和为 480 。
//
// 提示：
// - `1 <= nums.length <= 12`
// - `1 <= nums[i] <= 20`
//
// https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void impl(const vector<int>& nums, int i, int xsum, int& ans) {
        if (i >= nums.size())
            return;

        impl(nums, i + 1, xsum, ans);

        xsum ^= nums[i];
        ans += xsum;
        impl(nums, i + 1, xsum, ans);
    }

    int subsetXORSum(vector<int>& nums) {
        int ans{0};
        if (nums.empty())
            return ans;

        impl(nums, 0, 0, ans);
        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<int> nums = {1, 3};
        int result = solution.subsetXORSum(nums);
        cout << "测试用例1 - 输入: [1,3]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 6" << endl;
    }

    // 测试用例2：示例2
    {
        vector<int> nums = {5, 1, 6};
        int result = solution.subsetXORSum(nums);
        cout << "测试用例2 - 输入: [5,1,6]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 28" << endl;
    }

    // 测试用例3：示例3
    {
        vector<int> nums = {3, 4, 5, 6, 7, 8};
        int result = solution.subsetXORSum(nums);
        cout << "测试用例3 - 输入: [3,4,5,6,7,8]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 480" << endl;
    }

    return 0;
}
