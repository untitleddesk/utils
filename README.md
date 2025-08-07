# UntitledUtils

A C++ library for my projects.

## UntitledLogger

Generic wrapper logger.

```cpp
#include <untitled/console/logger.hh>
using Log = Untitled:Console::Logger;

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

## UntitledMath

Library for studying mathematical operations.

```cpp
#include <untitled/math/functions/square_root.hpp>
using sqrt = Untitled::Math::square_root;
int main()
{
    float x = 9;
    float x_squared = sqrt(x);
    return 0;
}
```