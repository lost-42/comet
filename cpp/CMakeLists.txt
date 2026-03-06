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

project(comet)

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}")

# 添加 src 子目录
add_subdirectory(src)
add_subdirectory(toys/json)

# 安装到bin目录
install(TARGETS comet DESTINATION "${OUTPUT_DIR}")

# 打印配置信息
message(STATUS "项目名称: ${PROJECT_NAME}")
message(STATUS "C++标准: ${CMAKE_CXX_STANDARD}")
message(STATUS "编译器: ${CMAKE_CXX_COMPILER}")
message(STATUS "输出目录: ${OUTPUT_DIR}")
message(STATUS "C++20模块支持已启用")
