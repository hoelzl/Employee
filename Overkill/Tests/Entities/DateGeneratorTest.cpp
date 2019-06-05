#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by Matthias Hölzl on 2019-05-29.
//
#include <gmock/gmock.h>
#include "../../Entities/DateGenerator.h"
namespace
{

using namespace testing;

class TestDateGenerator : public ok::entities::DateGenerator {
public:
	tm Today() const override
	{
		return tm();
	}
};

TEST(DateGenerator, ParseDate_ParsesCorrectly)
{
    TestDateGenerator unit{};
    // Years are stored as offset from 1900.
	ASSERT_THAT(unit.ParseDate("2019-05-29").tm_year, Eq(2019 - 1900));
	// Month are stored with 0-based index.
    ASSERT_THAT(unit.ParseDate("2019-05-29").tm_mon, Eq(5 - 1));
    ASSERT_THAT(unit.ParseDate("2019-05-29").tm_mday, Eq(29));
}

} // namespace
#pragma clang diagnostic pop
