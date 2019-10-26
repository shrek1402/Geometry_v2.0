#ifndef PCH_H
#define PCH_H

#define _USE_MATH_DEFINES



#include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
#include <cctype>
#include <algorithm>
#include <set>

template<typename T1, typename T2>
struct tPoint {
  T1 x;
  T2 y;
};

using point = tPoint<int, int>;
using edge = std::pair<point, point>;

#include "figure.h"
#include "circle.h"
#include "poligone.h"
#include "treangle.h"

#endif
