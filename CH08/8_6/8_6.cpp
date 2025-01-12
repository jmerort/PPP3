/*
---
E8.6
[6] Add operators for the Book class. Have the == operator check whether the
ISBN numbers are the same for two books. Have != also compare the
ISBN numbers. Have a << print out the title, author, and ISBN on
separate lines.
---

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

		friend std::ostream& operator << (std::ostream&, Book); //print title, author and isbn
		friend bool operator == (Book, Book); //check if isbn numbers are equal
		friend bool operator != (Book, Book); // '' different

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
  


std::ostream& operator << (std::ostream& os, Book b)
{
	os << "Title: " << b.title << '\n' 
	   << "Author: " << b.author << '\n'
	   << "ISBN: " << b.isbn << '\n';

	return os;
}



bool operator == (Book b1, Book b2)
//check if the isbn numbers are the same
{
	return b1.isbn == b2.isbn;
}



bool operator != (Book b1, Book b2)
//check if the isbn numbers are different
{
	return !(b1 == b2); //I define this operation in terms of the "==" one
}



//----------------------------------------------------------------------



int main()
{
	try 
	{	
		Book lazarillo{"123a", "Lazarillo de Tormes"}; //book without author, date or status provided
		Book illiad{"123a", "The Illiad", "Homer"}; //book with same isbn
		Book hamlet("231y", "Hamlet", "W. Shakespeare");

		cout << lazarillo;

		if (lazarillo == illiad) cout << lazarillo.get_title() << " and " 
		   							  << illiad.get_title() << " have the same ISBN\n";

		if (lazarillo != hamlet) cout << lazarillo.get_title() << " and " 
		   							  << hamlet.get_title() << " have different ISBNs\n";

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