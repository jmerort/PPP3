#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>



//----------------------------------------------------------------------



enum class Month 
{
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


int to_int(Month m);
//return month number

Month operator++(Month& m);
// prefix increment operator

std::ostream& operator<<(std::ostream& os, Month m);
//print month name

bool is_month(Month m);



//----------------------------------------------------------------------



struct Year 
{
	int y;
};


bool is_year(Year ye);
Year operator++(Year& yy);



//----------------------------------------------------------------------



class Date 
{
	public:
		Date (int, Month, int);
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

#endif
