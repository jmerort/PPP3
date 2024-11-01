/*
---
E5.5
[5] Add to the program so that it can also convert from Kelvin to Celsius.
---

1 Nov 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm>


double ctok(double c, char u)
{
    if ((u == 'c' and c < -273.15)or(u == 'k' and c < 0))
        throw std::runtime_error("Temperature below absolute zero.");

    switch (u)
    {
        case 'c':
            return c + 273.15;                     //converts Celsius to Kelvin
            break;
        case 'k':
            return c - 273.15;                     //converts Kelvin to Celsius
            break;
        default:
            throw std::runtime_error("Wrong unit.");
    }
}

int main()
{
    try 
    {
            double d = 0;                   //declare input variable
            char u = ' ';

            std::cout << "Enter a temperature in celsius (c) or kelvin (k) (e.g.: \"50 k\", \"100 c\"):\n";
            std::cin >> d >> u;             //retrieve temperature to input variable
            double k = ctok(d, u);          //convert temperature
            std::cout << k << std::endl ;   //print out temperature
    }
    catch(std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << "\n"; 
    }
}