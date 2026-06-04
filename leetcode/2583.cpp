// 给你一棵二叉树的根节点 `root` 和一个正整数 `k` 。
//
// 树中的 层和 是指 同一层 上节点值的总和。
//
// 返回树中第 `k` 大的层和（不一定不同）。如果树少于 `k` 层，则返回 -1 。
//
// 注意，如果两个节点与根节点的距离相同，则认为它们在同一层。
//
//
// 示例 1：
//
// 输入：root = [5,8,9,2,1,3,7,4,6], k = 2
// 输出：13
// 解释：树中每一层的层和分别是：
// - Level 1: 5
// - Level 2: 8 + 9 = 17
// - Level 3: 2 + 1 + 3 + 7 = 13
// - Level 4: 4 + 6 = 10
// 第 2 大的层和等于 13 。
//
// 示例 2：
//
// 输入：root = [1,2,null,3], k = 1
// 输出：3
// 解释：最大的层和是 3 。
//
//
// 提示：
//
// - 树中的节点数为 `n`
// - `2 <= n <= 10^5`
// - `1 <= Node.val <= 10^6`
// - `1 <= k <= n`
//
// https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/description/

#include <algorithm>
#include <functional>

#include "check.h"
#include "utils.h"
using namespace std;

class Solution {
public:
    void dfs(TreeNode* n, vector<long long>& ans, int l) {
        if (n == nullptr)
            return;

        if (ans.size() <= l)
            ans.push_back(n->val);
        else
            ans[l] += n->val;

        dfs(n->left, ans, l + 1);
        dfs(n->right, ans, l + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans{};
        dfs(root, ans, 0);

        if (ans.size() < k)
            return -1;

        nth_element(ans.begin(), ans.begin() + k - 1, ans.end(),
                    greater<long long>());
        return ans[k - 1];
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        auto root = buildTree({5, 8, 9, 2, 1, 3, 7, 4, 6});
        auto result = solution.kthLargestLevelSum(root, 2);
        check("示例1: root=[5,8,9,2,1,3,7,4,6], k=2", result, 13LL);
        deleteTree(root);
    }

    // 示例 2
    {
        auto root = buildTree({1, 2, INT_MIN, 3});
        auto result = solution.kthLargestLevelSum(root, 1);
        check("示例2: root=[1,2,null,3], k=1", result, 3LL);
        deleteTree(root);
    }

    // 自定义用例
    {
        auto root = buildTree({705478, 839185, INT_MIN, INT_MIN, 588573,
                               INT_MIN, 776836, 630597, 5167});
        auto result = solution.kthLargestLevelSum(root, 4);
        check(
            "自定义: "
            "root=[705478,839185,null,null,588573,null,776836,630597,5167], "
            "k=4",
            result, 635764LL);
        deleteTree(root);
    }

    // 自定义用例2
    {
        auto root = buildTree({5, 8, 9, 2, 1, 3, 7});
        auto result = solution.kthLargestLevelSum(root, 4);
        check("自定义2: root=[5,8,9,2,1,3,7], k=4", result, -1LL);
        deleteTree(root);
    }

    return 0;
}
