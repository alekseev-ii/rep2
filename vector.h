#ifndef VECTOR_H
#define VECTOR_H

#include "planar.h"
#include "point.h"


struct Vector: Planar {
  Vector(Point aa, Point bb);
  virtual ~Vector();

  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;

  private:
    Point a, b;
};


#endif