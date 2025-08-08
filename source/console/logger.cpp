#include <untitled/console/logger.hpp>
namespace Untitled
{
  int String::length_raw(const char *string)
  {
    int length;
    // Each string ends with '\0'. Thanks compiler
    // So, I can do this:
    for(length = 0; string[length] != '\0'; ++length)
      ;
    return length;
  }
  int String::length() const { return length_raw(data); }
  int String::length(const char *string) { return length_raw(string); }

  String::String(const char *from)
  {
    // data = (char*)from; // Not making this. Because it's gonna share the
    // same value as from.

    data = new char[length(from) + 1]; // 1 is for fixing the size

    for(int i = 0; i < length(from); ++i)
      data[i] = from[i];
  }
  String::~String()
  {
    if(data != nullptr)
      {
        delete data;
      }
  }
  String::String() : data(nullptr) {}

  // Returns the raw data for specifics things.
  // As the c_str().
  const char *String::raw() const { return data; }

  String String::operator=(const char *from) { return from; }
  String String::operator=(const String &from) { return from; }
} // namespace Untitled
namespace Untitled::Console
{
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

  void Logger::Internal::print_raw(const char *description)
  {
    if(description == nullptr)
      {
        return;
      }
    syscall((long)System::write, 1, (long)description,
            (long)String::length(description));
  }

  template <typename... Args>
  void Logger::print(const String &description, Args... args)
  {
    Internal::print_raw(description.raw());
  }

  template void Logger::print<>(const String &);
  template void Logger::print<const char *>(const String &, const char *);
  template void Logger::print<int>(const String &, int);

  // template<typename... Args>
  // void Logger::print(const Card& card, String description, Args&... args);

  void Logger::set_debug(bool mode) { debug_mode = mode; }
} // namespace Untitled::Console
