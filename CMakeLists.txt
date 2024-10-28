cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(regular_expression)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        b514bdc898e2951020cbdca1304b75f5950d1f59
)

include_directories(${CMAKE_SOURCE_DIR}/src)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_executable(test ${CMAKE_SOURCE_DIR}/test/test.cpp)
target_link_libraries(test PUBLIC lib)


target_link_libraries(test PUBLIC gtest_main)
add_test(gtest test)