// 给你一个整数 `num`。
//
// 如果一个数 `num` 的每一个 前缀 和每一个 后缀 都是 质数，则称该数为 完全质数。
//
// 如果 `num` 是完全质数，返回 `true`，否则返回 `false`。
//
// 注意：
//
// - 一个数的 前缀 是由该数的 前 `k` 位数字构成的。
// - 一个数的 后缀 是由该数的 后 `k` 位数字构成的。
// - 质数 是大于 1 且只有两个因子（1 和它本身）的自然数。
// - 个位数只有在它是 质数 时才被视为完全质数。
//
// 示例 1：
//
// 输入：num = 23
// 输出：true
// 解释：
// - `num = 23` 的前缀是 2 和 23，它们都是质数。
// - `num = 23` 的后缀是 3 和 23，它们都是质数。
// - 所有的前缀和后缀都是质数，所以 23 是完全质数，答案是 `true`。
//
// 示例 2：
//
// 输入：num = 39
// 输出：false
// 解释：
// - `num = 39` 的前缀是 3 和 39。3 是质数，但 39 不是质数。
// - `num = 39` 的后缀是 9 和 39。9 和 39 都不是质数。
// - 至少有一个前缀或后缀不是质数，所以 39 不是完全质数，答案是 `false`。
//
// 示例 3：
//
// 输入：num = 7
// 输出：true
// 解释：
// - 7 是质数，所以它的所有前缀和后缀都是质数，答案是 `true`。
//
// 提示：
//
// - `1 <= num <= 10^9`
//
// https://leetcode.cn/problems/complete-prime-number/description/

#include "check.h"
using namespace std;

class Solution {
public:
    bool completePrime(int num) {
        return false;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        int num = 23;
        bool result = solution.completePrime(num);
        check("示例1: num=23", result, true);
    }

    // 示例 2
    {
        int num = 39;
        bool result = solution.completePrime(num);
        check("示例2: num=39", result, false);
    }

    // 示例 3
    {
        int num = 7;
        bool result = solution.completePrime(num);
        check("示例3: num=7", result, true);
    }

    return 0;
}
