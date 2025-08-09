#pragma once
#include <recurring/utils/string.hpp>
namespace Recurring::Console
{
  struct Card;
  class Logger
  {
    static inline bool debug_mode = false;

  public:
    static void set_debug(bool mode);

    template <typename... Args>
    static void
    print(const Card &card, const String &description, Args... args);
    template <typename... Args>
    static void print(const String &description, Args... args);
  };
} // namespace Recurring::Console