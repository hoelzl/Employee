//
// Created by tc on 2019-05-29.
//

#include "Utilities.h"

namespace ok::core
{

bool IsTodayBirthday(const std::tm& today, const std::tm& birthday)
{
    return today.tm_mday == birthday.tm_mday && today.tm_mon == birthday.tm_mon;
}

} // namespace ok::core
