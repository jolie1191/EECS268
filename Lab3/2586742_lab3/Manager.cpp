/*---------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Description: This is Manager.cpp class. which has its constructor and could print all the points and the centre point, finally print length.
Date: 02/20/2013
-----------------------------------------------*/

#include "Manager.h"

// constructor
Manager::Manager(std::istream& is) {
  ptArray = new Point2DArray(is);
}

// destructor
Manager::~Manager() {
  delete ptArray;
}

// start the process
void Manager::start() {
  // 1. print all the points
  ptArray->print(std::cout);
  // 2. print the centre point
  Point2D c;
  ptArray->centroid(c);
  std::cout.precision(2);
  std::cout.setf(std::ios::fixed);
  std::cout << "centroid: (" << c[0] << ", " << c[1] << ")" << std::endl;
  // 3. print the length
  std::cout << "length: " << ptArray->length() << std::endl;
}
