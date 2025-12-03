#include <array>
#include <iostream>

static void test_empty() {
    std::cout << "[test_empty]" << std::endl;
    std::cout << std::boolalpha;

    std::array<int, 0> a = {};
    std::cout << a.empty() << std::endl;

    /* array is fixed size, empty() always returns false if size is not 0 */
    std::array<int, 5> b = {};
    std::cout << b.empty() << std::endl;
}

static void test_swap() {
    std::cout << "[test_swap]" << std::endl;

    std::array<int, 3> a = {1, 2, 3};
    auto it = a.begin() + 1;
    std::cout << *it << std::endl;

    std::array<int, 3> b = {4, 5, 6};

    /* iterators to an array are never invalidated throughout the lifetime of the array */
    a.swap(b);
    std::cout << *it << std::endl;
}

static void test_fill() {
    std::cout << "[test_fill]" << std::endl;

    std::array<int, 5> a = {};
    a.fill(10);
    for (int i : a) {
        std::cout << i << std::endl;
    }
}

static void test_to_array() {
    std::cout << "[test_to_array]" << std::endl;

    int arr[5] = {1, 2, 3, 4, 5};
    std::array<int, 5> a = std::to_array(arr);
    for (int i : a) {
        std::cout << i << std::endl;
    }
}

static void test_deduction() {
    std::cout << "[test_deduction]" << std::endl;

    std::array a = {1, 2, 3, 4, 5}; /* do not specify type and size */
    for (int i : a) {
        std::cout << i << std::endl;
    }
}

int main() {
    test_empty();
    test_swap();
    test_fill();
    test_to_array();
    test_deduction();
}