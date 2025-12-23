#include <algorithm>
#include <iostream>
#include <list>
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

static void test_growth_factor() {
    std::cout << "[test_growth_factor]" << std::endl;

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
        S(int v) : v(v) {}

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

static void test_insert_range() {
    std::cout << "[test_insert_range]" << std::endl;

    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<int> l{6, 7, 8};
    v.insert_range(v.begin(), l);
    for (int i : v) {
        std::cout << i << std::endl;
    }
}

static void test_append_range() {
    std::cout << "[test_append_range]" << std::endl;

    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<int> l{6, 7, 8};
    v.append_range(l);
    for (int i : v) {
        std::cout << i << std::endl;
    }
}

static void test_resize() {
    std::cout << "[test_resize]" << std::endl;

    std::vector<int> v{};
    v.resize(10);
    /* inplace modify */
    std::for_each(v.begin(), v.end(), [](int& i) { i = 10; });
    for (int i : v) {
        std::cout << i << std::endl;
    }
}

int main() {
    test_vector_bool();
    test_erase();
    test_growth_factor();
    test_growth();
    test_insert_range();
    test_append_range();
    test_resize();
}