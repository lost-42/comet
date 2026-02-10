#include <string>

constexpr std::string firstName(std::string s) {
    size_t n = s.find_first_not_of(' ');
    if (n == s.npos)
        return "";
    return s.substr(n, s.find(' ', n) - n);
}
constexpr std::string bard() { return "William Shakespeare"; }

void run_string_20() {
    static_assert(firstName(bard()) == std::string("William"));

    int x = 0;
    static int y = 1;
    // constexpr int* p = &x;                    // Error
    constexpr int* q = &y;  // OK
    // constexpr intptr_t r = intptr_t(q) * 47;  // Error
}
