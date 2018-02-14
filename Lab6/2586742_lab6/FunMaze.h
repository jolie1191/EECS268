/*-------------------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Assignment: Lab6
Description: this is a FunMaze.h class. it contains its instances and declare constructors and functions.
Date: 03/12/2013
---------------------------------------------------------------*/
#ifndef FUNMAZE_H
#define FUNMAZE_H

class FunMaze
{
private:
	char** maze;
	int dim1;
	int dim2;

public:
	FunMaze();
	~FunMaze();
	void readMaze(char* fileName);
	void solveMaze(int x, int y);
	void printMaze();
};

#endif
