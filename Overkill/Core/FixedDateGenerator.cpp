//
// Created by tc on 2019-05-29.
//

#include "FixedDateGenerator.h"

namespace ok::core
{

std::tm FixedDateGenerator::Today() const
{
	return StoredTodayValue;
}

FixedDateGenerator::FixedDateGenerator(const char* DateString)
	: StoredTodayValue{DateGenerator::ParseDate(DateString)}
{
}

} // namespace ok::core
