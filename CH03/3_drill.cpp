/*
UNIT 3 - DRILL
Go through this drill step by step. Do not try to speed up by skipping steps.
Test each step by entering at least three pairs of values – more values would
be better.
[1] Write a program that consists of a while-loop that (each time around
the loop) reads in two ints and then prints them. Exit the program
when a terminating '|' is entered.
[2] Change the program to write out the smaller value is: followed by the
smaller of the numbers and the larger value is: followed by the larger
value.
[3] Augment the program so that it writes the line the numbers are equal
(only) if they are equal.
[4] Change the program so that it uses doubles instead of ints.
[5] Change the program so that it writes out the numbers are almost equal
after writing out which is the larger and the smaller if the two
numbers differ by less than 1.0/100.
[6] Now change the body of the loop so that it reads just one double each
time around. Define two variables to keep track of which is the
smallest and which is the largest value you have seen so far. Each
time through the loop write out the value entered. If it’s the smallest
so far, write the smallest so far after the number. If it is the largest so
far, write the largest so far after the number.
[7] Add a unit to each double entered; that is, enter values such as 10cm,
2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft. Assume
conversion factors 1m==100cm, 1in==2.54cm, 1ft==12in. Read the unit
indicator into a string. You may consider 12 m (with a space between
the number and the unit) equivalent to 12m (without a space).
[8] Reject values without units or with “illegal” representations of units,
such as y, yard, meter, km, and gallons.
[9] Keep track of the sum of values entered (as well as the smallest and
the largest) and the number of values entered. When the loop ends,
print the smallest, the largest, the number of values, and the sum of
values. Note that to keep the sum, you have to decide on a unit to use
for that sum; use meters.
[10] Keep all the values entered (converted into meters) in a vector. At the
end, write out those values.
[11] Before writing out the values from the vector, sort them (that’ll make
them come out in increasing order).

30 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    double greatest = -99999, //to correctly initialize both values
           smallest = 99999,
           n = 0,
           factor = 0,
           sum = 0;
    std::string unit = " ";
    std::vector <double> measures = {};
    
    std::cout << "Enter integer numbers or enter \"|\" to finish the pgoram: \n";

    while (std::cin >> n) 
    {
        std::cin >> unit;
        std::cout << n << " " << unit << "\n";

        if (unit == "cm") // conversion factors
            factor = 0.01;
        else if (unit == "m")
            factor = 1.0;
        else if (unit == "in")
            factor = 0.0254;
        else if (unit == "ft")
            factor = 0.3048;
        else 
        {
            std::cout << "I don't know the unit " << unit << ". Please enter a valid unit.\n";
            break;
        }

        if (n * factor > greatest)
        {
            greatest = n * factor;
            std::cout << "The greatest so far.\n";
        }
        if (n * factor < smallest)
        {
            smallest = n * factor;
            std::cout << "The smallest so far.\n";
        }

        sum += n * factor; 
        measures.push_back(n * factor); 
    }

    std:: cout << "The greatest value has been " << greatest << " meters and the smallest " << smallest << " meters. \n"
               << "The total sum is " << sum << " meters.\nHistorical measures (in meters):\n";

    std::sort(measures.begin(), measures.end());
    for (int i = 0; i < measures.size(); i++) 
        std::cout << measures[i] << " m \t";

    std::cout << "\n--END--.\n";

    return 0;
}