output: main.o Project.o
	g++ -std=c++11 -o output main.o Project.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Project.o: Project.h Project.cpp
	g++ -std=c++11 -c Project.cpp

clean:
	rm output main.o Project.o