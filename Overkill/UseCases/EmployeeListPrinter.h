//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_EMPLOYEELISTPRINTER_H
#define EMPLOYEE_EMPLOYEELISTPRINTER_H

#include <vector>

namespace ok::use_cases
{
using ok::entities::Employee;

class EmployeeListPrinter
{
public:
	virtual ~EmployeeListPrinter() = default;
	virtual void PrintEmployeeList(const std::vector<Employee>& Employees) const = 0;
};

} // namespace ok::use_cases
#endif // EMPLOYEE_EMPLOYEELISTPRINTER_H
