// 给你 3 个正整数 zero ，one 和 limit 。

// 一个 二进制数组 arr 如果满足以下条件，那么我们称它是 稳定的 ：

// 0 在 arr 中出现次数 恰好 为 zero 。
// 1 在 arr 中出现次数 恰好 为 one 。
// arr 中每个长度超过 limit 的 子数组 都 同时 包含 0 和 1 。
// 请你返回 稳定 二进制数组的 总 数目。

// 由于答案可能很大，将它对 10^9 + 7 取余 后返回。

// 示例 1：

// 输入：zero = 1, one = 1, limit = 2

// 输出：2

// 解释：

// 两个稳定的二进制数组为 [1,0] 和 [0,1] ，两个数组都有一个 0 和一个 1
// ，且没有子数组长度大于 2 。

// 示例 2：

// 输入：zero = 1, one = 2, limit = 1

// 输出：1

// 解释：

// 唯一稳定的二进制数组是 [1,0,1] 。

// 二进制数组 [1,1,0] 和 [0,1,1] 都有长度为 2
// 且元素全都相同的子数组，所以它们不稳定。

// 示例 3：

// 输入：zero = 3, one = 3, limit = 2

// 输出：14

// 解释：

// 所有稳定的二进制数组包括 [0,0,1,0,1,1] ，[0,0,1,1,0,1] ，[0,1,0,0,1,1]
// ，[0,1,0,1,0,1] ，[0,1,0,1,1,0] ，[0,1,1,0,0,1] ，[0,1,1,0,1,0]
// ，[1,0,0,1,0,1] ，[1,0,0,1,1,0] ，[1,0,1,0,0,1] ，[1,0,1,0,1,0]
// ，[1,0,1,1,0,0] ，[1,1,0,0,1,0] 和 [1,1,0,1,0,0] 。

// 提示：

// 1 <= zero, one, limit <= 200
//

import <string>;
import <iostream>;
import <vector>;
import <cmath>;

class Solution {
public:
    void impl(int zero, int one, int limit, std::vector<int>& vec) {
        // std::cout << zero << ',' << one << std::endl;
        // for (int v : vec) {
        //     std::cout << v << ',';
        // }
        // std::cout << std::endl;
        // std::cout << "-----------------\n";

        if (vec.size() > limit) {
            int v = vec.back();
            size_t s = vec.size();
            bool all_same = true;
            for (int i = 0; i <= limit; ++i) {
                if (vec[s - i - 1] != v) {
                    all_same = false;
                    break;
                }
            }
            if (all_same) {
                return;
            }
        }

        if (zero + one < limit) {
            cnt += (long long)pow(2, (zero + one));
            return;
        }

        if (zero == 0 && one == 0)
        {
            ++cnt;
            return;
        }

        if (zero > 0) {
            vec.push_back(0);
            impl(zero - 1, one, limit, vec);
            vec.pop_back();
        }
        if (one > 0) {
            vec.push_back(1);
            impl(zero, one - 1, limit, vec);
            vec.pop_back();
        }
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        cnt = 0;
        std::vector<int> vec{};
        vec.reserve(zero + one);

        impl(zero, one, limit, vec);
        return cnt % (1'000'000'007);
    }

private:
    long long cnt{0};
};

int main() {
    Solution s{};
    std::cout << s.numberOfStableArrays(1, 1, 2) << std::endl;
    std::cout << s.numberOfStableArrays(1, 2, 1) << std::endl;
    std::cout << s.numberOfStableArrays(3, 3, 2) << std::endl;
    std::cout << s.numberOfStableArrays(13, 20, 93) << std::endl;
}
