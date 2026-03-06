#include <array>
#include <iostream>

static void test_to_array() {
    std::cout << "[test_to_array]" << std::endl;

    int arr[5] = {1, 2, 3, 4, 5};
    std::array<int, 5> a = std::to_array(arr);
    for (int i : a) {
        std::cout << i << std::endl;
    }
}

void run_array_20() { test_to_array(); }
