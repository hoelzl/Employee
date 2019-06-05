cmake_minimum_required(VERSION 3.10)
project(Employee)

set(CMAKE_CXX_STANDARD 17)

# Google Test
add_subdirectory(googletest)
enable_testing()
include_directories(googletest/googletest/include googletest/googlemock/include)

# The bad part
add_library(BadEmployee Bad/Employee.cpp Bad/Location.cpp Bad/Location.h Bad/Calendar.cpp Bad/Calendar.h)

add_executable(BadMain Bad/Main.cpp)
target_link_libraries(BadMain BadEmployee)

# Tests for the bad part
add_executable(BadEmployeeTest Bad/EmployeeTest.cpp)
target_link_libraries(BadEmployeeTest BadEmployee gtest gtest_main)
add_test(BadEmployeeTest BadEmployeeTest)

# The refactored bad part
add_library(BadRef1 BadRefactored1/Employee.cpp BadRefactored1/Location.cpp BadRefactored1/Location.h BadRefactored1/Calendar.cpp BadRefactored1/Calendar.h)

add_executable(BadRef1Main BadRefactored1/Main.cpp)
target_link_libraries(BadRef1Main BadRef1)

# Tests for the refactored bad part
add_executable(BadRef1Test BadRefactored1/EmployeeTest.cpp)
target_link_libraries(BadRef1Test BadRef1 gtest gtest_main)
add_test(BadRef1Test BadRef1Test)

# The overkill part
add_library(OverkillEmployee
        Overkill/Entities/Employee.cpp
        Overkill/Entities/Name.cpp
        Overkill/Core/DefaultDateGenerator.cpp
        Overkill/UseCases/EmployeeFactory.cpp
        Overkill/UseCases/DefaultEmployeeListPrinter.cpp
        Overkill/UseCases/AugmentedEmployeeListPrinter.cpp
        Overkill/InputOutput/EmployeeFileReader.cpp
        Overkill/Core/FixedDateGenerator.cpp
        Overkill/Entities/DateGenerator.cpp
        Overkill/Core/DefaultSalaryComputationStrategy.cpp
        Overkill/Core/Utilities.cpp
        Overkill/UseCases/EmployeeListPrinter.cpp
        )

add_executable(OverkillMain Overkill/Main.cpp)
target_link_libraries(OverkillMain OverkillEmployee)

# Tests for the overkill part
add_executable(OverkillEmployeeTest
        Overkill/Tests/Entities/EmployeeTest.cpp
        Overkill/Tests/Entities/NameTest.cpp
        Overkill/Tests/Entities/DateGeneratorTest.cpp
        Overkill/Tests/Core/DefaultPaymentCalculatorTest.cpp
        Overkill/Tests/Core/FixedDateGeneratorTest.cpp
        Overkill/Tests/UseCases/AugmentedEmployeeListPrinterTest.cpp
        Overkill/Tests/UseCases/DefaultEmployeeListPrinterTest.cpp
        Overkill/Tests/UseCases/EmployeeFactoryTest.cpp
        Overkill/Tests/UseCases/EmployeeListFactoryTest.cpp
        )

target_link_libraries(OverkillEmployeeTest OverkillEmployee gtest gtest_main)
add_test(OverkillEmployeeTest OverkillEmployeeTest)
