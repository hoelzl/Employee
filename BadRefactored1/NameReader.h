//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_NAMEREADER_H
#define EMPLOYEE_NAMEREADER_H

#include <string>

struct NameData
{
    std::string first_name_;
    std::string last_name_;
};

class NameReader
{
public:
    virtual NameData readName(int id) const = 0;
};

#endif // EMPLOYEE_NAMEREADER_H
