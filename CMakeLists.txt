cmake_minimum_required(VERSION 3.10)
project(clean_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

# gtest
set(gtest_source_dir "${PROJECT_SOURCE_DIR}/gtest-1.6.0")
add_subdirectory(${gtest_source_dir})
enable_testing() # ??
include_directories(${gtest_source_dir}/include)

# testsuite
add_executable(clean_cpp main.cpp)
target_link_libraries(clean_cpp gtest gtest_main)