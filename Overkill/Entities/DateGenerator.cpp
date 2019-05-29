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
	std::stringstream DateStream{Date};
	std::tm Result{};
	DateStream >> std::get_time(&Result, "%Y-%m-%d");
	return Result;
}
} // namespace ok::entities
