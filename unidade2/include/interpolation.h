#ifndef _INTERPOLATION_H_
#define _INTERPOLATION_H_

#include "util.h"

/**
 * Newton's Interpolation Polynomial
 */
Polynomial newton_ip(vector<Point> points)
{
  Polynomial p = {points[0].y};
  for (auto it = points.begin(); it != points.end(); ++it)
  {
    p += div_diff(points.begin(), it) *
      prod(points.begin(), it);
  }
}
Polynomial prod(iterator start, iterator end)
{
}
/**
 * The Divided Difference
 */
double div_diff(iterator start, iterator end)
{
  if (start == end){
    return start->y;
  }
  else {
    return 
      div_diff(start-1, end) - div_diff(start, end-1)
      /
      (end->x - start->x)
  }
}

#endif// _INTERPOLATION_H_
