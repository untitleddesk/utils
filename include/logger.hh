#ifndef UNTITLED_LOGGER_HH
#define UNTITLED_LOGGER_HH
namespace Untitled
{
    using literal = const char*;
    struct String
    {
    private:
        static int length_raw(literal string);
    public:
        char* data;

        String(literal from);
        
        // Why do I need making a constructor to use operator???
        
        String operator=(literal from);
        String operator=(const String& from);

        int length() const;
        static int length(literal from);
    };
}
namespace Untitled::CLI
{
    // The "kind" of any println. It's gonna be putted on the left side.
    struct Card
    {
        struct Color
        {
            // constexpr is for the compilation time
            // inline is for runtime

            static constexpr literal RESET = "\033[0m";
            static constexpr literal GREEN = "\033[32m";
            static constexpr literal RED = "\033[31;4m";
            static constexpr literal YELLOW = "\033[33m";
            static constexpr literal WHITE = "\033[37m";
            static constexpr literal GRAY = "\033[2;3m";
        };
        struct Title
        {
            static constexpr literal GENERIC = "GENERIC";
            static constexpr literal INFO = "INFO";
            static constexpr literal ERROR = "ERROR";
            static constexpr literal DEBUGGING = "DEBUG";
            static constexpr literal WARNING = "WARNING";
        };
        literal color = Color::WHITE;
        literal title = Title::GENERIC;
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
        template<typename T, typename... Args>

        static void print(const Card& card, T description, Args... args);
        template<typename T, typename... Args>
        static void print(T description, Args... args);
        
        template<typename T, typename... Args>
        static void println(const Card& card, T description, Args... args);
        template<typename T, typename... Args>
        static void println(T description, Args... args);
    private:
        struct Internal
        {
            static void print_raw(literal description);
        };
    };
} // namespace Untitled::CLI

#endif // UNTITLED_LOGGER_HH