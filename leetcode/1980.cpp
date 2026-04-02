#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        if (nums.empty())
            return "";

        int n = nums.front().size();

        unordered_set<int> set{};
        for (auto& num : nums)
            set.insert(binaryStringToInt(num));

        for (int i = 0; i < 1 << n; ++i)
            if (!set.contains(i))
                return intToBinaryString(i, n);

        return "";
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<string> nums = {"01", "10"};
        string result = solution.findDifferentBinaryString(nums);
        cout << "测试用例1 - 输入: [\"01\",\"10\"]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: \"11\" (或 \"00\")" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        vector<string> nums = {"00", "01"};
        string result = solution.findDifferentBinaryString(nums);
        cout << "测试用例2 - 输入: [\"00\",\"01\"]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: \"11\" (或 \"10\")" << endl;
        cout << endl;
    }

    // 测试用例3：示例3
    {
        vector<string> nums = {"111", "011", "001"};
        string result = solution.findDifferentBinaryString(nums);
        cout << "测试用例3 - 输入: [\"111\",\"011\",\"001\"]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: \"101\" (或 \"000\", \"010\", \"100\", \"110\")"
             << endl;
        cout << endl;
    }

    return 0;
}
