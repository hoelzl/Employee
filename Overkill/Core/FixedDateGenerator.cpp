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

FixedDateGenerator::FixedDateGenerator(const char* date_string)
    : StoredTodayValue{DateGenerator::ParseDate(date_string)}
{
}

} // namespace ok::core
