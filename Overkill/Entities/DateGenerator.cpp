//
// Created by Matthias Hölzl on 2019-05-29.
//

#include "DateGenerator.h"
#include <iomanip>
#include <sstream>

namespace ok::entities
{

std::tm DateGenerator::ParseDate(const char* date) const
{
    if (date)
    {
        std::stringstream date_stream{date};
        std::tm result{};
        date_stream >> std::get_time(&result, "%Y-%m-%d");
        return result;
    }
    else
    {
        return std::tm{};
    }
}
} // namespace ok::entities
