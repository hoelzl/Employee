// Created by Matthias Hölzl on 2019-05-28.
//

#include "EmployeeFileReader.h"
#include <fstream>
#include <utility>

namespace ok::input_output
{

using ok::entities::Employee;

EmployeeFileReader::EmployeeFileReader(std::string file_name,
                                       std::shared_ptr<ok::use_cases::EmployeeFactory> generator)
    : file_name_{std::move(file_name)}, generator_{std::move(generator)}
{
}

std::vector<Employee> EmployeeFileReader::CreateEmployees() const
{
    std::ifstream data{file_name_};
    std::vector<Employee> result{};

    if (generator_)
    {
        CreateAndAddEmployees(data, result);
    }

    return result;
}

void EmployeeFileReader::CreateAndAddEmployees(std::ifstream& data,
                                               std::vector<Employee>& result) const
{
    while (data)
    {
        std::string line;
        std::getline(data, line);
        CreateAndAddEmployee(line, result);
    }
}
void EmployeeFileReader::CreateAndAddEmployee(const std::string& line,
                                              std::vector<Employee>& result) const
{
    std::optional<Employee> Employee{generator_->CreateEmployee(line)};
    if (Employee.has_value())
    {
        result.emplace_back(Employee.value());
    }
}

} // namespace ok::input_output
