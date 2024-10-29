/*
E3.2
[2] Write a program that reads a string from input and then, for each
character read, prints out the character and its integer value on a line.

29 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    std::string word = " ";

    std::cout << "Enter a string (e.g.: \"Potato\"):\n";
    std::cin >> word;

    for (int i = 0; i < word.length(); ++i)
    {
        std::cout << word[i] << "\t" << int(word[i]) << "\n";
    }

    return 0;
}   
