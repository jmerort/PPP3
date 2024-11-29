/*
---
E6.1
[1] Allow underscores in the calculator's variable names.
---

I've assumed that a variable name can't begin with an underscore and added a check for that.

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


25 Nov 2024
@jmerort
*/



#include <iostream>
#include <vector>
#include <math.h>



//----------------------------------------------------------------------



struct Token
{
	//Token type to represent the unitary elements that can be input into the calculator.
	char kind;
	double value;
	std::string name; //name used for variables

public:
	Token() :kind{'0'}{}
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, std::string n) :kind{ch}, name{n} {} //variable constructor
};



//----------------------------------------------------------------------



class Token_stream 
{
	//to hold the last read token
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};



//----------------------------------------------------------------------



const char let = 'L', //keywords for different actions
           quit = 'Q',
           print = ';',
           number = '8',
           name = 'a',
	       square_root = 'S',
	       power = 'P';

const std::string prompt = "> ",
				  result = "= ";
				  
				  
				  
Token Token_stream::get()
{
	//get a token, either by emptying the buffer or by reading a new token from the input stream
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

			if (isalpha(ch)) //is ch a letter
			{
				std::string s;
				s = ch;
				while (std::cin.get(ch) && ((isalpha(ch) || isdigit(ch) || ch == '_'))) s += ch;
				std::cin.putback(ch);
				if (s == "exit")
					return Token(quit);
				if (s == "sqrt")
					return (Token(square_root));
				if (s == "pow")
					return (Token(power));
				return Token(name, s); //if none of these, it's a variable
			}
			throw(std::runtime_error("Bad token"));
	}
}



//----------------------------------------------------------------------



void Token_stream::ignore(char c)
{
	//discard all input stream characters until a certain one is reached, used to clean up erroneous expressions
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (std::cin >> ch)
		if (ch == c) return;
}



//----------------------------------------------------------------------



struct Variable {
	//class for named variables
	std::string name;
	double value;
	Variable(std::string n, double v) :name(n), value(v) { }
};



//----------------------------------------------------------------------



std::vector<Variable> names;
//vector to hold the named variables



double get_value(std::string s)
{
	//get the value of a named variable from the vector
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	throw(std::runtime_error("get: undefined name "));
}

void set_value(std::string s, double d)
{
	//change the value of a named variable from the vector
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	throw(std::runtime_error("set: undefined name "));
}

bool is_declared(std::string s)
{
	//check if a named variable is in the vector
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}



//----------------------------------------------------------------------

int pot(int n, int i)
{
	//computes n to the power of i
	int power = n;

	for(int u = 1; u < i; u++)
		power *=  n;
	return power;
}



//----------------------------------------------------------------------



Token_stream ts;
double expression();



double primary()
{
	//compute a primary and return its value
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



//----------------------------------------------------------------------



double term()
{
	//compute a term and return its value
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



//----------------------------------------------------------------------



double expression()
{
	//compute an expression and return its value
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



//----------------------------------------------------------------------



double declaration()
{
	//compute a declaration and return its value
	Token t = ts.get();
	if (t.kind != 'a') throw(std::runtime_error("name expected in declaration"));
	std::string name = t.name;
	if (is_declared(name)) throw(std::runtime_error(" declared twice"));
	Token t2 = ts.get();
	if (t2.kind != '=') throw(std::runtime_error("= missing in declaration"));
	if (name[0] == '_') throw(std::runtime_error("variable name can't begin with underscore"));
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}



//----------------------------------------------------------------------



double statement()
{
	//compute a statement and return its value
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



//----------------------------------------------------------------------



void define_name(std::string name, double val)
{
	names.push_back(Variable(name, val));
}



//----------------------------------------------------------------------



void clean_up_mess()
{
	//throw out all input up to a print character
	ts.ignore(print);
}



//----------------------------------------------------------------------



void calculate()
{
	//perform the calculation loop until quit is pressed or an error has occured
	while (true) try {
		std::cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		
		std::cout << result << statement() << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		clean_up_mess();
	}
}



//----------------------------------------------------------------------



int main()
try 
{
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	define_name("k", 1000);

	std::cout << "-CALCULATOR-\nEnter an arithmetic expression and end it by ; to see the result. Available operands:\n"
		      << "+, -, *, /, sqrt(a), pow(a,b).\nYou can now add variables, declare them using \"#\" (e.g. # v1 = 10;) and give them new values.\n";
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
