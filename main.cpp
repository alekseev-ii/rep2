#include <iostream>
#include <cstddef>

#include "planars.h"


int main()
{
  Planar * pls[10] = {};
  size_t k = 0;
  // pls[k++] = make(std::cin);
  Planar * left = most_left(pls, k);
  // draw(left);
  // free_planars(pls, k)
}
