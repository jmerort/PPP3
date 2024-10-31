/*
---
E3.17
[17] Write a program to solve quadratic equations. A quadratic equation is of
the form ax2 + bx + c = 0. If you don’t know the formula for solving
such an expression, do some research. Remember, researching how to
solve a problem is often necessary before a programmer can teach the
computer how to solve it. Use doubles for the user inputs for a, b, and c.
Since there are two solutions to a quadratic equation, output both x1 and
x2.
---

The faults of this program will be corrected in the next unit, when we learn how to deal with errors.

31 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <math.h>

std::vector <double> quadratic(std::vector <double> coefs)
{
    double a = coefs[0],
           b = coefs[1],
           c = coefs[2];

    std::vector <double> roots (2);

    roots[0] = (-b + std::sqrt(b*b - 4*a*c))/(2*a);
    roots[1] = (-b - std::sqrt(b*b - 4*a*c))/(2*a);

    return roots;
}

int main()
{
    double a {0}, //coefficients
           b = {0},
           c = {0},
           r1 = {0}, //roots
           r2 = {0};

    std::cout << "Enter the coefficients a, b & c of a quadratic equation of the form ax² + bx + c:\n";
    std::cin >> a >> b >> c;
    std::vector <double> coefs = {a, b, c}; 

    std::vector <double> roots = quadratic(coefs);
    std::cout << "The roots of the equation are: " << roots[0] << " and " << roots[1] << ".\n";

    return 0;
}