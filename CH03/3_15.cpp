/*
---
E3.15 
[15] In the drill, you wrote a program that, given a series of numbers, found
the max and min of that series. The number that appears the most times
in a sequence is called the mode. Create a program that finds the mode
of a set of positive integers.
---

The loop is kinda hard to read.

30 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int appearances {0}, //how many consecutive times a value appears (2 times = 1, 3 times = 2...)
        mode {0}, //consecutive times the mode has appeared
        n {0}, //value to input
        previous{-1}, 
        current{-1};
    std::vector <double> measures {};
    std::vector <double> modes {}; //to hold the current modes


    //we fill a vector with integers and sort it
    std::cout << "Enter integer numbers or enter \"|\" to finish the program: \n";

    while (std::cin >> n) 
        measures.push_back(n); 

    std::sort(measures.begin(), measures.end());


    //we check the number of consecutive times each value appear and store the mode/s
    current = measures[0];
    for (int i = 0; i < measures.size(); ++i)
    {
        current = measures[i];
        if (current == previous)
            ++appearances;
        else 
        {
            if (appearances > mode) //new mode is found which surpasses the current mode/s
            {
                mode = appearances;
                modes.clear();
                modes.push_back(previous);
            }
            else if (appearances == mode) //new mode is found equal to the current mode
            {
                modes.push_back(previous);
            }
            appearances = 0;
        }
        previous = current;
    }

    if (appearances > mode) //so that the last value is counted, if it is a repeat
            {
                mode = appearances;
                modes.clear();
                modes.push_back(previous);
            }
            else if (appearances == mode)
                modes.push_back(previous);
    

    //output
    if (modes.size() == 1)
        std::cout << "The mode is " << modes[0] << " which appears " << mode + 1 <<" times.\n--END--\n";
    else 
    {
        std::cout << "The modes are:\n";
        for (int u = 0; u < modes.size(); ++u)
            std::cout << modes[u] << "\n";
        std::cout << " which appear " << mode + 1 << " times.\n--END--\n";
    }

    return 0;
}