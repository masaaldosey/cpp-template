#include <adder/plus_one.hpp>
#include <gtest/gtest.h>

TEST(AdderTest, CheckSum)
{
	ASSERT_EQ(adder::plus_one(0), 1);
	ASSERT_EQ(adder::plus_one(123), 124);
	ASSERT_EQ(adder::plus_one(-1), 0);
}
