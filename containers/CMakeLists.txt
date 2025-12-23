cmake_minimum_required(VERSION 3.10)

add_executable(array array.cpp)
install(TARGETS array DESTINATION "${OUTPUT_DIR}")

add_executable(deque deque.cpp)
install(TARGETS deque DESTINATION "${OUTPUT_DIR}")

add_executable(vector vector.cpp)
install(TARGETS vector DESTINATION "${OUTPUT_DIR}")
