/*
---
E7.5
[5] Write two functions that reverse the order of elements in a vector<int>.
For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse
function should produce a new vector with the reversed sequence,
leaving its original vector unchanged. The other reverse function should
reverse the elements of its vector without using any other vectors (hint:
swap).
---

Dec 2024
@jmerort
*/

#include <iostream>
#include <vector>



using std::vector,
      std::cout;



void print(vector <int> v)
{
    for(int i = 0; i < v.size(); i++) cout << v[i] << "\n";
}



vector <int> reverse(vector <int> v)
{
    //return a new vector with the elements of the input reversed e.g. {1,2,3} -> {3,2,1}
    vector <int> rev;
    for(int i = 1; i <= v.size(); i++)
        rev.push_back(v[v.size()-i]); //push back all elements of v starting from the end

    return rev;
}



void reverse_sw(vector <int>& v)
{
    //reverse all elements of a vector e.g. {1,2,3} -> {3,2,1}
    for (int i = 0; i < v.size()/2; i++)
    {
        std::swap(v[i], v[v.size()-1-i]);
    }
}



int main()
{
    vector <int> v1 {1, 2, 3, 4, 5},
                 v2 {reverse(v1)};

    //print(v2);

    //print(v1);
    reverse_sw(v1);
    print(v1);

    return 0;
}
