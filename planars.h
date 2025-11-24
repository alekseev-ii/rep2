#ifndef PLANARS_H
#define PLANARS_H
#include <iostream>

struct Planar {
  virtual ~Planar() = default;

  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
};


struct Point : Planar {
  int x, y;

};


Planar * most_left(Planar ** pls, size_t k);
Planar * make(std::istream & input);
Planar * make(size_t pl);
void draw(Planar * p);
void free_planars(Planar ** pls, size_t k);


#endif
