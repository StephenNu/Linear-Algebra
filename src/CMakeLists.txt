cmake_minimum_required(VERSION 2.8)


add_definitions("--std=c++11 -Wall -Wextra")
# Added the include directory for header files. -Stephen
include_directories("../include")
include_directories("../src")

project(Linear_algebra_libary)


add_executable(
  bin/test_vector
  test_vector.cpp
)

enable_testing()

	add_test( vector_test test_vector )
#target_link_libraries(
#)
