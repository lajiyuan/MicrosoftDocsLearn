//
// Created by root on 3/18/21.
//

#include <iostream>
using namespace std;
int main()
{
	struct Bar
	{
		int x;
		int y;
		char a;
		char b;
		int z;
	};
	// 内存对齐默认4字节， 可以通过alignas(num) 来指定num对齐
	// 不同的默认类型对齐方式为: short on 2-byte boundaries, int, long, and float on 4-byte boundaries
	// and long long, double, and long double on 8-byte boundaries
	cout << alignof(Bar) << endl;// cout 4
	cout << sizeof(Bar) << endl; // cout 16
	/*/
	 * int x: 4
	 * int y: 4
	 * char a: 1
	 * char b: 1
	 * char pad[2]: 2 // 用来对齐
	 * int z: 4
	 */
	// alignas argument need power of 2
	struct alignas(16) Bar2
	{
		int x;
		int y;
		char a;
		char b;
		int z;
	};
	cout << alignof(Bar2) << endl;// cout 16
	cout << sizeof(Bar2) << endl; // cout 16
	return 0;
}