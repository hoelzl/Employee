//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_UTILITIES_H
#define EMPLOYEE_UTILITIES_H

#include <ctime>

namespace ok::core
{
bool IsTodayBirthday(const std::tm& today, const std::tm& birthday);
}

#endif // EMPLOYEE_UTILITIES_H
