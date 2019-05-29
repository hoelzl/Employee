//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include "DateGenerator.h"
#include "Name.h"
#include "PaymentCalculator.h"
#include <ctime>
#include <memory>

namespace ok::entities
{

using ok::entities::Name;
using ok::entities::PaymentCalculator;

class Employee
{
public:
	Employee(int Id, Name Name, const std::tm& Birthday,
			 std::shared_ptr<PaymentCalculator> PaymentCalculator);

	Employee(int Id, Name Name, const std::tm& Birthday);

	int GetId() const;

	Name GetName() const;

	double GetSalary(const ok::entities::DateGenerator& DateGenerator) const;

	std::tm GetBirthday() const;

private:
	int MyId{};
	Name MyName{"<no given name>", "<no last name>"};
	std::tm MyBirthday{};
	std::shared_ptr<PaymentCalculator> MyPaymentCalculator{};

	double GetFixedSalary(const ok::entities::DateGenerator& DateGenerator) const;

	double GetSalaryMultiplier(const ok::entities::DateGenerator& DateGenerator) const;

	double GetBonus(const ok::entities::DateGenerator& DateGenerator) const;
};

std::ostream& operator<<(std::ostream& Stream, const Employee& Employee);

} // namespace ok::entities

#endif // EMPLOYEE_EMPLOYEE_H
