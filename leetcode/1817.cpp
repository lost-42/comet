#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(), logs.end(),
             [](const vector<int>& lhs, const vector<int>& rhs) {
                 if (lhs[0] != rhs[0])
                     return lhs[0] < rhs[0];

                 return lhs[1] < rhs[1];
             });

        vector<int> ans(k, 0);
        int cId = logs[0][0], cT = logs[0][1], cCnt = 1;
        for (const auto& log : logs) {
            int id = log[0];
            int t = log[1];

            if (id != cId) {
                ++ans[cCnt - 1];
                cId = id;
                cCnt = 1;
                cT = t;
            }

            if (t != cT) {
                ++cCnt;
                cT = t;
            }
        }

        if (cCnt)
            ++ans[cCnt - 1];

        return ans;
    }
};

// 测试主函数
int main() {
    Solution solution;

    // 测试示例1
    cout << "测试示例1:" << endl;
    vector<vector<int>> logs1 = {{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
    int k1 = 5;
    vector<int> result1 = solution.findingUsersActiveMinutes(logs1, k1);
    cout << "输入: logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5" << endl;
    cout << "预期输出: [0,2,0,0,0]" << endl;
    cout << "实际输出: ";
    printVector(result1);
    cout << endl;

    // 测试示例2
    cout << "测试示例2:" << endl;
    vector<vector<int>> logs2 = {{1, 1}, {2, 2}, {2, 3}};
    int k2 = 4;
    vector<int> result2 = solution.findingUsersActiveMinutes(logs2, k2);
    cout << "输入: logs = [[1,1],[2,2],[2,3]], k = 4" << endl;
    cout << "预期输出: [1,1,0,0]" << endl;
    cout << "实际输出: ";
    printVector(result2);
    cout << endl;

    return 0;
}
