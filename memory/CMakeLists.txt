cmake_minimum_required(VERSION 3.10)

add_executable(allocator allocator.cpp)
install(TARGETS allocator DESTINATION "${OUTPUT_DIR}")
