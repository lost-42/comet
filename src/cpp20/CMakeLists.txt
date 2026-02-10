# C++20 模块的CMake配置
cmake_minimum_required(VERSION 3.28)

project(cpp20_lib)

add_library(cpp20_lib STATIC)

# 设置 Clang 编译器
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

# C++20 模块支持
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 模块编译标志
target_compile_options(cpp20_lib PRIVATE
    -stdlib=libc++
    -fmodules
    -fbuiltin-module-map
    -fimplicit-modules
    -fimplicit-module-maps
)

target_link_options(cpp20_lib PRIVATE
    -stdlib=libc++
)

target_sources(cpp20_lib
    PRIVATE
    "containers/array.cpp"
    "containers/string.cpp"
)

target_include_directories(cpp20_lib PRIVATE
    ${CMAKE_SOURCE_DIR}
)

# 设置目标属性
set_target_properties(cpp20_lib PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# 打印调试信息
message(STATUS "C++20 模块配置完成")
message(STATUS "编译器: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++标准: ${CMAKE_CXX_STANDARD}")
message(STATUS "模块支持已启用")
