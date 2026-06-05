// 给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
//
// 只有当 `c <= a` 且 `b <= d` 时，我们才认为区间 `[a,b)` 被区间 `[c,d)` 覆盖。
//
// 在完成所有删除操作后，请你返回列表中剩余区间的数目。
//
// 示例：
// 输入：intervals = [[1,4],[3,6],[2,8]]
// 输出：2
// 解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
//
// 提示：
// - `1 <= intervals.length <= 1000`
// - `0 <= intervals[i][0] < intervals[i][1] <= 10^5`
// - 对于所有的 `i != j`：`intervals[i] != intervals[j]`
//
// https://leetcode.cn/problems/remove-covered-intervals/description/

#include <algorithm>
#include <utility>
#include <vector>

#include "check.h"
#include "utils.h"
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& i1, vector<int>& i2) {
                 if (i1[0] != i2[0])
                     return i1[0] < i2[0];
                 return i1[1] > i2[1];
             });

        int max_end{0}, ans{0};
        for (const auto& interval : intervals) {
            if (interval[1] > max_end) {
                ++ans;
                max_end = interval[1];
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // 示例
    {
        vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
        int result = solution.removeCoveredIntervals(intervals);
        check("示例: intervals=[[1,4],[3,6],[2,8]]", result, 2);
    }

    return 0;
}
