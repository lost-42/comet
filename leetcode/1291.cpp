// 我们定义「顺次数」为：每一位上的数字都比前一位上的数字大 `1` 的整数。
//
// 请你返回由 `[low, high]` 范围内所有顺次数组成的 有序 列表（从小到大排序）。
//
//
// 示例 1：
//
// 输入：low = 100, high = 300
// 输出：[123,234]
//
// 示例 2：
//
// 输入：low = 1000, high = 13000
// 输出：[1234,2345,3456,4567,5678,6789,12345]
//
//
// 提示：
//
// - `10 <= low <= high <= 10^9`
//
// https://leetcode.cn/problems/sequential-digits/description/

#include <algorithm>
#include <vector>

#include "check.h"
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        static int arr[] = {
            12,      23,      34,      45,       56,       67,
            78,      89,      123,     234,      345,      456,
            567,     678,     789,     1234,     2345,     3456,
            4567,    5678,    6789,    12345,    23456,    34567,
            45678,   56789,   123456,  234567,   345678,   456789,
            1234567, 2345678, 3456789, 12345678, 23456789, 123456789};

        auto it1 = lower_bound(arr, arr + sizeof(arr) / sizeof(int), low);
        auto it2 = upper_bound(arr, arr + sizeof(arr) / sizeof(int), high);

        return vector<int>(it1, it2);
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        int low = 100, high = 300;
        auto result = solution.sequentialDigits(low, high);
        check("示例1: low=100, high=300", result, vector<int>{123, 234});
    }

    // 示例 2
    {
        int low = 1000, high = 13000;
        auto result = solution.sequentialDigits(low, high);
        check("示例2: low=1000, high=13000", result,
              vector<int>{1234, 2345, 3456, 4567, 5678, 6789, 12345});
    }

    // 自定义测试：全范围
    {
        int low = 10, high = 1000000000;
        auto result = solution.sequentialDigits(low, high);
        check("全范围: low=10, high=1000000000", result,
              vector<int>{
                  12,      23,      34,      45,       56,       67,
                  78,      89,      123,     234,      345,      456,
                  567,     678,     789,     1234,     2345,     3456,
                  4567,    5678,    6789,    12345,    23456,    34567,
                  45678,   56789,   123456,  234567,   345678,   456789,
                  1234567, 2345678, 3456789, 12345678, 23456789, 123456789});
    }

    return 0;
}
