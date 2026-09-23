#include <string>

#include "doctest.h"

/* C++20 made much of <string> usable in constant expressions (P0980), so
 * simple string algorithms can run at compile time. */
constexpr std::string first_name(std::string s) {
    const std::size_t n = s.find_first_not_of(' ');
    if (n == std::string::npos) {
        return "";
    }
    return s.substr(n, s.find(' ', n) - n);
}

constexpr std::string bard() { return "William Shakespeare"; }

TEST_CASE("string: constexpr std::string operations [cpp20][strings]") {
    static_assert(first_name(bard()) == std::string("William"));

    CHECK(first_name(bard()) == "William");
    CHECK(first_name("   Ada Lovelace") == "Ada");
    CHECK(first_name("   ") == "");

    /* Related C++20 constexpr nuance: only objects with static storage have a
     * constant address, so this is fine ...
     *     static int y = 1;
     *     constexpr int* q = &y;      // OK
     * ... while taking the address of an automatic variable is not:
     *     int x = 0;
     *     constexpr int* p = &x;      // ERROR
     */
}
