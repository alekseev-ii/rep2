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


double Point::area() const
{
  return 0;
}


frame_t Point::frame() const
{
  int min_x = x() < 0 ? x() : 0;
  int min_y = y() < 0 ? y() : 0;
  int max_x = x() > 0 ? x() : 0;
  int max_y = y() > 0 ? y() : 0;
  return frame_t{p_t{min_x, min_y}, p_t{max_x, max_y}};
}
