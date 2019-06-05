//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_SALARYCOMPUTATIONSTRATEGY_H
#define EMPLOYEE_SALARYCOMPUTATIONSTRATEGY_H

#include "DateGenerator.h"
#include "Employee.h"

namespace ok::entities
{

class Employee;

class SalaryComputationStrategy
{
public:
    virtual ~SalaryComputationStrategy() = default;

    virtual double ComputeSalary(const Employee& employee,
                                 const DateGenerator& date_generator) const = 0;
};

} // namespace ok::entities
#endif // EMPLOYEE_SALARYCOMPUTATIONSTRATEGY_H
