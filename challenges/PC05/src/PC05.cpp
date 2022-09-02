/* Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: PC05.cpp
 * Date Created: 2/23/22
 * File contents: the main file for PC05 */

#include "../include/sudoku.h"



int main(const int argc, const char *argv[])
{
	// if user entered incorrect amount of inputs
	if (argc != 3) {
		COUT << "Incorrect number of inputs." << ENDL;
		return EXIT_FAILURE;
	}

	// initializing the streams
	IFSTREAM sudoku_infile;
	sudoku_infile.open(argv[1]);
	if (sudoku_infile == NULL) {
		COUT << "File does not exist" << ENDL;
		return EXIT_FAILURE;
	}

	OFSTREAM sudoku_outfile;
	sudoku_outfile.open(argv[2]);

	// initializing sudoku board
	VECTOR< VECTOR<int> > sudoku;

	// greeting the user
	greeting();

	// filling the sudoku board
	fill_vector(sudoku);
	populate_puzzle(sudoku_infile, sudoku);

	// print puzzle
	COUT << ENDL << "Original puzzle:" << ENDL;
	print_puzzle(sudoku);

	// solve the puzzle
	recursive_solver(sudoku, 0, 0);

	// figuring out if puzzle is solvable
	if (check_puzzle(sudoku)) {
		COUT << ENDL << "Solved puzzle:" << ENDL;
	} else {
		COUT << ENDL << "Puzzle is not solvable." << ENDL;
	}

	// print puzzle to terminal
	print_puzzle(sudoku);
	COUT << ENDL;

	// print puzzle to file
	print_puzzle_to_file(sudoku_outfile, sudoku);

	return EXIT_SUCCESS;
}
