#include "logger.hh"
#include <format>
#include <iostream>
#include <string>

// This file is only for testing this project. It's ugly, and I know that.

using namespace UntitledDesk; // Don't use this. It's bad.

struct Vector2
{
    int x, y;
};

template<>
void Logger::print<Vector2>(const Card& card, Vector2 description)
{
    std::string formatted = std::format("[{0}, {1}]", description.x, description.y);
    Internal::print_raw(card, formatted.c_str());
}

template<>
void Logger::print<int>(int description)
{
    Internal::print_raw(std::to_string(description).c_str());
}

int main()
{
    Logger::set_debug(true);
    Logger::print(10 + 10);

    Vector2 vec2 = {1920, 1080};

    Logger::print(Logger::INFO, vec2);
    std::cout << "standard printing\n";

    Logger::print(Logger::DEBUGGING, std::format("Hello, world! -> {}", 10e2));
    Logger::print(Logger::GENERIC, std::format("Hello, world! -> {}", 0));
    Logger::print(Logger::ERROR, std::format("Hello, world! -> {}", 10 * 2));
    Logger::print(Logger::INFO, std::format("Hello, world! -> {}", 20));
    Logger::print(Logger::WARNING, std::format("Hello, world! -> {}", 1000));

    Logger::print("NO CARD");

    std::string stringing = "TESTING";
    const char* charace = "suzu";

    std::string new_string = std::format("THIS -> {} {}", stringing, charace);
    Logger::print(Logger::DEBUGGING, new_string);
    return 0;
}