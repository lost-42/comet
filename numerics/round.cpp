#include <cmath>
#include <cstdio>
#include <iostream>

void test_round() {
    std::cout << "[test_round]" << std::endl;

    double values[] = {2.3, 2.7, -2.3, -2.7, 2.5, -2.5};
    for (double val : values) {
        std::cout << std::round(val) << std::endl;
        printf("%.0f\n", val);
    }
}

void run_round() { test_round(); }
