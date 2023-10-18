CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Queue.o
EXEC = output

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)
# output: main.o Queue.o
# 	g++ -std=c++11 -o output main.o Queue.o
#
# main.o: main.cpp
# 	g++ -std=c++11 -c main.cpp
#
# Queue.o: Queue.h Queue.cpp
# 	g++ -std=c++11 -c Queue.cpp
#
# clean:
# 	rm output main.o Queue.o