#include "vector.h"


Vector::Vector(Point aa, Point bb): Planar(), a(aa), b(bb)
{
}


int Vector::x() const
{
  return b.x() - a.x();
}


int Vector::y() const
{
  return b.y() - a.y();
}


int Vector::abs_sqr() const
{
  return x() * x() + y() * y();
}

double Vector::area() const
{
  return 0;
}


frame_t Vector::frame() const
{
  int min_x = a.x() < b.x() ? a.x() : b.x();
  int min_y = a.y() < b.y() ? a.y() : b.y();
  int max_x = a.x() > b.x() ? a.x() : b.x();
  int max_y = a.y() > b.y() ? a.y() : b.y();
  return frame_t{p_t{min_x, min_y}, p_t{max_x, max_y}};
}
