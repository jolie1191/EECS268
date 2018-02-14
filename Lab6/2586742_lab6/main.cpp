/*-------------------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Assignment: Lab6
Description: this is main class. create a object maze, and call the readMaze function and solveMaze function, finally return.
Date: 03/12/2013
---------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>

#include "FunMaze.h"

//Assume that the starting position is always [1][1]
#define START_DIM_1	1
#define START_DIM_2	1

int main(int argc, char* argv[])
{
	FunMaze maze;

	if( argc != 2)
	{
		std::cout << "One argument required: name of maze input file\n";
		exit(1);
	}

	maze.readMaze(argv[1]);
	maze.solveMaze(START_DIM_1, START_DIM_2);
  return 0;
}

	
