#pragma once
#include "pch.h"
class circle : public figure {
 private:
  std::string _initialData;

 public:
  circle(std::string);
  double getSquare();
  double getPerimetr();
  void setPoint(std::string);
  bool getError();

  ~circle();
};
