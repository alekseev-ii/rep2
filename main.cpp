#include <iostream>
#include <cstddef>

#include "point.h"
#include "triangle.h"
#include "vector.h"


Planar ** most_left(Planar ** pls, size_t k);
Planar ** max_area(Planar ** pls, size_t k);
size_t intersection_of_frames_area(frame_t f1, frame_t f2);
Planar *** max_frame_intersections(Planar ** pls, size_t k);
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

  if (size == 0) {
    free_planars(pls, size);
    delete[] pls;
    return 4;
  }

  Planar * max_area_planar = *max_area(pls, size);
  draw(max_area_planar);
  Planar *** max_intersection = max_frame_intersections(pls, size);
  draw(*max_intersection[0]);
  draw(*max_intersection[1]);


  free_planars(pls, size);
  delete[] pls;
  delete[] max_intersection;
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


Planar ** max_area(Planar ** pls, size_t k)
{
  if (!k) {
    return pls;
  }
  Planar ** result = pls;
  while (--k) {
    int next_area = (*(++pls))->area();
    int current_area = (*(result))->area();
    if (next_area > current_area) {
      result = pls;
    }
  }
  return result;
}


size_t intersection_of_frames_area(frame_t f1, frame_t f2)
{
  int left = f1.AA.x > f2.AA.x ? f1.AA.x : f2.AA.x;
  int right = f1.BB.x < f2.BB.x ? f1.BB.x : f2.BB.x;
  int bottom = f1.AA.y > f2.AA.y ? f1.AA.y : f2.AA.y;
  int top = f1.BB.y < f2.BB.y ? f1.BB.y : f2.BB.y;

  if (left >= right || bottom >= top) {
    return 0;
  }

  return (right - left) * (top - bottom);
}


Planar ***  max_frame_intersections(Planar ** pls, size_t k)
{
  Planar *** result = new Planar **[2];
  if (k < 2) {
    result[0] = result[1] = pls;
    return result;
  }
  result[0] = pls;
  result[1] = pls + 1;
  size_t max_intersections = intersection_of_frames_area(pls[0]->frame(), pls[1]->frame());
  for (size_t i = 0; i < k - 1; ++i) {
    for (size_t j = i + 1; j < k; ++j) {
      size_t intersection = intersection_of_frames_area(pls[i]->frame(), pls[j]->frame());
      if (intersection > max_intersections) {
        max_intersections = intersection;
        result[0] = pls + i;
        result[1] = pls + j;
      }
    }
  }
  if (max_intersections == 0) {
    result[0] = result[1] = pls + k;
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
