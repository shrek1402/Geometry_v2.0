#include "poligone.h"

poligone::poligone(std::string) {}

bool poligone::getError() { return false; }

double poligone::getSquare() { return 0.0; }

double poligone::getPerimetr() { return 0.0; }

void poligone::setPoint(std::string) {}

poligone::~poligone() { std::cout << " delPoligone "; }