/*
---
UNIT 1 DRILL
[1] Figure out how to compile and run a program on your machine. This
may be a good time to get a bit of help from someone who has done
that before.
[2] If you use an IDE, set up an empty console C++ project called
hello_world. Otherwise, if you plan to use the command line, get a
command window, figure out how to use an editor to type in your
code, and see §0.3.1.
[3] Type in hello_world.cpp, exactly as specified below, save it in your
practice directory (folder), and include it in your hello_world project.

import std;
int main()
// C++ programs start by executing the function main
{
std::cout << "Hello, World!\n";
// output "Hello, World!"
}

What if you don’t have an up-to-date C++ implementation that
supports module std? Then, use a less elegant and less efficient
technique that has worked since the early days of C: #include a header
file as is explained in §7.7.2:

#include<iostream>
int main()
// C++ programs start by executing the function main
{
std::cout << "Hello, World!\n";
// output "Hello, World!"
}

[4] Compile and run the “Hello, World!” program. An IDE will have a
compile-and-run button. Even something as simple as “Hello,
World!” very rarely compiles and runs in a first attempt to use a new
programming language or a new programming environment.
Find the problem and fix it! This is a point where asking for help from
a more experienced person is sensible, but be sure to understand what
you are shown so that you can do it all by yourself before proceeding
further.
[5] By now, you have probably encountered some errors and had to
correct them. Now is the time to get a bit better acquainted with your
compiler’s error-detection and error-reporting facilities! Try the eight
programs from §1.3 to see how your programming environment
reacts. Think of at least five more errors you might have made typing
in your program (e.g., leave the Caps Lock key on while typing a
word, or type a comma instead of a semicolon) and try each to see
what happens when you try to compile and run those versions.
*/

#include <iostream>

int main()
// C++ programs start by executing the function main
{
    std::cout << "Hello, World!\n";
    // output "Hello, World!"
}