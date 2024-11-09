/*
---
E5.4
[4] Define a class Name_value that holds a string and a value. Rework
exercise 20 in Chapter 3 to use a vector<Name_value> instead of two
vectors.
---

8 Nov 2024
@jmerort
*/

#include <iostream>
#include <vector>

class Name_value {
    public: 
        std::string name;
        int value;
        
        Name_value(std::string n, int val):name(n), value(val) { } // make a Name_value from a name and a value
        Name_value(std::string n):name(n), value(0) { } // make a Name_value from just a name
};


bool repeat(Name_value current, std::vector <Name_value> v)
{
    //Checks if a given name is in a vector of NameValues and returns "true" if there is at least one instance of it.
    bool rep {false};

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].name == current.name)
            rep = true;
    }

    return rep;
}


int main ()
{
    try
    {
        std::vector <Name_value> v {};
        std::string cu_name;
        int cu_score;

        //fill the vectors with names/scores, checking each iteration for repeats
        std::cout << "Enter names followed by scores or end the program by entering \"NoName 0\" (e.g.: \"John 24\")\n";
        std::cin >> cu_name >> cu_score;
        if(!std::cin)
            throw(std::runtime_error("enter a number."));


        Name_value current {cu_name, cu_score};

        while (current.name != "NoName") //only both at once end the program
        {
            v.push_back(current);

            std::cin >> cu_name >> cu_score;
            if(!std::cin)
                throw(std::runtime_error("enter a number."));

            current.name = cu_name;
            current.value = cu_score;

            if (repeat(current, v) == true) //if the name is a repeat, exit the loop
            {
                std::cout << "Error: repeated name: " << current.name << ".\n";
                break;
            }
        }
        
        //as the user for scores and output all names with these scores
        int q {0}; //q is an int now
        bool found {false};
        
        std::cout << "Now enter a score to get the people who have it or press CTRL-D to exit the program:\n";
        while(std::cin >> q)
        {
            if(!std::cin)
                throw(std::runtime_error("enter a number."));
            
            for(int i = 0; i < v.size(); ++i) //loop it
                if (q == v[i].value)
                {
                    std::cout << v[i].name << " has a score of " << v[i].value << ".\n";
                    found = true;
                }
            if (found == false)
                std::cout << "Score not found.\n";
            
            found = false;
        }

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    catch(...)
    {
        std::cerr << "Error: unknown error.\n";
        return 2;
    }
    
}