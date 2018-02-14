/*----------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Description: This is process.cpp class. it contains its instances and functions to concatenate the strings. to shown the first way by typing "1", the second way by typing "0". Finally, display the string.
Asignment: Lab 7
Date: 03/26/2013
------------------------------------------------------*/
#include "Process.h"


void Process::Start(char *str)
{
	int select;
	
	std::cout<<"please make a choice of order"<<std::endl;
	std::cout<<"typing 1: According the string pop order\n";
	std::cout<<"typing 0: According the string push order\n";
	
	//Choose the output mode 
	cin>>select;
	
	//If the input string is not empty, ergodic string 
	while(*str)
	{	
		//If the current character is instead a digit
		if(*str>='0' && *str <='9')
		{
			PopMainStack(*str-'0',select);
			
		}else    //If the current character not a digit
		{	
			string l_str;	
			l_str =*str;
			PushMainStack(l_str);		//push character 
			
		}
		str++;  //pointer move down
	}
	
	// if stack1 not empty, remove the last','
	if(!stack1.isEmpty())
	{
		string l_str;
		l_str= stack1.peek();
		stack1.pop();
		
		l_str.erase(l_str.length()-1);
		stack1.push(l_str);
	}
}
//push
void Process::PushMainStack(string str)
{
	str+=",";
	stack1.push(str);
}

//pop
void Process::PopMainStack(int length,int dir)
{
	string str="";
	int i=0;
	//If the digit is 0,  push "()"
	if(length ==0)
	{
		str ="(),";
		stack1.push(str);
	}else
	{
		while(!stack1.isEmpty())
		{
			if( i == length) 
				break;
			if(dir !=1)
			{
				str+= stack1.peek();
			}else
			{
				str= stack1.peek() +str;
			}
			
			stack1.pop();
			i++;
		}
		
		if(i!=length)//report error if i is not equal to length.
		{
			cout<<"stack underflow"<<endl;
			return ;// return 
		}
		
		str.erase(str.length()-1);
		str = "("+str+"),";
		stack1.push(str);
	}	
}
	
// output 
void Process::Display()
{
	string str;
	while(!stack1.isEmpty())
	{	
		str= stack1.peek();
		cout<<str;
		stack1.pop();
	}
	cout<<endl;
}
