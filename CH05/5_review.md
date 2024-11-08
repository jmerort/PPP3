# UNIT 5 REVIEW

**[1] What do we mean by “Programming is understanding”?**

Programming consist of expressing a problem in terms a computer can understand, which involves a very rigorous formulation of each step of the problem. Thus, unless we have a good understanding of the problem we want a computer to solve, we won't be able to express it properly. It can go both ways, however, because programming usually forces us to be more rigorous in our thought, as we see our half-baked ideas repeatedly fail.


**[2] The chapter details the creation of a calculator program. Write a short analysis of what the calculator should be able to do.**

The calculator program should take as (keyboard) input arithmetic expressions composed of rational positive numbers, the operators +, -, * and /, and parentheses. If an expression is followed by "=", its result (which ought to be correct according to the rules of basic arithmetic) should be output on the screen. Entering the exit character or any invalid inputs should cause the program to end. 

**[3] How do you break a problem up into smaller manageable parts?**

By first seeing everything we need to do, then isolating the sections that can be dealt with in a separate manner, taking into account the information they should send and recieve to and from other parts of the program. Then solving each of the problems independently, which usually involves creating different functions and classes.

**[4] Why is creating a small, limited version of a program a good idea?**

Because it's less likely to fail and because it will take a significantly smaller amount of time to get to run and debug. Code complexity scales non linearly with its length, so it's almost always a good idea to develop a limited version, to have a sctructure (something we know already works) around which to build. Also, we probably don't even understand the problem we are dealing with until we have tried to solve it, so the understanding we get by developing prototypes will help us design the final product.

**[5] Why is feature creep a bad idea?**

Because it can increase the development time tremendously for functions that are often unnecessary or that can be added with much less effort once our program is working. It also makes us more prone to adding even more non-essential functions in the future.

**[6] What are the three main phases of software development?**

Analysis, design and implementation.

**[7] What is a “use case”?**

A use case is an informal definition of what a program should minimally do, used in the analysis and design phases.

**[8] What is the purpose of testing?**

Checking if a program works and, in case it doesn't, figuring out likely causes of error (this is more doable the better testing our program has.)

**[9] According to the outline in the chapter, describe the difference between a Term, an Expression, a Number, and a Primary.**

An expression is a term or another expression plus or minus a term.
A term is a primary or another term multiplied, divided or module-d by a primary.
A primary is a number or an expression enclosed in parentheses.
A number is just a floating point number.

**[10] In the chapter, an input was broken down into its components: Terms, Expressions, Primarys, and Numbers. Do this for (17+4)/(5−1).**

(17+4)/(5-1) = term
(17+4)/(5-1) = term / term


(17+4) = term 
(17+4) = primary 
(17+4) = "("expression")" 
17+4 = expression + term 

17 = term 
17 = primary 
17 = number 
17 = fp literal 
4 = primary 
4 = number 
4 = fp literal 

(5-1) = term
(5-1) = primary
(5-1) = "("expression")"
5-1 = expression - term

5 = term 
5 = primary 
5 = number 
5 = fp literal
1 = primary
1 = number
1 = fp literal

**[11] Why does the program not have a function called number()?**

Because the C++ standary library already provides ways to read numbers that suit our purposes.

**[12] What is a token?**

A sequence of characters that represents something we consider a unit.

**[13] What is a grammar? A grammar rule?**

A series of rules describing how the computer should interpret series of tokens. A grammar rule is a single rule in a gramar, defining a type of entity, like an expression or a number in our case.

**[14] What is a class? What do we use classes for?**

A type of object with it's own attributes (information that it can store) and methods (functions that work with it.) Depending of how we want to represent certain information, we shall use one class of objects or another (e.g.: string for words, int for integers etc.)

**[15] How can we provide a default value for a member of a class?**

By defining a constructor with default values e.g.:
    Token():kind('x'), value(0) { } //the default values for the attributes are 'x' and 0

**[16] In the expression function, why is the default for the switch-statement to “put back” the token?**

Because if you don't put it back, the information is lost and the next token is read, skipping the current one.

**[17] What is “look-ahead”?**

For a program to act in such a way that is congruent with the next characters of the line it is reading. For instance, if our calculator is to process 2 + 1 * 3, it should multiply the 1 and 3 first instead of summing 2 and 1, even if they are first in line. 

**[18] What does putback() do and why is it useful?**

It puts a token back into the token stream. It works so as not to lose any information in certain cases, like the one described in [16].

**[19] Why is the remainder (modulus) operation, %, difficult to implement in the term()?**

Because we are working with floating point numbers, for which the modulus operatioon is not defined. 

**[20] What do we use the two data members of the Token class for?**

One for storing the type of token it is (+, -, (, number etc.) and another to store the value, in case it's a number.

**[21] Why do we (sometimes) split a class’s members into private and public members?**

To hide the implementation details from the user, making sure they don't manipulate objects in wrong ways, providing instead an interface they can use.

**[22] What happens in the Token_stream class when there is a token in the buffer and the get() function is called?**

The token in the buffer is returmed.

**[23] Why were the ';' and 'q' characters added to the switch-statement in the get() function of the Token_stream class?**

Because those characters are used (elsewhere) to print output and to stop the program.

**[24] When should we start testing our program?**

As soon as we can, to make sure the individual pieces of code we are building actually work, and we don't mesh together a bunch of faulty code which would then be much harder to debug.

**[25] What is a “user-defined type”? Why would we want one?**

A type of object with it's own attributes (information that it can store) and methods (functions that work with it.) We use classes when the types of information we want to handle in our program are too specific for the standard C++ classes. 

**[26] What is the interface to a C++ “user-defined type”?**

A class of obejct that is not one of the C++ basic types (int, double, bool, char...) It can come in a library or be written by us.

**[27] Why do we want to rely on libraries of code?**

To save us the time to implement something which someone else has already done, often much better than us.
