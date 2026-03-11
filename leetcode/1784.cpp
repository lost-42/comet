#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(const string& s) {
        if (s.empty())
            return true;

        int oneCnt = (s[0] == '1') ? 1 : 0;
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == '1' && s[i - 1] == '0') {
                ++oneCnt;
            }
            if (oneCnt > 1)
                return false;
        }

        return oneCnt <= 1;
    }
};

int main() {
    Solution s{};
    std::cout << s.checkOnesSegment("1001") << std::endl;  // 应该输出0 (false)
    std::cout << s.checkOnesSegment("110") << std::endl;   // 应该输出1 (true)
    std::cout << s.checkOnesSegment("1") << std::endl;     // 应该输出1 (true)
    std::cout << s.checkOnesSegment("10") << std::endl;    // 应该输出1 (true)
    std::cout << s.checkOnesSegment("101") << std::endl;   // 应该输出0 (false)
}
