/*
---
E7.3
[3] Create a vector of Fibonacci numbers and print them using the function
from exercise 2. To create the vector, write a function, fibonacci(x,y,v,n),
where integers x and y are ints, v is an empty vector<int>, and n is the
number of elements to put into v; v[0] will be x and v[1] will be y. A
Fibonacci number is one that is part of a sequence where each element
is the sum of the two previous ones. For example, starting with 1 and 2,
we get 1, 2, 3, 5, 8, 13, 21, ... . Your fibonacci() function should make
such a sequence starting with its x and y arguments.
---

Dec 2024
@jmerort
*/

#include <iostream>
#include <vector>

void print(std::string label, std::vector <int> v)
{
	// print all elements of a vector of ints, preceded by the label string
	std::cout << label << "\n";
	for(int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << "\n";
	}	
}

void fibonacci(int x, int y, std::vector <int>& v, int n)
{
	// fills a given empty vector with fibonacci numbers, startign from arguments x and y, until 
	// n numbers are in the vector
	
	if(v.size() > 0) throw(std::runtime_error("Non empty vector.\n")); //check if vector is empty
	
	int fib = 0;
			
	v.push_back(x);
	v.push_back(y);
	
	for(int i = 2; i < n; i++)
	{
		fib = x + y; //compute the next term in fibonacci series

		v.push_back(fib); //fill the vector with fib numbers
		
		x = y; //update the two previous terms
		y = fib;
	}
}

int main()
{
	try
	{
		std::vector <int> v1;
		fibonacci(1, 1, v1, 10);
		print("fibonacci_numer_list", v1);
		return 0;
	}
	catch(std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
	catch(...)
	{
		std::cerr << "Unknown error.\n";
		return 1;
	}
}
