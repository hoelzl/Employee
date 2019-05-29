//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "Name.h"
#include <iostream>
#include <string>
#include <utility>

namespace ok::entities
{

Name::Name(std::string InFirstName, std::string InLastName)
	: FirstName{std::move(InFirstName)}, LastName{std::move(InLastName)}
{
}

std::string Name::GetFullName() const
{
	return FirstName + " " + LastName;
}

std::string Name::GetFirstName() const
{
	return FirstName;
}

std::string Name::GetLastName() const
{
	return LastName;
}

std::ostream& operator<<(std::ostream& Stream, const Name& Name)
{
	Stream << Name.GetFullName();
	return Stream;
}
} // namespace ok::entities
