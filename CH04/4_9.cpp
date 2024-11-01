/*
---
E4.9
[9] Modify the program from the previous exercise to write out an error if
the result cannot be represented as an int.
---

Adding a simple check to the previous program, this can be done.

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
        {
            int u = n; //check that the user enters an integer
            double w = u;
            if (n != w)
                throw(std::runtime_error("enter an integer."));
            series.push_back(u);
        }

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