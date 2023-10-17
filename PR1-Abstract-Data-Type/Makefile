output: main.o List.o
	g++ -std=c++11 -o output main.o List.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

List.o: List.h List.cpp
	g++ -std=c++11 -c List.cpp

clean:
	rm output main.o List.o