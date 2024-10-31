/*
---
E3.20
[20] Modify the program from the previous exercise so that once you have
entered the name-and-value pairs, you ask for names: In a loop, when
you enter a value, the program will output all the names with that score
or score not found.
---

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

    int cu_score {-1},
        pr_score {0},
        q {0}; //q is an int now

    bool found {false};

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

    std::cout << "Now enter a score to get the people who have it or press CTRL-D to exit the program:\n";
    while(std::cin >> q)
    {
        for(int i = 0; i < scores.size(); ++i) //loop it
            if (q == scores[i])
            {
                std::cout << names[i] << " has a score of " << scores[i] << ".\n";
                found = true;
            }
        if (found == false)
            std::cout << "Score not found.\n";
        
        found = false;
    }

    return 0;
}