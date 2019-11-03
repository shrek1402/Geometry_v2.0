#pragma once
#include "pch.h"
class circle : public figure {
 private:
  friend void parse(std::string, circle*);

  std::string _coordinats;
  Circle _dataCircle;

 public:
  circle(std::string c);
  void* getData();
  double getSquare();
  double getPerimetr();
  uint16_t getName();


  ~circle();
};
