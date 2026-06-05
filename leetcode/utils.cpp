#include "utils.h"

#include <algorithm>
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

static void printTreeHelper(TreeNode* node, const std::string& prefix,
                            bool isLeft) {
    if (!node) return;

    // 先打印右子树（显示在上方）
    if (node->right)
        printTreeHelper(node->right,
                        prefix + (isLeft ? "│   " : "    "), false);

    // 打印当前节点
    std::cout << prefix;
    if (prefix.empty()) {
        std::cout << "── ";
    } else {
        std::cout << (isLeft ? "└── " : "┌── ");
    }
    std::cout << node->val << std::endl;

    // 再打印左子树（显示在下方）
    if (node->left)
        printTreeHelper(node->left,
                        prefix + (isLeft ? "    " : "│   "), true);
}

void printTree(TreeNode* root) {
    if (!root) {
        std::cout << "(null)" << std::endl;
        return;
    }
    printTreeHelper(root, "", true);
}

std::vector<int> treeToVector(TreeNode* root) {
    std::vector<int> v;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto* n = q.front();
        q.pop();
        if (n) {
            v.push_back(n->val);
            q.push(n->left);
            q.push(n->right);
        } else {
            v.push_back(INT_MIN);
        }
    }
    while (!v.empty() && v.back() == INT_MIN) v.pop_back();
    return v;
}

// 二进制字符串转整数
int binaryStringToInt(const std::string& binaryStr) {
    int value = 0;
    for (size_t i = 0; i < binaryStr.size(); ++i) {
        value = (value << 1) + (binaryStr[i] - '0');
    }
    return value;
}

// 整数转二进制字符串（固定长度）
std::string intToBinaryString(int value, size_t length) {
    if (value == 0) {
        return std::string(length, '0');
    }

    std::string result;
    while (value > 0) {
        result.push_back((value & 1) + '0');
        value >>= 1;
    }

    // 添加前导零以达到指定长度
    while (result.size() < length) {
        result.push_back('0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

// 整数转二进制字符串（自动长度，不含前导零）
std::string intToBinaryString(int value) {
    if (value == 0) {
        return "0";
    }

    std::string result;
    while (value > 0) {
        result.push_back((value & 1) + '0');
        value >>= 1;
    }

    std::reverse(result.begin(), result.end());
    return result;
}
