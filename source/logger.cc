#include "logger.hh"
namespace Untitled
{
    int String::length_raw(literal string)
    {
        int length;
        // Each string ends with '\0'. Thanks compiler
        // So, I can do this:
        for (length = 0; string[length] != '\0'; ++length);
        return length;
    }
    int String::length() const
    {
        return length_raw(data);
    }
    int String::length(literal string)
    {
        return length_raw(string);
    }

    String::String(literal from)
    {
        // data = (char*)from; // Not making this. Because it's gonna share the same value as from.

        data = new char[length(from)] + 1; // 1 is for fixing the size

        for (int i = 0; i < length(from); ++i)
            data[i] = from[i];
    }

    String String::operator=(literal from)
    {
        return from;
    }
    String String::operator=(const String& from)
    {
        return from;
    }
}
namespace Untitled::CLI
{
    namespace System
    {
        static constexpr int write = 1;
    }

    // I remember syscall while trying learning assembly x86
    // Idk how exactly it works here. syscall depends the OS
    // Like, move this stuff to the memory. Call this thing from the memory and use it. Or write this literal to the buffer.
    // This can help, but idk. https://gist.github.com/GabriOliv/a9411fa771a1e5d94105cb05cbaebd21
    // unistd.h provides it. I'm still wanna learn it from ""scratch"".
    // Apparently this syscall use libc. Roger.
    extern "C" long syscall(long id, long rdi = 0, long rsi = 0, long rdx = 0, long r10 = 0, long r8 = 0, long r9 = 0);

    void Logger::Internal::print_raw(literal description)
    {
        syscall((long)System::write, 1, (long)description, (long)String::length(description));
    }
    
    template<typename T, typename... Args>
    void Logger::print(T description, Args... args)
    {
        Internal::print_raw(description);
    }

    template<typename T, typename... Args>
    void Logger::println(T description, Args... args)
    {
        print_raw(description);
    }

    template void Logger::print<const char*>(const char*);

    template<typename T>
    static void print(const Card& card, T description);
    template<typename T>
    static void print(T description);

    void Logger::set_debug(bool mode)
    {
        debug_mode = mode;
    }
} // namespace UntitledDesk
