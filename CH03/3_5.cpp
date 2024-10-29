/* 
E3.5
[5] Write a program to play a numbers guessing game. The user thinks of a
number between 1 and 100 and your program asks questions to figure
out what the number is (e.g., “Is the number you are thinking of less
than 50?”). Your program should be able to identify the number after
asking no more than seven questions.

29 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    bool success = false;
    int n = 0,
        factor = 0,
        guess = 50,
        increment = 25,
        count = 1,
        answer = 0;

    std::cout << "Think of a number between 1 and 100 and I will surely guess it <(:-|). \n";


    while(count <= 7 and success == false)
    {
        std::cout << "¿Is the number you are thinking of bigger than " << guess << "?\n1 = Yes\n0 = No\n9 = It's exactly that number!\n";
        std::cin >> answer;
        switch(answer) 
        {
            case 1:
                factor = 1;
                break;
            case 0:
                factor = -1;
                break;
            case 9:
                success = true;
            default:
                factor = 0;
                break;
        }
        guess = guess + factor * increment;
        if (increment > 1)
            increment /= 2;   
        ++count; 
    }

    std::cout << "Your number is " << guess << " <(:-D).\n"; 

    return 0;
}

/*
The algorithm takes increasingly smaller steps in the direction of the answer. 
It probably could be improved (for instance, you could make it only have to ask binary questions),
but it does guess the number in 7 steps or less.
*/