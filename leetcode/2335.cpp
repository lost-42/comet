#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    bool allZero(const vector<int>& amount) {
        return amount[0] == 0 && amount[1] == 0 && amount[2] == 0;
    }

    int fillCups(vector<int>& amount) {
        int ans{0};

        while (!allZero(amount)) {
            ++ans;

            sort(amount.begin(), amount.end(), greater<int>());

            --amount[0];
            if (amount[1])
                --amount[1];
        }

        return ans;
    }
};

// 测试主函数
int main() {
    Solution solution;

    // 测试示例1
    std::cout << "测试示例1:" << std::endl;
    std::vector<int> amount1 = {1, 4, 2};
    std::cout << "输入: amount = ";
    printVector(amount1);
    std::cout << std::endl;
    int result1 = solution.fillCups(amount1);
    std::cout << "预期输出: 4" << std::endl;
    std::cout << "实际输出: " << result1 << std::endl;
    std::cout << std::endl;

    // 测试示例2
    std::cout << "测试示例2:" << std::endl;
    std::vector<int> amount2 = {5, 4, 4};
    std::cout << "输入: amount = ";
    printVector(amount2);
    std::cout << std::endl;
    int result2 = solution.fillCups(amount2);
    std::cout << "预期输出: 7" << std::endl;
    std::cout << "实际输出: " << result2 << std::endl;
    std::cout << std::endl;

    // 测试示例3
    std::cout << "测试示例3:" << std::endl;
    std::vector<int> amount3 = {5, 0, 0};
    std::cout << "输入: amount = ";
    printVector(amount3);
    std::cout << std::endl;
    int result3 = solution.fillCups(amount3);
    std::cout << "预期输出: 5" << std::endl;
    std::cout << "实际输出: " << result3 << std::endl;
    std::cout << std::endl;

    return 0;
}
