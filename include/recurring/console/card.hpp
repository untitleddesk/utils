#pragma once

namespace Recurring::Console
{
  // The "kind" of any println. It's gonna be putted on the left side.
  struct Card
  {
    struct Color
    {
      // constexpr is for the compilation time
      // inline is for runtime

      static constexpr const char *RESET = "\033[0m";
      static constexpr const char *GREEN = "\033[32m";
      static constexpr const char *RED = "\033[31;4m";
      static constexpr const char *YELLOW = "\033[33m";
      static constexpr const char *WHITE = "\033[37m";
      static constexpr const char *GRAY = "\033[2;3m";
    };
    struct Title
    {
      static constexpr const char *GENERIC = "GENERIC";
      static constexpr const char *INFO = "INFO";
      static constexpr const char *ERROR = "ERROR";
      static constexpr const char *DEBUGGING = "DEBUG";
      static constexpr const char *WARNING = "WARNING";
    };
    const char *color = Color::WHITE;
    const char *title = Title::GENERIC;
  };
} // namespace Recurring::Console