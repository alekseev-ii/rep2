#include "quadrangle.h"

#include "cstddef"


int Quadrangle::x() const
{
  return first().x();
}


int Quadrangle::y() const
{
  return first().y();
}


int Quadrangle::abs_sqr() const
{
  return first().abs_sqr();
}


double Quadrangle::get_area() const
{
  double area1 = (a().x() * (b().y() - c().y()) +
                  b().x() * (c().y() - a().y()) + c().x() * (a().y() - b().y())) / 2;
  double area2 = (d().x() * (b().y() - c().y()) +
                  b().x() * (c().y() - d().y()) + c().x() * (d().y() - b().y())) / 2;
  return area1 + area2;
}


frame_t Quadrangle::get_frame() const
{
  int min_x = data[0].x();
  int min_y = data[0].y();
  int max_x = data[0].x();
  int max_y = data[0].y();
  for (size_t i = 1; i < 4; ++i) {
    if (data[i].x() < min_x) {
      min_x = data[i].x();
    }
    if (data[i].y() < min_y) {
      min_y = data[i].y();
    }
    if (data[i].x() > max_x) {
      max_x = data[i].x();
    }
    if (data[i].y() > max_y) {
      max_y = data[i].y();
    }
  }
  return frame_t{min_x, min_y, max_x, max_y};
}


Point Quadrangle::first() const
{
  Point first = data[0];
  for (size_t i = 1; i < 4; ++i) {
    if (first.abs_sqr() > data[i].abs_sqr()) {
      first = data[i];
    }
  }
  return first;
}


Point Quadrangle::a() const
{
  return data[0];
}


Point Quadrangle::b() const
{
  return data[1];
}


Point Quadrangle::c() const
{
  return data[2];
}


Point Quadrangle::d() const
{
  return data[3];
}
