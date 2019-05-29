//
// Created by tc on 2019-05-28.
//

#ifndef EMPLOYEE_DEFAULTEMPLOYEELISTPRINTER_H
#define EMPLOYEE_DEFAULTEMPLOYEELISTPRINTER_H

#include "../Entities/Employee.h"
#include "EmployeeListPrinter.h"
#include <ostream>
#include <vector>

namespace ok::use_cases
{

class DefaultEmployeeListPrinter : public EmployeeListPrinter
{
public:
	explicit DefaultEmployeeListPrinter(std::ostream& OStream);
	~DefaultEmployeeListPrinter() override;

	void PrintEmployeeList(const std::vector<ok::entities::Employee>& Employees) const override;

private:
	::std::ostream* Stream;
};

} // namespace ok::use_cases

#endif // EMPLOYEE_DEFAULTEMPLOYEELISTPRINTER_H
