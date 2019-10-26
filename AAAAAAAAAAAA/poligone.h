#pragma once
#include "pch.h"
class poligone : public figure {
 public:
  poligone(std::string);
  double getSquare();
  double getPerimetr();
  void setPoint(std::string);
  bool getError();

  ~poligone();
};
