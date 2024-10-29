/*
E2.2
[2] Write a program in C++ that converts from miles to kilometers. Your
program should have a reasonable prompt for the user to enter a number
of miles. Hint: A mile is 1.609 kilometers.

28-Oct-2024
@jmerort
*/

#include <iostream>

int main()
{
    const double mil_km = 1.609; //conversion factor
    double miles = 0;

    std::cout << "Enter a distance in miles:\n";
    std::cin >> miles;

    double kilometers = miles * mil_km;
    if(miles != 1)
        std::cout << miles << " miles equal " << kilometers << " kilometers.\n";
    else
        std::cout << miles << " mile equals " << kilometers << " kilometers.\n";

    return 0; 
}
