//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_EMPLOYEELISTFACTORY_H
#define EMPLOYEE_EMPLOYEELISTFACTORY_H

#include <memory>
#include <vector>

namespace ok::use_cases
{

class EmployeeListFactory : public std::enable_shared_from_this<EmployeeListFactory>
{
public:
	virtual ~EmployeeListFactory() = default;
	virtual std::vector<ok::entities::Employee> CreateEmployees() const = 0;
};

} // namespace ok::use_cases

#endif // EMPLOYEE_EMPLOYEELISTFACTORY_H
