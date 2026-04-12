#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> v(nums.size(), 0);
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 0; j <= nums.size() - i; ++j) {
                v[j] |= nums[i + j - 1];
                if (v[j] >= k)
                    return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<int> nums = {1, 2, 3};
        int k = 2;
        int result = solution.minimumSubarrayLength(nums, k);
        cout << "测试用例1 - 输入: nums = [1,2,3], k = 2" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 1" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        vector<int> nums = {2, 1, 8};
        int k = 10;
        int result = solution.minimumSubarrayLength(nums, k);
        cout << "测试用例2 - 输入: nums = [2,1,8], k = 10" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 3" << endl;
        cout << endl;
    }

    // 测试用例3：示例3
    {
        vector<int> nums = {1, 2};
        int k = 0;
        int result = solution.minimumSubarrayLength(nums, k);
        cout << "测试用例3 - 输入: nums = [1,2], k = 0" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 1" << endl;
        cout << endl;
    }

    return 0;
}
