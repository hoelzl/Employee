#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Matthias Hölzl on 2019-05-29.
//
#include "../../Entities/Name.h"
#include <gmock/gmock.h>

namespace
{
using ok::entities::Name;
using namespace testing;

TEST(Name, Constructor_CorrectlyInitializesState)
{
    Name unit{"Phil", "Collins"};
    ASSERT_THAT(unit.GetFirstName(), Eq("Phil"));
    ASSERT_THAT(unit.GetLastName(), Eq("Collins"));
}

TEST(Name, GetFullName_ReturnsFullName)
{
    Name unit{"Joe", "Cocker"};
    ASSERT_THAT(unit.GetFullName(), Eq("Joe Cocker"));
}

} // namespace
#pragma clang diagnostic pop
