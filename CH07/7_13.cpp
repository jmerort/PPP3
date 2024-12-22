/*
---
E7.13
[13] Write a function that takes a vector<string> argument and returns a
vector<int> containing the number of characters in each string. Also find
the longest and the shortest string and the lexicographically first and last
string. How many separate functions would you use for these tasks?
Why?
---

Lexicographical ordering is a generalization of alphabetical order to include 
non alphabetical symbols, such as numbers. std::sort() does it by default.

As we are taught to implement a function for every logically separate action,
I will implement 5 functions here, even if it means more function calls in this
particular program.

Dec 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector,
      std::string,
      std::cout;



vector <int> num_char (vector <string> v)
{
    //return a vector with the number of letters of each string element
    vector <int> count;
    for(string i : v)
    {
        count.push_back(i.size());
    }

    return count;
}



string get_longest(vector <string> v)
{
    //return the longest word of string vector (if there are multiple of the same size, return the first of these)
    if (v.size() == 0) throw(std::runtime_error("get_longest(): empty vector"));

    string longest;
    int count = 0,
        size = v.size(); //to avoid calling size() over and over in the loop
    vector<int> c {num_char(v)}; //count the letter numbers of each word

    for(int i{0}; i < size; i++)
    {
        if(c[i] > count)
        {
            longest = v[i];
            count = c[i];
        }
    }

    return longest;
}



string get_shortest(vector <string> v)
{
    //return the shortest word of string vector (if multiple, return the first of the shortest)
    if (v.size() == 0) throw(std::runtime_error("get_shortest(): empty vector"));

    string shortest;
    int count = 999,
        size = v.size();
    vector<int> c {num_char(v)};

    for(int i{0}; i < size; i++)
    {
        if(c[i] < count) 
        {
            shortest = v[i];
            count = c[i];
        }
    }

    return shortest;
}



string get_first(vector <string> v)
{
    //return the lexicographically first element of string vector
    if (v.size() == 0) throw(std::runtime_error("get_first(): empty vector"));
 
    std::sort(v.begin(), v.end());
    return v[0];
}



string get_last(vector <string> v)
{
    //return the lexicographically last element of string vector
    if (v.size() == 0) throw(std::runtime_error("get_last(): empty vector"));

    std::sort(v.begin(), v.end());
    return v[v.size()-1];
}


void print(vector <int> v) 
{
    //print int vector
    for(int i : v) cout << i << '\t';
    cout << '\n';
}



void print(vector <string> v) 
{
    //print int vector
    for(string i : v) cout << i << '\t';
    cout << '\n';
}



int main()
{
    try
    {
        vector <string> v1 {"mary", "had", "a", "little", "lamb"};
        vector <int> count {num_char(v1)};


        //print results
        cout << "The string vector is:\n";
        print(v1); 

        cout << "Word numbers:\n";
        print(count);

        cout << "The longest word is: " << get_longest(v1) << '\n';
        cout << "The shortest word is: " << get_shortest(v1) << '\n';
        cout << "The first word is: " << get_first(v1) << '\n';
        cout << "The last word is: " << get_last(v1) << '\n';

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