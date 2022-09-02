// Author: Danielle Croft
// E-mail: dcroft@nd.edu
// File name: PC04.cpp
// Date Created: 2/17/22
// File contents: This is the main file for PC04

#include "../include/game.h"

int main()
{
	// setting up srand
	srand((unsigned int)time(0));

	// initializing vector, user_choice, and valid_choice
	VECTOR< VECTOR<int> > game_board;
	fill_vector(game_board);
	char user_choice;
	bool valid_choice = true;

	// initializing the first part of the board
	initialize_board(game_board);

	// printing the initial board
	int score = 0;
	print_board(game_board, score);

	// playing one iteration
	generate_new_initial(game_board);
	print_board(game_board, score);

	// while loop to play the game
	while (1) {
		// resetting valid choice
		valid_choice = true;

		// testing if player lost
		if (check_board(game_board) == false) {
			COUT << "Game is over." << ENDL;
			break;
		}

		// getting the user decision
		COUT << "Eligible to make a move..." << ENDL;
		COUT << "u for up, d for down, l for left, r for right, q to quit" << ENDL;
		user_choice = get_move_choice();

		// if user wants to quit
		if (user_choice == 'q') break;

		// execute user choice
		execute_user_choice(user_choice, valid_choice, game_board, score);

		// clearing the screen
		system("clear");

		// if user entered an invalid choice
		if (valid_choice == false) {
			COUT << "Not a valid choice." << ENDL;
		} else {  // if choice was valid
			// generating a new initial
			generate_new_initial(game_board);
		}

		// printing the resulting board
		print_board(game_board, score);
	}
	
	return EXIT_SUCCESS;
}
