//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "DefaultPaymentCalculator.h"

namespace ok::entities
{

float DefaultPaymentCalculator::ComputePayment(double FixedPayment, double Multiplier, double Bonus)
{
	return FixedPayment * Multiplier + Bonus;
}

} // namespace ok::entities
