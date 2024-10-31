/*
--- 
E3.18
[18] Write a program where you first enter a set of name-and-value pairs,
such as Joe 17 and Barbara 22. For each pair, add the name to a vector
called names and the number to a vector called scores (in corresponding
positions, so that if names[7]=="Joe" then scores[7]==17). Terminate input
with NoName 0. Check that each name is unique and terminate with an
error message if a name is entered twice. Write out all the (name,score)
pairs, one per line.
---

This can be made hard, until you find a convenient way of handling repeated words.

31 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool repeat(std::string word, std::vector <std::string> v)
{
    //Checks is a given word is in a vector of strings and returns "true" if there is at least one instance of it.
    bool rep {false};

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == word)
            rep = true;
    }

    return rep;
}

int main()
{
    std::vector <std::string> names {};
    std::vector <int> scores {};

    std::string cu_name {" "},
                pr_name {"NoName"};
    int cu_score = -1,
        pr_score = 0;

    //fill the vectors with names/scores, checking each iteration for repeats
    std::cout << "Enter names followed by scores or end the program by entering \"NoName 0\" (e.g.: \"John 24\")\n";
    std::cin >> cu_name >> cu_score;

    while (cu_name != "NoName" or cu_score != 0) //only both at once end the program
    {
        names.push_back(cu_name);
        scores.push_back(cu_score);

        pr_name = cu_name;
        pr_score = cu_score;
        std::cin >> cu_name >> cu_score;

        if (repeat(cu_name, names) == true) //if the name is a repeat, exit the loop
        {
            std::cout << "Error: repeated name: " << cu_name << ".\n";
            break;
        }
    }

    std::cout << "--STATS--\n";
    for(int i = 0; i < names.size(); ++i)
        std::cout << names[i] << " " << scores[i] << "\n";

    return 0;
}