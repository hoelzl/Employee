//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "DefaultDateGenerator.h"

namespace ok::core
{

std::tm DefaultDateGenerator::Today() const
{
    std::time_t current_time{std::time(nullptr)};
    return *localtime(&current_time);
}

} // namespace ok::core
