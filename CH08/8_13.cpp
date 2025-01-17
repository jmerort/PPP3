/*
---
8.13
[13] Design and implement a rational number class, Rational. A rational
number has two parts: a numerator and a denominator, for example, 5/6
(five-sixths, also known as approximately .83333). Look up the
definition if you need to. Provide assignment, addition, subtraction,
multiplication, division, and equality operators. Also, provide a
conversion to double. Why would people want to use a Rational class?
---

Jan 2024
@jmerort
*/


#include <iostream>


//---------------------------------------------------------------------------



class Rational 
{
    public:
        Rational (int nn, int dd):n{nn},d{dd}{};

        int num(){return n;};
        int den(){return d;};

        friend bool std::operator== (Rational, Rational);

    private:
        int n,
            d;
};



bool std::operator== (Rational a, Rational b)
{ 
    return a.num()/a.den() == b.num()/b.den();
}



//---------------------------------------------------------------------------



int main()
{
	try
	{
        Rational a {1,2},
                 b {2,4};
        
        std::cout << std::operator==(a,b);

		return 0;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	catch(...)
	{
		std::cerr << "Unknown error.\n";
		return 2;
	}

}