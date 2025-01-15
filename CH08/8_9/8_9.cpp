/*
---
E8.9
[9] Create a Library class. Include vectors of Books and Patrons. Include a
struct called Transaction to record when a book is checked out. Have it
include a Book, a Patron, and a Date. Make a vector of Transactions to
keep a record of which books are out. Create functions to add books to
the library, add patrons to the library, and check out books. Whenever a
user checks out a book, have the library make sure that both the user and
the book are in the library. If they aren’t, report an error. Then check to
make sure that the user owes no fees. If the user does, report an error. If
not, create a Transaction, and place it in the vector of Transactions. Also
write a function that will return a vector that contains the names of all
Patrons who owe fees.
---

This program is much more complicated than the previous ones (and might benefit from splitting some
classes into files). You could make it way more polished than this, but I don't want this to turn
into a project, so I'll leave it as it is. 

I tried to make it so that the user interacts as much as possible with the Library objects, and lets
those objects handle the Patron and Book objects.

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



std::ostream& operator << (std::ostream& os, Patron p)
{
	os << "Username: " << p.get_username() << '\n' 
	   << "Card number: " << p.get_card_n() << '\n'
	   << "Fee: " << p.get_fee() << "$\n";

	return os;
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
}



void Book::check_out()
{
	if (!checked)
		checked = true;
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



struct Transaction 
{
	Book b;
	Patron p;
	Date d;	
};


Date today {2025, Month::jan, 15};


//----------------------------------------------------------------------



class Library 
{
	public:
		Library(){};

		void add_book (Book); //add 1 book
		void add_books (const vector <Book>&); //add a list of books
		void add_patron (const string&); //add 1 patron

		void check_out(const string&, const string&); //check out a book if possible

		void set_fee(const string&, const double); // set a patron's fee

		void print_catalog ();
		void print_patrons ();
		void print_transactions ();
		void print_debtors (); //print patrons who have any fees currently


	private:
		vector <Book> books;
		vector <Patron> patrons;
		vector <Transaction> transactions; //book check-outs

		bool check_isbn (const string&); //check if there is any book with that isbn in catalogue
		bool check_username (const string&); //check if there is any patron with that username

		int get_book(const string&); //get book position with given isbn number
		int get_patron(const string&); //get patron position with a given username
};



bool Library::check_isbn(const string& s)
//check if the library has a book with the same isbn
{
	bool same{false};

	for (int i{0}; i < books.size(); i++)
		if (books[i].get_isbn() == s) same = true;

	return same;
}



bool Library::check_username(const string& n)
//check if there is a patron with a given username
{
	bool same{false};

	for (int i{0}; i < patrons.size(); i++)
		if (patrons[i].get_username() == n) same = true;

	return same;
}



int Library::get_book(const string& isbn)
{
// pre-condition: there is a book with that name in the library
	for (int i{0}; i < books.size(); i++)
		if (books[i].get_isbn() == isbn) return i;
	
	throw std::runtime_error("No book with that name, check first!\n"); 
}



int Library::get_patron(const string& username)
{
// pre-condition: there is a patron with that name in the library
	for (int i{0}; i < patrons.size(); i++)
		if (patrons[i].get_username() == username) return i;
	
	throw std::runtime_error("No patron with that name, check first!\n"); 
}



void Library::add_book(Book b)
//if there isn't a book with the same isbn, add it to the list
{
	if (check_isbn(b.get_isbn()))
	{
		cout << ("Another book has the same isbn.\nIsbn:");
		return;
	}
	books.push_back(b);
}



void Library::add_books (const vector <Book>& books)
{
	for (Book b : books) add_book(b);
}



void Library::add_patron(const string& username)
//if there isn't a user with the same username, add him as a patron
{
	if(check_username(username))
	{
		cout << "Username: " << username << " already taken.\n\n";
		return;
	}

	patrons.push_back({username, patrons.size()-1});
}



void Library::check_out(const string& username, const string& isbn)
//check out a book if possible
{
	
		//check if patron is in library
	if (!check_username(username)) 
	{
		cout << username << " is not a library patron.\n";
		return;
	}

	//check if patron owes fee
	int patron_n = get_patron(username);
	if (patrons[patron_n].get_fee()) 
	{
		cout << "Patron " << username << " owes a fee and can't check out books yet.\n";
		return; 
	}		

	//check if book is in the catalogue
	if (!check_isbn(isbn)) 
	{
		cout << "Book of isbn = " << isbn << " is not in the library catalogue.\n";
		return;
	}

	//check if the book has been cheked out
	int book_n = get_book(isbn);
	if (books[book_n].get_checked()) //if book already checked out
	{
		cout << "The book " << isbn << " has already been check out.\n";
		return;
	}
	
	//check out the book;
	books[book_n].check_out();	

	//create transaction
	transactions.push_back(Transaction{books[book_n], patrons[patron_n], today});

	cout << "Book " << books[book_n].get_title() << " of isbn " << books[book_n].get_isbn() << " successfully checked out by " 
			<< username << ".\n";
}



void Library::set_fee(const string& username, const double fee)
{
	for (int i{0}; i < patrons.size(); i++)
	{
		if (patrons[i].get_username() == username)
			patrons[i].set_fee(fee);
	}
}



void Library::print_catalog()
{
	cout << "-CATALOGUE-\n";
	for (int i{0}; i < books.size(); i++)
	{
		cout << i << " - " << books[i] << '\n';
	}
}



void Library::print_patrons()
{
	cout << "-LIBRARY PATRONS-\n";
	for (int i{0}; i < patrons.size(); i++)
	{
		cout << i << " - " << patrons[i] << '\n';
	}
}



void Library::print_transactions()
{
	cout << "\n-LIST OF TRANSACTIONS-\n";
	for (int i{0}; i < transactions.size(); i++)
	{
		cout << i << " - " << "Isbn: " << transactions[i].b.get_isbn() << '\n'
						   << "Date: " << transactions[i].d << '\n'
						   << "Patron: " << transactions[i].p.get_username() << '\n';
	}
}



void Library::print_debtors()
{
	cout << "\n-LIST OF PATRONS WHO OWE FEES-\n";
	for (Patron p : patrons)
		if (p.get_fee() > 0) cout << p;
}



//----------------------------------------------------------------------



int main()
{
	try 
	{	
		vector <Book> book_list {
			{"111a", "The Illiad", "Homer", Genre::epic},
			{"111b", "The Oddyssey", "Homer", Genre::epic},
			{"222g", "Sonnets", "W. Shakespeare", Genre::lyr},
			{"345g", "Fuenteovejuna", "Lope de Vega", Genre::dram}
		};

		Library public_lib;

		public_lib.add_books(book_list);
		public_lib.print_catalog();

		public_lib.add_patron("Josele32");
		public_lib.add_patron("NickTheBest");
		public_lib.add_patron("NickTheBest"); //try to add patron with same name
		public_lib.print_patrons();

		//testing
		public_lib.check_out("josele32", "111a"); //user enters the wrong name
		public_lib.check_out("Josele32", "111a"); //normal book borrow

		public_lib.set_fee("Josele32", 10);
		public_lib.check_out("Josele32", "111b"); //patron tries to borrow while owing fee

		public_lib.check_out("NickTheBest", "345g");  
		public_lib.check_out("NickTheBest", "111a");  //patron tries to borrow checked out book
			
		public_lib.set_fee("Josele32", 0);
		public_lib.set_fee("NickTheBest", 5);
		public_lib.check_out("Josele32", "222g"); //patron can borrow after fee is removed

		public_lib.print_transactions();
		public_lib.print_debtors();
		
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