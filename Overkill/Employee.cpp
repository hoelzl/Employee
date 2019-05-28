//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include "PaymentCalculator.h"
#include "DefaultPaymentCalculator.h"
#include "Name.h"

namespace ok {
namespace core {

using ok::entities::Name;
using ok::entities::PaymentCalculator;
using ok::entities::DefaultPaymentCalculator;

int Employee::GetId() const {
    return MyId;
}

Name Employee::GetName() const {
    return MyName;
}

double Employee::GetSalary() const {
    return MyPaymentCalculator->ComputePayment(GetFixedSalary(), GetSalaryMultiplier(), GetBonus());
}

bool Employee::IsBirthday() const {
    return false;
}

Employee::Employee(int Id, Name Name, const std::tm& Birthday) : Employee(Id, Name, Birthday,
                                                                          std::make_unique<DefaultPaymentCalculator>()) {

}

Employee::Employee(int Id, Name InName, const std::tm& Birthday, std::unique_ptr<PaymentCalculator> PaymentCalculator)
        : MyId{Id},
          MyName{std::move(InName)},
          MyPaymentCalculator{std::move(PaymentCalculator)} {

}

double Employee::GetFixedSalary() const {
    double Salary{100.0};
    if (GetName().GetLastName() == "Boss") {
        Salary += 1000.0;
    }
    return Salary;
}

double Employee::GetSalaryMultiplier() const {
    if (GetName().GetLastName().size() <= 3 || GetName().GetGivenName().size() <= 3) {
        return 1.1;
    }
    return 1.0;
}

double Employee::GetBonus() const {
    return 0;
}


} // namespace core
} // namespace ok
