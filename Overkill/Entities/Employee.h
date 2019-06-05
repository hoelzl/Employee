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
    Employee(int id, Name name, const std::tm& birthday);

    int GetId() const;

    Name GetName() const;

    std::tm GetBirthday() const;

private:
    int id_{};
    Name name_{"<no given name>", "<no last name>"};
    std::tm birthday_{};
};

std::ostream& operator<<(std::ostream& stream, const Employee& employee);

} // namespace ok::entities

#endif // EMPLOYEE_EMPLOYEE_H
