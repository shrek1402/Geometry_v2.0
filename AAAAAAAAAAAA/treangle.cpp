#include "treangle.h"

treangle::treangle(std::string c) : _coordinats(c) {
  parse(_coordinats, this);

  if (_point.size() != 3) {
    // exception
  }
}

void parse(std::string coord, treangle* treangle) {
  std::set<char> set{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-'};
  std::string tmpStr;
  point tmpPoint;

  for (size_t i = 0; i < coord.size(); i++) {
    if (coord.at(i) == ' ' && set.find(coord.at(i-1)) != set.end()) {
      tmpPoint.x = stoi(tmpStr);
      tmpStr = "";
    } else if (coord.at(i) == ',' || i == coord.size()-1) {
      tmpPoint.y = stoi(tmpStr);
      tmpStr = "";
      treangle->_point.push_back(tmpPoint);
    } else if (set.find(coord.at(i)) != set.end()) {
      tmpStr += coord.at(i);
    } else {
      continue;//user dolboeb:(    exception
	}
  }
}
// poligone(1 2, 3 4, 5 6, 7 8, 9 0)

bool treangle::getError() { return false; }

double treangle::getSquare() {
  return abs(
      ((_point.at(1).x - _point.at(0).x) * (_point.at(2).y - _point.at(0).y) -
       (_point.at(2).x - _point.at(0).x) * (_point.at(1).y - _point.at(0).y)) /
      2.0);
}

double treangle::getPerimetr() {
  return sqrt((_point.at(1).x - _point.at(0).x) *
                  (_point.at(1).x -
                   _point.at(0).x)  // sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
              + (_point.at(1).y - _point.at(0).y) *
                    (_point.at(1).y - _point.at(0).y))  // +
         + sqrt((_point.at(2).x - _point.at(0).x) *
                    (_point.at(2).x -
                     _point.at(0).x)  // sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))
                + (_point.at(2).y - _point.at(0).y) *
                      (_point.at(2).y - _point.at(0).y))  // +
         + sqrt((_point.at(2).x - _point.at(1).x) *
                    (_point.at(2).x -
                     _point.at(1).x)  // sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))
                + (_point.at(2).y - _point.at(1).y) *
                      (_point.at(2).y - _point.at(1).y));
}

void treangle::setPoint(std::string) {}

treangle::~treangle() { std::cout << " delTriangle "; }
