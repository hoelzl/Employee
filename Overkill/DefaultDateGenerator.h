//
// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_DEFAULTDATEGENERATOR_H
#define EMPLOYEE_DEFAULTDATEGENERATOR_H

#include <ctime>
#include "DateGenerator.h"

namespace ok {
namespace entities {

class DefaultDateGenerator : public DateGenerator {
public:
    std::tm Today() const override;
    std::tm ParseDate(const char* Date) const override;
};

} // namespace entities
} // namespace ok

#endif //EMPLOYEE_DEFAULTDATEGENERATOR_H
