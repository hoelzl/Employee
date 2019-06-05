#include "Employee.h"
#include <iostream>

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        Employee employee{i};
        std::cout << "We present: " << employee << std::endl;
    }
    return 0;
}
