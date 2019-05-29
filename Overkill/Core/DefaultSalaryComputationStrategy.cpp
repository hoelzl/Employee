//
// Created by tc on 2019-05-29.
//

#include "DefaultSalaryComputationStrategy.h"

static bool IsTodayBirthday(const std::tm& Today, const std::tm& Birthday)
{
	return Today.tm_mday == Birthday.tm_mday && Today.tm_mon == Birthday.tm_mon;
}

double ok::core::DefaultSalaryComputationStrategy::ComputeSalary(
	const ok::entities::Employee& Employee, const ok::entities::DateGenerator& DateGenerator) const
{
	double Salary{BaseSalary};
	if (Employee.GetName().GetLastName() == "Boss")
	{
		Salary += 1000.0;
	}
	if (Employee.GetName().GetFirstName().size() <= 3 ||
		Employee.GetName().GetLastName().size() <= 3)
	{
		Salary *= 1.1;
	}
	if (IsTodayBirthday(DateGenerator.Today(), Employee.GetBirthday()))
	{
		Salary += 150.0;
	}

	return Salary;
}
ok::core::DefaultSalaryComputationStrategy::DefaultSalaryComputationStrategy(
	double BaseSalary, double BossPrime, double ShortNameScaleFactor, double BirthdayBonus)
	: BaseSalary{BaseSalary}
	, BossPrime{BossPrime}
	, ShortNameScaleFactor{ShortNameScaleFactor}
	, BirthdayBonus{BirthdayBonus}
{
}
