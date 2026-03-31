#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int spaceCnt{0};
        vector<string> wordVec{};
        for (auto it = text.begin(); it != text.end();) {
            if (*it == ' ') {
                ++it;
                ++spaceCnt;
                continue;
            } else {
                string word{};
                while (it != text.end() && *it != ' ') {
                    word.push_back(*it);
                    ++it;
                }
                wordVec.push_back(word);
            }
        }

        string ans{};
        int n = (wordVec.size() == 1) ? 0 : spaceCnt / (wordVec.size() - 1);
        int r = spaceCnt - n * (wordVec.size() - 1);
        for (auto it = wordVec.begin(); it != wordVec.end() - 1; ++it) {
            ans.append(*it);
            for (int i = 0; i < n; ++i)
                ans.push_back(' ');
        }
        ans.append(wordVec.back());
        for (int i = 0; i < r; ++i)
            ans.push_back(' ');

        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        string text = "  this   is  a sentence ";
        string result = solution.reorderSpaces(text);
        cout << "测试用例1 - 输入: \"" << text << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"this   is   a   sentence\"" << endl;
        cout << "字符串长度: 输入=" << text.length()
             << ", 输出=" << result.length() << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        string text = " practice   makes   perfect";
        string result = solution.reorderSpaces(text);
        cout << "测试用例2 - 输入: \"" << text << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"practice   makes   perfect \"" << endl;
        cout << "字符串长度: 输入=" << text.length()
             << ", 输出=" << result.length() << endl;
        cout << endl;
    }

    // 测试用例3：示例3
    {
        string text = "hello   world";
        string result = solution.reorderSpaces(text);
        cout << "测试用例3 - 输入: \"" << text << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"hello   world\"" << endl;
        cout << "字符串长度: 输入=" << text.length()
             << ", 输出=" << result.length() << endl;
        cout << endl;
    }

    // 测试用例4：示例4
    {
        string text = "  walks  udp package   into  bar a";
        string result = solution.reorderSpaces(text);
        cout << "测试用例4 - 输入: \"" << text << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"walks  udp  package  into  bar  a \"" << endl;
        cout << "字符串长度: 输入=" << text.length()
             << ", 输出=" << result.length() << endl;
        cout << endl;
    }

    // 测试用例5：示例5
    {
        string text = "a";
        string result = solution.reorderSpaces(text);
        cout << "测试用例5 - 输入: \"" << text << "\"" << endl;
        cout << "输出: \"" << result << "\"" << endl;
        cout << "期望输出: \"a\"" << endl;
        cout << "字符串长度: 输入=" << text.length()
             << ", 输出=" << result.length() << endl;
        cout << endl;
    }

    return 0;
}
