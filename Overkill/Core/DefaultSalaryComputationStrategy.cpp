//
// Created by tc on 2019-05-29.
//

#include "DefaultSalaryComputationStrategy.h"
#include "Utilities.h"

namespace ok::core
{

using ok::entities::DateGenerator;
using ok::entities::Employee;

DefaultSalaryComputationStrategy::DefaultSalaryComputationStrategy(double BaseSalary,
																   double BossPrime,
																   double ShortNameScaleFactor,
																   double BirthdayBonus)
	: BaseSalary{BaseSalary}
	, BossPrime{BossPrime}
	, ShortNameScaleFactor{ShortNameScaleFactor}
	, BirthdayBonus{BirthdayBonus}
{
}

double DefaultSalaryComputationStrategy::ComputeSalary(const Employee& Employee,
													   const DateGenerator& DateGenerator) const
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

} // namespace ok::core
