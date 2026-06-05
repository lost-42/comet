// 现有一个包含所有正整数的集合 `[1, 2, 3, 4, 5, ...]`。
//
// 实现 `SmallestInfiniteSet` 类：
//
// - `SmallestInfiniteSet()` 初始化 SmallestInfiniteSet 对象以包含 所有 正整数。
// - `int popSmallest()` 移除 并返回该无限集中的最小整数。
// - `void addBack(int num)` 如果正整数 `num` 不 存在于无限集中，则将一个 `num` 添加 到该无限集中。
//
//
// 示例：
//
// 输入
// ["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
// [[], [2], [], [], [], [1], [], [], []]
// 输出
// [null, null, 1, 2, 3, null, 1, 4, 5]
//
// 解释
// SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
// smallestInfiniteSet.addBack(2);    // 2 已经在集合中，所以不做任何变更。
// smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 是最小的整数，并将其从集合中移除。
// smallestInfiniteSet.popSmallest(); // 返回 2 ，并将其从集合中移除。
// smallestInfiniteSet.popSmallest(); // 返回 3 ，并将其从集合中移除。
// smallestInfiniteSet.addBack(1);    // 将 1 添加到该集合中。
// smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 在上一步中被添加到集合中，
//                                    // 且 1 是最小的整数，并将其从集合中移除。
// smallestInfiniteSet.popSmallest(); // 返回 4 ，并将其从集合中移除。
// smallestInfiniteSet.popSmallest(); // 返回 5 ，并将其从集合中移除。
//
//
// 提示：
//
// - `1 <= num <= 1000`
// - 最多调用 `popSmallest` 和 `addBack` 方法 共计 `1000` 次
//
// https://leetcode.cn/problems/smallest-number-in-infinite-set/description/

#include <algorithm>
#include <iostream>
#include <set>

#include "check.h"
using namespace std;

class SmallestInfiniteSet {
private:
    int min{1};
    set<int> st{};

public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        int v{0};
        if (!st.empty()) {
            v = *st.begin();
            st.erase(st.begin());
        } else {
            v = min;
            ++min;
        }
        return v;
    }

    void addBack(int num) {
        if (num < min)
            st.insert(num);
    }
};

int main() {
    // 示例
    {
        SmallestInfiniteSet s;
        s.addBack(2);
        check("popSmallest() #1", s.popSmallest(), 1);
        check("popSmallest() #2", s.popSmallest(), 2);
        check("popSmallest() #3", s.popSmallest(), 3);
        s.addBack(1);
        check("popSmallest() #4", s.popSmallest(), 1);
        check("popSmallest() #5", s.popSmallest(), 4);
        check("popSmallest() #6", s.popSmallest(), 5);
    }

    return 0;
}
