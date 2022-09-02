/* Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: PC07.cpp
 * Date Created: 3/22/22
 * File contents: the main file for PC07 */

#include "../include/passcode.h"
#include <string>

int main(const int argc, const char *argv[])
{
	// if user did not enter correct number of inputs
	if (argc!= 2) {
		COUT << "Incorrect number of inputs." << ENDL;
		return EXIT_FAILURE;
	}

	// initialize variables
	STRING filename = argv[1];
	VECTOR< VECTOR<int> > passwords;
 
	// read in the file, return failure if file does not exist
	int valid = read_file(filename, passwords);
	if (valid == -1) return EXIT_FAILURE;

	// create the graph based on the passwords
	Graph<int> the_graph = create_graph(passwords);

	// cracking the passcode
	STACK<int> the_stack = all_and_once(the_graph);

	// if the stack was empty, then the code couldn't be solved
	if (the_stack.empty()) { 
		COUT << "The passcode could not be solved." << ENDL;
		return EXIT_FAILURE;
	}

	// putting stack into vector so we can print correct password
	VECTOR<int> the_passcode = stack_to_vec(the_graph, the_stack);

	// printing the passcode
	COUT << "The passcode is: ";
	print_vector(the_passcode);

	return EXIT_SUCCESS;
}
