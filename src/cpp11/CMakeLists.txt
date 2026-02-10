# C++11 模块的CMake配置
cmake_minimum_required(VERSION 3.10)

project(cpp11_lib)

add_library(cpp11_lib STATIC)

# 设置 Clang 编译器
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
target_compile_options(cpp11_lib PRIVATE -stdlib=libc++)
add_link_options(-stdlib=libc++)

target_sources(cpp11_lib
    PRIVATE
    "containers/array.cpp"
    "containers/deque.cpp"
    "containers/vector.cpp"
    "language/move_constructor.cpp"
    "memory/allocator.cpp"
    "numerics/round.cpp"
)

target_include_directories(cpp11_lib PRIVATE
    ${CMAKE_SOURCE_DIR}
)

# 设置C++11标准
set_target_properties(cpp11_lib PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
