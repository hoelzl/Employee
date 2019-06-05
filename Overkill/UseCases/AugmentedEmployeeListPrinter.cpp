//
// Created by tc on 2019-05-29.
//

#include "AugmentedEmployeeListPrinter.h"
#include "../Core/Utilities.h"
#include <utility>

namespace ok::use_cases
{

AugmentedEmployeeListPrinter::AugmentedEmployeeListPrinter(
    std::ostream& stream, std::shared_ptr<const ok::entities::DateGenerator> date_generator,
    std::shared_ptr<const ok::entities::SalaryComputationStrategy> salary_computation_strategy)
    : stream_{&stream}
    , date_generator_{std::move(date_generator)}
    , salary_computation_strategy_{std::move(salary_computation_strategy)}
{
}

AugmentedEmployeeListPrinter::~AugmentedEmployeeListPrinter()
{
    stream_ = nullptr;
}

void AugmentedEmployeeListPrinter::PrintEmployee(const ok::entities::Employee& employee) const
{
    if (stream_)
    {
        *stream_ << "Employee{" << employee.GetId() << ": " << employee.GetName() << ", $"
                 << salary_computation_strategy_->ComputeSalary(employee, *date_generator_) << "}"
                 << (core::IsTodayBirthday(date_generator_->Today(), employee.GetBirthday())
                         ? " *** It's their birthday *** "
                         : "")
                 << std::endl;
    }
}

} // namespace ok::use_cases
