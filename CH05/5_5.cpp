/*
---
E5.5
[5] Write a grammar for bitwise logical expressions. A bitwise logical
expression is much like an arithmetic expression except that the
operators are ! (not),  ̃ (complement), & (and), | (or), and ˆ (exclusive or).
Each operator does its operation to each bit of its integer operands (see
PPP2.§25.5). ! and  ̃ are prefix unary operators. A ˆ binds tighter than a |
(just as * binds tighter than +) so that x|yˆz means x|(yˆz) rather than
(x|y)ˆz. The & operator binds tighter than ˆ so that xˆy&z means xˆ(y&z).
---

--Operators--
! not
~ complement
& and 
| or
^ xor

--Grammar--
Expression: 
    Term
    Expression | Term
Term:
    Phrase
    Term & Phrase
Phrase:
    Composite
    Phrase ^ Composite
Composite:
    Primary
    !Primary
    ~Primary
Primary: 
    Proposition
    "("Expression")"
Proposition:
    Boolean


Aside from writing the grammar, I made a very simple logical calculator using it. The operands it uses are true
propositions represented by 't' and false propositions represented by 'f'. Example input: "!(f^t)^t="

MISSING: MAKE ! AND ~ BE PREFIXES INSTEAD OF SUFFIXES
8 Nov 2024
@jmerort
*/

#include <iostream>

class Token
{
    public:
        char kind; // what kind of token
        bool value; // for propositions, a logical value

        Token(char ch):kind(ch), value(false) { } // make a Token from a char
        Token(char ch, bool val):kind(ch), value(val) { } // make a Token from a char and a bool
};



//-----------------------------------------------------------------



class Token_stream 
{
    public:
        Token_stream(); // make a Token_stream that reads from cin
        Token get(); // get a Token (get() is defined elsewhere)
        void putback(Token t); // put a Token back

    private:
        bool full; // is there a Token in the buffer?
        Token buffer; // here is where we keep a Token put back using putback()
};



//---------------------------------------------------



// The constructor just sets full to indicate that the buffer is empty:

Token_stream::Token_stream():full(false), buffer(0) // no Token in buffer
{
}



//-----------------------------------------------------



void Token_stream::putback(Token t)
{
    if (full) 
        throw(std::runtime_error("putback() into a full buffer"));

    buffer = t; // copy t to buffer
    full = true; // buffer is now full
}



//----------------------------------------------------------



Token Token_stream::get()
{
    if (full) 
    { // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) 
    {
        case '=': // for "print"
        case 'x': // for "quit"
        case '(': case ')': case '!': case '~': case '|': case '&': case '^': case '{': case '}':
            return Token(ch); // let each character represent itself

        case 't':
        {
            return Token('p', true); // let '8' represent "a number"
        }

        case 'f':
        {
            return Token('p', false); // let '8' represent "a number"
        }
        default:
            throw(std::runtime_error("Bad token"));
    }
}



//-----------------------------------------------------------------



Token_stream ts; // provides get() and putback()
bool expression();
bool phrase();



//------------------------------------------------------------------------------



// deal with numbers and parentheses

bool primary()
{
    Token t = ts.get();

    switch (t.kind) 
    {
        case '{': //handle '{' expression '}'
        {
            bool b = expression();

            t = ts.get();
            if (t.kind != '}') 
                throw(std::runtime_error("'}' expected"));
            return b;
        }
        case '(': // handle '(' expression ')'
        {
            bool d = expression();

            t = ts.get();
            if (t.kind != ')') 
                throw(std::runtime_error("')' expected"));
            return d;
        }
        case 'p': // we use 'p' to represent a proposition
            return t.value; // return the proposition's value
        default:
            throw(std::runtime_error("primary expected"));
    }
}




//-----------------------------------------------------------------------


//deal with ! and ~
bool composite()
{
    Token t = ts.get(); // get the next token from token stream
    bool left,
         flag = false; //flag to avoid calling primary() twice
    while (true) 
    {
        switch (t.kind) 
        {
            case '!':
                left = !primary();
                flag = true;
                t = ts.get();
                break;
            case '~':
                left = !primary();
                flag = true;
                t = ts.get();
                break;
            default:
                ts.putback(t); // put t back into the token stream
                if(flag == false)
                    left = primary();
                return left;
        }
    }
}



//-----------------------------------------------------------------------

//deal with ^
bool phrase()
{
    bool left = composite();
    Token t = ts.get(); // get the next token from token stream

    while (true) 
    {
        switch (t.kind) 
        {
            case '^':
                left = composite() xor left;
                t = ts.get();
                break;
            default:
                ts.putback(t); // put t back into the token stream
                return left;
        }
    }
}

//------------------------------------------------------------------------------



// deal with &

bool term()
{
    bool left = phrase();
    Token t = ts.get(); // get the next token from token stream

    while (true) 
    {
        switch (t.kind) 
        {
            case '&':
                left = phrase() and left;
                t = ts.get();
                break;
            default:
                ts.putback(t); // put t back into the token stream
                return left;
        }
    }
}



//------------------------------------------------------------------------------



// deal with |

bool expression()
{
    bool left = term(); // read and evaluate a Term
    Token t = ts.get(); // get the next token from token stream

    while (true) 
    {
        switch (t.kind) 
        {
            case '|':
            left = term() or left; // evaluate Term and add
            t = ts.get();
            break;

            default:
            ts.putback(t); // put t back into the token stream
            return left; // finally: no more + or -: return the answer
        }
    }
}



//------------------------------------------------------------------------------








//------------------------------------------------------------------------------



int main()
{
    std::cout << "-LOCICAL CALCULATOR-\nThis calculator accepts two operands: \"t\" (true proposition) and"
              <<" \"f\" (false proposition)\nand the operators \"!\" \"~\" \"|\" \"&\" and \"^\"\n";
    bool val = expression();
    try
    {
        while (std::cin) 
        {
            Token t = ts.get();
            if (t.kind == 'x') 
                break; // 'x' for quit
            else if (t.kind == '=') // '=' for "print now"
                if(val == true)
                    std::cout << "=True\n";
                else if(val == false)
                    std::cout << "=False\n";
            else
                ts.putback(t);

            val = expression();
        }
    }

    catch (std::exception& e)
    {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }

    catch (...) 
    {
        std::cerr << "Oops: unknown exception!\n";
        return 2;
    }
}

//------------------------------------------------------------------------------


