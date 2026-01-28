// main.cpp - Comet Learning Environment

#include <functional>
#include <iostream>
#include <map>
#include <string>

// 声明模块入口函数（按字母顺序）
void run_allocator();         // memory/allocator.cpp
void run_array();             // containers/array.cpp
void run_deque();             // containers/deque.cpp
void run_move_constructor();  // language/move_constructor.cpp
void run_prod_cons();         // posix/prod_cons.cpp
void run_pthread();           // posix/pthread.cpp
void run_round();             // numerics/round.cpp
void run_vector();            // containers/vector.cpp

int main() {
    // 模块映射：用户输入 -> 对应的run_函数（按字母顺序）
    std::map<std::string, std::function<void()>> modules = {
        {"allocator", run_allocator},
        {"array", run_array},
        {"deque", run_deque},
        {"move", run_move_constructor},  // 简称"move"
        {"prod_cons", run_prod_cons},
        {"pthread", run_pthread},
        {"round", run_round},
        {"vector", run_vector}};

    modules["round"]();

    return 0;
}
