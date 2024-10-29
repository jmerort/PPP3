/* 
E2.7
[7] Do exercise 6, but with three string values. So, if the user enters the
values Steinbeck, Hemingway, Fitzgerald, the output should be Fitzgerald,
Hemingway, Steinbeck.

28 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    std::string a = " ",
        b = " ",
        c = " ",
        greater = " ",
        medium = " ",
        smaller = " ";
    
    std::cout << "Write three names (e.g.:\"Pedro Santiago Marcos\"):\n";
    std::cin >> a >> b >> c;


    if (a >= b and a >= c) //if a is the biggest (last in alphabetical order)...
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

    std::cout << "Here they go, in alphabetical order: " << smaller << ", " << medium << ", " << greater << ".\n";

    return 0;
}