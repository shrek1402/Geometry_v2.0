#include "poligone.h"
#include "Exception.h"
poligone::poligone(std::string c) : _coordinats(c) { 
	parse(_coordinats, this); 
	if (_points.size() < 3) {
          throw Exception("Wrong coordinates. ", 1991);
    }
}

double poligone::getSquare() {
  double result = 0;
  for (size_t i = 0; i < _points.size(); i++) {
    if (i < _points.size() - 1) {
      result +=
          _points.at(i).x * _points.at(i + 1).y -
          _points.at(i + 1).x * _points.at(i).y;  // x1y2 - x2y1  01 10 12 21 23 32
    } else {
      result += _points.at(i).x * _points.at(0).y - _points.at(0).x * _points.at(i).y;
    }
  }
  return abs(result / 2.0);
}

double poligone::getPerimetr() {
  double result = 0;
  for (size_t i = 0; i < _points.size(); i++) {
    if (i < _points.size() - 1) {
      result += sqrt((_points.at(i + 1).x - _points.at(i).x) *
                         (_points.at(i + 1).x - _points.at(i).x) +
                     (_points.at(i + 1).y - _points.at(i).y) *
                         (_points.at(i + 1).y - _points.at(i).y));
    } else if (i = _points.size() - 1) {
      result += sqrt((_points.at(0).x - _points.at(i).x) *
                         (_points.at(0).x - _points.at(i).x) +
                     (_points.at(0).y - _points.at(i).y) *
                         (_points.at(0).y - _points.at(i).y));
    }
  }
  return result;
}

void parse(std::string coord, poligone* poligone) {
  std::set<char> set{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-'};
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
      poligone->_points.push_back(tmpPoint);
    } else if (set.find(coord.at(i)) != set.end()) {
      tmpStr += coord.at(i);
    } else {
      if (coord.at(i) != ')' && coord.at(i) != '(') {
        throw Exception("Invalid character encountered. ", 1991);
      }
    }
  }
  poligone->_points.push_back(poligone->_points.at(0));
}

void* poligone::getData() { return &_points; }

uint16_t poligone::getName() { return 3; }

poligone::~poligone() { std::cout << " delPoligone "; }