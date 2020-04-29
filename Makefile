CXX = g++
CXXFLAGS = -g -Wall -std=c++17

OBJS =	main.o		\
	binaryTreeSort.o

main:			$(OBJS)
			$(CXX) $^ -o $@

clean:
			rm -f *~ *.gch $(OBJS) main

#dependencies;
main.o:			main.cpp binaryTreeSort.hh
binaryTreeSort.o:	binaryTreeSort.cpp binaryTreeSort.hh
