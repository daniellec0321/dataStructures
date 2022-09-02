# Author: Danielle Croft
# E-mail: dcroft@nd.edu
# File name: Makefile
# Date created: 1/24/22
# File contents: This is the Makefile for Programming Challenge 2

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
	mkdir $(OBJ) $(EXE)

# on make, create object file for sllist.c in objects folder (Singly Linked List Object)
$(OBJ)/life.o: $(SRC)/life.c
	$(PP) $(CFLAGS) -c $(SRC)/life.c -o $@

# on make, create object file for PC01.c in objects folder
$(OBJ)/PC02.o: $(SRC)/PC02.c
	$(PP) $(CFLAGS) -c $(SRC)/PC02.c -o $@

# Create variable for all objects
PC02_objs := $(OBJ)/life.o $(OBJ)/PC02.o

# Singly Linked List Executable and Run
PC02: $(PC02_objs)
	$(PP) $(CFLAGS) -o $(EXE)/PC02 $(PC02_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
