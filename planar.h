#ifndef PLANAR_H
#define PLANAR_H


struct Planar {
  virtual ~Planar() = default;

  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
};


#endif