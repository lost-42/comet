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
template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]";
}
// 打印二维vector
template <typename T>
void printVector2D(const std::vector<std::vector<T>>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < vec[i].size(); j++) {
            std::cout << vec[i][j];
            if (j < vec[i].size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i < vec.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]";
}

#endif  // LEETCODE_UTILS_H
