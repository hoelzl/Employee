//
// Created by tc on 2019-06-05.
//

#ifndef EMPLOYEE_CALENDARREADER_H
#define EMPLOYEE_CALENDARREADER_H

#include "Time.h"
#include "Location.h"
#include <map>

class CalendarReader {
public:
    virtual std::map<Time, Location> ReadCalenderData(int employee_id) const = 0;
};



#endif // EMPLOYEE_CALENDARREADER_H
