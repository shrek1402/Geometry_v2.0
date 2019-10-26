#include "pch.h"

using namespace std;

int main() {
  string sForParce;
  string sCoordinats;
  string nameFigure;
  ifstream myFile("data.txt");

  if (!myFile) {
    std::cout << "FILE";
  }

  while (!myFile.eof()) {
    getline(myFile, sForParce);


	//функция которая будет разделять
    size_t i = 0;
    while (i < sForParce.size() && sForParce.at(i) != '(') {
      i++;
    }

    nameFigure = sForParce.substr(0, i);
    sCoordinats = sForParce.substr(i, sForParce.size());

    std::transform(nameFigure.begin(), nameFigure.end(), nameFigure.begin(),
                   tolower);
    std::cout << nameFigure;

    auto p = figure::createFigure(nameFigure, sCoordinats);
    std::cout << p->getPerimetr() << " ";
    std::cout << p->getSquare() << " ";
	
  }
}
