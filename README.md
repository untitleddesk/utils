# UntitledLogger

Generic wrapper logger for my C++ projects.

It requires C++23 and uses functions like `std::println` and `std::format`.

You will need to compile it into a shared or static library to use it in your project.

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