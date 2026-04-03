#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

int get_r(int num) {
    int r{0};
    while (num) {
        r = (r << 1) + (num & 1);
        num = num >> 1;
    }
    return r;
}

class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> v{};
        v.reserve(nums.size());
        transform(nums.begin(), nums.end(), back_inserter(v),
                  [](int num) { return make_pair(get_r(num), num); });

        sort(v.begin(), v.end(),
             [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
                 if (lhs.first != rhs.first)
                     return lhs.first < rhs.first;
                 return lhs.second < rhs.second;
             });

        vector<int> ans{};
        ans.reserve(nums.size());
        transform(v.begin(), v.end(), back_inserter(ans),
                  [](const pair<int, int>& p) { return p.second; });

        return ans;
    }
};

int main() {
    Solution solution;

    // 测试用例1：示例1
    {
        vector<int> nums = {4, 5, 4};
        vector<int> result = solution.sortByReflection(nums);
        cout << "测试用例1 - 输入: [4,5,4]" << endl;
        cout << "输出: [";
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
        cout << "期望输出: [4,4,5]" << endl;
        cout << endl;
    }

    // 测试用例2：示例2
    {
        vector<int> nums = {3, 6, 5, 8};
        vector<int> result = solution.sortByReflection(nums);
        cout << "测试用例2 - 输入: [3,6,5,8]" << endl;
        cout << "输出: [";
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
        cout << "期望输出: [8,3,6,5]" << endl;
        cout << endl;
    }

    return 0;
}
