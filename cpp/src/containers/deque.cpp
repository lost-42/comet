#include <deque>
#include <iostream>
#include <vector>

#include "doctest.h"

TEST_CASE("deque: push/pop at both ends [cpp11][containers]") {
    std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(4);
    dq.push_front(5); /* 5 4 1 2 */

    CHECK(dq == std::deque<int>({5, 4, 1, 2}));
    CHECK(dq.front() == 5);
    CHECK(dq.back() == 2);

    dq.pop_front(); /* 4 1 2 */
    dq.pop_back();  /* 4 1 */

    CHECK(dq == std::deque<int>({4, 1}));
}

TEST_CASE("deque: size vs max_size [cpp11][containers]") {
    std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(4);
    dq.push_front(5); /* 5 4 1 2 */

    std::cout << "current size: " << dq.size() << std::endl
              << "max size: " << dq.max_size() << std::endl;

    CHECK(dq.size() == 4u);
}
