//
// Created by tc on 2019-05-28.
//

#ifndef EMPLOYEE_EMPLOYEEFILEREADER_H
#define EMPLOYEE_EMPLOYEEFILEREADER_H

#include "../Entities/Employee.h"
#include "../UseCases/EmployeeFactory.h"
#include "../UseCases/EmployeeListFactory.h"
#include <memory>
#include <string>
#include <vector>

namespace ok::input_output
{

using ok::use_cases::EmployeeListFactory;

class EmployeeFileReader : public EmployeeListFactory
{
public:
	EmployeeFileReader(std::string FileName,
					   std::shared_ptr<ok::use_cases::EmployeeFactory> Generator);

	std::vector<ok::entities::Employee> CreateEmployees() const override;

private:
	std::string FileName;
	std::shared_ptr<ok::use_cases::EmployeeFactory> Generator;
};

} // namespace ok::input_output

#endif // EMPLOYEE_EMPLOYEEFILEREADER_H
