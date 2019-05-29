#include <utility>

//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "../Core/DefaultPaymentCalculator.h"
#include "DateGenerator.h"
#include "Employee.h"
#include "Name.h"
#include "PaymentCalculator.h"
#include <iostream>

namespace ok::entities
{

int Employee::GetId() const
{
	return MyId;
}

Name Employee::GetName() const
{
	return MyName;
}

double Employee::GetSalary(const ok::entities::DateGenerator& DateGenerator) const
{
	return MyPaymentCalculator->ComputePayment(
		GetFixedSalary(DateGenerator), GetSalaryMultiplier(DateGenerator), GetBonus(DateGenerator));
}

std::tm Employee::GetBirthday() const
{
	return MyBirthday;
}

Employee::Employee(int Id, Name Name, const std::tm& Birthday)
	: Employee(Id, std::move(Name), Birthday, std::make_shared<DefaultPaymentCalculator>())
{
}

Employee::Employee(int Id, Name InName, const std::tm& Birthday,
				   std::shared_ptr<PaymentCalculator> PaymentCalculator)
	: MyId{Id}
	, MyName{std::move(InName)}
	, MyBirthday{Birthday}
	, MyPaymentCalculator{std::move(PaymentCalculator)}
{
}

double Employee::GetFixedSalary(const ok::entities::DateGenerator& DateGenerator) const
{
	double Salary{100.0};
	if (GetName().GetLastName() == "Boss")
	{
		Salary += 1000.0;
	}
	return Salary;
}

double Employee::GetSalaryMultiplier(const ok::entities::DateGenerator& DateGenerator) const
{
	if (GetName().GetLastName().size() <= 3 || GetName().GetFirstName().size() <= 3)
	{
		return 1.1;
	}
	return 1.0;
}

static bool IsTodayBirthday(const std::tm& Today, const std::tm& Birthday)
{
	return Today.tm_mday == Birthday.tm_mday && Today.tm_mon == Birthday.tm_mon;
}

double Employee::GetBonus(const ok::entities::DateGenerator& DateGenerator) const
{
	if (IsTodayBirthday(DateGenerator.Today(), GetBirthday()))
	{
		return 150.0;
	}
	return 0.0;
}

std::ostream& operator<<(std::ostream& Stream, const Employee& Employee)
{
	Stream << "Employee{" << Employee.GetId() << ": " << Employee.GetName().GetFullName() << "}";
	return Stream;
}
} // namespace ok::entities
