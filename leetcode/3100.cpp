#include <iostream>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans{numBottles};
        while (numBottles >= numExchange) {
            numBottles = numBottles - numExchange + 1;
            ++numExchange;
            ++ans;
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        int numBottles = 13;
        int numExchange = 6;
        int result = solution.maxBottlesDrunk(numBottles, numExchange);
        cout << "测试用例1 - 输入: numBottles = " << numBottles
             << ", numExchange = " << numExchange << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 15" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        int numBottles = 10;
        int numExchange = 3;
        int result = solution.maxBottlesDrunk(numBottles, numExchange);
        cout << "测试用例2 - 输入: numBottles = " << numBottles
             << ", numExchange = " << numExchange << endl;
        cout << "输出: " << result << endl;
        cout << "期望输出: 13" << endl;
    }

    return 0;
}
