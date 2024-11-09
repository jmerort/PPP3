Here are my definitions of some important C++ terms.   
# //
Indicates a comment from the sign to the end of the line.

# <<
Output operator. It is used with output streams to print data on screen or store it in a file. 

# Abstraction
The act of leaving out of a model (mathematical, physical, mental etc.) the elements deemed unnecessary for a particular goal, leaving only the essentials. In programming, it involves hiding the implementation details of a particular application, giving the user instead a simple interface through which they can use it.

# Asesrtion
Statement that affirms an [Invariant](glossary.md#Invariant).

# Assignment
Giving a value to an already created variable, removing the previous one.

# begin()
Method of the std::vector class which returns its first element.

# Loop
Programming structure that can run a section of code many times, depending on some logic condition.

# C++
Object-oriented programming language developed by Bjarne Stroustrup. More complex than most, it offers a very good performance and is widely used in many areas.

# Header
File containing the definitions of objects and functions to be used in another program. They are .h files.

# catch
Structure indicating the code that is to be executed if a particular type of error is thrown by the try{} section.
```
try{
	función();
}
catch{   // Ejecutado si la función lanza un error. 
	... 
}
```

# cin
Character input stream. Used to give inputs to a program through the keyboard.

# Source code
Code written on a programming language, not yet compiles.

# Código objeto
Code given by a compiler from source code. It's written in a language that the computer can "understand".

# Comment
Part of a program which is ignored by the compiler and is written so that future human readers (including the author him/herself) may better understand what the program is supposed to do. 

# Compiler
Program tasked with translating other programs from source code to object code. The most popular for C++ is GCC (Gnu Compiler Collection), and is called by invoking "g++" in the command line. 

# Computation
Process of getting an output from an input.

# Concatenation
Putting one value immediately after another to create a new one. Can be done with strings.
```
"Hola" + "Adios" = "HolaAdios"
```

# Container
Structure that can hold many objects. In C++ the most popular container is [vector](glossary.md#vector).

# Conversion
Change of an object's type. There are safe conversion (those whose final type can contain all the information of the original type) and unsafe ones (those where some information is lost.) See [narrowing](glossary.md#Narrowing).
```
int a = 2.5 / 1 //conversion of double 1.25 to int 1
``` 

# cout
Character output stream. Used in conjunction with [<<](glossary.md#<<)

# Debugging
Process of finding and fixing software errors (or bugs) in a program. It is rather tedious, so our code should be structured in such a way as to minimize the time spent on it.

# Declaration
Statement that gives name to an object or function.

# Decrement
Decrease of the value of a variable (often of 1 unit.)

# Definition
Declaration that saves memory for a given object. When talking about funcions, it refers to the code which contains its name, inputs and body. 

# Divide and conquer
Methodology which consists of divinding big problems into many smaller solutions. In programming, this means making programs out of many interconnected programs and functions.

# Executable
Final form of a program, once it has been compiled and linked. It can be executed by a computer. 

# else
indicates the statement to be executed if the condition of a preceeding if is false.
```
if(cond){...} else{...}
```

# end()
Method of std::vector that returns its last element.
```
v1.end();
```

# Linker
Program tasked with linking a program in object code with the libraries whose objects and functions it uses.
![[Pasted image 20241017092308.png]]

# Input
Information that a program uses to produce its output [output](glossary.md#Output). It can come from external sources (e.g.: keyboard, files, other programs etc.) or from other parts of the program.

# Statement
Expression ended by a semicolon. It is the building block of programs.

# Conditional statement
Statement that alters the flow of execution of a program based on a given logical condition.

# Error 
Element of a program that causes it not to work. It includes everything from software errors to hardware or human errors. Depending on how reliable we need our program to be, we will take into account more or less errors.
To reduce the amount of errors on our programs, we can follow these steps:
1) Structure the code in such a way as to minimize mistakes, including tests, separating different functions and so on.
2) Fix the errors that have occurred through debugging and testing.
3) Make sure the remaining errors are not significant.

# Argument error
Error which appears when a function is called using a different set of arguments from those for which it has been defined. Found by the compiler.

# Range error
Error which appears when a non existent container element is called. Typically due to not taking into account that the first element of a vector has index 0.
```
std::cout v1[v1.range()] // range error, the last element is
                         // actually v1[v1.range()-1]
```

# Syntax error
Error caused by not writing the code according to the C++ syntax rules. Detectable by the compiler.
```
std::cout << "Hola" // missing ;
int a = 10
	b = 10
	c = 10; // missing commas
```

# Compile time error
Error caught by the compiler. They can be syntax or type errors.

# Link time error
Error caught by the linker, when it can't find all the linked elements on a given program.

# Run time error 
Error that appears once the program is running. They include execution errors and logic errors.

# Type error
Error caused by using an object in a way incompatible with its type.
```
std::string s = 10; //can't asign number to string
double d = "Hola."; //can't assign characters to a double
```

# Logic error
Error type present when the program works but doesn't do what we want. It is not detected automatically and is due to us expressing our ideas wrongly. It's the most diffcult type of error to fix.

# Excepction
C++ mechanism of dealing with errors that separates error detection (to be done in the called function) from error handling (to be done in the called function). It consists of a structure with the functions try(), throw() and catch().
```
try {
    ...
    throw(error_1) // if an erro occurs, the try function can throw it
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

# for
Loop statement with all its control information contained in its header. In the first position of it, the control variable is designated (often declared and initialized); in the second, the exit condition, which, when no longer true, makes the loop end; in the third, a statement to be executed every time the loop ends, typically used to modify the value of the control variable.
```
for (int i = 0; i < val; i++){body}
```

# Function
Named sequence of statements, characterized by these four elements:
```
type indentifier (parameters) {body}
```
Functions should be defined for locically separate operations. 

# Member function
Function belonging to a class. It is called using point notation on an object of the class.
```
vector v1;
v1.push_back(val);
```

# IDE
Integrated development environment. Program which gives you tools to write, compile, link and execute programs easier than on the command line. Some examples are CodeBlocks and VSCode.

# if
Conditional statement whose body (the statement after it, which can be many statements enclosed in brackets) is executed if the condition is logically true. See [else](glossary.md#else).
```
if(cond){...}
```

# \#include
Statement that tells the linker to include (link) a file, whose functions and objects can then be used. 

# Increment
Increase of the value of a variable (often of 1 unit.)

# Initialization
Giving a variable a value on its declaration statement. 
```
int a {10}; //brackets initialization
double b = 23.6; // equal sign initialization
```

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

# L-value 
Value that a variable takes when it is on the left side of an assignement. It refers to a memory position.
```
v1 = 3;
```

# main()
Function run at the start of any program. Every C++ program must have it. Typically ended by a `return 0 statement` to indicate succesful termination.

# Narrowing
Unsafe conversion in which part of the information is lost due to one data type not being able to hold all the information.
```
double a {1.5};
int b = a;
a = b; // a is now 1, the .5 has been lost
```

# Name
Sequence of characters that designates a particular variable.

# Object
(consecutive) Positions of memory with a given value and data type.

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

# push_back()
Member function of the std::vector class that pushes an element to the back of the vector, increasing its size by 1.
```
std::vector <int> v1 {1, 2}
v1.push_back(3); //v1 is now {1, 2, 3}
```

# Repetition
Running a section of code many times. Similar to [iteración](glossary.md#Iteración).

# Requisite
Condition. See [pre-condition](glossary.md#Pre-condition) and [post-condition](glossary.md#Post-condition).

# R-value 
Value that a variable takes when it is on the right side of an assignement. It refers to the value of the variable.
```
2 == v1;
```

# Output
Data that a program or part of it sends (to another program, to a screen, a file etc.). 

# Type safety
Way of programming where each variable is handeled according to its type, so as to avoid narrowing.

# Selection
Decision structure where one of a number of sections of code can be executed according to the value of a given variable. Similar to if. In C++ it is implemented using [switch](glossary.md#switch) structures.

# size()
Member function of std::vector which returns its size, or number of elements.

# sort()
Standard library function to sort alphanumerically the elements of a vector, or a part of them. Requires `<algorithm>`.
```
#include <algorithm>
std::sort(v1.begin(), v1.end()) // sort from beginning to end
```

# switch
C++ selection structure which compares the value of a variable against a set of constants and executes the code of the constants to which it equals. Don't forget the break; statements!
```
switch(var)
{
	case const 1:
		...
		break;  // salir de la estructura
	case const 2:
		...
		break;
	default:  // if var matches none of the constants
		...
		break;
}
```

# Testing
Entering inputs into a program to check if it works how it should. For professional software, this should be done systematically and with a large amount of inputs, for which testing programs are used. Testing and debugging [debugging](glossary.md#Debugging) are the two techniques used to solve programming errors. 

# Throw 
Function that can throw errors when called inside the body of a [try()](glossary.md#Exceptiin).

# Tipo
Data type of a given object. It determines how the information it contains is interpreted by the computer, as well as the operations that you can do to it. 

# Value
Information that a given object contains.

# Variable
Named object.

# Vector 
C++ standard library class used to create and manipulate single type containers. Requires `#include <vector>` 

# While
C++ loop structure whose body is ran while the condition of its heading, which is checked every time the loop starts, is true. It is important to have an exit condition in some form or another, or else you can end with an infinite loop. 
```
while(cond)
{...}
```
