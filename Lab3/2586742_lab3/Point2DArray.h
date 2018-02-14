/*------------------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Description:This is a Point2DArray class, which contain instances like array size and number of points, and constructor. this class will be functioned in the Point2DArray.cpp class. 
Date: 02/20/2013
-------------------------------------------------------------*/



#ifndef POINT_2D_ARRAY_H
#define POINT_2D_ARRAY_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>

typedef double Point2D[2];

class Point2DArray {
public:

  // constructor to read points coming from the stream
  Point2DArray(std::istream& is);

  // destructor free the memory
  virtual ~Point2DArray();

  // computes the centre point of the points
  void centroid(Point2D centre);

  // return length of the points
  double length();

  // print the point array
  void print(std::ostream& os_stream);

private:
  // pointer of the pointers array
  Point2D *pts;
  // size of the array
  int arraySize;
  // number of points
  int numPoints;
};

#endif
