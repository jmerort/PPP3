/*
---
E4.7
[7] Quadratic equations are of the form a*x2 + b*x + c = 0. To solve these,
one uses the quadratic formula: x = −b± √b 2 − 4ac/2a. There is a problem,
though: if b^2- 4ac is less than zero, then it will fail. Write a program that
can calculate x for a quadratic equation. Create a function that prints out
the roots of a quadratic equation, given a, b, c. When the program
detects an equation with no real roots, have it print out a message. How
do you know that your results are plausible? Can you check that they are
correct?
---

We can know that the results are plausible by doing the calculations in our
head for simple cases like 1 2 1, 1 0 -1, 1 1 1 and so on. We can check that
they are correct by using another calculator like Matlab to check more complex
cases.

1 Nov 2024
*/

#include <iostream>
#include <vector>
#include <math.h>

std::vector <double> cuadratica(std::vector <double> coefs)
{
    double a = coefs[0],
           b = coefs[1],
           c = coefs[2];

    std::vector <double> roots (2);

    if (b*b-4*a*c < 0)
        throw (std::runtime_error("The equation has no real roots."));
    else if (a == 0)
        throw (std::runtime_error("You must enter a quadratic equation, a can't be zero."));
    else 
        roots[0] = (-b + std::sqrt(b*b - 4*a*c))/(2*a);
        roots[1] = (-b - std::sqrt(b*b - 4*a*c))/(2*a);

    return roots;
}

int main()
{
    try
    {
        double a = 0, //coefficients
               b = 0,
               c = 0,
               r1 = 0, //roots
               r2 = 0;

        std::cout << "Enter the a, b & c coefficients of a quadratic equation of the form ax² + bx + c:\n";
        std::cin >> a >> b >> c;
        std::vector <double> coefs = {a, b, c}; 

        std::vector <double> roots = cuadratica(coefs);
        std::cout << "The roots of the equation are: " << roots[0] << " y " << roots[1] << ".\n";

        return 0;
    }

    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}