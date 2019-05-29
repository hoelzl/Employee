//
// Created by Matthias Hölzl on 2019-05-29.
//

#include "DateGenerator.h"
#include <iomanip>
#include <sstream>

namespace ok::entities
{

std::tm DateGenerator::ParseDate(const char* Date) const
{
	if (Date)
	{
		std::stringstream DateStream{Date};
		std::tm Result{};
		DateStream >> std::get_time(&Result, "%Y-%m-%d");
		return Result;
	}
	else
	{
		return std::tm{};
	}
}
} // namespace ok::entities
