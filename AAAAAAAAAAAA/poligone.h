#pragma once
#include "pch.h"
class poligone : public figure {
 public:
  poligone(std::string);

  double getSquare();
  double getPerimetr();
  void* getData();
  uint16_t getName();

  ~poligone();

 private:
  std::string _coordinats;
  uint64_t _figureName = 2;  // 1-circle, 2-triangle, 3-poligone
  std::vector<point> _points;

  friend void parse(std::string, poligone*);
};