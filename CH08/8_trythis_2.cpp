/*
---
TT7.2
Try This
Write, compile, and run a small example using ++ and << for Month.
---

Dec 2024
@jmerort
*/

#include <iostream>
#include <vector>


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
{
return os << month_tbl[to_int(m)];
}


int main()
{
	Month enero{1};
	std::cout << enero << '\n';
		
	Month current{1};
	++current;
	++current;
	std::cout << current << '\n';
	
	return 0;
}
