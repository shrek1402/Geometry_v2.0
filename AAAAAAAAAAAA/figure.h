#pragma once
#include "pch.h"

class figure {
 protected:
  figure() = default;
  virtual ~figure() = 0;

 public:
  figure(const figure&) = delete;
  figure& operator=(const figure&) = delete;

  virtual uint16_t getName() = 0;
  virtual double getSquare() = 0;
  virtual double getPerimetr() = 0;
  
  virtual void* getData() = 0;

  static std::shared_ptr<figure> createFigure(std::string id, std::string coordinats);
};