#ifndef LEETCODE_CHECK_H
#define LEETCODE_CHECK_H

#include <iostream>
#include <string>

#include "utils.h"

// 通用比较（int, bool, string, double 等有 == 和 << 的类型）
template <typename T>
bool check(const std::string& label, const T& actual, const T& expected) {
    if (actual == expected) {
        std::cout << "[🟢 PASS] " << label << std::endl;
        return true;
    }
    std::cout << "[🔴 FAIL] " << label << std::endl;
    std::cout << "  期望: " << expected << std::endl;
    std::cout << "  实际: " << actual << std::endl;
    return false;
}

// vector<T> 版本 — 用 printVector 输出
template <typename T>
bool check(const std::string& label,
           const std::vector<T>& actual,
           const std::vector<T>& expected) {
    if (actual == expected) {
        std::cout << "[🟢 PASS] " << label << std::endl;
        return true;
    }
    std::cout << "[🔴 FAIL] " << label << std::endl;
    std::cout << "  期望: ";
    printVector(expected);
    std::cout << std::endl;
    std::cout << "  实际: ";
    printVector(actual);
    std::cout << std::endl;
    return false;
}

// vector<vector<T>> 版本 — 用 printVector2D 输出
template <typename T>
bool check(const std::string& label,
           const std::vector<std::vector<T>>& actual,
           const std::vector<std::vector<T>>& expected) {
    if (actual == expected) {
        std::cout << "[🟢 PASS] " << label << std::endl;
        return true;
    }
    std::cout << "[🔴 FAIL] " << label << std::endl;
    std::cout << "  期望: ";
    printVector2D(expected);
    std::cout << std::endl;
    std::cout << "  实际: ";
    printVector2D(actual);
    std::cout << std::endl;
    return false;
}

#endif  // LEETCODE_CHECK_H
