#include "logger.hh"
#include <format>
#include <iostream>
#include <string>

using namespace UntitledDesk; // Don't use this. It's bad.

int main()
{
    Logger::set_debug(true);
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