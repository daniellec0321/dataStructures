# Author: Danielle Croft
# E-mail: dcroft@nd.edu
# File name: Makefile
# Date Created: 2/23/22
# File contents: This is the Makefile for Programming Challenge 05

# g++ is for the GCC compiler for C++
CC := g++

# CFLAGS are the compiler flags for when we compile C++ code in this course
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

# on make, create object file for sudoku.cpp in objects folder (Singly Linked List Object)
$(OBJ)/sudoku.o: $(SRC)/sudoku.cpp $(INC)/sudoku.h
	$(CC) $(CXXFLAGS) -c $(SRC)/sudoku.cpp -o $@

# on make, create object file for PC05.cpp in objects folder
$(OBJ)/PC05.o: $(SRC)/PC05.cpp $(INC)/sudoku.h
	$(CC) $(CXXFLAGS) -c $(SRC)/PC05.cpp -o $@

# Create variables for all objects
PC05_objs := $(OBJ)/sudoku.o $(OBJ)/PC05.o

# Singly Linked List Executable and Run
PC05: $(PC05_objs)
	$(CC) $(CXXFLAGS) -o $(EXE)/PC05 $(PC05_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*


