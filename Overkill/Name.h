//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_NAME_H
#define EMPLOYEE_NAME_H

#include <string>

namespace ok {
namespace entities {

class Name {
public:
    Name(std::string InGivenName, std::string InLastName);

    std::string GetGivenName() const;
    std::string GetLastName() const;
    std::string GetFullName() const;

private:
    std::string GivenName;
    std::string LastName;
};

} // namespace entities
} // namespace ok


#endif //EMPLOYEE_NAME_H
