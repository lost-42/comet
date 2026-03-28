#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <climits>
#include <iostream>
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

// 通用打印函数
// 打印一维vector
void printVector(const std::vector<int>& vec);
// 打印二维vector
void printVector2D(const std::vector<std::vector<int>>& vec);

#endif  // LEETCODE_UTILS_H
