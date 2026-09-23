#include <algorithm>
#include <iostream>
#include <list>
#include <type_traits>
#include <typeinfo>
#include <vector>

#include "doctest.h"

TEST_CASE("vector<bool>: operator[] returns a proxy, not bool [cpp11][containers]") {
    std::vector<bool> v{true, false, true};
    auto b = v[1];
    static_assert(!std::is_same_v<decltype(b), bool>);

    std::cout << "v[1] is " << static_cast<bool>(b) << " (" << typeid(b).name()
              << ")\n";
    CHECK_FALSE(static_cast<bool>(b));
}

TEST_CASE("vector: erase invalidates iterators [cpp11][containers]") {
    std::vector<int> v{1, 2, 3, 4, 5};

    auto it = v.begin(); /* points at the erased element */
    v.erase(it);

    CHECK(v == std::vector<int>{2, 3, 4, 5});

#ifdef DEMO_UB
    /* DANGER: reading an invalidated iterator is undefined behaviour. In an
     * MSVC Debug build the checked-iterator assertion aborts here, which
     * would also kill the rest of the run - that is why it is opt-in. Build
     * with -DDEMO_UB when you explicitly want to observe it. */
    std::cout << "stale: " << *it << std::endl;
#endif
}

TEST_CASE("vector: capacity growth factor is implementation-defined [cpp11][containers]") {
    std::vector<int> v;
    std::size_t last = 0;
    for (int i = 0; i < 200; ++i) {
        v.push_back(i);
        if (last != v.capacity()) {
            last = v.capacity();
            std::cout << "capacity: " << last << std::endl;
        }
    }
    CHECK(last >= 200u);
}

TEST_CASE("vector: growth moves elements only if the move ctor is noexcept [cpp11][containers]") {
    struct S {
        explicit S(int v) : v(v) {}

        S(const S& s) {
            std::cout << "copy ctor\n";
            v = s.v;
        }

        /* Without noexcept, std::vector falls back to the copy ctor while
         * growing, because it must keep the strong exception guarantee. */
        S(S&& s) noexcept {
            std::cout << "move ctor\n";
            v = s.v;
        }

        int v{0};
    };

    std::vector<S> v;
    for (int i = 0; i < 6; ++i) {
        v.push_back(S{i});
    }
    CHECK(v.size() == 6u);
}

TEST_CASE("vector: insert_range copies a range in the middle [cpp23][containers]") {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<int> l{6, 7, 8};

    v.insert_range(v.begin(), l);

    CHECK(v == std::vector<int>{6, 7, 8, 1, 2, 3, 4, 5});
}

TEST_CASE("vector: append_range appends a range [cpp23][containers]") {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<int> l{6, 7, 8};

    v.append_range(l);

    CHECK(v == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
}

TEST_CASE("vector: resize value-initialises new elements [cpp11][containers]") {
    std::vector<int> v;
    v.resize(10);
    for (int i : v) {
        CHECK(i == 0);
    }

    /* In-place mutation via a lambda. */
    std::for_each(v.begin(), v.end(), [](int& i) { i = 10; });
    for (int i : v) {
        CHECK(i == 10);
    }
}
