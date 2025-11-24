#include "planars.h"


Planar * most_left(Planar ** pls, size_t k)
{
  return nullptr;
}


Planar * make(size_t pl)
{
  switch (pl) {
    default: throw std::logic_error("bad pl");
  }
  return nullptr;
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


