/*
E3.8
[8] Modify the “mini calculator” from exercise 6 to accept (just) single-digit
numbers written as either digits or spelled out.


I created a function out of the 2 from the past excercise, which gives back an integer value in response to a string
digit, spelled out or numeric. Error detection could be added for the cases where the user types something else.

29 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>


int num (std::string d)
{
    //Takes the string of a digit (spelled or as a number) and gives back the number as an int
    //Post condition: To return a (sensible) value, the input must be equal to one of the elements of the vector "digits"

    std::vector <std::string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; //possible inputs
    std::vector <std::string> cifras = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    std::vector <int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //values to output

    for (int i = 0; i < digits.size(); i++)
    {
        if (digits[i] == d || cifras[i] == d)
            return nums[i];
    }

    return -1;
}


int main()
{
    std::string operand1 = " ", //computation inputs
                operand2 = " ";
    char op = ' '; //operator
    int a = 0,
        b = 0;

    std::cout << "-CALCULATOR-\nEnter two integer numbers from 0 to 9 followed by the operation symbol (e.g.: \"4 six /\").\nAvailable operations:\n"
              << "+\n-\n*\n/\n%\n";
    std::cin >> operand1 >> operand2 >> op;

    //translate the operand strings to integers
    a = num(operand1); 
    b = num(operand2);

    switch (op)
    {
        case '+':
            std::cout << a << " " << op << " " << b << " = " << a + b << "\n";
            break;
        case '-':
            std::cout << a << " " << op << " " << b << " = " << a - b << "\n";
            break;
        case '*':
            std::cout << a << " " << op << " " << b << " = " << a * b << "\n";
            break;
        case '/':
            std::cout << a << " " << op << " " << b << " = " << a / b << "\n";
            break;
        case '%':
            std::cout << a << " " << op << " " << b << " = " << a % b << "\n";
            break;
        default:
            std::cout << "I don't know the operation " << op << " (make sure the syntax is correct.)\n";
            break;
    }

    return 0;
}