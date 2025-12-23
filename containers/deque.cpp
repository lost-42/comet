#include <deque>
#include <iostream>

static void test_push_pop() {
    std::cout << "[test_push_pop]" << std::endl;

    std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(4);
    dq.push_front(5); /* 5 4 1 2 */

    std::cout << "dq: ";
    for (auto i : dq) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    dq.pop_front(); /* 4 1 2 */
    dq.pop_back();  /* 4 1 */

    std::cout << "dq: ";
    for (auto i : dq) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

static void test_memory() {
    std::cout << "[test_memory]" << std::endl;

    std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(4);
    dq.push_front(5); /* 5 4 1 2 */

    std::cout << "max size: " << dq.size() << std::endl;
    for (auto i : dq) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    test_push_pop();
    test_memory();
}
