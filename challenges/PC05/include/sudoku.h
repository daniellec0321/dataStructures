/* Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: sudoku.h
 * Date created: 2/23/22
 * File contents: These are the function declarations for PC05 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

#define ROWS 9
#define COLS 9
#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define VECTOR std::vector
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream

// prints a greeting to the user
void greeting(void);

// fills a vector with zeroes
void fill_vector(VECTOR< VECTOR<int> >& sudoku);

// reads a file and creates sudoku board
void populate_puzzle(IFSTREAM& sudoku_infile, VECTOR< VECTOR<int> >& sudoku);

// prints a given sudoku puzzle to the terminal
void print_puzzle(const VECTOR< VECTOR<int> >& sudoku);

// updates a value at the puzzle
void update_puzzle(VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row, long unsigned int col);

// checking if a number can be placed in a certain spot
bool check_guess(const VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row, long unsigned int col);

// check if a puzzle is complete or not
bool check_puzzle(const VECTOR< VECTOR<int> >& sudoku);

// solves puzzle recursively
bool recursive_solver(VECTOR< VECTOR<int> >& sudoku, long unsigned int row, long unsigned int col);

// print a puzzle to a file
void print_puzzle_to_file(OFSTREAM& sudoku_outfile, const VECTOR< VECTOR<int> >& sudoku);

#endif
