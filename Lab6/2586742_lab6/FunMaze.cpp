/*-------------------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Assignment: Lab6
Description: this is a FunMaze class. it contains its functions(solveMaze, readMaze and printMaze) and  and we also need to use FunMaze.h in this class. Moreover, we need output the maze to the console which should look the same as the input file. 
Date: 03/12/2013
---------------------------------------------------------------*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

#include "FunMaze.h"

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//A method to recursively solve the maze
//input:  A coordinate of the maze to inspect (x,y)
//output:  Either a solution to the maze or nothing if no path is found (calls printMaze())
//
//note:  we need to mark visited positions to avoid cycles when searching for a solution (testing the same positions over and over again)
void FunMaze::solveMaze(int x, int y) {
//  cout << x << " " << y << endl;
  //First check to see if the current spot is open (' ')
  //If it is mark the position as visited (0)
  if (maze[x][y] == ' ' || x == 1 && y == 1) {
    maze[x][y] = '0';
  }
  else if (maze[x][y] == 'X') {
    //If the current spot is not open check to see if you have arrived at the goal position (X), (this is our basis case!)
    //If the goal has been found print the current solution for the maze
    printMaze();
    return;
  } else {
    return;
  }
  //Next we need to check if there are any open spots (' ') around our current position and explore them, there are up to 4 directions to explore
  for (int i = 0; i < 4; ++i) {
    int x1 = x + dx[i];
    int y1 = y + dy[i];
    if (maze[x1][y1] == ' ' || maze[x1][y1] == 'X') {
      solveMaze(x1, y1);
    }
  }
  //finally after we have examined all possible paths from this location we must "unmark" this position and make it open again (' ')
  maze[x][y] = ' ';
  //If we have have come this far it means that there is no solution to be found along this path (our other basis case!)

}

//Constructor
FunMaze::FunMaze() {
  maze = NULL;
  dim1 = 0;
  dim2 = 0;
}

//Destructor
FunMaze::~FunMaze() {
  //free all memory we allocated earlier
  if (maze != NULL) {
    for (int i = 0; i < dim1; i++)
      delete[] maze[i];
    delete[] maze;
  }
}

//Reads the input file and stores the maze in an mxn array 
void FunMaze::readMaze(char *fileName) {
  ifstream file;
  file.open(fileName, ios::in);
  string dummyLine;

  //check that we correctly opened the file
  if (!file) {
    cout << "Unable to open file" << endl;
    exit(1);
  }

  //get the dimensions of the maze
  file >> dim1;
  file >> dim2;

  //place the file get pointer at the beginning of the file
  file.seekg(ios::beg);

  //skip over the first line
  std::getline(file, dummyLine);

  //allocate memory for the maze
  //read in at the same time
  maze = new char *[dim1];
  for (int i = 0; i < dim1; i++) {
    maze[i] = new char [dim2];
    file.getline(maze[i], dim2 + 1);
  }
}

//Output the current state of the maze 
void FunMaze::printMaze() {
  //This should output the maze to the console
  //The output should look the same as the input file
  cout << endl;
  for (int i =0; i < dim1; i ++) {
    for (int j=0; j <dim2; j++) {
      cout << maze[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

	
