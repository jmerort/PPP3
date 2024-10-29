/*
E2.8
[8] Write a program to test an integer value to determine if it is odd or even.
As always, make sure your output is clear and complete. In other words,
don’t just output yes or no. Your output should stand alone, like The
value 4 is an even number. Hint: See the remainder (modulo) operator in
§2.4.

29 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    int n = 0;
    std::cout << "Enter an integer number (i.e.: \"4\"):\n";
    std::cin >> n;

    if(n%2 == 0)
        std::cout << "The number " << n << " is even.\n";
    else
        std::cout << "The number " << n << " is odd.\n";

    return 0;
}