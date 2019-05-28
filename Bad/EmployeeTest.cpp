// Created by Matthias Hölzl on 2019-05-28.
//

#include "gmock/gmock.h"
#include "Employee.h"

TEST(Employee, CreateEmployee) {
    Employee employee{1};
    ASSERT_TRUE(true);
}
