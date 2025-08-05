#include "logger.hh"
#include <iostream>
using Log = Untitled::CLI::Logger;
using String = Untitled::String;
int main()
{
    String string = "Hello, world!\n";
    Log::print(string);
    return 0;
}