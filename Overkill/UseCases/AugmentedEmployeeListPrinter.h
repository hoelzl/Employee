//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_AUGMENTEDLISTPRINTER_H
#define EMPLOYEE_AUGMENTEDLISTPRINTER_H

#include "../Entities/DateGenerator.h"
#include "../Entities/Employee.h"
#include "EmployeeListPrinter.h"
#include <ostream>
#include <vector>

namespace ok::use_cases
{

using ok::entities::DateGenerator;
using ok::entities::SalaryComputationStrategy;

class AugmentedEmployeeListPrinter : public EmployeeListPrinter
{
public:
    AugmentedEmployeeListPrinter(
        std::ostream& stream, std::shared_ptr<const DateGenerator> date_generator,
        std::shared_ptr<const SalaryComputationStrategy> salary_computation_strategy);

    ~AugmentedEmployeeListPrinter() override;

    void PrintEmployee(const ok::entities::Employee& employee) const override;

private:
    std::ostream* stream_{};
    std::shared_ptr<const DateGenerator> date_generator_{};
    std::shared_ptr<const SalaryComputationStrategy> salary_computation_strategy_{};
};

} // namespace ok::use_cases

#endif // EMPLOYEE_AUGMENTEDLISTPRINTER_H
