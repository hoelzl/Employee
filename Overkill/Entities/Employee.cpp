//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include "DateGenerator.h"
#include "Name.h"
#include "SalaryComputationStrategy.h"
#include <iostream>
#include <utility>

namespace ok::entities
{

Employee::Employee(int Id, Name InName, const std::tm& Birthday)
	: MyId{Id}, MyName{std::move(InName)}, MyBirthday{Birthday}
{
}

int Employee::GetId() const
{
	return MyId;
}

Name Employee::GetName() const
{
	return MyName;
}

std::tm Employee::GetBirthday() const
{
	return MyBirthday;
}

std::ostream& operator<<(std::ostream& Stream, const Employee& Employee)
{
	Stream << "Employee{" << Employee.GetId() << ": " << Employee.GetName().GetFullName() << "}";
	return Stream;
}
} // namespace ok::entities
