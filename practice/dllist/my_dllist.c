#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
	int data;
	struct list_node *prev_node;
	struct list_node *next_node;
} list_node;

typedef struct dllist {
	struct list_node *head_node;
	struct list_node *tail_node;
} dllist;



void deconstructor(list_node *curr_ptr)
{
	// if at end of list
	if (curr_ptr->next_node == NULL) {
		free(curr_ptr);
		return;
	}

	deconstructor(curr_ptr->next_node);

	free(curr_ptr);

	return;
}

void print_dllist(dllist *my_dllist)
{
	printf("\nYour list is:\n");

	// if list is empty
	if (my_dllist->head_node == NULL) {
		putchar('\n');
		return;
	}

	// initializing pointer
	list_node *curr_ptr = my_dllist->head_node;

	// printing the list
	while(1) {
		// if at the end of the list
		if (curr_ptr->next_node == NULL) {
			printf("%d \n\n", curr_ptr->data);
			break;
		}

		printf("%d ", curr_ptr->data);
		curr_ptr = curr_ptr->next_node;
	}

	return;
}

void push_front(dllist *my_dllist)
{
	// getting user value
	int new_value;
	printf("Enter the value you would like to push: ");
	fscanf(stdin, "%d", &new_value);

	// creating and assigning node
	list_node *insert_node = (list_node *)malloc(sizeof(list_node));
	insert_node->data = new_value;
	insert_node->prev_node = NULL;
	insert_node->next_node = NULL;

	// if my_dllist is empty
	if (my_dllist->head_node == NULL) {
		my_dllist->head_node = insert_node;
		my_dllist->tail_node = insert_node;
		return;
	}

	// if list is not empty, update head node
	my_dllist->head_node->prev_node = insert_node;
	insert_node->next_node = my_dllist->head_node;
	my_dllist->head_node = insert_node;

	return;
}

void push_back(dllist *my_dllist)
{
	// getting user value
	int new_value;
	printf("Enter the value you would like to push: ");
	fscanf(stdin, "%d", &new_value);

	// creating and assigning node
	list_node *insert_node = (list_node *)malloc(sizeof(list_node));
	insert_node->data = new_value;
	insert_node->prev_node = NULL;
	insert_node->next_node = NULL;

	// if my_dllist is empty
	if (my_dllist->head_node == NULL) {
		my_dllist->head_node = insert_node;
		my_dllist->tail_node = insert_node;
		return;
	}

	// if list is not empty, update tail node
	my_dllist->tail_node->next_node = insert_node;
	insert_node->prev_node = my_dllist->tail_node;
	my_dllist->tail_node = insert_node;

	return;
}

void pop_front(dllist *my_dllist)
{
	// if list is empty
	if (my_dllist->head_node == NULL) return;

	// if there is only 1 element
	if (my_dllist->head_node->next_node == NULL) {
		free(my_dllist->head_node);
		my_dllist->head_node = NULL;
		my_dllist->tail_node = NULL;
		return;
	}

	// if there is more than one element - save reference
	list_node *reference = my_dllist->head_node->next_node;

	// freeing the head node
	free(my_dllist->head_node);

	// make reference be the head node
	my_dllist->head_node = reference;
	my_dllist->head_node->prev_node = NULL;
	my_dllist->head_node->next_node = reference->next_node;

	return;
}

void pop_back(dllist *my_dllist)
{
	// if list is empty
	if (my_dllist->head_node == NULL) return;

	// if there is only 1 element
	if (my_dllist->head_node->next_node == NULL) {
		free(my_dllist->head_node);
		my_dllist->head_node = NULL;
		my_dllist->tail_node = NULL;
		return;
	}

	// if there is more than one element - save reference
	list_node *reference = my_dllist->tail_node->prev_node;

	// freeing the tail node
	free(my_dllist->tail_node);

	// make reference be the tail node
	my_dllist->tail_node = reference;
	my_dllist->tail_node->prev_node = reference->prev_node;
	my_dllist->tail_node->next_node = NULL;

	return;
}

void do_operation(char opcode, dllist *my_dllist)
{
	// case statement for what user entered
	switch (opcode) {
		case '1':
			push_front(my_dllist);
			break;
		case '2':
			push_back(my_dllist);
			break;
		case '3':
			pop_front(my_dllist);
			break;
		case '4':
			pop_back(my_dllist);
			break;
		default:
			printf("Invalid opcode\n");
			return;
			break;
	}
}



int main()
{
	system("clear");

	// creating the dllist
	dllist *my_dllist = (dllist *)malloc(sizeof(dllist));
	my_dllist->head_node = NULL;
	my_dllist->tail_node = NULL;

	// opcode will contain user's option
	char opcode;

	// getting user input
	while (1) {
		printf("Enter option:\nq to quit\n1 to push front\n2 to push back\n3 to pop front\n4 to pop back\n");
		fscanf(stdin, "%c", &opcode);
		
		// quit if user entered 0
		if (opcode == 'q') break;

		// execute whatever user entered
		do_operation(opcode, my_dllist);

		system("clear");
		print_dllist(my_dllist);
	}

	// printing the final array
	print_dllist(my_dllist);

	// deconstructing the list (if not empty)
	if (my_dllist->head_node != NULL) {
		deconstructor(my_dllist->head_node);
	}

	free(my_dllist);

	return 0;
}
