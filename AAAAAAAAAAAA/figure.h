#pragma once
#include "pch.h"

class figure {
 protected:
  figure() = default;
  virtual ~figure() = 0;

 public:
  figure(const figure&) = delete;
  figure& operator=(const figure&) = delete;


  virtual double getSquare() = 0;
  virtual double getPerimetr() = 0;
  virtual void setPoint(std::string) = 0;
  virtual bool getError() = 0;
  

  // Фабрика
  static std::shared_ptr<figure> createFigure(std::string id, std::string coordinats);
};
