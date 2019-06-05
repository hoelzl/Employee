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

Employee::Employee(int id, Name name, const std::tm& birthday)
    : id_{id}, name_{std::move(name)}, birthday_{birthday}
{
}

int Employee::GetId() const
{
    return id_;
}

Name Employee::GetName() const
{
    return name_;
}

std::tm Employee::GetBirthday() const
{
    return birthday_;
}

std::ostream& operator<<(std::ostream& stream, const Employee& employee)
{
    stream << "Employee{" << employee.GetId() << ": " << employee.GetName().GetFullName() << "}";
    return stream;
}
} // namespace ok::entities
