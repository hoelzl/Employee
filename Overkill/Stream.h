//
// Created by tc on 2019-05-28.
//

#ifndef EMPLOYEE_STREAM_H
#define EMPLOYEE_STREAM_H

#include "Name.h"
#include "Employee.h"

namespace ok {
namespace entities {
std::ostream& operator<<(std::ostream& Stream, const Name& Name);
}

namespace core {
std::ostream& operator<<(std::ostream& Stream, const Employee& Employee);
}

} // namespace ok

#endif //EMPLOYEE_STREAM_H
