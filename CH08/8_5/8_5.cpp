/*
---
E8.5
[5] This exercise and the next few require you to design and implement a
Book class, such as you can imagine as part of software for a library.
Class Book should have members for the ISBN, title, author, and
copyright date. Also store data on whether or not the book is checked
out. Create functions for returning those data values. Create functions
for checking a book in and out. Do simple validation of data entered into
a Book; for example, accept ISBNs only of the form n−n−n−x where n is
an integer and x is a digit or a letter. Store an ISBN as a string.
---

I used the Date class created in the drill. Not sure if I should've created 
header and cpp files for the year and month structs, but it seemed too much
for a program such as this (creating a namespace for this might be a good idea).
Ideally, one would use a Date object provided by the standard library (or any
other good library) instead of this custom one.

Jan 2025
@jmerort
*/


#include <iostream>
#include <chrono>
#include "date.h"

using std::cout, 
	  std::cin,
	  std::string,
	  std::vector;



//----------------------------------------------------------------------



class Book
{
	public:
		Book(string, string, string, Date, bool);

		bool is_valid();
	
		string get_isbn(){return isbn;};
		string get_title(){return title;};
		string get_author(){return author;};
		Date get_copyright(){return copyright;};
		bool get_checked(){return checked;};

		class Invalid{};

		void check_in();
		void check_out();
		
	private:
		string isbn, //isbn number
			   title,
		       author;
		Date copyright; //copyright date
		bool checked; //true if the book has been borrowed/checked out
};



Book::Book (string num, string ti, string au = "Unknown", Date copy = Date{}, bool check = false)
//Book constructor, one must provide at least isbn and title
	:isbn{num},title{ti},author{au},copyright{copy},checked{check}
{
	if (!is_valid()) throw Invalid{};
}



bool Book::is_valid()
{
	//check if the isbn is made of 3 digits and a letter
	return isbn.size() == 4 && isdigit(isbn[0]) && isdigit(isbn[1]) && isdigit(isbn[2]) && isalpha(isbn[3]);
}



void Book::check_in()
{
	if (checked)
		checked = false;
	else
		cout << "The book hasn't been checked out yet.\n";
}



void Book::check_out()
{
	if (!checked)
		checked = true;
	else 
		cout << "The book has already been checked out, somebody else has it.\n";
}
  
  

//----------------------------------------------------------------------



int main()
{
	try 
	{	
		Date today{1870, Month::aug, 12};
		Book crime{"173d", "crime_and_punishment", "F. Dostoevski", today, true}; //regular book

		Book lazarillo{"123a", "lazarillo_de_tormes"}; //book without author, date or status provided
		lazarillo.check_out();
		cout << lazarillo.get_title() << " check status: " << lazarillo.get_checked() << '\n';
		lazarillo.check_out(); //try to check out an already checked out book

		Book fake{"123$", "fake_book"}; //book with wrong isbn

		return 0;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
	catch(Book::Invalid)
	{
		std::cerr << "Invalid isbn.\n";
		return 2;
	}
	catch(Date::Invalid)
	{
		std::cerr << "Invalid date.\n";
		return 3;
	}
	catch(...)
	{
		std::cerr << "Unknown error.\n";
		return 4;
	}
}