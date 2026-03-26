#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MIN, ans);
        return ans;
    }

    void dfs(TreeNode* node, int maxV, int& ans) {
        if (node == nullptr)
            return;

        int oldMaxV = maxV;
        if (node->val >= maxV) {
            maxV = node->val;
            ++ans;
        }

        dfs(node->left, maxV, ans);
        dfs(node->right, maxV, ans);
        maxV = oldMaxV;
    }
};

// 测试主函数
int main() {
    Solution solution;

    // 测试示例1: [3,1,4,3,null,1,5]
    cout << "测试示例1:" << endl;
    vector<int> nodes1 = {3, 1, 4, 3, INT_MIN, 1, 5};
    TreeNode* root1 = buildTree(nodes1);
    int result1 = solution.goodNodes(root1);
    cout << "输入: [3,1,4,3,null,1,5]" << endl;
    cout << "预期输出: 4" << endl;
    cout << "实际输出: " << result1 << endl;
    cout << endl;
    deleteTree(root1);

    // 测试示例2: [3,3,null,4,2]
    cout << "测试示例2:" << endl;
    vector<int> nodes2 = {3, 3, INT_MIN, 4, 2};
    TreeNode* root2 = buildTree(nodes2);
    int result2 = solution.goodNodes(root2);
    cout << "输入: [3,3,null,4,2]" << endl;
    cout << "预期输出: 3" << endl;
    cout << "实际输出: " << result2 << endl;
    cout << endl;
    deleteTree(root2);

    // 测试示例3: [-1,5,-2,4,4,2,-2,null,null,-4,null,-2,3,null,-2,0,null,-1,null,-3,null,-4,-3,3,null,null,null,null,null,null,null,3,-3]
    cout << "测试示例3:" << endl;
    vector<int> nodes3 = {-1,      5,       -2,      4,       4,       2,
                          -2,      INT_MIN, INT_MIN, -4,      INT_MIN, -2,
                          3,       INT_MIN, -2,      0,       INT_MIN, -1,
                          INT_MIN, -3,      INT_MIN, -4,      -3,      3,
                          INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN,
                          INT_MIN, 3,       -3};
    TreeNode* root3 = buildTree(nodes3);
    int result3 = solution.goodNodes(root3);
    cout << "输入: "
            "[-1,5,-2,4,4,2,-2,null,null,-4,null,-2,3,null,-2,0,null,-1,null,-"
            "3,null,-4,-3,3,null,null,null,null,null,null,null,3,-3]"
         << endl;
    cout << "预期输出: 5" << endl;
    cout << "实际输出: " << result3 << endl;
    cout << endl;
    deleteTree(root3);

    return 0;
}
