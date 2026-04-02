#include <algorithm>
#include <bit>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int lhs, int rhs) {
            int lenL = bit_width((unsigned int)lhs),
                lenR = bit_width((unsigned int)rhs);
            return (lhs << lenR) + rhs > (rhs << lenL) + lhs;
        });

        int ans = (nums[0] << bit_width((unsigned int)nums[1])) + nums[1];
        ans = (ans << bit_width((unsigned int)nums[2])) + nums[2];

        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<int> nums = {1, 2, 3};
        int result = solution.maxGoodNumber(nums);
        cout << "测试用例1 - 输入: [1,2,3]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 30" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        vector<int> nums = {2, 8, 16};
        int result = solution.maxGoodNumber(nums);
        cout << "测试用例2 - 输入: [2,8,16]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 1296" << endl;
        cout << endl;
    }

    // 测试用例3：示例3
    {
        vector<int> nums = {1, 18, 27};
        int result = solution.maxGoodNumber(nums);
        cout << "测试用例3 - 输入: [1,18,27]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 1906" << endl;
        cout << endl;
    }

    // 测试用例4：示例4
    {
        vector<int> nums = {2, 91, 119};
        int result = solution.maxGoodNumber(nums);
        cout << "测试用例4 - 输入: [2,91,119]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 61294" << endl;
        cout << endl;
    }

    return 0;
}
