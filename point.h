#ifndef POINT_H
#define POINT_H

#include "planar.h"


struct Point: Planar {
  Point(int xx, int yy);
  virtual ~Point() = default;

  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  virtual double area() const;
  virtual frame_t frame() const;

  private:
    int data[2];
};


#endif
