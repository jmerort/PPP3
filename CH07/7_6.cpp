/*
---
E7.6
[6] Write versions of the functions from exercise 5, but with a vector<string>
---

Didn't have to change much :-)

Dec 2024
@jmerort
*/



#include <iostream>
#include <vector>



using std::vector,
      std::string,
      std::cout;



void print(vector <string> v)
{
    for(int i = 0; i < v.size(); i++) cout << v[i] << "\n";
}



vector <string> reverse(vector <string> v)
{
    //return a new vector with the elements of the input reversed e.g. {"uno","dos","tres"} -> {"tres","dos","uno"}
    vector <string> rev;
    for(int i = 1; i <= v.size(); i++)
        rev.push_back(v[v.size()-i]); //push back all elements of v starting from the end

    return rev;
}



void reverse_sw(vector <string>& v)
{
    //reverse all elements of a vector e.g. {"uno","dos","tres"} -> {"tres","dos","uno"}
    for (int i = 0; i < v.size()/2; i++)
    {
        std::swap(v[i], v[v.size()-1-i]);
    }
}



int main()
{
    vector <string> v1 {"uno", "dos", "tres", "cuatro", "cinco"},
                    v2 {reverse(v1)};

    //print(v2);

    //print(v1);
    reverse_sw(v1);
    print(v1);

    return 0;
}
