/*
---
E5.7
[7] Write a program that reads digits and composes them into integers. For
example, 123 is read as the characters 1, 2, and 3. The program should
output 123 is 1 hundred and 2 tens and 3 ones. The number should be output
as an int value. Handle numbers with one, two, three, or four digits.
Hint: To get the integer value 5 from the character '5' subtract '0', that is,
'5'−'0'==5.
---


9 Nov 2024
@jmerort
*/

#include <iostream>
#include <vector>


class Digit_int {

    private:
        std::vector <char> digits {};
        std::vector <int> numbers {};

    public:
        void put_val (char);
        void print_val();
};



//----------------------------------------------------------------------------------------



void Digit_int::put_val(char c)
{
    //add a digit char to the vector, convert it to an int and add it to hte int vector
    if(c < '0' or c > '9')
        throw(std::runtime_error("Use only numbers from 0 to 9."));

    digits.push_back(c);
    numbers.push_back(c-'0');
}

void Digit_int::print_val()
{
    //print the digit vector and the int vector, separated by units
    for (int i = 0; i < digits.size(); i++)
    {
        std::cout << digits[i];
    }

    std::cout << " is ";

    switch(numbers.size())
    {
        case 1:
            std::cout << numbers[0] << " ones.\n"; 
            break;
        case 2:
            std::cout << numbers[0] << " tens and " << numbers[1] << " ones.\n";
            break;
        case 3:
            std::cout << numbers[0] << " hundred, " << numbers[1] << " tens and " << numbers[2] << " ones.\n"; 
            break;
        case 4:
            std::cout << numbers[0] << " thousand, " << numbers[1] << " hundred, " << numbers [2] << " tens and " << numbers [3] << " ones.\n";
            break; 
        default:
            std::cout << "too long, max number is 9999.\n";
            break;
    }
}



//----------------------------------------------------------------------------------------



int main()
{
    try
    {
        char n;
        Digit_int serie;

        std::cout << "Enter a number from 0 to 9999 followed by | (e.g.: \"645|\").\n";
        while(std::cin >> n)
        {
            if(n == '|') //to end the input
                break;

            serie.put_val(n);
        }
        
        serie.print_val();

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        std::cerr << "Error: unknown error.\n";
        return 2;
    } 
}