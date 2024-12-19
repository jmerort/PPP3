/*
---
E7.4
[4] An int can hold integers only up to a maximum number. Find an
approximation of that maximum number by using fibonacci().
---

The highest fibonacci number before overflow (starting from 1 1) is 
1836311903
 
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
		if (fib < y)
		{
			std::cout << "Last number reached: " << y << "\n"; //if an overflow occurs, print the highest number reached and stop the program
			throw(std::runtime_error("Overflow.\n"));
		}
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
		fibonacci(1, 1, v1, 60);
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
