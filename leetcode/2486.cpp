#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        auto si = s.begin();
        auto ti = t.begin();

        while (si != s.end() && ti != t.end()) {
            if (*si == *ti) {
                ++si;
                ++ti;
            } else {
                ++si;
            }
        }

        return t.end() - ti;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        string s = "coaching";
        string t = "coding";
        int result = solution.appendCharacters(s, t);
        cout << "测试用例1 - 输入: s = \"" << s << "\", t = \"" << t << "\""
             << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 4" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        string s = "abcde";
        string t = "a";
        int result = solution.appendCharacters(s, t);
        cout << "测试用例2 - 输入: s = \"" << s << "\", t = \"" << t << "\""
             << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 0" << endl;
        cout << endl;
    }

    // 测试用例3：示例3
    {
        string s = "z";
        string t = "abcde";
        int result = solution.appendCharacters(s, t);
        cout << "测试用例3 - 输入: s = \"" << s << "\", t = \"" << t << "\""
             << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 5" << endl;
        cout << endl;
    }

    return 0;
}
