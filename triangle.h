#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "planar.h"
#include "point.h"


struct Triangle: Planar {
  Triangle(Point aa, Point bb, Point cc);
  virtual ~Triangle() = default;

  virtual int x() const;
  virtual int y() const;
  virtual double area() const;
  virtual frame_t frame() const;
  Point first() const;
  Point a() const;
  Point b() const;
  Point c() const;

  private:
    Point data[3];
};
#endif
