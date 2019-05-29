cmake_minimum_required(VERSION 3.10)
project(Employee)

set(CMAKE_CXX_STANDARD 17)

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

# The overkill part
add_library(OverkillEmployee
        Overkill/Entities/Employee.cpp
        Overkill/Entities/Name.cpp
        Overkill/Core/DefaultDateGenerator.cpp
        Overkill/Core/DefaultPaymentCalculator.cpp
        Overkill/UseCases/EmployeeFactory.cpp
        Overkill/UseCases/DefaultEmployeeListPrinter.cpp
        Overkill/UseCases/AugmentedEmployeeListPrinter.cpp
        Overkill/InputOutput/EmployeeFileReader.cpp
        Overkill/Core/FixedDateGenerator.cpp Overkill/Core/FixedDateGenerator.h Overkill/Entities/DateGenerator.cpp)

add_executable(OverkillMain Overkill/Main.cpp)
target_link_libraries(OverkillMain OverkillEmployee)

# Tests for the overkill part
add_executable(OverkillEmployeeTest Overkill/Tests/Entities/EmployeeTest.cpp Overkill/Tests/Entities/NameTest.cpp Overkill/Tests/Entities/DateGeneratorTest.cpp Overkill/Tests/Core/DefaultPaymentCalculatorTest.cpp Overkill/Tests/Core/FixedDateGeneratorTest.cpp Overkill/Tests/UseCases/AugmentedEmployeeListPrinterTest.cpp Overkill/Tests/UseCases/DefaultEmployeeListPrinterTest.cpp Overkill/Tests/UseCases/EmployeeFactoryTest.cpp Overkill/Tests/UseCases/EmployeeListFactoryTest.cpp)
target_link_libraries(OverkillEmployeeTest OverkillEmployee gtest gtest_main)
add_test(OverkillEmployeeTest OverkillEmployeeTest)
