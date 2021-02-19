#pragma once

namespace something
{
  class derpy
  {
  public:
    derpy() = delete;
    derpy(const derpy&) = delete;
    derpy(derpy&&) = delete;
    derpy& operator=(const derpy&) = delete;
    derpy& operator=(derpy&&) = delete;

    static void msg();
    static std::string get_msg();
  };
}