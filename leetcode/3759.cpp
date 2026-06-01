// 给你一个长度为 n 的整数数组 nums 和一个整数 k。
//
// 如果数组 nums 中的某个元素满足以下条件，则称其为
// 合格元素：存在 至少 k 个元素 严格大于 它。
//
// 返回一个整数，表示数组 nums 中合格元素的总数。
//
//
// 示例 1：
//
// 输入：nums = [3,1,2], k = 1
// 输出：2
// 解释：
// 元素 1 和 2 均有至少 k = 1 个元素大于它们。
// 没有元素比 3 更大。因此答案是 2。
//
// 示例 2：
//
// 输入：nums = [5,5,5], k = 2
// 输出：0
// 解释：
// 由于所有元素都等于 5，没有任何元素比其他元素大。因此答案是 0。
//
//
// 提示：
//
// - 1 <= n == nums.length <= 10^5
// - 1 <= nums[i] <= 10^9
// - 0 <= k < n
//
// https://leetcode.cn/problems/count-elements-with-at-least-k-greater-values/description/

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0)
            return n;

        nth_element(nums.begin(), nums.begin() + n - k, nums.end());

        int kth = nums[n - k];
        int ans = 0;
        for (int& x : nums)
            ans += x < kth;
        return ans;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        vector<int> nums = {3, 1, 2};
        int k = 1;
        int result = solution.countElements(nums, k);
        cout << "示例 1 - 输入: nums = [3,1,2], k = 1" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 2" << endl;
    }

    // 示例 2
    {
        vector<int> nums = {5, 5, 5};
        int k = 2;
        int result = solution.countElements(nums, k);
        cout << "示例 2 - 输入: nums = [5,5,5], k = 2" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 0" << endl;
    }

    // 自定义用例
    {
        vector<int> nums = {332931278, 226558367, 744830869};
        int k = 2;
        int result = solution.countElements(nums, k);
        cout << "自定义用例 - 输入: nums = [332931278,226558367,744830869], k "
                "= 2"
             << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 1" << endl;
    }

    return 0;
}
