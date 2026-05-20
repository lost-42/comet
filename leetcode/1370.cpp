#include <array>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        static constexpr int N = 26;
        array<char, N> arr{};
        for (char ch : s)
            ++arr[ch - 'a'];

        string ans{};
        ans.reserve(s.size());

        while (ans.size() < s.size()) {
            for (int i = 0; i < N; ++i) {
                if (arr[i]) {
                    ans.push_back(i + 'a');
                    --arr[i];
                }
            }

            for (int i = N - 1; i >= 0; --i) {
                if (arr[i]) {
                    ans.push_back(i + 'a');
                    --arr[i];
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        string s = "aaaabbbbcccc";
        string result = solution.sortString(s);
        cout << "测试用例1 - 输入: \"aaaabbbbcccc\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"abccbaabccba\"" << endl;
    }

    // 测试用例2：示例2
    {
        string s = "rat";
        string result = solution.sortString(s);
        cout << "测试用例2 - 输入: \"rat\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"art\"" << endl;
    }

    return 0;
}
