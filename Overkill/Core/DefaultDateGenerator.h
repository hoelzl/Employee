//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_DEFAULTDATEGENERATOR_H
#define EMPLOYEE_DEFAULTDATEGENERATOR_H

#include "../Entities/DateGenerator.h"
#include <ctime>

namespace ok::core
{

class DefaultDateGenerator : public ok::entities::DateGenerator
{
public:
	std::tm Today() const override;
};

} // namespace ok::core

#endif // EMPLOYEE_DEFAULTDATEGENERATOR_H
