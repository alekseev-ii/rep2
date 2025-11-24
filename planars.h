#ifndef PLANARS_H
#define PLANARS_H
#include <iostream>

struct Planar {
  virtual ~Planar() = default;

  virtual int x() const = 0;
  virtual int y() const = 0;
  virtual int abs_sqr() const = 0;
};


struct Point: Planar {
  Point(int xx, int yy);
  virtual ~Point() = default;

  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;

  private:
    int data[2];
};


Planar * most_left(Planar ** pls, size_t k);
Planar * make(std::istream & input);
Planar * make(size_t id);
void draw(Planar * pl);
void free_planars(Planar ** pls, size_t k);


#endif
