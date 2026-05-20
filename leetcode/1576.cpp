#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '?')
                continue;

            for (int j = 0; j < 26; ++j) {
                char ch = 'a' + j;

                if (i != 0 && s[i - 1] == ch)
                    continue;
                if (i != s.size() - 1 && s[i + 1] == ch)
                    continue;

                s[i] = ch;
                break;
            }
        }
        return s;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        string s = "?zs";
        string result = solution.modifyString(s);
        cout << "测试用例1 - 输入: \"" << s << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"azs\"" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        string s = "ubv?w";
        string result = solution.modifyString(s);
        cout << "测试用例2 - 输入: \"" << s << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"ubvaw\"" << endl;
        cout << endl;
    }

    return 0;
}
