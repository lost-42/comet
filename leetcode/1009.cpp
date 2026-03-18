#include <iostream>

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        int ans = 0;
        int p = 0;
        while (n > 0) {
            int t = !(n & 1);
            ans += t << p;
            n = n >> 1;
            ++p;
        }

        return ans;
    }
};

int main() {
    Solution s{};

    std::cout << s.bitwiseComplement(5) << std::endl;
    std::cout << s.bitwiseComplement(7) << std::endl;
    std::cout << s.bitwiseComplement(10) << std::endl;
}
