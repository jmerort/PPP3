/*
E2.4
[4] Write a program that prompts the user to enter two integer values. Store
these values in int variables named val1 and val2. Write your program to
determine the smaller, larger, sum, difference, product, and ratio of
these values and report them to the user.

28 Oct 2024 
@jmerort
*/

#include <iostream>

int main()
{
    int val1 = 0,
        val2 = 0;
    
    std::cout << "Enter two integer numbers (e.g.: \"1 2\"):\n";
    std::cin >> val1 >> val2;

    int smallest = 0,
        largest = 0,
        sum = val1 + val2,
        difference = val1 - val2,
        product = val1 * val2,
        ratio = val1 / val2;

    if(val1 > val2)
    {
        largest = val1;
        smallest = val2;
    }
    else if (val1 <= val2)
    {
        largest = val2;
        smallest = val1;
    }

    std::cout << "Product of " << val1 << " and " << val2 << " = " << product <<"\n"
              << "Sum = " << sum << "\n"
              << "Difference = " << difference << "\n"
              << "Ratio = " << ratio << "\n"
              << "The larger number is " << largest << " and the smaller is " << smallest << "\n";

    return 0;
}