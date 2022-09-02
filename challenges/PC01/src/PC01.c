/*
 * Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File Name: PC01.c
 * Date Created: 1/19/22
 * File Contents: This file contains the main function for my PC01 assignment
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/rotations.h"



int main()
{
	// variable declarations
	long unsigned int length, num_rotations, i;
	char direction, doContinue;

	// loop to begin the prompts
	while(1) {
		printf("Enter the size, num rotations, and the direction: ");
		fscanf(stdin, "%lu %lu %c", &length, &num_rotations, &direction);

		// making sure user entered valid direction
		if (isValidDirection(direction) < 0) {
			printf("Invalid direction chosen.\n");
			continue;
		}

		// creating array and getting user input
		int *array = (int *)malloc(length * sizeof(int));

		printf("Input the %lu values: ", length);
		for (i=0; i<length; i++) {
			fscanf(stdin, "%d", array+i);
		}

		// printing before rotation
		printBeforeRotation(array, length);

		// finding the index of the first element of rotated array
		long unsigned int startIndex = findStartIndex(length, num_rotations, direction);

		// printing after rotation
		printAfterRotation(array, length, startIndex);

		free(array);

		// asking to continue here
		printf("Do you wish to continue? (y/n): ");
		fscanf(stdin, "%c", &doContinue);
		fscanf(stdin, "%c", &doContinue);
		if (doContinue == 'n') break;
	}

	return 0;
}
