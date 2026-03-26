#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        static constexpr int OFFSET = 1950;

        array<int, 101> years{};

        for (const auto& log : logs) {
            ++years[log[0] - OFFSET];
            --years[log[1] - OFFSET];
        }

        int ans = 0, cnt = 0, mCnt = 0;
        for (int i = 0; i < 101; ++i) {
            cnt += years[i];
            if (cnt > mCnt) {
                ans = i + OFFSET;
                mCnt = cnt;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<vector<int>> logs = {{1993, 1999}, {2000, 2010}};
    cout << s.maximumPopulation(logs) << endl;

    vector<vector<int>> logs2 = {{1950, 1961}, {1960, 1971}, {1970, 1981}};
    cout << s.maximumPopulation(logs2) << endl;

    vector<vector<int>> logs3 = {{2000, 2001}};
    cout << s.maximumPopulation(logs3) << endl;

    vector<vector<int>> logs4 = {{2008, 2026}, {2004, 2008}, {2034, 2035},
                                 {1999, 2050}, {2049, 2050}, {2011, 2035},
                                 {1966, 2033}, {2044, 2049}};
    cout << s.maximumPopulation(logs4) << endl;

    return 0;
}
