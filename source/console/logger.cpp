#include <recurring/console/logger.hpp>
#include <print>
#include <recurring/utils/string.hpp>
namespace Recurring::Console
{
  namespace Internal
  {
    void print_raw(const char *description);
  };
  namespace System
  {
    static constexpr int write = 1;
  }

  // I remember syscall while trying learning assembly x86
  // Idk how exactly it works here. syscall depends the OS
  // Like, move this stuff to the memory. Call this thing from the memory and
  // use it. Or write this const char* to the buffer. This can help, but idk.
  // https://gist.github.com/GabriOliv/a9411fa771a1e5d94105cb05cbaebd21
  // unistd.h provides it. I'm still wanna learn it from ""scratch"".
  // Apparently this syscall use libc. Roger.
  extern "C" long syscall(long id, long rdi = 0, long rsi = 0, long rdx = 0,
                          long r10 = 0, long r8 = 0, long r9 = 0);

  void Internal::print_raw(const char *description)
  {
    if(description == nullptr)
      {
        return;
      }
    // Not using anymore. Because I gotta project my own formatter!
    std::print("{}", description);
  }

  template <typename... Args>
  void Logger::print(const String &description, Args... args)
  {
    Internal::print_raw(String::format(description, args...).raw());
  }

  template void Logger::print<>(const String &);
  template void Logger::print<const char *>(const String &, const char *);
  template void Logger::print<int>(const String &, int);

  // template<typename... Args>
  // void Logger::print(const Card& card, String description, Args&... args);

  void Logger::set_debug(bool mode) { debug_mode = mode; }
} // namespace Recurring::Console
