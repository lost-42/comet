// 给你一个二进制字符串 s ，该字符串 不含前导零 。

// 如果 s 包含 零个或一个由连续的 '1' 组成的字段 ，返回
// true​​​ 。否则，返回 false 。

// 示例 1：

// 输入：s = "1001"
// 输出：false
// 解释：由连续若干个 '1' 组成的字段数量为 2，返回 false
// 示例 2：

// 输入：s = "110"
// 输出：true

// 提示：

// 1 <= s.length <= 100
// s[i]​​​​ 为 '0' 或 '1'
// s[0] 为 '1'

import <string>;
import <iostream>;

using namespace std;

class Solution {
public:
  bool checkOnesSegment(const string &s) {
    if (s.empty())
      return true;

    int oneCnt = (s[0] == '1') ? 1 : 0;
    for (int i = 1; i < s.size(); ++i) {
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
  std::cout << s.checkOnesSegment("1001") << std::endl; // 应该输出0 (false)
  std::cout << s.checkOnesSegment("110") << std::endl;  // 应该输出1 (true)
  std::cout << s.checkOnesSegment("1") << std::endl;    // 应该输出1 (true)
  std::cout << s.checkOnesSegment("10") << std::endl;   // 应该输出1 (true)
  std::cout << s.checkOnesSegment("101") << std::endl;  // 应该输出0 (false)
}
