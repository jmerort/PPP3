/*
---
E4.10
[10] Modify the program from the previous exercise to use double instead of
int. Also, make a vector of doubles containing the N-1 differences
between adjacent values and write out that vector of differences.
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
        int i {0}; //number of values to sum

        double n {0},
               sum {0};

        std::vector <double> series {},
                             diffs {}; //differences between adjacent values


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

        for(int v = 0; v < series.size() - 1; ++v)
            diffs.push_back(series[v]-series[v-1]);

        std::cout << "The sum of the first " << i << " numbers is " << sum << ".\n"
                  << "The differences between adyacent numbers are: ";
        for(int w = 0; w < diffs.size(); ++w)
            std::cout << diffs[w] << "    ";
        
        std::cout << "\n--END--\n";

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