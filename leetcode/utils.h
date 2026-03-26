#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <climits>
#include <queue>
#include <vector>

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// 从LeetCode数组格式构建二叉树
// 数组格式示例: [3,1,4,3,null,1,5]
// 使用INT_MIN表示null
TreeNode* buildTree(const std::vector<int>& nodes);

// 删除二叉树，释放内存
void deleteTree(TreeNode* root);

#endif  // LEETCODE_UTILS_H
