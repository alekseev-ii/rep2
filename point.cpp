#include "point.h"


Point::Point(int xx, int yy): Planar(), data{xx, yy}
{
}


int Point::x() const
{
  return data[0];
}


int Point::y() const
{
  return data[1];
}


int Point::abs_sqr() const
{
  return x() * x() + y() * y();
}


double Point::get_area() const
{
  return 0;
}


frame_t Point::get_frame() const
{
  return frame_t{0, 0, x(), y()};
}
