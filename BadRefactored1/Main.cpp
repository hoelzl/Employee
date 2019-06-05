#include "CalendarFileReader.h"
#include "Employee.h"
#include <iostream>

int main()
{
    CalendarFileReader calendar_file_reader{"employee-calendars.txt"};

    std::cout << "Employee List\n\n";
    for (int i = 0; i < 5; ++i)
    {
        Employee employee{i, calendar_file_reader};
        std::cout << employee << std::endl;
    }
    return 0;
}
