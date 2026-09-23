#include <array>
#include <iostream>
#include <type_traits>

#include "doctest.h"

TEST_CASE("array: empty() is exactly size() == 0 [cpp11][containers]") {
    CHECK(std::array<int, 0>{}.empty());
    CHECK_FALSE(std::array<int, 5>{}.empty());
}

TEST_CASE("array: swap keeps iterators valid [cpp11][containers]") {
    std::array<int, 3> a = {1, 2, 3};
    std::array<int, 3> b = {4, 5, 6};

    auto it = a.begin() + 1;
    CHECK(*it == 2);

    /* Iterators into std::array are never invalidated for the array's
     * lifetime. After swap() the elements are exchanged, so `it` (which still
     * refers to a[1]) now observes the value that came from b[1]. */
    a.swap(b);
    CHECK(*it == 5);
    CHECK(a == (std::array<int, 3>{4, 5, 6}));
    CHECK(b == (std::array<int, 3>{1, 2, 3}));
}

TEST_CASE("array: fill() then range-for [cpp11][containers]") {
    std::array<int, 5> a = {};
    a.fill(10);
    for (int i : a) {
        CHECK(i == 10);
    }
}

TEST_CASE("array: to_array deduces type and size [cpp20][containers]") {
    /* C++17 CTAD cannot deduce std::array from a braced-init-list; C++20's
     * std::to_array is the supported replacement. */
    auto a = std::to_array<int>({1, 2, 3, 4, 5});
    static_assert(std::is_same_v<decltype(a), std::array<int, 5>>);
    CHECK(a.size() == 5);
    CHECK(a[4] == 5);
}

TEST_CASE("array: to_array copies a C array [cpp20][containers]") {
    int arr[5] = {1, 2, 3, 4, 5};
    auto a = std::to_array(arr); /* deduces std::array<int, 5> */
    static_assert(std::is_same_v<decltype(a), std::array<int, 5>>);
    CHECK(a[0] == 1);
    CHECK(a[4] == 5);
}
