/*
---
E7.8
[8] Do the previous exercise but allow an arbitrary number of names.
---

Dec 2024
@jmerort
*/



#include <iostream>
#include <vector>
#include <algorithm>

using std::vector,
      std::string,
      std::cout,
      std::cin;



bool check_repeat(string nombre, vector <string> v)
{
    bool repeat = false;
    for(int i = 0; i < v.size(); i++)
    {
        if(nombre == v[i]) repeat = true;
    }

    return repeat;
}



vector <string> get_names()
{
    vector <string> names;
    string name;

    cout << "Enter a series of different names (separated by spaces) or end by entering \"|\": ";
    while(cin>>name)
    {
        if(name == "|") break; //terminating input
        if(!cin) throw(std::runtime_error("wrong input, enter a name."));
        if(check_repeat(name, names)) throw(std::runtime_error("repeated name."));
        names.push_back(name);
    }

    return names;
}



vector <int> get_ages(int size)
{
    vector <int> ages;
    int age = 0;

    cout << "Enter the ages of the people (separated by spaces): ";
    for(int i = 0; i < size; i++)
    {
        cin >> age;
        if(!cin) throw(std::runtime_error("wrong input, enter a number."));
        ages.push_back(age);
    }

    return ages;
}



void print_pairs(vector <string> names, vector <int> ages)
{
    for(int i = 0; i < ages.size(); i++)
        cout << names [i] << "\t" << ages[i] << " years\n";
}



void sort_pairs(vector <string>& names, vector <int>& ages)
{
    // sorts names vector in alphabetical order and sorts the corresponding ages too
    vector <string> names_cp = names; //copy vectors that won't be changed, to be used during age sorting
    vector <int> ages_cp = ages;

    std::sort(names.begin(), names.end()); //sort the names

    //Age sorting algorithm: for every name in ages_cp (not sorted), check if it equals any name in ages (sorted) 
    //and, if so, change the corresponding age in ages (to be sorted)
    for(int i = 0; i < ages.size(); i++)
    {
        for(int u = 0; u < ages.size(); u++)
        {
            if(names_cp[i]== names[u])
                ages[u] = ages_cp[i]; 
        }
    }
}

int main()
{
    try
    {
        //inputs
        vector <string> names = get_names();
        int size = names.size();
        vector <int> ages = get_ages(size);

        //print unordered names and ages
        print_pairs(names, ages);

        sort_pairs(names, ages);

        //print sorted results
        cout << "Ordered names and ages:\n";
        print_pairs(names, ages);

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    catch(...)
    {
        std::cerr << "Unknown error.\n";
        return 2;
    }
}