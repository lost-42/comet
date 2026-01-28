cmake_minimum_required(VERSION 3.10)

project(comet)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}")

# 添加所有源文件
set(SOURCES
    main.cpp
    containers/array.cpp
    containers/deque.cpp
    containers/vector.cpp
    language/move_constructor.cpp
    memory/allocator.cpp
    numerics/round.cpp
    posix/prod_cons.cpp
    posix/pthread.cpp
)

# 添加可执行文件
add_executable(comet ${SOURCES})

# 设置目标属性
target_include_directories(comet PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 链接pthread库（用于posix模块）
find_package(Threads REQUIRED)
target_link_libraries(comet PRIVATE Threads::Threads)

# 安装到bin目录
install(TARGETS comet DESTINATION "${OUTPUT_DIR}")
