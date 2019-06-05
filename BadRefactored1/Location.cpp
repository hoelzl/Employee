//
// Created by Dr. Matthias Hölzl (tc) on 2019-06-05.
//

#include "Location.h"

Location::Location(int building_number) : buildingNumber(building_number)
{
}

bool operator==(Location lhs, Location rhs)
{
    if (lhs.buildingNumber < 0 || rhs.buildingNumber < 0)
    {
        return false;
    }
    return lhs.buildingNumber == rhs.buildingNumber;
}
std::ostream& operator<<(std::ostream& stream, const Location& location)
{
    stream << "{Location: building " << location.buildingNumber << "}";
    return stream;
}
