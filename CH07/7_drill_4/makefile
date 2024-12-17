all: run.out

run.out: use.o foo.o
	g++ -o run.out use.o foo.o

use.o: use.cpp
	g++ -c -Wall -Wextra -g use.cpp

foo.o: foo.cpp
	g++ -c -Wall -Wextra -g foo.cpp

clean:
	rm use.o foo.o run.out
