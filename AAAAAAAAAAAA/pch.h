#ifndef PCH_H
#define PCH_H

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

template <typename T1, typename T2>
struct tPoint {
  T1 x;
  T2 y;
};

struct Circle {
  int x;
  int y;
  double r;
};

using point = tPoint<int, int>;
using edge = std::pair<point, point>;

#include "IException.h"
#include "ExcImpl.h"

#include "figure.h"
#include "circle.h"
#include "poligone.h"
#include "triangle.h"

#endif  