#ifndef POINT_H
#define POINT_H

#include "planar.h"


struct Point: Planar {
  Point(int xx, int yy);
  virtual ~Point() = default;

  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  virtual double get_area() const;
  virtual frame_t get_frame() const;

  private:
    int data[2];
};


#endif
