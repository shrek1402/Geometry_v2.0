#pragma once
#include "pch.h"
class treangle : public figure {
 public:
  treangle(std::string);
  double getSquare();
  double getPerimetr();
  void setPoint(std::string);
  bool getError();

  ~treangle();
};
