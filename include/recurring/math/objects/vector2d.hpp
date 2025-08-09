#pragma once
namespace Recurring::Math
{
  struct Vector2D
  {
    float x, y;
    float length() const;
    Vector2D(float x = 0.0f, float y = 0.0f);
    Vector2D operator+(const Vector2D &right_hand_side) const;
    Vector2D operator-(const Vector2D &right_hand_side) const;
  };
} // Recurring::Math