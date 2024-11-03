/*
---
E4.12
[12] Implement a little guessing game called (for some obscure reason)
“Bulls and Cows.” The program has a vector of four different integers in
the range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to
discover those numbers by repeated guesses. Say the number to be
guessed is 1234 and the user guesses 1359; the response should be “1
bull and 1 cow” because the user got one digit (1) right and in the right
position (a bull) and one digit (3) right but in the wrong position (a
cow). The guessing continues until the user gets four bulls, that is, has
the four digits correct and in the correct order.
---

I should add a better way to end the game, I don't like CTRL-Z at all.

1 Nov 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <random>

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
            n {0};
        
        std::vector <int> number {1, 7, 4, 0}, //hardcoded solution
                        guess {}; 

        std::cout << "-BULLS AND COWS-\n";
        while(bulls < 4)
        {
            std::cout << "Guess a vector of 4 numbers from 0 to 9 or press CTRL-Z to end the game (e.g.: \"3 5 2 6\"):\n";

            //fill the guess vector
            for (int u = 0; u < number.size(); ++u)
            {
                std::cin >> n;
                if(!std::cin)
                    throw(std::runtime_error("wrong input, enter an integer."));
                guess.push_back(n);
            }

            //check bulls
            bulls = check_bulls(number, guess);

            //check cows
            cows = check_cows(number, guess);

            //output
            std::cout << "Bulls: " << bulls << "\nCows: " << cows << "\n";

            guess.clear();
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