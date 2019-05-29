#include <utility>

//
// Created by tc on 2019-05-29.
//

#include "AugmentedEmployeeListPrinter.h"

ok::use_cases::AugmentedEmployeeListPrinter::~AugmentedEmployeeListPrinter()
{
	Stream = nullptr;
}

ok::use_cases::AugmentedEmployeeListPrinter::AugmentedEmployeeListPrinter(
	std::ostream& Stream, std::shared_ptr<const ok::entities::DateGenerator> DateGenerator,
	std::shared_ptr<const ok::entities::SalaryComputationStrategy> SalaryComputationStrategy)
	: Stream{&Stream}
	, DateGenerator{std::move(DateGenerator)}
	, SalaryComputationStrategy{std::move(SalaryComputationStrategy)}
{
}

void ok::use_cases::AugmentedEmployeeListPrinter::PrintEmployeeList(
	const std::vector<ok::entities::Employee>& Employees) const
{
	for (auto& Employee : Employees)
	{
		*Stream << "Employee{" << Employee.GetId() << ": " << Employee.GetName() << ", $"
				<< SalaryComputationStrategy->ComputeSalary(Employee, *DateGenerator) << "}"
				<< std::endl;
	}
}
