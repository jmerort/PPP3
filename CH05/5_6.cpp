/*
---
E5.6
[6] Redo the “Bulls and Cows” game from exercise 12 in Chapter 4 to use
four letters rather than four digits.
---

8 Nov 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <random>


//class created to check that the letters are between a and z
class Word 
{
    public:
        std::vector <char> letters{'*', '*', '*', '*'};

        Word()
        {
            for(int i = 0; i < letters.size(); i++)
            {
                    letters[i] = '*';
            }
        } // make a

        void assign (std::vector<char> l)
        {
            for(int i = 0; i < letters.size(); i++)
            {
                if(l[i] >= 'a' and l[i] <= 'z')
                    letters[i] = l[i];
                else 
                    throw(std::runtime_error("use only lower case letters."));
            }
        }
};


int check_bulls (Word v1, Word v2)
{
    //returns the number of positions where each of the vectors hold the same number
    //precondition: both vectors have the same size
    int bulls {0};

    for (int i = 0; i < v1.letters.size(); ++i)
    {
        if (v1.letters[i] == v2.letters[i])
            ++bulls;
    }

    return bulls;
}

int check_cows (Word v1, Word v2)
{
    //returns the number of instances where each of the vectors hold the same number but in different positions
    //precondition: both vectors have the same size
    int cows {0};

    for (int i = 0; i < v1.letters.size(); ++i)
    {
        for (int u = 0; u < v1.letters.size(); ++u)
        {
            if (v1.letters[i] == v2.letters[u] and i != u)
            {
                ++cows;
                break; //so that one cow only gets counted once
            }       
        }
    }

    return cows;
}

int main()
{
    try
    {
        int bulls {0},
            cows {0};
        
        char n {' '};

        std::vector <char> v1 {}; //vector created to update the guess 
        
        Word solution, guess;
        solution.assign(std::vector <char> {'f', 'i', 'n', 'e'}); //hardcoded solution
        
        
        std::cout << "-BULLS AND COWS-\n";
        while(bulls < 4)
        {
            std::cout << "Guess a 4 letter word in lowercase or press CTRL-Z to end the game (e.g.: \"tree\"):\n";
            //fill the guess vector
            for (int u = 0; u < solution.letters.size(); ++u)
            {
                std::cin >> n;
                if(!std::cin)
                    throw(std::runtime_error("wrong input, enter a word."));
                v1.push_back(n);
            }
            guess.assign(v1);
            v1.clear();

            //check bulls
            bulls = check_bulls(solution, guess);

            //check cows
            cows = check_cows(solution, guess);

            //output
            std::cout << "Bulls: " << bulls << "\nCows: " << cows << "\n";
        }

        if(bulls == 4)
            std::cout << "You won! :-D\n";
        return 0; 
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Error: unknown error. \n";
        return 2;
    }
}
