# PPP3
As I work my way through Bjarne Stroustrup's Programming Principles and Practice using C++ (3rd ed.), I will be uploading here the code I write as I do the excercises and drills. Now that I'm out of college and have more time on my hands, I can devote some of it to programming and, as I've always liked C++, I think now is a good time to improve my skills and learn more about it. I also want to get more comfortable using GitHub, so sharing my code here may help me with that, as well as force me to keep the code somewhat organized and readable.


I will try to do most if not all of the excercises, drills and "try this" sections of the book, and I might upload here some notes and definitions, if I happen to write them. How far I go into the book, time will tell.


I'm not a professional programmer, and my education is as an engineer, so these are not expert solutions or anything of the sort, though I hope they'll get better as I continue to program.


## About my programs

I prefer not to use the `PPP3.h` file or any other specific files, so I import the necessary libraries. I also do not use namespace std, as I always read people warning against it. This also means i don't use the `error()` function, throwing instead `runtime_error`s and catching them accordingly.


## How to compile and run the files

I use gcc version 12.2.0 (Debian 12.2.0-14) as a compiler for these files, and compile them with this command:
```
g++ -o run file.cpp -Wall -Wextra -g -std=c++20
```

If there is more than one file in the program I use the following commands:
- To compile the source files:
```
g++ -c main_file.cpp [additional_files.cpp] -Wall -Wextra -g -std=c++20
```
- To create the executable from the object files:
```
g++ -o run main_file.o [additional_files.o] -std=c++20
```

I try to make each excercise as self-contained as reasonable; therefore, if there are many files per program, I create a folder and put them all there, next to the "main file".


## Licensing
These are very simple educational programs, not meant for commercial or otherwise professional use. If anybody wishes to use them or parts of them in their programs, they are free to do so, as the MIT license says.