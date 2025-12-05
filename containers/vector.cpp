#include <iostream>
#include <vector>

static void test_vector_bool() {
    std::cout << "[test_vector_bool]" << std::endl;

    std::vector<bool> v{true, false, true};
    auto b = v[1];
    std::cout << typeid(b).name() << " " << b << std::endl;
}

static void test_erase() {
    std::cout << "[test_erase]" << std::endl;

    std::vector<int> v{1, 2, 3, 4, 5};
    auto it = v.begin();
    auto it1 = v.begin() + 2;
    auto it2 = v.begin() + 4;

    std::cout << *it1 << ' ' << *it2 << std::endl;

    std::cout << &(*it) << std::endl;
    std::cout << &(*it1) << std::endl;
    std::cout << &(*it2) << std::endl;

    /* it1 and it2 are invalid after erase */
    v.erase(it);
    std::cout << *it1 << ' ' << *it2 << std::endl;

    std::cout << &(*it) << std::endl;
    std::cout << &(*it1) << std::endl;
    std::cout << &(*it2) << std::endl; /* out-of-bounds access */
}

static void test_auto_resize() {
    std::cout << "[test_auto_resize]" << std::endl;

    int s = 0;
    int sum = 0;
    std::vector<int> v{};
    for (int i = 0; i < 200; ++i) {
        v.push_back(i);
        if (s != v.capacity()) {
            s = v.capacity();
            sum += s;
            std::cout << "capacity: " << s << std::endl;
            std::cout << "sum: " << sum << std::endl;
        }
    }
}

static void test_growth() {
    std::cout << "[test_growth]" << std::endl;

    struct S {
        S(int v) : v(v) {
        }

        S(const S& s) {
            std::cout << "copy constructor" << std::endl;
            v = s.v;
        }

        /* move constructor must with noexcept, otherwise vector will use copy constructor when growth */
        S(S&& s) noexcept {
            std::cout << "move constructor" << std::endl;
            v = s.v;
        }

        int v{0};
    };

    std::vector<S> v{};
    for (int i = 0; i < 6; ++i) {
        v.push_back(S{i});
    }
}

int main() {
    test_vector_bool();
    test_erase();
    test_auto_resize();
    test_growth();
}