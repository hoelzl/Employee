//
// Created by tc on 2019-05-29.
//

#include "AugmentedEmployeeListPrinter.h"
#include "../Core/Utilities.h"
#include <utility>

namespace ok::use_cases
{

AugmentedEmployeeListPrinter::AugmentedEmployeeListPrinter(
	std::ostream& Stream, std::shared_ptr<const ok::entities::DateGenerator> DateGenerator,
	std::shared_ptr<const ok::entities::SalaryComputationStrategy> SalaryComputationStrategy)
	: Stream{&Stream}
	, DateGenerator{std::move(DateGenerator)}
	, SalaryComputationStrategy{std::move(SalaryComputationStrategy)}
{
}

AugmentedEmployeeListPrinter::~AugmentedEmployeeListPrinter()
{
	Stream = nullptr;
}

void AugmentedEmployeeListPrinter::PrintEmployee(const ok::entities::Employee& Employee) const
{
	if (Stream)
	{
		*Stream << "Employee{" << Employee.GetId() << ": " << Employee.GetName() << ", $"
				<< SalaryComputationStrategy->ComputeSalary(Employee, *DateGenerator) << "}"
				<< (core::IsTodayBirthday(DateGenerator->Today(), Employee.GetBirthday())
						? " *** It's their birthday *** "
						: "")
				<< std::endl;
	}
}

} // namespace ok::use_cases
