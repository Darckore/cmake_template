#ifdef WIN32
  #include "libsomething/win_includes.h"
#endif

namespace something::detail
{
  void init_console()
  {
#ifdef WIN32
    auto console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (console == INVALID_HANDLE_VALUE)
      return;

    if (DWORD mode = 0; GetConsoleMode(console, &mode))
    {
      SetConsoleMode(console, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
#endif
  }
}
