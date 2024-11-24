/*
---
UNIT 6 DRILL
[1] Starting from the file calculator08buggy.cpp, get the calculator to compile.
[2] Go through the entire program and add appropriate comments.
[3] As you commented, you found errors (deviously inserted especially for
you to find). Fix them; they are not in the text of the book.
[4] Testing: prepare a set of inputs and use them to test the calculator. Is
your list pretty complete? What should you look for? Include negative values, 0, very small, very large, and silly inputs.
[5] Do the testing and fix any bugs that you missed when you commented.
[6] Add a predefined name k meaning 1000.
[7] Give the user a square root function sqrt(), for example, sqrt(2+6.7).
Naturally, the value of sqrt(x) is the square root of x; for example, sqrt(9)
is 3. Use the standard-library sqrt() function to implement that calculator
sqrt(). Remember to update the comments, including the grammar.
[8] Catch attempts to take the square root of a negative number and print an
appropriate error message.
[9] Allow the user to use pow(x,i) to mean Multiply x with itself i times; for
example, pow(2.5,3) is 2.5*2.5*2.5. Require i to be an integer using the
technique we used for % (§6.5).
[10] Change the declaration keyword from let to #.
[11] Change the quit keyword from quit to exit. That will involve defining a
string for quit just as we did for let in §6.8.2.
---


calculator08buggy.cpp
Helpful comments removed.
We have inserted 3 bugs that the compiler will catch and 3 that it won't.


-GRAMMAR-
Calculation:
	Statement
	Print
	Quit
	Calculation Statement
Print: 
	";"
Quit:
	"q"
Statement:
	Declaration
	Expression
Declaration:
	"let" Name "=" Expression
Expression:
	Term
	Expression "+" Term
	Expression "-" Term
Term:
	Primary
	Term "*" Primary
	Term "/" Primary
	Term "%" Primary
Primary:
	Number
	"sqrt(" Expression ")"
	"pow(" Expression ")"
	"(" Expression ")"
	"-" Primary
	"+" Primary
Number:
	floating-point-literal


15 Nov 2024
@jmerort
*/

#include <iostream>
#include <vector>
#include <math.h>

struct Token {
	char kind;
	double value;
	std::string name; //name used for variables

public:
	Token() :kind{'0'}{}
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, std::string n) :kind{ch}, name{n} {} //variable constructor
};

class Token_stream { //to hold the last read token
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L', //keywords for different actions
           quit = 'Q',
           print = ';',
           number = '8',
           name = 'a',
	   square_root = 'S',
	   power = 'P';

Token Token_stream::get()
{
	if (full) //if there already is a token in the buffer, return it
	{
        	full = false;
        	return buffer; 
	}
	char ch;
	std::cin >> ch;
	switch (ch) 
	{
        case '(': //if the character read is a symbol, return it
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
	case ',':
        case '=':
            	return Token(ch);
        case '.': //if the character read is the start of a number, put it back and read the whole number into a double
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {	
	    	std::cin.unget();
            	double val;
	    	std::cin >> val;
            	return Token(number, val);
        }
        default: //if the character read os none of the above, it can be one of the keywords or a mistake
            	if (ch == '#') //new declaration keyword
			return Token(let);

		if (isalpha(ch)) //is ch a letter?
            	{
			std::string s;
                	s = ch;
                	while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			std::cin.putback(ch);
                	if (s == "exit")
                    		return Token(quit);
			if (s == "sqrt")
				return (Token(square_root));
			if (s == "pow")
				return (Token(power));
                	return Token(name, s);
            	}
            throw(std::runtime_error("Bad token"));
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (std::cin >> ch)
		if (ch == c) return;
}

struct Variable {
	//class for named variables
	std::string name;
	double value;
	Variable(std::string n, double v) :name(n), value(v) { }
};

std::vector<Variable> names;

double get_value(std::string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	throw(std::runtime_error("get: undefined name "));
}

void set_value(std::string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	throw(std::runtime_error("set: undefined name "));
}

bool is_declared(std::string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

int pot(int n, int i)
{
	//computes n to the power of i
	int power = n;

	for(int u = 1; u < i; u++)
		power *=  n;
	return power;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	
		double d = expression();
		t = ts.get();
		if (t.kind != ')') throw(std::runtime_error("'(' expected"));
		return d;
	}
	case '-':
		return -primary();
	case square_root:
	{
		double d = primary();
		if (d < 0) throw(std::runtime_error("square root of a negative is not defined"));
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if(t.kind != '(') throw(std::runtime_error("Power syntax error (should be \"pow(a,b)\")"));
		t = ts.get();
		if(t.kind != number) throw(std::runtime_error("Power syntax error (should be \"pow(a,b)\")"));
		int d = t.value;
		t = ts.get();
		if (t.kind != ',') throw(std::runtime_error("Power syntax error (should be \"pow(a,b)\")"));
		t = ts.get();
		if (t.kind != number) throw(std::runtime_error("Power syntax error (should be \"pow(a,b)\")"));
		int i = t.value;
		t = ts.get();
		if (t.kind != ')') throw(std::runtime_error("Power syntax error (should be \"pow(a,b)\")"));
	       	return pot(d,i);
	}
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		throw(std::runtime_error("primary expected"));
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) throw(std::runtime_error("divide by zero"));
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') throw(std::runtime_error("name expected in declaration"));
	std::string name = t.name;
	if (is_declared(name)) throw(std::runtime_error(" declared twice"));
	Token t2 = ts.get();
	if (t2.kind != '=') throw(std::runtime_error("= missing in declaration"));
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) 
	{
		case let:
			return declaration();
		default:
       	    		ts.unget(t);
	    		return expression();
	}
}

void define_name(std::string name, double val)
{
	names.push_back(Variable(name, val));
}

void clean_up_mess()
{
	ts.ignore(print);
}

const std::string prompt = "> ";
const std::string result = "= ";

void calculate()
{
	//perform the calculation loop until quit is pressed or an error has occured
	while (true) try {
		std::cout << prompt;
		Token t = ts.get();
		while (t.kind == print)
			t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		
		std::cout << result << statement() << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		clean_up_mess();
	}
}

int main()
try 
{
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	define_name("k", 1000);

	calculate();
	return 0;
}

catch (std::exception& e) 
{
	std::cerr << "exception: " << e.what() << std::endl;
	char c;
	while (std::cin >> c && c != ';');
	return 1;
}
catch (...) 
{
	std::cerr << "exception\n";
	char c;
	while (std::cin >> c && c != ';');
	return 2;
}
