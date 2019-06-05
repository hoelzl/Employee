//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_DEFAULTSALARYCOMPUTATIONSTRATEGY_H
#define EMPLOYEE_DEFAULTSALARYCOMPUTATIONSTRATEGY_H

#include "../Entities/SalaryComputationStrategy.h"

namespace ok::core
{

class DefaultSalaryComputationStrategy : public ok::entities::SalaryComputationStrategy
{
public:
    explicit DefaultSalaryComputationStrategy(double base_salary = 100.0,
                                              double boss_prime = 1000.0,
                                              double short_name_scale_factor = 1.1,
                                              double birthday_bonus = 150.0);

    double ComputeSalary(const entities::Employee& employee,
                         const entities::DateGenerator& date_generator) const override;

private:
    double base_salary_ = 100.0;
    double boss_prime_ = 1000.0;
    double short_name_scale_factor_ = 1.1;
    double birthday_bonus_ = 150.0;
};

} // namespace ok::core

#endif // EMPLOYEE_DEFAULTSALARYCOMPUTATIONSTRATEGY_H
