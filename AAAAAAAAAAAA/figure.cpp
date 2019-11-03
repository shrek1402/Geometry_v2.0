#include "pch.h"
#include "Exception.h"
std::shared_ptr<figure> figure::createFigure(std::string id, std::string coordinats) {
  if (id == "triangle") {
    return std::make_shared<triangle>(coordinats);
  } else if (id == "circle") {
    return std::make_shared<circle>(coordinats);
  } else if (id == "poligone") {
    return std::make_shared<poligone>(coordinats);
  } else {
    throw Exception("Unknown shape type. ", 1991);
  }
};

figure::~figure() = default;