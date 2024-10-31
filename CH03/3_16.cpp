/*
---
E3.16
[16] Write a program that finds the min, max, and mode of a sequence of
strings.
---

Just use the previous and change int to string

31 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int appearances {0}, //how many consecutive times a value appears (2 times = 1, 3 times = 2...)
        mode {0}; //consecutive times the mode has appeared
    std::string word {" "}, //value to input
         previous{" "}, 
         current{" "};
    std::vector <std::string> measures {};
    std::vector <std::string> modes {}; //to hold the current modes


    //we fill a vector with strings and sort it
    std::cout << "Enter a series of words or press \"CTRL-D\" to finish the program: \n";

    while (std::cin >> word) 
        measures.push_back(word); 

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