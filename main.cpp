#include <iostream>
#include <cstddef>

#include "point.h"
#include "triangle.h"
#include "vector.h"


Planar ** most_left(Planar ** pls, size_t k);
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

  Planar ** ml = most_left(pls, size);

  if (ml == pls + size) {
    std::cout << "Not found";
    free_planars(pls, size);
    delete[] pls;
    return 0;
  }

  draw(*ml);

  free_planars(pls, size);
  delete[] pls;
}


Planar ** most_left(Planar ** pls, size_t k)
{
  if (!k) {
    return pls;
  }
  Planar ** result = pls;
  while (--k) {
    int next_x = (*(++pls))->x();
    int current_x = (*(result))->x();
    if (next_x < current_x) {
      result = pls;
    }
  }
  return result;
}


Planar * make(std::istream & input)
{
  char cmd[3] = {0};
  input >> cmd[0] >> cmd[1];
  int data[6]{0};
  if (cmd[0] == 'P' && cmd[1] == 'T') {
    if (input >> data[0] >> data[1]) {
      return new Point(data[0], data[1]);
    }
  } else if (cmd[0] == 'V' && cmd[1] == 'T') {
    if (input >> data[0] >> data[1] >> data[2] >> data[3]) {
      return new Vector(Point(data[0], data[1]), Point(data[2], data[3]));
    }
  } else if (cmd[0] == 'T' && cmd[1] == 'T') {
    if (input >> data[0] >> data[1] >> data[2] >> data[3] >> data[4] >> data[5]) {
      return new Triangle(Point(data[0], data[1]), Point(data[2], data[3]),
      Point(data[4], data[5]));
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
    case 2:
      result = new Triangle(Point(0, 0), Point(1, 1), Point(0, 1));
      break;
    default: throw std::logic_error("bad id");
  }
  return result;
}


void draw(Planar * pl)
{
  std::cout << pl->x() << " " << pl->y() << " " << pl->area() << "\n";
  frame_t fr = pl->frame();
  std::cout << fr.AA.x << " " << fr.AA.y << "    " << fr.BB.x << " " << fr.BB.y << "\n";
}


void free_planars(Planar ** pls, size_t k)
{
  for (size_t i = 0; i < k; ++i) {
    delete pls[i];
  }
}
