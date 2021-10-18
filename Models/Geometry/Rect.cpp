#include "Rect.h"
#include "Vector2.h"

#include <math.h>

namespace Models::Geometry
{

bool Rect::Intersects(const Rect &o) const
{
  return IntersectX(o) && IntersectY(o);
}

bool Rect::IntersectX(const Rect &o) const
{
  float dx = _w * cosf(_rotation);
  float dy = _w * sinf(_rotation);

  float odx = o.GetWidth() * cosf(o.GetRotationRadians());
  float ody = o.GetWidth() * sinf(o.GetRotationRadians());

  Vector2 source (dx, dy);
  Vector2 target (odx, ody);
  target.Rotate(_rotation - o.GetRotationRadians());

  return ((_x + source.GetMagnitude()) > o.GetX()) && ((o.GetX() + target.GetMagnitude()) > _x);
}

bool Rect::IntersectY(const Rect &o) const
{
  // TODO: Get y-axis intersections working.

  return false;
}

}