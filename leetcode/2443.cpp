// 给你一个 非负 整数 num 。如果存在某个 非负 整数 k 满足
// k + reverse(k) = num ，则返回 true ；否则，返回 false 。
//
// reverse(k) 表示 k 反转每个数位后得到的数字。
//
// 示例 1：
// 输入：num = 443
// 输出：true
// 解释：172 + 271 = 443 ，所以返回 true 。
//
// 示例 2：
// 输入：num = 63
// 输出：false
// 解释：63 不能表示为非负整数及其反转后数字之和，返回 false 。
//
// 示例 3：
// 输入：num = 181
// 输出：true
// 解释：140 + 041 = 181 ，所以返回 true 。注意，反转后的数字可能包含前导零。
//
// 提示：
// - 0 <= num <= 10^5
//
// https://leetcode.cn/problems/sum-of-number-and-its-reverse/description/

#include <string>

#include "check.h"
using namespace std;

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = num; i >= 0; --i) {
            int n2{0};
            int ti = i;
            while (ti) {
                n2 = n2 * 10 + (ti % 10);
                ti /= 10;
            }

            if (num == i + n2)
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        bool result = solution.sumOfNumberAndReverse(443);
        check("示例1: num=443", result, true);
    }

    // 示例 2
    {
        bool result = solution.sumOfNumberAndReverse(63);
        check("示例2: num=63", result, false);
    }

    // 示例 3
    {
        bool result = solution.sumOfNumberAndReverse(181);
        check("示例3: num=181", result, true);
    }

    // 自定义用例
    {
        bool result = solution.sumOfNumberAndReverse(19998);
        check("自定义: num=19998", result, true);
    }

    return 0;
}
