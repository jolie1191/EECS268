/*-----------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Description: This is main class. it will use Process.h class.
Assignment: Lab7
Date: 03/26/2013
---------------------------------------------------------*/
#include <iostream>
#include <string>
#include "Process.h"


int main(int argc,char *argv[])
{
	Process Pro;
	
	if(argc ==2){
		Pro.Start(argv[1]);
		Pro.Display();
	}else
	{
		cout<<"please pass string you want by argv[1]"<<endl;
	}
	return 0;
}
