output: main.o BST.o
	g++ -std=c++11 -o output main.o BST.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

BST.o: BST.h BST.cpp
	g++ -std=c++11 -c BST.cpp

clean:
	rm output main.o BST.o