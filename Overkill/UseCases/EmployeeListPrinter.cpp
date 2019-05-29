//
// Created by tc on 2019-05-29.
//

#include "EmployeeListPrinter.h"
#include "../Entities/Employee.h"

namespace ok::use_cases
{

using ok::entities::Employee;

void ok::use_cases::EmployeeListPrinter::PrintEmployeeList(
	const std::vector<Employee>& Employees) const
{
	for (auto& Employee : Employees)
	{
		PrintEmployee(Employee);
	}
}

} // namespace ok::use_cases
