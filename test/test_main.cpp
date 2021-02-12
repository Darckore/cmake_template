#include "gtest/gtest.h"

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(thingy, derpy)
{
  EXPECT_EQ(1, 1);
}

TEST(thingy, herpy)
{
  EXPECT_EQ(1, 2);
}