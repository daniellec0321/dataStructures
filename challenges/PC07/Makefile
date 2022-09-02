# Author: Danielle Croft
# E-mail: matt.morrison@nd.edu
# File name: Makefile
# Date created: 3/22/22
# File contents: the makefile for PC07

# g++ is for the GCC compiler for C++
CC := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 $(FLAGS)

# Folder Variables
INC := include
SRC := src
OBJ := objects
EXE := exe

# Make initialize - Create the objects and executables

initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)


# Run Compilation Command
# Command: make PC07

$(OBJ)/passcode.o: $(SRC)/passcode.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/passcode.cpp -o $@
	
$(OBJ)/PC07.o: $(SRC)/PC07.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/PC07.cpp -o $@

PC07Objs :=  $(OBJ)/PC07.o $(OBJ)/passcode.o

PC07: $(initialize) $(PC07Objs)
	$(CC) $(CXXFLAGS) -o $(EXE)/PC07 $(PC07Objs)
	

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
