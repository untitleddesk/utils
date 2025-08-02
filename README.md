Generic logger made in C++ for my projects. It uses 23 standard, `std::println()` and `std::format()`.

I've got to compile it into a shared or static library to use it!

```cpp
#include <untitled/logger.hh>
using Log = UntitledDesk::Logger;

int main(void)
{
    Log::print("Hello, world!");
    return 0;
}
```

Features:
- Cards (aka tags)
- Colors
- Template

What it doesn't have:
- Inifite args