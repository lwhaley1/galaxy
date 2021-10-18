#include "Rect.h"
#include "Vector2.h"

namespace Models::Geometry
{

bool Rect::Intersects(const Rect &o) const
{
  Vector2 this_rect (_x, _y);
  Vector2 other_rect (o.GetX(), o.GetY());

  this_rect.Rotate(-1 * _rotation);
  other_rect.Rotate(-1 * _rotation);

  // Get something drawing to screen here so we can visually debug this logic.
  bool xcheck = ((other_rect.GetDX() + o.GetWidth()) > this_rect.GetDX()) && ((this_rect.GetDX() + _w) > other_rect.GetDX());
  bool ycheck = ((other_rect.GetDY() + o.GetHeight()) > this_rect.GetDY()) && ((this_rect.GetDY() + _h) > other_rect.GetDY()); 

  return xcheck && ycheck;
}

}