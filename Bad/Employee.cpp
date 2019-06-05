// Created by Matthias Hölzl on 2019-05-28.
//

#include "Employee.h"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

Name::Name(int id) : first_name_{"<no given name>"}, last_name_{"<no last name>"}
{
    std::ifstream data_{"employee-data.txt"};
    while (data_)
    {
        int data_id{-1};
        std::string data_given_name, data_last_name;
        std::tm data_date{};
        data_ >> data_id >> data_given_name >> data_last_name >>
            std::get_time(&data_date, "%Y-%m-%d");
        if (data_id >= 0 && data_id == id)
        {
            first_name_ = data_given_name;
            last_name_ = data_last_name;
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& stream, const Name& name)
{
    stream << name.first_name_ << " " << name.last_name_;
    return stream;
}

Employee::Employee(int id) : id_{id}, name_{id}, birthday_{}
{
    std::ifstream data{"employee-data.txt"};
    while (data)
    {
        int data_id{-1};
        std::string first_name, last_name;
        std::tm date{};
        data >> data_id >> first_name >> last_name >> std::get_time(&date, "%Y-%m-%d");
        if (data_id >= 0 && data_id == id)
        {
            birthday_ = date;
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& stream, const Employee& employee)
{
    stream << "Employee{" << employee.id_ << ": " << employee.name_ << ", "
           << std::put_time(&employee.birthday_, "%Y-%m-%d") << ", "
           << "$" << employee.GetSalary() << "}"
           << (employee.IsBirthday() ? " *** It's their birthday!*** " : "");
    return stream;
}

bool Employee::IsBirthday() const
{
    std::time_t current_time{std::time(nullptr)};
    std::tm current_date{*localtime(&current_time)};
    return (current_date.tm_mday == birthday_.tm_mday && current_date.tm_mon == birthday_.tm_mon);
}

double Employee::GetSalary() const
{
    double salary{100.0};
    if (name_.last_name_ == "Boss")
    {
        salary += 1000.0;
    }
    if (name_.first_name_.size() <= 3 || name_.last_name_.size() <= 3 ||
        name_.first_name_ == "Bill")
    {
        salary *= 1.1;
    }
    if (IsBirthday())
    {
        salary += 150.0;
    }
    return salary;
}
