//
// Created by root on 3/18/21.
//
#include <cstdlib>
#include <iostream>

using namespace std;
void fun1()
{
	std::cout << "End1" << std::endl;
}
void fun2()
{
	std::cout << "End2" << std::endl;
}
int main()
{
	atexit(fun1);
	atexit(fun2);
	cout << "not end." << endl;
	exit(0);
	// The function pointed by func is automatically called without arguments when the program terminates normally.
	// if more than one,  they are all executed in reverse order as a stack
	return 0;
}
