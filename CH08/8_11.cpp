/*
---
E8.11
[11] Design and implement a set of useful helper functions for the Date class
with functions such as next_workday() (assume that any day that is not a
Saturday or a Sunday is a workday) and week_of_year() (assume that
week 1 is the week with January 1 in it and that the first day of a week is
a Sunday).
---

[I think this works, just clean it up a little bit.]

Jan 2025
@jmerort
*/


#include <iostream>
#include <vector>

using std::cout;

//----------------------------------------------------------------------



enum class Month 
{
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};



std::vector<std::string> month_tbl = 
{
	"Not a month", "January", "February", "March", "April", "May",
	"June", "July", "August", "September", "October", "November", "December" 
};



int to_int(Month m)
//return month number
{
	return static_cast<int>(m);
}



Month operator++(Month& m)
// prefix increment operator
{
	m = (m==Month::dec) ? Month::jan : Month{to_int(m)+1};
	return m;
}



std::ostream& operator<<(std::ostream& os, Month m)
//print month name
{
return os << month_tbl[to_int(m)];
}



bool is_month(Month m)
{
	return (to_int(m) > 0 && to_int(m) <= 12);
}



//----------------------------------------------------------------------



struct Year 
{
	int y;
};



bool is_year(Year ye)
{
	return (ye.y >= 2000 && ye.y < 3000); //I accept years of this millenium
}



Year operator++(Year& yy)
// prefix increment operator
{
	yy.y = (yy.y==3000) ? 2000 : yy.y + 1;
	return yy;
}



bool leapyear (Year yy)
{
	return yy.y % 4 == 0; //there might be an additional rule for this, but I dont remember :/
}



//----------------------------------------------------------------------



enum class Weekday
{
	sun=0, mon=1, tue, wed, thu, fri, sat,
};



int to_int(Weekday w)
//return weekday number (sunday = 0, monday = 1...)
{
	return static_cast<int>(w);
}


std::vector<std::string> weekday_tbl = 
//weekday names
{
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
	"Friday", "Saturday" 
};



std::ostream& operator<<(std::ostream& os, Weekday wd)
//print weekday name
{
return os << weekday_tbl[to_int(wd)];
}



//----------------------------------------------------------------------



class Date 
{
	public:
		Date (int year, Month month, int day);
		Date () :y{2000}, m{Month::jan}, d{1} {} //default constructor
			
		int day() const {return d;};
		Month month() const {return m;};
		Year year() const {return y;};
		
		void add_year(int n); //increase date by n years
		void add_month(int n); // increase date by n months
		void add_day(int n); //increase date by n days

		bool is_valid(); //check if date is valid
		class Invalid{}; 

        Weekday get_weekday(); //get day of the week
        int get_week_n(); //get week number (assuming 1st on jan of that year belongs to week 1)
		
        Date next_workday(); //get next workday (monday to friday)

		friend std::ostream& operator << (std::ostream& os, Date d); //operator to print dates
		
	private:
		Year y;
		Month m;
		int d;
};



Date::Date (int year, Month month, int day)
: y{year}, m{month}, d{day}
{
	if(!is_valid())
		throw Invalid {};
}



void Date::add_year(int n)
//add n years to Date
{
	for (int i {0}; i < n; i++)
		++y;
}



void Date::add_month(int n)
//add n months to Date
{
	for (int i {0}; i < n; i++)
	{
		++m;
		if (m == Month::jan) ++y; //if the month has looped back, increase year
	}
}



void Date::add_day(int n)
//add n days to Date
{
	for (int i {0}; i < n; i++)
	{
		switch (m)
		{
			case Month::apr: case Month::jun: case Month::sep: case Month::nov: //months with 30 days
				if (d < 30)
					d++;
				else
				{ 
					d = 1;
					++m;
				}	
				break;
						
			case Month::jan: case Month::mar: case Month::may: case Month::jul: case Month::aug: case Month::oct: case 	Month::dec: //months with 31 days
				if (d < 31)
					d ++;
				else
				{ 
					d = 1;
					++m;
				}	
				break;
				
			case Month::feb:
				if (leapyear(y)) //if year is a leapyear
					if (d < 29)
						d++;
					else 
					{ 
						d = 1;
						++m;
					}
				else 	//regular frebruary
					if (d < 28) 
						d++;
					else
					{ 
						d = 1;
						++m;
					}
				break;
		}
		if (d == 1 && m == Month::jan) ++y; //if it loops back to jan 1st, increase year
	}
}



bool Date::is_valid()
//check if a date is valid (enough days in the month and so on)
{
	bool valid{true};
	
	if (!is_month(m) || !is_year(y)) valid = false; //check if month or year does not exist
	else //check if day number makes sense in that month
		switch (m)
		{
			case Month::apr: case Month::jun: case Month::sep: case Month::nov: //months with 30 days
				if (d < 0 || d > 30) valid = false; 
				break;
						
			case Month::jan: case Month::mar: case Month::may: case Month::jul: case Month::aug: case Month::oct: case 	Month::dec: //months with 31 days
				if (d < 0 || d > 31) valid = false; 
				break;
				
			case Month::feb: //february
				if (leapyear(y))
				{
					if (d < 0 || d > 29) valid = false; 
					break;
				}
				else
				{
					if (d < 0 || d > 28) valid = false; 
					break;
				}
		}
		
	return valid;
}



Weekday Date::get_weekday()
{
    Date begin {2000, Month::jan, 1}; //year 200 started on saturday
    //get day difference between date and begin
    int i{0};
    while (y.y != begin.y.y || m != begin.m || d != begin.d)
    {
        begin.add_day(1);
        i++;
    }
    Weekday wd {(i + 6)%7};
    return wd;
}



int Date::get_week_n()
{
    Date first {y.y, Month::jan, 1}; //first day of current year
    int week_n {1};
    while (first.m != m || first.d != d) 
    {
        first.add_day(1);
        if (first.get_weekday() == Weekday::sun) week_n++;
    }

    return week_n;
}



Date Date::next_workday()
{
    Date dd {y.y, m, d};
    while (to_int(dd.get_weekday()) == 0 || to_int(dd.get_weekday()) == 6) //while date is sunday or saturday, increase days
    {
        dd.add_day(1);
    } 
    return dd;
}



std::ostream& operator << (std::ostream& os, Date dt)
{
	os << dt.day() << '-' << dt.month() << '-' << dt.year().y;
	return os;
}



//----------------------------------------------------------------------



int main()
{
	try
	{
		Date today {2025, Month::jan, 18}, //saturday
             next {today.next_workday()},
             workday {2025, Month::jan, 15}; //wednesday

        cout << "Today is " << today.get_weekday() << ' ' << today << '\n';
        cout << "The next weekday will be on " << next.get_weekday() << ' ' << next << '\n';
		
        cout << "The next weekday from " << workday <<  " will be on " << workday.next_workday() << '\n';

        cout << today << " belongs to the week " << today.get_week_n() << " of the year.\n";

		return 0;
	}
	catch(std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	catch(Date::Invalid)
	{
		std::cerr << "Invalid date.\n";
		return 2;
	}
	catch(...)
	{
		std::cerr << "Unknown error.\n";
		return 3;
	}
}
