#include <iostream>
#include <queue>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> eq{}, oq{};
        vector<bool> eo{};
        while (num) {
            int n = num % 10;
            if (n & 1) {
                oq.push(n);
                eo.push_back(true);
            } else {
                eq.push(n);
                eo.push_back(false);
            }
            num /= 10;
        }

        int ans{0};
        for (int i = eo.size() - 1; i >= 0; --i) {
            auto& q = eo[i] ? oq : eq;
            ans = ans * 10 + q.top();
            q.pop();
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        int num = 1234;
        int result = solution.largestInteger(num);
        cout << "测试用例1 - 输入: " << num << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 3412" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        int num = 65875;
        int result = solution.largestInteger(num);
        cout << "测试用例2 - 输入: " << num << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 87655" << endl;
        cout << endl;
    }

    return 0;
}
