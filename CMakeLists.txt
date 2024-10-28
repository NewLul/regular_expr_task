cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

enable_testing()
find_package(GTest REQUIRED)

project(regular_expression)

add_subdirectory(src)
add_executable(test ${CMAKE_SOURCE_DIR}/test/test.cpp)
target_link_libraries(test PUBLIC lib)
target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(test PRIVATE GTest::gtest GTest::gtest_main)
add_test(gtest test)