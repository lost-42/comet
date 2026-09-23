#include <iostream>
#include <type_traits>
#include <utility>

#include "doctest.h"

struct s1 {
    int val{0};

    /* A user-provided converting constructor does NOT suppress the implicit
     * move constructor (only a user-declared copy/move ctor would). */
    s1(int v) : val(v) {}

    bool operator==(const s1& other) const { return val == other.val; }
};

TEST_CASE("move: implicit move constructor stays trivial [cpp11][language]") {
    static_assert(std::is_trivially_move_constructible_v<s1>);

    s1 s{1};
    s1 ss{std::move(s)};

    CHECK(ss.val == 1);
    CHECK(ss == s1{1});
}
