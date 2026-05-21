#include <cstddef>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m{};
        for (int d : deck)
            ++m[d];

        int X = -1;
        for (const auto& [d, c] : m) {
            X = (~X) ? gcd(X, c) : c;
        }

        return X >= 2;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<int> deck = {1, 2, 3, 4, 4, 3, 2, 1};
        bool result = solution.hasGroupsSizeX(deck);
        cout << "测试用例1 - 输入: [1,2,3,4,4,3,2,1]" << endl;
        cout << "输出: " << boolalpha << result << endl;
        cout << "期望输出: true" << endl;
    }

    // 测试用例2：示例2
    {
        vector<int> deck = {1, 1, 1, 2, 2, 2, 3, 3};
        bool result = solution.hasGroupsSizeX(deck);
        cout << "测试用例2 - 输入: [1,1,1,2,2,2,3,3]" << endl;
        cout << "输出: " << boolalpha << result << endl;
        cout << "期望输出: false" << endl;
    }

    // 测试用例3
    {
        vector<int> deck = {1, 1, 2, 2, 2, 2};
        bool result = solution.hasGroupsSizeX(deck);
        cout << "测试用例3 - 输入: [1,1,2,2,2,2]" << endl;
        cout << "输出: " << boolalpha << result << endl;
        cout << "期望输出: true" << endl;
    }

    // 测试用例4
    {
        vector<int> deck = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
        bool result = solution.hasGroupsSizeX(deck);
        cout << "测试用例4 - 输入: [1,1,1,1,2,2,2,2,2,2]" << endl;
        cout << "输出: " << boolalpha << result << endl;
        cout << "期望输出: true" << endl;
    }

    return 0;
}
