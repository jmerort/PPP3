/*
E2.9
[9] Write a program that converts spelled-out numbers such as “zero” and
“two” into digits, such as 0 and 2. When the user inputs a number, the
program should print out the corresponding digit. Do it for the values 0,
1, 2, 3, and 4 and write out not a number I know if the user enters
something that doesn’t correspond, such as stupid computer!.

29 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    std::string n = " ";
    std::cout << "Write a number using letters (e.g.: \"three\"):\n";
    std::cin >> n;

    if(n == "zero" || n == "Zero" || n == "ZERO") //you can spell the number any (reasonable) way
    {
        std::cout << "0\n";
    }
    else if(n == "one" || n == "One" || n == "ONE")
    {
        std::cout << "1\n";
    }
    else if(n == "two" || n == "Two" || n == "TWO")
    {
        std::cout << "2\n";
    }
    else if(n == "three" || n == "Three" || n == "THREE")
    {
        std::cout << "3\n";
    }
    else if(n == "four" || n == "Four" || n == "FOUR")
    {
        std::cout << "4\n";
    }
    else
    {
        std::cout << "I don't know the number " << n << ".\n";
    }

    return 0;
}