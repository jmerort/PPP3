/*
---
E7.11
[11] Write a function that finds the smallest and the largest element of a
vector argument and also computes the mean and the median. Do not use
global variables. Either return a struct containing the results or pass them
back through reference arguments. Which of the two ways of returning
several result values do you prefer and why?
---

I personally prefer havign the function return a struct with the results, because it
seems more simple and easier to understand, rather than declaring the variables in the 
calling function and having its values modified by compute_stats(). I think the former 
program logic is a better expression of my idea of solving this problem.

Dec 2024
@jmerort
*/


#include <iostream>
#include <vector>
#include <algorithm>

using std::vector,
      std::cout;


double maxv(vector <double> v)
{
    //return the biggets element of a vector
    if(v.size() == 0) throw(std::runtime_error("empty vector."));
    double max = v[0];
    int size = v.size();

    for(int i = 1; i < size; i++)
        if(v[i] > max) max = v[i];

    return max;
}



double minv(vector <double> v)
{
    //return the smallest element of a vector
    if(v.size() == 0) throw(std::runtime_error("empty vector."));
    double min = v[0];
    int size = v.size();

    for(int i = 1; i < size; i++)
        if(v[i] < min) min = v[i];

    return min;
}



double meanv(vector <double> v)
{
    //return the mean of a vector
    if(v.size() == 0) throw(std::runtime_error("empty vector."));
    double mean = 0;
    double sum = 0;
    int size = v.size();

    for(int i = 0; i < size; i++)
        sum += v[i];
    mean = sum/size;

    return mean;
}



double medianv(vector <double> v)
{
    //return the median of a vector
    if(v.size() == 0) throw(std::runtime_error("empty vector."));
    double median = 0;

    std::sort(v.begin(), v.end());

    if(v.size()%2 == 0)
        median = (v[v.size()/2] + v[v.size()/2 -1]) / 2;
    else
        median = v[v.size()/2];

    return median;
}



struct Stats
{
    double smallest,
           largest,
           mean,
           median;
};



Stats compute_stats(vector <double> v)
{
    Stats s {0,0,0,0}; //create struct to hold the stats
    s.smallest = minv(v);
    s.largest = maxv(v);
    s.mean = meanv(v);
    s.median = medianv(v);

    return s;
}



void print_stats(Stats s)
{
    cout << "Largest: " << s.largest << '\n'
         << "Smallest: " << s.smallest << '\n'
         << "Mean: " << s.mean << '\n'
         << "Median: " << s.median << '\n';
}



int main()
{
    try
    {
        vector <double> v1 {10, 20, 5, -10, 50, 100, 20}, //odd sized input vector
                        v2 {5, 40, 30, 20}; //even sized input vector
        
        
        Stats v1_stats = compute_stats(v1);
        cout << "V1 statistics:\n";
        print_stats(v1_stats);

        Stats v2_stats = compute_stats(v2);
        cout << "V2 statistics:\n";
        print_stats(v2_stats);

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        std::cerr << "Unknown error.\n";
        return 2;
    }
    


}