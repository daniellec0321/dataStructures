#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	
	// Step 1 - Size
	long unsigned int size;
	
	
	// Step 2 - Capacity
	long unsigned int capacity;
	
	
	// Step 3 - Integer Pointer
	int *ptr;
	
	
} vector;


// Step 6 - Create a function "constructor" which allocates the vector 
void constructor(vector *our_vector)
{

	
	// 6-1 Set size and capacity to 0
	our_vector->size = 0;
	our_vector->capacity = 0;
	
	
	
	// 6-2 Set the integer array pointer to NULL
	our_vector->ptr = NULL;
	
}
	
	


// Step 8 - Create a function "destructor" which frees the int pointer 
void deconstructor(vector *our_vector)
{

	
	// 8-1 Dr. Morrison's Golden Rule of Pointers 
	// Avoid excessive frees 
	
		
		// Free the integer array
		if (our_vector->ptr != NULL)
			free(our_vector->ptr);

}
		
	


// Step 10 - Insertion
void insert(vector *our_vector, int value) {

	
	// 10-1 Dr. Morrison's Golden Rule of Pointers
	
	if (our_vector->ptr == NULL) {
	
		
		// Allocate an array of one integer 
		our_vector->ptr = (int *)malloc(sizeof(int));
		
		
		// Set the capacity to 1
		our_vector->capacity = 1;
		our_vector->size = 0;
	}
		
		
	
	
	// Next, check if the size is equal to the capacity 
	if (our_vector->size == our_vector->capacity) {
		// If so, we need to reallocate 
		// First, multiply the capacity by 2
		our_vector->capacity *= 2;
		
		
		// Then we need to create a pointer to the current array 
		int *temp_ptr = (int *)malloc(our_vector->size * sizeof(int));
		temp_ptr = our_vector->ptr;
		
		
		// Allocate a new vector that is size of the capacity 
		our_vector->ptr = (int *)malloc(our_vector->capacity * sizeof(int));
		
		
		// Iterate through the array and copy the old values to the new values 
		long unsigned int i;
		for (i=0; i<our_vector->size; i++) {
			*(our_vector->ptr + i) = *(temp_ptr + i);
		}
			
		// Finally, free the old array 
		
		free(temp_ptr);
	}
	
	
	// Insert the element at the location of size 
	*(our_vector->ptr + our_vector->size) = value;
	
	
	// And increment the size 
	our_vector->size += 1;
	
}


// Print the vector 
void print( vector* int_vector ){
	
	fprintf( stdout, "--------------------------\n" );
	fprintf( stdout, "Vector Size = %lu, Capacity = %lu\n", 
			int_vector->size, int_vector->capacity);
	
	long unsigned int iter;
	for( iter = 0; iter < int_vector->size; ++iter ){
		
		fprintf( stdout, "%d %p\n", 
			int_vector->ptr[iter], &(int_vector->ptr[iter]) );
		
	}
	
}

int main(){
	
	
	// Step 4 - Dynamically Allocate the Vector Struct 
	vector *our_vector = (vector *)malloc(sizeof(vector));
	
	
	// Step 7 - Call the Constructor
	constructor(our_vector);
	
	
	//  I will explain this loop, but it will help you with Programming Challenge 1
	char char_continue = 'y';
	while( char_continue == 'y' ){
		
		int read_int;
		fprintf( stdout, "Enter an integer: ");
		fscanf( stdin, "%d", &read_int );

		// Pass By Reference Function 
		insert( our_vector, read_int );
		
		// Print function 
		print( our_vector );

		fprintf( stdout, "Do you wish to continue? (y for yes): ");
		fscanf( stdin, " %c", &char_continue );		
		
	}
	
	// Step 9 - Call the Destructor
	deconstructor(our_vector);
	
	
	// Step 5 - Call free on the vector 
	free(our_vector);
	
	
	return 0;
}
