// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include <ctime>
#include <ostream>

class Name
{
public:
	explicit Name(int Id);

private:
	friend std::ostream& operator<<(std::ostream& Stream, const Name& Name);
	friend class Employee;
	std::string GivenName;
	std::string LastName;
};

std::ostream& operator<<(std::ostream& Stream, const Name& Name);

class Employee
{
public:
	explicit Employee(int InId);

private:
	friend std::ostream& operator<<(std::ostream& Stream, const Employee& Employee);
	int MyId;
	Name MyName;
	std::tm Birthday;
	bool IsBirthday() const;
	double GetSalary() const;
};

std::ostream& operator<<(std::ostream& Stream, const Employee& Employee);

#endif // EMPLOYEE_EMPLOYEE_H
