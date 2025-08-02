#ifndef LOGGER_HH
#define LOGGER_HH
namespace UntitledDesk
{
class Logger
{
    static inline bool debug_mode = false;
public:
    using literal = const char*;
    static void set_debug(bool mode);
    // THe "kind" of any println. It's gonna be putted on the left side.
    struct Card
    {
        struct Color
        {
            static inline literal RESET = "\e[0m";
            static inline literal GREEN = "\033[32m";
            static inline literal RED = "\033[31;4m";
            static inline literal YELLOW = "\033[33m";
            static inline literal WHITE = "\033[37m";
            static inline literal GRAY = "\033[2;3m";
        };
        struct Title
        {
            static inline literal GENERIC = "GENERIC";
            static inline literal INFO = "INFO";
            static inline literal ERROR = "ERROR";
            static inline literal DEBUGGING = "DEBUG";
            static inline literal WARNING = "WARNING";
        };
        literal color{Color::WHITE};
        literal title{Title::GENERIC};
    };
    static inline Card WARNING{Card::Color::YELLOW, Card::Title::WARNING};
    static inline Card INFO{Card::Color::GREEN, Card::Title::INFO};
    static inline Card ERROR{Card::Color::RED, Card::Title::ERROR};
    static inline Card DEBUGGING{Card::Color::GRAY, Card::Title::DEBUGGING};
    static inline Card GENERIC{Card::Color::WHITE, Card::Title::GENERIC};

    template<typename T>
    static void print(const Card& card, T description);
    template<typename T>
    static void print(T description);
};
}

#endif // LOGGER_HH