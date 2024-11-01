/*
---
E4.11
[11] Write a program that writes out the first N values of the Fibonacci series,
that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next number
of the series is the sum of the two previous ones. Find the largest
Fibonacci number that fits in an int.
---

Giving the program a big value, I can see the largest fibonacci number that fits an
int is 1073741824, with the next one the int overflows and gives me -2147483648.

1 Nov 2024
@jmerort
*/

#include <iostream>

int main()
{
    try
    {
        int n {0},
            current {1},
            previous {0};

        std::cout << "Enter the number of Fibonacci terms you want: ";
        std::cin >> n;
        if(!std::cin)
        {
            throw(std::runtime_error("wrong value entered (enter an integer)."));
        }

        for (int i{0}; i < n; ++i)
        {
            std::cout << current << "\n";
            current = current + previous;
            previous = current;
        }

        std::cout << "-END-\n";

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error:" << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        std::cerr << "Error: unknown error.\n";
        return 2;
    }
}