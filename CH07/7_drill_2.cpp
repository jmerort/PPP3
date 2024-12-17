/*
---
UNIT 7 DRILL PART 2
[2] Write a program using a single file containing three namespaces X, Y,
and Z so that the following main() works correctly:

int main()
{
	X::var = 7;
	X::print();	// print X's var
	using namespace Y;
	var = 9;
	print();	// print Y's var
	{
		using Z::var;
		using Z::print;		// print Z's var
		var = 11;
		print();
	}
	print(); 	// print Y's var
	X::print(); 	// print X's var
}

Each namespace needs to define a variable called var and a function
called print() that outputs the appropriate var using cout.
---

Dec 2024
@jmerort
*/

#include <iostream>
using std::cout;



namespace X
{
	int var = 0;
	void print(){cout << var;};
}

namespace Y
{
	int var = 0;
	void print(){cout << var;};
}

namespace Z
{
	int var = 0;
	void print(){cout << var;};
}


int main()
{
	X::var = 7;
	X::print();	// print X's var
	using namespace Y;
	var = 9;
	print();	// print Y's var
	{
		using Z::var;
		using Z::print;		// print Z's var
		var = 11;
		print();
	}
	print(); 	// print Y's var
	X::print(); 	// print X's var
}
