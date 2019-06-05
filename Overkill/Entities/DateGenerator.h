//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_DATEGENERATOR_H
#define EMPLOYEE_DATEGENERATOR_H

#include <ctime>

namespace ok::entities
{

class DateGenerator
{
public:
	virtual ~DateGenerator() = default;
	virtual std::tm Today() const = 0;

	virtual std::tm ParseDate(const char* date) const;
};

} // namespace ok::entities

#endif // EMPLOYEE_DATEGENERATOR_H
