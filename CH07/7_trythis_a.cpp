/*
---
TT7-a
Try This
Compile the three examples above to see how the compiler complains.
Then add a definition of f() to get a running version.
---

Dec 2024
@jmerort
*/

#include <iostream>

int f(int); // declaration of f

int main()
{
	int i = 7; // definition of i
	std::cout << f(i) << '\n';
}

int f(int n) //definition of f	
{
	return n*2;
}


