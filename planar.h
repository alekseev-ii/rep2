#ifndef PLANAR_H
#define PLANAR_H

struct frame_t {
  int x1, y1;
  int x2, y2;
};


struct Planar {
  virtual ~Planar() = default;

  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
  virtual double get_area() const = 0;
  virtual frame_t get_frame() const = 0;
};


#endif
