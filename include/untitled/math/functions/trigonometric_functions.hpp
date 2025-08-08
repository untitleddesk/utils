#pragma once
namespace Untitled::Math
{
  /**
   * @brief The "X" value of a circle.
   *
   * @tparam T
   * @param angle In radians
   * @return T
   */
  template <typename T> T sine(T angle);

  /**
   * @brief The "Y" value of a circle
   *
   * @tparam T
   * @param angle
   * @return T
   */
  template <typename T> T cosine(T angle);

  /**
   * @brief The "mix" of the sine and cosine.
   *
   * @tparam T
   * @param angle
   * @return T
   */
  template <typename T> T tangent(T angle);
} // namespace Untitled::Math