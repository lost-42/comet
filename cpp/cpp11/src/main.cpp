// main.cpp - Comet C++11 Learning Environment

#include <functional>
#include <map>
#include <string>

#include "inc/cpp11.h"

int main() {
    // Register available modules
    std::map<std::string, std::function<void()>> modules = {
        {"array", run_array},         {"deque", run_deque},
        {"vector", run_vector},       {"move", run_move},
        {"allocator", run_allocator}, {"round", run_round}};

    modules["round"]();

    return 0;
}
