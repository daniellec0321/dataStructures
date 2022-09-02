// Name: Danielle Croft
// E-mail: dcroft@nd.edu
// File name: fenwick.c
// Date created: 2/14/22
// File contents: This is the function definitions for PC03

#include <stdio.h>
#include <stdlib.h>
#include "../include/fenwick.h"

// creating the array based on the command line arguments
int *create_array(const char *argv[], long unsigned int num_inputs)
{
	// initializing array
	int *array = (int *)malloc((num_inputs+1)*sizeof(int));
	array[0] = 0;

	// filling in values
	long unsigned int i;
	for (i=0; i<num_inputs; i++) {
		array[i+1] = atoi(argv[i+1]);	
	}

	return array;
}

// printing out available choices
void print_menu(void)
{
	puts("Select your choice:");
	puts("1: Print array and fenwick tree");
	puts("2: Calculate range sum");
	puts("3: Update array and fenwick tree");
	puts("4: Quit the program.");
	printf("Enter your selection: ");

	return;
}

// get a scanned in integer from the user
int get_choice(void)
{
	int choice;
	fscanf(stdin, "%d", &choice);
	return choice;
}

// prints a given array onto a single line
void print_array(int *the_array, long unsigned int array_len)
{
	long unsigned int i;
	for (i=0; i<array_len; i++) {
		printf("%d ", the_array[i]);
	}
	putchar('\n');

	return;
}

// make a fenwick tree based on a given array
int *make_fenwick(int* array, long unsigned int length)
{
	// initializing tree
	int *fenwick = (int *)malloc(length * sizeof(int));

	// copying original array into fenwick tree
	long unsigned int iter;
	for (iter=0; iter<length; iter++) 
		fenwick[iter] = array[iter];

	// creating the tree
	long unsigned int parent;
	for (iter=0; iter<length; iter++) {
		// updating the parent location
		parent = iter + (iter & -iter);

		// updating the tree
		if (parent < length)
			fenwick[parent] = fenwick[parent] + fenwick[iter];
	}

	return fenwick;
}

// changing given array and updating the fenwick tree
void update_fenwick(int *array, int *fenwick, long unsigned int array_len)
{
	// getting user input
	printf("\nEnter the index whose value you want to change: ");
	int new_location = get_choice();
	printf("Enter the new value: ");
	int new_value = get_choice();
	putchar('\n');

	// getting difference between current and new values
	int difference = new_value - array[new_location];

	// updating array
	array[new_location] = new_value;

	// updating fenwick tree
	long unsigned int iter = (long unsigned int)new_location;
	while(iter < array_len) {
		// adding the difference
		fenwick[iter] += difference;

		// updating the iterator
		iter += (iter & -iter);
	}

	return;
}

// finding sum between two indices of the array
void sum_vals(int *fenwick)
{
	// getting the indices of what we will add
	printf("\nEnter the left index: ");
	int left_index = get_choice() - 1;
	printf("Enter the right index: ");
	int right_index = get_choice();

	// declaring variables
	int left_sum = 0;
	int right_sum = 0;

	// Summing up the left index
	int left_index_iter = left_index;
	while (left_index_iter > 0) {
		// adding to the sum
		left_sum += fenwick[left_index_iter];

		// updating the left index
		left_index_iter -= (left_index_iter & -left_index_iter);
	}

	// Summing up the right index
	int right_index_iter = right_index;
	while (right_index_iter > 0) {
		// adding to the sum
		right_sum += fenwick[right_index_iter];

		// updating the right index
		right_index_iter -= (right_index_iter & -right_index_iter);
	}

	// obtaining the true sum
	int true_sum = right_sum - left_sum;

	// printing this to the user
	printf("The sum from indices %d to %d is %d.\n\n", left_index+1, right_index, true_sum);

	return;
}

// calling the functions depending on what the user choice was
void execute_user_choice(int user_choice, int *array, int *fenwick, long unsigned int array_len)
{
	// case statement to decide what to do
	switch (user_choice) {
		// printing arrays
		case 1:
			printf("\nArray: ");
			print_array(array, array_len);
			printf("Fenwick: ");
			print_array(fenwick, array_len);
			putchar('\n');
			break;

		// summing values
		case 2:
			sum_vals(fenwick);
			break;

		// updating array and fenwick tree
		case 3: 
			update_fenwick(array, fenwick, array_len);
			break;

		// if user entered an invalid choice
		default:
			printf("Not a valid choice.\n\n");
			break;
	}

	return;
}
