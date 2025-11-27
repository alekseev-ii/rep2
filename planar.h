#ifndef PLANAR_H
#define PLANAR_H

struct p_t {
  int x, y;
};
struct frame_t {
  p_t AA, BB;
};


struct Planar {
  virtual ~Planar() = default;

  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
  virtual double area() const = 0;
  virtual frame_t frame() const = 0;
};


#endif
