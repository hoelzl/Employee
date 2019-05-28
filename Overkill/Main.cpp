// Created by Matthias Hölzl on 2019-05-28.
//

#include <iostream>
#include "Employee.h"
#include "Name.h"
#include "Stream.h"

using ok::entities::Name;
using ok::core::Employee;

int main() {
    for (int i = 0; i < 5; ++i) {
        Employee employee{i, Name{"Foo", "Bar"}, std::tm{}};
        std::cout << "We present: " << employee << std::endl;
    }
    return 0;
}
