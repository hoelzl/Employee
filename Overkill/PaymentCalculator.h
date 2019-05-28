//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_PAYMENT_CALCULATOR_H
#define EMPLOYEE_PAYMENT_CALCULATOR_H


namespace ok {
namespace entities {

class PaymentCalculator {
public:
    virtual float ComputePayment(double FixedPayment, double Multiplier, double Bonus) = 0;
};

} // namespace entities
} // namespace ok

#endif //EMPLOYEE_PAYMENT_CALCULATOR_H
