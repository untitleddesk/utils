#include "logger.hh"
#include <iostream>
using Log = Untitled::CLI::Logger;
using String = Untitled::String;
int main()
{
    Log::print("Hello, world!\n");
    String string_0 = "Testing\n";
    String string_1 = string_0;
    std::cout << string_1.data;
    return 0;
}