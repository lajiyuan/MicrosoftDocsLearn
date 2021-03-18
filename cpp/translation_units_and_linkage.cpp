#include <iostream>
int main()
{
	extern int i;
	std::cout << i << std::endl;
	extern int x;
	std::cout << x << std::endl;
	/*
	 * A translation units consists of an implementation file and all the headers that it includes directly or indirectly
	 * You can force a global name to have internal linkage by explicitly declaring it as static. This limits its visibility to the same translation unit in which it is declared. In this context, static means something different than when applied to local variables.

		The following objects have internal linkage by default:
		const objects
		constexpr objects
		typedefs
		static objects in namespace scope
	 * To give a const object external linkage, declare it as extern and assign it a value:
	 * extern const int value = 42;
	 */
	return 0;
}
