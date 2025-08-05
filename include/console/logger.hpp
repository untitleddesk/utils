#ifndef UNTITLED_LOGGER_GUARD
#define UNTITLED_LOGGER_GUARD
#include "string.hpp"
namespace Untitled::Console
{
    // The "kind" of any println. It's gonna be putted on the left side.
    struct Card
    {
        struct Color
        {
            // constexpr is for the compilation time
            // inline is for runtime

            static constexpr const char* RESET = "\033[0m";
            static constexpr const char* GREEN = "\033[32m";
            static constexpr const char* RED = "\033[31;4m";
            static constexpr const char* YELLOW = "\033[33m";
            static constexpr const char* WHITE = "\033[37m";
            static constexpr const char* GRAY = "\033[2;3m";
        };
        struct Title
        {
            static constexpr const char* GENERIC = "GENERIC";
            static constexpr const char* INFO = "INFO";
            static constexpr const char* ERROR = "ERROR";
            static constexpr const char* DEBUGGING = "DEBUG";
            static constexpr const char* WARNING = "WARNING";
        };
        const char* color = Color::WHITE;
        const char* title = Title::GENERIC;
    };
    class Logger
    {
        static inline bool debug_mode = false;
    public:
        static constexpr Card WARNING = { Card::Color::YELLOW, Card::Title::WARNING };
        static constexpr Card INFO = { Card::Color::GREEN, Card::Title::INFO} ;
        static constexpr Card ERROR = { Card::Color::RED, Card::Title::ERROR};
        static constexpr Card DEBUGGING = { Card::Color::GRAY, Card::Title::DEBUGGING };
        static constexpr Card GENERIC = { Card::Color::WHITE, Card::Title::GENERIC };
        
        static void set_debug(bool mode);

        template<typename... Args>
        static void print(const Card& card, const String& description, Args... args);
        template<typename... Args>
        static void print(const String& description, Args... args);
    private:
        struct Internal
        {
            static void print_raw(const char* description);
        };
    };
} // namespace Untitled::CLI

#endif // UNTITLED_LOGGER_GUARD