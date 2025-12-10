#include <type_traits>
#include <utility>

struct s1 {
    int val{0};

    /* this makes compiler do not generate default constructor as deleted
     * but the compiler still generate move constructor
     */
    s1(int v) : val(v) {}

    bool operator==(const s1& other) const { return val == other.val; }
};

int main() {
    static_assert(std::is_trivially_move_constructible_v<s1>,
                  "s1 can be moved");

    s1 s{1};
    s1 ss{std::move(s)};
}