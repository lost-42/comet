#include "utils.h"

#include <iostream>
#include <queue>
#include <vector>

TreeNode* buildTree(const std::vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == INT_MIN)
        return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // 左子节点
        if (i < nodes.size() && nodes[i] != INT_MIN) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        // 右子节点
        if (i < nodes.size() && nodes[i] != INT_MIN) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void deleteTree(TreeNode* root) {
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// 打印一维vector
void printVector(const std::vector<int>& vec) {
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
void printVector2D(const std::vector<std::vector<int>>& vec) {
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
