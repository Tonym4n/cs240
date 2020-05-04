CXX = g++
CXXFLAGS = -g -Wall -std=c++17

OBJS =	main.o			\
	binaryTreeSort.o	\
	queueSort.o	\
	DLinkedList.o

main:			$(OBJS)
			$(CXX) $^ -o $@

clean:
			rm -f *~ *.gch $(OBJS) main

#dependencies;
main.o:			main.cpp binaryTreeSort.hh queueSort.hh DLinkedList.hh
binaryTreeSort.o:	binaryTreeSort.cpp binaryTreeSort.hh
queueSort.o:		queueSort.cpp queueSort.hh
DLinkedList.o:		DLinkedList.hh
