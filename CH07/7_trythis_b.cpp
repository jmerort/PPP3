/*
---
TT7-b
Try This
Type in the example above and indent it properly. What suspicious
constructs and bugs can you now find?
---

Dec 2024
@jmerort
*/

// dangerously ugly code
struct X 
{
	void f(int x) 
	{
		struct Y 
		{
			int f() { return 1; } 
			int m; 
		};
		int m;
		m=x;
	       	Y m2;
		return f(m2.f()); //this would cause an endless loop, and I think there is also a scope problem, as f doesn't know the Y struct
	}
	int m; 
	void g(int m) 
	{
		if (0<m) f(m+2);
	       	else 
		{
			g(m+2.3); //another endless loop >:(
		}
	}
	X() { } // this doesn't even mean anything
       	int m3() {} // empty function
	void main() // main inside of a struct?
	{
		X a; // struct instance inside of the struct?
	       	a.f(2);
	}
};
