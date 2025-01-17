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


To implement Date in this way, the difficulty lies in transforming a long int into a 
number of years, months, and days, given that all months don't have the same number
of days (even ignoring leap-years).

Jan 2025
@jmerort
*/


#include <iostream>
#include <vector>

using std::cout,
      std::vector;


//----------------------------------------------------------------------



class Date 
{
    public:
        Date():days{0}{};
        Date(int y, int m, int d);

        int year(), //return year number
            month(), //return month number
            day(); //return day number

        void add_day(int dd) {days += dd;};

        friend std::ostream& operator << (std::ostream&, Date);

        struct Invalid {};

    private:
        long int days;

        const vector <int> days_each_month {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        const int days_each_year {365},
                  year_zero {1970};

        bool is_valid();
};



Date::Date (int y, int m, int d)
{
    if (y < year_zero) throw Invalid {};

    long int year_days {0}; //days in x years
    int month_days {0}; //days in x months
    int day_days {d}; //days in x days

    year_days = (y - year_zero) * days_each_year; //get days of past years to sum (ignoring leap-years)

    for (int i {1}; i < m; i++) //get days of past months to sum
        month_days += days_each_month [i-1];

    days = year_days + month_days + day_days;
}



int Date::year()
//return number or years since day 0 (1 jan 1970)
{ 
    return (days - days % days_each_year) / days_each_year; //get only integer part of division
}



int Date::month()
//return  month number
{
    int d {days},
        m {1}; //month number

    d = days - year() * days_each_year;

    while (d > days_each_month[m-1])
    {
        d -= days_each_month[m-1];
        m++;
    }

    return m;
}



int Date::day()
{
    vector <int> month_days {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d {days},
        m {month()};

    d -= year() * days_each_year;

    for (int i {1}; i < m; i++)
        d -= month_days[i-1];

    return d;
}



std::ostream& operator << (std::ostream& os, Date dt)
{
	os << dt.year() + dt.year_zero << '-' << dt.month() << '-' << dt.day();
	return os;
}


//----------------------------------------------------------------------



int main()
{
	try
	{
        Date today {2025, 2, 13};

        cout << "Today is " << today << '\n';

        Date inv {1123, 2, 1}; //try to create invalid date

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