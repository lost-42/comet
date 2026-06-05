#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
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

// 打印二叉树（横向，root 在左，树向右生长）
void printTree(TreeNode* root);

// 二叉树转层序遍历数组（INT_MIN 表示 null，去除尾部 null）
std::vector<int> treeToVector(TreeNode* root);

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

// 二进制字符串转整数
int binaryStringToInt(const std::string& binaryStr);

// 整数转二进制字符串（固定长度）
std::string intToBinaryString(int value, size_t length);

// 整数转二进制字符串（自动长度，不含前导零）
std::string intToBinaryString(int value);

// 打印map（支持所有变体：map, unordered_map, multimap, unordered_multimap）
template <template <typename, typename, typename...> class MapType,
          typename K,
          typename V,
          typename... Args>
void printMap(const MapType<K, V, Args...>& m) {
    std::cout << "{";
    auto it = m.begin();
    while (it != m.end()) {
        std::cout << it->first << ":" << it->second;
        ++it;
        if (it != m.end()) {
            std::cout << ",";
        }
    }
    std::cout << "}";
}

// 打印queue（支持int和string类型）
template <typename T>
void printQueue(std::queue<T> q) {
    std::cout << "[";
    bool first = true;
    while (!q.empty()) {
        if (!first) {
            std::cout << ",";
        }
        std::cout << q.front();
        q.pop();
        first = false;
    }
    std::cout << "]";
}

// 打印priority_queue（支持int和string类型及自定义比较器）
template <typename T,
          typename Container = std::vector<T>,
          typename Compare = std::less<typename Container::value_type>>
void printPriorityQueue(std::priority_queue<T, Container, Compare> pq) {
    std::cout << "[";
    bool first = true;
    while (!pq.empty()) {
        if (!first) {
            std::cout << ",";
        }
        std::cout << pq.top();
        pq.pop();
        first = false;
    }
    std::cout << "]";
}

#endif  // LEETCODE_UTILS_H
