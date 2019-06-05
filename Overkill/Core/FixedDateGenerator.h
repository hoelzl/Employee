//
// Created by tc on 2019-05-29.
//

#ifndef EMPLOYEE_FIXEDDATEGENERATOR_H
#define EMPLOYEE_FIXEDDATEGENERATOR_H

#include "../Entities/DateGenerator.h"
#include <ctime>

namespace ok::core
{

class FixedDateGenerator : public ok::entities::DateGenerator
{
public:
    explicit FixedDateGenerator(const char* date_string);

    std::tm Today() const override;

private:
    std::tm StoredTodayValue{};
};

} // namespace ok::core

#endif // EMPLOYEE_FIXEDDATEGENERATOR_H
