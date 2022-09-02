/* Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: lru_cache.cpp
 * Date Created: 2/23/22
 * File contents: The function definitions for PC06 */



#include "../include/lru_cache.h"

char get_user_choice( ){
	
	COUT << "p: Put value onto cache" << ENDL;
	COUT << "g: Get value from cache" << ENDL;
	COUT << "Enter your choice: ";
	
	char user_choice;
	
	CIN >> user_choice;
	
	return user_choice;
	
}


SIZE_T initialize_cache( ){
	
	COUT << "State the size of the cache: ";
	
	int capacity;
	
	CIN >> capacity;
	
	return capacity;
}


void put_value( dllist& cache_list, UNOR_MAP< int, dllist_node* >& cache_map, 
    int insert_data, int num_accesses ){

	// key is not present
	if (cache_map.find(insert_data) == cache_map.end()) {

		COUT << insert_data << " was not in cache" << ENDL;

		// checking if linked list is at capacity
		if (cache_list.at_capacity()) {
			// popping the back of the list
			cache_list.pop_back();

			// erase from unordered map
			cache_map.erase(insert_data);
		}

		// push the value to the front
		dllist_node* return_node = cache_list.push_front(insert_data, num_accesses);

		// insert the int and node into unordered map
		cache_map.insert({insert_data, return_node});

	// key is present
	} else {
		get_value(cache_list, cache_map, insert_data, num_accesses);
	}

	return;
}


void get_value( dllist& cache_list, UNOR_MAP< int, dllist_node* >& cache_map, 
    const int insert_data, int num_accesses ){
	
	// if the key is not in the cache
	if (cache_map.find(insert_data) == cache_map.end()) {
		COUT << insert_data << " is not in cache; a cache miss" << ENDL;

	// if key is in the cache
	} else {
		COUT << insert_data << " is already in cache; a cache hit" << ENDL;

		// promoting the node to the front
		dllist_node* insert_node = cache_map[insert_data];
		cache_list.promote_node_to_front(insert_node, num_accesses);
	}

	 return;
}
