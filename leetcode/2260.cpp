#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans{numeric_limits<int>::max()};
        unordered_map<int, int> m{};

        for (size_t i = 0; i < cards.size(); ++i) {
            int card = cards[i];
            int& pos = m[card];

            if (pos == 0)
                pos = i + 1;
            else {
                int dis = i + 1 - pos + 1;
                ans = min(dis, ans);
                pos = i + 1;
            }
        }

        return (ans != numeric_limits<int>::max()) ? ans : -1;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<int> cards = {3, 4, 2, 3, 4, 7};
        int result = solution.minimumCardPickup(cards);
        cout << "测试用例1 - 输入: [3,4,2,3,4,7]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 4" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        vector<int> cards = {1, 0, 5, 3};
        int result = solution.minimumCardPickup(cards);
        cout << "测试用例2 - 输入: [1,0,5,3]" << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: -1" << endl;
    }

    return 0;
}
