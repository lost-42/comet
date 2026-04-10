#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size(), 0);
        ans[0] = pref[0];
        for (int i = 1; i < pref.size(); ++i) {
            ans[i] = pref[i] ^ pref[i - 1];
        }

        return ans;
    }
};

// 辅助函数：打印vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
}

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        cout << "测试用例1 - 示例1" << endl;
        vector<int> pref = {5, 2, 0, 3, 1};
        vector<int> result = solution.findArray(pref);

        cout << "输入: pref = ";
        printVector(pref);
        cout << endl;

        cout << "输出: arr = ";
        printVector(result);
        cout << endl;

        cout << "期望输出: [5,7,2,3,2]" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        cout << "测试用例2 - 示例2" << endl;
        vector<int> pref = {13};
        vector<int> result = solution.findArray(pref);

        cout << "输入: pref = ";
        printVector(pref);
        cout << endl;

        cout << "输出: arr = ";
        printVector(result);
        cout << endl;

        cout << "期望输出: [13]" << endl;
        cout << endl;
    }

    return 0;
}
