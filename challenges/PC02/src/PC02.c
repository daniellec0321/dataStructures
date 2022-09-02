/*
 * Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: PC02.c
 * Date Created: 1/24/22
 * File contents: The main file for PC02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/life.h"

int main(const int argc, const char* argv[])
{
	// checking number of inputs
	if (argc != 4) {
		printf("Incorrect number of inputs.\n");
		return(EXIT_FAILURE);
	}

	// initializing variables (source_filename, num_gen, dest_filename)
	char source_filename[50];
	strcpy(source_filename, argv[1]);
	int num_gen = get_num_plays(argv[2]);
	char dest_filename[50];
	strcpy(dest_filename, argv[3]);

	// initializing board and reading from file
	char board[BOARD_WIDTH][BOARD_HEIGHT];
	read_file(board, source_filename);

	// printing board initially
	system("clear");
	puts("Generation 1");
	print_board(board);

	// playing the generations
	int i;
	for (i=2; i<=num_gen; i++) {
		system("clear");
		printf("Generation %d\n", i);
		play_generation(board);
		print_board(board);
	} 

	// printing to file
	print_to_file(board, dest_filename);

	return(EXIT_SUCCESS);
}
