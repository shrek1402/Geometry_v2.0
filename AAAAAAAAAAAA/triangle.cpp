#include "triangle.h"
#include "Exception.h"
triangle::triangle(std::string c) : _coordinats(c) {
  parse(_coordinats, this);

  if (_points.size() != 3) {
    // exception
  }
}

void parse(std::string coord, triangle* triangle) {
  std::set<char> set{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '.'};
  std::string tmpStr;
  point tmpPoint;

  for (size_t i = 0; i < coord.size(); i++) {
    if (coord.at(i) == ' ' && set.find(coord.at(i - 1)) != set.end()) {
      tmpPoint.x = stoi(tmpStr);
      tmpStr = "";
    } else if (coord.at(i) == ' ' && coord.at(i - 1) == ',') {
      continue;
    } else if (coord.at(i) == ',' || i == coord.size() - 1) {
      tmpPoint.y = stoi(tmpStr);
      tmpStr = "";
      triangle->_points.push_back(tmpPoint);
    } else if (set.find(coord.at(i)) != set.end()) {
      tmpStr += coord.at(i);
    } else {
      if (coord.at(i) != ')' && coord.at(i) != '(') {
        throw Exception("Invalid character encountered. ", 1991);
      }
    }
  }
  triangle->_points.push_back(triangle->_points.at(0));
}
// poligone(1 2, 3 4, 5 6, 7 8, 9 0)

double triangle::getSquare() {
  return abs(((_points.at(1).x - _points.at(0).x) *
                  (_points.at(2).y - _points.at(0).y) -
              (_points.at(2).x - _points.at(0).x) *
                  (_points.at(1).y - _points.at(0).y)) /
             2.0);
}

double triangle::getPerimetr() {
  return sqrt((_points.at(1).x - _points.at(0).x) *
                  (_points.at(1).x -
                   _points.at(0).x)  // sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
              + (_points.at(1).y - _points.at(0).y) *
                    (_points.at(1).y - _points.at(0).y))  // +
         + sqrt((_points.at(2).x - _points.at(0).x) *
                    (_points.at(2).x -
                     _points.at(0).x)  // sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))
                + (_points.at(2).y - _points.at(0).y) *
                      (_points.at(2).y - _points.at(0).y))  // +
         + sqrt((_points.at(2).x - _points.at(1).x) *
                    (_points.at(2).x -
                     _points.at(1).x)  // sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))
                + (_points.at(2).y - _points.at(1).y) *
                      (_points.at(2).y - _points.at(1).y));
}

void* triangle::getData() { return &_points; }

uint16_t triangle::getName() { return 2; }

triangle::~triangle() { std::cout << " delTriangle "; }