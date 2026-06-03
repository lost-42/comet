// 给你一个整数数组 `nums` 。请你创建一个满足以下条件的二维数组：
//
// - 二维数组应该 只 包含数组 `nums` 中的元素。
// - 二维数组中的每一行都包含 不同 的整数。
// - 二维数组的行数应尽可能 少 。
//
// 返回结果数组。如果存在多种答案，则返回其中任何一种。
//
// 请注意，二维数组的每一行上可以存在不同数量的元素。
//
//
// 示例 1：
//
// 输入：nums = [1,3,4,1,2,3,1]
// 输出：[[1,3,4,2],[1,3],[1]]
// 解释：根据题目要求可以创建包含以下几行元素的二维数组：
// - 1,3,4,2
// - 1,3
// - 1
// nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
// 可以证明无法创建少于三行且符合题目要求的二维数组。
//
// 示例 2：
//
// 输入：nums = [1,2,3,4]
// 输出：[[4,3,2,1]]
// 解释：nums 中的所有元素都不同，所以我们可以将其全部保存在二维数组中的第一行。
//
//
// 提示：
//
// - `1 <= nums.length <= 200`
// - `1 <= nums[i] <= nums.length`
//
// https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/description/

#include <utility>
#include <vector>

#include "check.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int arr[201]{};
        for (int n : nums)
            ++arr[n];

        vector<vector<int>> ans{};
        while (true) {
            vector<int> row{};
            for (int i = 1; i <= 200; ++i) {
                if (arr[i] > 0) {
                    row.push_back(i);
                    --arr[i];
                }
            }
            if (row.empty())
                return ans;
            else
                ans.push_back(std::move(row));
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        vector<int> nums = {1, 3, 4, 1, 2, 3, 1};
        auto result = solution.findMatrix(nums);
        check("示例1: nums=[1,3,4,1,2,3,1]", result,
              vector<vector<int>>{{1, 2, 3, 4}, {1, 3}, {1}});
    }

    // 示例 2
    {
        vector<int> nums = {1, 2, 3, 4};
        auto result = solution.findMatrix(nums);
        check("示例2: nums=[1,2,3,4]", result,
              vector<vector<int>>{{1, 2, 3, 4}});
    }

    return 0;
}
