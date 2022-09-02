/*
 * Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File Name: life.h
 * Date Created: 1/24/22
 * File Contents: the function declarations for PC02
 */

#define BOARD_WIDTH 70
#define BOARD_HEIGHT 30

// allows width to wrap like cylinder
int width_add(int width_index, int width_offset);

// allows height to wrap like cylinder
int height_add(int height_index, int height_offset);

// counts how many adjacent live cells there are
int adjacent_to(char board[][BOARD_HEIGHT], int x_index, int y_index);

// converts user input into a number
int get_num_plays(const char *num_plays);

// plays generation of the game of life
void play_generation(char board[][BOARD_HEIGHT]);

// prints the current board
void print_board(char board[][BOARD_HEIGHT]);

// reads the file and puts the info into the command line
void read_file(char board[][BOARD_HEIGHT], const char *name);

// puts the board into a file
void print_to_file (char board[][BOARD_HEIGHT], const char *name);
