// Name: Danielle Croft
// E-mail: dcroft@nd.edu
// File name: PC03.c
// Date created: 2/14/22
// File contents: this is the main file for PC03

#include <stdio.h>
#include <stdlib.h>
#include "../include/fenwick.h"

int main(const int argc, const char *argv[])
{
	// initializing arrays and variables
	long unsigned int num_inputs = ((long unsigned int)argc) - 1;
	long unsigned int array_len = num_inputs+1;
	int *array = create_array(argv, num_inputs);
	int *fenwick = make_fenwick(array, array_len);

	// variable that will hold user choice
	int user_choice;

	// while loop to continue the program
	while (1) {
		// printing the options
		print_menu();

		// getting user choice
		user_choice = get_choice();

		// breaking if user entered '4'
		if (user_choice == 4) break;

		// executing the user's decision
		execute_user_choice(user_choice, array, fenwick, array_len);
	}
	
	// freeing the arrays
	free(array);
	free(fenwick);

	return 0;
}
