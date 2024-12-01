/*
---
E6.11-a
[11] Revisit two programs you wrote for the exercises in §3 or Chapter 4.
Clean up that code according to the rules outlined in this chapter. See if
you find any bugs in the process.
---

I will improve program 3.9, in which you are supposed to compute the number of squares of the chess board
that are necessary to get a given amount of grains, according to the rules of the famous tale.

While improving this program (adding error checking, comments and separating operations into functions) I 
noticed a big logic error I made because I didn't think carefully about the problem. On the original excercise, 
I had only computed the grains on the furthest square, instead of summing all the suqares leading up to and 
including it. The original program also didn't give useful information when the wrong iputs were entered.

After the changes, the size of the program has increased considerable (and this is an extremely simple program,)
but now it's way more robust and easier to modify.


Dec 2024
@jmerort
*/



#include <iostream>


int max_squares = 64; //maximim size of the board, in a normal chess board it's 64



bool check_whole (double num)
{
	// check if a double number is a whole or has a non-zero decimal part
	long n = num;
	double d = n;
	if (num == d) return true; //if all the info has been kept through the conversion, it's a whole number
	else return false;
}



//----------------------------------------------------------



long get_goal()
{
	// get the desired number of squares and make sure it is an integer (stored in a double to have the proper size)
	double n = 0; // long automatically narrows, so I read into a double to make sure
   	std::cin >> n;
	if(!std::cin) throw (std::runtime_error("Wrong input, enter an integer."));
	if(!check_whole(n)) throw (std::runtime_error("Enter a whole number."));
	long goal = n;
	return goal;
}



//-----------------------------------------------------------



int compute_squares(long goal)
{
	// compute the number of chess squares required to get "goal" grains of rice
	long current = 1,
	     sum = 1;
	int squares = 1;

    	while(sum < goal)
    	{
		if (squares > max_squares) throw (std::runtime_error("The board is too small for that amount of grains."));
       		++squares;
       		current *= 2;
		sum = sum + current;
	}

	return squares;
}



//----------------------------------------------------------



int main()
{
	try
	{
		std::cout << "How many grains do you (at least) want?\n";
		
		long goal = get_goal(),
		     squares = compute_squares(goal);
        
		std::cout << "To get at least " << goal << " grains you need to traverse " << squares << " squares.\n";

    		return 0;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
	catch(...)
	{
		std::cerr << "Unknown error.\n";
		return 2;	
	}
}
