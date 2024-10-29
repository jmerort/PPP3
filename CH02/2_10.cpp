/*
E2.10
[10] Write a program that takes an operation followed by two operands and
outputs the result. For example:
+ 100 3.14
* 45
Read the operation into a string called operation and use an if-statement
to figure out which operation the user wants, for example, if
(operation=="+"). Read the operands into variables of type double.
Implement this for operations called +, −, *, /, plus, minus, mul, and div
with their obvious meanings.

29 Oct 2024
@jmerort
*/

#include <iostream>

int main()
{
    std::string op = "";
    double operand_1 = 0,
           operand_2 = 0;

    std::cout << "Enter an operator followed by two numeric operands (e.g.: \"+ 1 3\")\n"
              << "Available operations:\n+\n-\n*\n/\nplus\nminus\nmul\ndiv\n";
    std::cin >> op >> operand_1 >> operand_2;


    if(op == "+" or op == "plus")   //I'm guessing you're supposed to treat "plus" the same as "+" and so forth
        std::cout << operand_1 << " + " << operand_2 << " = " << operand_1 + operand_2 <<"\n";

    else if(op == "-" or op == "minus")
        std::cout << operand_1 << " - " << operand_2 << " = " << operand_1 - operand_2 <<"\n";

    else if(op == "*" or op == "mul")
        std::cout << operand_1 << " * " << operand_2 << " = " << operand_1 * operand_2 <<"\n";   

    else if(op == "/" or op == "div")
        std::cout << operand_1 << " / " << operand_2 << " = " << operand_1 / operand_2 <<"\n";  

    else
        std::cout << "Use a valid operation (check the syntax) >_<\n";

    return 0;
}