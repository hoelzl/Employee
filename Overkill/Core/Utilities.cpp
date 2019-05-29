//
// Created by tc on 2019-05-29.
//

#include "Utilities.h"

namespace ok::core
{

bool IsTodayBirthday(const std::tm& Today, const std::tm& Birthday)
{
	return Today.tm_mday == Birthday.tm_mday && Today.tm_mon == Birthday.tm_mon;
}

}
