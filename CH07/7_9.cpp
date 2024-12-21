/*
---
E7.9
[9] Write a function that given two vector<double>s price and weight computes
a value (an “index”) that is the sum of all price[i]*weight[i]. Make sure to
have weight.size()==price.size().
---

Dec 2024
@jmerort
*/


#include <iostream>
#include <vector>

using std::vector;


double get_index (vector <double> price, vector <double> weight)
{
    if(price.size()!=weight.size()) throw(std::runtime_error("non-equal sized vectors."));

    double index = 0;
    int size = price.size();
    for(int i = 0; i < size; i++)
    {
        index += price[i]*weight[i];
    }

    return index;
} 


int main()
{
    try
    {
        vector <double> price {10, 20, 10},
                        size {1, 2, 1};

        double index = get_index(price, size);
        std::cout << "Index: " << index << "\n";

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}