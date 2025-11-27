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
  return frame_t{a.x(), a.y(), b.x(), b.y()};
}