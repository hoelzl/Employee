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

class AugmentedEmployeeListPrinter : public ok::use_cases::EmployeeListPrinter
{
public:
	~AugmentedEmployeeListPrinter() override;

	AugmentedEmployeeListPrinter(std::ostream& Stream,
								 std::shared_ptr<const ok::entities::DateGenerator> DateGenerator);

	void PrintEmployeeList(const std::vector<ok::entities::Employee>& Employees) const override;

private:
	std::ostream* Stream{};
	std::shared_ptr<const ok::entities::DateGenerator> DateGenerator{};
};

} // namespace ok::use_cases

#endif // EMPLOYEE_AUGMENTEDLISTPRINTER_H
