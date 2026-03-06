cmake_minimum_required(VERSION 3.28)

# 设置 Clang 编译器
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

# 全局C++标准设置
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 全局模块支持标志
add_compile_options(
    -stdlib=libc++
    -fmodules
    -fbuiltin-module-map
    -fimplicit-modules
    -fimplicit-module-maps
)

add_link_options(-stdlib=libc++)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(json)

add_executable(json)

target_sources(json
    PRIVATE
    "main.cpp"
)

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}")

# 安装到bin目录
install(TARGETS json DESTINATION "${OUTPUT_DIR}")
