#include "circle.h"
#include "Exception.h"
circle::circle(std::string c) : _coordinats(c) { parse(_coordinats, this); }

void parse(std::string coord, circle* circle) {
  std::set<char> set{'0', '1', '2', '3', '4', '5',
                     '6', '7', '8', '9', '-', '.'};
  std::string tmpStr;

  for (size_t i = 0; i < coord.size(); i++) {
    if (coord.at(i) == ' ' && set.find(coord.at(i - 1)) != set.end()) {
      circle->_dataCircle.x = stoi(tmpStr);
      tmpStr = "";
    } else if (coord.at(i) == ' ' && coord.at(i - 1) == ',') {
      continue;
    } else if (coord.at(i) == ',') {
      circle->_dataCircle.y = stoi(tmpStr);
      tmpStr = "";
    } else if (set.find(coord.at(i)) != set.end()) {
      tmpStr += coord.at(i);
    } else if (i == coord.size() - 1) {
      circle->_dataCircle.r = stod(tmpStr);
    } else {
      if (coord.at(i) != ')' && coord.at(i) != '(') {
        throw Exception("Invalid character encountered. ", 1991);
      }
    }
  }
}

double circle::getSquare() { return _dataCircle.r * _dataCircle.r * M_PI; }

double circle::getPerimetr() { return 2 * M_PI * _dataCircle.r; }

void* circle::getData() { return &_dataCircle; }

uint16_t circle::getName() { return 1; }

circle::~circle() { std::cout << " delCircle "; }