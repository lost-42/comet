# src目录的CMake配置
cmake_minimum_required(VERSION 3.10)

# 设置输出目录
set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}")

# 添加可执行文件
add_executable(comet main.cpp)

target_include_directories(comet PRIVATE
    ${CMAKE_SOURCE_DIR}
)

# 设置主程序使用C++23标准
set_target_properties(comet PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)

# C++11 模块
add_subdirectory(cpp11)
if(TARGET cpp11_lib)
    target_link_libraries(comet PRIVATE cpp11_lib)
    message(STATUS "链接C++11库到主程序")
endif()

# C++14 模块
# add_subdirectory(cpp14)
# if(TARGET cpp14_lib)
#     target_link_libraries(comet PRIVATE cpp14_lib)
#     message(STATUS "链接C++14库到主程序")
# endif()

# C++17 模块
# add_subdirectory(cpp17)
# if(TARGET cpp17_lib)
#     target_link_libraries(comet PRIVATE cpp17_lib)
#     message(STATUS "链接C++17库到主程序")
# endif()

# C++20 模块
add_subdirectory(cpp20)
if(TARGET cpp20_lib)
    target_link_libraries(comet PRIVATE cpp20_lib)
    message(STATUS "链接C++20库到主程序")
endif()

# C++23 模块
# add_subdirectory(cpp23)
# if(TARGET cpp23_lib)
#     target_link_libraries(comet PRIVATE cpp23_lib)
#     message(STATUS "链接C++23库到主程序")
# endif()

# OS相关模块
add_subdirectory(os)
if(TARGET os_lib)
    target_link_libraries(comet PRIVATE os_lib)
    message(STATUS "链接OS库到主程序")
endif()

# 链接pthread库（用于os/posix模块）
find_package(Threads REQUIRED)
target_link_libraries(comet PRIVATE Threads::Threads)

# 编译器选项
target_compile_options(comet PRIVATE -stdlib=libc++)
target_link_options(comet PRIVATE -stdlib=libc++)

# 安装到bin目录
install(TARGETS comet DESTINATION "${OUTPUT_DIR}")

# 打印调试信息
message(STATUS "主程序源文件: ${MAIN_SOURCES}")
message(STATUS "构建目标: comet")
message(STATUS "输出目录: ${OUTPUT_DIR}")
