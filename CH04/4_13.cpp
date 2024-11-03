/*
---
E4.13
[13] The program is a bit tedious because the answer is hard-coded into the
program. Make a version where the user can play repeatedly (without
stopping and restarting the program) and each game has a new set of
four digits. You can get four random digits by calling the random
number generator random_int(0,9) from PPP_support (and §4.7.5) four
times. You will note that if you run that program repeatedly, it will pick
the same sequence of four digits each time you start the program. To
avoid that, ask the user to enter a number (any number) and call seed(n),
also from PPP_support, where n is the number the user entered before
calling random_int(0,10). Such an n is called a seed, and different seeds
give different sequences of random numbers.
---

Sometimes the number of cows might be misleading, but to fix that would require
a way more complex solution.

2 Nov 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <random>
#include <time.h>

int check_bulls (std::vector <int> v1, std::vector <int> v2)
{
    //returns the number of positions where each of the vectors hold the same number
    //precondition: both vectors have the same size
    int bulls {0};

    for (int i = 0; i < v1.size(); ++i)
    {
        if (v1[i] == v2[i])
            ++bulls;
    }

    return bulls;
}

int check_cows (std::vector <int> v1, std::vector <int> v2)
{
    //returns the number of instances where each of the vectors hold the same number but in different positions
    //precondition: both vectors have the same size
    int cows {0};

    for (int i = 0; i < v1.size(); ++i)
    {
        for (int u = 0; u < v1.size(); ++u)
        {
            if (v1[i] == v2 [u] and i != u)
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
            cows {0},
            n {0},
            s {0}; 
        
        std::vector <int> number {},
                        guess {};


        std::cout << "-BULLS AND COWS-\n";
        while (true)
        {
            std::cout << "New game begins.\nEnter a seed number (any random number): ";
            std::cin >> s;
            if(!std::cin)
                throw(std::runtime_error("enter an integer."));

            std::default_random_engine engine;
            engine.seed(s);
            std::uniform_int_distribution <int> dist(0,9);

            //fill the number vector with random numbers from 0 to 9
            for(int i = 0; i < 4; ++i)
                number.push_back(dist(engine));

            while(bulls < 4)
            {
                std::cout << "Guess a vector of 4 numbers from 0 to 9 or press CTRL-Z to end the game (e.g.: \"3 5 2 6\"):\n";

                //fill the guess vector
                for (int u = 0; u < number.size(); ++u)
                {
                    std::cin >> n;
                    guess.push_back(n);

                    if(!std::cin)
                        throw(std::runtime_error("enter a series of 4 integers."));
                }

                //check bulls
                bulls = check_bulls(number, guess);

                //check cows
                cows = check_cows(number, guess);

                //output
                std::cout << "Bulls: " << bulls << "\nCows: " << cows << "\n";

                guess.clear();
            }
            std::cout << "You won! :-D\n";
            bulls = 0;
            cows = 0;
            number.clear();
        }

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