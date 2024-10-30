/* 
E3.7
[7] Make a vector holding the ten string values "zero", "one", . . . "nine". Use
that in a program that converts a digit to its corresponding spelled-out
value; e.g., the input 7 gives the output seven. Have the same program,
using the same input loop, convert spelled-out numbers into their digit
form; e.g., the input seven gives the output 7.



¿Should I have written one function instead of two? Following the guidelines of this book, one should create a
function for every logically distinct operation. I think converting a word to a number and a number to a word 
are two logically distinct operations, so I have chosen to create two functions, even though they are very
similar.

29 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>

std::string spell (std::string n) 
{
    //Takes the string of a digit and gives back its spelling
    //Post condition: To return a value, the input must be equal to one of the elements of the vector "cifras"

    std::vector <std::string> cifras = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::vector <std::string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i = 0; i < cifras.size(); i++)
    {
        if (cifras[i] == n)
            return digits[i];
    }

    return "Error, number not found.\n";
}

std::string number (std::string d)
{
    //Takes the string of a spelled digit and gives back the number (as a string)
    //Post condition: To return a value, the input must be equal to one of the elements of the vector "digits"

    std::vector <std::string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector <std::string> cifras = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (int i = 0; i < digits.size(); i++)
    {
        if (digits[i] == d)
            return cifras[i];
    }

    return "Error, number not found.\n";
}

int main()
{
    std::string input = " ";
    std::cout << "Enter a digit as a number or spelled out (e.g.: \"four\", \"6\"):\n";
    std::cin >> input;

    if(input.length()>1) //check if the input is a word or a number (which is supposed to be only 1 digit)
        std::cout << number(input) << "\n";
    else
        std::cout << spell(input) << "\n";


    return 0;
}