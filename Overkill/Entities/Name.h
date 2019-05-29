//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_NAME_H
#define EMPLOYEE_NAME_H

#include <string>

namespace ok::entities
{

class Name
{
public:
	Name(std::string InFirstName, std::string InLastName);

	std::string GetFirstName() const;

	std::string GetLastName() const;

	std::string GetFullName() const;

private:
	std::string FirstName;
	std::string LastName;
};

std::ostream& operator<<(std::ostream& Stream, const Name& Name);

} // namespace ok::entities

#endif // EMPLOYEE_NAME_H
