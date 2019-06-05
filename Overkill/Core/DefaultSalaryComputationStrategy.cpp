//
// Created by tc on 2019-05-29.
//

#include "DefaultSalaryComputationStrategy.h"
#include "Utilities.h"

namespace ok::core
{

using ok::entities::DateGenerator;
using ok::entities::Employee;

DefaultSalaryComputationStrategy::DefaultSalaryComputationStrategy(double base_salary,
                                                                   double boss_prime,
                                                                   double short_name_scale_factor,
                                                                   double birthday_bonus)
    : base_salary_{base_salary}
    , boss_prime_{boss_prime}
    , short_name_scale_factor_{short_name_scale_factor}
    , birthday_bonus_{birthday_bonus}
{
}

double DefaultSalaryComputationStrategy::ComputeSalary(const Employee& employee,
                                                       const DateGenerator& date_generator) const
{
    double Salary{base_salary_};
    if (employee.GetName().GetLastName() == "Boss")
    {
        Salary += 1000.0;
    }
    if (employee.GetName().GetFirstName().size() <= 3 ||
        employee.GetName().GetLastName().size() <= 3)
    {
        Salary *= 1.1;
    }
    if (IsTodayBirthday(date_generator.Today(), employee.GetBirthday()))
    {
        Salary += 150.0;
    }

    return Salary;
}

} // namespace ok::core
