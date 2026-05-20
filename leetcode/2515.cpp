#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string& target, int startIndex) {
        int ans = words.size();
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == target) {
                int dist{abs(startIndex - i)};
                ans = std::min<int>(ans,
                                    std::min<int>(dist, words.size() - dist));
            }
        }

        return ans < words.size() ? ans : -1;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
        string target = "hello";
        int startIndex = 1;
        int result = solution.closestTarget(words, target, startIndex);
        cout << "测试用例1 - 示例1" << endl;
        cout
            << "输入: words = [\"hello\",\"i\",\"am\",\"leetcode\",\"hello\"], "
               "target = \"hello\", startIndex = 1"
            << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 1" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        vector<string> words = {"a", "b", "leetcode"};
        string target = "leetcode";
        int startIndex = 0;
        int result = solution.closestTarget(words, target, startIndex);
        cout << "测试用例2 - 示例2" << endl;
        cout << "输入: words = [\"a\",\"b\",\"leetcode\"], target = "
                "\"leetcode\", startIndex = 0"
             << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 1" << endl;
        cout << endl;
    }

    // 测试用例3：示例3
    {
        vector<string> words = {"i", "eat", "leetcode"};
        string target = "ate";
        int startIndex = 0;
        int result = solution.closestTarget(words, target, startIndex);
        cout << "测试用例3 - 示例3" << endl;
        cout << "输入: words = [\"i\",\"eat\",\"leetcode\"], target = \"ate\", "
                "startIndex = 0"
             << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: -1" << endl;
        cout << endl;
    }

    return 0;
}
