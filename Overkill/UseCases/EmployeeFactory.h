//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_EMPLOYEELISTGENERATOR_H
#define EMPLOYEE_EMPLOYEELISTGENERATOR_H

#include "../Entities/Employee.h"
#include <memory>
#include <optional>

namespace ok::use_cases
{

class EmployeeFactory : public std::enable_shared_from_this<EmployeeFactory>
{
	using Employee = ok::entities::Employee;

public:
	virtual ~EmployeeFactory() = default;
	virtual std::optional<Employee> CreateEmployee(const std::string& EmployeeData) const;
};

} // namespace ok::use_cases
#endif // EMPLOYEE_EMPLOYEELISTGENERATOR_H
