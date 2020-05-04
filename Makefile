CXX := g++
CXXFLAGS := -g -Wall -std=c++17
VPATH := . src

OBJS := main.o			\
	binaryTreeSort.o	\
	queueSort.o

main:			$(OBJS)
			$(CXX) $^ -o $@

clean:
			rm -f *.o *~ *.gch main

#dependencies;
main.o:			binaryTreeSort.hh queueSort.hh DLinkedList.hh
binaryTreeSort.o:	binaryTreeSort.hh
queueSort.o:		queueSort.hh
