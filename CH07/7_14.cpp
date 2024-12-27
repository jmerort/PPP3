/*
---
E7.14
[14] Can we declare a non-reference function argumentconst (e.g., void
f(const int);)? What might that mean? Why might we wantWhy don't people do
that often? Try it; write a couple of small programs to see what works.
---

It means that the function will create a copy of the input parameter, but (the compiler)
will give an error if the copy is modified in its body. I don't see why one would do that
instead of declaring a constant reference argument, which does the same but avoids copying
the parameter.

Dec 2024
@jmerort
*/

#include <iostream>

using std::cout;


int sum(const int a, const int b)
{
	return(a+b);
}

int main()
{
	int n1 = 10,
	    n2 = 20;

	cout << n1 << " + " << n2 << " = " << sum(n1,n2) << '\n';
	return 0;
}
