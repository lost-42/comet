// 网站域名 `"discuss.leetcode.com"` 由多个子域名组成。顶级域名为 `"com"` ，二级域名为 `"leetcode.com"` ，最低一级为 `"discuss.leetcode.com"` 。当访问域名 `"discuss.leetcode.com"` 时，同时也会隐式访问其父域名 `"leetcode.com"` 以及 `"com"` 。
//
// 计数配对域名 是遵循 `"rep d1.d2.d3"` 或 `"rep d1.d2"` 格式的一个域名表示，其中 `rep` 表示访问域名的次数，`d1.d2.d3` 为域名本身。
//
// - 例如，`"9001 discuss.leetcode.com"` 就是一个 计数配对域名 ，表示 `discuss.leetcode.com` 被访问了 `9001` 次。
//
// 给你一个 计数配对域名 组成的数组 `cpdomains` ，解析得到输入中每个子域名对应的 计数配对域名 ，并以数组形式返回。可以按 任意顺序 返回答案。
//
// 示例 1：
//
// 输入：cpdomains = ["9001 discuss.leetcode.com"]
// 输出：["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
// 解释：例子中仅包含一个网站域名："discuss.leetcode.com"。
// 按照前文描述，子域名 "leetcode.com" 和 "com" 都会被访问，所以它们都被访问了 9001 次。
//
// 示例 2：
//
// 输入：cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
// 输出：["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
// 解释：按照前文描述，会访问 "google.mail.com" 900 次，"yahoo.com" 50 次，"intel.mail.com" 1 次，"wiki.org" 5 次。
// 而对于父域名，会访问 "mail.com" 900 + 1 = 901 次，"com" 900 + 50 + 1 = 951 次，和 "org" 5 次。
//
// 提示：
//
// - `1 <= cpdomain.length <= 100`
// - `1 <= cpdomain[i].length <= 100`
// - `cpdomain[i]` 会遵循 `"rep_i d1_i.d2_i.d3_i"` 或 `"rep_i d1_i.d2_i"` 格式
// - `rep_i` 是范围 `[1, 10^4]` 内的一个整数
// - `d1_i`、`d2_i` 和 `d3_i` 由小写英文字母组成
//
// https://leetcode.cn/problems/subdomain-visit-count/description/

#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "check.h"
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m{};
        for (string& d : cpdomains) {
            int cnt{0}, i{0};
            while (isdigit(d[i])) {
                cnt = cnt * 10 + (d[i] - '0');
                ++i;
            }
            ++i;

            int j{i};
            while (d[j] != '\0') {
                if (d[j - 1] == '.' || d[j - 1] == ' ') {
                    m[d.substr(j)] += cnt;
                }
                ++j;
            }
        }

        vector<string> ans{};
        for (const auto& [d, c] : m) {
            ans.push_back(to_string(c) + ' ' + d);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // 示例 1
    {
        vector<string> cpdomains = {"9001 discuss.leetcode.com"};
        auto result = solution.subdomainVisits(cpdomains);
        vector<string> expected = {"9001 leetcode.com",
                                   "9001 discuss.leetcode.com", "9001 com"};
        sort(result.begin(), result.end());
        sort(expected.begin(), expected.end());
        check("示例1", result, expected);
    }

    // 示例 2
    {
        vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com",
                                    "1 intel.mail.com", "5 wiki.org"};
        auto result = solution.subdomainVisits(cpdomains);
        vector<string> expected = {
            "901 mail.com", "50 yahoo.com", "900 google.mail.com",
            "5 wiki.org",   "5 org",        "1 intel.mail.com",
            "951 com"};
        sort(result.begin(), result.end());
        sort(expected.begin(), expected.end());
        check("示例2", result, expected);
    }

    return 0;
}
