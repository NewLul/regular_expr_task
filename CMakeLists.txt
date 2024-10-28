cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#enable_testing()

project(regular_expression)

add_executable(main ${CMAKE_SOURCE_DIR}/src/main.cpp)