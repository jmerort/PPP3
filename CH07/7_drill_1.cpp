/*
---
UNIT 7 DRILL PART 1
[1] Write three functions swap_v(int,int), swap_r(int&,int&), and swap_cr(const
int&, const int&). Each should have the body { int temp; temp = a, a=b; b=temp; } where a and b are the names of the arguments.
Try calling each swap like this 

int x = 7;
int y = 9;
swap_?(x,y);
swap_?(7,9);
const int cx = 7;
const int cy = 9;
swap_?(cx,cy);
swap_?(7.7,9.9);
double dx = 7.7;
double dy = 9.9;
swap_?(dx,dy);
swap_?(7.7,9.9);

Which functions and calls compiled, and why? After each swap that
compiled, print the value of the arguments after the call to see if theywere actually swapped. If you are surprised by a result, consult §7.5.
---

All functions and calls with swap_v compiled, but no variables were swapped, because swap_v only modifies the values of the local copies
of a and b that it creates.

Only the first call to swap_r was compiled, because all the others tried to modify numeric literals (which don't have variables associated to them), 
constants (which can't be modified) or tried to pass doubles by reference to a function expecting ints. The one function that compiled does in fact
modify the values of x and y.

The definition of swap_cr can't compile because it tries to modify 2 constants in its own body, so it can't be used.


Dec 2024
@jmerort
*/

#include <iostream>
using std::cout;


void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


int main()
{
	int x = 7;
	int y = 9;

	swap_r(x,y);
	cout << x << ", " << y << "\n";

	swap_cr(7,9);	
	cout << x << ", " << y << "\n";

	const int cx = 7;
	const int cy = 9;
	
	swap_cr(cx,cy);	
	cout << x << ", " << y << "\n";

	swap_cr(7.7,9.9);	
	cout << x << ", " << y << "\n";

	double dx = 7.7;
	double dy = 9.9;

	swap_cr(dx,dy);	
	cout << x << ", " << y << "\n";

	swap_cr(7.7,9.9);	
	cout << x << ", " << y << "\n";

	return 0;
}
