//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "DefaultPaymentCalculator.h"
namespace ok {
namespace entities {

float DefaultPaymentCalculator::ComputePayment(double FixedPayment, double Multiplier, double Bonus) {
    return FixedPayment * Multiplier + Bonus;
}

} // namespace entities
} // namespace ok
