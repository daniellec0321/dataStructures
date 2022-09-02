/* Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: sudoku.cpp
 * Date Created: 2/23/22
 * File contents: These are the function definitions for PC05 */



#include "../include/sudoku.h"



// prints a greeting to the user
void greeting(void)
{
	COUT << "Welcome to the sudoku solver!" << ENDL;
	return;
}



// fill an empty vector with zeroes
void fill_vector(VECTOR< VECTOR<int> >& sudoku)
{
	// initializing iteration variables
	int row, column;

	// iterating through vector
	for (row=0; row<ROWS; row++) {
		// creating inner vector
		VECTOR<int> vtemp;
		for (column=0; column<COLS; column++) {
			// placing the zero
			vtemp.push_back(0);
		}
		// placing vector into vector array
		sudoku.push_back(vtemp);
	}

	return;
}



// reads a file stream and creates the sudoku board
void populate_puzzle(IFSTREAM& sudoku_infile, VECTOR< VECTOR<int> >& sudoku)
{
	// setting temporary readers
	std::string temp_str;

	// row and column iterators
	int row = 0;
	int col = 0;

	// while loop to read file stream
	while (sudoku_infile >> temp_str) {
		// putting the number in the vector
		sudoku.at(row).at(col) = stoi(temp_str);

		// iterating column
		col++;

		// if at end of row
		if (col >= COLS) {
			col = 0;
			row++;
		}

		// if at end of file
		if (row >= ROWS) {
			break;
		}
	}

	// closing file stream
	sudoku_infile.close();

	return;
}



// print a given sudoku puzzle to the terminal
void print_puzzle(const VECTOR< VECTOR<int> >& sudoku)
{
	// iterators
	int row, col;

	// for loop to print sudoku board
	for (row=0; row<ROWS; row++) {
		for (col=0; col<COLS; col++) {
			// printing the number and whitespace
			COUT << sudoku.at(row).at(col) << " ";
		}
		// printing newline
		COUT << ENDL;
	}

	return;
}



// updates a value in the puzzle
void update_puzzle(VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row, long unsigned int col)
{
	// setting the value
	sudoku.at(row).at(col) = value;

	return;
}



// checks if a number can be placed in a certain spot
bool check_guess(const VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row, long unsigned int col)
{
	// indexes for checking row and column
	long unsigned int curr_row, curr_col;
	
	// checking row
	for (curr_row=0; curr_row<ROWS; curr_row++) {
		// making sure we're not at original placement
		if (curr_row==row) continue;

		// checking that this is a valid placement
		if (sudoku.at(curr_row).at(col) == value) return false;
	}

	// checking column
	for (curr_col=0; curr_col<COLS; curr_col++) {
		// making sure we're not at original placement
		if (curr_col==col) continue;

		// checking that this is a valid placement
		if (sudoku.at(row).at(curr_col) == value) return false;
	}

	// finding where to start row and col for checking the boxes
	curr_row = row - (row%3);
	curr_col = col - (col%3);

	// have to check 9 boxes, loop total of nine times
	int i, j;
	for (i=0; i<ROWS/3; i++) {
		for (j=0; j<COLS/3; j++) {
			// check if this spot is the original; if it is, skip
			if (!((curr_row == row) && (curr_col == col))) {
				// check if this spot equals the value
				if (sudoku.at(curr_row).at(curr_col) == value) return false;
			}

			// iterate column
			curr_col++;
		}
		// reset column and iterate row
		curr_col -= 3;
		curr_row++;
	}
	
	// if no problems encountered, return true
	return true;
}



// checks if a puzzle is complete
bool check_puzzle(const VECTOR< VECTOR<int> >& sudoku)
{
	// iterating through puzzle
	int row, col;

	for (row=0; row<ROWS; row++) {
		for (col=0; col<COLS; col++) {
			// if zero encountered, return false
			if (sudoku.at(row).at(col) == 0) return false;
		}
	}

	// if no problems encountered, return true
	return true;
}



// solves the puzzle recursively
bool recursive_solver(VECTOR< VECTOR<int> >& sudoku, long unsigned int row, long unsigned int col)
{
	// iterate to a 0
	while (1) {
		// if zero has been found
		if (sudoku.at(row).at(col) == 0) break;

		// iterate to next box
		col++;
		if (col >= COLS) {
			col = 0;
			row++;
		}

		// if at end of puzzle (base case)
		if (row >= ROWS) {
			return true;
		}
	}

	// zero has been found - iterate through sentinel
	int sentinel;
	for (sentinel=1; sentinel<=9; sentinel++) {
		// test the guess here
		bool guess_result = check_guess(sudoku, sentinel, row, col);

		// set the sudoku board equal to the sentinel
		update_puzzle(sudoku, sentinel, row, col);

		// if both the guess and the recursive call are true
		if (guess_result && recursive_solver(sudoku, row, col)) {
			return true;
		} else {  // if not true, put 0 back in the puzzle
			update_puzzle(sudoku, 0, row, col);
		}
	}

	// if the value does not work in this spot, evaluate to false
	return false;
}



// prints puzzle to a file
void print_puzzle_to_file(OFSTREAM& sudoku_outfile, const VECTOR< VECTOR<int> >& sudoku)
{
	// for loop to print row by row of sudoku board
	int row, col;
	for (row=0; row<ROWS; row++) {
		for (col=0; col<COLS; col++) {
			// printing number and whitespace
			sudoku_outfile << sudoku.at(row).at(col) << " ";
		}
		// printing endline character
		sudoku_outfile << ENDL;
	}

	// closing file
	sudoku_outfile.close();
	
	return;
}
