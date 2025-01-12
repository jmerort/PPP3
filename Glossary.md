Here are my definitions of the important C++ terms that appear at the end of each chapter.
# `//`
Indicates a comment from the sign to the end of the line.

# `<<`
Output operator. It is used with output streams to print data on screen or store it in a file. 

# Abstraction
The act of leaving out of a model (mathematico-physical, economic, mental etc.) the elements deemed unnecessary for a particular goal, leaving only the essentials. In programming, it involves hiding the implementation details of a particular application, giving the user instead a simple interface through which they can use it.

# Activation record
Data structure containing a copy of all the parameters and local variables of a function.

# Argument
Variable that is passed to a function when it is called. They serve as the inputs of a function.

# Argument error
Error that appears when a function is called using a different set of arguments from those for which it has been defined. Found by the compiler.

# Argument passing
Passing [arguments](Glossary.md#Argument) to functions.

# Asesrtion
Statement that affirms an [invariant](Glossary.md#Invariant).

# Assignment
Giving a value to an already created variable, removing the previous one.

# `begin()`
Method of the std::vector class which returns its first element.

# C++
Object-oriented programming language developed by Bjarne Stroustrup. More complex than most, it offers a very good performance and is widely used in many areas.

# Call stack
Data structure that holds the activation records of the functions that have been called and have not yet returned. As functions are called it grows and as functions return it shrinks, according to the rule "last in, first out".

# `catch`
Structure indicating the code that is to be executed if a particular type of error is thrown by the try{} section.
```
try
{
	function();
}
catch(error)
{   // This section is run if an error is thrown on the try section. 
	... 
}
```

# `cin`
Character input stream. Used to give inputs to a program through the keyboard.

# Class scope
Scope containing the objects and functions that are members of a class. The `public:` elements can be accessed by any part of the program, while the `private:` ones are only accessible to class members. Class elements in C++ are private by default.

# Code layout
Distribution of code on the screen. This has to do with how the code is displayed visually and not with its logical structure, therefore, it depends on a proper use of spaces and comments. A program with a good layout will be more easily read and less susceptible to human errors.
```
// same code with 2 layouts

while(true) if(a >= 10) cout << "Hello"; else cout << "Goodbye";

while(true)
	if(a >= 10)
		cout << "Hello";
	else
		cout << "Goodbye"; 
```

# Comment
Part of a program which is ignored by the compiler and is written so that future human readers (including the author him/herself) may better understand what the program is supposed to do. 

# Commenting
Writing comments that help future readers understand and manipulate a piece of code.

# Compiler
Program tasked with translating other programs from source code to object code. The most popular for C++ is GCC (Gnu Compiler Collection), and is called by writing `g++` in the command line. 

# Compile time error
Error caught by the compiler. They can be syntax or type errors.

# Computation
Process of getting an output from an input.

# Concatenation
Putting one value immediately after another to create a new one. Can be done with strings.
```
"Hola" + "Adios" = "HolaAdios"
```

# Conditional statement
Statement that alters the flow of execution of a program based on a given logical condition.

# `const`
Variable qualifier that makes the compiler forbid the program from changing the value of that variable.

# Container
Structure that can hold many objects. In C++ the most popular container is [vector](Glossary.md#vector).

# Conversion
Change of an object's type. There are safe conversion (those whose final type can contain all the information of the original type) and unsafe ones (those where some information is lost.) See [narrowing](Glossary.md#Narrowing).
```
int a = 2.5 / 1 //conversion of double 1.25 to int 1
``` 

# `cout`
Character output stream. Used in conjunction with [`<<`](Glossary.md#<<)

# Debugging
Process of finding and fixing software errors (or bugs) in a program. It is rather tedious, so our code should be structured in such a way as to minimize the time spent on it.

# Declaration
Statement that gives name to an object or function.

# Decrement
Decrease of the value of a variable (often of 1 unit.)

# Definition
Declaration that saves memory for a given object.

# Divide and conquer
Methodology which consists of divinding big problems into many smaller solutions. In programming, this means making programs out of many interconnected programs and functions.

# Executable
Final form of a program, once it has been compiled and linked. It can be executed by a computer. 

# `else`
indicates the statement to be executed if the condition of a preceeding if is false.
```
if(cond){...} else{...}
```

# `end()`
Method of `std::vector` that returns its last element.
```
v1.end();
```

# Error 
Element of a program that causes it not to work. It includes everything from software errors to hardware or human errors. Depending on how reliable we need our program to be, we will take into account more or less errors.
To reduce the amount of errors on our programs, we can follow these steps:
1) Structure the code in such a way as to minimize mistakes, including tests, separating different functions and so on.
2) Fix the errors that have occurred through debugging and testing.
3) Make sure the remaining errors are not significant.

# Error handling
Actions that our program should take once an error has been caught. Not to be confused with [debugging](#Debugging).

# Exception
C++ mechanism of dealing with errors that separates error detection (to be done in the called function) from error handling (to be done in the called function). It consists of a structure with the functions `try()`, `throw()` and `catch()`.
```
try {
    ...
    throw(error_1) // if an error occurs, the try function can throw it
}

catch(error_1){
    ... // code to run if an error_1 is thrown within try()
}
```

# Expression
Code which computes a value from a given set of operands.
```
a + b;  10;  x == y
```

# Feature creep
Adding too many features to a program too early. This often results in programs which take way too long to develop, because we often underestimate how difficult a particular feature will be to implement. It's a good practice to make sure a small scale version of the program works before adding more functions to it.

# `for`
Loop statement with all its control information contained in its header. In the first position of it, the control variable is designated (often declared and initialized); in the second, the exit condition, which, when no longer true, makes the loop end; in the third, a statement to be executed every time the loop ends, typically used to modify the value of the control variable.
```
for (int i = 0; i < val; i++){body}
```

# Function
Named sequence of statements, characterized by these four elements:
```
type indentifier (parameters) {body}
```
Functions should be defined for logically separate operations. 

# Function definition
Line of code which contains the name, inputs and body of a function. 

# Global scope
Most general scope. Global objects and functions can be used in every part of a program. Elements declared outside of any structure in the program belong to the global scope.

# Header file
File containing the definitions of objects and functions to be used in another program. They are .h files.

# IDE
Integrated development environment. Program which gives you tools to write, compile, link and execute programs easier than on the command line. Some examples are CodeBlocks and VSCode.

# if
Conditional statement whose body (the statement after it, which can be many statements enclosed in brackets) is executed if the condition is logically true. See [else](Glossary.md#else).
```
if(cond){...}
```

# `#include`
Statement that tells the linker to include (link) a file, whose functions and objects can then be used. 

# Increment
Increase of the value of a variable (often of 1 unit.)

# Initialization
Giving a variable a value on its declaration statement. 
```
int a {10}; //brackets initialization
double b = 23.6; // equal sign initialization
```

# Input
Information that a program uses to produce its output [output](Glossary.md#Output). It can come from external sources (e.g.: keyboard, files, other programs etc.) or from other parts of the program.

# Invariant
Condition that must always hold for a program to work. E.g.: for a function that sums positive integers, its inputs must always be positive. Can be used to find errors.
```
int sum_pos(int a, int b)
{
	if(a > 0 || b < 0)    
		error("Wrong arguments) // Invariant check
	
	return a + b;
}
```

# Iteration
Running a section of code many times. It is often used to apply a certain operation over a set of data.

# Library
Sets of code written by other users that we can use in our programs.

# Linker
Program tasked with linking a program in object code with the libraries whose objects and functions it uses.

# Link time error
Error caught by the linker, when it can't find all the linked elements on a given program.

# Logic error
Error type present when the program works but doesn't do what we want. It is not detected automatically and is due to us expressing our ideas wrongly. It's the most diffcult type of error to fix.

# Loop
Programming structure that can run a section of code many times, depending on some logic condition.

# L-value 
Value that a variable takes when it is on the left side of an assignement. It refers to a memory position.
```
v1 = 3;
```

# Magic constant
Specific number that is used inside of a function and whose meaning could be confusing to future readers (that's almost every number used inside functions.) A better practice is to use symbolic constants, which are named, for every non obvious constant we have to use. 
```
weight(double m)
{
	return a * 9.8; // magic constant, what is 9.8??
}

const double earth_gravity = 9.8;
weight(double m)
{
	return m * earth_gravity // proper use
}
```

# `main()`
Function run at the start of any program. Every C++ program must have it. Typically ended by a `return 0` statement to indicate succesful termination.

# Maintenance
Process of making sure that a program continues to work in the future, as changes are made to it or to software with which it interacts.

# Member function
Function belonging to a class. It is called using point notation on an object of the class.
```
vector v1;
v1.push_back(val);
```

# Name
Sequence of characters that designates a particular variable.

# Narrowing
Unsafe conversion in which part of the information is lost due to one data type not being able to hold all the information.
```
double a {1.5};
int b = a;
a = b; // a is now 1, the .5 has been lost
```

# Object
Position(s) of memory with assigned value and data type.

# Object code
Code given by a compiler from source code. It's written in a language that the computer can "understand".

# Operation
Logical or mathematical operation executed on objects.
```
a+b  a==b   a*2
```

# Operator
Symbol used to indicate certain operations. Its meaning depends on the type of object it is used with.  
```
+ - * / ^ and or ! < > >= <= ==
```

# Output
Data that a program or part of it sends (to another program, to a screen, a file etc.). 

# Pass-by-reference
Way of passing arguments to functions in which the function recieves a pointer to a variable and accesses the variable itself.

# Pass-by-value
Way of passing arguments to functions in which the function creates a (local) copy of the argument variable.

# Post-condition
Check done before a function returns its output to check if it is of the required type before returning it.

# Pre-condition
Check done at the start of a function to check if its inputs are of the required type before running it. These two conditions make error detection easier.
```
sum_integers (int a, int b)
{
	if(a < 0 || b < 0) // pre-condition
		error ("Wrong inputs.\n");
	
	...

	if(output < 0) // post-condition
		error ("Wrong output.\n");
}
```

# Program
Set of intstructions susceptible of being run by a digital computer.

# `push_back()`
Member function of the `std::vector` class that pushes an element to the back of the vector, increasing its size by 1.
```
std::vector <int> v1 {1, 2}
v1.push_back(3); //v1 is now {1, 2, 3}
```

# Range error
Error which appears when a non existent container element is called. Typically due to not taking into account that the first element of a vector has index 0.
```
std::cout v1[v1.range()] // range error, the last element is
                         // actually v1[v1.range()-1]
```

# Recovery
Process of keeping a program running as good as it can once an error has occurred. It means handling the errors and keeping the information that can be kept.

# Recursion
When an element, usually a function, can call itself.

# Repetition
Running a section of code many times. Similar to [iteración](Glossary.md#Iteración).

# Requisite
Condition. See [pre-condition](Glossary.md#Pre-condition) and [post-condition](Glossary.md#Post-condition).

# Return value
Value that a function returns to its caller once its execution has ended.

# Revision history
Comment showing who has written and edited a certain program and when each revision has occurred.

# Run time error 
Error that appears once the program is running. They include execution errors and logic errors.

# R-value 
Value that a variable takes when it is on the right side of an assignement. It refers to the value of the variable.
```
2 == v1;
```

# Scaffolding
Code structure to be used generically in many programs. e.g.:
```
int main()
{
	try 
	{
		some_function();
	}
	catch (...)
	{
		std::cerr << "ERROR\n";
	}
}
```

# Selection
Decision structure where one of a number of sections of code can be executed according to the value of a given variable. Similar to if. In C++ it is implemented using [`switch`](Glossary.md#switch) structures.

# `size()`
Member function of `std::vector` which returns its size, or number of elements.

# `sort()`
Standard library function to sort alphanumerically the elements of a vector, or a part of them. Requires `<algorithm>`.
```
#include <algorithm>
std::sort(v1.begin(), v1.end()) // sort from beginning to end
```

# Source code
Code written on a programming language, not yet compiled.

# Statement
Expression ended by a semicolon. It's the building block of programs.

# `switch`
C++ selection structure which compares the value of a variable against a set of constants and executes the code of the constants to which it equals. Don't forget the break statements!
```
switch(var)
{
	case const 1:
		...
		break;  // exit the switch structure
	case const 2:
		...
		break;
	default:  // if var matches none of the constants
		...
		break;
}
```

# Symbolic constant
Variable with a constant value.

# Syntax error
Error caused by not writing the code according to the C++ syntax rules. Detectable by the compiler.
```
std::cout << "Hola" // missing ;
int a = 10
	b = 10
	c = 10; // missing commas
```

# Testing
Entering inputs into a program to check if it works how it should. For professional software, this should be done systematically and with a large amount of inputs, for which testing programs are used. Testing and [debugging](Glossary.md#Debugging) are the two techniques used to solve programming errors. 

# `throw` 
Function that can throw errors when called inside the body of a [`try()`](Glossary.md#Exception).

# Type
Data type of a given [object](#Object). It determines how the information it contains is interpreted by the computer, as well as the operations that you can do to it. 

# Type error
Error caused by using an object in a way incompatible with its type.
```
std::string s = 10; //can't asign number to string
double d = "Hola."; //can't assign characters to a double
```

# Type safety
Way of programming where each variable is handeled according to its type, so as to avoid narrowing.

# Value
Information that an [object](#Object) contains.

# Variable
Named object.

# `vector` 
C++ standard library class used to create and manipulate single type containers. Requires `#include <vector>` 

# `while`
C++ loop structure whose body is ran while the condition of its heading, which is checked every time the loop starts, is true. It is important to have an exit condition in some form or another, or else you can end with an infinite loop. 
```
while(cond)
{...}
```
