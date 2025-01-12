/*
---
E8.8
[8] Create a Patron class for the library. The class will have a user’s name,
library card number, and library fees (if owed). Have functions that
access this data, as well as a function to set the fee of the user. Have a
helper function that returns a Boolean (bool) depending on whether ornot the user owes a fee.
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



class Patron 
{
	public:
		Patron(string, long, double);
		
		string get_username(){return username;};
		long get_card_n(){return card_n;};
		double get_fee(){return fee;};

		void set_fee(double);

	private:
		string username;
		long card_n;
		double fee;	
};



Patron::Patron(string un, long cn, double fe = 0) 
	:username{un},card_n{cn},fee{fe}{}



void Patron::set_fee(double f)
{
	if (f < 0) fee = 0; //trying to set negative fees cancels the fee
	else fee = f;
}



bool owes_fee(Patron p)
//checks if a Patron owes any fees
{
	return p.get_fee() > 0;
}



//----------------------------------------------------------------------



enum class Genre {
	unk=0, lyr=1, epic, dram, nov, hist, phil, sci, jour, rel
};



//names of the genres
vector<string> genre_tbl = {"Unknown", "Lyric", "Epic", "Drama", "Novel", "History", 
							 "Philosophy", "Science", "Journalism", "Religion"};



std::ostream& operator << (std::ostream& os, Genre g)
//print genre name
{
	os << genre_tbl[static_cast <int>(g)];
	return os;
}



//----------------------------------------------------------------------



class Book
{
	public:
		Book(string, string, string, Genre, Date, bool);

		bool is_valid();
	
		string get_isbn(){return isbn;};
		string get_title(){return title;};
		string get_author(){return author;};
		Genre get_genre(){return genre;};
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
		Genre genre;
		Date copyright; //copyright date
		bool checked; //true if the book has been borrowed/checked out
};



Book::Book (string num, string ti, string au = "Unknown", Genre gen = Genre::unk, Date copy = Date{}, bool check = false)
//Book constructor, one must provide at least isbn and title
	:isbn{num},title{ti},author{au},genre{gen},copyright{copy},checked{check}
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
	   << "Genre: " << b.genre << '\n'
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
		Patron john{"John", 453};
		cout << "Patron " << john.get_username() << " owes " << john.get_fee() << " Euros.\n";

		john.set_fee(10); 
		cout << "Patron " << john.get_username() << " owes " << john.get_fee() << " Euros.\n";

		john.set_fee(-10); //try to set negative value
		cout << "Patron " << john.get_username() << " owes " << john.get_fee() << " Euros.\n";

		if (owes_fee(john)) cout << john.get_username() << " owes a fee.\n";
		else cout << john.get_username() << " doesn't owe any money.\n";
		
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