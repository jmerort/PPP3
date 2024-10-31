/*
---
E4.4
[4] Do exercise 3 again, but this time handle the error inside ctok().
---

Not sure about this solution. 

31 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm>


double ctok(double c)
{
    try
    {
        if(c < -273.15)
            throw(std::runtime_error("Value below absolute zero."));

        int k = c + 273.15;    //converts Celsius to Kelvin
        return k;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}

int main()
{
    double d = 0;          //declare input variable
    std::cin >> d;         //retrieve temperature to input variable
    double k = ctok(d);    //convert temperature
    std::cout << k << std::endl ; //print out temperature
}