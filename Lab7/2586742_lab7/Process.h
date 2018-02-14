/*----------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Description: This is Process.h class, it contains its functions and it also used ArrayStack.h class .
Asignment: Lab 7
Date: 03/26/2013
------------------------------------------------------*/
#ifndef _PROCESS_H
#define _PROCESS_H
#include <iostream>
#include <string>
using namespace std;
#include "ArrayStack.h"

class Process
{
public:
	void Start(char *str);
	void Display();

private:
	void PushMainStack(string str);
	void PopMainStack(int length,int dir);
private:
	ArrayStack<std::string> stack1;
	
};

#endif

