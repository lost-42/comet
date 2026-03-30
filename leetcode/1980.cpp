#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int str2int(const string& str) {
        int v{0};
        for (size_t i = 0; i < str.size(); ++i)
            v = (v << 1) + (str[i] - '0');
        return v;
    }

    string int2str(int val, size_t n) {
        string s{};
        while (val) {
            s.push_back((val & 1) + '0');
            val >>= 1;
        }

        size_t sSize = s.size();
        for (size_t i = 0; i < n - sSize; ++i)
            s.push_back('0');

        reverse(s.begin(), s.end());
        return s;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        if (nums.empty())
            return "";

        int n = nums.front().size();

        unordered_set<int> set{};
        for (auto& num : nums)
            set.insert(str2int(num));

        for (int i = 0; i < 1 << n; ++i)
            if (!set.contains(i))
                return int2str(i, n);

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
