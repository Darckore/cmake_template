#include "libsource.h"

namespace something
{
  void derpy::msg()
  {
    fmt::print(get_msg());
  }

  std::string derpy::get_msg()
  {
    return fmt::format("{} {}, {}\n", "Hai", "dere", "m8");
  }
}