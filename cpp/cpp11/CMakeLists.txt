cmake_minimum_required(VERSION 3.10)

project(cpp11)

# 使用Clang编译器
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

# 设置C++11标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 使用libc++标准库
add_compile_options(-stdlib=libc++)
add_link_options(-stdlib=libc++)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    inc/cpp11.h
    src/containers/array.cpp
    src/containers/deque.cpp
    src/containers/vector.cpp
    src/language/move_constructor.cpp
    src/memory/allocator.cpp
    src/numerics/round.cpp
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}
)
