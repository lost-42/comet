// 给定一个长度为 n 的整数数组 nums 和一个整数 k。
//
// 你必须从 nums 中选择 恰好 k 个非空子数组 nums[l..r]。子数组可以重叠，同一个子数组（相同的 l 和 r）可以 被选择超过一次。
//
// 子数组 nums[l..r] 的 值 定义为：max(nums[l..r]) - min(nums[l..r])。
//
// 总值 是所有被选子数组的 值 之和。
//
// 返回你能实现的 最大 可能总值。
// 子数组 是数组中连续的 非空 元素序列。
//
// 示例 1:
// 输入: nums = [1,3,2], k = 2
// 输出: 4
// 解释:
// 一种最优的方法是：
// - 选择 nums[0..1] = [1, 3]。最大值为 3，最小值为 1，得到的值为 3 - 1 = 2。
// - 选择 nums[0..2] = [1, 3, 2]。最大值仍为 3，最小值仍为 1，所以值也是 3 - 1 = 2。
// 将它们相加得到 2 + 2 = 4。
//
// 示例 2:
// 输入: nums = [4,2,5,1], k = 3
// 输出: 12
// 解释:
// 一种最优的方法是：
// - 选择 nums[0..3] = [4, 2, 5, 1]。最大值为 5，最小值为 1，得到的值为 5 - 1 = 4。
// - 选择 nums[1..3] = [2, 5, 1]。最大值为 5，最小值为 1，所以值也是 4。
// - 选择 nums[2..3] = [5, 1]。最大值为 5，最小值为 1，所以值同样是 4。
// 将它们相加得到 4 + 4 + 4 = 12。
//
// 提示:
// - 1 <= n == nums.length <= 5 * 10^4
// - 0 <= nums[i] <= 10^9
// - 1 <= k <= 10^5
//
// https://leetcode.cn/problems/maximum-total-subarray-value-i/description/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [min_val, max_val] = ranges::minmax(nums);
        return k * (long long)(max_val - min_val);
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<int> nums = {1, 3, 2};
        int k = 2;
        long long result = solution.maxTotalValue(nums, k);
        cout << "测试用例1 - 输入: nums = [1,3,2], k = 2" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 4" << endl;
    }

    // 测试用例2：示例2
    {
        vector<int> nums = {4, 2, 5, 1};
        int k = 3;
        long long result = solution.maxTotalValue(nums, k);
        cout << "测试用例2 - 输入: nums = [4,2,5,1], k = 3" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 12" << endl;
    }

    // 测试用例3
    {
        vector<int> nums = {
            701025805, 484014287, 486484825, 479659005, 127752519, 497392660,
            905035207, 885813233, 36336196,  83624455,  562558760, 504283643,
            414557507, 340461196, 75269772,  787067318, 310705037, 994901461,
            509673195, 908722607, 69228965,  239220571, 719440526, 986897320};
        int k = 87;
        long long result = solution.maxTotalValue(nums, k);
        cout << "测试用例3 - 输入: nums = [701025805,...], k = 87" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 83395178055" << endl;
    }

    return 0;
}
