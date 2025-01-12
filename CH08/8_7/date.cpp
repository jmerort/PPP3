#include "date.h"
#include <iostream>
#include <vector>



//----------------------------------------------------------------------



std::vector<std::string> month_tbl = 
{
	"Not a month", "January", "February", "March", "April", "May",
	"June", "July", "August", "September", "October", "November", "December" 
};//month names



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



bool is_year(Year ye)
{
	return (ye.y >= -1000 && ye.y < 3000); //I accept years since 1000 b.c.
}



Year operator++(Year& yy)
// prefix increment operator
{
	yy.y = (yy.y==3000) ? 2000 : yy.y + 1;
	return yy;
}



//----------------------------------------------------------------------



Date::Date (int year, Month month, int day)
: y{year}, m{month}, d{day}
{
	if(!is_valid())
		throw Invalid {};
}



int Date::day() const
{
	return d;
}



Month Date::month() const
{
	return m;
}



Year Date::year() const
{
	return y;
}



bool Date::is_valid()
{
	bool valid{true};
	
	if (!is_month(m) || !is_year(y)) valid = false; //check if month or year does not exist
	else
		switch (m)
		{
			case Month::apr: case Month::jun: case Month::sep: case Month::nov: //months with 30 days
				if (d < 0 || d > 30) valid = false; 
				break;
						
			case Month::jan: case Month::mar: case Month::may: case Month::jul: case Month::aug: case Month::oct: case 	Month::dec: //months with 31 days
				if (d < 0 || d > 31) valid = false; 
				break;
				
			case Month::feb: //february (with always 28 days)
				if (d < 0 || d > 28) valid = false; 
				break;
		}
		
	return valid;
}



void Date::add_day(int n)
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
				
			case Month::feb: //february (with always 28 days)
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



void Date::add_month(int n)
{
	for (int i {0}; i < n; i++)
	{
		++m;
		if (m == Month::jan) ++y; //if the month has looped back, increase year
	}
}



void Date::add_year(int n)
{
	for (int i {0}; i < n; i++)
		++y;
}



std::ostream& operator << (std::ostream& os, Date dt)
{
	os << dt.day() << '-' << dt.month() << '-' << dt.year().y;
	return os;
}
