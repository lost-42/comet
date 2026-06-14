// 给你一个正整数 n。
//
// 令 digitSum 表示 n 的各位数字之和，令 squareSum 表示 n 的各位数字平方之和。
//
// 如果一个整数满足 squareSum - digitSum >= 50，则称它是 好整数 。
//
// 如果 n 是好整数，返回 true；否则，返回 false。
//
//
// 示例 1：
//
// 输入： n = 1000
// 输出： false
// 解释：
// 1000 的数字为 1、0、0 和 0。
// digitSum 为 1 + 0 + 0 + 0 = 1。
// squareSum 为 1^2 + 0^2 + 0^2 + 0^2 = 1。
// squareSum - digitSum 为 1 - 1 = 0。由于 0 小于 50，因此输出 false。
//
// 示例 2：
//
// 输入： n = 19
// 输出： true
// 解释：
// 19 的数字为 1 和 9。
// digitSum 为 1 + 9 = 10。
// squareSum 为 1^2 + 9^2 = 1 + 81 = 82。
// squareSum - digitSum 为 82 - 10 = 72。由于 72 大于等于 50，因此输出 true。
//
//
// 提示：
//
// 1 <= n <= 10^9
//
// https://leetcode.cn/contest/weekly-contest-506/problems/check-good-integer/description/

#include "check.h"
using namespace std;

class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum{0}, squareSum{0};
        while (n) {
            int t = n % 10;
            digitSum += t;
            squareSum += t * t;
            n /= 10;
        }

        return squareSum - digitSum >= 50;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        bool result = solution.checkGoodInteger(1000);
        check("示例1: n=1000", result, false);
    }

    // 示例 2
    {
        bool result = solution.checkGoodInteger(19);
        check("示例2: n=19", result, true);
    }

    return 0;
}
