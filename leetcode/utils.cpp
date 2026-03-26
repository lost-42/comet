#include "utils.h"

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
