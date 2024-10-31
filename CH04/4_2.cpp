/*
---
E4.2
[2] The following program takes in a temperature value in Celsius and
converts it to Kelvin. This code has many errors in it. Find the errors,
list them, and correct the code.
---

As I don't write using namespace std, i have to add std:: to some objects, but
that is not one of the intended errors.

31 Oct 2024
@jmerort
*/

#include <iostream>

double ctok(double c) // converts Celsius to Kelvin
{
    int k = c + 273.25;
    return k; 
    //missing semicolon and variable name
}

int main()
{
    double c = 0; // declare input variable

    std::cin >> c; // retrieve temperature to input variable     
    // wrong variable name

    double k = ctok(c); // convert temperature 
    //extra quotation marks

    std::cout << k << '\n'; // print out temperature 
    //cout and "\n" are misspelled
}
