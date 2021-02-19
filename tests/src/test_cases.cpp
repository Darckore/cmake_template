#include "libsomething/libsource.h"

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
  std::ifstream f{ TEST_BASE_DIR"/sample/some_test_file" };
  EXPECT_TRUE(f);

  std::string file_contents;
  EXPECT_TRUE(std::getline(f, file_contents));
  EXPECT_EQ(file_contents, "stub");
}

TEST(other_thingy, format)
{
  auto formatStr = "It is {1}, not {0}"sv;
  auto str = fmt::format(formatStr, 42, 23);
  EXPECT_EQ(str, "It is 23, not 42");
}


TEST(lib, msg)
{
  EXPECT_EQ(something::derpy::get_msg(), "Hai dere, m8\n");
}