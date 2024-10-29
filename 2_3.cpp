/*
E2.3
[3] Write a program that doesn’t do anything, but declares a number of
variables with legal and illegal names (such as int double = 0;), so that
you can see how the compiler reacts.

28 Oct 2024 
@jmerort
*/

#include <iostream>

int main()
{
    //double " " = 10;   //remove the comments to see the error messages
    int oso = 2;
    //int int = 1;
    int _foo = 35;
    double main = 46;
    //bool #include = 46;

    return 0;
}