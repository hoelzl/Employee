//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "EmployeeFactory.h"
#include <iomanip>
#include <sstream>

namespace ok::use_cases
{

using ok::entities::Employee;

std::optional<Employee> EmployeeFactory::CreateEmployee(const std::string& EmployeeData) const
{
	int DataId{-1};
	std::string DataFirstName, DataLastName;
	std::tm DataDate{};
	std::stringstream Data{EmployeeData};
	Data >> DataId >> DataFirstName >> DataLastName >> std::get_time(&DataDate, "%Y-%m-%d");
	if (DataId >= 0)
	{
		return Employee{DataId, ok::entities::Name{DataFirstName, DataLastName}, DataDate};
	}
	else
	{
		return std::nullopt;
	}
}
} // namespace ok::use_cases
