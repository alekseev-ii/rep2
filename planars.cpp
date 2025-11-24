#include "planars.h"


Point::Point(int xx, int yy): Planar(), data{xx, yy}
{
}


int Point::x() const
{
  return data[0];
}


int Point::y() const
{
  return data[1];
}


int Point::abs_sqr() const
{
  return x() * x() + y() * y();
}


Planar * most_left(Planar ** pls, size_t k)
{
  return nullptr;
}


Planar * make(size_t id)
{
  Planar * result = nullptr;
  switch (id) {
    case 0:
      result = new Point(0, 0);
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
