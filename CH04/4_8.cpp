/*
---
E4.8
[8] Write a program that reads and stores a series of integers and then
computes the sum of the first N integers. First ask for N, then read the
values into a vector, then calculate the sum of the first N values. For
example:
Please enter the number of values you want to sum: 3
Please enter some integers (press ’|’ to stop): 12 23 13 24 15 |
The sum of the first 3 numbers ( 12 23 13 )is 48
Handle all inputs. For example, make sure to give an error message if
the user asks for a sum of more numbers than there are in the vector.
---

1 Nov 2024
@jmerort
*/

#include <iostream>
#include <vector>

int main()
{
    try
    {
        int i {0}, 
            sum {0};

        double n {0};

        std::vector <int> series {};


        std::cout << "Please enter the number of values you want to sum:\n";
        std::cin >> i;
        if (!std::cin)
            throw(std::runtime_error("enter an integer."));

        std::cout << "Please enter some integers (press \"|\" to stop):\n";
        while(std::cin >> n)
            series.push_back(n);

        if(i > series.size()) //check sum size
            throw(std::runtime_error("number of terms to sum is bigger than series."));

        for(int u = 0; u < i; ++u)
            sum += series[u];

        std::cout << "The sum of the first " << i << " numbers is " << sum << ".\n";

        return 0;
    }

    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    catch(...)
    {
        std::cerr << "Error: unknown error.\n";
        return 2;
    }
}