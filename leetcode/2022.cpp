#include <iostream>
#include <span>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(const vector<int>& original,
                                         int m,
                                         int n) {
        vector<vector<int>> ans{};
        int s = original.size();
        if (s != m * n)
            return ans;

        ans.reserve(m);
        for (int i = 0; i < m; ++i) {
            vector<int> v{};
            v.insert_range(v.begin(),
                           std::span{original.begin() + i * n, (size_t)n});
            ans.emplace_back(std::move(v));
        }

        return ans;
    }
};

void test(const vector<int>& v, int m, int n) {
    Solution s{};
    auto v1 = s.construct2DArray(v, m, n);
    cout << "--------\n";
    if (v1.empty()) {
        cout << "[]\n";
        return;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v1[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    test({1, 2, 3, 4}, 2, 2);
    test({1, 2, 3}, 1, 3);
    test({1, 2}, 1, 1);
    test({3}, 1, 2);
}
