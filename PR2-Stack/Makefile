output: main.o Stack.o
	g++ -std=c++11 -o output main.o Stack.o

main.o: main.cpp 
	g++ -std=c++11 -c main.cpp

Stack.o: Stack.h Stack.cpp 
	g++ -std=c++11 -c Stack.cpp

clean:
	rm output main.o Stack.o