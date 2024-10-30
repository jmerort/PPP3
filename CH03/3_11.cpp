/*
E3.11
[11] Write a program that plays the game “Rock, Paper, Scissors.” If you are
not familiar with the game do some research (e.g., on the Web using
Google). Research is a common task for programmers. Use a switch-
statement to solve this exercise. Also, the machine should give random
answers (i.e., select the next rock, paper, or scissors randomly). Real
randomness is too hard to provide just now, so just build a vector with a
sequence of values to be used as “the next value.” If you build the vector
into the program, it will always play the same game, so maybe you
should let the user enter some values. Try variations to make it less easy
for the user to guess which move the machine will make next.


I added 3 counters to check the statistics (w/l/d) at the end of the game.

30 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <time.h>

int main()
{
    int count = 0,
        init = 0,
        w = 0, //stats for wins, losses and draws
        l = 0,
        d = 0;
    std::string player = " ";
    //instead of adding randomness, I used a long vector with some positions (though it's always the same)
    std::vector <std::string> computer = {"rock", "rock", "paper", "scissors", "paper", "rock", "scissors", "scissors", "rock", "paper", "scissors","rock", "paper","paper"};

    std::cout << "--ROCK, PAPER, SCISSORS BEGINS!--\nFirst of all, tell me your day of birth (or, if you've played before, a random positive number)\n";
    std::cin >> init;
    count = init % computer.size(); //we start at a "random" place in the vector, given that the person inputs "random" numbers

    while(player != "|")
    {
        std::cout<< "The round begins, choose your attack or enter \"|\" to exit the game. (You can enter \"rock\", \"paper\" or \"scissors\")\n";
        std::cin >> player;
        
        //DRAW
        if (player == computer[count])
        {
            std::cout << computer[count] << ". It's a draw -_-\n";
            ++d;
        }
        //PLAYER WIN
        if ((player == "rock" and computer[count] == "scissors") or (player == "paper" and computer[count] == "rock") or (player == "scissors") and computer[count] == "paper")
        {
            std::cout << computer[count] << ". You win >:-(\n";
            ++w;
        }
        //PLAYER LOSS
        if ((player == "rock" and computer[count] == "paper") or (player == "paper" and computer[count] == "scissors") or (player == "scissors") and computer[count] == "rock")
        {
            std::cout << computer[count] << ". You lost! <:-D \n";
            ++l;
        }

        //INVALID MOVE
        if (player != "rock" && player != "paper" && player != "scissors" && player != "|")
            std::cout << "Please choose a valid option (check the spelling).\n";


        //RESET COUNTER?
        if (count < computer.size()-1)
            ++count;
        else
            count = 0;
    }

    std::cout << "--END OF THE GAME--\nStats:\nWins: " << w << "\t Losses: " << l << "\t Draws: " << d << "\n";

    return 0;
}
