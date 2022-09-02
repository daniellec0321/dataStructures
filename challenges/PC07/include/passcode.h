/* Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: passcode.h
 * Date Created: 3/22/22
 * File contents: the function declarations for PC07 */

#ifndef PASSCODE_H
#define PASSCODE_H

// Including Prof Morrison's graph code
#include "Graph.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream
#define STRING std::string
#define SIZE_T long unsigned int

// reads text file and puts passcodes into vector of vectors. If given a nonexistant text file, returns -1
int read_file(const STRING filename, VECTOR< VECTOR<int> >& passcodes);

// prints a vector
void print_vector(const VECTOR<int> the_vector);

// prints out a vector within a vector
void print_vector_2(const VECTOR< VECTOR<int> > the_vector);

// creates a graph based on the vector of ints
Graph<int> create_graph(const VECTOR< VECTOR<int> > the_vector);

// algorithm to crack the password
STACK<int> all_and_once(const Graph<int> the_graph);

// prints a stack
void print_stack(STACK<int> the_stack);

// converts a stack of indexes to vertexes to a vector, depending on the order of the stack
VECTOR<int> stack_to_vec(const Graph<int> the_graph, STACK<int> the_stack);

#endif
