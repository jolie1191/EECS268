main: main.o Process.o
	g++ -g -o main main.o Process.o
main.o: ArrayStack.h ArrayStack.cpp main.cpp
	g++ -c -g main.cpp
Process.o: Process.cpp Process.h 
	g++ -c -g Process.cpp 
