#pragma once

namespace Models::Geometry
{

class Vector2
{
public:
  Vector2(float dx, float dy) : _dx(dx), _dy(dy) {}
  virtual ~Vector2() {}

  inline float GetDX() const { return _dx; }
  inline float GetDY() const { return _dy; }

  inline void SetDX(float dx) { _dx = dx; }
  inline void SetDY(float dy) { _dy = dy; }
  inline void SetComponents(float dx, float dy) { SetDX(dx); SetDY(dy); }

  inline void InvertX() { _dx = -1 * _dx; }
  inline void InvertY() { _dy = -1 * _dy; }
  inline void InvertComponents() { InvertX(); InvertY(); }

  float GetMagnitude() const;
  // With respect to the +x axis. Positive = Counter-Clockwise. Negative = Clockwise.
  float GetRadians() const;
  // With respect to the +x axis. Positive = Counter-Clockwise. Negative = Clockwise.
  float GetDegrees() const;

  void Rotate(float radians);

  Vector2 operator+(const Vector2 &o) const;
  Vector2 operator-(const Vector2 &o) const;
  Vector2 operator*(float scalar) const;
  Vector2 &operator+=(const Vector2 &o);
  Vector2 &operator-=(const Vector2 &o);
  Vector2 &operator*=(float scalar);

private:
  float _dx;
  float _dy;
};

}