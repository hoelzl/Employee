//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_DEFAULTSALARYCOMPUTATIONSTRATEGY_H
#define EMPLOYEE_DEFAULTSALARYCOMPUTATIONSTRATEGY_H

#include "../Entities/SalaryComputationStrategy.h"

namespace ok::core
{

class DefaultSalaryComputationStrategy : public ok::entities::SalaryComputationStrategy
{
public:
	explicit DefaultSalaryComputationStrategy(double BaseSalary = 100.0, double BossPrime = 1000.0,
											  double ShortNameScaleFactor = 1.1,
											  double BirthdayBonus = 150.0);

	double ComputeSalary(const entities::Employee& Employee,
						 const entities::DateGenerator& DateGenerator) const override;

private:
	double BaseSalary = 100.0;
	double BossPrime = 1000.0;
	double ShortNameScaleFactor = 1.1;
	double BirthdayBonus = 150.0;
};

} // namespace ok::core

#endif // EMPLOYEE_DEFAULTSALARYCOMPUTATIONSTRATEGY_H
