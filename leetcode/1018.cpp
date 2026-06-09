// 给定一个二进制数组 `nums` ( 索引从0开始 )。
//
// 我们将`x_i` 定义为其二进制表示形式为子数组 `nums[0..i]` (从最高有效位到最低有效位)。
//
// - 例如，如果 `nums =[1,0,1]` ，那么 `x_0 = 1`, `x_1 = 2`, 和 `x_2 = 5`。
//
// 返回布尔值列表 `answer`，只有当 `x_i` 可以被 `5` 整除时，答案 `answer[i]` 为 `true`，否则为 `false`。
//
// 示例 1：
//
// 输入：nums = [0,1,1]
// 输出：[true,false,false]
// 解释：
// 输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为 true 。
//
// 示例 2：
//
// 输入：nums = [1,1,1]
// 输出：[false,false,false]
//
// 提示：
//
// - `1 <= nums.length <= 10^5`
// - `nums[i]` 仅为 `0` 或 `1`
//
// https://leetcode.cn/problems/binary-prefix-divisible-by-5/description/

#include <iostream>

#include "check.h"
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans{};
        ans.reserve(nums.size());

        int val{0};
        for (int n : nums) {
            val = (val << 1) | n;
            val = val % 5;
            ans.push_back(val == 0);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        vector<int> nums = {0, 1, 1};
        auto result = solution.prefixesDivBy5(nums);
        check("示例1: nums=[0,1,1]", result, vector<bool>{true, false, false});
    }

    // 示例 2
    {
        vector<int> nums = {1, 1, 1};
        auto result = solution.prefixesDivBy5(nums);
        check("示例2: nums=[1,1,1]", result, vector<bool>{false, false, false});
    }

    // 额外用例
    {
        vector<int> nums = {1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
                            1, 0, 1, 1, 1, 0, 0, 1, 0};
        auto result = solution.prefixesDivBy5(nums);
        check("额外用例", result,
              vector<bool>{false, false, false, false, false, true, false,
                           false, false, true, false, false, true, false, false,
                           false, false, true, true});
    }

    // 额外用例2
    {
        vector<int> nums = {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                            1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1};
        auto result = solution.prefixesDivBy5(nums);
        check(
            "额外用例2", result,
            vector<bool>{false, false, false, false, false, false, false, false,
                         false, false, false, false, false, false, false, false,
                         false, false, false, false, false, false, false, false,
                         false, false, false, false, false, false, false, true,
                         false, false, true,  true,  true,  true,  false});
    }

    return 0;
}
