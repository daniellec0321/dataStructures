/* Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: PC06.cpp
 * Date Created: 3/13/22
 * File contents: the main file for PC06 */



#include "../include/lru_cache.h"

int main()
{
	// getting the user's capacity for the cache
	SIZE_T capacity = initialize_cache();

	// initializing doubly linked list and hash table
	dllist my_dllist(capacity, 0);
	UNOR_MAP<int, dllist_node*> my_map;
	
	// initializing variables
	char continue_read = 'y';
	int num_accesses = 0;
	int user_data;

	// while loop to get user input
	while( continue_read == 'y' ){
	    // Increment the number of accesses
	    ++num_accesses;
	    
		// get the user choice of whether to put or get
	    char user_choice = get_user_choice( );
	   
		switch( user_choice ) {

			// if user entered p
			case 'p':
				// getting the value that will be put in the cache
				COUT << "Enter what value you want to insert: ";
				CIN >> user_data;

				// putting value into the cache
				put_value(my_dllist, my_map, user_data, num_accesses);

				break;
			
			// if user entered g
			case 'g':
				// getting the value that will be taken from the cache
				COUT << "Enter what value you want to get: ";
				CIN >> user_data;

				// getting value from the cache
				get_value(my_dllist, my_map, user_data, num_accesses);
				
				break;
				
			// if user didn't enter g or p
			default:
				COUT << "Value must be either p or g" << ENDL;
			
		}
		
		// printing the doubly linked list
		my_dllist.print_list();
	   
		// continuing the program
	    COUT << "Do you wish to continue? (y/n): ";
	    CIN >> continue_read;
		COUT << ENDL;
	}
	
	return EXIT_SUCCESS;
}
