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

 private:
  std::string _coordinats;
  uint64_t _figureName = 2; // 1-circle, 2-triangle, 3-poligone
  std::vector<point> _point;


  friend void parse(std::string, treangle*);
  
};
