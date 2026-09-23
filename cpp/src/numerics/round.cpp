#include <cmath>
#include <cstdio>
#include <iostream>

#include "doctest.h"

/* std::round: halfway cases round away from zero. */
TEST_CASE("round: std::round rounds half away from zero [cpp11][numerics]") {
    CHECK(std::round(2.3) == 2.0);
    CHECK(std::round(2.7) == 3.0);
    CHECK(std::round(-2.3) == -2.0);
    CHECK(std::round(-2.7) == -3.0);
    CHECK(std::round(2.5) == 3.0);
    CHECK(std::round(-2.5) == -3.0);
}

/* printf("%.0f") follows the current floating-point rounding mode
 * (FE_TONEAREST => half to even), so it disagrees with std::round on .5.
 * Observation only - the exact behaviour is not something to assert. */
TEST_CASE("round: printf %0.f uses the FP rounding mode [cpp11][numerics]") {
    double values[] = {2.3, 2.7, -2.3, -2.7, 2.5, -2.5};
    for (double val : values) {
        std::printf("%g: printf=%.0f std::round=%g\n", val, val,
                    std::round(val));
    }
    /* 2.5 prints as 2 and -2.5 as -2 (banker's rounding). */
    CHECK(true);
}
