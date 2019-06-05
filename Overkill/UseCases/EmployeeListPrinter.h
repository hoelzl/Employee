//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_EMPLOYEELISTPRINTER_H
#define EMPLOYEE_EMPLOYEELISTPRINTER_H

#include "../Entities/Employee.h"
#include <vector>

namespace ok::use_cases
{
class EmployeeListPrinter
{
    using Employee = ok::entities::Employee;

public:
    virtual ~EmployeeListPrinter() = default;
    virtual void PrintEmployeeList(const std::vector<Employee>& employees) const;
    virtual void PrintEmployee(const Employee& employee) const = 0;
};

} // namespace ok::use_cases
#endif // EMPLOYEE_EMPLOYEELISTPRINTER_H
