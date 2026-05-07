cmake_minimum_required(VERSION 3.15)
project(TwoSumProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(twosum STATIC src/twosum.cpp)
target_include_directories(twosum PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_executable(twosum_app src/main.cpp)
target_link_libraries(twosum_app PRIVATE twosum)

add_executable(twosum_tests tests/test_twosum.cpp)
target_link_libraries(twosum_tests PRIVATE twosum)

enable_testing()
add_test(NAME TwoSumTests COMMAND twosum_tests)
