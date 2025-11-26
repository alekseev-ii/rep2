#include <iostream>
#include <cstddef>

#include "point.h"
#include "vector.h"


Planar * most_left(Planar ** pls, size_t k);
Planar * make(std::istream & input);
Planar * make(size_t id);
void draw(Planar * pl);
void free_planars(Planar ** pls, size_t k);


int main()
{
  size_t size = 0;
  size_t capacity = 20;
  Planar ** pls = new Planar *[capacity];

  while (std::cin) {
    Planar * pl = nullptr;
    try {
      pl = make(std::cin); // bad_alloc || logic_error
      if (size == capacity) {
        Planar ** ext_pls = new Planar *[capacity * 2]; // bad_alloc
        for (size_t i = 0; i < size; ++i) {
          ext_pls[i] = pls[i];
        }
        delete[] pls;
        pls = ext_pls;
        capacity *= 2;
      }
      pls[size++] = pl;
    } catch (...) {
      delete pl;
      free_planars(pls, size);
      delete[] pls;
      return 2;
    }
  }
  if (!std::cin.eof()) {
    free_planars(pls, size);
    delete[] pls;
    return 3;
  }

  draw(most_left(pls, size));

  free_planars(pls, size);
  delete[] pls;
}


Planar * most_left(Planar ** pls, size_t k)
{
  Planar * left = pls[0];
  for (size_t i = 1; i < k; ++i) {
    if (pls[i]->x() < left->x()) {
      left = pls[i];
    }
  }
  return left;
}


Planar * make(std::istream & input)
{
  char cmd[2] = {};
  input >> cmd[0] >> cmd[1];
  int data[4]{0};
  if (cmd[0] == 'P' && cmd[1] == 'T') {
    if (input >> data[0] >> data[1]) {
      return new Point(data[0], data[1]);
    }
  } else if (cmd[0] == 'V' && cmd[1] == 'T') {
    if (input >> data[0] >> data[1] >> data[2] >> data[3]) {
      return new Vector(Point(data[0], data[1]), Point(data[2], data[3]));
    }
  }
  throw std::logic_error("bad cmd");
}


Planar * make(size_t id)
{
  Planar * result = nullptr;
  switch (id) {
    case 0:
      result = new Point(0, 0);
      break;
    case 1:
      result = new Vector(Point(0, 0), Point(1, 1));
      break;
    default: throw std::logic_error("bad id");
  }
  return result;
}


void draw(Planar * pl)
{
  std::cout << pl->x() << " " << pl->y() << "\n";
}


void free_planars(Planar ** pls, size_t k)
{
  for (size_t i = 0; i < k; ++i) {
    delete pls[i];
  }
}
