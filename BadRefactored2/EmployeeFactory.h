//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_EMPLOYEEFACTORY_H
#define EMPLOYEE_EMPLOYEEFACTORY_H

#include "Calendar.h"
#include "Employee.h"
#include "Location.h"
#include "Name.h"
#include <ctime>
#include <memory>

struct EmployeeData
{
    int id_;
    std::string first_name_;
    std::string last_name_;
    std::tm birthday_;
};

class EmployeeFactory
{
public:
    EmployeeFactory(const char* data_file_name);
    Employee CreateEmployee(int id);


private:
    EmployeeData readEmployeeData(int id) const;
    const char* data_file_name_;
};

#endif // EMPLOYEE_EMPLOYEEFACTORY_H
