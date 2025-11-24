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
