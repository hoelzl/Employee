cmake_minimum_required(VERSION 3.10)
project(Employee)

set(CMAKE_CXX_STANDARD 14)

# Google Test
add_subdirectory(googletest)
enable_testing()
include_directories(googletest/googletest/include googletest/googlemock/include)

# The bad part
add_library(BadEmployee Bad/Employee.cpp)

add_executable(BadMain Bad/Main.cpp)
target_link_libraries(BadMain BadEmployee)

# Tests for the bad part
add_executable(BadEmployeeTest Bad/EmployeeTest.cpp)
target_link_libraries(BadEmployeeTest BadEmployee gtest gtest_main)
add_test(BadEmployeeTest BadEmployeeTest)
