#include <utility>

#include <utility>

//
// Created by Matthias Hölzl on 2019-05-28.
//

#include <string>
#include "Name.h"

namespace ok {
namespace entities {

Name::Name(std::string InGivenName, std::string InLastName)
    : GivenName{std::move(InGivenName)}, LastName{std::move(InLastName)}
{
}

std::string Name::GetFullName() const {
    return GivenName + " " + LastName;
}

std::string Name::GetGivenName() const {
    return GivenName;
}

std::string Name::GetLastName() const {
    return LastName;
}

} // namespace entities
} // namespace ok
