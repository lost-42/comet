cmake_minimum_required(VERSION 3.10)

add_executable(move_constructor move_constructor.cpp)
install(TARGETS move_constructor DESTINATION "${OUTPUT_DIR}")
