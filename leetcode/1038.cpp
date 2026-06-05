// 给定一个二叉搜索树 `root` (BST)，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。
//
// 提醒一下，二叉搜索树满足下列约束条件：
// - 节点的左子树仅包含键小于节点键的节点。
// - 节点的右子树仅包含键大于节点键的节点。
// - 左右子树也必须是二叉搜索树。
//
// 示例 1：
// 输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
// 输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
//
// 示例 2：
// 输入：root = [0,null,1]
// 输出：[1,null,1]
//
// 提示：
// - 树中的节点数在 [1, 100] 范围内。
// - 0 <= Node.val <= 100
// - 树中的所有值均不重复。
//
// 注意：该题目与 538: https://leetcode.cn/problems/convert-bst-to-greater-tree/ 相同
//
// https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/description/

#include "check.h"
#include "utils.h"
using namespace std;

class Solution {
public:
    void dfs(TreeNode* n, int& sum) {
        if (n == nullptr)
            return;

        dfs(n->right, sum);
        sum += n->val;
        n->val = sum;
        dfs(n->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum{0};
        dfs(root, sum);
        return root;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        auto root = buildTree({4, 1, 6, 0, 2, 5, 7, INT_MIN, INT_MIN, INT_MIN,
                               3, INT_MIN, INT_MIN, INT_MIN, 8});
        cout << "输入树:" << endl;
        printTree(root);

        auto result = solution.bstToGst(root);

        cout << "输出树:" << endl;
        printTree(result);

        check("示例1: root=[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]",
              treeToVector(result),
              vector<int>{30, 36, 21, 36, 35, 26, 15, INT_MIN, INT_MIN, INT_MIN,
                          33, INT_MIN, INT_MIN, INT_MIN, 8});
        deleteTree(root);
    }

    // 示例 2
    {
        auto root = buildTree({0, INT_MIN, 1});
        cout << "输入树:" << endl;
        printTree(root);

        auto result = solution.bstToGst(root);

        cout << "输出树:" << endl;
        printTree(result);

        check("示例2: root=[0,null,1]", treeToVector(result),
              vector<int>{1, INT_MIN, 1});
        deleteTree(root);
    }

    return 0;
}
