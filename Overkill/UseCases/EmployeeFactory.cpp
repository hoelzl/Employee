//
// Created by Matthias Hölzl on 2019-05-28.
//

#include "EmployeeFactory.h"
#include <iomanip>
#include <sstream>

namespace ok::use_cases
{

using ok::entities::Employee;

std::optional<Employee> EmployeeFactory::CreateEmployee(const std::string& employee_data) const
{
    int id{-1};
    std::string first_name, last_name;
    std::tm date{};
    std::stringstream data{employee_data};
    data >> id >> first_name >> last_name >> std::get_time(&date, "%Y-%m-%d");
    if (id >= 0)
    {
        return Employee{id, ok::entities::Name{first_name, last_name}, date};
    }
    else
    {
        return std::nullopt;
    }
}
} // namespace ok::use_cases
