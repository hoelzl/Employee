//
// Created by tc on 2019-05-28.
//

#include "DefaultEmployeeListPrinter.h"
#include "../Entities/Employee.h"
#include <algorithm>

namespace ok::use_cases
{

DefaultEmployeeListPrinter::DefaultEmployeeListPrinter(std::ostream& OStream) : Stream{&OStream}
{
}

void DefaultEmployeeListPrinter::PrintEmployeeList(
	const std::vector<ok::entities::Employee>& Employees) const
{
	for (auto& Employee : Employees)
	{
		*Stream << Employee << std::endl;
	}
}

DefaultEmployeeListPrinter::~DefaultEmployeeListPrinter()
{
	Stream = nullptr;
}

} // namespace ok::use_cases
