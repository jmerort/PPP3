/*
---
E4.3
[3] Absolute zero is the lowest temperature that can be reached; it is
-273.15C, or 0K. The above program, even when corrected, will
produce erroneous results when given a temperature below this. Place a
check in the main program that will produce an error if a temperature is
given below -273.15C.
---

31 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm>


double ctok(double c)
{
    if(c < -273.15)
        throw std::runtime_error("Value below absolute zero.");

    int k = c + 273.15; //converts Celsius to Kelvin
    return k;
}

int main()
{
    try 
    {
            double d = 0;       //declare input variable
            std::cin >> d;      //retrieve temperature to input variable
            double k = ctok(d); //convert temperature
            std::cout << k << std::endl ; //print out temperature
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error:" << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Unknown error.\n";
    }
}