// Created by Matthias Hölzl on 2019-05-28.
//

#include "EmployeeFileReader.h"
#include <fstream>
#include <utility>

namespace ok::input_output
{

using ok::entities::Employee;

EmployeeFileReader::EmployeeFileReader(std::string FileName,
									   std::shared_ptr<ok::use_cases::EmployeeFactory> Generator)
	: FileName{std::move(FileName)}, Generator{std::move(Generator)}
{
}

std::vector<Employee> EmployeeFileReader::CreateEmployees() const
{
	std::ifstream Data{FileName};
	std::vector<Employee> Result{};
	while (Data)
	{
		std::string Line;
		std::getline(Data, Line);
		std::optional<Employee> Employee{Generator->CreateEmployee(Line)};
		if (Employee.has_value())
		{
			Result.emplace_back(Employee.value());
		}
	}
	return Result;
}
} // namespace ok::input_output
