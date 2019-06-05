//
// Created by tc on 2019-05-28.
//

#include "DefaultEmployeeListPrinter.h"
#include "../Entities/Employee.h"
#include <algorithm>

namespace ok::use_cases
{

DefaultEmployeeListPrinter::DefaultEmployeeListPrinter(std::ostream& ostream) : Stream{&ostream}
{
}

DefaultEmployeeListPrinter::~DefaultEmployeeListPrinter()
{
    Stream = nullptr;
}
void DefaultEmployeeListPrinter::PrintEmployee(const ok::entities::Employee& employee) const
{
    if (Stream)
    {
        *Stream << employee << std::endl;
    }
}

} // namespace ok::use_cases
