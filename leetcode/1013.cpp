// 给你一个整数数组 `arr`，只有可以将其划分为三个和相等的 非空 部分时才返回 `true`，否则返回 `false`。
//
// 形式上，如果可以找出索引 `i + 1 < j` 且满足 `(arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])` 就可以将数组三等分。
//
//
// 示例 1：
//
// 输入：arr = [0,2,1,-6,6,-7,9,1,2,0,1]
// 输出：true
// 解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
//
// 示例 2：
//
// 输入：arr = [0,2,1,-6,6,7,9,-1,2,0,1]
// 输出：false
//
// 示例 3：
//
// 输入：arr = [3,3,6,5,-2,2,5,1,-9,4]
// 输出：true
// 解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
//
//
// 提示：
//
// - `3 <= arr.length <= 5 * 10^4`
// - `-10^4 <= arr[i] <= 10^4`
//
// https://leetcode.cn/problems/partition-array-into-three-parts-with-equal-sum/description/

#include <numeric>

#include "check.h"
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int tSum = accumulate(arr.begin(), arr.end(), 0);
        if (tSum % 3 != 0)
            return false;
        int trg = tSum / 3;
        int n{0}, pSum{0};

        for (auto it = arr.begin(); it != arr.end(); ++it) {
            int v = *it;
            pSum += v;
            if (pSum == trg) {
                ++n;
                pSum = 0;
            }
            if (n == 2 && it + 1 != arr.end())
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        vector<int> arr = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
        auto result = solution.canThreePartsEqualSum(arr);
        check("示例1: arr=[0,2,1,-6,6,-7,9,1,2,0,1]", result, true);
    }

    // 示例 2
    {
        vector<int> arr = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
        auto result = solution.canThreePartsEqualSum(arr);
        check("示例2: arr=[0,2,1,-6,6,7,9,-1,2,0,1]", result, false);
    }

    // 示例 3
    {
        vector<int> arr = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
        auto result = solution.canThreePartsEqualSum(arr);
        check("示例3: arr=[3,3,6,5,-2,2,5,1,-9,4]", result, true);
    }

    // [1,-1,1,-1]
    {
        vector<int> arr = {1, -1, 1, -1};
        auto result = solution.canThreePartsEqualSum(arr);
        check("arr=[1,-1,1,-1]", result, false);
    }

    return 0;
}
