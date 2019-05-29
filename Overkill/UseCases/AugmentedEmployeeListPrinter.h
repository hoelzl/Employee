//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_AUGMENTEDLISTPRINTER_H
#define EMPLOYEE_AUGMENTEDLISTPRINTER_H

#include "../Entities/DateGenerator.h"
#include "../Entities/Employee.h"
#include "EmployeeListPrinter.h"
#include <ostream>
#include <vector>

namespace ok::use_cases
{

using ok::entities::DateGenerator;
using ok::entities::SalaryComputationStrategy;

class AugmentedEmployeeListPrinter : public EmployeeListPrinter
{
public:
	AugmentedEmployeeListPrinter(
		std::ostream& Stream, std::shared_ptr<const DateGenerator> DateGenerator,
		std::shared_ptr<const SalaryComputationStrategy> SalaryComputationStrategy);

	~AugmentedEmployeeListPrinter() override;

	void PrintEmployee(const ok::entities::Employee& Employee) const override;

private:
	std::ostream* Stream{};
	std::shared_ptr<const DateGenerator> DateGenerator{};
	std::shared_ptr<const SalaryComputationStrategy> SalaryComputationStrategy{};
};

} // namespace ok::use_cases

#endif // EMPLOYEE_AUGMENTEDLISTPRINTER_H
