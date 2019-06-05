//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "Name.h"
#include <iostream>
#include <string>
#include <utility>

namespace ok::entities
{

Name::Name(std::string first_name, std::string last_name)
    : first_name_{std::move(first_name)}, last_name_{std::move(last_name)}
{
}

std::string Name::GetFullName() const
{
    return first_name_ + " " + last_name_;
}

std::string Name::GetFirstName() const
{
    return first_name_;
}

std::string Name::GetLastName() const
{
    return last_name_;
}

std::ostream& operator<<(std::ostream& Stream, const Name& Name)
{
    Stream << Name.GetFullName();
    return Stream;
}
} // namespace ok::entities
