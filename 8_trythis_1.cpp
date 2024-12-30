/*
---
TT7.1
Try This
Get some example uses of a version of Date so far to run. For that, we need
an output operator for Date. There is one in PPP_support, but for now use

ostream& operator<<(ostream& os, Date d)
{
return os << d.year() << '/’ << d.month() << '/’ << d.day();
}
---
 
Dec 2024
@jmerort
*/

#include <iostream>

class Date 
{
    public:
    
	Date(int yy, int mm, int dd)
	:y{yy}, m{mm}, d{dd}
	{
	}
	
	void add_day(int n)
	{
	    d += n;
	}
	
	int year() {return y; }
	int month() { return m; }
	int day() {return d; }
	
	friend std::ostream& operator << (std::ostream& os, Date d);

    private:
	
	int y,
	    m,
	    d;
};


std::ostream& operator << (std::ostream& os, Date d)
{
	os << d.year() << '/' << d.month() << '/' << d.day();
	return os;
}

int main()
{
	Date today {2024, 12, 28};
	std::cout << today << '\n';
	return 0;
}
