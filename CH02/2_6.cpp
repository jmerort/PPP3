/*
E2.6
[6] Write a program that prompts the user to enter three integer values, and
then outputs the values in numerical sequence separated by commas. So,
if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
values are the same, they should just be ordered together. So, the input 4
5 4 should give 4, 4, 5.

28 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    int a = 0,
        b = 0,
        c = 0,
        greater = 0,
        medium = 0,
        smaller = 0;
    
    std::cout << "Enter three integer numbers (e.g.: \"3 14 1\"):\n";
    std::cin >> a >> b >> c;

    if (a >= b and a >= c) //if a is the biggest...
    {
        greater = a;
        if (b >= c)
        {
            medium = b;
            smaller = c;
        }    
        else
        {
            medium = c;
            smaller = b;
        }
    }

    else if (b >= a and b >= c) //if b is the biggest...
    {
        greater = b;
        if (a >= c)
        {
            medium = a;
            smaller = c;
        }    
        else
        {
            medium = c;
            smaller = a;
        }
    }

    else //if c is the biggest...
    {
        greater = c;
        if (a >= b)
        {
            medium = a;
            smaller = b;
        }    
        else
        {
            medium = b;
            smaller = a;
        }
    }

    std::cout << "Here are the values, ordered: " << smaller << ", " << medium << ", " << greater << ".\n";

    return 0;
}