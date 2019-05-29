// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

Name::Name(int Id) : GivenName{"<no given name>"}, LastName{"<no last name>"}
{
	std::ifstream Data{"employee-data.txt"};
	while (Data)
	{
		int DataId{-1};
		std::string DataGivenName, DataLastName;
		std::tm DataDate{};
		Data >> DataId >> DataGivenName >> DataLastName >> std::get_time(&DataDate, "%Y-%m-%d");
		if (DataId >= 0 && DataId == Id)
		{
			GivenName = DataGivenName;
			LastName = DataLastName;
			break;
		}
	}
}

std::ostream& operator<<(std::ostream& Stream, const Name& Name)
{
	Stream << Name.GivenName << " " << Name.LastName;
	return Stream;
}

Employee::Employee(int InId) : MyId{InId}, MyName{InId}, Birthday{}
{
	std::ifstream Data{"employee-data.txt"};
	while (Data)
	{
		int DataId{-1};
		std::string DataGivenName, DataLastName;
		std::tm DataDate{};
		Data >> DataId >> DataGivenName >> DataLastName >> std::get_time(&DataDate, "%Y-%m-%d");
		if (DataId >= 0 && DataId == MyId)
		{
			Birthday = DataDate;
			break;
		}
	}
}

std::ostream& operator<<(std::ostream& Stream, const Employee& Employee)
{
	Stream << "Employee{" << Employee.MyId << ": " << Employee.MyName << ", "
		   << std::put_time(&Employee.Birthday, "%Y-%m-%d") << ", "
		   << "$" << Employee.GetSalary()
		   << (Employee.IsBirthday() ? " ***It's their birthday!***" : "") << "}";
	return Stream;
}

bool Employee::IsBirthday() const
{
	std::time_t CurrentTime{std::time(nullptr)};
	std::tm CurrentDate{*localtime(&CurrentTime)};
	return (CurrentDate.tm_mday == Birthday.tm_mday && CurrentDate.tm_mon == Birthday.tm_mon);
}

double Employee::GetSalary() const
{
	double Salary{100.0};
	if (MyName.LastName == "Boss")
	{
		Salary += 1000.0;
	}
	if (MyName.GivenName.size() <= 3 || MyName.LastName.size() <= 3 || MyName.GivenName == "Bill")
	{
		Salary *= 1.1;
	}
	if (IsBirthday())
	{
		Salary += 150.0;
	}
	return Salary;
}
