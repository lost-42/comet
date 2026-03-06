# OS相关模块的CMake配置
cmake_minimum_required(VERSION 3.10)

# 查找当前目录下的所有.cpp文件
file(GLOB_RECURSE OS_SOURCES
    "*.cpp"
    "*/*.cpp"
)

if(OS_SOURCES)
    # 创建OS静态库
    add_library(os_lib STATIC ${OS_SOURCES})

    # 设置C++23标准（OS模块使用最新标准）
    set_target_properties(os_lib PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
    )

    # 包含目录
    target_include_directories(os_lib PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
    )

    # 编译器选项（如果使用Clang）
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(os_lib PRIVATE -stdlib=libc++)
    endif()

    # 打印调试信息
    message(STATUS "OS 模块: 找到 ${OS_SOURCES} 个源文件")
else()
    message(STATUS "OS 模块: 没有找到源文件")
endif()
