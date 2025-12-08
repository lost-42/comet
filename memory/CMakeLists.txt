cmake_minimum_required(VERSION 3.10)

add_executable(vector_allocator vector_allocator.cpp)
install(TARGETS vector_allocator DESTINATION "${OUTPUT_DIR}")
