//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "DefaultDateGenerator.h"

namespace ok::core
{

std::tm DefaultDateGenerator::Today() const
{
	std::time_t CurrentTime{std::time(nullptr)};
	return *localtime(&CurrentTime);
}

} // namespace ok::entities
