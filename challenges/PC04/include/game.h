// Author: Danielle Croft
// E-mail: dcroft@nd.edu
// File name: game.h
// Date Created: 2/17/22
// File contents: These are the function declarations for PC04

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define VECTOR std::vector
#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define HEIGHT 4
#define WIDTH 4
#define SIZE_T long unsigned int

// Function declarations will go here

// fills an empty vector with zeros
void fill_vector(VECTOR< VECTOR<int> > &game_board);

// initializing a board at the start of the game
void initialize_board(VECTOR< VECTOR<int> >& game_board);

// printing a board
void print_board(const VECTOR< VECTOR<int> >& game_board, const int score);

// checking board to see if user lost the game
bool check_board(const VECTOR< VECTOR<int> >& game_board);

// generating a new random number
void generate_new_initial(VECTOR< VECTOR<int> >& game_board);

// takes a user input and returns a char
char get_move_choice(void);

// executes whatever move user wanted it to execute
void execute_user_choice(char user_choice, bool& valid_choice, VECTOR< VECTOR<int> >& game_board, int& score);

// moves board to the left
void move_left(VECTOR< VECTOR<int> >& game_board, int& score);

// moves board to the right
void move_right(VECTOR< VECTOR<int> >& game_board, int& score);

// moves board up
void move_up(VECTOR< VECTOR<int> >& game_board, int& score);

// moves board down
void move_down(VECTOR< VECTOR<int> >& game_board, int& score);

#endif
