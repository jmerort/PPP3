# UNIT 7 REVIEW

**[1] What is the difference between a declaration and a definition?**
A declaration is a statement that introduces a name into a scope, if it also fully specifies the entity declares it is also a definition. All definitions are thus technically also declarations, but the word declaration is normally used to imply one that is not a definition.

**[2] How do we syntactically distinguish between a function declaration and
a function definition?**
A function declaration has no body and ends with a semicolon, whereas a function definition has a body.

**[3] How do we syntactically distinguish between a variable declaration and a variable definition?**
A variable definition gives the variable a value as well as a name.

**[4] Why can't you use the functions in the calculator program from Chapter
5 without declaring one or more of them first?**
Because they call each other forming a loop, so at least one not yet declared function would be called if we didn't declare it earlier.

**[5] Is int a; a definition or just a declaration?**
It's (just) a declaration.

**[6] Why is it a good idea to initialize variables as they are declared?**
Because if you mistakenly use them before they have a value assigned to them, you will be using the garbage values they have by default, which can make the progrma behave differently on different systems (which is more dangerous than just functioning wrong).

**[7] What can a function declaration consist of?**
A return type, an identifier (name) and the number and types of input variables(if they exist).

**[8] What is the suffix return type notation, and why might you use it?**
It's a way of putting the return type of a function at the end. It might make our code easier to read in some cases, for instance:
```
auto Token_stream::get() -> Token
``` 

**[9] What good does indentation do?**
Indentation does nothing for the compiler in C++; however, properly indented code is significantly easier to read. 

**[10] What is the scope of a declaration?**
The part of a program in which a variable can be used. Once the program execution goes out of a given scope, the variables defined inside of that scope (called local variables) are destroyed.

**[11] What kinds of scope are there? Give an example of each.**
- Global scope: variables defined outside of a function (typically at the top of the program) can be used in any scope. 
- Module scope: area of text within a module.
- Namespace scope: named scope nested in the global scope or in another namespace.
- Class scope: Within a class
- Local scope: Between the braces of a block of code or in a function argument list.
- Statent scope: Inside a for- if- etc. statement.

**[12] What is the difference between a class scope and local scope?**

**[13] Why should a programmer minimize the number of global variables?**

**[14] What is the difference between pass-by-value and pass-by-reference?**

**[15] What is the difference between pass-by-reference and pass-by-const-reference?**

**[16] What is a swap()?**
**[17] Would you ever define a function with a vector<double> as a by-value
parameter?**
**[18] Give an example of undefined order of evaluation. Why can undefined
order of evaluation be a problem?**
**[19] What do x&&y and x||y, respectively, mean?**
**[20] Which of the following is standard-conforming C++: functions within
functions, functions within classes, classes within classes, classes within
functions?**
**[21] What goes into an activation record?**
**[22] What is a call stack and why do we need one?**
**[23] What is the purpose of a namespace?**
**[24] How does a namespace differ from a class?**
**[25] What is a using declaration?**
**[26] Why should you avoid using directives in a header?**
**[27] What is namespace std?**

