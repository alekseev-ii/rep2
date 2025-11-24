#ifndef PLANARS_H
#define PLANARS_H
#include <iostream>

struct Planar {
  virtual ~Planar() = default;

  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
};


Planar * make(std::istream & input);
Planar * most_left(Planar ** pls, size_t k);


#endif
