// main.cpp - Comet Learning Environment

#include <functional>
#include <map>
#include <string>

#include "inc/cpp11.h"
#include "inc/cpp20.h"
#include "inc/os.h"

int main() {
    // 模块映射：用户输入 -> 对应的run_函数（按字母顺序）
    std::map<std::string, std::function<void()>> modules = {
        {"allocator", run_allocator}, {"array_11", run_array_11},
        {"array_20", run_array_20},   {"deque", run_deque_11},
        {"move", run_move},           {"prod_cons", run_prod_cons},
        {"pthread", run_pthread},     {"string_20", run_string_20},
        {"round", run_round},         {"vector", run_vector}};

    modules["string_20"]();

    return 0;
}
