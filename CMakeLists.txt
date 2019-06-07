cmake_minimum_required(VERSION 3.10)
project(Employee)

set(CMAKE_CXX_STANDARD 17)

# Google Test
add_subdirectory(googletest)
enable_testing()
include_directories(googletest/googletest/include googletest/googlemock/include)

# The bad part
add_library(BadEmployee
        Bad/Employee.cpp
        Bad/Employee.h
        Bad/Location.cpp
        Bad/Location.h
        Bad/Calendar.cpp
        Bad/Calendar.h
        )

add_executable(BadMain Bad/Main.cpp)
target_link_libraries(BadMain BadEmployee)

# Tests for the bad part
add_executable(BadEmployeeTest Bad/EmployeeTest.cpp)
target_link_libraries(BadEmployeeTest BadEmployee gtest gtest_main)
add_test(BadEmployeeTest BadEmployeeTest)

# The refactored bad part (1)
add_library(BadRef1
        BadRefactored1/Employee.cpp
        BadRefactored1/Employee.h
        BadRefactored1/Location.cpp
        BadRefactored1/Location.h
        BadRefactored1/Calendar.cpp
        BadRefactored1/Calendar.h
        BadRefactored1/CalendarReader.h
        BadRefactored1/Time.cpp
        BadRefactored1/Time.h
        BadRefactored1/CalendarFileReader.cpp
        BadRefactored1/CalendarFileReader.h
        BadRefactored1/EmployeeDataReader.h
        BadRefactored1/Name.cpp
        BadRefactored1/Name.h
        BadRefactored1/NameReader.h
        BadRefactored1/NameFileReader.cpp
        BadRefactored1/NameFileReader.h
        BadRefactored1/EmployeeDataFileReader.cpp
        BadRefactored1/EmployeeDataFileReader.h
        )

add_executable(BadRef1Main BadRefactored1/Main.cpp)
target_link_libraries(BadRef1Main BadRef1)

# Tests for the refactored bad part (1)
add_executable(BadRef1Test BadRefactored1/EmployeeTest.cpp)
target_link_libraries(BadRef1Test BadRef1 gtest gtest_main)
add_test(BadRef1Test BadRef1Test)

# The refactored bad part (2)
add_library(BadRef2
        BadRefactored2/Employee.cpp
        BadRefactored2/Employee.h
        BadRefactored2/Location.cpp
        BadRefactored2/Location.h
        BadRefactored2/Calendar.cpp
        BadRefactored2/Calendar.h
        BadRefactored2/AppointmentProvider.h
        BadRefactored2/Time.cpp
        BadRefactored2/Time.h
        BadRefactored2/FileAppointmentProvider.cpp
        BadRefactored2/FileAppointmentProvider.h
        BadRefactored2/EmployeeFactory.h
        BadRefactored2/Name.cpp
        BadRefactored2/Name.h
        BadRefactored2/EmployeeFactory.cpp)

add_executable(BadRef2Main BadRefactored2/Main.cpp)
target_link_libraries(BadRef2Main BadRef2)

# Tests for the refactored bad part (1)
add_executable(BadRef2Test BadRefactored2/EmployeeTest.cpp)
target_link_libraries(BadRef2Test BadRef2 gtest gtest_main)
add_test(BadRef2Test BadRef2Test)

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
