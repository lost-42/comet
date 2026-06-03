// 给你一个大小为 `n x n` 的整数方阵 `grid`。返回一个经过如下调整的矩阵：
//
// - 左下角三角形（包括中间对角线）的对角线按 非递增顺序 排序。
// - 右上角三角形 的对角线按 非递减顺序 排序。
//
//
// 示例 1：
//
// 输入： grid = [[1,7,3],[9,8,2],[4,5,6]]
// 输出： [[8,2,3],[9,6,7],[4,5,1]]
// 解释：
//
// 标有黑色箭头的对角线（左下角三角形）应按非递增顺序排序：
// - `[1, 8, 6]` 变为 `[8, 6, 1]`。
// - `[9, 5]` 和 `[4]` 保持不变。
//
// 标有蓝色箭头的对角线（右上角三角形）应按非递减顺序排序：
// - `[7, 2]` 变为 `[2, 7]`。
// - `[3]` 保持不变。
//
// 示例 2：
//
// 输入： grid = [[0,1],[1,2]]
// 输出： [[2,1],[1,0]]
// 解释：
//
// 标有黑色箭头的对角线必须按非递增顺序排序，因此 `[0, 2]` 变为 `[2, 0]`。其他对角线已经符合要求。
//
// 示例 3：
//
// 输入： grid = [[1]]
// 输出： [[1]]
// 解释：
//
// 只有一个元素的对角线已经符合要求，因此无需修改。
//
//
// 提示：
//
// - `grid.length == grid[i].length == n`
// - `1 <= n <= 10`
// - `-10^5 <= grid[i][j] <= 10^5`
//
// https://leetcode.cn/problems/sort-matrix-by-diagonals/description/

#include <algorithm>
#include <functional>

#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1)
            return grid;

        int dig[10] = {};

        // bottom left
        for (int i = 0; i < n; ++i) {
            for (int j = 0, k = i; j < n - i; ++j, ++k)
                dig[j] = grid[k][j];

            sort(dig, dig + n - i, greater<int>());

            for (int j = 0, k = i; j < n - i; ++j, ++k)
                grid[k][j] = dig[j];
        }

        // top right
        for (int j = 1; j < n; ++j) {
            for (int i = 0, k = j; i < n - j; ++i, ++k)
                dig[i] = grid[i][k];

            sort(dig, dig + n - j);

            for (int i = 0, k = j; i < n - j; ++i, ++k)
                grid[i][k] = dig[i];
        }

        return grid;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
        auto result = solution.sortMatrix(grid);
        cout << "示例1 - 输入: ";
        printVector2D(grid);
        cout << endl;
        cout << "输出: ";
        printVector2D(result);
        cout << endl;
        cout << "期望输出: [[8,2,3],[9,6,7],[4,5,1]]" << endl;
    }

    // 示例 2
    {
        vector<vector<int>> grid = {{0, 1}, {1, 2}};
        auto result = solution.sortMatrix(grid);
        cout << "示例2 - 输入: ";
        printVector2D(grid);
        cout << endl;
        cout << "输出: ";
        printVector2D(result);
        cout << endl;
        cout << "期望输出: [[2,1],[1,0]]" << endl;
    }

    // 示例 3
    {
        vector<vector<int>> grid = {{1}};
        auto result = solution.sortMatrix(grid);
        cout << "示例3 - 输入: ";
        printVector2D(grid);
        cout << endl;
        cout << "输出: ";
        printVector2D(result);
        cout << endl;
        cout << "期望输出: [[1]]" << endl;
    }

    return 0;
}
