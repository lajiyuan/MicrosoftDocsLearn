//
// Created by root on 3/18/21.
//

#include <iostream>
#include <string.h>

using namespace std;
int main(int argc, char **argv, char **envp)
{
	// envp is the list of env, = (printenv)
	for (int i = 0; envp[i] != nullptr; i++)
	{
		cout << envp[i] << endl;
	}
	return 0;
}