main:	main.cpp
	g++ -g -Wall -std=c++17 main.cpp -o main

clean:
	rm -f *~ *.o *.gch main
