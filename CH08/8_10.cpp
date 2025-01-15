/*
---
E8.10
[10] Implement leapyear(int).
---

Jan 2025
@jmerort
*/


#include <iostream>
#include <vector>



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



class Date 
{
	public:
		Date (int year, Month month, int day);
		Date () :y{2000}, m{Month::jan}, d{1} {} //default constructor
			
		int day() const;
		Month month() const;
		Year year() const;
		
		void add_day(int n); //increase date by n days
		void add_month(int n); // increase date by n months
		void add_year(int n); //increase date by n years
		
		bool is_valid(); //check if date is valid
		class Invalid{}; 
		
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
				
			case Month::feb: //february
				if (leapyear(y))
					if (d < 29)
						d++;
					else 
					{ 
						d = 1;
						++m;
					}
				else 
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



//----------------------------------------------------------------------



int main()
{
	try
	{
		Date today{2025, Month::feb, 28};
		std::cout << "Today is " << today << ".\n";
		today.add_day(1); //non leap day
		std::cout << "The next day will be " << today << ".\n";

		Date year_ago{2024, Month::feb, 28}; //leap year
		std::cout << "A year ago was " << year_ago << ".\n";
		year_ago.add_day(1);
		std::cout << "The next day was " << year_ago << ".\n"; //leap day
		year_ago.add_day(1);
		std::cout << "And the next was " << year_ago << ".\n";
		
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
