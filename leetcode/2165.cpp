#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0)
            return 0;

        bool ltZero = num < 0;
        if (ltZero)
            num = -num;

        std::vector<int> nv{};
        while (num) {
            nv.push_back(num % 10);
            num /= 10;
        }

        std::sort(nv.begin(), nv.end());
        long long ans{0};
        if (ltZero) {
            for (auto it = nv.rbegin(); it != nv.rend(); ++it)
                ans = ans * 10 + *it;

            return -ans;
        } else {
            auto it = nv.begin();
            while (*it == 0)
                ++it;

            ans = *it;
            for (auto it1 = nv.begin(); it1 != it; ++it1)
                ans = ans * 10;
            for (auto it2 = it + 1; it2 != nv.end(); ++it2)
                ans = ans * 10 + *it2;

            return ans;
        }
    }
};

// 测试用例
int main() {
    Solution solution;

    // 测试用例1：示例1
    long long num1 = 310;
    long long result1 = solution.smallestNumber(num1);
    std::cout << "Test 1 - Input: " << num1
              << ", Expected: 103, Output: " << result1 << std::endl;

    // 测试用例2：示例2
    long long num2 = -7605;
    long long result2 = solution.smallestNumber(num2);
    std::cout << "Test 2 - Input: " << num2
              << ", Expected: -7650, Output: " << result2 << std::endl;

    return 0;
}
