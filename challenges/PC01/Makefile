# Author: Danielle Croft
# E-mail: dcroft@nd.edu
# File name: Makefile
# Date created: 1/19/22
# File contents: This is the Makefile for Programming Challenge 1

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
$(OBJ)/rotations.o: $(SRC)/rotations.c
	$(PP) $(CFLAGS) -c $(SRC)/rotations.c -o $@

# on make, create object file for PC01.c in objects folder
$(OBJ)/PC01.o: $(SRC)/PC01.c
	$(PP) $(CFLAGS) -c $(SRC)/PC01.c -o $@

# Create variable for all objects
PC01_objs := $(OBJ)/rotations.o $(OBJ)/PC01.o

# Singly Linked List Executable and Run
PC01: $(PC01_objs)
	$(PP) $(CFLAGS) -o $(EXE)/PC01 $(PC01_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
