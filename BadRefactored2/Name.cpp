//
// Created by tc on 2019-06-05.
//

#include "Name.h"
#include <ctime>
#include <fstream>

Name::Name(std::string first_name, std::string last_name)
        : first_name_{first_name}, last_name_{last_name}
{
}

std::ostream& operator<<(std::ostream& stream, const Name& name)
{
    stream << name.first_name_ << " " << name.last_name_;
    return stream;
}
