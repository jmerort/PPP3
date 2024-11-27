/*
---
E6.2
[2] Provide an assignment operator, =, so that you can change the value of a
variable after you have introduced it using let. Discuss why that can be
useful and how it can be a source of problems.
---

This can be hard to implement, because now you have to distinguish between two potential uses of variables, assignments and normal uses. To distinguish them you have to somehow look ahead to see if the variable name is followed by an "=" sign.
We can make it easier if we add a keyword at the begining of an assignment such as "make a = 10", but if we want to make assignments behave like in other programming languages "a = 10" we have to change the Token buffer so it can hold more than one token, which increases program complexity a bit.

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
	Assignment
	Declaration
	Expression
Assignment:
	Name "=" Expression
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

class Token_stream { //to hold the last read tokens
	bool full;
	std::vector <Token> buffer; //vector that cand hold many tokens
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer.push_back(t); full = true; } // put the last read token back in the buffer
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
		Token last = buffer[buffer.size()-1];
		buffer.pop_back();
        	if (buffer.size() == 0) full = false; //if the buffer has been emptied, the get() method will now read more characters from input stream
        	return last;
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

void Token_stream::ignore(char c)
{
	if (full && c == buffer[buffer.size()-1].kind) {
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

double assignment(std::string name)
{
	if(!is_declared(name)) throw(std::runtime_error("can't assign value to underclared variable"));
	Token t = ts.get();
	if (t.kind != '=') throw(std::runtime_error("= missing in assignment"));
	double d = expression();
	set_value(name, d);
	return d;
}

double declaration()
{
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

double statement()
{
	Token t = ts.get();
	switch (t.kind) 
	{
		case let:
			return declaration();
		default:
			Token t1 = ts.get();
			if(t1.kind == '=')
			{
				ts.unget(t1);
				return assignment(t.name);
			}
			ts.unget(t1);
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
		while (t.kind == print)	t = ts.get();
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

	std::cout << "-CALCULATOR-\nEnter an arithmetic expression and end it by ; to see the result. Available operands:\n"
		  << "+, -, *, /, sqrt(a), pow(a,b).\nYou can now add variables, declare them using \"let\" (e.g. let v1 = 10;) and give them new values.\n";
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
