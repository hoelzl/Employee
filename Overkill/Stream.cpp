//
// Created by tc on 2019-05-28.
//

#include <iostream>
#include "Stream.h"

namespace ok {
namespace entities {

std::ostream& operator<<(std::ostream& Stream, const Name& Name) {
    Stream << Name.GetFullName();
    return Stream;
}
} // namespace entities

namespace core {
std::ostream& operator<<(std::ostream& Stream, const Employee& Employee) {
    Stream << "Employee{" << Employee.GetId() << ": " << Employee.GetName().GetFullName() << "}";
    return Stream;
}
} // namespace core
} // namespace ok
