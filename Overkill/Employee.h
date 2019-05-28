//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H


#include <ctime>
#include <memory>
#include "Name.h"
#include "PaymentCalculator.h"

namespace ok {
namespace core {

using ok::entities::Name;
using ok::entities::PaymentCalculator;

class Employee {
public:
    Employee(int Id, Name Name, const std::tm& Birthday, std::unique_ptr<PaymentCalculator> PaymentCalculator);
    Employee(int Id, Name Name, const std::tm& Birthday);

    int GetId() const;
    Name GetName() const;
    double GetSalary() const;
    bool IsBirthday() const;

private:
    int MyId{};
    Name MyName{"<no given name>", "<no last name>"};
    std::tm MyBirthday{};
    std::unique_ptr<PaymentCalculator> MyPaymentCalculator{};

    double GetFixedSalary() const;

    double GetSalaryMultiplier() const;

    double GetBonus() const;
};

} // namespace core
} // namespace ok


#endif //EMPLOYEE_EMPLOYEE_H
