/*
E2.11
[11] Write a program that prompts the user to enter some number of pennies
(1-cent coins), nickels (5-cent coins), dimes (10-cent coins), quarters
(25-cent coins), half dollars (50-cent coins), and one-dollar coins (100-
cent coins). Query the user separately for the number of each size coin,
e.g., “How many pennies do you have?” Then your program should
print out something like this:

You have 23 pennies.
You have 17 nickels.
You have 14 dimes.
You have 7 quarters.
You have 3 half dollars.
The value of all of your coins is 573 cents.

Make some improvements: if only one of a coin is reported, make the
output grammatically correct, e.g., 14 dimes and 1 dime (not 1 dimes).
Also, report the sum in dollars and cents, i.e., .73 instead of 573 cents.

29 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    int pennies = 0,
        nickels = 0,
        dimes = 0,
        quarters = 0,
        half_dollars = 0;

// ask for the amount of each coin
    std::cout << "How many pennies have you got?\n"; 
    std::cin >> pennies;

    std::cout <<"How many nickels have you got?\n";
    std::cin >> nickels;

    std::cout <<"How many dimes have you got?\n";
    std::cin >> dimes;

    std::cout <<"How many quarters have you got?\n";
    std::cin >> quarters;

    std::cout <<"How many half-dollars have you got?\n";
    std::cin >> half_dollars;

//output the coins and sum them into dollars
    if(pennies != 1)
        std::cout << "You've got " << pennies << " pennies.\n";
    else
        std::cout << "You've got one penny.\n";

    if(nickels != 1)
        std::cout << "You've got " << nickels << " nickels.\n";
    else
        std::cout << "You've got one nickel.\n";

    if(dimes != 1)
        std::cout << "You've got " << dimes << " dimes.\n";
    else
        std::cout << "You've got one dime.\n";

    if(quarters != 1)
        std::cout << "You've got " << quarters << " quarters.\n";
    else
        std::cout << "You've got one quarter.\n";

    if(half_dollars != 1)
        std::cout << "You've got " << half_dollars << " half-dollars.\n";
    else
        std::cout << "You've got one half-dollar.\n";
    
    std::cout << "You've got $" << double(pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollars)/100 << " in total.\n";


    return 0;
}