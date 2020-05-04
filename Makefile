CXX := g++
CXXFLAGS := -g -Wall -std=c++17
VPATH := sourceFiles

OBJS := main.o			\
	binaryTreeSort.o	\
	queueSort.o

main:			$(OBJS)
			$(CXX) $^ -o $@

clean:
			rm -f *.o *~ *.gch main

#dependencies;
main.o:			main.cpp binaryTreeSort.hh queueSort.hh DLinkedList.hh
binaryTreeSort.o:	binaryTreeSort.cpp binaryTreeSort.hh
queueSort.o:		queueSort.cpp queueSort.hh
