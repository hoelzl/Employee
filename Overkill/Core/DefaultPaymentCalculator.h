//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_DEFAULT_PAYMENT_CALCULATOR_H
#define EMPLOYEE_DEFAULT_PAYMENT_CALCULATOR_H

#include "../Entities/PaymentCalculator.h"

namespace ok::entities
{

class DefaultPaymentCalculator : public PaymentCalculator
{
public:
	float ComputePayment(double FixedPayment, double Multiplier, double Bonus) override;
};

} // namespace ok::entities

#endif // EMPLOYEE_DEFAULT_PAYMENT_CALCULATOR_H
