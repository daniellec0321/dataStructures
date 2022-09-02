/* Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: passcode.cpp
 * Date created: 3/22/22
 * File contents: the function definitions for PC07 */

#include "../include/passcode.h"

// reads a file and puts info into vector, returns -1 if file does not exist
int read_file(const STRING filename, VECTOR< VECTOR<int> >& passcodes)
{
	// declaring filestream
	IFSTREAM infile;
	infile.open(filename);

	// if file does not exist
	if (infile == NULL) {
		COUT << "File does not exist." << ENDL;
		return -1;
	}

	// setting up a temporary reader and vector
	VECTOR<int> vtemp;
	int temp_char;

	// while loop to read file
	while (infile) {
		// get a singular character
		temp_char = infile.get();

		// if at end of file
		if (temp_char == -1) {
			break;

		// if at end of line
		} else if (temp_char == 10) {
			passcodes.push_back(vtemp);
			vtemp.clear();

		// if still reading the line
		} else {
			vtemp.push_back(temp_char - 48);
		}
	}

	// closing file stream
	infile.close();

	return 0;
}



// prints out a vector
void print_vector(const VECTOR<int> the_vector)
{
	SIZE_T iter;

	// iterate through vector and print out the element
	for (iter = 0; iter < the_vector.size(); iter++) {
		COUT << the_vector[iter];
	}

	COUT << ENDL;

	return;
}



// prints a vector within a vector
void print_vector_2(const VECTOR< VECTOR<int> > the_vector)
{
	SIZE_T iter, jter;

	// iterate through outer vector
	for (iter = 0; iter < the_vector.size(); iter++) {

		// iterate through inner vector
		for (jter = 0; jter < the_vector.at(iter).size(); jter++) {

			// print digit
			COUT << the_vector.at(iter).at(jter);

		}

		COUT << ENDL;

	}

	return;
}



// creates a graph based on the vector of ints
Graph<int> create_graph(const VECTOR< VECTOR<int> > the_vector)
{
	// initialize the graph
	Graph<int> the_graph;

	// unordered map to keep track of what vertexes we have added, and their INDEX in the vertices list
	UNOR_MAP<int, int> the_vertices;

	// keeps track of what vertex index we are at
	unsigned int index_counter = 0;

	// looping through the outer vector
	for (SIZE_T iter=0; iter<the_vector.size(); iter++) {

		// checking first element in the row, see if it is not in map yet
		if (the_vertices.find(the_vector.at(iter).at(0)) == the_vertices.end()) {

			// not in map--add this number to the unordered map
			the_vertices.insert({the_vector.at(iter).at(0), index_counter});

			// iterate the index counter
			index_counter++;

			// add this number to the vertex list of the graph
			the_graph.add_vertex(the_vector.at(iter).at(0)); 
		} 

		// looping through inner vector
		for (SIZE_T jter=1; jter<the_vector.at(iter).size(); jter++) {

			// checking element in the row, see if it is not in map yet
			if (the_vertices.find(the_vector.at(iter).at(jter)) == the_vertices.end()) {

				// not in map--add this number to the unordered map
				the_vertices.insert({the_vector.at(iter).at(jter), index_counter});

				// iterate the index counter
				index_counter++;

				// add this number to the vertex list of the graph
				the_graph.add_vertex(the_vector.at(iter).at(jter)); 
			}

			// initializing variables to add edges between vertices
			int dummy;
			int val1 = the_vertices[the_vector.at(iter).at(jter-1)];
			int val2 = the_vertices[the_vector.at(iter).at(jter)];
			bool edge_exists = the_graph.get_edge_value(val1, val2, dummy);

			// if edge does not exist, add it
			if (edge_exists == false) {

				// adding the edge to the graph
				the_graph.add_edge(val1, val2, 1);

			}

		}
	}

	return the_graph;
}



// The all-and-once algorithm to crack the passcode
STACK<int> all_and_once(const Graph<int> the_graph)
{
	// keeps track of what vertices we have visited
	VECTOR<int> visited(the_graph.vertices.size(), 0);

	// keeps track of what EDGES we have visited
	VECTOR<unsigned int> edges_visited(the_graph.vertices.size(), 0);

	// the stack we will use to crack the passcode
	STACK<int> the_stack;

	// flag to keep track if a solution has been found
	bool solution_found = false;

	// this will loop through each vertex to make sure we get the right starting vertex
	for (unsigned int iter=0; iter<the_graph.vertices.size(); iter++) {

		// if solution has been found, then break
		if (solution_found) break;

		// if vertex has no edges, then move on to the next vertex
		if (the_graph.vertices[iter].num_edges() == 0) continue;
		
		// setting the current vertex
		int curr_vertex = iter;

		// intializing that none of the edges have been visited
		edges_visited[curr_vertex] = 0;

		// evaluating the current vertex and its edges
		do {

			// if we haven't visited this vertex yet:
			// set the visited vector and push onto the stack
			if (visited[curr_vertex] == 0) {
				visited[curr_vertex] = 1;
				the_stack.push(curr_vertex);
			}

			// if stack is full, then solution has been found
			if (the_stack.size() == the_graph.vertices.size()) {
				solution_found = true;
				break;
			}

			// if the vertex has no outgoing edges, reset everything related to that vertex, pop, and continue
			if (the_graph.vertices[curr_vertex].num_edges() == 0) {

				// reset visited
				visited[curr_vertex] = 0;

				// pop off the stack
				the_stack.pop();

				// resetting the curr_vertex value, if the stack isn't empty
				if (!the_stack.empty()) {
					curr_vertex = the_stack.top();
					continue;

				// if the stack is empty, then we need to break and start our algorithm from a new vertex
				} else {
					break;
				}

			}

			// if all of the vertexes outgoing edges have been visited, then reset and pop
			if (edges_visited[curr_vertex] >= the_graph.vertices[curr_vertex].num_edges()) {

				// reset the number of edges it has visited
				edges_visited[curr_vertex] = 0;

				// reset visited
				visited[curr_vertex] = 0;

				// pop off the stack
				the_stack.pop();

				// resetting the curr_vertex value, if stack isn't empty
				if (!the_stack.empty()) {
					curr_vertex = the_stack.top();
					continue;

				// if the stack is empty, then we need to break and start our algorithm from a new vertex
				} else {
					break;
				}

			}

			// Now that we have a valid vertex, change curr_vertex to the next outgoing edge
			int next_edge = edges_visited[curr_vertex];
			int last_vertex = curr_vertex;
			curr_vertex = the_graph.vertices[curr_vertex].edges[next_edge].destin;

			// updating the amount of edges visited
			edges_visited[last_vertex]++;

		} while (!the_stack.empty());
	}

	return the_stack;
}



// prints a stack to the terminal
void print_stack(STACK<int> the_stack)
{
	while (!the_stack.empty()) {
		COUT << the_stack.top() << " ";
		the_stack.pop();
	}

	COUT << ENDL;

	return;
}



// converts the passcode stack to a vector
VECTOR<int> stack_to_vec(const Graph<int> the_graph, STACK<int> the_stack)
{
	// initialize vector
	VECTOR<int> the_vec(the_stack.size(), 1);

	// intialize variables
	int length = (int)the_stack.size();

	// going through stack, putting it into vector BACKWARDS
	for (int i = length-1; i>=0; i--) {
		the_vec[i] = the_graph.vertices[the_stack.top()].data;
		the_stack.pop();
	}

	return the_vec;
}
