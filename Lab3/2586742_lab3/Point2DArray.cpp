/*---------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Description: this is a Point2DArray.cpp class, which could read the initial array size and read the points. Moreover, there is a method to compute the centre point and return length. Finally, print the point array.
Date: 02/20/2013
--------------------------------------------------*/
#include "Point2DArray.h"

// constructor to read points coming from the stream
Point2DArray::Point2DArray(std::istream& is) {
  is >> arraySize;// read the initial array size
  pts = new Point2D[arraySize];// create the array with the initial size

  
  numPoints = 0;// initialize num of points

  // read points until reaches end of the stream
  while (is >> pts[numPoints][0] >> pts[numPoints][1]) {
    numPoints++;// increase the num
    
    if (numPoints >= arraySize) {// if numPoint exceed the array size
      Point2D *temp = new Point2D[numPoints];// create a temp array
      memcpy(temp, pts, numPoints * sizeof(Point2D));// copy the points to the temp array
      

       // delete the points array
      delete[] pts;


      // double the arraySize and create a new points array;
      pts = new Point2D[arraySize <<= 1];
      memcpy(pts, temp, numPoints * sizeof(Point2D));// copy the temp points to the new array
      
      delete [] temp;// delete the temp array
    }
  }

}


// destructor free the memory
Point2DArray::~Point2DArray() {
  delete [] pts;
}

// computes the centre point of the points
void Point2DArray::centroid(Point2D centre) {
  for (int i = 0; i < numPoints; i++) {
    centre[0] = centre[0] +pts[i][0];
    centre[1] = centre[0] + pts[i][1];
  }
  centre[0] = centre[0]/ numPoints;
  centre[1] = centre[1]/ numPoints;
}

// return length of the points
double Point2DArray::length() {
  double length = 0.0;
  for (int i = 1; i < numPoints; ++i) {
    length = length +  sqrt((pts[i - 1][0] - pts[i][0]) * (pts[i - 1][0] - pts[i][0])
        + (pts[i - 1][1] - pts[i][1]) * (pts[i - 1][1] - pts[i][1]));
  }
  return length;
}
// print the point array

void Point2DArray::print(std::ostream& os_stream) {
  os_stream << numPoints << " Given point(s):" << std::endl;// print num of points
  
  os_stream.precision(2);// set precision
  std::cout.setf(std::ios::fixed);


  // print all the points with 2 points each line
  for (int i = 0; i < numPoints; i++) {
    os_stream << "(" << std::setw(2) << pts[i][0] << "," << std::setw(2) << pts[i][1] << ")";
    if ((i + 1) % 2 == 0 || i == numPoints - 1) {
      os_stream << std::endl;
    } 
    else {
      os_stream << " and ";
    }
  }
}
