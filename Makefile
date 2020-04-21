main:			main.o binaryTreeSort.o
			g++ -g -Wall -std=c++17 main.o binaryTreeSort.o -o main

main.o:			main.cpp
			g++ -g -Wall -std=c++17 -c main.cpp

binaryTreeSort.o:	binaryTreeSort.cpp binaryTreeSort.hh
			g++ -g -Wall -std=c++17 -c binaryTreeSort.cpp binaryTreeSort.hh

clean:
			rm -f *~ *.o *.gch main
