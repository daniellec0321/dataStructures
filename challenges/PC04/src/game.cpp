// Author: Danielle Croft
// E-mail: dcroft@nd.edu
// File name: game.cpp
// Date Created: 2/17/22
// File contents: These are the function defintions for PC04

#include "../include/game.h"



// fills an empty vector with zeros
void fill_vector(VECTOR< VECTOR<int> > &game_board)
{
	// initializing iteration variables
	int row, column;

	// iterating through vector
	for (row=0; row<HEIGHT; row++) {
		// creating inner vector
		VECTOR<int> vtemp;
		for (column=0; column<WIDTH; column++) {
			// placing the zero
			vtemp.push_back(0);
		}
		// placing vector into vector array
		game_board.push_back(vtemp);
	}

	return;
}



// initializes a board at the beginning of the game
void initialize_board(VECTOR< VECTOR<int> > &game_board)
{
	// get random number between 0 and 15
	int rand_int = rand() % 16;

	// getting the height and width location
	int height_location = rand_int / 4;
	int width_location = rand_int % 4;

	// printing the initial location
	COUT << "Initial Location: (" << height_location << ", " << width_location << ")" << ENDL;

	// initializing the vector location with 2
	game_board.at(height_location).at(width_location) = 2;

	return;
}



// prints the game board
void print_board(const VECTOR< VECTOR<int> >& game_board, const int score)
{
	// initializing column and row counter
	int row = 0;
	int column = 0;

	// printing initial row and score
	COUT << "Score: " << score << ENDL;
	COUT << "---------" << ENDL;

	// loop to print the board
	for (row=0; row<HEIGHT; row++) {
		// printing initial bar
		COUT << "|";
		for (column=0; column<WIDTH; column++) {
			// if score is empty
			if (game_board.at(row).at(column) != 0) {
				COUT << game_board.at(row).at(column) << "|";
			} else {
				COUT << " |";
			}
		}

		// printing the bottom border
		COUT << ENDL << "---------" << ENDL;
	}

	return;
}



// checks if the user lost the game
bool check_board(const VECTOR< VECTOR<int> >& game_board)
{
	// variables to iterate through the board
	int row = 0;
	int column = 0;

	// iterate through board
	for (row=0; row<HEIGHT; row++) {
		for (column=0; column<WIDTH; column++) {
			// check if a zero is found
			if (game_board.at(row).at(column) == 0) return true;
		}
	}

	// if made it to this spot, no zeros were found
	return false;
}



// generating a random "2" on the board
void generate_new_initial(VECTOR< VECTOR<int> >& game_board)
{
	// declaring variables
	int rand_int, height_location, width_location;

	// in loop until valid location is found
	while (1) {
		// generating random location
		rand_int = rand() % 16;
		height_location = rand_int / 4;
		width_location = rand_int % 4;

		// checking that this number is at a zero location
		if (game_board.at(height_location).at(width_location) == 0) break;
	}

	// setting this valid location to two
	game_board.at(height_location).at(width_location) = 2;

	// printing info
	COUT << "New 2 placed at (" << height_location << ", " << width_location << ")" << ENDL;

	return;
}



// gets a char from user
char get_move_choice(void)
{
	// initializing variables
	char user_choice;

	// getting the user input
	COUT << "Enter what direction you want to move the board: ";
	CIN >> user_choice;

	return user_choice;
}



// executes a move depending on the user choice
void execute_user_choice(char user_choice, bool& valid_choice, VECTOR< VECTOR<int> >& game_board, int& score)
{
	// switch on user_choice
	switch (user_choice) {
		case 'u':
			move_up(game_board, score);
			break;
		
		case 'd':
			move_down(game_board, score);
			break;

		case 'l':
			move_left(game_board, score);
			break;

		case 'r':
			move_right(game_board, score);
			break;

		default:
			valid_choice = false;
			break;
	}

	return;
}



// moves the board to the left
void move_left(VECTOR< VECTOR<int> >& game_board, int& score)
{
	// initializing iterators
	int row, column, backtrack, second_loop;

	// iterate through all of the rows
	for (row=0; row<HEIGHT; row++) {
		// iterate through columns from RIGHT TO LEFT, width-1 to 1
		for (column=WIDTH-1; column>=1; column--) {
			// if the value to the left is zero
			if (game_board.at(row).at(column-1) == 0) {
				// setting value at left equal to current value
				game_board.at(row).at(column-1) = game_board.at(row).at(column);

				// making current value equal to zero
				game_board.at(row).at(column) = 0;

				// backtracking by looping to the right
				for (backtrack=column; backtrack<=WIDTH-2; backtrack++) {
					// making this current value equal to the value to the right
					game_board.at(row).at(backtrack) = game_board.at(row).at(backtrack+1);
				}

				// making right-most element equal to 0
				game_board.at(row).at(WIDTH-1) = 0;
			}

			// second for loop
			for (second_loop=0; second_loop<=WIDTH-2; second_loop++) {
				// if the value to the right is equal to the current value
				if (game_board.at(row).at(second_loop) == game_board.at(row).at(second_loop+1)) {
					// multiplying current value by 2
					game_board.at(row).at(second_loop) *= 2;
					
					// incrementing score
					score += game_board.at(row).at(second_loop);

					// backtracking again from currentval+1 to width-2
					for (backtrack=second_loop+1; backtrack<=WIDTH-2; backtrack++) {
						// current value equals new value to the right
						game_board.at(row).at(backtrack) = game_board.at(row).at(backtrack+1);
					}

					// set right-most element to zero
					game_board.at(row).at(WIDTH-1) = 0;
				}
			}
		}
	}

	return;
}



// moves the board to the right
void move_right(VECTOR< VECTOR<int> >& game_board, int& score)
{
	// initializing iterators
	int row, column, backtrack, second_loop;

	// iterate through all of the rows
	for (row=0; row<HEIGHT; row++) {
		// iterate through columns from left to right, 0 to width-2
		for (column=0; column<=WIDTH-2; column++) {
			// if the value to the right is zero
			if (game_board.at(row).at(column+1) == 0) {
				// setting value at right equal to current value
				game_board.at(row).at(column+1) = game_board.at(row).at(column);

				// making current value equal to zero
				game_board.at(row).at(column) = 0;

				// backtracking by looping to the left, current value to 1
				for (backtrack=column; backtrack>=1; backtrack--) {
					// making this current value equal to the value to the left
					game_board.at(row).at(backtrack) = game_board.at(row).at(backtrack-1);
				}

				// making left-most element equal to 0
				game_board.at(row).at(0) = 0;
			}

			// second for loop
			for (second_loop=WIDTH-1; second_loop>=1; second_loop--) {
				// if the value to the left is equal to the current value
				if (game_board.at(row).at(second_loop) == game_board.at(row).at(second_loop-1)) {
					// multiplying current value by 2
					game_board.at(row).at(second_loop) *= 2;
					
					// incrementing score
					score += game_board.at(row).at(second_loop);

					// backtracking again from currentval-1 to 1
					for (backtrack=second_loop-1; backtrack>=1; backtrack--) {
						// current value equals new value to the left
						game_board.at(row).at(backtrack) = game_board.at(row).at(backtrack-1);
					}

					// set left-most element to zero
					game_board.at(row).at(0) = 0;
				}
			}
		}
	}

	return;
}



// moves the board up
void move_up(VECTOR< VECTOR<int> >& game_board, int& score)
{
	// initializing iterators
	int row, column, backtrack, second_loop;

	// iterate through all of the columns
	for (column=0; column<WIDTH; column++) {
		// iterate through rows from the bottom up, HEIGHT-1 to 1
		for (row=HEIGHT-1; row>=1; row--) {
			// if the value above is zero
			if (game_board.at(row-1).at(column) == 0) {
				// setting value above equal to current value
				game_board.at(row-1).at(column) = game_board.at(row).at(column);

				// making current value equal to zero
				game_board.at(row).at(column) = 0;

				// backtracking by looping down, currentval to height-2
				for (backtrack=row; backtrack<=HEIGHT-2; backtrack++) {
					// making this current value equal to the value below
					game_board.at(backtrack).at(column) = game_board.at(backtrack+1).at(column);
				}

				// making bottom element equal to 0
				game_board.at(HEIGHT-1).at(column) = 0;
			}

			// second for loop, from 0 to HEIGHT-2
			for (second_loop=0; second_loop<=HEIGHT-2; second_loop++) {
				// if the value below is equal to the current value
				if (game_board.at(second_loop).at(column) == game_board.at(second_loop+1).at(column)) {
					// multiplying current value by 2
					game_board.at(second_loop).at(column) *= 2;
					
					// incrementing score
					score += game_board.at(second_loop).at(column);

					// backtracking again from currentval+1 to height-2
					for (backtrack=second_loop+1; backtrack<=HEIGHT-2; backtrack++) {
						// current value equals new value below
						game_board.at(backtrack).at(column) = game_board.at(backtrack+1).at(column);
					}

					// set bottom element to zero
					game_board.at(HEIGHT-1).at(column) = 0;
				}
			}
		}
	}

	return;
}



// moves the board down
void move_down(VECTOR< VECTOR<int> >& game_board, int& score)
{
	// initializing iterators
	int row, column, backtrack, second_loop;

	// iterate through all of the columns
	for (column=0; column<WIDTH; column++) {
		// iterate through rows from the top down, 0 to HEIGHT-2
		for (row=0; row<=HEIGHT-2; row++) {
			// if the value below is zero
			if (game_board.at(row+1).at(column) == 0) {
				// setting value below equal to current value
				game_board.at(row+1).at(column) = game_board.at(row).at(column);

				// making current value equal to zero
				game_board.at(row).at(column) = 0;

				// backtracking by looping up, currentval to 1
				for (backtrack=row; backtrack>=1; backtrack--) {
					// making this current value equal to the value above
					game_board.at(backtrack).at(column) = game_board.at(backtrack-1).at(column);
				}

				// making top element equal to 0
				game_board.at(0).at(column) = 0;
			}

			// second for loop, from HEIGHT-1 to 1
			for (second_loop=HEIGHT-1; second_loop>=1; second_loop--) {
				// if the value above is equal to the current value
				if (game_board.at(second_loop).at(column) == game_board.at(second_loop-1).at(column)) {
					// multiplying current value by 2
					game_board.at(second_loop).at(column) *= 2;
					
					// incrementing score
					score += game_board.at(second_loop).at(column);

					// backtracking again from currentval-1 to 1
					for (backtrack=second_loop-1; backtrack>=1; backtrack--) {
						// current value equals new value above
						game_board.at(backtrack).at(column) = game_board.at(backtrack-1).at(column);
					}

					// set top element to zero
					game_board.at(0).at(column) = 0;
				}
			}
		}
	}

	return;
}
