#include "pch.h"
std::shared_ptr<figure> figure::createFigure(std::string id, std::string coordinats) {
  if (id == "triangle") {
    return std::make_shared<treangle>(coordinats);
  } else if (id == "circle") {
    return std::make_shared<circle>(coordinats);
  } else if (id == "poligone") {
    return std::make_shared<poligone>(coordinats);
  } else {
    return  nullptr;
  }
};

figure::~figure() = default;