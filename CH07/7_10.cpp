/*
---
E7.10
[10] Write a function maxv() that returns the largest element of a vector
argument.
---

Dec 2024
@jmerort
*/

#include <iostream>
#include <vector>

using std::vector,
      std::cout;

double maxv(vector <double> v)
{
    //return the biggets element of a vector
    
    if(v.size() == 0) throw(std::runtime_error("empty vector."));
    double max = v[0];
    int n = v.size();

    for(int i = 1; i < n; i++)
        if(v[i] > max) max = v[i];

    return max;
}

int main()
{
    try
    {
        vector <double> v1 {1.45, 10.9, 30.9, 24.3, 34.3, 34.5},
                        v2 {-10, -23, -30, -24, -1},
                        v3 {100, 100},
                        v4 {};

        double max_1 = maxv(v1);
        cout << "The biggest element of v1 is " << max_1 << '\n';
        
        double max_2 = maxv(v2);
        cout << "The biggest element of v2 is " << max_2 << '\n';

        double max_3 = maxv(v3);
        cout << "The biggest element of v3 is " << max_3 << '\n';

        double max_4 = maxv(v4);
        cout << "The biggest element of v4 is " << max_4 << '\n';

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