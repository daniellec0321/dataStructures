/* Name: Danielle Croft
 * Email: dcroft@nd.edu
 * File name: dllist.h
 * Date Created: 3/13/22
 * File contents: the function declarations and defintions for a dllist in PC06 */

#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
#include <cstdlib>

#define COUT std::cout 
#define CIN std::cin
#define ENDL std::endl
#define SIZE_T long unsigned int

struct dllist_node{

	public:
		
		int data;
		int time_stamp;
		struct dllist_node* prev_node;
		struct dllist_node* next_node;

		// default constructor
		dllist_node(): data(0), time_stamp(0) {
			this->prev_node = NULL;
			this->next_node = NULL;
		};

		// overloaded constructor
		dllist_node(const int data_in, const int time_stamp_in):
			data(data_in), time_stamp(time_stamp_in) {
				this->prev_node = NULL;
				this->next_node = NULL;
			}
};


struct dllist{

    private:
    
        void destructor( dllist_node* curr_ptr ){
	
        	// Dr. Morrison's Golden Rule of Pointers 
        	if( curr_ptr == NULL )
        		return;
        	
        
        	// Recursively call destructor on the next node  
        	destructor( curr_ptr->next_node );
        		
        	// Delete the current pointer 
        	delete curr_ptr;
        	
        }

    public:

		/********************************
		 * Put the public members, the constructor, and the destructor here 
		 * for the Doubly Linked List as identified in the project description
		 *********************************/
		 
		SIZE_T capacity;
		SIZE_T list_size;
		dllist_node* head_node;
		dllist_node* tail_node;

		// MY CODE - default constructor for dllist
		dllist(): capacity(0), list_size(0) {
			this->head_node = NULL;
			this->tail_node = NULL;
		};

		// MY CODE - overloaded constructor
		dllist(const SIZE_T capacity_in, const SIZE_T list_size_in): 
			capacity(capacity_in), list_size(list_size_in) {
				this->head_node = NULL;
				this->tail_node = NULL;
		};

		// MY DESTRUCT - calls the private destructor function
		~dllist() {
			destructor(this->head_node);
		}
    	
    	
    	dllist_node* push_front( const int& the_value, const int& the_time ){
        	
        	// Create a dll_node pointer called insert_node
        	dllist_node* insert_node = new dllist_node( the_value, the_time );
        	
        	// Dr. Morrison's Golden Rule of Pointers 
        	if( this->head_node == NULL ){
        		
        		// Set the head node equal to insert_node 
        		this->head_node = insert_node;
        		this->tail_node = insert_node;
        		
        		// Increment the size
        		this->list_size++;
        		
				return this->head_node;
        	}

        	// Otherwise, we perform the pointer arithmetic
        	dllist_node* reference = this->head_node;
        	
        	// Set the head_node to the new node 
        	this->head_node = insert_node;
        	
        	// Set the new head_node's next to the reference 
        	this->head_node->next_node = reference;
        	reference->prev_node = this->head_node;
        	
    		// Increment the size
    		this->list_size++;
    		
    		// MY CODE - return the address of the inserted node	
			return insert_node;
        	
        }
        
    // Step 15 - Pop Back 
    void pop_back( ){
    	
    	// Check if the list is not empty
    	if( this->head_node == NULL && this->tail_node == NULL )
    		return;
    	
    	if( this->head_node == this->tail_node ){
    		
    		delete this->head_node;
    		
    		// Set the pointers value to NULL
    		this->head_node = NULL;
    		this->tail_node = NULL;
    		
    		// Decrement the size
    		this->list_size--;
    		
    		// Return the node to delete
    		return;
    	}
    	
    	// Otherwise, move the node and free
    	// Set a reference pointer to head_node
    	dllist_node* reference = this->tail_node;
    	
    	// Set the head_node to head_node's next_node;
    	this->tail_node = reference->prev_node;
    	this->tail_node->next_node = NULL;
    
    	
    	// Free the reference 
    	delete reference;
    	
		// Decrement the size
		this->list_size--;
    	
    }

	// MY CODE - promotes a node already in the list to the front
    void promote_node_to_front( dllist_node* the_node, int num_accesses ){

		// returning if head_node, tail_node, or the_node is NULL
		if ((this->head_node == NULL) || (this->tail_node == NULL) || (the_node == NULL)){
			return;
		}

		// setting node's time stamp equal to num accesses
		the_node->time_stamp = num_accesses;

		// if head node is equal to current node -- then already at the front, so don't need to do anything
		if (this->head_node == the_node) {
			return;
		}

		// if tail node is equal to current node
		if (this->tail_node == the_node) {
			// setting tail node equal to previous node
			this->tail_node = the_node->prev_node;
			this->tail_node->next_node = NULL;
		} else {
			// connecting the nodes before and after the_node
			the_node->prev_node->next_node = the_node->next_node;
			the_node->next_node->prev_node = the_node->prev_node;
		}

		// since the_node is now head node, update everything
		the_node->prev_node = NULL;
		the_node->next_node = this->head_node;
		this->head_node->prev_node = the_node;
		this->head_node = the_node;
    }
    
    bool at_capacity(){
        
        return this->capacity == this->list_size;
    }
    
    void print_list(){
        
        COUT << "Cache contents: " << ENDL;
        COUT << "Current size: " << this->list_size << ENDL;
        
        dllist_node* print_node = this->head_node;
        
        while( print_node != NULL ){
        
            COUT << "Address = " << print_node << ": ";
            COUT << "Time Stamp = " << print_node->time_stamp << ", ";
            COUT << "Data =  " << print_node->data << ENDL;
            
            print_node = print_node->next_node;
        }
    }
};

#endif
