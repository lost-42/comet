#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    int maxDistinct(string s) {
        set<char> cs{s.begin(), s.end()};
        return cs.size();
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        string s = "abab";
        int result = solution.maxDistinct(s);
        cout << "测试用例1 - 输入: \"abab\"" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 2" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        string s = "abcd";
        int result = solution.maxDistinct(s);
        cout << "测试用例2 - 输入: \"abcd\"" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 4" << endl;
        cout << endl;
    }

    // 测试用例3：示例3
    {
        string s = "aaaa";
        int result = solution.maxDistinct(s);
        cout << "测试用例3 - 输入: \"aaaa\"" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 1" << endl;
        cout << endl;
    }

    return 0;
}
