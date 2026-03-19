#include <limits>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans{numeric_limits<int>::max()};
        if (blocks.size() < k)
            return ans;

        int bCnt{0};
        for (int i = 0; i < k; ++i) {
            bCnt += (blocks[i] == 'B') ? 1 : 0;
        }
        if (bCnt == k)
            return 0;
        ans = k - bCnt;

        for (size_t i = 1; i <= blocks.size() - k; ++i) {
            char pB = blocks[i - 1], nB = blocks[i + k - 1];
            if (pB == nB)
                continue;

            if (blocks[i - 1] == 'B' && blocks[i + k - 1] == 'W')
                --bCnt;
            else
                ++bCnt;

            if (bCnt == k)
                return 0;

            ans = min<int>(ans, k - bCnt);
        }

        return ans;
    }
};

int main() {
    Solution s;

    println("{}", s.minimumRecolors("WBBWWBBWBW", 7));
    println("{}", s.minimumRecolors("WBWBBBW", 2));
}
