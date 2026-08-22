cmake_minimum_required(VERSION 3.20)
project(tiny_array LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tiny_array
        main.cpp
        tiny_array.cpp
)

target_compile_options(tiny_array PRIVATE -Wall -Wextra -Wpedantic)

add_executable(test_tiny_array
    tests/test_tiny_array.cpp
    tiny_array.cpp
)

target_include_directories(test_tiny_array PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(test_tiny_array PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()
add_test(NAME tiny_array_tests COMMAND test_tiny_array)
