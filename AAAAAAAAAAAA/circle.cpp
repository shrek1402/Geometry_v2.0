#include "circle.h"

circle::circle(std::string) { 
	//parse(_initialData);
}

bool circle::getError() { return false; }

double circle::getSquare() { return 0.0; }

double circle::getPerimetr() { return 0.0; }

void circle::setPoint(std::string) {}

circle::~circle() { std::cout << " delCircle "; }