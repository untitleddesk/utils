#include "math/constants.hpp"
#include "math/functions/convert.hpp"
#include "math/functions/square_root.hpp"
#include "math/functions/trigonometry.hpp"
#include <xmmintrin.h>

namespace Untitled::Math
{
    float radians_to_degrees(float number_in_radians)
    {
        const float number_in_degrees = number_in_radians * (180.0f / PI);
        return number_in_degrees;
    }

    float degrees_to_radians(float number_in_degrees)
    {
        float number_in_radians = number_in_degrees * (180.0f / PI);
        return number_in_radians;
    }

    // @todo #3 Implement all most important trigonometric functions

    float sine(float number)
    {
        return 0.0;
    }
    float cosine(float number)
    {
        return 0.0f;
    }
    float tangent(float number)
    {
        return 0.0f;
    }



    float square_root(float number)
    {
        // This will break in a few of CPUs. Just for tests
        // cmath makes this better btw
        if (number <= 0.0f) return 0.0f;
        __m128 value = _mm_set_ss(number); // Asking for CPU 'generate memory with' using SIMD
        __m128 result = _mm_sqrt_ss(value); // CPU makes the magic
        return _mm_cvtss_f32(result); // "CPU, convert convert to float"
    }
    
    // namespace Internal
    // {
    //     constexpr int max_iterations = 10;
    // }
    // double square_root(double number)
    // {
    //     // trying to learn newton's method. generic, ik
    //     // f(x) = (x^2)-2
    //     // f'(x) = 2*x
    //     // I wanna learn bitwise to make it like Quake HAHAHA

    //     if (number <= 0.0f)
    //         return 0.0;

    //     double result = number;
    //     for (int i = 0; i < Internal::max_iterations; ++i)
    //     {
    //         // result = ((result * result) + number) / (result * 2.0f);
    //         result = (result + number / result) / 2.0;
    //     }
    //     return result;
    // }
    // float square_root(float number)
    // {
    //     if (number <= 0.0f)
    //         return 0.0;

    //     float result = number;
    //     for (int i = 0; i < Internal::max_iterations; ++i)
    //     {
    //         result = (result + number / result) / 2.0f;
    //     }
    //     return result;
    // }
} // namespace Untitled::Math