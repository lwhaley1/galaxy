#include "Vector2.h"

#include <math.h>

#define PI 3.1415926535F
#define RADIAN_TO_DEGREE_FACTOR (360 / (2 * PI))

namespace Models::Geometry
{

float Vector2::GetMagnitude() const
{
  return sqrtf(powf(_dx, 2) + powf(_dy, 2));
}

float Vector2::GetRadians() const
{
  float rads = atan2f(_dy, _dx);
  if (rads < 0)
    rads += 2 * PI;
  return rads;
}

float Vector2::GetDegrees() const
{
  return GetRadians() * RADIAN_TO_DEGREE_FACTOR;
}

void Vector2::Rotate(float radians)
{
  float dx = (_dx * cosf(radians)) - (_dy * sinf(radians));
  float dy = (_dx * sinf(radians)) + (_dy * cosf(radians));

  _dx = dx;
  _dy = dy;
}

Vector2 Vector2::operator+(const Vector2 &o) const
{
  return Vector2(_dx + o.GetDX(), _dy + o.GetDY());
}

Vector2 Vector2::operator-(const Vector2 &o) const
{
  return Vector2(_dx - o.GetDX(), _dy - o.GetDY());
}

Vector2 Vector2::operator*(float scalar) const
{
  return Vector2(_dx * scalar, _dy * scalar);
}

Vector2 &Vector2::operator+=(const Vector2 &o)
{
  _dx += o.GetDX();
  _dy += o.GetDY();

  return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &o)
{
  _dx -= o.GetDX();
  _dy -= o.GetDY();

  return *this;
}

Vector2 &Vector2::operator*=(float scalar)
{
  _dx *= scalar;
  _dy *= scalar;

  return *this;
}

}