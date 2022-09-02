# Author: Danielle Croft
# E-mail: dcroft@nd.edu
# File name: Makefile
# Date Created: 2/17/22
# File contents: This is the Makefile for Programming Challenge 04

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

# on make, create object file for game.cpp in objects folder (Singly Linked List Object)
$(OBJ)/game.o: $(SRC)/game.cpp $(INC)/game.h
	$(CC) $(CXXFLAGS) -c $(SRC)/game.cpp -o $@

# on make, create object file for PC04.cpp in objects folder
$(OBJ)/PC04.o: $(SRC)/PC04.cpp $(INC)/game.h
	$(CC) $(CXXFLAGS) -c $(SRC)/PC04.cpp -o $@

# Create variables for all objects
PC04_objs := $(OBJ)/game.o $(OBJ)/PC04.o

# Singly Linked List Executable and Run
PC04: $(PC04_objs)
	$(CC) $(CXXFLAGS) -o $(EXE)/PC04 $(PC04_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*


