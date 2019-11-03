#pragma once
#include "pch.h"
class triangle : public figure {
 public:
  triangle(std::string);

  double getSquare();
  double getPerimetr();
  void* getData();
  uint16_t getName();

  ~triangle();

 private:
  std::string _coordinats;
  uint64_t _figureName = 2; // 1-circle, 2-triangle, 3-poligone
  std::vector<point> _points;

  friend void parse(std::string, triangle*);
};
