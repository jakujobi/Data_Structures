# FILEPATH: c:\Users\akujo_2rtofyy\OneDrive - South Dakota State University - SDSU\#SDSU Courses\CSC 300 - Data Structures\Data_Structures\PR 1 - Abstract Data Type\Makefile

# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

# Source files
SRCS = main.cpp List.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
EXEC = program

all: $(EXEC)

$(EXEC): $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(EXEC)