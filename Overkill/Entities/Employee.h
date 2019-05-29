//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include "DateGenerator.h"
#include "Name.h"
#include "SalaryComputationStrategy.h"
#include <ctime>
#include <memory>

namespace ok::entities
{
class Employee
{
public:
	Employee(int Id, Name Name, const std::tm& Birthday);

	int GetId() const;

	Name GetName() const;

	std::tm GetBirthday() const;

private:
	int MyId{};
	Name MyName{"<no given name>", "<no last name>"};
	std::tm MyBirthday{};
};

std::ostream& operator<<(std::ostream& Stream, const Employee& Employee);

} // namespace ok::entities

#endif // EMPLOYEE_EMPLOYEE_H
