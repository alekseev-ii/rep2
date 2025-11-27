#ifndef QUADRANGLE_H
#define QUADRANGLE_H
#include "Planar.h"
#include "point.h"


struct Quadrangle: Planar {
  Quadrangle(Point aa, Point bb, Point cc, Point dd);
  ~Quadrangle() = default;

  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  virtual double get_area() const;
  virtual frame_t get_frame() const;
  Point first() const;
  Point a() const;
  Point b() const;
  Point c() const;
  Point d() const;

  private:
    Point data[4];
    double area_abc() const;
    double area_dbc() const;
};


#endif
