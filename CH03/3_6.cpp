/*
E3.6
[6] Write a program that performs as a very simple calculator. Your
calculator should be able to handle the four basic math operations – add,
subtract, multiply, and divide – on two input values. Your program
should prompt the user to enter three arguments: two double values and a
character to represent an operation. If the entry arguments are 35.6, 24.1,
and '+', the program output should be The sum of 35.6 and 24.1 is 59.7. In
Chapter 5 and Chapter 6, we look at a much more sophisticated simple
calculator.

29 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    int a = 0, //computation inputs
        b = 0;
    char op = ' '; //operator

    std::cout << "-CALCULATOR-\nEnter two integer numbers followed by the operation symbol (e.g.: \"4 10 /\").\nAvailable operations:\n"
              << "+\n-\n*\n/\n%\n";
    std::cin >> a >> b >> op;

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