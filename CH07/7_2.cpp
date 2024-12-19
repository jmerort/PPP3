/*
---
E7.2
[2] Write a function print() that prints a vector of ints to cout.Give it two
arguments: a string for "labelling" the output and a vector.
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

int main()
{
	std::vector <int> v1 {1, 2, 3, 4, 5};
	std::string label = "digits";

	print(label, v1);
	return 0;
}
