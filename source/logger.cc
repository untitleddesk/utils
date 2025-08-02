#include "logger.hh"
#include <cstring>
#include <format>
#include <string>
#include <print>

namespace UntitledDesk
{
void Logger::set_debug(bool mode)
{
    debug_mode = mode;
}

template<typename T>
void Logger::print(const Card& card, T description)
{
    if (!debug_mode && std::strcmp(card.title, Card::Title::DEBUGGING) == 0) return;
    std::string card_colored = std::format("{1}{0}{2}", card.title, card.color, Card::Color::RESET);
    if (std::strcmp(card.title, Card::Title::ERROR) == 0)
    {
        std::println(stderr, "[{1}] {0}", description, card_colored);
        return;
    }
    std::println(stdout, "[{1}] {0}", description, card_colored);

}

template<typename T>
void Logger::print(T description)
{
    std::println(stdout, "{}", description);
}

template void Logger::print<std::string>(std::string);
template void Logger::print<const char*>(const char*);

template void Logger::print<std::string>(const Card&, std::string);
template void Logger::print<const char*>(const Card&, const char*);
}
