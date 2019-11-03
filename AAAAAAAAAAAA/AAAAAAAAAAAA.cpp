#include "IException.h"
#include "Exception.h"
#include "ExcImpl.h"
#include "pch.h"
using namespace std;

bool intersection(point p_i_1, point p_i_2, point p_j_1, point p_j_2) {
  int x1 = p_i_1.x;
  int y1 = p_i_1.y;
  int x2 = p_i_2.x;
  int y2 = p_i_2.y;
  int x3 = p_j_1.x;
  int y3 = p_j_1.y;
  int x4 = p_j_2.x;
  int y4 = p_j_2.y;
  int denominator = (y4 - y3) * (x1 - x2) - (x4 - x3) * (y1 - y2);

  if (denominator == 0) {
    if (((x1 >= x3 && x1 <= x4 || x1 <= x3 && x1 >= x4) &&
         (y1 >= y3 && y1 <= y4 || y1 <= y3 && y1 >= y4)) ||
        ((x2 >= x3 && x2 <= x4 || x2 <= x3 && x2 >= x4) &&
         (y2 >= y3 && y2 <= y4 || y2 <= y3 && y2 >= y4))) {
      if ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1) ==
              0 &&
          (x1 * y2 - x2 * y1) * (y4 - y3) - (x3 * y4 - x4 * y3) * (y2 - y1) ==
              0) {
        return true;
      }
    }

  } else {
    int numerator_a = (x4 - x2) * (y4 - y3) - (x4 - x3) * (y4 - y2);
    int numerator_b = (x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2);
    double Ua = 1.0 * numerator_a / denominator;
    double Ub = 1.0 * numerator_b / denominator;
    if (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1) {
      return true;
    }
  }
  return false;
}

void nameIntersect(std::shared_ptr<figure> p_j, uint64_t j) {
  if (p_j->getName() == 1) {
    std::cout << "\t  " << j << ". "
              << "Circle" << std::endl;
  } else if (p_j->getName() == 2) {
    std::cout << "\t  " << j << ". "
              << "Triangle" << std::endl;
  } else if (p_j->getName() == 3) {
    std::cout << "\t  " << j << ". "
              << "Poligone" << std::endl;
  }
}

void CC(shared_ptr<figure> p_i, shared_ptr<figure> p_j, uint64_t j) {
  Circle* p_i_circle = (Circle*)p_j->getData();
  Circle* p_j_circle = (Circle*)p_j->getData();

  double H = sqrt(pow((p_i_circle->x - p_j_circle->x), 2) +
                  pow((p_i_circle->y - p_j_circle->y), 2));
  if (H - (p_i_circle->r + p_j_circle->r) <= 0) {
    nameIntersect(p_j, j);
  }
}

void PT(shared_ptr<figure> p_i, shared_ptr<figure> p_j, uint64_t j) {
  std::vector<point>* p_i_vec = (std::vector<point>*)p_i->getData();
  std::vector<point>* p_j_vec = (std::vector<point>*)p_j->getData();

  for (size_t ii = 0; ii < p_i_vec->size() - 1; ii++) {
    for (size_t jj = 0; jj < p_j_vec->size() - 1; jj++) {
      if (intersection(p_i_vec->at(ii), p_i_vec->at(ii + 1), p_j_vec->at(jj),
                       p_j_vec->at(jj + 1))) {
        nameIntersect(p_j, j);
        ii = jj = max(p_i_vec->size(), p_j_vec->size());
        break;
      }
    }
  }
}

void CP(shared_ptr<figure> p_i, shared_ptr<figure> p_j, uint64_t j) {
  Circle* tmpCircle;
  std::vector<point>* tmpPoint;

  if (p_i->getName() == 1) {
    tmpCircle = (Circle*)p_i->getData();
    tmpPoint = (std::vector<point>*)p_j->getData();
  } else {
    tmpCircle = (Circle*)p_j->getData();
    tmpPoint = (std::vector<point>*)p_i->getData();
  }
  for (size_t m = 0; m < tmpPoint->size() - 1; m++) {
    double H = abs(((tmpPoint->at(m + 1).x - tmpPoint->at(m).x) *
                        (tmpCircle->y - tmpPoint->at(m).y) -
                    (tmpPoint->at(m + 1).y - tmpPoint->at(m).y) *
                        (tmpCircle->x - tmpPoint->at(m).x)) /
                   sqrt((tmpPoint->at(m + 1).x - tmpPoint->at(m).x) *
                            (tmpPoint->at(m + 1).x - tmpPoint->at(m).x) +
                        (tmpPoint->at(m + 1).y - tmpPoint->at(m).y) *
                            (tmpPoint->at(m + 1).y - tmpPoint->at(m).y)));
    if (0 <= tmpCircle->r - H) {
      nameIntersect(p_j, j);
      break;
    }
  }
}

int main() {
  string sForParce;
  string sCoordinats;
  string nameFigure;
  ifstream myFile("data.txt");
  std::vector<shared_ptr<figure>> figures;

  if (!myFile.is_open()) {
    std::cout << "FILE";
  }

  uint64_t numFigure = 1;
  try {
    while (!myFile.eof()) {
      getline(myFile, sForParce);
      size_t i = 0;

      while (i < sForParce.size() && sForParce.at(i) != '(') {
        i++;
      }

      nameFigure = sForParce.substr(0, i);
      sCoordinats = sForParce.substr(i, sForParce.size());
      std::transform(nameFigure.begin(), nameFigure.end(), nameFigure.begin(),
                     tolower);

      std::cout << numFigure++ << ". " << sForParce << endl;

      auto p = figure::createFigure(nameFigure, sCoordinats);
      figures.push_back(p);
    }
    std::cout << std::endl << std::endl;

    for (size_t i = 0; i < figures.size(); i++) {
      std::cout << std::endl << i << ". ";
      auto p_i = figures.at(i);

      if (p_i->getName() == 1) {
        std::cout << "Circle" << std::endl;
      } else if (p_i->getName() == 2) {
        std::cout << "Triangle" << std::endl;
      } else if (p_i->getName() == 3) {
        std::cout << "Poligone" << std::endl;
      }

      std::cout << "      Perimetr: " << p_i->getPerimetr() << std::endl;
      std::cout << "      Square: " << p_i->getSquare() << std::endl;
      std::cout << "      Intersection: " << std::endl;

      for (size_t j = 0; j < figures.size(); j++) {
        if (i == j) {
          continue;
        }
        auto p_j = figures.at(j);
        if (p_i->getName() + p_j->getName() == 2) {
          CC(p_i, p_j, j);
        } else if ((p_i->getName() == 2 || p_i->getName() == 3) &&
                   (p_j->getName() == 2 || p_j->getName() == 3)) {
          PT(p_i, p_j, j);
        } else if (((p_i->getName() == 1) &&
                    (p_j->getName() == 2 || p_j->getName() == 3)) ||
                   ((p_i->getName() == 2 || p_i->getName() == 3) &&
                    p_j->getName() == 1)) {
          CP(p_i, p_j, j);
        }
      }
    }
  } catch (Exception& it) {
    cout << it.Ptr()->What() << endl;
    cout << it.Ptr()->Code() << endl;
  }
}