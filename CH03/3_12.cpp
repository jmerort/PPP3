/*
E3.12
[12] Create a program to find all the prime numbers between 1 and 100. One
way to do this is to write a function that will check if a number is prime
(i.e., see if the number can be divided by a prime number smaller than
itself) using a vector of primes in order (so that if the vector is called
primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.). Then write a loop
that goes from 1 to 100, checks each number to see if it is a prime, and
stores each prime found in a vector. Write another loop that lists the
primes you found. You might check your result by comparing your
vector of prime numbers with primes. Consider 2 the first prime.

30 Oct 2024
@jmerort
*/

#include <iostream>
#include <vector>

int main()
{
    std::vector <int> primes = {2};
    bool prim = true; 

    for (int i = 3; i < 100; ++i)
    {
        for (int n = 0; n < primes.size(); ++n)
        {
            if (i % primes[n] == 0)
                prim = false;
        }
        if (prim == true)
            primes.push_back(i);
        
        prim = true;
    }

    std::cout << "List of primes between 2 and 100:\n";
    for (int u = 0; u < primes.size(); ++u)
        std::cout << primes[u] << "\n";

   
    return 0;
}