/*
E2.5
[5] Modify the program above to ask the user to enter floating-point values
and store them in double variables. Compare the outputs of the two
programs for some inputs of your choice. Are the results the same?
Should they be? What’s the difference?

The results of both programs are not the same, as double values can hold decimal numbers. Thus, if you enter "2.2 2.8"
in the first program both numbers will be read as 2. Also, the decimal parts of the ratio will be truncated using ints.

28 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    double val1 = 0,
           val2 = 0;
    
    std::cout << "Enter two floating-point numbers (e.g.: \"1.0 6.54\"):\n";
    std::cin >> val1 >> val2;

    double smallest = 0,
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
              << "The larger number is " << largest << " and the smaller " << smallest << "\n";

    return 0;
}