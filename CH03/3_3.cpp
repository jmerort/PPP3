/*
E3.3 
[3] If we define the median of a sequence as “a number so that exactly as
many elements come before it in the sequence as come after it,” fix the
program in §3.6.3 so that it always prints out a median. Hint: A median
need not be an element of the sequence.

29 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm> //needed in order to use sort()

int main()
{
    std::vector <double> temps = {};
    double d = 0,
           sum = 0,
           avg = 0,
           median = 0;

    //fill the vector with doubles until something else is input
    std::cout << "Enter a series of temperatures or enter \"|\" to end the input (e.g.: \"10 -13 40 24 |\").\n";
    while (std::cin >> d) 
        temps.push_back(d);

    for (int i = 0; i < temps.size(); i++) 
        sum += temps[i];
    avg = sum / temps.size(); 

    //computation of the median, if the series is even (there is no one middle element) we pick as median the average of the two middle elements
    std::sort(temps.begin(), temps.end());
    if (temps.size()%2 == 0)
        median = (temps[temps.size()/2 - 1]+temps[temps.size()/2])/2;
    else 
        median = temps[temps.size()/2];


    std::cout << "The sum of temperatures is: " << sum <<".\n"
              << "The lowest temperature is: " << temps[0] << " and the highest is: " << temps[temps.size()-1] << ".\n"
              << "The average temperature is: " << avg << ".\n"
              << "The median temperature is: " << median << ".\n";     
     
    return 0;
}