#include "math/functions/square_root.hh"
#include "math/objects/vector2d.hh"
#include <untitled/logger.hh>
#include <format>
using Log = UntitledDesk::Logger;
using Vec2 = Untitled::Math::Vector2D;
namespace Math = Untitled::Math;
int main(int argc, char* argv[])
{
    Log::print(Log::INFO, "OK");
    Vec2 vector = Vec2(10.0f, 30.5f);
    Log::print(std::format("{}, {}", vector.x, vector.y));

    float number = 10.0f;
    Log::print(std::format("Square root of {} -> {}", number, Math::square_root(number)));
    return 0;
}