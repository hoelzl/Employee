#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Matthias Hölzl on 2019-05-28.
//
#include <gmock/gmock.h>

namespace
{

TEST(Employee, AlwaysSucceed)
{
    ASSERT_TRUE(true);
}

} // namespace
#pragma clang diagnostic pop
