/*
E3.4
[4] Read a sequence of double values into a vector. Think of each value as the
distance between two cities along a given route. Compute and print the
total distance (the sum of all distances). Find and print the smallest and
greatest distance between two neighboring cities. Find and print the
mean distance between two neighboring cities.

29 Oct 2024 
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector <double> distances = {};
    double d = 0,
           sum = 0,
           avg = 0;

    //fill the vector with doubles until something else is input
    std::cout << "Enter a series of distances or enter \"|\" to end the input (e.g.: \"10 -13 40 24 |\").\n";
    while (std::cin >> d) 
        distances.push_back(d);

    for (int i = 0; i < distances.size(); i++) 
        sum += distances[i];
    avg = sum / distances.size(); 

    std::sort(distances.begin(), distances.end()); //sort in order to get the biggest and smallest values

    std::cout << "The sum of distances is: " << sum <<".\n"
              << "The greatest distance is: " << distances[0] << " and the smallest is: " << distances[distances.size()-1] << ".\n"
              << "The average distance is: " << avg << ".\n";
     
    return 0;
}

/*
Negative distances are allowed to be input, which makes no sense. I should probably
raise an exception, using what is shown in the next unit.
*/