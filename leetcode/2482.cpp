// 给你一个下标从 0 开始的 `m x n` 二进制矩阵 `grid` 。
//
// 我们按照如下过程，定义一个下标从 0 开始的 `m x n` 差值矩阵 `diff` ：
//
// - 令第 `i` 行一的数目为 `onesRow_i` 。
// - 令第 `j` 列一的数目为 `onesCol_j` 。
// - 令第 `i` 行零的数目为 `zerosRow_i` 。
// - 令第 `j` 列零的数目为 `zerosCol_j` 。
// - `diff[i][j] = onesRow_i + onesCol_j - zerosRow_i - zerosCol_j`
//
// 请你返回差值矩阵 `diff` 。
//
// 示例 1：
// 输入：grid = [[0,1,1],[1,0,1],[0,0,1]]
// 输出：[[0,0,4],[0,0,4],[-2,-2,2]]
// 解释：
// - diff[0][0] = onesRow_0 + onesCol_0 - zerosRow_0 - zerosCol_0 = 2 + 1 - 1 - 2 = 0
// - diff[0][1] = onesRow_0 + onesCol_1 - zerosRow_0 - zerosCol_1 = 2 + 1 - 1 - 2 = 0
// - diff[0][2] = onesRow_0 + onesCol_2 - zerosRow_0 - zerosCol_2 = 2 + 3 - 1 - 0 = 4
// - diff[1][0] = onesRow_1 + onesCol_0 - zerosRow_1 - zerosCol_0 = 2 + 1 - 1 - 2 = 0
// - diff[1][1] = onesRow_1 + onesCol_1 - zerosRow_1 - zerosCol_1 = 2 + 1 - 1 - 2 = 0
// - diff[1][2] = onesRow_1 + onesCol_2 - zerosRow_1 - zerosCol_2 = 2 + 3 - 1 - 0 = 4
// - diff[2][0] = onesRow_2 + onesCol_0 - zerosRow_2 - zerosCol_0 = 1 + 1 - 2 - 2 = -2
// - diff[2][1] = onesRow_2 + onesCol_1 - zerosRow_2 - zerosCol_1 = 1 + 1 - 2 - 2 = -2
// - diff[2][2] = onesRow_2 + onesCol_2 - zerosRow_2 - zerosCol_2 = 1 + 3 - 2 - 0 = 2
//
// 示例 2：
// 输入：grid = [[1,1,1],[1,1,1]]
// 输出：[[5,5,5],[5,5,5]]
// 解释：
// - diff[0][0] = onesRow_0 + onesCol_0 - zerosRow_0 - zerosCol_0 = 3 + 2 - 0 - 0 = 5
// - diff[0][1] = onesRow_0 + onesCol_1 - zerosRow_0 - zerosCol_1 = 3 + 2 - 0 - 0 = 5
// - diff[0][2] = onesRow_0 + onesCol_2 - zerosRow_0 - zerosCol_2 = 3 + 2 - 0 - 0 = 5
// - diff[1][0] = onesRow_1 + onesCol_0 - zerosRow_1 - zerosCol_0 = 3 + 2 - 0 - 0 = 5
// - diff[1][1] = onesRow_1 + onesCol_1 - zerosRow_1 - zerosCol_1 = 3 + 2 - 0 - 0 = 5
// - diff[1][2] = onesRow_1 + onesCol_2 - zerosRow_1 - zerosCol_2 = 3 + 2 - 0 - 0 = 5
//
// 提示：
// - `m == grid.length`
// - `n == grid[i].length`
// - `1 <= m, n <= 10^5`
// - `1 <= m * n <= 10^5`
// - `grid[i][j]` 要么是 `0` ，要么是 `1` 。
//
// https://leetcode.cn/problems/difference-between-ones-and-zeros-in-row-and-column/description/

#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<int> ones_in_row(m, 0), ones_in_col(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++ones_in_row[i];
                    ++ones_in_col[j];
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = ones_in_row[i] + ones_in_col[j] -
                             (m - ones_in_row[i]) - (n - ones_in_col[j]);
            }
        }

        return grid;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<vector<int>> grid = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
        vector<vector<int>> result = solution.onesMinusZeros(grid);
        cout << "测试用例1 - 输入: [[0,1,1],[1,0,1],[0,0,1]]" << endl;
        cout << "输出: ";
        printVector2D(result);
        cout << endl;
        cout << "期望输出: [[0,0,4],[0,0,4],[-2,-2,2]]" << endl;
    }

    // 测试用例2：示例2
    {
        vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 1}};
        vector<vector<int>> result = solution.onesMinusZeros(grid);
        cout << "测试用例2 - 输入: [[1,1,1],[1,1,1]]" << endl;
        cout << "输出: ";
        printVector2D(result);
        cout << endl;
        cout << "期望输出: [[5,5,5],[5,5,5]]" << endl;
    }

    return 0;
}
