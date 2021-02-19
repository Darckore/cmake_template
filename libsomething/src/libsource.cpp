#include "libsomething/libsource.h"

namespace something::detail
{
  void init_console();
}

namespace something
{
  void derpy::init()
  {
    detail::init_console();
  }

  void derpy::msg()
  {
    constexpr auto textClr = bg(fmt::color::ghost_white) | fg(fmt::color::crimson);
    fmt::print(textClr, get_msg());
  }

  std::string derpy::get_msg()
  {
    return fmt::format(FMT_COMPILE("{} {}, {}\n"), "Hai", "dere", "m8");
  }
}