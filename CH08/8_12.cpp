/*
---
E8.12
[12] Change the representation of a Date to be the number of days since
January 1, 1970 (known as day 0), represented as a long int (that is, an int
that can hold much larger integers than plain int), and re-implement the
Date member functions from §8.4.2. Be sure to reject dates outside the
range we can represent that way (feel free to reject days before day 0,
i.e., no negative days).
---

member functions to implement:
- add_day(int)
- Date(int, int, int)
- << operator
- i dont find any more in 8.4.2...

UNFINISHED

Jan 2025
@jmerort
*/


#include <iostream>
#include <vector>

using std::cout;


//----------------------------------------------------------------------



class Date 
{
    public:
        Date():d{0}{};
        Date(int y, int m, int d);

        int year(), //return year number
            month(), //return month number
            day(); //return day number

        void add_day(int dd) {d += dd;};

        friend std::ostream& operator << (std::ostream&, Date);

        struct Invalid {};

    private:
        long int d;

        bool is_valid();
};



Date::Date (int yy, int mm, int dd)
{
    d = (yy - 1970) * 365 + mm * 12 + dd;
}



bool Date::is_valid()
//check for invalid dates
{
    return d < 0;
}



int year()
{

}



int month()
{

}



int day()
{
    
}



std::ostream& operator << (std::ostream& os, Date dt)
{
    int yy year();
    int mm month();
    int dd day();
	os << yy << '-' << mm << '-' << dd;

	return os;
}


//----------------------------------------------------------------------



int main()
{
	try
	{
        Date today {2000, 1, 23};
        cout << today << '\n';

		return 0;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
    catch(Date::Invalid)
	{
		std::cerr << "Error: Invalid date.\n";
		return 2;
	}
	catch(...)
	{
		std::cerr << "Unknown error.\n";
		return 3;
	}

}