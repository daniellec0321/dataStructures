/*
 * Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File Name: rotations.c
 * Date Created: 1/19/22
 * File Contents: This file contains the function definitions for my PC01 assignment
*/

#include <stdio.h>
#include "../include/rotations.h"



long unsigned int findStartIndex(long unsigned int length, long unsigned int num_rotations, char direction)
{
	// simplifying rotations value
	num_rotations = num_rotations % length;

	// returning value if rotated to the left
	if ((direction == 'L') || (direction == 'l')) {
		return (num_rotations % length);

	// returning value if rotated to the right
	} else {
		return ((length - num_rotations) % length);
	}

}



int isValidDirection(char direction)
{
	// will return 0 if user entered valid direction; otherwise will return -1
	switch (direction) {
		case 'L':
			return 0;
			break;
		case 'l':
			return 0;
			break;
		case 'R':
			return 0;
			break;
		case 'r':
			return 0;
			break;
		default:
			return -1;
			break;
	}

	return 0;
}



void printBeforeRotation(int *array, long unsigned int length)
{
	long unsigned int i;

	printf("Before Rotation:\n");

	// prints the element and its location in the heap
	for (i=0; i<length; i++) {
		printf("%d at %p\n", *(array+i), array+i);
	}

}



void printAfterRotation(int *array, long unsigned int length, long unsigned int startIndex)
{
	long unsigned int i;

	printf("After Rotation:\n");

	// prints element and its location in the heap
	for (i=0; i<length; i++) {
		printf("%d at %p\n", *(array + ((startIndex+i)%length)), array + ((startIndex+i)%length)); 
	}

	// this was where the brunt of my work was; figuring out what should be printed when and what the index should be given the rotation.
}
