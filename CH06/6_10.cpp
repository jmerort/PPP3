/*
---
E6.10
[10] Modify the calculator to operate on ints (only); give errors for overflow
and underflow. Hint: Use narrow (§6.5).
---


-GRAMMAR-
Calculation:
	Statement
	Print
	Quit
	Calculation Statement
	Help
	List
List:
	"Variable and constant list"
Help:
	"Instructions for the calculator..."
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
	"const" Name "=" Expression
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


Dec 2024
@jmerort
*/



#include <iostream>
#include <vector>
#include <math.h>
#include <cctype>


//----------------------------------------------------------------------



struct Token 
{
	//Token type to represent the unitary elements that can be input into the calculator.
	char kind;
	int value;
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
	//to hold the last read tokens
	bool full;
	std::vector <Token> buffer; //vector that cand hold many tokens
	
public:
	Token_stream() :full(0), buffer(0) { }
	Token get();
	void unget(Token t) { buffer.push_back(t); full = true; } // put the last read token back in the buffer
	void ignore(char);
};



//----------------------------------------------------------------------



const char let = '#', //keywords for different actions
           quit = 'Q',
           print = ';',
           number = '8',
           name = 'a',
	   square_root = 'S',
	   power = 'P',
	   ct = 'C',
	   help = 'H',
	   list = 'L';

const std::string prompt = "> ",
	          result = "= ";
				  
			

//----------------------------------------------------------------------



int narrow_int(double num)
{
	//converts a double to an int and throws a narrowing error if information is lost
	int i = num;
	double d = i;

	if (d != num) throw (std::runtime_error("narrowing error, use integers"));
	return i;
}




//----------------------------------------------------------------------



Token Token_stream::get()
{
	//get a token, either by emptying the buffer or by reading a new token from the input stream
	if (full) //if there already is a token in the buffer, return it
	{
		Token last = buffer[buffer.size()-1];
		buffer.pop_back();
        	if (buffer.size() == 0) full = false; //if the buffer has been emptied, the get() method will now read more characters from input stream
        	return last;
	}
	char ch;
	std::cin.get(ch);
	while(isspace(ch)) 
	{
		if(ch == '\n') return Token(print);
		else std::cin.get(ch);
	}
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
		int n = narrow_int(val);
            	return Token(number, n);
        }
	case '#': //new declaration keyword
		return Token(let);
        default: //if the character read os none of the above, it can be one of the keywords or a mistake

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
			if (s == "const")
				return (Token(ct));
			if (s == "h" || s == "H") // I put this here to avoid words beginning with h to be mistaken as help commands
				return (Token(help));
			if (s == "list")
				return (Token(list));
                	return Token(name, s); //if none of these, it's a variable
            	}
            throw(std::runtime_error("Bad token"));
	}
}



//----------------------------------------------------------------------



void Token_stream::ignore(char c)
{
	//discard all input stream characters until a certain one is reached, used to clean up erroneous expressions
	if (full && c == buffer[buffer.size()-1].kind) {
		full = false;
		buffer.clear();
		return;
	}
	buffer.clear();
	full = false;

	char ch;
	while (std::cin.get(ch))
		if (ch == c || ch == '\n') return; //improved version that returns when newline is pressed as well as print
}



//----------------------------------------------------------------------



struct Variable 
{
	//class for named variables
	std::string name;
	int value;
	bool ct;
	Variable(std::string n, int v, bool c) :name(n), value(v), ct(c) { }
};



//----------------------------------------------------------------------



class Symbol_table 
{
	//class to hold the variable vector and its methods
	private:
		std::vector <Variable> var_table;
	public:
		int get(std::string);
		void set(std::string, int);
		bool is_declared(std::string);
		int declare(bool);
		void add(std::string, int, bool);
		void print_variables();
};



//----------------------------------------------------------------------



Symbol_table nombres;
Token_stream ts;
double expression();



int Symbol_table::get(std::string s)
{
	//get the value of a named variable from the vector
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	throw(std::runtime_error("get: undefined name "));
}


void Symbol_table::set(std::string s, int d)
{
	//change the value of a named variable from the vector
	for (int i = 0; i <= var_table.size(); ++i)
	{
		if (var_table[i].name == s) {
			if(var_table[i].ct) throw(std::runtime_error("can't change value of a constant."));
			var_table[i].value = d;
			return;
		}
	}
	throw(std::runtime_error("set: undefined name "));
}


bool Symbol_table::is_declared(std::string s)
{
	//check if a named variable is in the vector
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return true;
	return false;
}


int Symbol_table::declare(bool c)
{
	//compute a declaration: put a variable in a Variable vector and return its value
	Token t = ts.get();
	if (t.kind != 'a') throw(std::runtime_error("name expected in declaration"));
	std::string name = t.name;
	if (is_declared(name)) throw(std::runtime_error(" declared twice"));
	Token t2 = ts.get();
	if (t2.kind != '=') throw(std::runtime_error("= missing in declaration"));
	if (name[0] == '_') throw(std::runtime_error("variable name can't begin with underscore"));
	double d = expression();
	int val = narrow_int(d);
	add(name, val, c);
	return val;
}


void Symbol_table::add(std::string name, int d, bool c)
{
	//add a new variable to the vector directly
	var_table.push_back(Variable(name, d, c));
}


void Symbol_table::print_variables()
{
	//print a list of all variables and constants and their values
	std::cout << "-USER-DEFINED VARIABLES-\n-Constants:\n";
	for(int i = 0; i < var_table.size(); i++)
		if (var_table[i].ct)
			std::cout << var_table[i].name << " = " << var_table[i].value << "\n";
	std::cout << "-Variables:\n";
	for(int u = 0; u < var_table.size(); u++)
		if (!var_table[u].ct)
			std::cout <<  var_table[u].name << " = " << var_table[u].value << "\n";
}



//----------------------------------------------------------------------



int pot(double n, int i)
{
	//computes n to the power of i
	double power = n;

	for(int u = 1; u < i; u++)
		power *=  n;
	return power;
}



//----------------------------------------------------------------------



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
		double d;
		if(t.kind == name) d = nombres.get(t.name);
		else if(t.kind == number) d = t.value;
		else throw(std::runtime_error("Power syntax error (should be \"pow(a,b)\")"));
		t = ts.get();
		if (t.kind != ',') throw(std::runtime_error("Power syntax error (should be \"pow(a,b)\")"));
		t = ts.get();
		int i;
		if(t.kind == name) i = nombres.get(t.name);
		else if(t.kind == number) i = t.value;
		else throw(std::runtime_error("Power syntax error (should be \"pow(a,b)\")"));
		t = ts.get();
		if (t.kind != ')') throw(std::runtime_error("Power syntax error (should be \"pow(a,b)\")"));
	       	return pot(d,i);
	}
	case number:
		return t.value;
	case name:
		return nombres.get(t.name);
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
		{	
			double d = primary();
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



int assignment(std::string name)
{
	//compute an assignment, give a variable a value and return it
	if(!nombres.is_declared(name)) throw(std::runtime_error("can't assign value to underclared variable"));
	Token t = ts.get();
	if (t.kind != '=') throw(std::runtime_error("= missing in assignment"));
	double d = expression();
	int val = narrow_int(d);
	nombres.set(name, val);
	return val;
}



//----------------------------------------------------------------------



void print_help()
{
	std::cout <<"-INSTRUCTIONS-\nEnter an arithmetical expression made of integers (or several followed by ; each) to compute its results.\n"
		  <<"Available operands: \"+\", \"-\", \"*\", \"/\", \"pow(a,b)\", \"sqrt()\"\n"
		  <<"Use \"#\" to define new variables (e.g.: # price = 24;) and \"const\" to define new constants (e.g.: const uno = 1).\n"
		  <<"Enter \"list\" to see the list of current variables.\n"
		  <<"Enter \"exit\" to exit and \"h\" to see the instructions again.\n";
}



//----------------------------------------------------------------------



double statement()
{
	//compute a statement and return its value
	Token t = ts.get();
	switch (t.kind) 
	{
		case help: 
			print_help();
			return 0; //an additional zero is printed, which I don't like
		case list:
			nombres.print_variables();
			return 0;
		case ct:
			return nombres.declare(true); //constant variable declaration
		case let:
			return nombres.declare(false); //non constant variable declaration
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



//----------------------------------------------------------------------



void clean_up_mess()
{
	//ignore all input up to a print character
	ts.ignore(print);
}



//----------------------------------------------------------------------



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



//----------------------------------------------------------------------



int main()
{
	try 
	{
		nombres.add("pi", 3.1415926535, 1);
		nombres.add("e", 2.7182818284, 1);
		nombres.add("k", 1000, 1);

		std::cout << "-INTEGER CALCULATOR-\nPress \"h\" for help and \"exit\" to exit the program.\n";
		calculate();
		return 0;
	}

	catch (std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
	catch (...)
	{
		std::cerr << "Error: unknown error.\n";
		return 2;
	}
}
