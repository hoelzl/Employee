//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_DEFAULT_PAYMENT_CALCULATOR_H
#define EMPLOYEE_DEFAULT_PAYMENT_CALCULATOR_H

#include "PaymentCalculator.h"

namespace ok {
namespace entities {

class DefaultPaymentCalculator : public PaymentCalculator {
public:
    float ComputePayment(double FixedPayment, double Multiplier, double Bonus) override;
};

} // namespace entities
} // namespace ok

#endif //EMPLOYEE_DEFAULT_PAYMENT_CALCULATOR_H
