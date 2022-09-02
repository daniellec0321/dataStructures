# Author: Danielle Croft
# E-mail: dcroft@nd.edu
# File name: Makefile
# Date created: 2/11/22
# File contents: This is the Makefile for Programming Challenge 3

# gcc is the compiler for C
PP := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe

# Initialize the folders for the objects and executables
initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

# on make, create object file for fenwick.c in objects folder (Singly Linked List Object)
$(OBJ)/fenwick.o: $(SRC)/fenwick.c $(INC)/fenwick.h
	$(PP) $(CFLAGS) -c $(SRC)/fenwick.c -o $@

# on make, create object file for PC03.c in objects folder
$(OBJ)/PC03.o: $(SRC)/PC03.c $(INC)/fenwick.h
	$(PP) $(CFLAGS) -c $(SRC)/PC03.c -o $@

# Create variable for all objects
PC03_objs := $(OBJ)/fenwick.o $(OBJ)/PC03.o

# Singly Linked List Executable and Run
PC03: $(PC03_objs)
	$(PP) $(CFLAGS) -o $(EXE)/PC03 $(PC03_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
