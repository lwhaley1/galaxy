#pragma once

namespace Models::Geometry
{

class Rect
{
public:
  Rect(float x, float y, float w, float h, float rotation = 0.0F)
    : _x(x), _y(y), _w(w), _h(h), _rotation(rotation) {}
  virtual ~Rect() {}

  inline float GetX() const { return _x; }
  inline float GetY() const { return _y; }
  inline float GetWidth() const { return _w; }
  inline float GetHeight() const { return _h; }
  // With respect to the +x axis. Positive = Counter-Clockwise. Negative = Clockwise.
  inline float GetRotationRadians() const { return _rotation; }

  inline void SetX(float x) { _x = x; }
  inline void SetY(float y) { _y = y; }
  inline void SetWidth(float w) { _w = w; }
  inline void SetHeight(float h) { _h = h; }
  inline void Rotate(float rotation) { _rotation += rotation; }

  bool Intersects(const Rect &o) const;

private:
  float _x;
  float _y;
  float _w;
  float _h;
  float _rotation;

  bool IntersectX(const Rect &o) const;
  bool IntersectY(const Rect &o) const;
};

}