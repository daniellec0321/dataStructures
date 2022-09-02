/*
 * Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File Name: rotations.h
 * Date Created: 1/19/22
 * File Contents: This file contatins the function declarations for my PC01 assignment
*/



// this function finds the first element of the rotated array, specifically what the index is in the original array
long unsigned int findStartIndex(long unsigned int length, long unsigned int num_rotations, char direction);

// this function takes what the user entered for the direction and returns if it is valid or not (0 for valid, -1 for invalid)
int isValidDirection(char direction);

// this function prints the array before it is rotated
void printBeforeRotation(int *array, long unsigned int length);

// this function prints the array after it is rotated
void printAfterRotation(int *array, long unsigned int length, long unsigned int startIndex);
