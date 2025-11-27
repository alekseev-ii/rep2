#include "triangle.h"

#include <stdexcept>


Triangle::Triangle(Point aa, Point bb, Point cc): data{aa, bb, cc}
{
  if (area() == 0) {
    throw std::logic_error("bad triangle");
  }
}


int Triangle::x() const
{
  return first().x();
}


int Triangle::y() const
{
  return first().y();
}


int Triangle::abs_sqr() const
{
  return first().abs_sqr();
}


double Triangle::area() const
{
  return (a().x() * (b().y() - c().y()) +
          b().x() * (c().y() - a().y()) + c().x() * (a().y() - b().y())) / 2;
}


frame_t Triangle::frame() const
{
  int min_x = data[0].x();
  int min_y = data[0].y();
  int max_x = data[0].x();
  int max_y = data[0].x();
  for (int i = 1; i < 3; ++i) {
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
}


Point Triangle::first() const
{
  Point fst = data[0];
  for (int i = 1; i < 3; ++i) {
    if (fst.abs_sqr() > data[i].abs_sqr()) {
      fst = data[i];
    }
  }
  return fst;
}


Point Triangle::a() const
{
  return data[0];
}


Point Triangle::b() const
{
  return data[1];
}


Point Triangle::c() const
{
  return data[2];
}
