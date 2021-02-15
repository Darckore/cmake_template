#include "gtest/gtest.h"

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(thingy, derpy)
{
  EXPECT_EQ(42, 42);
}

TEST(thingy, herpy)
{
  EXPECT_TRUE(42 != 69);
}

TEST(other_thingy, file)
{
  std::ifstream f{ "sample/some_test_file" };
  EXPECT_TRUE(f);

  std::string file_contents;
  EXPECT_TRUE(std::getline(f, file_contents));
  EXPECT_EQ(file_contents, "stub");
}