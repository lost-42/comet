// 现有一个 `n x n` 大小的网格，左上角单元格坐标 `(0, 0)` ，右下角单元格坐标 `(n - 1, n - 1)` 。给你整数 `n` 和一个整数数组 `startPos` ，其中 `startPos = [start_row, start_col]` 表示机器人最开始在坐标为 `(start_row, start_col)` 的单元格上。
//
// 另给你一个长度为 `m` 、下标从 0 开始的字符串 `s` ，其中 `s[i]` 是对机器人的第 `i` 条指令：`'L'`（向左移动），`'R'`（向右移动），`'U'`（向上移动）和 `'D'`（向下移动）。
//
// 机器人可以从 `s` 中的任一第 `i` 条指令开始执行。它将会逐条执行指令直到 `s` 的末尾，但在满足下述条件之一时，机器人将会停止：
//
// - 下一条指令将会导致机器人移动到网格外。
// - 没有指令可以执行。
//
// 返回一个长度为 `m` 的数组 `answer` ，其中 `answer[i]` 是机器人从第 `i` 条指令 开始 ，可以执行的 指令数目 。
//
// 示例 1：
//
// 输入：n = 3, startPos = [0,1], s = "RRDDLU"
// 输出：[1,5,4,3,1,0]
// 解释：机器人从 startPos 出发，并从第 i 条指令开始执行：
// - 0: "RRDDLU" 在移动到网格外之前，只能执行一条 "R" 指令。
// - 1: "RDDLU" 可以执行全部五条指令，机器人仍在网格内，最终到达 (0, 0) 。
// - 2: "DDLU" 可以执行全部四条指令，机器人仍在网格内，最终到达 (0, 0) 。
// - 3: "DLU" 可以执行全部三条指令，机器人仍在网格内，最终到达 (0, 0) 。
// - 4: "LU" 在移动到网格外之前，只能执行一条 "L" 指令。
// - 5: "U" 如果向上移动，将会移动到网格外。
//
// 示例 2：
//
// 输入：n = 2, startPos = [1,1], s = "LURD"
// 输出：[4,1,0,0]
// 解释：
// - 0: "LURD"
// - 1: "URD"
// - 2: "RD"
// - 3: "D"
//
// 示例 3：
//
// 输入：n = 1, startPos = [0,0], s = "LRUD"
// 输出：[0,0,0,0]
// 解释：无论机器人从哪条指令开始执行，都会移动到网格外。
//
// 提示：
//
// - `m == s.length`
// - `1 <= n, m <= 500`
// - `startPos.length == 2`
// - `0 <= start_row, start_col < n`
// - `s` 由 `'L'`、`'R'`、`'U'` 和 `'D'` 组成
//
// https://leetcode.cn/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/

#include <string>
#include <vector>

#include "check.h"
using namespace std;

class Solution {
public:
    bool isInRange(int n, const vector<int>& pos) {
        if (pos[0] < 0 || pos[0] >= n)
            return false;
        else if (pos[1] < 0 || pos[1] >= n)
            return false;
        return true;
    }

    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        size_t m = s.size();

        vector<int> pref_row(m + 1, 0), pref_col(m + 1, 0);
        for (size_t i = 1; i < m + 1; ++i) {
            char ch = s[i - 1];
            if (ch == 'U') {
                pref_row[i] = pref_row[i - 1] - 1;
                pref_col[i] = pref_col[i - 1];
            } else if (ch == 'D') {
                pref_row[i] = pref_row[i - 1] + 1;
                pref_col[i] = pref_col[i - 1];
            } else if (ch == 'L') {
                pref_row[i] = pref_row[i - 1];
                pref_col[i] = pref_col[i - 1] - 1;
            } else if (ch == 'R') {
                pref_row[i] = pref_row[i - 1];
                pref_col[i] = pref_col[i - 1] + 1;
            }
        }

        vector<int> ans{};
        ans.reserve(m);

        for (size_t i = 0; i < m; ++i) {
            int upper_bound_r = pref_row[i] + n - 1 - startPos[0];
            int lower_bound_r = pref_row[i] - startPos[0];
            int upper_bound_c = pref_col[i] + n - 1 - startPos[1];
            int lower_bound_c = pref_col[i] - startPos[1];

            for (size_t k = i + 1; k <= m; ++k) {
                if (pref_row[k] < lower_bound_r ||
                    pref_row[k] > upper_bound_r) {
                    ans.push_back(k - i - 1);
                    break;
                } else if (pref_col[k] < lower_bound_c ||
                           pref_col[k] > upper_bound_c) {
                    ans.push_back(k - i - 1);
                    break;
                }
            }
            if (ans.size() != i + 1)
                ans.push_back(m - i);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        int n = 3;
        vector<int> startPos = {0, 1};
        string s = "RRDDLU";
        vector<int> result = solution.executeInstructions(n, startPos, s);
        check("示例1: n=3, startPos=[0,1], s=\"RRDDLU\"", result,
              vector<int>{1, 5, 4, 3, 1, 0});
    }

    // 示例 2
    {
        int n = 2;
        vector<int> startPos = {1, 1};
        string s = "LURD";
        vector<int> result = solution.executeInstructions(n, startPos, s);
        check("示例2: n=2, startPos=[1,1], s=\"LURD\"", result,
              vector<int>{4, 1, 0, 0});
    }

    // 示例 3
    {
        int n = 1;
        vector<int> startPos = {0, 0};
        string s = "LRUD";
        vector<int> result = solution.executeInstructions(n, startPos, s);
        check("示例3: n=1, startPos=[0,0], s=\"LRUD\"", result,
              vector<int>{0, 0, 0, 0});
    }

    return 0;
}
