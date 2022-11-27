#include "cpp-template/Algorithm.h"

#include <gtest/gtest.h>


TEST(AlgorithmTest, CheckSum)
{
  ASSERT_EQ(AddTwoNumbers(1.1, 2.15), 3.25);
  ASSERT_EQ(AddTwoNumbers(2, 1), 3);
}
