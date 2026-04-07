#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestEven(string s) {
        reverse(s.begin(), s.end());

        for (auto it = s.begin(); it != s.end();) {
            if (*it == '1')
                it = s.erase(it);
            else
                break;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        string s = "1112";
        string result = solution.largestEven(s);
        cout << "测试用例1 - 输入: s = \"" << s << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"1112\"" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        string s = "221";
        string result = solution.largestEven(s);
        cout << "测试用例2 - 输入: s = \"" << s << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"22\"" << endl;
        cout << endl;
    }

    // 测试用例3：示例3
    {
        string s = "1";
        string result = solution.largestEven(s);
        cout << "测试用例3 - 输入: s = \"" << s << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"\"" << endl;
        cout << endl;
    }

    return 0;
}
