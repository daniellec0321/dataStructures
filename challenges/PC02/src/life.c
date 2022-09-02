/*
 * Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File Name: life.c
 * Date Created: 1/24/22
 * File Contents: the function definitions for PC02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/life.h"

int width_add(int width_index, int width_offset)
{
	// wrapping around the width
	width_index += width_offset;

	if (width_index < 0) width_index += BOARD_WIDTH;
	if (width_index > BOARD_WIDTH-1) width_index -= BOARD_WIDTH;

	return width_index;
}

int height_add(int height_index, int height_offset)
{
	// wrapping around the height
	height_index += height_offset;

	if (height_index < 0) height_index += BOARD_HEIGHT;
	if (height_index > BOARD_HEIGHT-1) height_index -= BOARD_HEIGHT;

	return height_index;
}

// finding number of adjacent live cells
int adjacent_to(char board[][BOARD_HEIGHT], int x_index, int y_index)
{
	int counter = 0;

	if (board[ width_add(x_index, -1) ][ height_add(y_index, -1) ] == 'X') counter++;
	if (board[ width_add(x_index, -1) ][ height_add(y_index, 0) ] == 'X') counter++;
	if (board[ width_add(x_index, -1) ][ height_add(y_index, 1) ] == 'X') counter++;
	if (board[ width_add(x_index, 0) ][ height_add(y_index, -1) ] == 'X') counter++;
	if (board[ width_add(x_index, 0) ][ height_add(y_index, 1) ] == 'X') counter++;
	if (board[ width_add(x_index, 1) ][ height_add(y_index, -1) ] == 'X') counter++;
	if (board[ width_add(x_index, 1) ][ height_add(y_index, 0) ] == 'X') counter++;
	if (board[ width_add(x_index, 1) ][ height_add(y_index, 1) ] == 'X') counter++;

	return counter;
}

int get_num_plays(const char *num_plays)
{
	// converting string to integer
	int num_gen = atoi(num_plays);

	return num_gen;
}

void play_generation(char board[][BOARD_HEIGHT])
{
	// initializing variables
	int x, y;
	char update_board[BOARD_WIDTH][BOARD_HEIGHT];
	int num_neighbors;

	// for loop to go through entire board to create update board
	// we cannot change it immediately; we have to find if there's stasis, death, or growth
	// D means death; S means stasis; G means growth
	for (y=0; y<BOARD_HEIGHT; y++) {
		for (x=0; x<BOARD_WIDTH; x++) {
			num_neighbors = adjacent_to(board, x, y);

			if ((num_neighbors <= 1) || (num_neighbors >= 4)) update_board[x][y] = 'D';
			else if (num_neighbors == 2) update_board[x][y] = 'S';
			else update_board[x][y] = 'G';
		}
	}

	// now for loop to change the physical board
	for (y=0; y<BOARD_HEIGHT; y++) {
		for (x=0; x<BOARD_WIDTH; x++) {
			if (update_board[x][y] == 'D') board[x][y] = '.';
			if (update_board[x][y] == 'G') board[x][y] = 'X';
		}
	} 
	
	return;
}

void print_board(char board[][BOARD_HEIGHT])
{
	int i, j;

	// going through board and printing to the screen
	for (i=0; i<BOARD_HEIGHT; i++) {
		for (j=0; j<BOARD_WIDTH; j++) {
			fprintf(stdout, "%c", board[j][i]);
		}
		fprintf(stdout, "\n");
	}

	return;
}

void read_file(char board[][BOARD_HEIGHT], const char *name)
{
	// initializing variables
	FILE *fp = (FILE *)malloc(sizeof(name));
	fp = fopen(name, "r");
	int buf;
	int row_index = 0;
	int column_index = 0;

	while (1) {
		// if end of file is found, or if the board has been filled
		if(feof(fp)) break;
		if (row_index == BOARD_HEIGHT) break;

		buf = fgetc(fp);

		// if newline character was found, or if at end of the row
		if ((buf == 10) || (column_index == BOARD_WIDTH)) {
			row_index++;
			column_index = 0;

		// if any other character was found
		} else {
			board[column_index][row_index] = (char)(buf);
			column_index++;
		}
	}

	fclose(fp);

	return;
}

void print_to_file (char board[][BOARD_HEIGHT], const char *name)
{
	// opening new file
	FILE *fp = (FILE *)malloc(sizeof(board));
	fp = fopen(name, "w+");

	// for loop to go through board and print into file
	int i, j;
	for (i=0; i<BOARD_HEIGHT; i++) {
		for (j=0; j<BOARD_WIDTH; j++) {
			fprintf(fp, "%c", board[j][i]);
		}
		fprintf(fp, "\n");
	}

	fclose(fp);

	return;
}
